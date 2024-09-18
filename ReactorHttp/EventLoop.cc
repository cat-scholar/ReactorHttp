#include "EventLoop.h"
#include "EpollDispatcher.h"
#include "SelectDispatcher.h"
#include "PollDispatcher.h"
#include "Channel.h"
#include <assert.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

EventLoop::EventLoop() : EventLoop(std::string()){

}

EventLoop::EventLoop(const std::string threadName){
    m_isQuit = true;
    m_threadID = std::this_thread::get_id();
    m_threadName = threadName == std::string() ? "MainThread" : threadName;
    m_dispatcher = new EpollDispatcher(this);
    m_channelMap.clear();
    int ret = socketpair(AF_UNIX, SOCK_STREAM, 0, m_socketPair);
    if(ret == -1){
        perror("socketpair");
        return;
    }
#if 0
    // 指定规则：loop->socketPair[0] 发送数据 loop->socketPair[1] 接收数据
    auto channel =new Channel(m_socketPair[1], FDEvent::ReadEvent,
                                    readLocalMessage, nullptr, nullptr, this);
#else
    // 绑定 -bind
    auto obj = std::bind(&EventLoop::readMessage, this, std::placeholders::_1);
    
    auto channel =new Channel(m_socketPair[1], FDEvent::ReadEvent,
                                    obj, nullptr, nullptr, this);
    if (!channel){
        printf("Error: Failed to create Channel\n");
    }
#endif
    addTask(channel, ElemType::ADD);

}

EventLoop::~EventLoop(){

}

bool EventLoop::hasPendingTasks() const{
    {
        std::lock_guard<std::mutex> lock(m_mtx);
        return !m_taskQ.empty();
    }
}

// 启动反应堆模型
int EventLoop::run(){
    m_isQuit = false;
    // 比较线程ID是否是正常的
    if(m_threadID != std::this_thread::get_id()){
        return -1;
    }
    // 循环进行处理事件
    while(!m_isQuit){
        m_dispatcher->dispatch();
        processTaskQ();
    }
    return 0;
}

// 处理激活的文件fd
int EventLoop::eventActive(int fd, int event){
    if(fd < 0){
        return -1;
    }
    // std::lock_guard<std::mutex> lock(m_mtx);  // 确保线程安全访问m_channelMap
    auto it = m_channelMap.find(fd);
    if (it == m_channelMap.end()) {
        fprintf(stderr, "Error: Channel not found for fd %d\n", fd);
        return -1;
    }
    // 取出channel
    Channel* channel = it->second;
    assert(channel->getSocket() == fd);
    if(event & (int)FDEvent::ReadEvent && channel->readCallback){
        channel->readCallback(const_cast<void*>(channel->getArg()));
    }
    if(event & (int)FDEvent::WriteEvent && channel->writeCallback){
        channel->writeCallback(const_cast<void*>(channel->getArg()));
    }
    return 0;
}

// 添加任务到任务队列
int EventLoop::addTask(Channel* channel, ElemType type){
    // 加锁， 保护共享资源
    std::unique_lock<std::mutex> lock(m_mtx);
    // 创建新节点
    auto node = std::make_unique<ChannelElement>();
    node->channel = channel;
    node->type = type;
    m_taskQ.push(std::move(node));
    lock.unlock();
    // 处理细节
    /**
     * 1.对于链表节点的添加，可能是当前线程也可能是其他线程（主线程）
     * 1) 修改fd的事件，当前子线程发起，当前子线程处理
     * 2) 添加新的fd，添加任务节点的操作是由主线程发起的
     * 2. 不能让主线程处理任务队列，需要由当前的子线程去处理
     */
    if(m_threadID == std::this_thread::get_id()){
        // 当前子线程（基于子线程的角度分析）
        processTaskQ();
    }else{
        // 主线程 -- 告诉子线程处理任务队列中的任务
        taskWakeup();
    }
    return 0;
}

// 处理任务队列中的任务
int EventLoop::processTaskQ(){
    // 取出头结点
    while(!m_taskQ.empty()){
        std::unique_lock<std::mutex> lock(m_mtx);
        auto node = std::move(m_taskQ.front());
        m_taskQ.pop();
        lock.unlock();

        Channel* channel = node->channel;
        if(node->type == ElemType::ADD){
            add(channel);
        }
        else if(node->type == ElemType::DELETE){
            remove(channel);
        }
        else if(node->type == ElemType::MODIFY){
            modify(channel);
        }
    }
    return 0;
}

// 处理disppatcher中的节点
int EventLoop::add(Channel* channel){
    int fd = channel->getSocket();
    // 找到fd对应的数组元素位置，并存储
    if(m_channelMap.find(fd) == m_channelMap.end()){
        m_channelMap.insert(std::make_pair(fd, channel));
        m_dispatcher->setChannel(channel);
        int ret = m_dispatcher->add();
        return ret;
    }
    return -1;
}

int EventLoop::remove(Channel* channel){
    int fd = channel->getSocket();
    if(m_channelMap.find(fd) == m_channelMap.end()){
        return -1;
    }
    m_dispatcher->setChannel(channel);
    int ret = m_dispatcher->remove();
    return ret;
}

int EventLoop::modify(Channel* channel){
    int fd = channel->getSocket();
    if(m_channelMap.find(fd) == m_channelMap.end()){
        return -1;
    }
    m_dispatcher->setChannel(channel);
    int ret = m_dispatcher->modify();
    return ret;
}

// 释放channel
int EventLoop::freeChannel(Channel* channel){
    // 删除channel和fd的对应关系
    // std::lock_guard<std::mutex> lock(m_mtx);
    auto it = m_channelMap.find(channel->getSocket());
    if(it != m_channelMap.end()){
        m_channelMap.erase(it);
        close(channel->getSocket());
    }
    return 0;
}

int EventLoop::readMessage(void * arg){
    char buf[256];
    ssize_t bytesRead = read(m_socketPair[1], buf, sizeof(buf));
    
    if (bytesRead == -1) {
        perror("read failed");
        return -1;
    }
    return 0;
}

int EventLoop::readLocalMessage(void* arg){
    EventLoop* loop = static_cast<EventLoop*>(arg);
    char buf[256];
    read(loop->m_socketPair[1], buf, sizeof(buf));
    return 0;
}

void EventLoop::taskWakeup(){
    const char* msg = "该醒了去当牛马了!";
    ssize_t ret = write(m_socketPair[0], msg, strlen(msg));
    if (ret == -1) {
        perror("write failed");
    }
}