# std::function

## 介绍
+ std::function 是一个函数包装器
+ std::function 类型对象实例可以包装以下可调用实体
    - 普通函数
    - 函数指针
    - 成员函数
    - 静态函数
    - lambda 表达式
    - 函数对象
+ std::function 对象实例可被拷贝和移动，并且可以使用指定的调用特征来直接调用目标元素
+ std::function 对象实例不允许 == 和 !== 比较操作

## 使用
### 基础使用
```
#include <functional>
#include <iostream>

using std::function;
using std::cout;
using std::endl;

int (*fun_tr)(int);
int fun1(int a) {
    return a;
}

int bindFunctionPointer()
{
    cout << "Functional Pointer" << endl;

    fun_tr = fun1;

    function<int(int)> callback = fun_tr;

    cout << callback(10) << endl;

    return 0;
}

int bindFunction()
{
    cout << "Function" << endl;

    function<int(int)> callback = fun1;
    cout << callback(3) << endl;

    return 0;
}

template<typename T>
T func2(T a)
{
    return a + 2;
}

int bindTemplateFunction()
{
    cout << "bind temlpate function" << endl;
    function<int(int)> callback = func2<int>;
    cout << callback(15) << endl;

    return 0;
}

struct add
{
    int operator()(int x) {
        return x + 9;
    }
};

int bindFunctor()
{
    cout << "bind Functor" << endl;
    function<int(int)> callback = add();
    cout << callback(5) << endl;

    return 0;    
}

int bindLambda()
{
    cout << "bind Lambda" << endl;

    auto fun3 = [](int a) {
        return a * 2;
    };

    function<int(int)> callback = fun3;
    cout << callback(6) << endl;

    return 0;   
}

template <typename T>
struct sub
{
    T operator()(T a) {
        return a - 8;
    }
};

int bindTemplateObjectFunction()
{
    cout << "bind template object function" << endl;
    function<int(int)> callback = sub<int>();
    cout << callback(5) << endl;

    return 0;    
}

template <typename T>
struct foo2
{
    static T foo(T a) {
        return a * 4;
    }
};

int bindTemplateObjectStaticFunction()
{
    cout << "bind template object static function" << endl;
    function<int(int)> callback = foo2<int>::foo;
    cout << callback(5) << endl;

    return 0;    
}

struct foo1
{
    static int foo(int a) {
        return a * 3;
    }
};

int bindObjectStaticFunction()
{
    cout << "bind object static function" << endl;
    function<int(int)> callback = foo1::foo;
    cout << callback(5) << endl;

    return 0;    
}

struct foo3
{
    int foo(int a) {
        return a * a;
    }
};

int bindClassMemberFunction()
{
    cout << "bind class member function" << endl;
    foo3 test_foo1;
    function<int(int)> callback = std::bind(&foo3::foo, test_foo1, std::placeholders::_1);

    cout << callback(5) << endl;

    return 0;    
}

template <typename T>
struct foo4
{
    T foo(T a) {
        return a * a * a;
    }
};

int bindTemplateClassFunction()
{
    cout << "bind template class member function" << endl;
    foo4<int> test_foo2;
    function<int(int)> callback = std::bind(&foo4<int>::foo, test_foo2, std::placeholders::_1);

    cout << callback(7) << endl;

    return 0;        
}

int copyAndMove()
{
    cout << "functional move and copy" << endl;
    function<int(int)> callback = foo2<int>::foo;

    function<int(int)> callback1 = callback;
    cout << "functional move assignment: " << callback1(20) <<  endl;

    std::function<int(int)>&& callback3 = std::move(callback);
    cout << "functional move assignment callback3: " << callback3(20) <<  endl;
    cout << "functional move assignment callback: " << callback(20) <<  endl;

    function<int(int)> callback4(callback);
    cout << "functional cpoy assignment: " << callback4(50) <<  endl;

}

int main()
{
    // bind normal function
    bindFunction();

    // bind functional pointer
    bindFunctionPointer();

    // bind template function
    bindTemplateClassFunction();

    // bind functor
    bindFunctor();

    // bind lambda
    bindLambda();

    // bind template object function
    bindTemplateObjectFunction();

    // bind template object sattic function
    bindTemplateObjectFunction();

    // bind object static function
    bindObjectStaticFunction();

    // bind class member's function
    bindClassMemberFunction();

    // bind template class member's function
    bindTemplateClassFunction();

    // assignment of copy and move for std::function
    copyAndMove();

    return 0;
}
```