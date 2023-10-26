# std::bind

## 介绍
+ std::bind 是一个函数包装器，允许程序将参数绑定到函数上，并获取一个新的函数对象
    - 该对象可以使用指定的参数进行调用
+ std::bind 返回一个新的函数对象，该对象是原始函数对象的副本，但是某些参数值已经绑定了特定值
+ std::bind 是一种延迟计算的思想，通过绑定参数或者放置一个占位符，在实际调用执行的时候传入。
+ std::bind 是一个模板函数，std::function 是一个模板类。
    - std::bind 的结果可以由 std::function 保存
## 作用
+ 将可调用对象与其参数一起绑成一个仿函数
+ 将多元可调用对象转换成一元或者低元可调用函数，即只绑定部分参数

## 应用场景
1. 绑定参数：将一部分参数绑定到特定的值或者对象上，从而创建一个新的函数对象。
    - 在需要将函数作为回调函数传递，但是又需要固定一些参数时非常有用
2. 绑定非成员函数：可以用于绑定非成员函数，全局函数或者静态成员函数，从而创建一个新的函数的对象。
    - 该对象可以在不传递任何对象的情况下调用
3. 绑定成员函数：可以用于绑定成员函数，将对象的成员函数和对象本身绑定到一起，从而创建一个函数对象
    - 在需要将成员函数作为回调函数传递时非常有用

## 使用
### 普通函数/全局函数/静态函数
1. bind 绑定时，第一个参数是函数名，后续将该函数所需要的参数依次放入即可
2. 如果是用 function 类型存储 bind 的返回值，则，function 类型如下
    + `function<[return_tyep](type1,type2)>`
    + return_tyep: 表示表达式返回类型
    + type1,type2... :表示的是被占位符占位的数据类型和个数
        + 占位符要从 _1 开始
3. 返回值可以直接使用 auto 类型推导即可

### 类成员函数，类静态成员函数
1. 绑定类成员函数时，类成员函数必须取地址作为第一个参数传入，类对象作为第二个参数传入，后续跟需要传入的参数或者绑定符号
2. 绑定类静态成员函数时，等同于静态函数
    + 普通函数/全局函数/静态函数/类静态成员函数的函数名就是函数入口地址

## 代码示例
### 绑定普通函数/全局函数/静态函数
```
#include <iostream>
#include <functional>

using namespace std;

void func1(int a,int b, int c)
{
    cout << a << " " << b << " " << c << endl;
}
static int func2(int a, float b, string c)
{
    cout << "b " << b << endl;
    cout << "c " << c << endl;
    return a;
}
void bindNormalFunc()
{
    function<void(int,int,int)> pf = bind(func1, placeholders::_1, placeholders::_2, placeholders::_3);
    function<void(int,int)> pf1 = bind(func1, placeholders::_1, placeholders::_2, 6);
    function<void(int)> pf2 = bind(func1, 42, 41, placeholders::_1);
    auto pf3 = bind(&func1, placeholders::_1, placeholders::_2, placeholders::_3);
    auto pf4 = bind(func1, 11 ,placeholders::_1, placeholders::_2);

    function<int(float, string)> pf5 = bind(func2, 14, placeholders::_1, placeholders::_2);

    pf(1,2,3);
    pf1(4,5);
    pf2(7);
    pf3(8,9,10);
    pf4(12,13);
    cout << pf5(15.5, "hi") << endl;
}

int main()
{
    bindNormalFunc();

    return 0;
}
```

### 绑定类成员函数
```
class TestBind
{
public:
    void printSum(int a, int b) {
        cout << "Sum: " << a+b << endl;
    }

    static int printLog(int a, string s) {
        cout << a << " " << s << endl;
        return a;
    }
};

void testClassFunction()
{
    TestBind CTestBind;
    auto pf = bind(&TestBind::printSum, CTestBind, 10, placeholders::_1);
    auto pf_1 = bind(TestBind::printLog, 10, placeholders::_1);

    pf(5);
    cout << pf_1("xaxc") << endl;;
}
```