# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zwdai/vscode/ReactorHttp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zwdai/vscode/ReactorHttp/build

# Include any dependencies generated for this target.
include CMakeFiles/reactorhttp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/reactorhttp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/reactorhttp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/reactorhttp.dir/flags.make

CMakeFiles/reactorhttp.dir/Buffer.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/Buffer.cc.o: /home/zwdai/vscode/ReactorHttp/Buffer.cc
CMakeFiles/reactorhttp.dir/Buffer.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/reactorhttp.dir/Buffer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/Buffer.cc.o -MF CMakeFiles/reactorhttp.dir/Buffer.cc.o.d -o CMakeFiles/reactorhttp.dir/Buffer.cc.o -c /home/zwdai/vscode/ReactorHttp/Buffer.cc

CMakeFiles/reactorhttp.dir/Buffer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/Buffer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/Buffer.cc > CMakeFiles/reactorhttp.dir/Buffer.cc.i

CMakeFiles/reactorhttp.dir/Buffer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/Buffer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/Buffer.cc -o CMakeFiles/reactorhttp.dir/Buffer.cc.s

CMakeFiles/reactorhttp.dir/Channel.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/Channel.cc.o: /home/zwdai/vscode/ReactorHttp/Channel.cc
CMakeFiles/reactorhttp.dir/Channel.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/reactorhttp.dir/Channel.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/Channel.cc.o -MF CMakeFiles/reactorhttp.dir/Channel.cc.o.d -o CMakeFiles/reactorhttp.dir/Channel.cc.o -c /home/zwdai/vscode/ReactorHttp/Channel.cc

CMakeFiles/reactorhttp.dir/Channel.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/Channel.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/Channel.cc > CMakeFiles/reactorhttp.dir/Channel.cc.i

CMakeFiles/reactorhttp.dir/Channel.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/Channel.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/Channel.cc -o CMakeFiles/reactorhttp.dir/Channel.cc.s

CMakeFiles/reactorhttp.dir/Dispatcher.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/Dispatcher.cc.o: /home/zwdai/vscode/ReactorHttp/Dispatcher.cc
CMakeFiles/reactorhttp.dir/Dispatcher.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/reactorhttp.dir/Dispatcher.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/Dispatcher.cc.o -MF CMakeFiles/reactorhttp.dir/Dispatcher.cc.o.d -o CMakeFiles/reactorhttp.dir/Dispatcher.cc.o -c /home/zwdai/vscode/ReactorHttp/Dispatcher.cc

CMakeFiles/reactorhttp.dir/Dispatcher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/Dispatcher.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/Dispatcher.cc > CMakeFiles/reactorhttp.dir/Dispatcher.cc.i

CMakeFiles/reactorhttp.dir/Dispatcher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/Dispatcher.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/Dispatcher.cc -o CMakeFiles/reactorhttp.dir/Dispatcher.cc.s

CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.o: /home/zwdai/vscode/ReactorHttp/EpollDispatcher.cc
CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.o -MF CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.o.d -o CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.o -c /home/zwdai/vscode/ReactorHttp/EpollDispatcher.cc

CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/EpollDispatcher.cc > CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.i

CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/EpollDispatcher.cc -o CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.s

CMakeFiles/reactorhttp.dir/PollDispatcher.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/PollDispatcher.cc.o: /home/zwdai/vscode/ReactorHttp/PollDispatcher.cc
CMakeFiles/reactorhttp.dir/PollDispatcher.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/reactorhttp.dir/PollDispatcher.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/PollDispatcher.cc.o -MF CMakeFiles/reactorhttp.dir/PollDispatcher.cc.o.d -o CMakeFiles/reactorhttp.dir/PollDispatcher.cc.o -c /home/zwdai/vscode/ReactorHttp/PollDispatcher.cc

CMakeFiles/reactorhttp.dir/PollDispatcher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/PollDispatcher.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/PollDispatcher.cc > CMakeFiles/reactorhttp.dir/PollDispatcher.cc.i

CMakeFiles/reactorhttp.dir/PollDispatcher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/PollDispatcher.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/PollDispatcher.cc -o CMakeFiles/reactorhttp.dir/PollDispatcher.cc.s

CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.o: /home/zwdai/vscode/ReactorHttp/SelectDispatcher.cc
CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.o -MF CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.o.d -o CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.o -c /home/zwdai/vscode/ReactorHttp/SelectDispatcher.cc

CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/SelectDispatcher.cc > CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.i

CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/SelectDispatcher.cc -o CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.s

CMakeFiles/reactorhttp.dir/EventLoop.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/EventLoop.cc.o: /home/zwdai/vscode/ReactorHttp/EventLoop.cc
CMakeFiles/reactorhttp.dir/EventLoop.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/reactorhttp.dir/EventLoop.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/EventLoop.cc.o -MF CMakeFiles/reactorhttp.dir/EventLoop.cc.o.d -o CMakeFiles/reactorhttp.dir/EventLoop.cc.o -c /home/zwdai/vscode/ReactorHttp/EventLoop.cc

