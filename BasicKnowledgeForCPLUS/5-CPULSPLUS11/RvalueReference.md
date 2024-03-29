# 右值引用

## 右值和左值
+ 在 C++ 11 中可以去地址的、有名字的就是左值，反之，不能取地址的，没有名字的就是右值
### 左值
1. 介绍
    - 左值表示了一个占据内存中某个可识别的位置对象，可以出现在等号两边。能修改，可以长久保持
2. 类型
    - 函数名和变量名
    - 返回左值引用的函数调用
    - 前置自增自减表达式 --i,++i
    - 由赋值表达式或赋值运算符链接的表达式，如 a = b, a += b
    - 解引用表达式 *p

### 右值
1. 右值
    - 右值表示了一个不占据内存的可识别位置的对象，只能出现在等号的右边，且不能被修改，要么是常量，要么是临时变量。右值包括纯右值和将亡值

2. 纯右值
+ 右值一般是运算表达式产生的临时变量、不和对象关联的原始字面量、非引用返回的临时变量、lambda 表达式
    - 除字符串字面值外的字面值
    - 返回非引用类型的函数调用
    - 后置自增自减表达式 i++，i--
    - 算数表达式(a+b , a*b , a&&b , a==b 等)
    - 取地址表达式 (&a)

3. 将亡值
+ 概念
    + C++ 新增的右值引用相关和的表达式，将亡值可以理解为即将销毁的值，通过“盗取”其他变量内存空间方式获取的值，在确保其他变量不再被使用或者即将销毁时，可以避免内存空间的释放和分配，延长变量值得生命周期，常用来完成移动构造或者移动赋值的特殊任务，
+ 类型
    - 要被移动的对象，T&& 函数的返回值
    - std::move 函数的返回值
    - 转换成 T&& 类型转换函数的返回值

## 左值引用和右值引用
### 左值引用
+ 左值引用是对左值进行引用的类型
    + 左值引用就是对变量起一个别名
    + 对于左值引用，等号右边的值必须可以取地址
    + 如果不能去地址，就只能使用 const 引用形式，但是这种方式只能通过读取引用，不能修改数组，因为是常量引用

```
int a = 5;
int &b = a; // b is a left value reference

int &c = 10;    // error, 10 is a const, which can't refer
const int &d = 10;  // correct, this is a const-reference
```

### 右值引用
+ 介绍
    + 右值引用就是对右值进行引用的类型
    + 如果使用右值引用，那表达式等号右边的值需要右值，可以使用 std::move() 函数强制把左值转换成右值
+ 目的
    + 右值引用主要是为了支持移动操作，比如移动构造函数和移动复制函数。而移动函数可以减少拷贝带来的资源浪费

+ 格式
`[type] && [reference_name] = [RValue]`
+ 效果
    - 使用右值引用能够延长将亡值的生存期，并且充分利用临时对象的构造减少对象构造和析构操作以达到提高效率的目的
+ 举例
```
#include<iostream>
using namespace std;

template<typename T>
void fun(T&& t){
    cout << t << endl;
} 

int getInt(){
    return 8;
}

int main(){
    int a = 10;
    int &b = a; //b是左值引用
    //int &c = 10;    //错误， c是左值不能使用右值初始化
    int &&d = 10;   //正确，右值引用用右值初始化
    //int &&e = a;    //错误，e 是右值引用不能使用左值初始化
    const int& f = a;   //正确，左值常引用相当于万能型，可以用左值或者右值初始化
    const int& g = 10;  //正确，左值常引用相当于万能型，可以用左值或者右值初始化
    const int&& h = 10; //正确，右值常引用
    const int& a = h;  //正确；

    //int& i = getInt();  //错误， i 是左值引用，不能使用临时变量来初始化
    int&& j = getInt(); //正确，函数返回值是右值

    fun(10);    //此时fun函数的参数t是右值
    fun(a);     //此时fun函数的参数t是左值

    // example_2
    int &&i = 1;    //i 绑定了右值1，说明初始化时右值引用一定要用一个右值表达式绑定
    int b = 2;
    i = b;      // 绑定之后，可以用左值表达式修改右值引用的所引用临时对象的值；

    // example_3
    int && temp = 0;
    // int && i = temp; // temp 是一个右值引用变量，变量是左值，因此 i 引用 temp 左值是非法的

    // example_4
    int &&temp = 0;
    int && i = 0;
    i = tmep;    // 上述代码是合法的，取出 temp 所引用临时对象的值，在赋值给 i 所引用对象的值；

    return 0;
}
```

## 右值引用和左值引用的区别
+ 绑定的对象不同
    - 右值引用是对不能取地址的值进行绑定，左值相反，只能绑定有地址的值，不能取地址的值只能绑定到常量引用去
+ 持续时间不同
    - 右值只能绑定到临时对象，所引用的对象将要销毁或该对象没有其他用户；而左值引用的变量都是持久性变量
+ 引用的目的不同
    - 右值引用为了支持移动构造，而左值引用是为了给变量起个别名，使用左值引用更安全

## 深拷贝和浅拷贝
+ 深拷贝和浅拷贝指的是和指针相关的拷贝
+ 浅拷贝说的是复制的是指针的值
+ 深拷贝说的是复制的是指针指向的内容的值

## 移动语义
+ 转移内存所有权，可以在不需要拷贝操作的场合执行数据移动，充分利用临时对象的构造来减少对象构造和对象析构操作来达到提高效率的目的。

```
class MyArray
{
public:
    // Constructor
    MyArray(int size):data(new int[size]), size(size){}

    // Copy Constructor
    MyArray(const MyArray& other) : data(new int[other.size]), size(other.size){
        std::copy(other.data, other.data+other.size, data);
    }

    // Move Constructor
    MyArray(MyArray&& other) : data(other.data), size(other.size){
        other.data = nullptr;
        other.size = 0;
    }
    ~MyArray(){
        delete[] data;
    }
private:
    int* data;
    int size;
}；
int main()
{
    MyArray a(10);
    MyArray b(std::move(a));    // 通过 move 函数将对象 a 转成右值引用，然后调用 b 的移动构造函数构造 b，减少了 a 析构和 b 构造过程中带来的资源浪费

    return 0;
}
```