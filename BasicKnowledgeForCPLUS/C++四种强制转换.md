# C++ 四种强制转换

## reinterpret_cast：用于类型之间进行强制转换
+ reinterpret_cast<type_id>(expression)：type-id必须是一个指针、引用、算术类型、函数指针或成员指针。它可以用于类型之间的强制转换。

## const_cast：用来修改类型的 const 和 volatile 属性。
+ const_cast<type_id>(expression)：该运算符用来修改类型的 const 或 volatile 修饰之外，type_id 和 expression 的类型是一样的。
    - 常量指针被转换成非常量指针，仍然指向原来的指针
    - 常量引用被转换成非常量引用，仍然指向原来的对象
    - const_cast 一般用于修改底自指针，如 const char *p;

## static_cast：
+ const_cast<type_id>(expression)：该运算符将 expression 转换成 type-id 类型，但是没有运行时类型检查来保证转换的安全性。
+ 用于类层次结构中基类和派生类之间指针或引用的转换；
    + 进行上行转换（把派生类指针或引用转换成基类）是安全的；
    + 进行下行转换（把基类指针或引用转换成派生类表示）时，由于没有动态类型检查，所以是不安全的；
+ 用于基本数据类型开发的转换（int=》char、int=》enum），这种安全性也是需要开发人员保证
+ 把空指针转换成目标类型的空指针
+ 把任何类型的表达式转换成 void 类型

    **注意：static_cast 不能转换掉 expression 的const、volatile、或者 _unaligned 属性**

## dynamic_cast：有类型检查，基类向派生类转换比较安全，但派生类转基类不太安全；
+ dynamic_cast<type-id>(expression)：该运算符把 expression 转换成 type-id 类型的对象
    - type-id 必须是类的指针、类的引用或者 void*；
    - 如果 type-id 是类指针类型，那么 expression 也必须是一个指针，如果 type-id 是一个引用，那么 expression 也必须是引用；
+ dynamic_cast 运算符了可以在执行期决定真正的类型，也就是说 expression 必须是多态类型，如果下行转换是安全的（基类指针或者引用指向一个派生类对象），这个运算符会传回适当转型过的指针；如果下行转换不安全，这个运算符会传给空指针（基类指针或者引用没有指向一个派生类对象）；
+ dynamic_cast 主要是用于类层次间上行和下行转换，还可以用于类之间的交叉转换
+ 在类层次间进行上下行转换时，dynamic_cast 和 static_cast 效果是一样的；
+ 在进行下行转换时， dynamic_cast 既有类型检查，比 static_cast 更安全；

**EXAMPLE**
```
#include<bits/stdc++.h>
using namespace std;

class Base{
    public:
        Base():b(1){}
        virtual void fun(){};
        int b;
};

 class Son : public Base{
     public:
        Son() : d(2){}
        int d;
 };

int main(){
    int n = 97;

    int *p = &n;

    //reinterpret_cast
    char *c = reinterpret_cast<char*> (p);
    char *c2 = (char*)(p);  //效果同上
    cout << "reinterpret_cast 输出" << *c2 << endl;

    //const_cast
    const int* p2 = &n;
    int *p3 = const_cast<int*>(p2);
    *p3 = 100;
    cout << "const_cast 输出： " << *p3 << endl;

    Base *b1 = new Son;
    Base *b2 = new Base;

    //static_cast
    Son* s1 = static_cast<Son*>(b1);    //同类型转换
    Son* s2 = static_cast<Son*>(b2);    //下行转换：基类=》派生类
    cout << "static_cast ： " << endl;
    cout << s1->d << endl;
    cout << s2->d << endl;  //下行转换，原先父对象没有d成员，输出垃圾值

    //dynamic_cast
    Son* s3 = dynamic_cast<Son*>(b1);   //同类型转换
    Son* s4 = dynamic_cast<Son*>(b2);   //下行转换，安全
    cout << "dynamic_cast : " << endl;
    cout << s3->d << endl;
    if (nullptr == s4){
        cout << "s4 指针为 nullptr" << endl;
    }
    else{
        cout << s4->d << endl;
    }

    return 0;
}
```

运行结果：
reinterpret_cast 输出a
const_cast 输出： 100
static_cast ： 
2
0
dynamic_cast : 
2
s4 指针为 nullptr
    