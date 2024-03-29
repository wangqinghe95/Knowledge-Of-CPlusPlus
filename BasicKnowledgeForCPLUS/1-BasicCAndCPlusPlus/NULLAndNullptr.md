# C++ 中 NULL 和 nullptr 的区别

## 区别
1. NULL 是一个宏定义，通常被定义为 0 或者 (void*)0
2. C++ 中，(void*)类型是不允许隐式转换成其他类型的，因此在重载整型的情况下，会出现二义性
3. C++ 引入 nullptr 作为空指针常量的，nullptr 是一个编译器常量，可以用于类型推导，解决一些歧义问题。
4. 在 C++ 中， NULL 被定义为整数 0， nullptr 被定义为空指针

## NULL
### 定义
+ NULL 是一个宏定义， 在 C++ 中，NULL 被定义为整数 0

### 源码
```
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void*)0)
#endif
```

## nullptr
### 引入原因：
+ 在传入参数 NULL 时，C++ 会把 NULL 当作整数 0 来处理，如果想要调用参数是指针的函数时，就会产生二异性，为了区分指针0和整型0的区别，C++引入了 nullptr

### 定义
+ nullptr 可以明确的区分整型和指针类型，能够根据环境自动转换成相应的指针类型，但不会转换成任何整形，所以不会造成参数传递错误；

### 源码
```
const class nullptr_t{
    pubilc:
        template<class T> inline operator T*() const{
            return 0;
        }
        template<class C, class T>inline opeartor T C::*（） const{
            return 0;
        }
    private:
        void operator&() const;
}nullptr = {};
```

+ 介绍
- 通过模板类和运算符重载的方式来对不同类型的指针进行实例化从而解决(void*) 指针带来的参数类型不明的问题，另外由于明确确定了 nullptr 是指针类型，所以它不会与整形变量相混淆。
### 问题
+ 但 nullptr 还是存在问题:
    - 当对不同指针类型进行函数重载时，传入 nullptr 仍然无法区分应实际调用哪个函数；
+ 代码
```
#include<iostream>
using namespace std;

void fun(char* p){
    cout << "char* p" << endl;
}

void fun(int* p){
    cout << "int* p" << endl;
}

void fun(int p){
    cout << "int p" << endl;
}

int main(){
    // fun((char*)nullptr); //char* p
    // fun(nullptr);        //error
    // fun(NULL);           //error
    return 0;
}        
```