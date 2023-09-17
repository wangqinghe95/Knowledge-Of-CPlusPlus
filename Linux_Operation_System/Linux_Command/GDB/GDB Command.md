# GDB Command
+ GDB 调试的对象在编译时必须加上 -g，无论是调试执行文件，运行的进程，还是 core 文件

## GDB 调试文件命令

1. 直接调试执行文件
+ gdb [program_name]

2. 调试运行的进程
+ gdb attach [pid]
+ gdb [program_name] [pid]

3. 调试 Core 文件
+ gdb [program_name] [core_file]
+ 生成 core 文件的方式
    1. 主动生成
        + 在 gdb 运行终端执行命令：gcore [core_file]
    2. 被动生成
        1. 修改当前用户生成 core 文件大小权限（重新登录后生效）
            + echo "ulitimt -c umlimited" > ~/.profile
        2. 修改 core 文件保存地址
            + echo "[folder_name]-%e-%p-%t" > /proc/sys/kernel/core_pattern

## 调试步骤

### 调试正常运行的程序
1. GDB 启动程序
2. 查看源码，确定断点位置
3. run/r 运行到断点位置
4. 查看变量/指针/数组/结构体/函数入参
5. 单步调试：s(step)/n(next)
6. 重复步骤 4，确定关键数据是否符合语气
7. 重复步骤 4~6，直到主动结束调试位置

### 调试崩溃的程序
0. 获取崩溃程序的 core 文件
1. gdb [program] [core]
2. r(run) 运行到程序中断处
3. where 查看中断程序所处位置
4. 查看函数调用栈: bt
5. 切换函数调用至程序崩溃处（多线程使用）： frame
6. 显示当前处代码，查找原因

## 基础调试命令
### 启动
1. run/r [argumens]: 带参数运行程序到断点处
2. start [arguments]: 带参数运行程序到 main 函数指令的下一行
3. show args: 查看当前程序启动时的参数列表
4. set args: 设置程序启动时的参数列表，下次启动时成效	

### 退出
1. kill: 停止调试程序
2. quit/q/Ctrl+D: 退出GDB调试程序

### 执行
1. step：单步调试，可执行到函数内部
    + step/s [number]: 单步执行 [number] 步，参数可选，默认1.
2. next：单步调试，不可执行到函数内部
    + next/n [number]:单步执行 [number] 步，参数可选，默认1.
3. continue：继续运行直到断点处
    + continue/c [number]: 继续运行程序，忽略 [number]次命中
4. where：查看当前程序运行的位置
    + 会显示出当前代码的函数调用栈信息

### 断点管理
#### breakpoints：普通断点
1. break/b [line]/[function_name]/[file_name]:[line]/[class_name]:[function_name]: 在指定行，函数名处加断点
2. break/b [address]: 在指定地址加断点，地址可以是变量的，或者函数处
3. break/b +/- [offset]: 在当前代码行的偏移量处加断点
4. break/b [break_ponit] if [condition]: 在指定位置加上条件断点
5. tbreak: 临时断点，用法同break，命中一次后自动删除

#### watchpoints：观察断点，当观察的对象发生变化时，会触发该断点
1. watch [variable]: 观察指定变量
2. watch [variable_1] + [variable_2]: 监控多个变量
3. watch *(type*)[address]: 通过内存地址间接设置断点
4. watch [variable] thread [thread_number]: 监控线程[number]修改变量时触发中断

#### catchpoints：捕获断点
1. catch throw/catch/exec/fork/vfork/load/unload:
    + 捕捉C++throw调用/catch调用/exec系统调用/fork系统调用/vfork系统调用/动态库加载/卸载 事件

#### 查看断点
1. info/i break/b:显示所有断点
2. info watchpoints/catchpoints: 显示数据断点类型/捕获断点类型列表

#### 启用/禁用断点
1. enable/disable [number]: 启用和禁用编号为 [number]的断点

#### 保存/导入断点
1. save break/b [file_name]: 保存断点信息到 [file_name] 文件中
2. source [file_name]: 导入文件 [file_name] 中的断点信息

#### 删除断点
1. clear [line]/[file]:[line]/[function]: 清除指定位置的所有断点，如果有多个同名函数的断点，则也会被全部删除
2. delete/d [Num]: 删除编号为 Num 的断点, [Num]可选，如果没有该参数，则是删除所有断点
3. delete/d [num1]-[num2] [num3]-[num4]: 删除编号区域内的断点
4. clear和delete的区别
    + clear 只能删除局部的断点，delete 可以删除全局的断点
    + clear 只能删除普通断点，观察断点和捕获断点只能由 delete 删除
    + clear 的 arguments同添加断点的参数一样，delete 的 arguments 一般是为编号

