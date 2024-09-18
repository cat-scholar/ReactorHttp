#pragma once

#include <string>
#include <vector>
#include <memory>

class Buffer{
public:
    Buffer(int size);
    ~Buffer() = default; 

    

    // 写内存 1.直接写 2.接受套接字数据
    int appendString(const char* data, int size);
    int appendString(const char* data);
    int appendString(const std::string& data);
    int socketRead(int fd);
    // 根据\r\n取出一行，找到其在数据块中的位置，返回该位置
    char* findCRLF();

    // 发送数据
    int sendData(int socket); // 指向内存的指针

    // 得到剩余的可写的内容容量
    inline int writeableSize(){
        return m_capacity - m_writePos;
    }

    // 得到剩余的可读的内存容量
    inline int readableSize(){
        return m_writePos - m_readPos;
    }
    inline char* data() {
        return m_data.get() + m_readPos;  // 返回当前读取位置的指针
    }
    inline int readPosincrease(int size) {
        m_readPos += size;  // 增加读取位置
        return m_readPos;
    }
private:
    // 扩容
    void extendRoom(int size);
    
private:
    std::unique_ptr<char[]> m_data; // 使用智能指针管理内存
    int m_capacity=0;
    int m_readPos=0;
    int m_writePos=0;
};