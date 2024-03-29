+ C和C++的区别

**基础语法**

+ 形参和实参的区别？

+ 结构体内存对齐问题？

+ 内存对齐的理解以及理解？

+ 如何获取结构体成员相对于结构体开头的字节偏移量？

+ 结构体变量比较是否相等？

+ 指针和引用的区别？

+ 在汇编层面上解释一下引用？

+ const 的用法？（常量指针和指针常量的区别，C++ 中顶层 const 和底层 const）

+ static 的用法？（静态变量什么时候初始化）

+ strlen 和 sizeof 的区别？

+ extern"C" 的用法？

+ 宏定义（define）和 typedef 的区别？

+ 宏定义（define）和函数的区别？

+ 宏定义（define）和 const 的区别？

+ 宏定义（define）和内联函数的区别？

+ define、const、typedef、inline的使用方法？他们之间的区别？

+ 变量声明和定义的区别？（声明和定义的区别？）

+ 不同的指针类型？（数组名和指针， a 和 &a 之间的区别）

+ 野指针和悬空指针？

+ 简要说明 C++ 内存分布？

+ 初始化和赋值的区别？

+ 什么是内存池，如何实现？

+ 什么是内存泄漏？如何检查和避免？（内存泄露后果，如何检测，解决方案？）

+ C++ 函数调用压栈过程？

+ C++ 将临时变量作为返回值时的处理过程？

+ 全局变量和局部变量有什么区别？（全局变量和 static 变量区别？）

+ 指针加减要注意什么？

+ 如何判断两个浮点数相等？

+ 方法调用的原理？

+ 函数指针是什么？

+ 函数调用过程中栈的变化，返回值和参数变量哪个先入栈？

+ printf 函数实现原理？

+ lambda函数的全部知识？

+ 将字符串 “hello world” 从开始到打印屏幕上的全过程？

+ cout 和 printf 有什么区别？

+ ifdef、endif 代表着什么？

+ 在使用额外空间的情况下，交换两个人数，你有几种方法？

+ strcpy 和 memcpy 的区别？

+ 程序在执行 int main(int argc, char *argv[]) 时的内存结构？

+ const char* 和 string 之间是什么关系？

+ 如何快速定位错误出现的地方？

+ strcpy、sprintf、memcpy 这三个函数的不同之处？

+ Debug 和 release 的区别？

+ main 函数的返回值有什么考究之处的？

+ strcpy 函数和 strncpy 函数的区别？哪个更安全？

+ 回调函数的作用？

+ 一致性哈希？

+ C++ 从代码到可执行函数经历了什么？（预编译、编译、汇编、链接（静态链接、动态链接））

------

**关键字**

+ malloc 和 free 实现的原理？

+ malloc、realloc、calloc 区别？

+ new/delete 和 malloc/free 的区别？（new 和 malloc 的区别？）

+ new 和 delete 是如何实现的？（delete 是如何知道要释放内存的大小？）

+ malloc 申请的空间能用 delete 释放吗？

+ delete 和 delete [] 的区别？（delete、delete []、alloctor 有什么作用？）

+ C++ 有几种类型的 new？

+ c++ 中 NULL 和 nullptr 的区别？

+ C++ 中 struct 和 class 的区别？ C 中 struct 和 C++ struct 的区别？

+ final 和 override 关键字？

+ 值传递、指针传递、引用传递的区别和效率？

+ auto、decltype 和 decltype(auto) 的用法？

+ C++ 四种强制转换 reinterpret_cast/const_cast/static_cast/dynamic_cast 用法？

+ 将引用作为函数参数的好处是什么？

+ 数组和指针的区别？

+ static_cast 比 C 语言的转换强在哪里？

+ hello.c 的编译过程？（静态链接、动态链接）

+ 介绍几种典型的锁？

+ C++ 左值引用、右值引用？

----

**重载、虚函数**

+ C++ 中重载、重写（覆盖）、和隐藏的区别？

+ 什么是虚函数？虚函数和纯虚函数的区别？

+ 基类的虚函数表存储在内存的什么位置（哪个区）？虚表指针 vptr 的初始化位置？

+ 静态类型和动态类型、静态绑定和动态绑定的介绍

+ 引用是否能实现动态绑定，为什么可以实现？

+ C++ 指针参数传递和引用参数传递有什么区别？底层原理是什么？

+ 重载运算符？

+ 函数中有重载时，函数的匹配原则和顺序是什么？

+ 什么是隐式转换，如何消除隐式转换？

+ volidate 关键词作用是什么？

+ 你什么时候用指针当参数，什么时候用引用当参数，为什么？

+ 静态函数能定义为虚函数吗？常函数呢？

+ 虚函数的代价？

+ 什么是纯虚函数，与虚函数的区别？

+ 用 C 实现 C++ 继承？

+ 动态编译和静态编译？

----

**类、对象、继承**

+ 介绍面对对象的三大特性，并举例说明？

+ 是什么是类的继承？

+ 类成员初始化方式？构造函数的执行顺序？为什么成员初始化类列表会快一些？

+ 拷贝初始化和直接初始化的区别？

+ 什么是成员列表初始化？什么时候必须要用初始化成员列表？

+ 类的对象存储空间？

+ 类什么时候会析构？

+ C++ 有哪几种构造函数？

+ 构造函数的几种关键字？

+ 为什么析构函数一般写成虚函数？

+ 构造函数能否声明为虚函数或者纯虚函数，析构函数呢？ （构造函数为什么不能是虚函数，析构函数为什么要是虚函数）

+ 析构函数的作用？以及是如何起作用的？

+ 构造函数和析构函数可以调用虚函数吗？为什么？（构造函数或者虚构函数中可以调用虚函数吗？）

