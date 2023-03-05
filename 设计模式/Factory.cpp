/**
 * 工厂模式
 * 
*/
#include<iostream>
using namespace std;

class AbstractFruit{
public:
    virtual void showName() = 0;
};

class Apple : public AbstractFruit {
public:
    virtual void showName() {
        cout << "This is the class of Apple" << endl;
    }
};

class Banana : public AbstractFruit {
public:
    virtual void showName() {
        cout << "This is the class of Banana" << endl;
    }
};

class Pear : public AbstractFruit {
public:
    virtual void showName() {
        cout << "This is the class of Pear" << endl;
    }
};

class AbstractFactory{
public:
    virtual AbstractFruit* createFruit() = 0;
};

class AppleFactory : public AbstractFactory {
public:
    virtual AbstractFruit* createFruit(){
        return new Apple;
    }
};

class BananaFactory : public AbstractFactory {
public:
    virtual AbstractFruit* createFruit(){
        return new Banana;
    }
};

class PearFactory : public AbstractFactory {
public:
    virtual AbstractFruit* createFruit(){
        return new Pear;
    }
};

int main()
{
    AbstractFactory* CPFactory = nullptr;
    AbstractFruit* CPFruit = nullptr;

    CPFactory = new AppleFactory();
    CPFruit = CPFactory->createFruit();
    CPFruit->showName();

    CPFactory = new BananaFactory();
    CPFruit = CPFactory->createFruit();
    CPFruit->showName(); 

    CPFactory = new PearFactory();
    CPFruit = CPFactory->createFruit();
    CPFruit->showName();  

    return 0;
}
