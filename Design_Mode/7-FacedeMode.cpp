/**
 * 外观模式：为子系统的一组接口提供一个一致的界面，此模式定义了一个高层接口
*/

#include<iostream>
using namespace std;
class SubSystem1
{
public:
    void method1(){
        cout << "method1" << endl;
    }
};

class SubSystem2
{
public:
    void method2(){
        cout << "method2" << endl;
    }
};

class SubSystem3
{
public:
    void method3(){
        cout << "method3" << endl;
    }
};

class Facade
{
public:
    Facade(){
        m_pSys1 = new SubSystem1();
        m_pSys2 = new SubSystem2();
        m_pSys3 = new SubSystem3();
    }
    void Method1(){
        m_pSys1->method1();
        m_pSys2->method2();
    }
    void Method2(){
        m_pSys2->method2();
        m_pSys3->method3();
    }
private:
    SubSystem1* m_pSys1;
    SubSystem2* m_pSys2;
    SubSystem3* m_pSys3;
};

int main(){
    Facade* face = new Facade();
    face->Method1();
    face->Method2();
    return 0;
}