CMakeFiles/reactorhttp.dir/EventLoop.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/EventLoop.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/EventLoop.cc > CMakeFiles/reactorhttp.dir/EventLoop.cc.i

CMakeFiles/reactorhttp.dir/EventLoop.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/EventLoop.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/EventLoop.cc -o CMakeFiles/reactorhttp.dir/EventLoop.cc.s

CMakeFiles/reactorhttp.dir/HttpRequest.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/HttpRequest.cc.o: /home/zwdai/vscode/ReactorHttp/HttpRequest.cc
CMakeFiles/reactorhttp.dir/HttpRequest.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/reactorhttp.dir/HttpRequest.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/HttpRequest.cc.o -MF CMakeFiles/reactorhttp.dir/HttpRequest.cc.o.d -o CMakeFiles/reactorhttp.dir/HttpRequest.cc.o -c /home/zwdai/vscode/ReactorHttp/HttpRequest.cc

CMakeFiles/reactorhttp.dir/HttpRequest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/HttpRequest.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/HttpRequest.cc > CMakeFiles/reactorhttp.dir/HttpRequest.cc.i

CMakeFiles/reactorhttp.dir/HttpRequest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/HttpRequest.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/HttpRequest.cc -o CMakeFiles/reactorhttp.dir/HttpRequest.cc.s

CMakeFiles/reactorhttp.dir/HttpResponse.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/HttpResponse.cc.o: /home/zwdai/vscode/ReactorHttp/HttpResponse.cc
CMakeFiles/reactorhttp.dir/HttpResponse.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/reactorhttp.dir/HttpResponse.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/HttpResponse.cc.o -MF CMakeFiles/reactorhttp.dir/HttpResponse.cc.o.d -o CMakeFiles/reactorhttp.dir/HttpResponse.cc.o -c /home/zwdai/vscode/ReactorHttp/HttpResponse.cc

CMakeFiles/reactorhttp.dir/HttpResponse.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/HttpResponse.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/HttpResponse.cc > CMakeFiles/reactorhttp.dir/HttpResponse.cc.i

CMakeFiles/reactorhttp.dir/HttpResponse.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/HttpResponse.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/HttpResponse.cc -o CMakeFiles/reactorhttp.dir/HttpResponse.cc.s

CMakeFiles/reactorhttp.dir/main.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/main.cc.o: /home/zwdai/vscode/ReactorHttp/main.cc
CMakeFiles/reactorhttp.dir/main.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/reactorhttp.dir/main.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/main.cc.o -MF CMakeFiles/reactorhttp.dir/main.cc.o.d -o CMakeFiles/reactorhttp.dir/main.cc.o -c /home/zwdai/vscode/ReactorHttp/main.cc

CMakeFiles/reactorhttp.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/main.cc > CMakeFiles/reactorhttp.dir/main.cc.i

CMakeFiles/reactorhttp.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/main.cc -o CMakeFiles/reactorhttp.dir/main.cc.s

CMakeFiles/reactorhttp.dir/TcpConnection.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/TcpConnection.cc.o: /home/zwdai/vscode/ReactorHttp/TcpConnection.cc
CMakeFiles/reactorhttp.dir/TcpConnection.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/reactorhttp.dir/TcpConnection.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/TcpConnection.cc.o -MF CMakeFiles/reactorhttp.dir/TcpConnection.cc.o.d -o CMakeFiles/reactorhttp.dir/TcpConnection.cc.o -c /home/zwdai/vscode/ReactorHttp/TcpConnection.cc

CMakeFiles/reactorhttp.dir/TcpConnection.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/TcpConnection.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/TcpConnection.cc > CMakeFiles/reactorhttp.dir/TcpConnection.cc.i

CMakeFiles/reactorhttp.dir/TcpConnection.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/TcpConnection.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/TcpConnection.cc -o CMakeFiles/reactorhttp.dir/TcpConnection.cc.s

CMakeFiles/reactorhttp.dir/TcpServer.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/TcpServer.cc.o: /home/zwdai/vscode/ReactorHttp/TcpServer.cc
CMakeFiles/reactorhttp.dir/TcpServer.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/reactorhttp.dir/TcpServer.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/TcpServer.cc.o -MF CMakeFiles/reactorhttp.dir/TcpServer.cc.o.d -o CMakeFiles/reactorhttp.dir/TcpServer.cc.o -c /home/zwdai/vscode/ReactorHttp/TcpServer.cc

CMakeFiles/reactorhttp.dir/TcpServer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/TcpServer.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/TcpServer.cc > CMakeFiles/reactorhttp.dir/TcpServer.cc.i

