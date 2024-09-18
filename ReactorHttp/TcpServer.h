#pragma once
#include "EventLoop.h"
#include "ThreadPool.h"

class TcpServer{
public:
    TcpServer(unsigned short port, int threadNum);
    ~TcpServer() = default;
    // 初始化监听
    void setListen();
    // 启动服务器
    void run();
    static int accepetConnection(void* arg);
private:
    int m_threadNum;
    EventLoop* m_mainLoop;
    ThreadPool* m_threadPool;
    int m_lfd;
    unsigned short m_port;
};