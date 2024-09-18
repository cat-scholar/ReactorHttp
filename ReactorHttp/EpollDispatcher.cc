#include "Dispatcher.h"
#include "EpollDispatcher.h"

#include <sys/epoll.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

EpollDispatcher::EpollDispatcher(EventLoop* loop) : Dispatcher(loop){
    m_epfd = epoll_create(10);
    if(m_epfd == -1){
        perror("epoll_create");
        exit(0);
    }
    m_events = new struct epoll_event[m_maxNode];
    m_name = "Epoll";
}
EpollDispatcher::~EpollDispatcher(){
    close(m_epfd);
    delete[] m_events;
}
// 添加
int EpollDispatcher::add() {
    int ret = epollCtl(EPOLL_CTL_ADD);
    if(ret == -1){
        perror("epoll_ctl_add");
        exit(0);
    }
    return ret;
}
// 删除
int EpollDispatcher::remove() {
    int ret = epollCtl(EPOLL_CTL_DEL);
    if(ret == -1){
        perror("epoll_ctl_del");
    }
    // 通过channel释放对应的TcpConnection资源
    m_channel->destroyCallback(const_cast<void*>(m_channel->getArg()));
    return ret;
}

// 修改
int EpollDispatcher::modify() {
    int ret = epollCtl(EPOLL_CTL_MOD);
    if(ret == -1){
        perror("epoll_ctl_mod");
    }
    return ret;
}

// 事件监听
int EpollDispatcher::dispatch(int timeout) {
    int count = epoll_wait(m_epfd, m_events, m_maxNode, timeout * 1000);
    if (count == -1) {
        perror("epoll_wait failed");
        return -1;
    }
    for(int i = 0; i < count; ++i){
        int events = m_events[i].events;
        int fd = m_events[i].data.fd;
        if(events & EPOLLERR || events & EPOLLHUP){
            // 对方断开了连接，删除fd
            continue;
        }
        if(events & EPOLLIN){
            m_loop->eventActive(fd, (int)FDEvent::ReadEvent);
        }
        if(events & EPOLLOUT){
            m_loop->eventActive(fd, (int)FDEvent::WriteEvent);
        }
    }
    return 0;
}


int EpollDispatcher::epollCtl(int op){
    struct epoll_event epevent;
    memset(&epevent, 0, sizeof(epevent));
    epevent.data.fd = m_channel->getSocket();
    int events = 0;
    // 既有读事件发生，又有写事件发生，不能if else
    if(m_channel->getEvent() & (int)FDEvent::ReadEvent){
        events |= EPOLLIN;
    }
    if(m_channel->getEvent() & (int)FDEvent::WriteEvent){
        events |= EPOLLOUT;
    }
    // 默认是水平出发，添加边缘触发模式
    // events |= EPOLLET;
    epevent.events = events;
    int ret = epoll_ctl(m_epfd, op, m_channel->getSocket(), &epevent);
    if (ret == -1) {
        perror("epoll_ctl failed");
    }
    return ret;
}