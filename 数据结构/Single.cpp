/*
单例模式：允许创建一个并且只允许创建一个实例的类；
    特点：只提供唯一一个实例，具有全局变量的特点，并且在任何位置都可以通过接口获取到那个唯一实例
    运用场景：
        1. 设备管理器：系统中可能有多个设备，但只有一个设备管理器，用于管理设备驱动；
        2. 数据池：用来缓存数据的数据结构，需要在一处写，多处读取或者多处写，多处读取；
*/

//懒汉式：懒汉式的方法是直到使用的时才初始化实例化对象
//也就是说直到调用 get_instance() 方法才 new 一个单例对象
// 好处是不被调用就不会被占用内存；

#include<iostream>
using namespace std;

class Singleton
{
private:
    /* data */
    Singleton(/* args */){
        cout << "Constructor called" << endl;
    }
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton* m_instance_ptr;
public:
    ~Singleton(){
        cout << "destructor called" << endl;
    }

    static Singleton* get_instance(){
        if (m_instance_ptr == nullptr){
            m_instance_ptr = new Singleton;
        }
        return m_instance_ptr;
    }
    void use() const{
        cout << "in use" << endl;
    }
};

Singleton* Singleton::m_instance_ptr = nullptr;


int main(){
    Singleton* instance = Singleton::get_instance();
    Singleton* instance_2 = Singleton::get_instance();
    return 0;
}

/*
结果：获取两次实例，但是只有一次类的构造函数被调用，表明只有一个实例生成
问题：
    1. 线程安全问题：当多个线程获取单例时可能会引发竞争状态；
    2. 内存泄漏问题：类中只负责 new 出对象，却没有析构删除对象
*/

/*
针对以上版本的两个问题，采用加锁和智能指针的方式改进
*/

#include<iostream>
#include<mutex>
#include<memory>
using namespace std;

class Singleton
{

public:
    typedef shared_ptr<Singleton> Ptr;
    ~Singleton(){
        cout << "destructor called" << endl;
    }
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&) = delete;

    static Ptr get_instance(){
        if (m_instance_ptr == nullptr){        
            lock_guard<mutex> lk(m_mutex);
            if (m_instance_ptr == nullptr){
                m_instance_ptr = shared_ptr<Singleton>(new Singleton);
            }
        }
        return m_instance_ptr;
    }

private:
    /* data */
    Singleton(/* args */){
        cout << "Constructor called" << endl;
    }

    static Ptr m_instance_ptr;
    static mutex m_mutex;
};

Singleton::Ptr Singleton::m_instance_ptr = nullptr;
mutex Singleton::m_mutex;

int main(){
    Singleton::Ptr instance = Singleton::get_instance();
    Singleton::Ptr instance_2 = Singleton::get_instance();
    return 0;
}

/*
结果：只构造了一次实例，并且发生了析构；
优点：
    1. 使用了智能指针，当 shared_ptr 被析构时，new 出来的对象也会被 delete 掉，以此避免发生内存泄漏
    2. 加锁：使用了互斥量达到了线程安全；使用了两个 if 判断句，也被称为双检锁；好处是只有当指针为空时才加锁，避免每次调用这个方法都加锁，毕竟加锁消耗的资源还是蛮大的；
缺点：
    1. 使用智能指针也会要求用户也得使用智能指针，非必要不应提出这种要求；
    2. 使用锁也就意味着资源消耗增大，并且代码量也会增大，结构会变得更复杂；
*/

// 基于 Magic Static 方法达到安全：静态布局变量

#include<iostream>
using namespace std;

class Singleton
{

public:
    ~Singleton(){
        cout << "destructor called" << endl;
    }
    Singleton(Singleton&)=delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton& get_instance(){
        static Singleton instance;
        return instance;
    }
private:
    Singleton(){
        cout << "Constructor called" << endl;
    }
};

int main(){
    Singleton& instance_1 = Singleton::get_instance();
    Singleton& instance_2 = Singleton::get_instance();
    return 0;
}

//Magic Static：当变量在初始化时，并发同时进入声明语句，并发线程将阻塞等待线程结束
// 这样保证了并发线程在获取静态局部变量时一定是初始化过的，所以具有线程安全性；

/*
1. 通过局部静态变量保证了线程安全；
2. 不需要使用共享指针，代码简洁；
3. 注意在使用的时候需要声明单例的引用 Single& 才能获取对象；
*/