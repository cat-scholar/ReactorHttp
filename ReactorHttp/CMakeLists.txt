# 设置 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 将所有的源文件添加到变量 SOURCES 中
set(SOURCES
    Buffer.cc
    Channel.cc
    Dispatcher.cc
    EpollDispatcher.cc
    PollDispatcher.cc
    SelectDispatcher.cc
    EventLoop.cc
    HttpRequest.cc
    HttpResponse.cc
    main.cc
    TcpConnection.cc
    TcpServer.cc
    ThreadPool.cc
    WorkerThread.cc
)

# 将头文件路径添加到 include 目录
include_directories(${CMAKE_SOURCE_DIR})

# 链接 pthread 库
find_package(Threads REQUIRED)

# 生成可执行文件
add_executable(reactorhttp ${SOURCES})
# 链接 pthread 库到可执行文件
target_link_libraries(reactorhttp PRIVATE Threads::Threads)

# 添加额外的调试信息和优化标志
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Build type is Debug")
    target_compile_options(reactorhttp PRIVATE -g -O0)  # 启用调试信息，关闭优化
endif()