# lambda 表达式

1. 介绍
+ C++11引入的新特性，可以方便地定义和创建一个匿名函数，可以帮助开发者在保持代码的逻辑精简的同时不需要写一个普通的函数类；

2. 语法
+ 具体语法
```
[capture_list](params_list) mutable exception -> return_type
{
    function body;
}
```
+ 解释：
    + capture_list：捕获外部变量列表
    + params_list：形参列表
    + mutable：用于说明是否需要修改捕获的列表，可选
    + exception：异常设定，可选
    + return_type：返回类型，可选
    + functionn_body：函数体
+ 省略格式
```
[capture_list](params_list)->return_type {function_body}
// 声明了 const 类型的表达式，这种类型的表达式不能修改捕获列表中的值
```
```
[capture_list](params_list){function_body}
/*
省略了返回值类型，编译器可以根据一下规则推断 lambda 返回类型
1. 如果 function_body 中含有 return 语句，则 lambda 返回类型由 return 语句的返回类型确定
2. 如果 function_body 中没有 return 语句，则返回值类型为 void 型
*/
```
```
[capture_list]{function_body}
// 省略了参数列表，类似与普通的无参函数
```

3. lambda 内部实现
+ 编译器会为 lambda 表达式生成一个匿名类，该类重载 operator()
+ 代码
```
int id = 0;
auto f = [id]() mutable {
    cout << "id: " << id << endl;
    ++id;
};

// 上述代码会被会被编译器自动出一个带重写 operator() 的匿名类
/*
匿名函数名称由编译器自己决定
私有成员变量由捕获列表决定
重载的操作符内容由 lambda 内部函数体决定
*/
class Functor {
private:
    int id;
public:
    void operator() (){
        std::cout << "id： " << id << endl;
        ++id;
    }
};
```

4. lambda 使用
+ 捕获列表：
    + []:什么也不捕获
    + [=]: 按值的方式捕获所有变量
    + [&]: 按引用方式捕获所有变量
    + [boo]:值捕获 boo 的值
    + [=, &a]: 按值捕获所有局部变量，按引用捕获变量a。
    + [=, &a, &b, &c]:同上，
    + [&, a]：按引用捕获所有局部变量，按值捕获方式捕获 a
    + [&, a, b, c]：同上
    + [this]：在成员函数中，直接捕获 this 指针
+ mutable：
    + 值捕获后，在匿名函数中对该值是不能做修改的，如果想要做修改，必须加上 mutable 关键字，并且在匿名函数中做的修改结果在函数外是不会生效的；
+ parameters:
    + 参数列表也是可以将外部的值传递给匿名函数内部的，和捕获列表的在于，parameter 对应的 operator函数的形参列表。
+ return-tyep：
    + 对于编译器能自动推导的返回类型，可以省略 return-type，但是如果无法推导的类型，就必须添加上返回类型
    + 当函数不止一个return语句时，就需要加上返回类型了。

5. lambda 使用代码举例
```
#include<iostream>

using namespace std;

void capturePassedByValueAll();
void capturePassedByReferenceAll();
void capturePassedByValueExceptSome();
void lambdaMutable();
void lambdaParameter();
void lambdaReturnType();

int main() {

    // passed by value
    capturePassedByValueAll();

    // passed by reference
    capturePassedByReferenceAll();

    // passed by value all excpet some
    capturePassedByValueExceptSome();

    // passed by value all and mutable
    lambdaMutable();

    // lambda in parameter
    lambdaParameter();

    // lambda in return
    lambdaReturnType();
    return 0;
}

void lambdaReturnType()
{  
    auto autoGetRetutnType = []() {
        return 5+3;
    };
    cout  << "lambdaReturnType = " << autoGetRetutnType() << endl;

    auto specifyReturnType = [](int x)->string {
        if (x > 0) {
            return "x more than zero";
        }
        else {
            return "x less than zero";
        }
    };
    cout  << "specifyReturnType = " << specifyReturnType(2) << endl;

}

void lambdaParameter()
{
    int a = 1;
    int b = 2;
    
    auto f = [](int a, int b) {
        return a > b ? a : b;
    };

    cout  << "lambdaParameter f(a,b) = " << f(a, b) << endl;
}

void lambdaMutable()
{
    int a = 1;
    int b = 2;

    auto passedByValueMutable = [=]()mutable {
        cout << "lambdaMutable start a :" << a << " b: " << b << endl;
        a++;
        b++;
        cout << "modify after a :" << a << " b: " << b << endl;
    };
    passedByValueMutable();
    cout << "lambdaMutable a :" << a << " b: " << b << endl;
}

void capturePassedByValueExceptSome()
{
    int a = 0;
    int b = 1;
    int c = 100;
    int d = 200;
    auto passedByValueExceptSome = [=, &c, &d]() {
        cout << "capturePassedByValueExceptSome start a = " << a << " b = " << b << endl;
        cout << "midify after c = " << c << " d = " << d << endl;
        
        c++;
        d++;
        cout << "midify after c = " << c << " d = " << d << endl;
        cout << "capturePassedByValueExceptSome end" << endl;

    };

    passedByValueExceptSome();
    cout << "a = " << a << " b = " << b << endl;    
}

void capturePassedByReferenceAll()
{
    int c = 100;
    int d = 200;
    auto passedByReference = [&] {
        cout << "passedByReference c = " << c << " d = " << d << endl;
        c++;
        d++;
        cout << "c = " << c << " d = " << d << endl;
        cout << "passedByReference end" << endl;
    };
    passedByReference();
    cout << "c = " << c << " d = " << d << endl;
}

void capturePassedByValueAll()
{
    int a = 0;
    int b = 1;
    auto passedByValue = [=]() {
        cout << "passedByValue start a = " << a << " b = " << b << endl;
        cout << "passedByValue end" << endl;
    };

    passedByValue();
    cout << "a = " << a << " b = " << b << endl;
}
``` 