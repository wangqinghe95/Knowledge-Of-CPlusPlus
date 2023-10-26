# 完美转发

## 定义
+ 完美转发指的是函数模板可以将自己的参数“完美”的转发给内部调用的其他函数中。
+ 所谓的完美，指的是不仅能准确的转发参数的值，还能保证被转发的参数的左、右值属性不变

## 解决的问题
+ 在 C++ 中如果想要将一个函数的参数转发给另一个函数时，需要保留原始参数的左右值属性。

## 完美转发的动机
+ 以下方的函数模板举例
```
template<typename T>
void function(T t){
    otherdef(t);
}
```
+ 在函数模板的 function() 中调用了 otherdef() 函数，在此基础上的完美转发指的是
    - 如果 function() 函数接收到的参数是左值，那么该函数传递给 otherdef() 的参数 t 也应该是左值
    - 反之，function() 函数接收到的参数是右值，那么该传递给 otherdef() 的参数 t 也应该是右值
+ 但是 function() 函数并不能做到完美转发，
    - 因为无论传入进来的 t 是左值还是右值，因为实参是非引用类型的，参数在传递过程中，会有一次额外的拷贝动作，也就意味着传入进来的 t 永远是左值，因为它是一个变量，在内存中有自己的存储地址
+ 如果将 t 的类型设置为 T& 类型，那么 function() 函数无法接收一个常量，即 function(5) 这种调用方式

### 函数模板重载方式实现完美转发

+ 利用函数重载，使用  const 接受右值

```
#include<iostream>

using namespace std;

void otherDef(int &t)
{
    cout << "left value" << endl;
}

void otherDef(const int &t)
{
    cout << "right value" << endl;
}

template<typename T>
void function(const T& t)
{
    otherDef(t);
}

template<typename T>
void function(T& t)
{
    otherDef(t);
}

int main()
{
    function(5);

    int x = 1;
    function(x);

    return 0;
}
```

+ 这种方法会有以下几种问题：
    - 仅适合模板函数仅有少量参数的情况，否则就需要大量的重载函数模板，造成大量的代码冗余
    - 接受的右值只能读，不能修改，使用场景受限

## 完美转发的实现
+ 完美转发的实现可以由万能引用加上引用折叠以及 std::forward 三者共同作用完成

### 万能引用
+ 定义
    + C++ 标准中规定，右值引用形式的参数只能接收右值，不能接受左值。
    + 但是对于函数模板中使用右值引用语法定义的参数来说，它既可以接受左值，又可以接受右值，此时这个右值引用被称为万能引用

+ 代码
    + C++ 11 标准中，实现完美转发代码如下
    + 上面的模板代码的参数 t 既可以接受左值，也可以接受右值。

```
// version_1
template<typename T>
void function(T&& t)
{
    otherDef(t);
}
```


### 引用折叠
#### 引入原因
    
```
int n = 10;
int &num = n;
function(num);  // 1

int &&num2 = 10;
function(num2);     // 2
```

+ 1 处的函数调用底层变成了 function(int &&t)
+ 2 处的函数调用底层变成了 function(int && &&t)
+ C++ 11 之前版本是不支持这种用法的

#### 解决方法
+ C++ 11 为了更好的实现完美转发，特意为其指定了新的类型匹配规则，又称折叠规则
    + 当实参为左值或者左值引用（A&）时，函数模板中的 T&& 将转变为 A&，即 A& && = A&
    + 当实参为右值或者右值引用（A&&）时，函数模板中的 T&& 将转变为 A&&，即 A&& && = A&&
+ 即在实现完美转发时，只要函数模板的参数类型为 T&&，那么 C++ 就可以自行的推断出实际传入的实参是左值还是右值

### std::forward
#### 引入原因
+ 转发的函数模板 function() 已经解决了如何识别函数传入实参是左值还有右值类型的问题。
+ 但是对于函数内部，因为接收外部实参的函数参数在内存空间中有了地址，即 T&& t 这个 t 在 function 这个函数中始终是一个左值
+ 那么如何将 function() 接受的实参的类型与数值一同传递给内部要调用的函数呢？也就是 std::forward() 的作用

#### 使用
+ 只要在模板函数中，调用 std::forward() 函数，就可以将传入参数的属性和数值一同传递到内部的调用函数中
+ 最终版的完美转发代码示例如下
```
#include<iostream>

using namespace std;

void otherDef(int &t)
{
    cout << "left value" << endl;
}

void otherDef(const int &t)
{
    cout << "right value" << endl;
}

template<typename T>
void function(T&& t)
{
    otherDef(std::forward<T>(t));
}

int main()
{
    function(5);

    int x = 1;
    function(x);

    return 0;
}
```

## 应用场景
1. 转发函数参数
2. 实现可变参数模板
3. 通用库代码中处理各种类型的参数