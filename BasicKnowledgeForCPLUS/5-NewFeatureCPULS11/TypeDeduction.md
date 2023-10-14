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

## auto 与 decltype 搭配使用

## auto 与 decltype 在函数模板中的使用
+ 一般用于函数返回值类型问题上

# auto、decltype、和 decltype(auto) 的用法
+ auto： C++ 新标准引入 auto 说明符，用它就能让编译器替我们去分析表达式所属类型。auto 让编译器通过初始值进行类型推演，从而获得定义变量的类型，auto 必须要有初始值
+ decltype：选择并返回操作数的数据类型，在此过程中，编译器只是分析表达式并得到它的类型，并不去计算实际的表达式的值。
+ decltype(auto):C++14 新增的类型指示符，可以用来生命变量以及指示函数返回类型。在使用时会将"="号左边的表达式替换调 auto，再根据 decltype 的语法规则来确定类型；