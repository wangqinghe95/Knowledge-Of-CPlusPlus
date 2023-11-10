# 线程
## 定义
+ 线程是操作系统能够进行运算调度的最小单位。它被包含在进程中，是进程中的实际运作单位。
+ 一个线程指的是进程中一个单一顺序的控制流，一个进程可以并发多个线程，每条线程并行执行不同的任务。

## 线程操作
### 线程基本操作
+ pthread_self()：获取线程ID；
+ pthread_create()：线程创建；
+ pthread_exit()：线程退出
+ pthread_join()：等待线程结束
+ pthread_detach()：线程分离
+ pthread_cancel()：线程取消


### 线程互斥操作
#### 互斥锁
+ 介绍：
    - 访问共享资源前用互斥量对资源进行加锁，访问结束后释放。
    - 其他试图再次对资源上锁的线程都会被阻塞，直到当前线程释放该锁。
    - 当释放互斥量时有一个以上的线程阻塞，那么所有该锁上的阻塞线程都会变成可运行状态，第一个变为可运行状态的线程可以对资源加锁，其他线程则会变成重新阻塞状态继续等待资源变成可用状态。
+ 函数
    1. pthread_mutex_t: 互斥锁声明
    2. pthread_mutex_init：互斥锁初始化
    3. pthread_mutex_destroy：互斥锁销毁
    4. pthread_mutex_lock：互斥锁加锁
    5. pthread_mutex_unlock：互斥锁解锁

#### 读写锁
+ 介绍
    + 加载写状态的锁时，其他的线程的请求都会被阻塞；加载读状态锁时，写状态下的锁会被阻塞。
+ 函数
    1. pthread_rwlock_t: 读写锁声明
    2. pthread_rwlock_init：读写锁初始化
    3. pthread_rwlock_destroy：读写锁销毁
    4. pthread_rwlock_rdlock：读写锁加读锁
    5. pthread_rwlock_wrlock：读写锁写读锁
    5. pthread_rwlock_unlock：读写锁解锁

### 信号量
+ 介绍
    - 实际上是一个非负的整数计数器，用来实现对公共资源的控制，当公共资源增加时，信号量就增加；反之则减少。
+ 函数
    + sem_t sem：信号量声明
    + sem_init：信号量初始化
    + sem_destroy：信号量销毁
    + sem_post：信号量解锁
    + sem_wait：信号量枷锁

### 条件变量
+ 介绍
    - 一般同互斥锁同时使用，互斥锁用于上锁，条件变量用于等待，运行线程以无竞争的方式等待特定的条件产生。
+ 函数
    + pthread_cond_t：条件变量声明
    + pthread_cond_init：条件变量初始化
    + pthread_cond_destroy：条件变量销毁
    + pthread_cond_wait：阻塞等待一个条件变量
    + pthread_cond_signal：唤醒至少一个阻塞在条件变量上的线程
    + pthread_cond_broadcast：条件变量唤醒全部阻塞在条件变量上的线程

## 多线程使用代码样例
+ [条件变量+互斥锁实现一个线程池](https://www.cnblogs.com/wanghao-boke/p/11443241.html)
