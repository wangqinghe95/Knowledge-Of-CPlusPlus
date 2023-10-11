/**
 * 观察者模式 : 定义对象间的一种一对多的依赖关系，当一个对象的状态发生变化时，所有依赖它的对象都得到通知并且被自动更新
 * 
*/

#include<iostream>
#include<list>
using namespace std;

class Observer
{
public:
    virtual void update(int) = 0;
};

class Subject
{
public:
    virtual void attach(Observer*) = 0;
    virtual void detach(Observer*) = 0;
    virtual void notify() = 0;
};

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(Subject* pSubject) : m_pSubject(pSubject){}
    void update(int value) {
        cout << "ConcreteObserver update, value is " << value << endl;
    }
private:
    Subject* m_pSubject;
};

class ConcreteObserver2 : public Observer
{
public:
    ConcreteObserver2(Subject* pSubject) : m_pSubject(pSubject){}
    void update(int value) {
        cout << "ConcreteObserver2 update, value is " << value << endl;
    }
private:
    Subject* m_pSubject;
};

class ConcreteSubject : public Subject
{
public:
    void attach(Observer* pObserver){
        m_ObserverList.push_back(pObserver);
    }
    void detach(Observer* pObserver){
        m_ObserverList.remove(pObserver);
    }
    void notify()
    {
        list<Observer*>::iterator it = m_ObserverList.begin();
        while(it != m_ObserverList.end()){
            (*it)->update(m_nState);
            ++it;
        }
    }

    void setState(int state){
        m_nState = state;
    }
private:
    list<Observer*> m_ObserverList;
    int m_nState;
};


int main()
{
    ConcreteSubject* pSubject = new ConcreteSubject();

    Observer* pObserver = new ConcreteObserver(pSubject);
    Observer* pObsercer2 = new ConcreteObserver2(pSubject);

    pSubject->setState(2);

    pSubject->attach(pObsercer2);
    pSubject->attach(pObserver);

    pSubject->notify();

    pSubject->detach(pObsercer2);

    pSubject->setState(3);
    pSubject->notify();

    return 0;
}