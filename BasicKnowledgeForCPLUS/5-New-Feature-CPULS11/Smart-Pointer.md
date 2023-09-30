# 智能指针
+ 智能指针主要用于管理在堆上分配的内存，它将普通的指针封装为一个栈对象。当栈对象的生存周期结束后，会在析构函数中释放掉申请的内存，从而防止内存泄露。
+ C++ 标准库提供以下智能指针类型
    1. unique_ptr：用于管理独占所有权的资源，它在确保不再需要时自动释放资源，并且不能共享所有权
    2. shared_ptr：用于管理共享所有权的资源，它可以跟踪有多少个指针共享同一个资源，并在不需要时自动释放资源
    3. weak_ptr：用于解决 shared_ptr 循环引用问题。它允许创建一个不增加引用计数的指针，便于观察 shared_ptr 指向的资源

## unique_ptr
1. 实现
    + 通过禁止拷贝构造函数来实现独占资源所有权，仅支持移动构造函数。
        + 无拷贝构造函数，不支持普通的拷贝和赋值操作
        + 可进行移动构造和移动赋值操作
    + 可以从一个函数中返回一个 unique_ptr
2. 使用
```
std::unique_ptr<int> uptr(new int(10)); //绑定动态对象
//std::unique_ptr<int> uptr2 = uptr  // 不能赋值
//std::unique_ptr<int> uptr3(uptr)  //不能拷贝
std::unique_ptr<int> uptr4 = std::move(uptr)    // 更换所有权
uptr4.release();    // 释放所有权
```

## shared_ptr
1. 实现
    + shared_ptr 内部使用引用计数，每一个 shared_ptr 的拷贝都指向相同的内存。每使用他一次，内部的引用计数加 1，每析构一次，内部的引用计数减 1，减到 0 为止，自动删除所指向的堆内存。shared_ptr 内部的引用计数是县城安全的，但是对象的读取需要加锁
2. 初始化
    + 智能指针是一个模板类，可以指定类型，传入指针通过构造函数初始化。也可以使用 make_shared 函数初始化。不能将指针直接赋值给一个智能指针。
3. 拷贝和赋值
    + 拷贝使得对象的引用计数加 1，赋值使得原对象引用计数加 1，当计数为 0 时，自动释放内存，后来指向的对象引用计数加 1，指向后来的对象，
4. 获取原始指针
    + get 获取原始指针
5. 注意
    1. 不要使用一个原始指针初始化多个 shared_ptr，否则会造成二次释放同一内存
    2. 注意避免循环引用
6. 使用
```
int main()
{
    int a = 10;
    shared_ptr<int> ptr_a = std::make_shared<int>(a);
    shared_ptr<int> ptr_a1(ptr_a);

    cout << "shared_ptr ptra count : " << ptr_a.use_count() << endl;

    int b = 20;
    int *pb = &a;
    // shared_ptr<int> ptr_b = pb;  // The former is class, and the latter is pointer
    shared_ptr<int> ptr_b1 = make_shared<int>(b);
    ptr_a1 = ptr_b1;    // deassign for ptr_a1
    pb = ptr_b1.get();

    cout << "shared_ptr ptra count : " << ptr_a.use_count() << endl;
    cout << "shared_ptr ptr_b1 count : " << ptr_b1.use_count() << endl;

    return 0;
}
```

## weak_ptr
1. 概述 
    + weak_ptr 是一种解决 shared_ptr 相互引用时产生的死锁问题的智能指针。
        - 如果有两个 shared_ptr 互相引用，那么这两个 shared_ptr 指针的引用计数永远不会为 0，资源也就永远不会被释放
    + weak_ptr 是对对象的一种弱引用，它不会增加对象的 use_count。
2. 介绍
    + weak_ptr 指针通常不单独使用，只能和 shared_ptr 类型指针搭配使用。
        - 将一个 weak_ptr 绑定到一个 shared_ptr 不会改变 shared_ptr 的引用计数；
        - 一旦最后一个指向对象的 shared_ptr 被销毁，对象就会被释放。即使有 weak_ptr 指向对象，对象也还是被释放
    + weak_ptr 没有重载 operator-> 和 operator* 操作符，所以不可以直接通过 weak_ptr 使用对象
        - 调用 lock 函数来获取 shared_ptr 实例，进而访问原始对象

3. 使用
```
int main()
{
    shared_ptr<int> sh_ptr = make_shared<int>(10);
    cout << "sh_ptr.use_count() : " << sh_ptr.use_count() << endl;

    weak_ptr<int> wp(sh_ptr);
    cout << "First wp.use_count() : " << wp.use_count() << endl;

    if(!wp.expired()){
        shared_ptr<int> sh_ptr2 = wp.lock();
        *sh_ptr2 = 100;
        cout << "Second wp.use_count() : " << wp.use_count() << endl;
    }
    
    return 0;

}
```

