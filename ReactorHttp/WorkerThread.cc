#include "WorkerThread.h"
#include "Dispatcher.h"
#include "EpollDispatcher.h"
#include "PollDispatcher.h"
#include "SelectDispatcher.h"
#include <stdio.h>

WorkerThread::WorkerThread(int index)
    : m_loop(nullptr)
    , m_thread(nullptr)
    , m_threadID(std::thread::id())
    , m_name("SubThread-" + std::to_string(index))
{
    
}

WorkerThread::~WorkerThread(){
    if (m_thread != nullptr && m_thread->joinable())
    {
        m_thread->join();
    }
}

// 启动线程
void WorkerThread::run(){
    // 创建子线程
    m_thread = new std::thread(&WorkerThread::running, this);
    // 阻塞主线程, 让当前函数不会直接结束
    std::unique_lock<std::mutex> locker(m_mtx);
    while (m_loop == nullptr)
    {
        m_cond.wait(locker);
    }
}

void WorkerThread::running(){
    {
        std::lock_guard<std::mutex> lock(m_mtx);
        m_loop = new EventLoop(m_name);
    }
    m_cond.notify_one();
    m_loop->run();
}