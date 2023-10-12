# 原子操作

## 介绍
+ C++ 11 中的原子操作是一种多线程的同步机制，能够保证多个线程对共享变量的使用方式互斥的，避免竞态条件和死锁等问题
+ 在普通的变量中，多个线程并发访问会可能会导致数据竞争，竞争的后果是操作过程中不会按照正确的顺序进行进行操作
+ 原子变量可以看作是一种特殊的类型，它具有普通变量的操作，但是对原子变量的操作是原子级别的

## 使用
+ C++ 11 提供比较丰富的原子类型，整型，指针，bool等
+ 通过 std::atomic<T> 定一个原子变量，其中 T 表示变量的类型

### 成员函数
1. is_lock_free()
    + 检查当前 atomic 对象是否支持无锁操作
2. store(desired, order)
    + 将给定的值存储到原子对象中
3. load(order)
    + 从原子对象中加载值
4. exchange(desired, order)
    + 用给定的值替换原子对象中的值，并返回远的值
5. compare_exchange_weak(expected, desired, success,failure)、compare_exchange_strong(expected, desired, success,failure)
    + 比较交换函数

### 代码示例
```
#include<iostream>
#include<thread>
#include<atomic>

using namespace std;

atomic<int> counter(0);
// int counter = 0;
const int TEST_NUMBER = 1000000000;

void add_counter_1(int n)
{
    for(int i = 0; i < n; ++i)
    {
        counter++;
    }
}

int main()
{
    thread t1(add_counter_1, TEST_NUMBER);
    thread t2(add_counter_1, TEST_NUMBER);

    t1.join();
    t2.join();

    cout << "counter " << counter << endl;
    return 0;
}
```

+ 如果不对 counter 变量进行加锁，那么可能会出现数据竞争的问题
    - 例如两个线程同时读取变量 counter 的值，然后各自将其加 1，最后将其写回变量 x 中
    - 由于两个线程并发执行，那么最终变量的 x 就可能只加了 1，也不是预期的 2
    - 该问题会是偶发问题，如果在实际项目中出现就很难复现排查