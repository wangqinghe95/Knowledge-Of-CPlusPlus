# 初始化和赋值的区别

## 声明和定义
1. 声明
    + 程序中引入一个变量、函数或者类的名称，告诉编译器这个名称的存在，但是并不分配空间或初始化。
    + 通常出现在头文件中
2. 定义
    + 定义是为一个变量、函数或者类分配内存空间并初始化它们
    + 通常出现在源文件中
3. 区别
    + 如果想要在程序中使用一个函数或者变量，
    + 首先需要在程序中声明这个函数的名称和参数类型或者是变量的类型和名称，以便编译器知道它们的存在
    + 然后再在程序中定义它们，为他们分配内存空间并初始化它们

## 赋值和初始化
1. 赋值
    + 将一个值赋值给另一个，以改变变量的值
    + 赋值是变量在创建，并且分配内存空间以后，将新的值复制到变量的内存空间中
2. 初始化：为数据对象或者变量赋予初始值的过程
    + 发生在编译器编译时期
    + 编译器会为变量分配内存并将其初始化为指定的值，如果没有指定初始值，则编译器会使用默认值进行初始化
3. 区别：
    + 初始化发生在编译器阶段，由编译器复制处理赋值；赋值是发生在程序运行阶段，由CPU执行复制指令
    + 对于普通的内置变量，两者在运行效率上无太大差别，对于自定义类型，即类来说，区别很大

## 代码
```
#include<iostream>
using namespace std;

class Point
{
private:
    /* data */
public:
    Point(int a = 0, int b = 0) : x(a) , y (b){};
    ~Point() {};

    Point& operator=(const Point &rhs);

public:
    int x;
    int y;
};

Point& Point::operator=(const Point &rhs){
    cout << "Override Opeartor= " << endl;
    x = rhs.x + 1;
    y = rhs.y + 1;
    return *this;
}

int main(){
    Point p(1,1);
    Point p1 = p;   //initialize

    cout << "p1.x = " << p1.x << " p1.y = " << p1.y << endl;

    cout << "-------------------------" << endl;

    Point p2;
    p2 = p;     //assignment
    cout << "p2.x = " << p2.x << " p2.y = " << p2.y << endl;

    return 0;
}  
```
+ 初始化时没有调用赋值构造函数