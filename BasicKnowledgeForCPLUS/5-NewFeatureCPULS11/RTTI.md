# RTTI
+ Run Time Type Identification: 运行阶段类型识别，旨在为程序运行阶段确定对象的类型提供一种标准方式。
+ RTTI 只适用于包含虚函数的类，因为对于这种类层次的结构，才应该将派生类的地址赋值给基类指针。

## 动机
+ 由于面向对象程序设计中多态的要求，C++ 的指针和引用的类型，可能与它实际代表的类型不一致。所以就需要产生了类型识别的需求。而 RTTI 的机制就是 C++ 用来实现类型识别这个需求的。

## RTTI 工作原理
+ C++ 有三个支持 RTTI 机制的元素：typeid，dynamic_cast，type_info
    + typeid 返回指针和引用所指的实际类型；
    + dynamic_cast 将基类类型的指针或引用安全的转换成派生类的指针和引用
    + type_info 结构存储了有关特定类型的信息

## dynamic_cast 运算符

## typeid

## type_info
