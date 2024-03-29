# STL
# Content
[迭代器](./Iterator.md)
[列表](./List.md)

## 概述
+ STL：Standard Template Library，标准模板库，包含了诸多常用的基本数据结构和基本算法。
+ STL 主要是由容器，迭代器，算法，函数对象，内存分配器五部分构成

## 组件
1. 容器：用来管理某类对象集合
    + 各种数据结构，vector、list、deque、set、map
    + 从实现角度上来看，STL 容器时一种 class template
2. 算法：用来处理对象集合中的元素
    + 常用的算法，如 sort、find、copy、for_each
    + 从实现的角度上来看，STL 时一种 function template
3. 迭代器：用来在一个对象集合的元素上机型遍历动作，扮演容器和算法之间的胶合剂
    + 从实现角度上看，迭代器是一种将 operator*、operator->、operator++、operator-- 等指针相关操作给予重载的 class template
    + 所有的 STL 容器都附带自己专属的迭代器，只有容器的设计者才知道如何遍历自己的元素。原生指针也是一种迭代器
4. 仿函数：行为类似函数，可作为算法的某种策略
    + 从实现角度上来看，仿函数是一种重载了 operator() 的 class 或 class template
5. 适配器：
    + 一种用来修饰容器或者仿函数或者迭代器接口的东西
6. 空间配置器，负责空间的配置和管理。
    + 从实现的角度来看，配置器是一个实现了动态空间设置、空间管理、空间释放的 class template

## 介绍
1. STL 的基本观念就是将数据和操作分离，数据由容器进行管理，操作则由算法进行，而迭代器在两者之间充当粘合剂，使任何算法都可以和任何容器交互运作。
    + 通过迭代器的协助，我们只需要撰写一次算法，就可以将它应用于任何容器之上，这是因为所有的迭代器都提供了一致的接口
    + STL 六大组件的交互关系，容器通过空间配置器取得数据存储空间，算法通过迭代器存储容器中的内容，仿函数可以协助算法完成不同的策略的变化，适配器和修饰仿函数

