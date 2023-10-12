/**
 * @file CuriouslyRecurringTemplatePatter.cpp
 * @author your name (you@domain.com)
 * @brief 奇异递归模板模式
 *      @Concept
 *          通过模板继承的方式实现静态多态
 *      @Introdution
 *          一个类从一个模板实例化继承自己，从而实现对积累的静态多态
 *      @Function
 *          实现一些高级的 C++ 技术，静态多态，元编程
 *      @Advantage
 *          效率高
 *      @Disadvantage
 *          代码可读性差
 *      @Realize
 *          定义一个模板类，这个模板类有一个类型参数，这个类型参数是继承这个模板类的
 *          子类可以通过继承模板累的方式实现静态多态。在子类中通过调用基类中定义的函数实现对基类的静态多态
 * @version 0.1
 * @date 2023-10-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>

template<typename Derived>
class Base
{
public:
    void foo(){
        static_cast<Derived*>(this)->foo_impl();
    }
};

class Derived : public Base<Derived>
{
public:
    void foo_impl(){
        std::cout << "Dervied::foo_impl()" << std::endl;
    }
};

int main()
{
    Derived d;
    d.foo();

    return 0;
}

/**
 * @brief 定义了一个Base的模板类，他有一个类型参数 Derived。
 *          Base 类中有一个 foo() 函数，他通过调用 Derived 类中的 foo_impl() 函数来实现对基类的静态多态
 *          在 Dervied 类中，我们通过继承 Base<Derived> 类来实现对积累的静态多态。Derived 类中有一个名为 foo_impl（） 的函数，它实现了对基类的静态多态
 * 
 */