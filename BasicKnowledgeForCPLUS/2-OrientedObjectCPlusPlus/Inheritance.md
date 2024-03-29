# C++ 继承

## 继承概念
+ 继承是面向对象的程序设计中最重要的概念。继承允许依据一个类来定义另一个类。
+ 继承使得程序的创建和维护变得容易，并且实现了代码重用的功能，提高了执行效率。

## 继承格式
```
class <class-name> : <inheritance-method:public/protected/private> <base-class-name>
```

+ 派生类可以访问基类的所有非私有成员。因此基类成员如果不想被派生类的成员函数访问的话，可以将基类成员声明为 private
+ 派生类可以继承基类的所有方法，但不包括以下函数：
    1. 基类的构造函数，析构函数，和拷贝构造函数
    2. 基类的重载运算符
    3. 基类的友元函数

## 继承类型
+ 当一个类派生自基类，该类的访问修饰符有三种类型， public、protected、private。
    1. 公有继承：基类的公有成员也是派生类的公有成员，基类的保护成员是派生类的保护成员，基类的私有成员不能被派生类继承。
    2. 保护继承：基类的公有成员和保护成员都会被基类继承为保护成员
    3. 私有成员：基类的公有成员和保护成员都会被基类即成为私有成员

## 多继承
+ C++ 中一个子类可以继承多个父类，即多继承。

### 多继承格式
```
class <class-name> : <inheritance-method-1> <base-name-1>,<inheritance-method-2> <base-name-2>,...
{
    <class-body>
}
```