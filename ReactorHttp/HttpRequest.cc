#include "HttpRequest.h"
#include "TcpConnection.h"
#include <functional>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <assert.h>
#include <cctype>

HttpRequest::HttpRequest(){
    reset();
}

HttpRequest::~HttpRequest(){}

// 重置
void HttpRequest::reset(){
    m_curState = PrecessState::ParseReqLine;
    m_method = m_url = m_version = std::string();
    m_reqHeaders.clear();
}
// 添加请求头
void HttpRequest::addHeader(const std::string key, const std::string value){
    if(key.empty() || value.empty()){
        return;
    }
    if(key == "Connection"){
        m_connection = value;
    }
    m_reqHeaders[key] = value;
}

// 根据key得到请求头的value
std::string HttpRequest::getHeader(const std::string key){
    auto item = m_reqHeaders.find(key);
    if(item != m_reqHeaders.end()){
        return item->second;
    }
    return std::string();
}
// 解析请求行
bool HttpRequest::parseRequestLine(Buffer* readBuf){
    // 读取请求行，保存字符串结束地址
    char *end = readBuf->findCRLF();
    if(end == nullptr){
        fprintf(stderr, "Failed to find CRLF in request line.\n");
        return false;
    }
    // 保存字符串起始地址
    char *start = readBuf->data();
    // 请求行总长度
    int lineSize = end - start;
    if(lineSize > 0){
        auto methodFunc = [this](const std::string& method){
            this->setMethod(method);
        };
        start = splitRequestLine(start, end, " ", methodFunc);

        auto urlFunc = [this](const std::string& url){
            this->seturl(url);
        };
        start = splitRequestLine(start, end, " ", urlFunc);

        auto versionFunc = [this](const std::string& version){
            this->setVersion(version);
        };
        splitRequestLine(start, end, nullptr, versionFunc);

        // 为解析请求头做准备
        readBuf->readPosincrease(lineSize + 2);
        // 修改状态
        setState(PrecessState::ParseReqHeaders);
        return true;
    }
    return false;
}

// 解析请求头
bool HttpRequest::parseRequestHeader(Buffer* readBuf){
    char* end = readBuf->findCRLF();
    if(end != nullptr){
        char *start = readBuf->data();
        int lineSize = end - start;
        char *middle = std::search(start, end, ": ", ": " + 2);

        if(middle != end){
            int keylen = middle - start;
            int valuelen = end - middle + 1;
            if(keylen > 0 && valuelen > 0){
                std::string key(start, keylen);
                std::string value(middle + 2, valuelen); // 跳过 ": "
                addHeader(std::move(key), std::move(value));
            }
            // 移动读取位置
            readBuf->readPosincrease(lineSize + 2);
        }
        else{
            // 请求头解析完毕。跳过空行
            readBuf->readPosincrease(2);
            // 修改解析状态
            // 忽略post请求，按照get请求处理
            setState(PrecessState::ParseReqDone);
        }
        return true;
    }
    fprintf(stderr, "Failed to find CRLF in request header.\n");
    return false;
}

// 解析http请求协议
bool HttpRequest::parseHttpRequest(Buffer* readBuf, HttpResponse* response, Buffer* sendBuf, int socket){
    bool flag = true;
    while(m_curState != PrecessState::ParseReqDone){
        switch (m_curState)
        {
        case PrecessState::ParseReqLine:
            flag = parseRequestLine(readBuf);
            break;
        case PrecessState::ParseReqHeaders:
            flag = parseRequestHeader(readBuf);
            break;
        case PrecessState::ParseReqBody:
            break;
        default:
            break;
        }
        if(!flag) return false;

        // 判断是否解析完毕并准备响应
        if(m_curState == PrecessState::ParseReqDone){
            // 1.处理客户端请求
            processHttpRequest(response);

            // 2.准备并发送响应消息
            response->prepareMsg(sendBuf, socket, this);
        }
    }
    // 状态还原，以便处理后续请求
    m_curState = PrecessState::ParseReqLine;
    return true;
}

// 处理http请求协议
bool HttpRequest::processHttpRequest(HttpResponse* response){
    if(strcasecmp(m_method.data(), "get") != 0){
        return false;
    }
    m_url = decodeMsg(m_url);
    if(m_url.find("..") != std::string::npos){
        response->setFileName("403.html");
        response->setStatusCode(StatusCode::Forbidden);
        // 响应头
        response->addHeader("Content-type", getFileType(".html"));
        response->sendDataFunc = sendFile;
        return true;
    }
    // 处理客户端请求的静态资源（目录或文件）
    const char* file = nullptr;
    if(m_url == "/"){
        file = "./";
    }else{
        file = m_url.data() + 1;
    }
    // 获取文件属性
    struct stat st;
    int ret = stat(file, &st);
    if(ret == -1){
        // 文件不存在 -- 回复404
        response->setFileName("404.html");
        response->setStatusCode(StatusCode::NotFound);
        // 响应头
        response->addHeader("Content-type", getFileType(".html"));
        response->sendDataFunc = sendFile;
        return true;
    }

    response->setFileName(file);
    response->setStatusCode(StatusCode::OK);
    // 判断文件类型
    if(S_ISDIR(st.st_mode)){
        // 发送目录内容
        response->addHeader("Content-type", getFileType(".html"));
        response->sendDataFunc = sendDir;
    }
    else{
        // 发送文件内容
        response->addHeader("Content-type", getFileType(file));
        response->addHeader("Content-length", std::to_string(st.st_size));
        response->sendDataFunc = sendFile;
    }

    return false;
}

