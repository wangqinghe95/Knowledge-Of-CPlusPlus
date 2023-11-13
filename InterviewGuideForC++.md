# InterviewGuideForC++

## [Basic Knowledege for C/C++](BasicKnowledgeForCPLUS/BasicKnowledgeForCPLUS.md)
### 1、Basic C && C++
1. C 和 C++ 的区别
2. C++ 中 const 关键字
3. C++ 中指针和引用的区别
4. 解释区间（range）和范围（span）。
5. 什么是强制内联（forced inline）？它与普通内联（normal inline）有什么区别？
6. static 关键字作用
7. static_cast 比 C 中的强制转换有什么优势？
8. C++ nullptr 和 NULL 有什么区别？
9. malloc 和 free 实现的原理？
10. malloc、realloc、calloc 的区别
11. new/delete 和 malloc/free 的区别？
12. C++ 有几种类型 new？
13. struct 和 class 的区别
14. 判断两个结构体是否相等
15. 形参和实参的区别
16. 值传递、指针传递、引用传递的区别和效率？
17. 将引用作为函数参数的好处是什么？
18. 指针参数传递和引用参数传递有什么区别？底层原理是什么？
19. 什么时候用指针当参数，什么时候用引用当参数，为什么？
20. 深拷贝和浅拷贝
21. 数组名和指针（数组首地址指针）区别？
22. 数组和指针的区别
23. 野指针和悬空指针的区别？
24. 函数指针
25. 全局变量和局部变量有什么区别？
26. 全局变量和静态全局变量区别？
27. cout 和 printf 有什么区别？
28. ifdef、endif 有什么作用？
29. strcpy 、strncpy 、memcpy 的区别？
30. printf、sprintf、ssprintf 的区别
31. strlen 和 sizeof 的区别？
32. extern"C" 的用法？
33. define 和 typedef、const、函数、内联函数四者的区别
34. volatile 关键字
35. mutable 关键字
36. C++ 有哪些内存管理方式
37. 什么是隐式转换，如何消除隐式转换？
38. 什么是对象复用？什么是零拷贝？
39. 指针和引用之间如何转换？
40. 函数中有重载时，函数的匹配原则和顺序是什么？
41. C++ 类型安全
42. 解释 C++ 中的强制类型转换（type casting）
43. swap 实现

### 2、Oriented Object C++
1. 对象模型
2. 解释 C++ 三大特性
3. C++ 多态是如何实现的
4. 是什么是类的继承？
5. C++ 的组合和继承有什么区别和优缺点？
6. 如果想将某个类作为一个基类，为什么该类必须定义而非声明？
7. 关于 this 指针？
8. 在成员函数中 delete this 会出现什么问题？对象还可以使用吗？
9. 类析构函数中调用 delete this 会发生什么事情
10. 成员函数中 memset(this, 0, sizeof(this)) 会发生什么？
11. this 指针调用成员变量时，堆栈会发生变化吗?
12. public/protected/private 区别和访问、继承权限？
13. 类对象大小是如何计算？
14. 编译器会为一个空类默认添加哪些函数
15. C++ 有哪几种构造函数？
16. 什么是拷贝构造函数，赋值构造函数，赋值操作符
17. 什么是成员列表初始化？什么时候必须要用初始化成员列表？调用过程?
18. 拷贝构造函数介绍？
19. 拷贝构造函数为什么必须要使用引用，而不能传值？
20. 移动构造函数
21. 拷贝初始化和直接初始化的区别？
22. 构造函数的几种关键字？
23. 类成员初始化方式有哪些，它们有什么区别？
24. 成员初始化列表会在什么时候用到？
25. 构造函数和析构函数的执行顺序是什么？
26. 一个类中的全部构造函数的扩展过程是什么？
27. 什么时候会调用类的析构函数
28. 析构函数的作用？以及是如何起作用的？
29. 为什么析构函数一般写成虚函数？
30. 为什么构造函数不能是虚函数
31. 父类的析构函数是否能定义为纯虚函数
32. 在构造函数和析构函数中可以调用虚函数吗？
33. 构造函数和析构函数中是否可以抛出异常
34. 构造函数，拷贝构造函数，赋值操作符之间的区别
35. 构造函数、析构函数、虚函数是否能声明为内联函数？
36. 什么情况会自动生成默认构造函数？
37. 合成的默认构造函数中有哪些需要注意的点？
38. 什么时候需要合成拷贝构造函数？
39. 如何禁止程序自动生成拷贝构造函数？
40. 抽象基类为什么不能创建对象？
41. 什么是 trivial destructor？
42. 重载、重写、隐藏的区别
43. 解释虚函数和纯虚函数
44. 什么是虚函数表（virtual function table）？它在 C++ 中有什么作用？
45. 什么是 vtable 和 vptr？它们在 C++中有什么作用？
46. 静态函数能定义为虚函数吗？常函数呢？
47. 哪些函数不能定义为虚函数？
48. 虚函数的代价？
49. 基类的虚函数表存储在内存的什么位置（哪个区）？虚表指针 vptr 的初始化位置？
50. 虚拟继承
51. 虚继承？
52. 单继承的内存模型是什么样的？
53. 多继承的内存模型
54. 虚继承的内存模型
55. 多继承的优缺点
56. 为什么友元函数必须在内部声明？
57. 什么是动态绑定，它的使用场景是什么？
58. 引用是否能实现动态绑定，为什么可以实现？
59. 解释编译时（compile-time）和运行时（run-time）多态（polymorphism），它们有什么区别？
60. 解释 C++ 中的静态多态（static polymorphism）和动态多态（dynamic polymorphism）。
61. 静态类型和动态类型、静态绑定和动态绑定的介绍
62. 继承机制中对象直接如何转换？
63. 什么是 RAII 技术
64. 介绍一下重载运算符？
65. 静态成员和普通成员的区别是什么？
66. 如何设计一个类来计算类实例化的个数
67. 如何计算一个类的子类个数
68. 如何阻止一个类被实例化的方法？
69. [用面向对象思想实现一个 string 类](./2-OrientedObjectCPlusPlus/MyString.hpp)