## 代码
1. shared_ptr 循环引用
```
#include<iostream>
#include<memory>
#include<string>

using namespace std;

class B;
class A
{
public:
    shared_ptr<B> m_pB;
    ~A(){
        cout << "Delete A" << endl;
    }
};

class B
{
public:
    shared_ptr<A> m_pA;
    ~B(){
        cout << "Delete B" << endl;
    }
};

void func()
{
    // pb has one reference
    shared_ptr<B> pb(new B());
    cout << "pb.use_count : " << pb.use_count() << endl;

    // pa has one reference
    shared_ptr<A> pa(new A());
    cout << "pa.use_count : " << pa.use_count() << endl;

    // pa has two references
    pb->m_pA = pa;
    cout << "pb.use_count : " << pb.use_count() << endl;
    cout << "pa.use_count : " << pa.use_count() << endl;

    // pb has two references
    pa->m_pB = pb;
    cout << "pb.use_count : " << pb.use_count() << endl;
    cout << "pa.use_count : " << pa.use_count() << endl;    

    return ;

    // circular reference and don't call destructor function
}

int main()
{
    func();
    return 0;
}
```
2. weak_ptr 解决 shared_ptr 循环引用的问题
+ 将 `shared_ptr<B> m_pB;` 修改为 `weak_ptr<B> m_pB;`

3. shared_ptr 和 weak_ptr 实现
```
#include<iostream>

using namespace std;

class Counter
{
public:
    Counter() : s(0),w(0) {};
public:
    int s;  // the number of reference for shared_ptr
    int w;  // the number of reference fro weak_ptr
};

template <class T>
class WeakPtr;

template <class T>
class SharePtr
{
public:
    SharePtr(T* p = 0) : m_ptr(p)
    {
        m_pCounter = new Counter();
        if(p) {
            m_pCounter->s = 1;
        }
        cout << "In construct " << m_pCounter->s << endl;
    }
    ~SharePtr()
    {
        release();
    }

    SharePtr(SharePtr<T> const &s)
    {
        cout << "In copy con" << endl;
        m_ptr = s.m_ptr;
        (s.m_pCounter)->s++;
        cout << "Copy construct" << (s.m_pCounter)->s << endl;
        m_pCounter = s.m_pCounter;
    }

    // it need copy construct in order to use the function of lock of weak_ptr
    SharePtr(WeakPtr<T> const& w)
    {
        cout << "In w copy con " << endl;
        m_ptr = w.m_ptr;
        (w.m_pCounter)->s++;
        cout << "copy w construct " << (w.m_pCounter)->s << endl;
        m_pCounter = w.m_pCounter;
    }

    SharePtr<T> &operator=(SharePtr<T> &s)
    {
        if( this != &s ) {
            release();
            (s.m_pCounter)->s++;
            cout << "Assign construct " << (s.m_pCounter)->s << endl;
            m_pCounter = s.m_pCounter;
            m_ptr = s.m_ptr;
        }
        return *this;
    }

    T &operator*()
    {
        return *m_ptr;
    }

    T *operator->()
    {
        return m_ptr;
    }

    // it's useful for weak_ptr and shared_ptr to set reference's counts
    friend class WeakPtr<T>;

protected:
    void release()
    {
        m_pCounter->s--;
        cout << "release " << m_pCounter->s << endl;
        if(m_pCounter->s < 1) {
            delete m_ptr;
            if(m_pCounter->w < 1) {
                delete m_pCounter;
                m_pCounter = nullptr;
            }
        }
    }

private:
    T* m_ptr;
    Counter* m_pCounter;
};

template <class T>
class WeakPtr
{
public:
    WeakPtr()
    {
        m_pCounter = 0;
        m_ptr = 0;
    }
    WeakPtr(SharePtr<T>& s) : m_ptr(s.m_ptr), m_pCounter(s.m_pCounter)
    {
        cout << "w construct from s" << endl;
        m_pCounter->w++;
    }

    WeakPtr(WeakPtr<T>& w) : m_ptr(w.m_ptr), m_pCounter(w.m_pCounter)
    {
        m_pCounter->w++;
    }

    ~WeakPtr()
    {
        release();
    }

    WeakPtr<T> &operator=(WeakPtr<T> &w)
    {
        if( this != &w ) {
            release();
            m_pCounter = w.m_pCounter;
            m_pCounter->w++;
            m_ptr = w.m_ptr;
        }
        return *this;
    }

    WeakPtr<T> &operator=(SharePtr<T> &s)
    {
        cout << "w = s" << endl;
        release();
        m_pCounter = s.m_pCounter;
        m_pCounter->w++;
        m_ptr = s.m_ptr;
        return *this;
    }

    SharePtr<T> lock()
    {
        return SharePtr<T>(*this);
    }

    bool expired()
    {
        if(m_pCounter){
            if(m_pCounter->s > 0){
                cout << "empty " << m_pCounter->s << endl;
                return false;
            }
        }

        return true;
    }

    friend class SharePtr<T>;

protected:
    void release()
    {
        if(m_pCounter) {
            m_pCounter->w--;
            cout << "weakptr release " << m_pCounter->w << endl;
            if(m_pCounter->w < 1 && m_pCounter->s < 1) {
                m_pCounter = nullptr;
            }
        }
    }

private:
    T* m_ptr;
    Counter* m_pCounter;
    
};

class B;
class A
{
public:
    SharePtr<B> m_ptrB; // circular reference
    // WeakPtr<B> m_ptrB;
    ~A()
    {
        cout << "Destory A" << endl;
    }
};

class B
{
public:
    SharePtr<A> m_ptrA; // circular reference
    // WeakPtr<A> m_ptrA;
    ~B()
    {
        cout << "Destory B" << endl;
    }   
};

int main()
{
    SharePtr<A> a(new A);
    SharePtr<B> b(new B);
    a->m_ptrB = b;
    b->m_ptrA = a;
    return 0;
}
```

## 参考
[一文读懂智能指针](https://zhuanlan.zhihu.com/p/150555165)
