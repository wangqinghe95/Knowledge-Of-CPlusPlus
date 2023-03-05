/*
* 代理模式
*/

#include<iostream>
using namespace std;

class Subject {
public:
    virtual void func(){
        cout << "Subject" << endl;
    }
};

class RealSubject : public Subject{
public:
    virtual void func(){
        cout << "RealSubject" << endl;
    }
};

class Proxy : public Subject{
public:
    virtual void func()
    {
        cout << "Proxy" << endl;
        m_real.func();
    }
private:
    RealSubject m_real;
};

int main()
{
    Proxy CProxy;
    CProxy.func();
    return 0;
}

