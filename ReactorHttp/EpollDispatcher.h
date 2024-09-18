#pragma once
#include "Channel.h"
#include "EventLoop.h"
#include "Dispatcher.h"

#include <string>
#include <sys/epoll.h>

class EpollDispatcher : public Dispatcher{
public:
    EpollDispatcher(EventLoop* loop);
    ~EpollDispatcher();
    // 添加
    int add() override;
    // 删除
    int remove() override;
    // 修改
    int modify() override;
    // 事件监听
    int dispatch(int timeout = 2) override; // 单位（s)
    
private:
    int epollCtl(int op);

private:
    int m_epfd;
    struct epoll_event* m_events;
    const int m_maxNode = 520;
};