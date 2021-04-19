# C++ 中 new 类型
C++ 中，new 有三种典型用法， plain new，nothrow new 和 placement new

+ plain new：普通的 new，也就是我们常用的 new,在空间分配失败时抛出异常 std::bad_alloc 而不是返回 NULL。
```
    void* operator(std::size_t) throw(std::bad_alloc);
    void operator delete(void* ) throw();
```

+ nothrow new：在空间分配失败情况下，不抛出异常而是返回 NULL
```
void *opeartor new(std::size_t, const std::nothrow_t&) throw();
void operator delete(void*) throw();
```

+ example
```
#include<iostream>
#include<string>
using namespace std;

int main(){
    char*p = new(nothrow) char[10e11];
    if (NULL == p){
        cout << "alloc failed" << endl;
    }

    delete p;
    return 0;
}
```

+ placement new:允许在一块已经分配成功的内存上重新构造对象或对象数组。placement new 不用担心内存分配失败，因为它部分配内存，它做的唯一一件事就是调用对象的构造函数。
```
void *opeartor new(size_t, void*);
void operator delete(void*, void*);
```
    - placement new 的主要用途时反复使用一块较大的动态分配的内存来构造不同的对象或者他们的数组；
    - placement new 构造起来的对象数组，要显示的调用他们的析沟函数来销毁（析沟函数并不释放内存），不能使用 delete，这是因为 placement new 构造起来的对象或数组大小并不一定等于原来分配的内存大小，使用 delete 会造成内存泄漏或者之后释放内存时运行的错误；

+ example:
```
#include<iostream>
#include<string>

using namespace std;

class ADT{
    int i;
    int j;
public:
    ADT(){
        i = 10;
        j = 100;
        cout << "ADT construct i = " << i << " j = " << j << endl;
    }
    ~ADT(){
        cout << "ADT destruct" << endl;
    }
};

int main(){
    char *p = new(nothrow) char[sizeof(ADT) + 1];
    if (NULL == p){
        cout << "alloc failed" << endl;
    }

    ADT* q = new(p) ADT;
    q->ADT::~ADT();    //显示的调用析沟函数
    delete[] p;
    return 0;
}
```
