# 函数对象
## 概述
1. 介绍 
    + 就是重载了 () 运算符的类实例，可以像函数一样使用
2. 代码 
```
#include <iostream>

using namespace std;

class FunctionObject
{
public:
    void operator() ()
    {
        cout << "Operator()" << endl;
    }
};

int main()
{
    FunctionObject val;
    val();

    return 0;
}
```

## 优点
1. 函数对象可以有自己的状态。
    + 我们可以在类中定义状态变量，这样一个函数对象在多次的调用中可以共享这个状态。但是函数调用没有这种优势，除非它使用全局变量来保存这个状态
2. 函数对象可以有自己特有的类型，而普通函数类无状态可言。
    + 这种特性对于 C++ 标准库来说是至关重要的。这样我们在使用 STL 中的函数时，可以传递相应的类型作为参数实例化相应的模板，从而实现我们自定义的规则。