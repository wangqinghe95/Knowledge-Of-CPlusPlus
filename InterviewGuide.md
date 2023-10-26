# InterviewGuide

## C++

### Basic C++
+ C++与 C 有什么区别？
+ C++ 中的 const 关键字以及它的作用
+ C++ nullptr 和 NULL 有什么区别？
+ C++ 中的 static 关键字有哪些用途？
+ C++ 有几种类型 new？
+ C++ 中 malloc/free, new/delete 实现原理？
+ C++ RTTI（Run Time Type Identification）
+ C++ 函数指针是什么？
+ 引用（reference）和指针（pointer）有什么区别。
+ 区间（range）和范围（span）有什么区别。
+ 什么是强制内联（forced inline）？它与普通内联（normal inline）有什么区别？
+ 什么是 C++ 中的类型推导（type inference），例如 auto 关键字和 decltype 关键字。
+ 什么是 C++ 中的强制类型转换（type casting），例如 static_cast、dynamic_cast、reinterpret_cast 等。
+ strcpy、strncpy、memcpy 的实现与区别？
+ 数组名和数组首地址的区别？
+ 如何判断两个结构体是否相等

### Oriented Object C++
+ 解释 C++ 中的对象模型（object model）。
+ 解释 C++ 的多态性（polymorphism）和继承性（inheritance）
+ 解释编译时（compile-time）和运行时（run-time）多态（polymorphism），它们有什么区别？
+ 解释 C++ 中的静态多态（static polymorphism）和动态多态（dynamic polymorphism）。
+ 解释虚函数（virtual function）和纯虚函数（pure virtual function）
+ 什么是虚函数表（virtual function table）？它在 C++ 中有什么作用？
+ 什么是 vtable 和 vptr？它们在 C++中有什么作用？
+ 什么是动态绑定（dynamic binding）？它的使用场景是什么
+ 什么是 RAII 技术？它在 C++ 中有什么作用？
+ C++ 中有哪些内存管理方式？
+ 什么是拷贝构造函数（copy constructor）和赋值操作符（assignment operator）
+ 什么是函数对象（function object）？它们在 C++ 中有什么作用？

### Generic
+ 什么是模板（template）？它的优缺点？
+ 什么是元编程（metaprogramming）？
+ 什么是模板特化（template specialization）？
+ C++ 中的模板参数包（template parameter pack）是什么？它有什么作用？
+ 解释函数模板和类模板之间的区别。
+ 什么是 SFINAE（Substitution Failure Is Not An Error）？
+ 什么是模板元编程（TMP）？它有什么应用场景？
+ 解释 C++ 中的模板元编程（TMP）和泛型编程（generic programming）之间的区别。

### STL
+ C++ 中的 STL 是什么？它包含哪些常用的容器类和算法？
+ 解释迭代器（iterator）及其作用。
+ 什么是函数对象（function object）？
+ 解释 lambda 表达式及其用法。

### C++ 11/14/17/20
#### C++ 11
+ C++11 有哪些新特性和改进？
+ C++11 异常（exception）介绍？
+ C++11 右值引用（rvalue reference）？与左值引用（lvalue reference）有什么区别？
+ C++11 std::forward,完美转发（perfect forwarding）。
+ C++11 中的原子操作（atomic operation）和 std::atomic 类型。
+ C++11 lambda 表达式及其用法。
+ C++11 中的异常处理机制有哪些，例如 try-catch 块、throw 关键字等。
+ C++11 中的移动语义（move semantics）是什么？它有什么作用？
+ C++11 std::function 介绍和使用。
+ C++11 std::bind 介绍与使用。
+ C++11 智能指针（smart pointer）的介绍和作用。

#### C++ 14/17/20
+ C++20有哪些新特性和改进？
+ C++17有哪些新特性和改进？
+ C++14有哪些新特性和改进？


## Linux Shell

## Operation System
+ 什么是线程（thread）？C++ 中如何创建和管理线程？
+ 解释互斥锁（mutex）和条件变量（condition variable）。
+ 什么是死锁（deadlock）？如何避免死锁？
+ 什么是信号（signal）？在 C++ 中如何处理信号？
+ 什么是多进程（multiprocessing）？与多线程相比有哪些区别？
+ 什么是内存池？
+ 解释内存泄漏（memory leak）及其危害？如何处理内存泄漏问题？
+ 什么是异步编程（asynchronous programming）？C++ 中如何实现异步编程？
+ 解释 C++ 中的多线程同步机制，例如互斥量、信号量、读写锁等。
+ 解释多线程中的线程安全（thread safety）和竞态条件（race condition）。
+ C++ 中有哪些常见的并发编程模型，例如共享内存、消息传递等？
+ 什么是协程（coroutine）？它们在 C++ 中有什么应用场景？
+ 什么是异步 IO（asynchronous IO）？它在 C++ 中如何实现？解释下IO多路复用？
+ 解释 C++ 中的内存布局（memory layout），例如栈、堆、全局变量等。
+ 函数调用过程？
+ 一个打印 "Hello World" 字符串的程序的执行过程？

## Data Structrure
+ 掌握 C++ 中的排序算法，例如快速排序、归并排序等。
+ 掌握 C++ 中的查找算法，例如二分查找、哈希表等。
+ 解释 C++ 中的时间复杂度和空间复杂度。
+ 什么是 O(n)、O(nlogn)、O(n^2) 等时间复杂度表示法？它们分别代表什么含义？
+ 什么是数据结构（data structure）？C++ 中常见的数据结构有哪些？
+ 什么是红黑树（red-black tree）？它有什么作用？
+ 什么是 AVL 树？它有什么作用？
+ 什么是 B 树？它有什么作用？
+ 什么是哈希表（hash table）？它有什么作用？
+ 什么是堆（heap）？它有什么作用？
+ 什么是堆排序（heap sort）？它有什么特点？
+ 什么是拓扑排序（topological sorting）？它有什么作用？
+ 什么是并查集（union-find set）？它有什么作用？
+ 什么是 Trie 树？它有什么作用？
+ 什么是最短路径算法（shortest path algorithm）？例如 Dijkstra 算法、Bellman-Ford 算法等。
+ 什么是最小生成树算法（minimum spanning tree algorithm）？例如 Prim 算法、Kruskal 算法等。
+ 什么是一致性哈希

## Design Pattern
+ 什么是单例模式（singleton pattern）？解释它的优点和缺点。
+ 解释工厂模式（factory pattern）和抽象工厂模式（abstract factory pattern）。
+ 解释装饰器模式（decorator pattern）。它与继承（inheritance）有什么区别？
+ 什么是观察者模式（observer pattern）？
+ 解释迭代器模式（iterator pattern）和适配器模式（adapter pattern）。
+ 什么是 MVC 模式？它在 C++ 中如何应用？
+ 什么是 CRTP（Curiously Recurring Template Pattern）？它有什么作用？

## Compiler
+ 什么是编译器优化（compiler optimization）？C++ 中有哪些常见的编译器优化技术？
+ 解释 C++ 中的调试技术，例如断言（assert）和调试器（debugger）。
+ 什么是 C++ 中的动态链接库（dynamic link library，DLL）？它有什么作用？
+ 从代码到可执行程序的过程

## Test
+ 使用过代码覆盖率（code coverage）吗？
+ 使用过C++ 中的测试框架吗，例如 Google Test 和 Boost.Test。