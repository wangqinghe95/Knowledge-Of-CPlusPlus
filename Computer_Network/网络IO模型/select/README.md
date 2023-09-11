# 编译运行：
```g++ server.cpp -o server && ./server```
```g++ client.cpp -o client && ./client```

# 项目简介：

+ 客户端是很简单的 socket->bind->connect->write->read->write（显示屏）；
+ 服务器端是用很简单的 select 的网络I/O实现的
    - socket->bind->listen->fd_set->FD_ZERO->FD_SET->select->遍历文件描述符集->FD_ISSET->accept->FD_SET->read/write/recv/send

# 理解关键点：
+ bind 的文件描述符只是用于监听使用，如果监听到客户端后使用 accept 成功后返回的一个新文件描述符，这个新文件描述符才是用来和客户端读写的；也就是说监听和传输数据的文件描述符是分开的；
+ 新增了一个地址结构体数组用来保存正在通信的客户端，用来输出记录目前通信的是哪个客户端，但是存在两个问题：
    - 用 vector 构造数组使用时失败了；
    - 在客户端结束断开联系时如何把已经保存的地址给置为初始化状态；

# select 模型
+ select 模型解决了多个客户端链接的问题，与多个客户端分别通信；
+ 设计思想：一个 fds 数组存放所有需要监视的 socket，然后调用 select；如果 fds 中所有的 socket 都没有数据，select 会阻塞，直到有一个 socket 有响应，select 返回，唤醒进程，用户通过遍历 fds 数组，通过 FD_ISSET 判断具体哪个 socket 接收到了数据，然后做响应的处理；
+ 模型逻辑：
    - 将所有的socket装进一个数组中（fd_set)；
    - 通过 select 遍历 socket 数组；
    - 取出有响应的 socket 放入到另一数组中；
    - 对装有响应的 socket 数组进行集中处理；
    - 服务器 socket 响应：客户端链接，调用 accept；
    - 客户端 socket 响应：客户端通信，调用 send() 或 recv();
+ 缺点：
    - 每次调用 select 都需要将进程加入到所有监视 socket 的等待队列，每次唤醒都需要从每个队列中移除。这里涉及到两次遍历；而且每次都需要将 fds 列表传递给内核，有一定的开销。正因为遍历操作的开销比较大，处于对效率的考虑，才会规定 select 的最大监视数。
    - 进程被唤醒后，程序不知道哪些 socket 收到数据，还需要再遍历一次；

[](https://andyguo.blog.csdn.net/article/details/113117639)

