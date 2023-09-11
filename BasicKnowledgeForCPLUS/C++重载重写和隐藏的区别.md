# C++ 重载、重写和隐藏的区别

+ 重载和重写的区别：
    - 重写是父类和子类之间的同名函数之间关系，重载是同一个函数中同名函数之间的关系；
    - 重写要求参数列表相同，重载则要求参数列表不同，返回值不做要求；
    - 重写关系中，调用方法根据对象类型决定，重载根据调用时实参列表与形参列表的对应关系来选择函数体

+ 隐藏指的是在某种情况下，派生类中的函数屏蔽了基类的同名函数，包括以下情况：
    - 两个函数参数相同，但是基类函数不是虚函数，和重写的区别在于基类函数是否是虚函数。
    - 两个函数参数不同，无论基类函数是不是虚函数，都会被隐藏。和重载的区别是在于不在两个类中；

```
#include<iostream>
using namespace std;

class A{
    public:
        virtual void func(int a){
            cout << "A:: virtual " << a << endl;
        }
        void func2(int a){
            cout << "A:: no virtual " << a << endl;
        }
};

class B : public A{
    public:
        void func(int a){
            cout << "B:: override " << a << endl;
        }
        void func2(int a){
            cout << "B:: no override " << a << endl;
        }       
};  

int main(){
    A a;
    a.func(10);
    a.func2(20);

    B b;
    b.func(30);
    b.func2(40);

    A* c = &b;
    c->func(50);
    c->func2(60);

    A* e = nullptr;
    B* d = dynamic_cast<B*>(&a);
    if (nullptr == d){
        cout << "dynamic_cast is nullptr" << endl;
    }
    else
    {
        d->func(70);
        d->func2(80);
    }

    return 0;    
}

```

+ 当派生类重载基类的函数，但是基类的函数没有加上virtual时，基类指针指向派生类对象时，调用的函数是基类的；如果加上了 virtual 修饰符，该基类指针调用的函数是派生类的
+ 隐藏的作用：如果父类函数没有加上 virtual 修饰，但是子类有一个同名函数，那么派生类的对象调用该函数名调用的是派生类的函数