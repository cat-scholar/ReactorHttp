#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include "EventLoop.h"

// 定义子线程对应的类
class WorkerThread{
public:
    WorkerThread(int index);
    ~WorkerThread();
    // 启动线程
    void run();
    inline EventLoop* getEventLoop(){
        std::lock_guard<std::mutex> lock(m_mtx);
        return m_loop;
    }
private:
    void running();
private:
    std::thread* m_thread;
    std::thread::id m_threadID;
    std::string m_name;
    std::condition_variable m_cond;
    std::mutex m_mtx;
    EventLoop* m_loop;
};