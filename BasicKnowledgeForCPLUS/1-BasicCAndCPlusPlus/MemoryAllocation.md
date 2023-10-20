# C++ 动态内存分配函数

## 虚拟内存和物理内存
+ 物理内存，程序在运行时会被加载到计算机的运行内存中，这个运行内存就是我们所说的物理内存中。
    - 这个内存的提供者，就是 RAM 芯片，也是我们所说的内存条，是计算机主要的存储器
    - RAM 芯片是一种集成电路，可以存储和读取数据，速度也非常快。
    - 计算机的物理内存取决于安装的内存条数量和容量
+ 虚拟内存是一种内存管理技术，它将硬盘空间划分为页，每页通常 4KB。
    - 当程序需要更多内存时，操作系统会将一部分一面加载到物理内存中；当程序不再需要这些页面时，操作系统将他们从物理内存移除并释放空间
    - 虚拟内存是面向进程的，操作系统虚拟的为每个应用进程分配连续可用的内存，这个虚拟是通过内存转换技术，将分散的物理内存碎片抽象成连续的内存给进程使用
    - 虚拟内存大小受到计算机系统寻址方案限制
    - 虚拟内存的用途是在计算机缺少运行程序操作所需要的随机存储内存时，使用虚拟内存进行补偿，将计算机的 RAM 和硬盘中的临时空间组合起来。

## 动态分配
### 系统调用
+ 动态分配的内存分配的都是进程虚拟内存中堆中的内存空间
+ 动态分配的内存系统调用：brk,sbrk
    + brk 用于返回堆的顶部地址，sbrk 用于扩展堆
    + `int brk(void *addr)`
    + `void *sbrk(intptr_t increment)`
+ 动态分配思路
    + 先通过 sbrk 扩展堆，将这部分空闲内存空间作为缓冲池，然后通过 malloc/free 管理缓冲池中的内存

## malloc/free
### malloc
+ 函数声明
    - `void* malloc(size_t size)`
+ 函数功能
    - 申请 size 个字节大小的内存空间
+ 实现原理
    - 操作系统将堆中的空闲区块用双向链表组织起来。
    - malloc 分配时，操作系统会去搜索空闲链表，找到一块大于等于所需空间的空间区块，然后将这个空间的分配出去
        - 每个空闲区块都有一个的首部，成为“内存控制块” 
        - 内存控制块中记录了空闲区块的信息，比如指向下一个分配块的指针、当前分配块的长度，或者当前区块是否已经被分配出去
        - malloc 返回回去的是紧跟首部后面的地址，也就是可用空间的起始地址
+ free
    - free 接受一个指针参数，将指针所指向的地址空间重新加上一个首部，也就是内存控制块，插入到空闲链表中，也会根据需要和前后空闲的内存合并
### free
+ 函数声明
    - `void free(void* ptr)`
+ 函数功能
    - 释放 ptr 指针所指向的内存空间
+ 实现原理

### calloc
+ 函数声明
    - `void* calloc (size_t num, size_t size)`
+ 函数功能
    - 申请 num 个大小为 size 的内存

### realloc
+ 函数声明
    - `void* realloc (void* ptr, size_t size)`
+ 函数功能
    - 重新调整 ptr 所指向的内存空间，返回新的内存地址空间
    - 内部数据不变
+ 调整思路
    + 调整空间比原有空间大：
        - 大一点：直接延伸原有空间，并返回原空间首地址；
        - 大很多：重新开辟新空间，将旧空间内容拷贝到新空间去，释放旧空间，返回新空间的首地址；
    + 调整空间比原有空间小：将原有空间缩小，返回旧地址空间首地址

## new/delete

### new
+ 函数原型
```
// for operator new
void *operator new(size_t) throw(bad_alloc);            // normal 
void *operator new(size_t, const nothrow_t &) throw();   // noexcept
void *operator new(size_t, void *) throw();             // placement 
```
+ 函数介绍
    - normal 版本内存分配失败时会跑出 bad_alloc 错误，noexcept 失败时会返回 0
    - placement 版本不会执行分配内存操作，在已经分配的内存上重新构造对象或数组
    - normal 版本和 noexcept 版本都会调用到 placement 版本表达式

+ 函数实现步骤
    1. 分配内存空间
        + 调用动态分配函数，如 malloc。封装了平台的差异，并向上提供一致的动态内存分配接口
        + 加入异常处理机制，处理系统调用分配内存失败的错误。
    2. 在分配的内存上构造函数
    3. 将指针转换成对应的类型返回

+ new 执行步骤
    1. 调用 `void* operator new(sizeof(T))` 接口，申请与 T 类型大小相同的堆空间
    2. 调用构造函数，完成 T 类型对象的构造

+ new[N] 执行步骤
    1. 调用 `void *operator new[](std::size_t size)`，去申请 sizeof(T)*N+4 个字节大小的内存空间
    2. 将空间的前 4 个字节中填充对象的个数
    3. 在申请的空间上执行 N 次 构造函数

### delete
+ 函数原型
```
// for operator delete
void operator delete(void *) throw();                   // normal
void operator delete(void *, const nothrow_t &) throw();  // noexcept
void operator delete(void *, void *) throw();            // placement
```

+ 函数介绍：
    - 三个版本的 delete 分别去释放三个版本的 new

+ 函数实现
    + 先调用释放空间中对象类型的析构函数，再释放空间

+ delete 原理
    + 执行释放空间上对象的析构函数，完成对象中资源的清理工作
    + 调用 operator delete 函数释放对象的空间

+ delete[] 原理
    + 从第一个对象空间之前的 4 个字节中读取对象的个数 N
    + 在释放的对象上执行 N 次析构函数，完成 N 个对象中资源的清理
    + 调用 void operator delete[](void* p) 释放空间，实际在 operator delete[] 中调用 operator delete 释放内存