// 解码字符串
std::string HttpRequest::decodeMsg(const std::string& msg){
    std::string str;
    str.reserve(msg.size()); // 预留足够的空间，减少内存重新分配
    for(size_t i = 0; i < msg.size(); ++i){
        if(msg[i] == '%' && i + 2 < msg.size() && 
            std::isxdigit(msg[i+1]) && std::isxdigit(msg[i+2]))
        {
            // 处理%后面的两位十六进制数字
            char decodedChar = (hexToDec(msg[i+1] << 4) | hexToDec(msg[i+2]));
            str.push_back(decodedChar);
            i+=2; // 跳过处理过的字符
        }else{
            // 处理普通字符
            str.push_back(msg[i]);
        }
    }
    return str;
}

const std::string HttpRequest::getFileType(const std::string& name){
    auto dotPos = name.find('.');
    if(dotPos == std::string::npos){
        return "text/plain; charset=utf-8";
    }
    // 提取扩展名并将其转换为小写
    std::string extension = name.substr(dotPos + 1);
    std::transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
    // 查找MIME类型
    auto it = mimeTypes.find(extension);
    if(it != mimeTypes.end()){
        return it->second;
    }
    return "text/plain; charset=utf-8";
   
}

void HttpRequest::sendDir(const std::string& dirName, Buffer* sendBuf, int cfd){
    std::string html = "<html><head><title>" + dirName + "</title></head><body><table>";
    struct dirent** nameList;
    // 使用智能指针确保nameList的内存自动释放
    std::unique_ptr<struct dirent*, decltype(&free)> nameListWrapper(nullptr, free);
    
    int num = scandir(dirName.c_str(), &nameList, nullptr, alphasort);
    if(num < 0){
        return;
    }
    nameListWrapper.reset(nameList); // 将 nameList指针托管给unique_ptr

    for(int i = 0; i < num; ++i){
        // 取出文件名，nameList 指向的是一个指针数组 struct dirent* tmp[]

        std::string name = nameList[i]->d_name;
        struct stat st;
        std::string subPath = dirName + "/" + name;
        if(stat(subPath.c_str(), &st) == -1){
            // 忽略stat失败的文件
            free(nameList[i]);
            continue;
        }
        if(S_ISDIR(st.st_mode)){
            html += "<tr><td><a href=\"" + name + "/\">" + name + "</a></td><td>" + std::to_string(st.st_size) + "</td></tr>";
        }else{
            html += "<tr><td><a href=\"" + name + "\">" + name + "</a></td><td>" + std::to_string(st.st_size) + "</td></tr>";
        }

        sendBuf->appendString(html);
#ifndef MSG_SEND_AUTO
        sendBuf->sendData(cfd);
#endif
        html.clear();
        free(nameList[i]);
    }
    html = "</table></body></html>";
    sendBuf->appendString(html);
#ifndef MSG_SEND_AUTO
    sendBuf->sendData(cfd);
#endif
}

void HttpRequest::sendFile(const std::string& fileName, Buffer* sendBuf, int cfd){
    // 1.打开文件
    int fd = open(fileName.data(), O_RDONLY);
    if(fd < 0){
        perror("Failed to open file");
        return;
    }
#if 1
    std::array<char, 4096> buf;
    while(true){
        int len = read(fd, buf.data(), buf.size());
        if(len > 0){
            sendBuf->appendString(buf.data(), len);
#ifndef MSG_SEND_AUTO
            sendBuf->sendData(cfd);
#endif
        }
        else if(len == 0){
            break;
        }
        else{
            perror("read");
            close(fd);
            return;
        }
    }
#else
    off_t offset = 0;
    int size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    while(offset < size){
        int ret = sendFile(cfd, fd, &offset, size - offset);
        if(ret == -1 && errno == EAGAIN){
            std::cout << "没有可读数据...\n";
        }
    }
#endif
    close(fd);
}


char* HttpRequest::splitRequestLine(const char* start, const char* end,
                                    const char* sub, std::function<void(std::string)> callback)
{
    char* space = const_cast<char*>(end);
    if(sub != nullptr){
        space = static_cast<char*>(memmem(start, end-start, sub, strlen(sub)));
        assert(space != nullptr);
    }
    callback(std::string(start, space - start));
    return space + 1;
}


int HttpRequest::hexToDec(char c){
    if(std::isdigit(c)){
        return c - '0';
    }
    else if(std::isxdigit(c)){
        return std::tolower(c) - 'a' + 10;
    }
    return 0;
}

const std::unordered_map<std::string, std::string> HttpRequest::mimeTypes = {
    { "html", "text/html; charset=utf-8" },
    { "htm", "text/html; charset=utf-8" },
    { "jpg", "image/jpeg" },
    { "jpeg", "image/jpeg" },
    { "gif", "image/gif" },
    { "png", "image/png" },
    { "css", "text/css" },
    { "au", "audio/basic" },
    { "wav", "audio/wav" },
    { "avi", "video/x-msvideo" },
    { "mov", "video/quicktime" },
    { "qt", "video/quicktime" },
    { "mpeg", "video/mpeg" },
    { "mpe", "video/mpeg" },
    { "vrml", "model/vrml" },
    { "wrl", "model/vrml" },
    { "midi", "audio/midi" },
    { "mid", "audio/midi" },
    { "mp3", "audio/mpeg" },
    { "ogg", "application/ogg" },
    { "pac", "application/x-ns-proxy-autoconfig" }
};