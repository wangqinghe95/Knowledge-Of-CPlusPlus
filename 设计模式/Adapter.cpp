/**
 * 适配器模式：将一个类的接口转换成另一个类的接口
 *          主要是解决一个类因为一些原因无法直接使用的问题
*/

#include<iostream>
#include<string>
using namespace std;

class Target
{
public:
    virtual void request(){
        cout << "Target::Request" << endl;
    }
};

class Adaptee
{
public:
    void specificRequest(){
        cout << "Adaptee::Request" << endl;
    }
};

class Adapter : public Target, Adaptee
{
public:
    void request(){
        Adaptee::specificRequest();
    }
};

int main()
{
    Target* pTarget = new Adapter();
    pTarget->request();

    delete pTarget;
    pTarget = NULL;
    return 0;
}