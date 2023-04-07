# 程序介绍
+ 这是程序是使用 epoll 函数实现的服务器功能（把客户端传过来的字符串转大写）和验证的客户端的小 demo

# 程序运行
+ g++ server.cpp -o server && server
+ g++ client.cpp -o client && client

由于过于简单就没写 makefile

# 程序流程
0. socket
1. bind
2. listen
3. epoll_create：创建一个 epoll 实例，并返回一个引用该实例的文件描述符；
4. epoll_ctl：把监听描述符注册到 epoll 集合中；
5. epoll_wait：阻塞等待 I/O 事件；
6. accept：阻塞返回，如果是 监听描述符 有事件返回，说明有客户端请求，把返回的文件描述符也加入到 epoll 集合中继续监听，如果不是，则是客户端发送数据过来，读写处理；

# epoll 介绍
+ 介绍：epoll 监视多个 IO 事件的文件描述符。epoll 除了提供 select/poll 那种 IO 事件的水平触发外，还提供了边缘触发，这使得用户空间程序有可能缓存IO状态，减少 epoll_wait/epoll_pwait 的调用，提高应用程序效率；
+ 优点：
    1. 支持一个进程打开大数目的 socket 描述符；
    2. IO 效率随着 FD 数目增加而线性下降：
        + select/poll 采用轮询的方式扫描文件描述符，文件描述符数量越多，性能越查；
        + select/poll 需要复制大量的句柄数据结构，产生巨大的开销；
        + select/poll 返回的是含有整个句柄的数组，应用程序需要遍历整个数组才能知道那些数组发生了事件，导致效率很低；
        + epoll 只会对有事件发生的 socket 进行操作--这是因为内核实现中 epoll 是根据每个 fd 上面的回调函数实现的；
    3. 支持边缘触发：select/poll 的触发方式是水平触发，应用程序如果没有完成对一个已经就绪的文件描述符进行IO操作，那么 select/poll 调用还是将这些文件的描述符通知进程；
    4. 使用 mmap 加速内核与用户空间的消息传递：select/poll 需要把整个 FD 数组从用户态复制到内核态，而 epoll 是通过内核和用户空间的 mmap 同一块内存实现的，避免了数组的复制。

# IO 模型的两种触发方式
+ LT(Level_triggered:水平触发)：epoll 缺省工作方式，当一个文件描述符准备完毕以后，未对其做操作，或者对于读事件中，如果数据没有一次性读完，下次调用 epoll_wait 时，它还会通知你在上次未完成的文件描述符上进行读写；
+ ET（Edge_triggered:边缘触发）：内核针对已经就就绪好的文件描述符只会通知用户依次，无论你是否对其处理完毕或者已经作出处理；

[](https://www.cnblogs.com/ailumiyana/p/10183368.html)



