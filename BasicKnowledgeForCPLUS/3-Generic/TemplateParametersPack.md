# 模板参数包
## 介绍
+ 模板参数包是一种模板元编程技术，允许模板函数或者模板类接受可变数据的参数，这些参数被称为参数包。分为模板参数包和函数参数包
    - 模板参数包表示零个或多个模板参数
    - 函数参数包表示零个或多个函数参数。
+ 省略号用于指示一个模板参数包或函数参数包，在函数调用时，编译器会将这些参数打包成一个对象，以便在函数中使用

## 作用
+ 允许定义具有形参数量可变的模板和函数

## 代码
```
#include<iostream>
#include<string>

template<typename T>
void print(const T&t)
{
    std::cout << t << std::endl;
}

template <typename T, typename... Args>
void print(const T& t, const Args&... args)
{
    std::cout << t << ",";
    print(args...);
}

int main()
{
    print(1,2,3.5, "hello", 'c');
    return 0;
}
```