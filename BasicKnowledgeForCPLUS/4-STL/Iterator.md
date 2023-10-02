# Iterator
## 概述
1. Iterator 是 STL 容器类中的一种内嵌类，每种容器有自己的专属迭代器，负责对本容器内部数据的访问。
2. Itertor 是为了统一不同容器的访问方式，并且通过迭代器可以将容器和算法结合在一起，只要给予算法不同的迭代器，就可以对不同的容器执行相同的操作

## 源码
```
 class list_iterator
    {
    private:
        node<T>* ptr;
    public:
        list_iterator(node<T>* p = nullptr) : ptr(p){}
        T& operator*() const{
            return ptr->value;
        }
        node<T> *operator->() const {
            return ptr;
        }

        list_iterator &operator++(){
            ptr = ptr->next;
            return *this;
        }

        list_iterator operator++(int) {
            node<T>* tmp = ptr;
            ++(*this);
            return list_iterator(tmp);
        }

        bool operator==(const list_iterator& t) const{
            return t.ptr == this->ptr;
        }

        bool operator!=(const list_iterator &t) const {
            return t.ptr != this->ptr;
        }
    };
```

## 迭代器失效的问题
1. Code
```
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    std::vector<int> vec_myvertor(3,100);
    std::vector<int>::iterator iter;

    iter = vec_myvertor.begin();
    iter = vec_myvertor.end();

    vec_myvertor.insert(iter, 200);
    vec_myvertor.insert(iter, 5, 5500); // crash there

    for(std::vector<int>::iterator it = vec_myvertor.begin(); it != vec_myvertor.end(); ++iter) {
        cout << ' ' << *it;
    }
    cout << endl;
    return 0;
}
```

2. 分析
+ vec_myvertor.insert(iter, 200); // 申请一块新的内存存放原有的数据和插入的数据
+ vec_myvertor.insert(iter, 5, 5500);  // iter 指向一块已失效的数据，所以发生崩溃

## 迭代器自增
### 迭代器 ++iter 和 iter++ 哪个好，为什么
+ 前+ 前置返回一个引用，后置返回一个对象；
+ 前置不会产生临时对象，后置必须产生临时对象，临时对象会导致效率降低；

```
//++iter 代码实现
int& operator++(){
    * this += 1;
    return *this;
}

//iter++ 代码实现
int opertor++(int){
    int temp = *this;
    ++*this;
    return temp;
}
```