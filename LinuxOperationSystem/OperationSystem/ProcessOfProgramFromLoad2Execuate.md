# 一个打印 "Hello World" 用户程序的从加载到输出字符串到屏幕的全过程
1. 用于在 shell 中输入要执行的程序名
2. shell 会调用 fork() 系统函数创建一个新进程，然后新进程调用 execve() 系统函数执行指定的可执行程序
3. 内核开始装载过程
    + execvp() 系统函数对应的入口是 sys_execve()，在 sys_execve() 进行了参数的检查复制后，调用 do_execve()
    + do_execve() 根据可执行文件进行构造 linux_binprm 内核结构，该结构记录可执行文件信息
    + 从 formats 链表中找到执行该执行文件的方法
4. 内核将可执行文件载入内存，并将其映射到用户空间
5. 内核为可执行文件设置 CPU 上下文环境，并跳到程序开始处
6. 执行可执行文件的第一行命令，发生缺页异常
7. 内核分配一页物理内存，并将代码从磁盘读到内存，然后继续执行可执行文件
8. 可执行文件执行 puts() 系统函数，向显示器发送一行需要显示的字符串
9. 内核找到要将字符串送往的显示设备
    + 该设备通常是由一个进程控制
    + 所以内核会将要写的字符送给该进程
10. 内核控制设备的进程告诉设备的窗口系统，它有一行字符需要显示，窗口系统确认这是一个合法的操作，然后执行显示任务
    + 窗口系统将字符串转换成像素，再将像素写入设备的存储映像区
11. 视频硬件将橡树转换成显示器可接收的信号，并且伴随着一组控制数据信息
12. 显示器接受解释信号，激发液晶屏，在屏幕上显示出该字符串。