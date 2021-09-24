# C++ 左值引用和右值引用

[左值右值](https://zhuanlan.zhihu.com/p/137662465)

```
#include<iostream>
using namespace std;

template<typename T>
void fun(T&& t){
    cout << t << endl;
} 

int getInt(){
    return 8;
}

int main(){
    int a = 10;
    int &b = a; //b是左值引用
    //int &c = 10;    //错误， c是左值不能使用右值初始化
    int &&d = 10;   //正确，右值引用用右值初始化
    //int &&e = a;    //错误，e 是右值引用不能使用左值初始化
    const int& f = a;   //正确，左值常引用相当于万能型，可以用左值或者右值初始化
    const int& g = 10;  //正确，左值常引用相当于万能型，可以用左值或者右值初始化
    const int&& h = 10; //正确，右值常引用
    const int& a = h;  //正确；

    //int& i = getInt();  //错误， i 是左值引用，不能使用临时变量来初始化
    int&& j = getInt(); //正确，函数返回值是右值

    fun(10);    //此时fun函数的参数t是右值
    fun(a);     //此时fun函数的参数t是左值
    return 0;
}
```