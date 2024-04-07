# 交换两个数

1. 算术法
```
void swap_arithmetic(int &x, int &y)
{
	x = x + y;
    y = x - y;
    x = x - y;
}
```

2. 异或
```
void swap_exclusive_or(int &x, int &y)
{
	x = x ^ y;
    y = x ^ y;
    x = x ^ y;	
}
```

3. 模板
```
// C++ 03 使用临时变量
template <typename T>
void swap_C++03(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
} 
// C++ 11 使用 std::swap
template <typename T>
void swap_C++11(T& a, T& b) noexcept
{
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}
```