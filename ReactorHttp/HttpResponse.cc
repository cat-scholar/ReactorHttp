#include "HttpResponse.h"

HttpResponse::HttpResponse()
{
    m_statusCode = StatusCode::Unknown;
    m_fileName = std::string();
    m_headers.clear();
    sendDataFunc = nullptr;
    
}

// 添加响应头
void HttpResponse::addHeader(const std::string& key, const std::string& value){
    if(key.empty() || value.empty())
        return;
    m_headers.insert(std::make_pair(key, value));
}

void HttpResponse::prepareMsg(Buffer* sendBuf, int socket,HttpRequest* request){
    char tmp[4096] = {0};
    int code = static_cast<int>(m_statusCode);
    sprintf(tmp, "HTTP/1.1 %d %s\r\n", code, m_info.at(code).data());
    sendBuf->appendString(tmp);

    for(auto it = m_headers.begin(); it != m_headers.end(); ++it){
        sprintf(tmp, "%s: %s\r\n", it->first.data(), it->second.data());
        sendBuf->appendString(tmp);
    }
    
    
     // Check the HTTP version and connection header from the HttpRequest
    std::string connectionHeader = request->getHeader("Connection");
    if (request->getVersion() == "HTTP/1.1" && connectionHeader != "close") {
        addHeader("Connection", "keep-alive");
        addHeader("Keep-Alive", "timeout=5, max=100");  // Optional: set timeout and max requests
    } else {
        // For HTTP/1.0 or explicitly closed connections, add Connection: close
        addHeader("Connection", "close");
    }

    sendBuf->appendString("\r\n");
#ifndef MSG_SEND_AUTO
    sendBuf->sendData(socket);
#endif
    // 回复的数据
    sendDataFunc(m_fileName, sendBuf, socket);
}