### 3、Generic
1. 什么是模板（template）？它的优缺点，底层如何实现的？
2. 什么是元编程
3. 元编程和模板的联系与区别
4. [什么是模板特化](https://www.cnblogs.com/wanghao-boke/p/17750991.html)
5. C++ 中的模板参数包（template parameter pack）是什么？它有什么作用？
6. 解释函数模板和类模板之间的区别
7. 什么是 SFINAE（Substitution Failure Is Not An Error）？
8. 什么是模板元编程（TMP）？它有什么应用场景
9. 解释 C++ 中的模板元编程（TMP）和泛型编程（generic programming）之间的区别
10. 为什么模板类一般都放在一个头文件中？

### 4、STL
1. C++ 中标准库是什么？
2. C++ 中的 STL 是什么？它包含哪些常用的容器类和算法？
3. 如何在共享内存中使用 STL 标准库？
4. STL 迭代器如何实现？
5. 迭代器失效的情况？
6. 迭代器 ++it、it++ 哪个好，为什么？
7. STL 容器内部删除一个元素？
8. STL 的 hashtable 实现
9. STL 的 traits 技法？
10. STL 的 allocator，deallocator
11. STL 的两级空间配置器
12. vecotr 容器介绍
13. vector 删除一个元素，迭代器如何变化
14. vector 容器是如何扩容的
15. vector 容器的扩容倍数为什么是 2？
16. list 容器
17. vector 和 list 区别
18. map、set 如何实现的，红黑树是怎么能够同时使用这两种容器的？为什么使用红黑树？
19. STL 的 unordered_map(hash_map) 和 map 的区别？
20. STL 的 unordered_map 和 map 的区别和应用场景？
21. STL set 和 map 的区别
22. STL set 和 multiset 区别
23. STL map 和 multimap 的区别？
24. unordered_map 如何解决冲突的
25. vector 和 map 越界访问下标发生什么？
26. map 中的 [] 和 find 有什么区别？
27. STL 中的 list 和 queue 区别？
28. STL 的 hash_map 扩容发生了什么？
29. 常见的容器性质总结？
30. STL 实现

### 5、C++ 11 
1. 函数对象
2. lambda
3. C++ 异常处理方法
4. RTTI
5. C++ 左值和右值
6. C++ 右值引用（rvalue reference）和左值引用（lvalue reference）
7. 右值引用？与左值引用有什么区别？
8. C++11 中的移动语义（move semantics）是什么？它有什么作用？
9. 解释完美转发（perfect forwarding）。
10. 什么是 noexcept 关键字？它有什么作用？
11. 解释 C++11 中的原子操作（atomic operation）和 std::atomic 类型。
12. auto、decltype 和 decltype(auto) 的用法？
13. fianl 和 override
14. 介绍智能指针和其作用

### 6、C++ Code test
1. 什么是代码覆盖率（code coverage）
2. C++ 中的测试框架，例如 Google Test 和 Boost.Test。
3. 在 C++ 中应该遵循哪些代码规范？

## [Linux Operation System](LinuxOperationSystem/LinuxOperationSystem.md)
### System Function

### Basic Conception
1. 什么是异步编程（asynchronous programming）？C++ 中如何实现异步编程？
2. 什么是异步 IO（asynchronous IO）？它在 C++ 中如何实现？
3. C++ 中有哪些常见的并发编程模型，例如共享内存、消息传递等？

### 协程
1. 什么是协程
2. 它们在 C++ 中有什么应用场景

### Thread
1. 什么是线程（thread）？C++ 中如何创建和管理线程？
2. 解释 C++ 中的多线程同步机制
3. 什么是互斥锁和条件变量
4. 什么是死锁（deadlock）？如何避免死锁？
5. 什么是信号（signal）？在 C++ 中如何处理信号？
6. 解释多线程中的线程安全（thread safety）和竞态条件（race condition）
7. Linux 下线程的相关函数

### Process
1. 什么是多进程（multiprocessing）？与多线程相比有哪些区别？
2. 进程同步和进程通信的区别
3. 进程通信的方式
4. Linux 下进程相关函数

### 进程、线程、协程的区别和联系？
1. 进程和线程的区别
2. 进程和线程的联系

### Opeartion System
1. 解释内存泄漏（memory leak）及其危害？如何处理内存泄漏问题？
2. C++ 进程的内存布局
3. printf 函数执行过程
4. C++ main 函数执行前后做了什么
5. 函数调用压栈过程
6. C++ 如何将临时变量返回给调用函数的
7. 程序在执行 int main(int argc, char *argv[]) 时的内存结构？
8. 结构体内存对齐
9. 结构体内部成员相对偏移量计算
10. 什么是内存池，如何实现？
11. 什么是静态分配和动态分配？
12. 类是如何实现只允许静态分配/动态分配的？
13. 堆和栈的区别？
14. 如何用代码判断大小端存储？

## [DataStruct](DataStructure/DataStructure.md)
### 数据结构
1. 什么是数据结构（data structure）？C++ 中常见的数据结构有哪些？
2. 时间复杂度和空间复杂度
    + 解释 C++ 中的时间复杂度和空间复杂度。
    + 什么是 O(n)、O(nlogn)、O(n^2) 等时间复杂度表示法？它们分别代表什么含义？

### 数组

### 链表
1. 链表反转
2. 单链表反转，删除指定的链表的一个节点
3. 单链表如何判断有环

### 哈希表
1. hash 用在什么地方，解决 hash 冲突几种方法？负载因子是什么？
2. 什么是哈希表（hash table）？它有什么作用？
3. hashtable 中解决冲突的方法？

### 栈

### 队列
1. 实现一个循环队列

### 树
1. 搜索二叉搜索树的的增删改查
2. 求一个树的最大距离
3. 求二叉树中两个节点最大距离
4. n 个节点的二叉树的所有不同构的个数
5. 二叉树的公共祖先，排序二叉树的公共祖先
6. 把一个二叉树原地变成一个双向链表
7. 找出二叉树的所有路径
8. 二叉树中寻找每一层中最大值
9. 求树的最大深度，最小深度，是否是平衡树
10. 二叉树中叶子节点个数
11. 交换左右孩子、二叉树镜像
12. 两个二叉树是否相等
13. 是否为完全二叉树
14. 是否为对称二叉树
15. 判断 B 是否是 A 的子树
16. 二叉树创建
17. 二叉树搜索
18. 平衡二叉树
19. huffman （哈夫曼）编码、构建 huffman 树
20. 什么是红黑树（red-black tree）？它有什么作用？
21. 什么是 AVL 树？它有什么作用？
22. 红黑树比 AVL 有什么优点
23. 什么是 B 树？它有什么作用？
24. 什么是 B+ 树
25. B 树和 B+ 树有什么区别
26. 什么是 Trie 树？它有什么作用？
27. 什么是堆（heap）？它有什么作用？
28. 什么是堆排序（heap sort）？它有什么特点？
29. 什么是并查集（union-find set）？它有什么作用？

### 图
1. 如何判断一个图是否联通
2. 什么是拓扑排序（topological sorting）？它有什么作用？
3. 什么是最短路径算法（shortest path algorithm）
4. 深度优先遍历
5. 宽度优先遍历
6. Dijkstra 算法
7. Bellman-Ford 算法
8. Floyd-Warshall 算法
9. 什么是最小生成树算法（minimum spanning tree algorithm）？
    + Prim 算法
    + Kruskal 算法

### C++ 中的排序算法
1. 快速排序
2. 归并排序
3. 冒泡排序
4. 堆排序
5. 选择排序
6. 希尔排序
7. 插入排序

### C++ 中的查找算法
1. 顺序查找
2. 二分查找
3. 插值查找
4. 斐波那契查找
5. 数表查找
6. 分开查找
7. 哈希查找

### 算法问题
1. TopK 问题
2. 求逆序对
3. 海量数据的 bitmap 使用原理
4. 最长公共子序列（动态规划）
5. 分治与递归（归并算法的两种实现）
6. 背包问题（贪心算法）
7. 回文字符串（动态规划）
8. 字符串匹配（KMP 算法）
9. 求一个数开根号（二分）
10. 万个数找到第20个大的数（堆排序）
11. 字符串最长不重复字串
12. 求 1-n 的子集

## [Computer Network](ComputerNetwork/ComputerNetwork.md)
### 网络模型
1. IOS七层模型是什么？各自的功能是什么？
2. 计算机四层模型
    + 在浏览器中输入url地址后显示主页的过程？
    + 浏览器地址栏输入一个url，回车后背后进行哪些技术步骤？

### 网络层
1. RARP 协议
    + RARP 是什么？
    + RARP 原理

### 传输层
1. TCP
    + TCP 三次握手过程？
    + TCP 挥手次数为啥要比握手多一次？
    + 为什么一定进行三次握手？
    + TCP 粘包？
    + TCP 可靠性保证？
    + TCP 拥塞控制？
    + TCP 流量控制？
    + 流量控制和拥塞控制的区别？
    + 一个TCP连接可以对应几个HTTP请求？
    + 一个TCP连接中HTTP请求发送可以一起发送吗？
    + 端口有效范围？
2. UDP
    + UDP 一个包最大能多大？
    + TCP 和 UDP 的区别？应用场景都有哪些？

### 应用层
1. HTTP
    + 一个完整的HTTP请求包括哪些内容？
    + HTTP1.0 和 1.1 有什么区别？
    + HTTP长连接和短连接的区别
    + HTTP请求方法？
    + HTTP请求和响应报文主要有哪些字段？
    + HTTP和HTTPS协议的区别？
    + GET和POST的区别？
    + GET、POST、PUT、DELETE、OPTIONS
    + HTTPS是如何保证数据传输安全的，整体流程是什么？（SSL是怎么保证安全的）
    + 如何保证公钥不被篡改？
    + cookie是什么？
    + cookie有什么用？
    + session知识总结？
    + session工作原理？
    + cookie 和 session 的区别？
    + SQL注入攻击？
2. DNS
    + DNS是什么？
    + DNS工作原理？
    + 域名解析为什么要使用UDP协议？
    + DNS解析过程？
    + DNS负载均衡？

### 网络 IO 复用
1. select
2. poll
3. epoll

## [C++ Compiler](Compiler/Compiler.md)
### C++ Compiler
1. 什么是编译器优化（compiler optimization）？C++ 中有哪些常见的编译器优化技术？
2. 什么是 C++ 中的动态链接库（dynamic link library，DLL）？它有什么作用？
3. 从代码到可执行程序的过程
4. C++ 调试技术
5. debug 和 release 区别？
6. 声明和定义的区别
7. 赋值和初始化的区别
8. 动态编译和静态编译

## [Design Pattern](DesignPattern/DesignPattern.md)
### Design Pattern
1. 什么是单例模式（singleton pattern）？解释它的优点和缺点。
2. 解释工厂模式（factory pattern）和抽象工厂模式（abstract factory pattern）。
3. 解释装饰器模式（decorator pattern）。它与继承（inheritance）有什么区别？
4. 什么是观察者模式（observer pattern）？
5. 解释迭代器模式（iterator pattern）和适配器模式（adapter pattern）
6. 什么是 MVC 模式？它在 C++ 中如何应用？
7. 什么是 CRTP（Curiously Recurring Template Pattern）？它有什么作用？
