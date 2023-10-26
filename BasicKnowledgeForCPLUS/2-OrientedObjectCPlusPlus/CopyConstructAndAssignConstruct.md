# 拷贝构造函数和赋值构造函数

## 拷贝构造函数
+ 拷贝构造函数是一种特殊的构造函数，用于创建一个新对象并将其初始化为与现有对象相同的值
+ 它通常在以下情况被调用
    1. 将一个对象作为参数传递给函数，以值的传递方式
    2. 从函数返回一个对象时，已值的方式返回
    3. 使用一个对象初始化另一个对象


## 赋值构造函数
+ 赋值构造函数是一种特殊的构造函数，用于将一个已经存在的对象的值赋值给另一个已经存在的对象
+ 它通常在以下情况下被调用
    + 将一个已经初始化过的对象赋值给另一个已经初始化过的对象

## 代码
```
#include<iostream>
using namespace std;

class MyClass
{
public:
    int value;
    MyClass() : value(0) {}

    // copy constructor
    MyClass(const MyClass& other)
    {
        value = other.value;
    }

    // assignment constructor
    MyClass& operator=(const MyClass& other)
    {
        if (this == &other ){
            return *this;
        }
        value = other.value;
        return *this;
    }
};

int main()
{
    MyClass stru_obj1;
    stru_obj1.value = 42;
    MyClass stru_obj2 = stru_obj1; // Using copy constructor to create a new object and copy the value
    
    MyClass stru_obj3;
    stru_obj3 = stru_obj2;  // Using assignment constructor to copy the value
    
    return 0;
}
```