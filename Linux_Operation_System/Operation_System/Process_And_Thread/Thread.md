# 线程
## 定义
+ 线程是操作系统能够进行运算调度的最小单位。它被包含在进程中，是进程中的实际运作单位。
+ 一个线程指的是进程中一个单一顺序的控制流，一个进程可以并发多个线程，每条线程并行执行不同的任务。

## 线程操作
### 线程基本操作
1. 线程创建操作
    + pthread_create()
    + 创建线程
2. 线程获取自身线程 ID 操作
    + pthread_self()
    + 获取自身线程 id
3. 线程退出操作
    + pthread_exit()
    + 当前线程退出
4. 线程同步操作
    + pthread_join()
    + 阻塞等待指定线程退出，并获取线程获取状态。一般用于线程同步操作
5. 线程分离操作
    + pthread_detach()
    + 设置指定线程为分离状态，即指定线程执行完成后，系统将自动释放该线程占有的资源。主要用于线程异步操作
6. 线程取消操作
    + pthread_cancel()
    + 取消指定线程运行

### 线程互斥操作
#### 互斥锁
1. 声明
    + pthread_mutex_t
2. 初始化
    + pthread_mutex_init
3. 销毁
    + pthread_mutex_destroy
4. 加锁
    + pthread_mutex_lock
5. 解锁
    + pthread_mutex_unlock

#### 读写锁
1. 声明
    + pthread_rwlock_t
2. 初始化
    + pthread_rwlock_init
3. 销毁
    + pthread_rwlock_destroy
4. 以读的方式请求读写锁
    + pthread_rwlock_rdlock
5. 以写的方式请求读写锁
    + pthread_rwlock_wrlock
6. 解锁
    + pthread_rwlock_unlock

### 信号量
1. 声明
    + sem_t sem
2. 初始化
    + sem_init
3. 销毁
    + sem_destroy
4. 解锁
    + sem_post
5. 加锁
    + sem_wait

### 条件变量（配合互斥锁使用，作用于多线程）
1. 声明
    + pthread_cond_t cond
2. 初始化
    + pthread_cond_init
3. 销毁
    + pthread_cond_destroy
4. 阻塞等待一个条件变量
    + pthread_cond_wait
5. 唤醒至少一个阻塞在条件变量上的线程
    + pthread_cond_signal
6. 唤醒全部阻塞在条件变量上的线程
    + pthread_cond_broadcast
