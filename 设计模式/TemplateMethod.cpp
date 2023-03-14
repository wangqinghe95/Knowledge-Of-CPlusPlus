/**
 * 模板方法模式：将通用算法封装到抽象基类中，并将不同的算法细节放到子类中。
*/
#include<iostream>
#include<cstdio>
using namespace std;

class AbstractClass
{
public:
    ~AbstractClass(){}
    void templateMethod(){
        this->primitiveOperation1();
        this->primitiveOperation2();
    }
    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;
protected:
    AbstractClass(){}
};

class ConcreteClassA : public AbstractClass
{
private:
    /* data */
public:
    ConcreteClassA(/* args */){}
    ~ConcreteClassA(){}
    virtual void primitiveOperation1(){
        cout << "ConcreteClassA " << __func__ << endl;
    }
    virtual void primitiveOperation2(){
        cout << "ConcreteClassA " << __func__ << endl;
    }

};

class ConcreteClassB : public AbstractClass
{
private:
    /* data */
public:
    ConcreteClassB(/* args */){}
    ~ConcreteClassB(){}
    virtual void primitiveOperation1(){
        cout << "ConcreteClassB " << __func__ << endl;
    }
    virtual void primitiveOperation2(){
        cout << "ConcreteClassB " << __func__ << endl;
    }
    
};

int main(){
    AbstractClass *pAbstract = new ConcreteClassA();
    pAbstract->templateMethod();

    pAbstract = new ConcreteClassB();
    pAbstract->templateMethod();

    return 0;
}