#pragma once
#include "Channel.h"
#include "EventLoop.h"
#include "Dispatcher.h"

#include <string>
#include <poll.h>

class PollDispatcher : public Dispatcher{
public:
    PollDispatcher(EventLoop* loop);
    ~PollDispatcher();
    // 添加
    int add() override;
    // 删除
    int remove() override;
    // 修改
    int modify() override;
    // 监听事件
    int dispatch(int timeout = 2) override;
private:
    int m_maxfd;
    struct pollfd *m_fds;
    const int m_maxNode = 1024;
};