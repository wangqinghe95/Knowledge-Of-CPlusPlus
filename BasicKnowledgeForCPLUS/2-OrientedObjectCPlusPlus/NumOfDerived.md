# 计算一个类的子类个数

+ 使用反射机制计算子类个数
+ 代码
```
#include <iostream>
#include <typeinfo>
#include <vector>

class Base {
public:
    virtual ~Base() {}
};

class Derived1 : public Base {};
class Derived2 : public Base {};
class Derived3 : public Derived1 {};

int main() {
    std::vector<Base*> objects;
    objects.push_back(new Derived1());
    objects.push_back(new Derived2());
    objects.push_back(new Derived3());

    std::string base_name = typeid(Base).name();
    int count = 0;

    for (auto obj : objects) {
        std::string derived_name = typeid(*obj).name();
        if (derived_name != base_name) {
            count++;
        }
    }

    std::cout << "Number of subclasses: " << count << std::endl;

    return 0;
}

```