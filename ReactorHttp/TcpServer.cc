#include "TcpServer.h"
#include "TcpConnection.h"
#include "ThreadPool.h"
#include "Log.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

TcpServer::TcpServer(unsigned short port, int threadNum)
{
    m_port = port;
    m_threadNum = threadNum;
    m_mainLoop = new EventLoop;
    m_threadPool = new ThreadPool(m_mainLoop, threadNum);
    setListen();
}
// 初始化监听
void TcpServer::setListen(){
    // 1.创建监听的fd
    m_lfd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_lfd == -1){
        perror("socket");
        return;
    } else {
        printf("Socket created successfully, m_lfd = %d\n", m_lfd);
    }
    // 2.设置端口复用
    int opt = 1;
    int ret = setsockopt(m_lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    if(ret == -1){
        perror("setsockopt SO_REUSEADDR");
        return;
    }
    // 3.绑定
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(m_port);
    addr.sin_addr.s_addr = INADDR_ANY;
    ret = bind(m_lfd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret == -1){
        perror("bind failed");
        return;
    }
    // 4.设置监听
    ret = listen(m_lfd, 128);
    if (ret == -1) {
        perror("listen failed");
        return;
    }
}

// 启动服务器
void TcpServer::run(){
    Debug("服务器程序已经启动了...");
    // 启动线程池
    m_threadPool->run();
    // 添加检测的任务
    // 初始化一个channel实例
    auto channel = new Channel(m_lfd, FDEvent::ReadEvent, accepetConnection,nullptr, nullptr, this);
    m_mainLoop->addTask(channel, ElemType::ADD);
    // 启动反应堆模型
    m_mainLoop->run();
}

int TcpServer::accepetConnection(void* arg){
    TcpServer* server = static_cast<TcpServer*>(arg);
    // 和客户端建立连接
    int cfd = accept(server->m_lfd, NULL, NULL);
    if(cfd == -1){
        perror("TcpServer::acceptConnection accpet");
        return -1;
    }
    
    // 从线程池中取出一个子线程的反应实例，去处理这个cfd
    auto loop = server->m_threadPool->takeWorkerEventLoop();
    if (!loop) {
        Debug("Failed to get worker EventLoop from ThreadPool");
        return -1;
    }
    // 将cfd放到TcpConnection中处理
    new TcpConnection(cfd, loop);
    return 0;
}