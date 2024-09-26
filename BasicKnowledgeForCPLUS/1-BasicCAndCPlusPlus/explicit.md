# explicit 关键字

## 介绍
用于修饰类中只有一个参数的类构造函数，以防止隐式类型转换和构造。
通常当一个类有一个参数构造函数时，C++编译器允许隐式类型转换来调用该构造函数。使用该关键字可以避免这种情况，确保构造函数被显示调用。

## 代码
```
#include <iostream>

class MyNumber
{
public:
    explicit MyNumber(int num) : number(num) {
        std::cout << __func__ << " constructor called" << std::endl;
    }
    void print() const{
        std::cout << __func__ << " Number: " << number << std::endl;
    }
private:
    int number;
};


class MyNumber_implicit
{
public:
    MyNumber_implicit(int num) : number(num) {
        std::cout << __func__ << "constructor called" << std::endl;
    }
    void print() const{
        std::cout << "Number: " << number << std::endl;
    }
private:
    int number;
};

void printNumber(const MyNumber& num){
    num.print();
}

void printNumber_1(const MyNumber_implicit& num){
    num.print();
}

int main()
{
    // explicit calls the constructor
    MyNumber num1(41);
    num1.print();

    std::cout << "-------------------" << std::endl;

    printNumber(MyNumber(42));

    std::cout << "-------------------" << std::endl;

    // implicit to call the constructor
    // printNumber(42);     // error
    printNumber_1(43);

    return 0;
}
```

## 运行结果
```
MyNumber constructor called
print Number: 41
-------------------
MyNumber constructor called
print Number: 42
-------------------
MyNumber_implicitconstructor called
Number: 43
```

## 分析

从上述代码可以看到，printNumber() 系列函数参数，可以隐式的调用对应结构体的构造函数。如果使用 explicit 修饰了 ，那么隐式调用就会因为报错无法通过编译。
一般用来修饰只有一个函数参数的构造函数。但是实际上该关键字的作用是阻止编译器使用隐式转换调用它。不限制任何类型的构造函数。