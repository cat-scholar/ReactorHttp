#include "ThreadPool.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

ThreadPool::ThreadPool(EventLoop* mainLoop, int count)
    : m_mainLoop(mainLoop), m_threadNum(count), m_index(0), m_isStart(false)
{
    m_workerThreads.reserve(count); // 提前分配空间
}

ThreadPool::~ThreadPool(){
  
 }
 
// 启动线程池
void ThreadPool::run(){
    assert(!m_isStart);
    
    if(m_mainLoop->getThreadID() != std::this_thread::get_id()){
        printf("Error: run() should be called from the main thread\n");
        exit(0);
    }
    m_isStart = true;
    if(m_threadNum > 0){
        for (int i = 0; i < m_threadNum; ++i)
        {
            auto subThread = std::make_unique<WorkerThread>(i);
            subThread->run();
            m_workerThreads.push_back(std::move(subThread));
        }
    }
    
}
// 取出线程池中的某一个子线程的反应堆实例
EventLoop* ThreadPool::takeWorkerEventLoop(){
    assert(m_isStart);
    if(m_mainLoop->getThreadID() != std::this_thread::get_id()){
        exit(0);
    }
     // 从线程池中找到一个子线程，然后取出里面的反应堆实例
    EventLoop* loop = m_mainLoop;
    if(m_threadNum > 0){
        loop = m_workerThreads[m_index]->getEventLoop();
        m_index = ( m_index + 1) % m_threadNum;
    }
    return loop;
}