CMakeFiles/reactorhttp.dir/TcpServer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/TcpServer.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/TcpServer.cc -o CMakeFiles/reactorhttp.dir/TcpServer.cc.s

CMakeFiles/reactorhttp.dir/ThreadPool.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/ThreadPool.cc.o: /home/zwdai/vscode/ReactorHttp/ThreadPool.cc
CMakeFiles/reactorhttp.dir/ThreadPool.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/reactorhttp.dir/ThreadPool.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/ThreadPool.cc.o -MF CMakeFiles/reactorhttp.dir/ThreadPool.cc.o.d -o CMakeFiles/reactorhttp.dir/ThreadPool.cc.o -c /home/zwdai/vscode/ReactorHttp/ThreadPool.cc

CMakeFiles/reactorhttp.dir/ThreadPool.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/ThreadPool.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/ThreadPool.cc > CMakeFiles/reactorhttp.dir/ThreadPool.cc.i

CMakeFiles/reactorhttp.dir/ThreadPool.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/ThreadPool.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/ThreadPool.cc -o CMakeFiles/reactorhttp.dir/ThreadPool.cc.s

CMakeFiles/reactorhttp.dir/WorkerThread.cc.o: CMakeFiles/reactorhttp.dir/flags.make
CMakeFiles/reactorhttp.dir/WorkerThread.cc.o: /home/zwdai/vscode/ReactorHttp/WorkerThread.cc
CMakeFiles/reactorhttp.dir/WorkerThread.cc.o: CMakeFiles/reactorhttp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/reactorhttp.dir/WorkerThread.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/reactorhttp.dir/WorkerThread.cc.o -MF CMakeFiles/reactorhttp.dir/WorkerThread.cc.o.d -o CMakeFiles/reactorhttp.dir/WorkerThread.cc.o -c /home/zwdai/vscode/ReactorHttp/WorkerThread.cc

CMakeFiles/reactorhttp.dir/WorkerThread.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/reactorhttp.dir/WorkerThread.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwdai/vscode/ReactorHttp/WorkerThread.cc > CMakeFiles/reactorhttp.dir/WorkerThread.cc.i

CMakeFiles/reactorhttp.dir/WorkerThread.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/reactorhttp.dir/WorkerThread.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwdai/vscode/ReactorHttp/WorkerThread.cc -o CMakeFiles/reactorhttp.dir/WorkerThread.cc.s

# Object files for target reactorhttp
reactorhttp_OBJECTS = \
"CMakeFiles/reactorhttp.dir/Buffer.cc.o" \
"CMakeFiles/reactorhttp.dir/Channel.cc.o" \
"CMakeFiles/reactorhttp.dir/Dispatcher.cc.o" \
"CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.o" \
"CMakeFiles/reactorhttp.dir/PollDispatcher.cc.o" \
"CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.o" \
"CMakeFiles/reactorhttp.dir/EventLoop.cc.o" \
"CMakeFiles/reactorhttp.dir/HttpRequest.cc.o" \
"CMakeFiles/reactorhttp.dir/HttpResponse.cc.o" \
"CMakeFiles/reactorhttp.dir/main.cc.o" \
"CMakeFiles/reactorhttp.dir/TcpConnection.cc.o" \
"CMakeFiles/reactorhttp.dir/TcpServer.cc.o" \
"CMakeFiles/reactorhttp.dir/ThreadPool.cc.o" \
"CMakeFiles/reactorhttp.dir/WorkerThread.cc.o"

# External object files for target reactorhttp
reactorhttp_EXTERNAL_OBJECTS =

reactorhttp: CMakeFiles/reactorhttp.dir/Buffer.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/Channel.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/Dispatcher.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/EpollDispatcher.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/PollDispatcher.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/SelectDispatcher.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/EventLoop.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/HttpRequest.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/HttpResponse.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/main.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/TcpConnection.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/TcpServer.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/ThreadPool.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/WorkerThread.cc.o
reactorhttp: CMakeFiles/reactorhttp.dir/build.make
reactorhttp: CMakeFiles/reactorhttp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/zwdai/vscode/ReactorHttp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable reactorhttp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/reactorhttp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/reactorhttp.dir/build: reactorhttp
.PHONY : CMakeFiles/reactorhttp.dir/build

CMakeFiles/reactorhttp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/reactorhttp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/reactorhttp.dir/clean

CMakeFiles/reactorhttp.dir/depend:
	cd /home/zwdai/vscode/ReactorHttp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zwdai/vscode/ReactorHttp /home/zwdai/vscode/ReactorHttp /home/zwdai/vscode/ReactorHttp/build /home/zwdai/vscode/ReactorHttp/build /home/zwdai/vscode/ReactorHttp/build/CMakeFiles/reactorhttp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/reactorhttp.dir/depend

