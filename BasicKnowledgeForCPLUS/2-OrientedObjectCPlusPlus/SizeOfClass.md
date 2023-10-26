# 类大小计算

## 代码
```
#include<iostream>

using namespace std;

class Base
{
public:
    Base()=default;
    ~Base()=default;
private:
    static int a;
    int b;
    char c;
};

class Base1
{
public:
    Base1()=default;
    ~Base1()=default;
private:
    static int a;
    double c;
    int b;
};

class NoMember
{

};

struct DriverFromEmpty : public NoMember
{
    int a;
};

struct HoldAnInt
{
    int x;
    NoMember n;
};

class BaseHoldVirtual
{
public:
    virtual void f() {
        cout << "BaseHoldVirtual::f()" << endl;
    }
    virtual void g() {
        cout << "BaseHoldVirtual::g()" << endl;
    }
    virtual void h() {
        cout << "BaseHoldVirtual::h()" << endl;
    }
public:
    int age;
};

class Derived : public Base
{
public:
    virtual void f() {
        cout << "Derived::f()" << endl;
    }
    virtual void g() {
        cout << "Derived::g()" << endl;
    }
    virtual void h() {
        cout << "Derived::h()" << endl;
    }
public:
    int age;
};

class BaseVirtual
{
public:
    virtual void f() {
        cout << "Derived::f()" << endl;
    }    
};

class BaseVirtual2
{
public:
    virtual void f() {
        cout << "Derived::f()" << endl;
    }    
};

class Derived2 : public BaseVirtual
{
public:
    int age;
};


class Derived1 : public Base
{
public:
    int age;
};

class multiDerivedEmpty : public BaseVirtual2 , public BaseVirtual
{

};

int main(){

    Base b;
    cout << "sizeof(Base) " << sizeof(b) << endl;

    Base1 b1;
    cout << "sizeof(Base1) " << sizeof(b1) << endl;

    NoMember n;
    cout << "sizeof(NoMember) " << sizeof(n) << endl;

    DriverFromEmpty d;
    cout << "sizeof(DriverFromEmpty) " << sizeof(d) << endl;

    HoldAnInt h;
    cout << "sizeof(HoldAnInt) " << sizeof(h) << endl;

    cout << "--------------" << endl;

    BaseHoldVirtual bv;
    cout << "sizeof(BaseHoldVirtual) " << sizeof(bv) << endl;
    cout << "address(BaseHoldVirtual) " << &bv << endl;
    cout << "address(BaseHoldVirtual.age) " << &bv.age << endl;
    
    cout << "--------------" << endl;

    Derived de;
    cout << "sizeof(Derived) " << sizeof(de) << endl;
    cout << "address(Derived) " << &de << endl;
    cout << "address(Derived.age) " << &de.age << endl;

    cout << "--------------" << endl;

    Derived de1;
    cout << "sizeof(Derived1) " << sizeof(de1) << endl;
    cout << "address(Derived1) " << &de1 << endl;
    cout << "address(Derived1.age) " << &de1.age << endl;

    cout << "--------------" << endl;

    Derived2 de2;
    cout << "sizeof(Derived2) " << sizeof(de2) << endl;
    cout << "address(Derived2) " << &de2 << endl;
    cout << "address(Derived2.age) " << &de2.age << endl;

    
    cout << "--------------" << endl;

    multiDerivedEmpty e1;
    cout << "sizeof(multiDerivedEmpty) " << sizeof(e1) << endl;
    cout << "address(multiDerivedEmpty) " << &e1 << endl;
    // cout << "address(multiDerivedEmpty.age) " << &e1.age << endl;
    return 0; 
}
```