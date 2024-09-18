#include "Channel.h"
#include <stdlib.h>


Channel::Channel(int fd, FDEvent events, handleFunc readFunc, handleFunc writeFunc, handleFunc destroyFunc, void* arg)
    : m_arg(arg)
    , m_fd(fd)
    , m_events((int)events)
    , readCallback(readFunc)
    , writeCallback(writeFunc)
    , destroyCallback(destroyFunc)
{
    if (m_fd <= 0) {
        printf("Error: Invalid file descriptor in Channel constructor, m_fd = %d\n", m_fd);
        exit(1);
    }
    if (!readCallback) {
        printf("Error: readCallback is null\n");
        exit(1);
    }
    if (!m_arg) {
        printf("Error: m_arg is null\n");
        exit(1);
    }
}

void Channel::writeEventEnable(bool flag){
    if(flag){
        //m_events |= (int)FDEvent::WriteEvent;
        m_events |= static_cast<int>(FDEvent::WriteEvent);
    }else{
        m_events &= ~static_cast<int>(FDEvent::WriteEvent);
    }
}


bool Channel::isWriteEventEnable(){
    return m_events & static_cast<int>(FDEvent::WriteEvent);
}
