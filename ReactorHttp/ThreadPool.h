#pragma once
#include "WorkerThread.h"
#include "EventLoop.h"
#include <stdbool.h>
#include <functional>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <assert.h>
#include <vector>

// 定义线程池
class ThreadPool{
public:
    ThreadPool(EventLoop* mainLoop, int count);
    ~ThreadPool();
    // 启动线程池
    void run();
    // 取出线程池中的某一个子线程的反应堆实例
    EventLoop* takeWorkerEventLoop();
    
private:
    // 主线程的反应堆模型
    EventLoop* m_mainLoop;
    bool m_isStart;
    std::condition_variable m_cond;
    std::mutex m_mtx;
    std::queue<std::function<void()>> m_taskQueue;
    int m_threadNum;
    std::vector<std::unique_ptr<WorkerThread>> m_workerThreads;
    
    int m_index;
};