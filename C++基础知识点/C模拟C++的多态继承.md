# C 语言模拟 C++ 的多态和继承
```
#include<iostream>
using namespace std;

struct A{
    virtual void func(){    //C++ 多态：通过虚函数实现
        cout << "A::func()" << endl;
    }
    int a;
};

struct B : public A{    //C++中继承：B类公继承A类
    void fun(){         //C++ 多台，通过虚函数实现，子类的关键字 virtual 可加可不加
        cout << "B:fun()" << endl;
    }
    int b;
};


//C模拟C++继承和多态
typedef void (*FUN)();

struct _A{      //父类
    FUN _fun;   //C语言中结构体里不能包含函数，只能使用函数指针在外面实现
    int _a;
};

struct _B{      //子类
    _A _a_;     //在子类中定义一个基类的对象即可实现对父类的继承
    int _b;
};

void _fA(){     //父类的同名函数
    printf("_A:_fun()\n");
}

void _fB(){     //子类的同名函数
    printf("_B:_fun()\n");
}

void test(){

    //测试C++的继承和多态
    A a;    //定义一个父类对象 a
    B b;    //定义一个子类对象 b
    A* p1 = &a;     //定义一个父类指针指向父类的对象
    p1->func();     //调用父类的同名函数

    p1 = &b;        //让父类指针指向子类的对象
    p1->func();     //调用子类的同名函数

    //C 语言模拟继承和多态的测试
    _A _a;          //定义一个父类对象
    _B _b;          //定义一个一个子类对象
    _a._fun = _fA;  //父类的对象调用父类的同名函数
    _b._a_._fun = _fB;  //子类对象调用子类的同名函数

    _A* p2 = &_a;       //定义一个父类指针指向父类对象
    p2->_fun();         //调用父类的同名函数
    p2 = (_A*)&_b;      //让父类指针指向子类的对象，由于类型不匹配所以需要强制转换
    p2->_fun();         //调用子类的同名函数
}

int main(){
    test();
}
```