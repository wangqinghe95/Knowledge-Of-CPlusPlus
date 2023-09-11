# C++ 中类的数据成员和成员函数在内存中分布情况
    C++ 类是由结构体发展而来，所以他们的成员变量在内存分配机制上是一样的。

    一个类对象的地址就是类所包含的这一片内存空间的首地址，这个首地址就对应具体的某一个成员变量的地址。（在定义类的同时这些成员变量也就被定义了）

    ```
        #include<iostream>
        using namespace std;

        class Person{
            public:
                Person(){
                    this->age = 23;
                }
                void printAge(){
                    cout << this->age << endl;
                }
                ~Person(){}
            
            public:
                int age;
        };

        int main(){
            Person p;
            cout << "对象地址 ：" << &p << endl;  
            cout << "age地址 ：" << &(p.age) << endl;  
            cout << "对象大小 ：" << sizeof(p) << endl;  
            cout << "对象地址 ：" << sizeof(p.age)<< endl; 
            return 0; 
        }
    ```

    运行结果：
        对象地址 ：0x7ffe1e749fe4
        age地址 ：0x7ffe1e749fe4
        对象大小 ：4
        对象地址 ：4

    结论：
        + 成员函数不占用对象的内存，因为成员函数是存储在代码区的；静态成员函数也是如此
        + 对象大小等同于对象中数据成员大小