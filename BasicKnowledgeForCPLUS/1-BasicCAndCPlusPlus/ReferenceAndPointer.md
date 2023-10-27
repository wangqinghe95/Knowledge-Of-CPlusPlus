# 指针和引用的区别

## 概念
1. 指针是一个变量，存储了另一个变量的内存地址。指针需要 * 运算符进行解引用，以访问它指向的内存地址
2. 引用是一个别名，即已经存在的变量的另一个名称。

## 联系
1. 引用和指针类似，通过存储对象的地址来实现
2. 引用可以被视为具有自动间接性的常量指针，他们都用于使一个变量访问另一个变量

## 区别
1. 初始化
+ 指针的初始化
```
int a = 10;
int *p = &10;
```
+ 引用的初始化
```
int a = 10;
int &p = a;
```

2. 重新赋值
+ 指针可以被重新赋值
+ 引用不能被重新赋值，并且引用需要再初始化时就要赋值

3. 内存地址
+ 指针在堆栈上有自己的内存地址和大小
+ 引用与原始变量共享相同的内存地址，并且在堆栈上占用一些空间

4. NULL 值
+ 指针可以赋值为 NULL， 而引用不能

5. 间接性
+ 指针可以有多级指针
+ 引用只能有一级

## 汇编层次看引用
### 汇编代码
```
// reference.cpp
#include<iostream>

void swap(int*a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap(int& a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    return 0;
}

```

### 汇编代码分析
+ 生成汇编代码
```
g++ reference.cpp -o reference -g
gdb reference
b swap
r
info address [function]
dissassemble [address]
```

+ `void swap(int*a ,int *b)` 汇编部分代码
```
(gdb) info  address swap
Symbol "swap(int*, int*)" is a function at address 0x400726.
(gdb) disassemble 
No frame selected.
(gdb) disassemble 0x400726.
Dump of assembler code for function swap(int*, int*):
   0x0000000000400726 <+0>:     push   %rbp
   0x0000000000400727 <+1>:     mov    %rsp,%rbp
   0x000000000040072a <+4>:     mov    %rdi,-0x18(%rbp)     # 将第一个参数存放到 %rbp-0x18 的地址中
   0x000000000040072e <+8>:     mov    %rsi,-0x20(%rbp)     # 将第二个参数存放到 %rbp-0x20 的地址中
   0x0000000000400732 <+12>:    mov    -0x18(%rbp),%rax     # %rbp-0x18 地址中的数据(第一个数参数)保存到 %rax 中
   0x0000000000400736 <+16>:    mov    (%rax),%eax          # 将 %rax 中的值所指向的地址的内容复制到 %eax中，即 *a
   0x0000000000400738 <+18>:    mov    %eax,-0x4(%rbp)      # 将将 %eax 值存放到 -0x4(%rbp) 处，即 temp = *a
   0x000000000040073b <+21>:    mov    -0x20(%rbp),%rax     # %rbp-0x20 地址中的数据(第二个数参数)保存到 %rax 中
   0x000000000040073f <+25>:    mov    (%rax),%edx          # 将 %rax 中的值所指向的地址的内容复制到 %edx中，即 *b
   0x0000000000400741 <+27>:    mov    -0x18(%rbp),%rax     # 取第一个参数值（即a）
   0x0000000000400745 <+31>:    mov    %edx,(%rax)          # 取 *a
   0x0000000000400747 <+33>:    mov    -0x20(%rbp),%rax     # *a = *b
   0x000000000040074b <+37>:    mov    -0x4(%rbp),%edx      # temp 值放入到 %edx 寄存器中
   0x000000000040074e <+40>:    mov    %edx,(%rax)          # *b = temp
   0x0000000000400750 <+42>:    nop
   0x0000000000400751 <+43>:    pop    %rbp                 # 弹出返回地址
   0x0000000000400752 <+44>:    retq                        # 返回

(gdb) info address swap(int&,int&)
Symbol "swap(int&, int&)" is a function at address 0x400753.
(gdb) disassemble 0x400753.
(gdb) disassemble 0x400753.
Dump of assembler code for function swap(int&, int&):
   0x0000000000400753 <+0>:     push   %rbp                 # 返回地址入栈
   0x0000000000400754 <+1>:     mov    %rsp,%rbp            # 保存父函数帧地址
   0x0000000000400757 <+4>:     mov    %rdi,-0x18(%rbp)     # 第一个参数入栈，即 &a
   0x000000000040075b <+8>:     mov    %rsi,-0x20(%rbp)     # 第二个参数入栈, 即 &b
   0x000000000040075f <+12>:    mov    -0x18(%rbp),%rax     # 取 a 地址，即 &a
   0x0000000000400763 <+16>:    mov    (%rax),%eax          # 取 a
   0x0000000000400765 <+18>:    mov    %eax,-0x4(%rbp)      # temp = a
   0x0000000000400768 <+21>:    mov    -0x20(%rbp),%rax     # 取 b 地址
   0x000000000040076c <+25>:    mov    (%rax),%edx          # 取 b
   0x000000000040076e <+27>:    mov    -0x18(%rbp),%rax     # 取 a 地址，即 &a
   0x0000000000400772 <+31>:    mov    %edx,(%rax)          # a = b,将 b 的值放到 %rax 指向的地址中
   0x0000000000400774 <+33>:    mov    -0x20(%rbp),%rax     # 取 b
   0x0000000000400778 <+37>:    mov    -0x4(%rbp),%edx      # 取 temp
   0x000000000040077b <+40>:    mov    %edx,(%rax)          # b = temp，将 temp 直接放入 &b 的地址中
   0x000000000040077d <+42>:    nop
   0x000000000040077e <+43>:    pop    %rbp
   0x000000000040077f <+44>:    retq 
```

### 总结
1. 引用只是 C++ 的语法糖，可以看作是编译器自动完成取地址，解引用的常量指针
2. 引用区别与指针的特性，或者用法，都是在编译器约束下完成的，一旦编译成汇编，就和指针一样
3. 引用由编译器保证初始化，使用起来比较方便。
4. 引用没有顶层 const，即 `int& const`, 但是有底层 const，`const int&`
    + 这是因为引用本身就是不可变，所以加顶层无意义
    + 底层引用表示所引用的对象本身是常量
5. 有指针引用，它是引用类型，绑定到指针，但是没有引用指针
    + 指针的存在意义就是间接的改变对象的值，使用引用本身的值就是所引用对象的地址
    + 但是引用不能更改所引用的对象，也就不能有引用指针了
6. 指针和引用的自增自减含义不同
    + 指针是指针运算，移动的是地址的值
    + 引用是指向的地址的值的运算，修改的指向对象的的值

### 引用的风险
+ 由于引用只是对指针的包装，所有也存在风险
```
int* a = new int;
int& b = *a;
delete a;
b = 12;
```