### 显示打印
1. print： 直接跟需要打印的类型，变量、数组、指针、结构体、STL
    + print *[array]@[number]: 打印数组 [array] 从开头连续的 [number] 个元素的值查看变量
    + print [array][index]@[number]: 打印数组 [array] 以 [index] 为起点的 [number] 个元素
    + print [struct_name]/[variable]: 打印结构体/变量
    + set print array-indexes on: 打印数组的同时打印数组下标
    + set print pretty on: 每行只显示一个数据
    + set print null-stop: 不显示 “\000”

2. display:
    + display [expression]: 自动显示指定的表达式的值，其中表达式的类型等同于 print
    + info display: 查看display的列表
    + undisplay [number]: 取消编号为 [number] 的显示

3. x : 以指定的格式显示给定的地址的内容
    + x /[length][format] [Address expression]
4. ptype: 显示结构体或者类的定义
5. whatis: 显示变量的类型

### 多进程
1. attach [pid]: 绑定进程 pid
2. info inferiors: 显示进程列表
3. inferior [num]: 切换到编号为 num 的进程上调试
4. set follow-fork-mode child/parent: 追踪子进程/父进程
5. set detach-on-fork on/off: fork 调用时只追踪其中一个进程/同时追踪父子进程
6. set schedule-multiple on: 默认调试当前进程时，其他进程处于挂起状态。该命令设置调试时所有进程都在执行

### 多线程
1. info threads: 查看线程列表
2. thread [num]: 切换到线程编号为 num 的线程进行调试
3. set scheduler-locking on/off: 调试一个线程时，其他线程暂停执行/同步执行
4. set scheduler-locking step: 仅用step调试线程时其他线程不执行，用其他命令如 next 调试时执行

### 其他
1. GDB 启动时带上参数 –q 可以去掉一些非必要的信息
2. GDB 内部可以直接执行 shell 命令，其格式为
    + ![shell_cmd]
3. GDB 内部的命令行可以使用一些内嵌的函数，如C语言
4. GDB 查找源码时支持正则搜索
    + reverse-search [regular_expression]

## 调试动态库

### 调试命令
1. info sharelibrary/share: 查看当前程序是否加载了动态库
2. sharelibrary/share [lib_name]: 手动加载动态库
3. name/nm [lib_name]: 查看动态库/二进制文件/可执行文件 符号表
4. nm –g –C [lib_name]：查看
5. ldd [file_name]: 查看目标文件所依赖的动态库

### 调试步骤
1. 生成动态库
    + g++  [source_file] –fPIC –shared –o [lib_dynamic_name] -g
2. 生成可执行文件
    + g++ [source_file] –o [program_file] –L [libdynamic_path] -l[lib_dynamic_name] -g -Wl,-rpath,./
3. 查看动态库的提供的对外接口
    + nm –g –C [lib_dynamic_name]
4. 查看可执行程序依赖的动态库
    + ldd [program_name]
5. 调试步骤
    + 同**调试正常运行的程序**步骤一致
6. 注意事项
    + 可执行程序运行时找动态的路径不会包含当前文件夹，其寻找动态库路径的四个方式
        + 编译时指定可执行程序寻找动态库路径
            + 在编译生成可执行程序的命令中，加上编译参数 -Wl,-rpath,./
        + shell 环境变量 **LD_LIBRARY_PATH** 指定寻找路径
            + 临时生效: export LD_LIBRARY=[path]
            + 永久生效: export LD_LIBRARY=[path] > ~/.bashrc && source .bashrc
        + 配置文件 /etc/ld.so.conf 记录的路径
            + 在 /etc/ld.so.conf 中添加指定的动态库所在路径
            + 在 /etc/ld.so.conf.d 中添加一个后缀为 .conf 文件，文件记录动态库所在的路径
            + 修改之后执行命令 ldconfig
        + 默认动态库路径
            + 将动态库复制到 /usr/lib, /lib 目录下
    + 动态库新增函数后调用不到
        + 确定函数调用的动态库是更新的那个

## 内存相关调试

### 内存问题类型
1. 内存泄露
2. 堆溢出
3. 栈溢出
4. 全局溢出
5. 使用空指针

### 问题解决
1. 编译时使用 -fsanitize=address 参数，程序在运行时如果遇到上述问题，会有打印

## 调试 release 版本
1. 从相同源码，使用相同参数，只是少了 –g 编译生成的 debug 版本程序提取调试信息
    + objcopy --only-keep-debug [debug_program] [debug_symbol]
    + gdb --symbol=[debug_symbol] -exec= [release_program] 
2. 直接将 debug 版本的程序当做符号源
    + gdb --symbol= [debug_program] -exec=[release_program] 
3. release 版本生成的 core 文件也可以将 debug 版本的程序作为符号源调试
    + gdb [debug_program] [core_release_file]

![更详细的 GDB 命令](https://www.cnblogs.com/wanghao-boke/p/17246522.html)