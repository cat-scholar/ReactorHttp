#pragma once
#include "Channel.h"
#include "EventLoop.h"
#include "Dispatcher.h"

#include <string>
#include <sys/select.h>

class SelectDispatcher : public Dispatcher{
public:
    SelectDispatcher(EventLoop* loop);
    ~SelectDispatcher();
    // 添加
    int add() override;
    // 删除
    int remove() override;
    // 修改
    int modify() override;
    // 监听事件
    int dispatch(int timeout = 2) override;

private:
    void setFdSet();
    void clearFdSet();

private:
    fd_set m_readSet;
    fd_set m_writeSet;
    const int m_maxSize = 1024;
};