+ 构造函数和析构函数的执行顺序，以及它们的内部都做了什么？

+ 虚析构函数的作用？父类的析构函数是否要设置为虚函数？

+ 构造函数和析构函数可否抛出异常？

+ 构造函数一般都定义为虚函数的原因？

+ 构造函数、拷贝构造函数和赋值操作符的区别？

+ 拷贝构造函数和赋值运算符重载的区别？

+ C++ 多态是如何实现的？

+ 浅拷贝和深拷贝的区别？

+ 构造函数、析构函数、虚函数是否能声明为内联函数？

+ public/protected/private 区别和访问、继承权限？

+ 什么时候调用拷贝构造函数？

+ C++ 中类数据成员和成员函数内存分布情况？

+ 什么是 trivial destructor？

+ 什么是对象复用？什么是零拷贝？

+ 移动构造函数？

+ 关于 this 指针？
    - this 指针何时创建的？
    - this 指针存放在哪里？堆、栈、全局变量、还是其他？
    - this 指针是如何传递类中的函数的？绑定还是函数参数的首参数就是 this 指针？那么 this 指针是如何找到“类实例后函数的”？
    - this 指针是如何访问类中的变量的？
    - 只有获得一个对象后，才能通过对象使用 this 指针。如果我们知道一个对象 this 指针的位置，可以直接使用吗？
    - 每个类编译后，是否创建一个类中函数保存函数指针，以便用来调试函数？

+ 在成员函数中 delete this 会出现什么问题？对象还可以使用吗？

+ this 指针调用成员变量时，堆栈会发生变化吗?

+ 什么是虚拟继承？

+ 类是如何实现只能静态分配和动态分配的？

+ 如果想将某个类作为一个基类，为什么该类必须定义而非声明？

+ 什么情况会自动生成默认构造函数？

+ 抽象基类为什么不能创建对象？

+ 继承机制中对象直接如何转换？指针和引用之间如何转换？

+ C++ 的组合和继承有什么区别和优缺点？

+ C++ 类成员的访问权限和继承权限问题？

+ 静态成员和普通成员是什么？

+ 虚函数内存结构，棱形继承的虚函数内存结构呢？

+ 多继承的优缺点，作为一个开发者如何看待多继承？

+ 如果有一个空类，它会默认添加什么函数？

+ 空类大小是多少？

+ 拷贝构造函数为什么必须引用而不能传值？

+ 如何设计一个类来计算子类的个数？

+ 类对象大小受到哪些因素影响？

+ 什么时候用到合成构造函数？

+ 什么时候用到合成拷贝构造函数？

+ 成员初始化列表会在什么时候用到？它的调用过程是什么？

+ 构造函数的执行顺序是什么？

+ 一个类中的全部构造函数的扩展过程是什么？

+ 哪些函数不能是虚函数?
 
+ 如何阻止一个类被实例化的方法？

+ 如何禁止程序自动生成拷贝构造函数？

+ 成员函数中 memset(this, 0, sizeof(this)) 会发生什么？

+ 为什么友元函数必须在内部声明？

---

**独立特性（范式编程，异常机制、元编程、STL标准库）**

+ 迭代器失效的情况？

+ C++ 异常处理方法？（C++ 是如何处理多个异常的）

+ C/C++ 类型安全？

+ C++ 模板是什么，底层是如何实现的？

+ 模板函数和模板类的用法？

+ 智能指针的作用、原理、常用的智能指针及实现？

+ auto_ptr 作用？

+ 智能指针的循环引用？

+ 智能指针管理内存资源，RAII是什么？

+ 手写实现智能指针类？

+ 智能指针出现循环引用怎么解决？

+ C++ 11 有哪些新特性？

+ 模板类和模板函数的区别？

+ 为什么模板类一般都放在一个 .h 文件中？

+ 迭代器 ++it、it++ 哪个好，为什么？

+ 模板和实现写一个文件中可不可以？为什么？

+ C++ 中标准库是什么？

+ 写一个比较大小的模板？

+ STL 的 hashtable 实现

+ STL 的 traits 技法？

+ STL 的两级空间配置器？（一级配置器，二级配置器，一级分配器，二级分配器）

+ vector 和 list 的区别与应用，怎么找到某 vector 和 list 的倒数第二个元素?

+ STL 中 vector 删除其中的元素，迭代器如何变化？为什么是两倍扩容？释放空间？

+ STL 容器内部删除一个元素？

+ STL 迭代器如何实现？

+ map、set 如何实现的，红黑树是怎么能够同时使用这两种容器的？为什么使用红黑树？

+ 如何在共享内存中使用 STL 标准库？

+ map 插入有几种方式？

+ STL 的 unordered_map(hash_map) 和 map 的区别？hash_map 如何解决冲突和扩容？

+ vector 越界访问下标，map 越界访问下标？ vector 删除元素会不会释放空间？

+ map 中的 [] 和 find 有什么区别？

+ STL 中的 list 和 queue 区别？

+ STL 的 allocator deallocator

+ STL 的 hash_map 扩容发生了什么？

+ 常见的容器性质总结？

+ vector 的增加删除是怎么做到的，为什么是 1.5 或者是 2？

+ 说一下 STL 每种容器对于的迭代器？

+ STL 的 vector 实现

+ STL 的 slist 实现

+ STL 的 list 实现

+ STL 的 deque 实现

+ STL 的 stack 和 queue 实现

+ STL 的 heap 实现

+ STL 的 priority_queue 实现

+ STL 的 set 实现

+ STL 的 map 实现

+ set 和 map 的区别，multimap 和 multiset 的区别？

+ STL 的 unordered_map 和 map 的区别和应用场景？

+ hashtable 中解决冲突的方法？
----









