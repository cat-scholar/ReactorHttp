#include "SelectDispatcher.h"
#include "Dispatcher.h"

#include <sys/select.h>
#include <stdio.h>
#include <stdlib.h>

SelectDispatcher::SelectDispatcher(EventLoop* loop) : Dispatcher(loop){
    FD_ZERO(&m_readSet);
    FD_ZERO(&m_writeSet);
    m_name = "Select";
}

SelectDispatcher::~SelectDispatcher(){

}
// 添加
int SelectDispatcher::add(){
    if(m_channel->getSocket() >= m_maxSize){
        return -1;
    }
    setFdSet();
    return 0;
}
// 删除
int SelectDispatcher::remove(){
    clearFdSet();
    // 通过channel释放对应的TcpConection资源
    m_channel->destroyCallback(const_cast<void*>(m_channel->getArg()));

    return 0;
}
// 修改
int SelectDispatcher::modify(){
    setFdSet();
    clearFdSet();
    return 0;
}

// 监听事件
int SelectDispatcher::dispatch(int timeout){
    struct timeval val;
    val.tv_sec = timeout;
    val.tv_usec = 0;
    fd_set rdtmp = m_readSet;
    fd_set wrtmp = m_writeSet;
    int count = select(m_maxSize, &rdtmp, &wrtmp, NULL, &val);
    if(count == -1){
        perror("select");
        exit(0);
    }
    for(int i = 0; i < m_maxSize; ++i){
        if(FD_ISSET(i, &rdtmp)){
            m_loop->eventActive(i, (int)FDEvent::ReadEvent);
        }
        if(FD_ISSET(i, &wrtmp)){
            m_loop->eventActive(i, (int)FDEvent::WriteEvent);
        }
    }
    return 0;
}


void SelectDispatcher::setFdSet(){
    if(m_channel->getEvent() & (int)FDEvent::ReadEvent){
        FD_SET(m_channel->getSocket(), &m_readSet);
    }
    if(m_channel->getEvent() & (int)FDEvent::WriteEvent){
        FD_SET(m_channel->getSocket(), &m_writeSet);
    }
}

void SelectDispatcher::clearFdSet(){
    if(m_channel->getEvent() & (int)FDEvent::ReadEvent){
        FD_CLR(m_channel->getSocket(), &m_readSet);
    }
    if(m_channel->getEvent() & (int)FDEvent::WriteEvent){
        FD_CLR(m_channel->getSocket(), &m_writeSet);
    }
}
