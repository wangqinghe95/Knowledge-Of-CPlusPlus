/*
简单工厂模式：由一个工厂类根据传入的参数，动态的决定应该创建哪一个产品类实例。
举个实例：想要写一个计算器的功能，计算器包含加减乘除四种运算规则
最简单版本：由界面输出两个数字，和一个运算符，然后后台直接将这两个数和运算符计算出来返回到前台显示
缺点是一旦需要增加运算规则，就需要重新改写后台程序和编译旧有的已经通过测试的代码。本来的目的是增加一个新的功能，却使得原本运行良好的代码发生了变化。
升级版代码：虚拟抽象出一个运算类，然后加减乘除写成该类的子类，这样就相当于将各个运算的代码和功能给隔离开，当需要增加一个新的功能，只需要增加新的子类的实现，这样添加的逻辑就清楚了很多。
升级版代码子类的实例化其实就是简单工厂模式的过程。
简单工厂模式中包含了三个角色：
    + 抽象产品角色是所创建的所有对象的父类，负责描述所有实例所共有的公共接口；
    + 工厂角色是抽象产品角色的继承，负责实现所创建的对象的实例的内部逻辑；
    + 具体产品角色是创建目标，所有创建的对象当充当这个角色某个具体类的实例；
简单工厂模式要点在于：
    当你需要什么对象，只需要传入对应的参数。
优点：
    实现对象的创建和对象的使用分离，将对象的创建交给专门的工厂负责。
缺点：
    工厂类不够灵活，增添新的具体产品需要修改工厂类的判断逻辑代码，而且当产品比较多时，工厂方法代码将会非常复杂。
使用情况：
    工厂类负责创建的对象比较少，使用者只知道传入工厂类的参数，而无需关心创建对象。
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>

// 抽象产品角色
class Operation
{
private:
    double A,B;
public:
    Operation(/* args */):A(0),B(0){}
    ~Operation(){}

    double getNumberA(){
        return A;
    }
    double getNumberB(){
        return B;
    }

    void setNumberA(double x){
        A = x;
    }
    void setNumberB(double x){
        B = x;
    }

    double virtual getResult(){
        return 0;
    }
};

// 具体产品角色
class OperationAdd : public Operation{
public:
    double getResult(){
        return getNumberA() + getNumberB();
    }
};

class OperationSub : public Operation
{
public:
    double getResult(){
        return getNumberA() - getNumberB();
    }
};

class OperationMul : public Operation
{
public:
    double getResult(){
        return getNumberA() * getNumberB();
    }
};

class OperationDiv : public Operation
{
public:
    double getResult(){
        if(getNumberB() != 0) {
            return getNumberA()/getNumberB();
        }
        else{
            return 0;
        }
    }
};

// 工厂角色
class SimplyFactory
{
public:
    static Operation* createOperation(char ch){
        Operation* p;
        switch (ch)
        {
        case '+':
            p = new OperationAdd();
            break;
        case '-':
            p = new OperationSub();
            break;
        case '*':
            p = new OperationMul();
            break;
        case '/':
            p = new OperationDiv();
            break;
        
        default:
            break;
        }
        return p;
    }
};

void test(int x, int y, char ch){
    Operation* COpera = SimplyFactory::createOperation(ch);
    COpera->setNumberA(x);
    COpera->setNumberB(y);
    std::cout << "x " << ch << " y : ";
    std::cout << COpera->getResult() << std::endl;
}

int main()
{
    double x = 10;
    double y = 5;
    
    test(x,y,'+');
    test(x,y,'-');
    test(x,y,'*');
    test(x,y,'/');

    return 0;
}

