# 信号
## 概念
+ 信号是 Linux 进程间通信的一种机制，是软件层次上对中断的一种模拟，用在进程之间的传递消息。

## 来源
+ 内核产生
    - 内存错误，除 0 错误等
+ 由其他进程产生，传递给目标进程
    - kill 信号
    - 自定义信号：SIGURG
+ 硬件产生
    - 键盘

## 处理方式
+ 发送阶段
    - 内核将信号放到对应的 pending 队列中
+ 接受阶段
    - 内核将信号从 pending 队列中取出，并进行处理。一般是调用响应的处理函数
    - 处理方式由三种，用户定义处理函数，内核默认缺省处理，忽略

## 处理过程
+ signal 函数用于捕获突发事件
```
void (*signal (int sig, void (*func)(int)))(int); 
//signal(registered signal, signal handler);
```

+ raise 函数用于发送信号
```
int raise ( int signal_ );
```

## [跨进程信号通信](https://www.cnblogs.com/wanghao-boke/p/17745796.html)


## [跨线程信号通信](https://www.cnblogs.com/clover-toeic/p/4126594.html)

## 信号类型
1. `#define SIGHUP 1 /* hangup*/`
    + 通知进程控制终端被断开，常用来重启服务进程达到重新读取配置文件的目的
    + 缺省行为是终止进程。
2. `#define SIGINT 2`
    + 中断信号
    + 缺省行为是终止进程
3. `#define SIGQUIT 3`
    + 通知进程退出。
    + 缺省行为是终止进程，并且创建一个核心转储
4. `#define SIGILL 4 `
    + 进程在运行过程中某一句指令不能被 CPU 识别。可能是一些形式错误，未知或者是特权指令。
    + 缺省行为是终止进程，并创建一个核心转储
5. `#define SIGTRAP 5`
    + POSIX 定义，用于调试。当被调试进程接收到该信号后，就意味着它达到了一个调试断点。
    + 一旦该信号被交付，被调试的进程就会停止，并且它的父进程将接到通知
    + 缺省行为是终止进程，并创建一个核心转储
6. `#define SIGABRT 6`
    + 在异常终止一个进程的同时创建一个核心转储的方法
    + 如果该信号被捕获，并且信号处理句柄没有返回，则进程不会终止
    + 缺省行为是终止进程，并且创建一个核心转储
7. `#define SIGFPE 8`
    + 当进程发生一个浮点错误时，SIGFPE 信号被发送给该进程
    + 对于那些处理复杂数学运算的程序，一般会建议你捕获该信号
    + 缺省行为是终止进程，并且创建一个核心转储
8. `#define SIGKILL 9`
    + 结束信号
    + 该信号不能被捕获或者忽略
    + 极少数情况下不会被终止进程，比如在处理一个“非中断操作”，如磁盘 I/O，虽然该情况极少发生，但是一旦发生就会造成死锁。唯一结束进程的方法就是重启
    + 缺省行为是终止进程
9. `#define SIGBUS 10`
    + CPU 检测到数据总线上的错误时将会产生 SIGBUS。
    + 当程序尝试去访问一个没有正确对齐的内存地址时就会产生该信号
    + 缺省行为是终止进程，并且创建一个核心转储
10. `#define SIGSEGV 11`
    + 当程序没有权限去访问一个受保护的内存地址时，或者访问无效的虚拟内存地址时，会产生该信号
    + 缺省行为是终止进程，并创建一个核心转储
11. `#define SIGSYS 12`
    + 进程执行一个不存在的系统调用时由操作系统产生，然后该进程终止
    + 缺省行为是终止进程，并创建一个核心转储
12. `#define SIGPIPE 13`
    + 管道信号，允许进程之间的通信。如果进程尝试对管道执行写操作，然后管道另一方没有回应者时，操作系统会将该信号发送给该进程
    + 缺省行为是终止进程
13. `#define SIGALRM 14`
    + 在进程的计时器到期的时候，操作系统会发送该信号给该进程
    + 缺省行为是终止进程
14. `#define SIGTERM 15`
    + 通知进程终止，并在终止前做一些清理工作。
    + kill 命令发送的缺省信号，同时也是操作系统关闭时向进程发送的缺省信号
    + 缺省行为是终止进程
15. `#define SIGURG 16`
    + 在进程打开的套接字上发生的某些情况时， SIGURG 会被发送给该进程。
    + 缺省行为是丢弃该信号
16. `#define SIGSTOP 17`
    + 停止信号，进程收到该信号后会暂停运行，直到收到 SIGCONT 信号
    + 该信号不能被捕获或者忽略
    + 缺省行为是停止进程，直到收到 SIGCONT 信号
17. `#define SIGTSTP 18`
    + 同 SIGSTOP 类似，但该信号可以被捕获或者忽略，键盘输入 CTRL+Z 可以产生该信号
    + 缺省行为是停止运行，直到收到 SIGCONT 信号
18. `#define SIGCONET 19`
    + 恢复信号。不能忽略或阻塞，但是可以捕获。
    + 缺省行为是丢弃
19. `#define SIGCHLD 20`
    + 一个进程子进程状态发生后，该信号就会发送到该进程。
    + 缺省行为是丢弃
20. `#define SIGTTIN 21`
    + 当一个后台进程尝试进行一个读操作时，SIGTTIN 信号就会被发送给该进程。进程将会阻塞直到收到 SIGCONT 信号为止。
    + 缺省行为是停止进程
21. `#define SIGTTOU 22`
    + 类似与 SIGTTIN，不同之处在于 SIGTTOU 是后台进程尝试对一个设置了 TOSTOP 属性的 tty 执行写操作时才会产生，如果 tty 没有设置这个属性，该信号就不会被发送
    + 缺省行为是停止进程，直到收到 SIGCONT 信号为止
22. `#define SIGIO 23`
    + 如果进程在一个文件描述符上有 IO 操作的话，SIGIO 信号将被发送给该进程。进程可以通过 fcntl 调用来设置
    + 缺省行为是丢弃该信号
23. `#define SIGXCPU 24`
    + 如果一旦进程超出了它可以使用的 CPU 限制，SIGXCPU 信号就被操作系统发送给该进程
    + 缺省行为是终止该进程
24. `#define SIGXFSZ 25`
    + 如果一个进程超出了它可以使用的文件大小的限制，SIGXFSZ 信号就可以发送给该进程。缺省行为是终止进程
25. `#define SIGVTALRM 26`
    + 一旦进程超过了它设定的虚拟计时器，SIGVTALRM 信号就会被发送给该进程，+ 缺省行为是终止进程
26. `#define SIGPROF 27`
    + 当设置了计时器，SIGPROF 是另一个将会发送给进程的信号
    + 缺省行为是终止进程
27. `#define SIGWINCH`
    + 当进程调正了终端的行或者列时，SIGWINCH 信号就被发送给该进程
    + 缺省行为是丢弃该信号
28. `#define SIGUSR1 29`
29. `#define SIGUSR2 30`
    + 用户自定义信号