# 内存对齐

## 概念
1. 在 C 语言中，结构体的内存对其是指为了提高内存读取效率，编译器会在结构体中插入一些空白字节，使得结构体中的每个成员都位于某个特定的内存地址上。
    + 这个特定的内存地址通常是成员变量所占用的字节的整数倍。
    + 当 CPU 从内存中读取结构体中的成员变量时，只需要一次读取操作即可

## 规则
1. 结构体变量的起始地址必须是其最宽基本类型成员大小的倍数
2. 结构体每个成员相对于结构体起始地址的偏移量必须是其类型大小的整数倍
3. 结构体的总大小必须是其最宽类型成员大小的倍数

## 示例
```
#include <stdio.h>

struct MyStruct1 {
    char a;
    int b;
    short c;
};

struct MyStruct2 {
    short a;
    char b;
    int c;
};

struct MyStruct3 {
    double a;
    int b;
    char c;
};

int main() {
    printf("Size of MyStruct1: %lu bytes\n", sizeof(struct MyStruct1)); // 12
    printf("Size of MyStruct2: %lu bytes\n", sizeof(struct MyStruct2)); // 8
    printf("Size of MyStruct3: %lu bytes\n", sizeof(struct MyStruct3)); // 16

    return 0;
}

```

## 如何获取结构体成员相对于结构体开头的字节偏移量？
+ 取结构体成员变量的地址相减即可
`(unsigned long)(&([type].[member2])) - (unsigned long)(&([type].[member1]))`