#pragma once
#include "EventLoop.h"
#include "Channel.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "Buffer.h"
#include <memory>
class TcpConnection{
public:
    TcpConnection(int fd, EventLoop* loop);
    ~TcpConnection();
    static int processRead(void* arg);
    static int processWrite(void* arg);
    static int destory(void* arg);
private:
    std::string m_name;
    EventLoop* m_loop;
    Channel* m_channel;
    std::unique_ptr<Buffer> m_readBuf;
    std::unique_ptr<Buffer> m_writeBuf;
    // http协议
    std::unique_ptr<HttpRequest> m_request;
    std::unique_ptr<HttpResponse> m_response;
};