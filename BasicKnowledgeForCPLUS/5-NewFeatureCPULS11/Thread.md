# C++ Thread

## [基础操作](https://www.cnblogs.com/wanghao-boke/p/17741263.html)
1. 线程创建
    + `thread thread(<function_name>);`
2. 线程取消
    + `this_thread::yield();`
3. 线程同步
    + `thread.join()`
4. 线程分离
    + `thread.detach();`
5. 线程休眠
    + `this_thread::sleep_for(chrono::seconds(3));`
6. 获取线程id
    + `thread::id thread_id = this_thread::get_id();`

## [线程互斥操作](https://www.cnblogs.com/wanghao-boke/p/17742043.html)
### Mutex
1. 头文件
    + `#include<mutex>`
2. 类型
    + std::mutex
        - 最基础的 Mutex 类
    + std::recursive_mutex
        - 递归的 Mutex 类
    + std::time_mutex
        - 定时 Mutex
    + std::recursive_time_mutex
        - 定时递归 Mutex 类
3. 操作
    + 加锁
        - lock
    + 解锁
        - unlock
    + 查看是否上锁
        - trylock
        - 未上锁，返回 false，并锁住
        - 其他线程已上锁，返回 true
        - 同一线程已经上锁，将会产生死锁

### lock_guard
+ 会在实例化时去获取一个 mutex 的所有权，在作用域消失时，会自动析构并释放 mutex
+ 创建即加锁，作用域结束自动析构并解锁，无需自动解锁
+ 不能中途解锁，也不支持手动解锁
+ 不能复制

### unique_lock
+ 创建时可以不锁定，在需要的再锁定
+ 可以手动的，随时加锁解锁
+ 作用域结束后，析构函数自动释放锁
+ 不可复制，可移动
+ 条件变量需要该类型的锁作为参数（此时必须使用 unique_lock）

### 总结：
1. 当多个线程同时访问同一个资源时，为了保证数据的一致性，需要一个锁机制来提供数据保护，也就是 C++ mutex
2. 为了防止使用者使用 mutex 加锁后忘记释放，提供了 lock_guard
3. 为了更方便的对共享资源加锁和解锁，提供了 lock_guard 的升级版 unique_lock

## [条件变量](https://www.cnblogs.com/wanghao-boke/p/17742482.html)
### 介绍
+ 条件变量是利用线程间共享的全局变量进行同步的一种机制
+ 条件变量是为了控制多线程**有顺序**地访问共享资源，它和互斥量协同控制多线程**有序，互斥**地访问共享资源。

### variable_condition
+ 该类是专门结合 unique_lock 使用

### variable_condition_any
+ 该类可以搭配任意的一个线程锁使用

### 函数操作
1. wait
    + 等待通知
2. wait_for
    + 等待到收到通知或者超时
3. notify_one
    + 通知一个等待的线程
4. notify_all
    + 通知所有的线程

### 总结
+ 条件变量和互斥锁一起使用主要是用来解决是生产者和消费者的问题，其中使用的步骤如下
1. 定义互斥锁和条件变量
```
std::condition_variable cv
std::mutex mtx;
```
2. 等待条件满足
```
std::unique_lock<std::mutex> lck(mtx);
cv.wait(lck, []{ return condition;});
// wait 函数可以接受一个函数，该函数返回 true 表示条件已经满足
// 如果条件不满足，wait() 会释放锁并将线程挂起，直至条件满足
```
3. 通知条件满足
```
cv.notify_one();    // 唤醒一个等待的线程
cv.notify_all();    // 唤醒所有等待的线程
```

