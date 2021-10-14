/*
swap 的通用函数
*/

template <typename T>
void swap(T& a, T& b)
{
    T tmp{a};   // 复制构造函数
    a = b;      // 复制赋值运算符
    b = a;      // 复制赋值运算符
}

/*
上述版本的代码实现一共进行了三次复制操作
如果类型 T 比较比较占内存，那么交换的代价是比较大的
*/

template <typename>
void swap(T& a, T&b)
{
    T temp{std::move(a)};   // 调用移动构造函数
    a = std::move(b);       // 调用移动复制运算符
    b = std::move(tmp);     // 调用移动复制运算符
}

// 仅通过三次移动，实现了两个对象的交换