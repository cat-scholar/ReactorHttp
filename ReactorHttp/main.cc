#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "TcpServer.h"

int main(){

    // if (argc < 3)
    // {
    //     printf("./a.out port path\n");
    //     return -1;
    // }
    // unsigned short port = atoi(argv[1]);
    // 切换服务器的工作路径
    //chdir(argv[2]);

    int port = 10000;
    int threadNum = 10;
    chdir("/home/xxx/luffy");

    // 启动服务器
    TcpServer* server = new TcpServer(port, threadNum);
    server->run();
    return 0;
}