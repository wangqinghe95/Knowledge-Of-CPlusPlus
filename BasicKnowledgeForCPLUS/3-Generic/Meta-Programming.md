# 元编程
+ 定义
    + 元编程是一种编程范式，它允许程序员便携通用代码，以便在不同数据类型上操作
    + 元编程中，程序本身是动态的，程序运行也是动态的。元编程将程序作为数据来对待，从而赋予变成语言更加强大的表达能力
## 使用模板元编程实现类型选择和编译时计算
+ 代码

```
#include<iostream>
#include<type_traits>
#include<typeinfo>

// conditional_t 的模板别名，用于根据给定条件选择的两个不同的类型
template <bool B, typename T, typename F>
using conditional_t = typename std::conditional<B,T,F>::type;

// 模板类，用于计算给定整数的阶乘
template <int N>
struct factorial
{
    static constexpr int value = N * factorial<N - 1>::value;
};

template <>
struct factorial<0>
{
    static constexpr int value = 1;
};

// 模板类，检查给定的类型是否为指针类型

template <typename T>
struct is_pointer : std::false_type{};

// 不能使用 using namespace std, 否则该行会报错
template <typename T>
struct is_pointer<T*> : std::true_type {};

int main()
{

    // 计算 5 的阶乘
    constexpr int fact_5 = factorial<5>::value;
    std::cout << "Factorial of 5 is " << fact_5 << std::endl;

    // 
    using type = conditional_t<is_pointer<int>::value, int*, double>;
    std::cout << "Type is " << typeid(type).name() << std::endl;

    return 0;
}

```

## 使用模板元编程实现递归和循环
+ 代码
```
#include<iostream>
#include<type_traits>

// 模板类，计算给定整数的阶乘
template <int N>
struct factorial
{
    static constexpr int value = N * factorial<N-1>::value;
};

template <>
struct factorial<0>
{
    static constexpr int value = 1;
};

// 模板类，计算给定位置的斐波那契数列，递归实现
template <int N>
struct fibonacci
{
    static constexpr int value = fibonacci<N-1>::value + fibonacci<N-2>::value;
};

template <>
struct fibonacci<0>
{
    static constexpr int value = 0;
};

template <>
struct fibonacci<1>
{
    static constexpr int value = 1;
};

int main()
{
    constexpr int fact_5 = factorial<5>::value;
    std::cout << "Factorial of 5 is " << fact_5 << std::endl;

    constexpr int fib_10 = fibonacci<10>::value;
    std::cout << "Fibonacci number at point 10 is " << fib_10 << std::endl;

    return 0;
}
```
## 使用模板元编程实现函数式编程
+ 通常使用函数式编程实现可变参数模板
```
#include <iostream>
#include <functional>

template <typename F, typename... Args>
auto curry(F f, Args... args) {
    return = {
        return f(args..., new_args...);
    };
}

int add(int a, int b, int c) {
    return a + b + c;
}

int main() {
    auto add5 = curry(add, 5);
    auto add5and6 = curry(add5, 6);
    std::cout << add5and6(7) << std::endl; // 输出 18
    return 0;
}

```
+ 编译时一直要求 auto 指定返回类型。未通过编译