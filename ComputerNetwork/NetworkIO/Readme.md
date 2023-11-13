# EPOLL 原理
[EPOLL原理](https://os.51cto.com/art/202103/649405.htm)

[十个问题理解Linux epoll](https://zhuanlan.zhihu.com/p/378892166)

[Epoll 原理](https://www.zhihu.com/question/486578358)

+ level-triggered、edge-triggered：
    1. 状态持续通知和状态变化通知

+ select:
    1. 每个进程所打开的 FD 是有限制的，通过 FD_SETSIZE 设置，默认 1024；
    2. 每次调用 select，都需要把 fd 集合从用户态拷贝到内核态，fd 集合很大时，开销也很大；
    3. 内核会对监视的 fd 集合扫描，采用轮询的方法，效率很低（高并发时）
    4. select 并不是线程安全的；

+ poll：
    + 同 select 的优缺点一致，唯一的改进是解决了文件描述符的集合数量限制的问题；
    + select 和 poll 都会随着监控的描述符增加而出现性能下降，因此并不适合高并发场景；

+ epoll：
    1. epoll 是线程安全的；
    2. 

+ 高并发的网络 I/O 下，性能最大的绊脚石是 socket 在阻塞后导致的进程上下文切换。