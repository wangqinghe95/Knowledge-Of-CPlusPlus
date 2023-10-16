# 类型推导
+ 类型推导指的是程序中为变量赋予类型时无需显示声明，编译器能够通过代码自动推到变量的类型
## auto
+ 定义
    - 让编译器在编译时期推导出变量类型
+ 基本用法
    - `auto [variation_name] = [expression]`
+ 推导规则
    - 对于指针类型， auto，auto* 没有区别
    - 声明引用类型，必须使用 auto&
+ 使用限制
    - auto 声明必须进行初始化
    - auto 一行存在多个变量声明的话，类型要一致，否则会出现编译失败
    - 在类中 auto 不能用作非静态成员变量
    - auto 无法推断出模板参数
    - 不能得到推导变量的 const，volatile 属性
    - auto 不能用于函数传参
    - auto 不能用于推导数组类型
## decltype
+ 定义
    - 编译器在编译时期进行表达式推导
+ 基本用法

+ 推导规则
    - exp 是表达式，decltype(exp) 与 exp 类型相同
    - exp 是函数调用，decltype(exp) 与 exp 函数返回值类型相同
    - 其他情况，exp 是左值，decltpye(exp) 是 exp 的左值引用


## auto 与 decltype 在函数模板中的使用
### 一般用于函数返回值类型问题上
1. 直接使用 auto 推导返回值类型
```
template<typename T, typename U>
auto add(T t, U u) {
    return u+v
}
```
- 上述代码由于 t 和 u 的类型都不确定，所以无法推导出返回值类型

2. 使用 decltype 指定表达式的返回类型
```
template <typename T, typename U>
auto func(T& t, U& u) -> decltype(t+u){
    return t+u;
}
```


3. 代码示例：
```
#include<iostream>
int& foo(int& i)
{
    std::cout << "i " << i << std::endl;
    return i;
}
float& foo(float& f)
{
    std::cout << "f " << f << std::endl;
    return f;
}

template<typename T>
auto func(T& val) ->decltype(foo(val)){
    return foo(val);
}

template <typename T, typename U>
auto func(T& t, U& u) -> decltype(foo(t) + foo(u)){
    return foo(t) + foo(u);
}

int main()
{
    int i = 10;
    func(i);

    float f = 20.0;
    func(f);

    std::cout << "------" << std::endl;

    std::cout << func(i,f) << std::endl;    // yes, passed

    return 0;
}
```

## Question
```
#include<iostream>

struct square
{
    template<typename T>
    T operator()(T x) const {
        return x*x;
    }
};

struct add
{
    template<typename T>
    T operator()(T x, T y) const {
        return x + y;
    }
};

int squre_func(int x){
    return x*x;
}

int add_func(int x) {
    return x + x;
}


// there no problem of definition
// but the question if how to ues
template <typename F, typename G, typename T>
auto compose(F f, G g, T x) ->decltype(f(g(x))) {
    return f(g(x));
}


int main()
{
    std::cout << square()(3) << std::endl;
    std::cout << add()(2,3) << std::endl;
    int x = 3;
    // std::cout << compose(square(), add(), x)(3) << std::endl;    // can't compile, it may be it need C++ 14
    // std::cout << compose(squre_func, add_func, x)(3) << std::endl; // can't compile

    return 0;
}

```