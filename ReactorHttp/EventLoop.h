#pragma once
#include "Dispatcher.h"
#include "Channel.h"
#include <thread>
#include <queue>
#include <memory>
#include <unordered_map>
#include <mutex>

// 处理该节点中的channel的方式
enum class ElemType:char{
    ADD, DELETE, MODIFY
};

// 定义任务队列的节点
struct ChannelElement{
    ElemType type; // 如何处理该节点中的channel
    Channel* channel;
};

class Dispatcher;

class EventLoop{
public:
    EventLoop();
    EventLoop(const std::string threadName);
    ~EventLoop();
    // 启动反应堆模型
    int run();
    // 处理激活的文件fd
    int eventActive(int fd, int event);
    // 添加任务到任务队列
    int addTask(Channel* channel, ElemType type);
    // 处理任务队列中的任务
    int processTaskQ();
    // 处理disppatcher中的节点
    int add(Channel* channel);
    int remove(Channel* channel);
    int modify(Channel* channel);
    // 释放channel
    int freeChannel(Channel* channel);
    int readMessage(void* arg);
    // 返回线程ID
    inline std::thread::id getThreadID(){
        return m_threadID;
    }
    inline std::string getThreadName(){
        return m_threadName;
    }
    bool hasPendingTasks() const;
    static int readLocalMessage(void* arg);
private:
    void taskWakeup();
private:
    bool m_isQuit;
    // 该指针指向子类的实例 epoll poll select
    Dispatcher* m_dispatcher;
    // 任务队列
    std::queue<std::unique_ptr<ChannelElement>> m_taskQ;
    // map
    std::unordered_map<int, Channel*> m_channelMap;
    // 线程id，name，mutex
    std::thread::id m_threadID;
    std::string m_threadName;
    mutable std::mutex m_mtx;
    int m_socketPair[2]; // 存储本地通信的fd通过socketpair初始化
};