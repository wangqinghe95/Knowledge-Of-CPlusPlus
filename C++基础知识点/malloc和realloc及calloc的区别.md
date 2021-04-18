# malloc、realloc、calloc 之间的区别

## malloc 函数是从堆上获得指定字节的内存空间
    + 声明： void *malloc(int n);

## calloc 函数作用同malloc，区别是参数不同，申请空间大小为 n*size
    + 声明：void* calloc(int n, int size);

## realloc 函数重新分配指定指针大小的内存空间，如果 n 小于等于 p 原有的内存大小，则保持当前状态不变，如果 n 大于 p 之前所指向的空间大小，那么系统将重新为 p 从堆上分配一块大小为 n 的内存，同时将原来指向空间的内容依次复制到新的内存空间中，并且释放掉 p 之前指向的内容
    + 声明： void *realloc(void *p, int n);

[](https://blog.csdn.net/qq_38810767/article/details/85265541)