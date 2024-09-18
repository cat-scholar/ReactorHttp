#pragma once
#include "Channel.h"
#include "EventLoop.h"
#include <string>
#include <memory>
class EventLoop;
class Dispatcher{
public:
    Dispatcher(EventLoop* loop);
    virtual ~Dispatcher();
    // 添加
    virtual int add();
    // 删除
    virtual int remove();
    // 修改
    virtual int modify();
    // 事件监听
    virtual int dispatch(int timeout = 2); // 单位：s
    inline void setChannel(Channel* channel){
        m_channel = channel;
    }

protected:
    Channel* m_channel;
    EventLoop* m_loop;
    std::string m_name = std::string();
};