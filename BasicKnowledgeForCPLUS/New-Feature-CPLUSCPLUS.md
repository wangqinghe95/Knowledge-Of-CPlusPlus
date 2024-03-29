# [C++ 11/14/17/20 新特性](https://zhuanlan.zhihu.com/p/389895793)

## C++ 11 新特性
1. 类型推导：auto，decltype
2. 右值引用：用于实现移动语义
3. 列表初始化：用于实现对象的初始化
4. std::function,std::bind,lambda 表达式：更加方便的调用函数
5. 智能指针：用于解决内存管理问题
6. 基于范围的 for 循环：更加方便的遍历容器内的元素
7. 委托构造函数和继承构造函数：可以简化对象的初始化

## C++ 14 新特性
1. 返回类型推导：可以让编译器自动推导函数的返回类型
2. 二进制字面量：可以使用 0b 或者 0B 前缀表示二进制数
3. 通用 lambda 表达式：可以使用 auto 作为 lambda 表达式的参数类型
4. 变量模板：可以定一个模板变量
5. 别名模板：可以定义一个模板类型别名
6. constexpr 函数限制减少：constexpr 函数可以包含循环和局部变量
7. [[deprecated]] 属性：用于标记过时的类、变量、函数等

## C++ 17 新特性
1. if 语句初始化：可以在 if 语句中初始化变量
2. 折叠表达式：可以在不使用显示递归的情况下使用可变参数模板编写紧凑的代码
3. constexpr if：可以在编译时进行条件判断
4. 结构化绑定：可以将结构体或者元组的成员绑定到变量上
5. [[nodiscard]]属性：用于标记函数返回值必须被检查
6. 内联变量：可以直接将全局变量定义在头文件上
7. std::optional：用于表示可选值
8. std::variant：用于表示多态值

## C++ 20 新特性
1. Concept：用于定义模板的约束条件
2. Ranges：对 STL 算法库和迭代器库的扩展和泛化
3. Coroutines：用于实现异步编程
4. Module：用于代替头文件进行模块化编译
5. 三向比较运算符：用于简化比较操作
6. consteval：用于在编译期间计算常量表达式
7. std::span：用于表示连续的内存区域
8. std::format：用于格式化字符串
9. std::stop_toke：用于取消异步操作
