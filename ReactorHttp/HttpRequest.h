#pragma once
#include "Buffer.h"
#include "HttpResponse.h"
#include <functional>
#include <unordered_map>
#include <stdbool.h>

// 当前的解析状态
enum class PrecessState:char{
    ParseReqLine,
    ParseReqHeaders,
    ParseReqBody,
    ParseReqDone
};
class HttpResponse;
class HttpRequest{
public:
    HttpRequest();
    ~HttpRequest();
    // 重置
    void reset();
    // 添加请求头
    void addHeader(const std::string key, const std::string value);
    // 根据key得到请求头的value
    std::string getHeader(const std::string key);
    // 解析请求行
    bool parseRequestLine(Buffer* readBuf);

    // 解析请求头
    bool parseRequestHeader(Buffer* readBuf);
    // 解析http请求协议
    bool parseHttpRequest(Buffer* readBuf, HttpResponse* response, Buffer* sendBuf, int socket);

    // 处理http请求协议
    bool processHttpRequest(HttpResponse* response);
    // 解码字符串
    std::string decodeMsg(const std::string& msg);
    const std::string getFileType(const std::string& name);
    static void sendDir(const std::string& dirName, Buffer* sendBuf, int cfd);
    static void sendFile(const std::string& fileName, Buffer* sendBuf, int cfd);
    inline void setMethod(const std::string& method){
        m_method = method;
    }
    inline void seturl(std::string url){
        m_url = url;
    }
    inline void setVersion(std::string version){
        m_version = version;
    }
    
    const std::string getVersion() const {
        return m_version;
    }
    std::string getHeader(const std::string& key) const {
        auto it = m_reqHeaders.find(key);
        if (it != m_reqHeaders.end()) {
            return it->second;
        }
        return "";
    }
    // 获取处理状态
    inline PrecessState getState(){
        return m_curState;
    }
    inline void setState(PrecessState state){
        m_curState = state;
    }

private:
    char* splitRequestLine(const char* start, const char* end,
        const char* sub, std::function<void(std::string)> callback);
    int hexToDec(char c);

    static const std::unordered_map<std::string, std::string> mimeTypes;
private:
    std::string m_method;
    std::string m_url;
    std::string m_version;
    std::string m_connection;
    std::unordered_map<std::string, std::string> m_reqHeaders;
    PrecessState m_curState;
};
