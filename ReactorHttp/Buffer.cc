#include "Buffer.h"

#include <sys/uio.h>
#include <cstring>
#include <string>
#include <unistd.h>
#include <strings.h>
#include <stdexcept>
#include <vector>
#include <sys/socket.h>

Buffer::Buffer(int size)
    : m_data(std::make_unique<char[]>(size)),
      m_capacity(size),
      m_readPos(0),
      m_writePos(0)
{
    std::memset(m_data.get(), 0, size);
}


void Buffer::extendRoom(int size){
    // 1.内存够用 - 不需要扩容
    if(writeableSize() >= size){
        return;
    }
    // 内存需要合并才够用- 不需要扩容
    // 剩余的可写的内存 + 已读的内存 > size
    if(m_readPos + writeableSize() >= size){
        // 得到未读的内存大小
        int readable = readableSize();
        // 移动内存
        std::memmove(m_data.get(), m_data.get() + m_readPos, readable);
        // 更新位置
        m_readPos = 0;
        m_writePos = readable;
    }
    // 内存不够用 - 扩容
    else{
        // 采用倍数扩展策略，而不是直接扩展 size
        int newCapacity = m_capacity + std::max(size, m_capacity / 2);
        auto newData = std::make_unique<char[]>(newCapacity);
        std::memcmp(newData.get(), m_data.get() + m_readPos, readableSize());
        // 更新数据
        m_writePos = readableSize();
        m_readPos = 0;
        m_data = std::move(newData); // 更新指针
        m_capacity = newCapacity;
    }

}

int Buffer::appendString(const char* data, int size){
    if(data == nullptr || size <= 0){
        return -1;
    }
    // 扩容
    extendRoom(size);
    // 数据拷贝
    memcpy(m_data.get() + m_writePos, data, size);
    m_writePos += size;
    return 0;
}

int Buffer::appendString(const char* data){
    return appendString(data, std::strlen(data));
}

int Buffer::appendString(const std::string& data){
    return appendString(data.data(), data.size());
}

int Buffer::socketRead(int fd){
    // read/recv/readv
    struct iovec vec[2];
    // 初始化数组元素
    int writeable = writeableSize();
    vec[0].iov_base = m_data.get() +m_writePos;
    vec[0].iov_len = writeable;

    std::vector<char> tmpbuf(40960);
    vec[1].iov_base = tmpbuf.data();
    vec[1].iov_len = tmpbuf.size();

    int result = readv(fd, vec, 2);
    if(result == -1)
    {
        perror("readv failed");
        return -1;
    }
    else if(result == 0){
        return 0;  // 客户端关闭连接
    }
    else if(result <= writeable){
        m_writePos += result;
    }
    else{
        m_writePos = m_capacity;
        appendString(tmpbuf.data(), result - writeable);
    }
    return result;
}

// 根据\r\n取出一行，找到其在数据块中的位置，返回该位置
char* Buffer::findCRLF(){
    for(char* p = m_data.get() + m_readPos; p < m_data.get() + m_writePos - 1; ++p){
        if(*p == '\r' && *(p+1) == '\n'){
            return p;
        }
    }
    return nullptr;
}

// 发送数据
int Buffer::sendData(int socket){// 指向内存的指针
    // 判断有无数据
    int readable = readableSize();
    if(readable > 0){
        int count = send(socket, m_data.get() + m_readPos, readable, MSG_NOSIGNAL);
        if(count > 0){
            m_readPos += count;
            // usleep(1);
        }
        return count;
    }
    return 0;
}