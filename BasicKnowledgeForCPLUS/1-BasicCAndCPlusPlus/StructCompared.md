# 如何判断两个结构体是否相等

## 比较两个结构体的方法
1. 如果两个结构体的所有成员都是基本数据类型
    + 可以直接使用 memcmp() 进行比较
2. 如果两个结构体成员包含指针成员
    + 需要逐一比较指针所指向的内容是否相等
3. 如果两个结构体包含数组类型
    + 逐个比较数组元素是否相等
4. 如果两个结构体成员包含自定义类型
    + 自定义比较函数，逐个比较函数需要逐个比较结构体成员是否相等

## 实现
1. 重写比较操作符
2. 对结构体变量一一比较
3. 对结构体指针进行比较

### 代码
```
#include<iostream>
using namespace std;

struct A{
    char ch;
    int val;
    friend bool operator==(const A &ob1, const A &ob2);
    bool operator==(const A &rhs);
};

bool operator==(const A &ob1, const A &ob2){
    return (ob1.ch == ob2.ch && ob1.val == ob2.val);
}
bool A::operator==(const A &rhs){
    return (ch == rhs.ch && val == rhs.val);
}

int main(){
    struct A s3,s4;
    A  s, s1;
    A s2;
    s1.ch = 1;
    s1.val = 2;
    s2.ch = 1;
    s2.val = 2;
    if (s1 == s2){
        cout << "s1 is equal with s2" << endl;
    }
    else{
        cout << "s1 is not equal with s2" << endl;
    }
    return 0;
}
```



