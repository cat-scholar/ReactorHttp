#include "TcpConnection.h"
#include "EventLoop.h"
#include "Log.h"

TcpConnection::TcpConnection(int fd, EventLoop* loop)
    : m_loop(loop)
    , m_readBuf(new Buffer(10240))
    , m_writeBuf(new Buffer(10240))
    , m_request(new HttpRequest())
    , m_response(new HttpResponse())
    , m_name("Connection-" + std::to_string(fd))
    ,m_channel(new Channel(fd, FDEvent::ReadEvent, processRead, processWrite, destory, this))
{
    loop->addTask(m_channel, ElemType::ADD);
}

TcpConnection::~TcpConnection(){
    m_loop->freeChannel(m_channel);
    // Debug("连接断开, 释放资源! connName: %s", m_name.c_str());
}

int TcpConnection::processRead(void* arg){
    TcpConnection *conn = static_cast<TcpConnection*>(arg);
    // 接收数据
    int socket = conn->m_channel->getSocket();
    int count = conn->m_readBuf->socketRead(socket);

    if(count > 0){
        // 接收到了http请求，解析http请求
#ifdef MSG_SEND_AUTO
        conn->m_channel->writeEventEnable(true);
        conn->m_loop->addTask(conn->m_channel, ElemType::MODIFY);
#endif
        bool flag = conn->m_request->parseHttpRequest(conn->m_readBuf.get(), 
                                                      conn->m_response.get(),
                                                      conn->m_writeBuf.get(),
                                                      socket
                                                    );
        if(!flag){
            // 解析失败
            std::string errMsg = "Http/1.1 400 Bad Request\r\n\r\n";
            conn->m_writeBuf->appendString(errMsg);
        }
        
    }
    else{

#ifdef MSG_SEND_AUTO
        // 断开连接
        conn->m_channel->writeEventEnable(true);
        conn->m_loop->addTask(conn->m_channel, ElemType::MODIFY);
#endif
    }

#ifndef MSG_SEND_AUTO
    conn->m_loop->addTask(conn->m_channel, ElemType::DELETE);
#endif

    return 0;
}

int TcpConnection::processWrite(void* arg){
    // Debug("开始发送数据了(基于写事件发送)...");
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    // 发送数据
    int count = conn->m_writeBuf->sendData(conn->m_channel->getSocket());
    if(count > 0 && conn->m_writeBuf->readableSize() == 0){
        // 判断数据是否被全部发送出去了
        
        // 1.不在检测写事件 -- 修改channel中保存的事件
        conn->m_channel->writeEventEnable(false);
        // 2.修改dispatch检测的集合 -- 添加任务节点
        conn->m_loop->addTask(conn->m_channel, ElemType::MODIFY);
        // 3.删除这个节点
        // conn->m_loop->addTask(conn->m_channel, ElemType::DELETE);
        
    }
    return 0;
}

int TcpConnection::destory(void* arg){
    TcpConnection* conn = static_cast<TcpConnection*>(arg);
    if(conn){
        delete conn;
    }
    return 0;
}