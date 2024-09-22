------

## 这是一个基于Reactor模型的HTTPServer

```shell
\#请在main.cc文件下面，修改你的文件路径
\#在做测试时，请在文件路径中添加一些文件内容
#请注意你的cmake版本，以及c++版本
.
cd ReactorHttp
cmake -B build
cmake --build build
.
# 启动服务器
./build/reactorhttp

```

在浏览器输入任意的地址加上main.cc文件中设定的端口号, 以下是测试效果

------

![](./images/main.png)

![](./images/calendar.png)