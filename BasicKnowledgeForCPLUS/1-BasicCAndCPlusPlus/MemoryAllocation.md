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

### malloc、realloc、calloc 的区别
1. malloc 在堆上额分配指定指定字节数的存储区，该存储区的初始值不确定，需要 memset 处理
2. realloc 更改之前分配区的长度，可以对给定的指针所指的空间进行扩大或者缩小，原有内存内容保持不变
3. calloc 分配指定字节大小的存储区，会初始化分配的内存空间为零

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

## new/delete 和 malloc/free 的区别？（new 和 malloc 的区别？）
+ 类型不同：new/delete 是关键字，需要编译器支持；malloc/free 是库函数，需要头文件支持；
+ 参数不同：new 申请内存分配时无需指定内存块大小，编译器会根据类型信息自行计算。而 malloc 则需要显示地指出所需内存的大小；
+ 返回结果不同：new 内存申请成功后返回时对象类型的指针；malloc 返回的是 void*，需要通过强制类型转换将 void* 转换成需要的类型；
+ 内存分配失败返回结果不同：new 内存返回失败会抛出异常，malloc 内存分配失败返回 NULL；
+ 申请用户自定义类过程不同：new 会调用 operator new 函数，申请足够的内存，然后调用该类型的构造函数，进行初始化成员变量，最后返回自定义类型指针，delete 会先调用析构函数，然后再调用 operator delete 函数释放内存。malloc/free 只能实现动态的申请和释放内存，无法强制要求对其做自定义类型对象构造和析构函数。

## new 和 delete 是实现过程？
+ new 简单类型直接调用 operator new 分配内存；
+ new 复杂结构时表达式会调用 operator new(operator new[]) 函数，分配一块足够大的、原始的、未命名的内存空间；
+ 编译器运行相应的构造函数构造这些对象，并为其传入初始值；
+ 对象被分配了空间并构造完成，返回一个指向该对象的指针；

## delete 是如何知道要释放内存的大小？
+ delete 简单数据类型时只是调用了 free 函数，且此时 delete 和 delete[] 等同；
+ delete 复杂类型时先调用析构函数，再调用 operator delete；


## malloc 申请的空间能用 delete 释放吗？
+ 理论上来说是可以的，但是由于 malloc/free 操作对象都是明确大小的，而且是不能用在动态类上，与此同时 new 和 delete 会自动进行类型检查和大小，malloc/free 不能执行构造函数和析构函数，所以不建议使用 delete 去释放 malloc 分配的空间，因为这样不能保证每个 C++ 程序运行时都正常；

## delete 和 delete [] 的区别？（delete、delete []、alloctor 有什么作用？）
+ delete 和 delete[] 的区别主要是在于对非内部数据对象的处理上，delete 只能调用一次非内部数据对象的析构函数，而 delete[] 会调用数组的每一个成员的析构函数；
+ new 的机制是将内存分配和对象构造组合在一起，delete 也是将对象的析构函数和内存释放组合在一起了，allocator 是将这两部分分开了，allocator 申请一部分内存，但是不进行初始化，只有当需要的时候才进行初始化操作；


