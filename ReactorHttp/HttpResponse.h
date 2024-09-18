#pragma once
#include "Buffer.h"
#include "HttpRequest.h"
#include <map>
#include <functional>
#include <sstream>

enum class StatusCode{
    Unknown,
    OK = 200,
    MovedPermanently = 301,
    MovedTemporarily = 302,
    BadRequest = 400,
    Forbidden = 403,
    NotFound = 404
};
class HttpRequest;
class HttpResponse{
public:
    HttpResponse();
    ~HttpResponse() = default;
    std::function<void(const std::string, struct Buffer*, int)> sendDataFunc;
    // 添加响应头
    void addHeader(const std::string& key, const std::string& value);
    void prepareMsg(Buffer* sendBuf, int socket, HttpRequest* request);
    inline void setFileName(const std::string name){
        m_fileName = name;
    }
    inline void setStatusCode(const StatusCode code){
        m_statusCode = code;
    }

private:
    // 状态行：状态码，状态描述
    StatusCode m_statusCode;
    std::string m_fileName;
    // 响应头--键值对
    std::map<std::string, std::string> m_headers;
    // 定义状态码和描述的对应关系
    const std::map<int, std::string> m_info ={
        {200, "OK"},
        {301, "MovedPermanently"},
        {302, "MovedTemporarily"},
        {400, "BadRequest"},
        {404, "NotFound"},
    };
};