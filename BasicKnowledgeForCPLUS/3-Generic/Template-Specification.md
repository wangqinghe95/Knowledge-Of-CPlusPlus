# 模板特化
## 介绍
+ 模板特化是指在模板的基础上，针对某些特定的值，提供一种特殊的实现方式，模板特化分为两种，类模板特化和函数模板特化

## 类模板特化
+ 类模板特化指的是在类模板上，针对某些特定的类型和值，提供一种特殊的实现方式。类模板特化分为全特化和偏特化两种。

### 类模板全特化
1. 定义
	- 全特化是指将模板参数列表中的所有参数都确定化；
2. 示例
```
// class_Template_Ful_Specification.cpp
/**
 * 类模板全特化
 * 代码中，定义了一个名为 MyType 的类模板
 * 使用类模板全特化提供了一个 int 类型的特殊实现
*/

#include<iostream>

using namespace std;

template <typename T>
class MyType
{
public:
    void print(){
        cout << "This is a generic type." << endl;
    }
};

template <>
class MyType<int>
{
public:
    void print(){
        cout << "This is an integer type" << endl;
    }
};

int main()
{
    MyType<float> f;
    f.print();

    MyType<int> i;
    i.print();

    return 0;
}
```

### 类模板偏特化
1. 定义
	- 偏特化是指模板参数列表的一部分参数确定化
2. 示例
```
// Class_Template_Partial_Specification.cpp
/**
 * 类模板偏特化
 * 定义了一个 MyType 的类模板，然后使用类模板提供一个针对第二个参数为 int 类型的特殊实现
*/
#include<iostream>

using namespace std;

template <typename T1, typename T2>
class MyType
{
public:
    void print(){
        cout << "This is a generic type" << endl;
    }
    
};

template <typename T>
class MyType<T,int>
{
private:
    /* data */
public:
    void print(){
        cout << "This is a type with an interger as its second parmeter." << endl;
    }
};

int main()
{
    MyType<float, double> f;
    f.print();

    MyType<int,int> i;
    i.print();

    return 0;
}
```

## 函数模板特化
+ 函数模板特化指的是在函数模板的基础上，针对某些特定的类型或值，提供一种特殊的实现方式。函数模板特化分为全特化和偏特化两种：

### 函数模板全特化
1. 定义
	- 全特化是指将函数模板中所有参数都确定化；
2. 示例
```
// Function_Template_Full_Specification.cpp
/**
 * 函数模板全特化：
 * 定义一个名为 MySwap 的函数模板，然后使用函数模板全特化来提供一个针对 double 类型的特殊实现
*/
#include<iostream>

using namespace std;

template<typename T>
void MySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <>
void MySwap(double& a, double & b)
{
    cout << "This is a special implementation for double types." << endl;
    double temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 5, y = 10;
    MySwap(x,y);
    cout <<"X : " << x << " Y : " << y <<endl;

    double p = 3.14, q = 6.28;
    MySwap(p, q);
    cout << "P : " << p << " Q : " << q << endl;

    return 0;
}
```

### 函数模板偏特化
1. 定义
	- 偏特化是指将函数模板中的一部分参数确定化
2. 示例
+ 直接使用函数模板偏特化，C++ 编译器不支持
```
// Function_Template_Partial_Specification.cpp
/**
 * 函数模板偏特化
 * 
*/

#include <iostream>

using namespace std;

template<typename A, typename B> 
void f(A a, B b)
{
    cout << "Normal Version" << endl;
}

// 函数模板偏特化，但是编译器不支持函数模板偏特化
/*
template<typename A> 
void fun<A,int>(A a, int b)
{
    cout << "Partial Version" << endl;
}
*/

int main()
{
    int a = 10;
    double b = 12;
    f(a,b);
    f(a,a);

    return 0;
}
```

+ 使用类模板偏特化间接实现函数模板偏特化
```
#include <iostream>

using namespace std;

// 借助类模板偏特化，使用 Functor 代替函数
template <typename A, typename B>
class F
{
public:
    F(A a, B b):a_(a), b_(b){}
    void operator() (){
        cout << "Normal version" << endl;
    }

private:
    A a_;
    B b_;
};

template <typename A>
class F<A,int>
{
public:
    F(A a, int b) : a_(a), b_(b){}

    void operator()(){
        cout << "Partial version." << endl;
    }
private:
    A a_;
    int b_;

};

int main()
{
    int a = 10;
    double b = 12;
    F<int, double>(a,b)();
    F<int,int>(a,a)();

    return 0;
}
```

+ 标签分发，通过函数重载实现函数模板偏特化
```
#include<iostream>

using namespace std;

struct NormalVersionTag{};
struct IntPartialVersionTag{};

template<class T>
struct TagDispatchTrait
{
    using Tag = NormalVersionTag;
};

template<>
struct TagDispatchTrait<int>
{
    using Tag = IntPartialVersionTag;
};

template <typename A, typename B>
inline void internal_f(A a, B b, NormalVersionTag)
{
    cout << "Normal Version" << endl;
}

template <typename A, typename B>
inline void internal_f(A a, B b, IntPartialVersionTag)
{
    cout << "Partial Version" << endl;
}

template <typename A, typename B>
void f(A a, B b)
{
    return internal_f(a, b, typename TagDispatchTrait<B>::Tag {});
}

int main()
{
    int a = 10;
    double b = 12;
    f(a,b);
    f(a,a);

    return 0;
}
```