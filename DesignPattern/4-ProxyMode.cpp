/*
* 代理模式:为其他对象提供一种代理以控制对这个对象的访问
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

// 大话设计模式样例
#include<iostream>
#include<string>
using namespace std;

class SchoolGirl
{
public:
    string getName(){
        return m_strName;
    }
    void setName(string name){
        m_strName = name;
    }
private:
    string m_strName;
};

class Gift
{
public:
     void giveDolls();
     void giveFlowers();
     void giveChocolate();
};

class Pursuit : public Gift
{
public:
    Pursuit(SchoolGirl* pGirl) : m_Girl(pGirl){}
    string getName(){
        return m_strName;
    }
    void setName(string strName){
        m_strName = strName;
    }
    void giveDolls(){
        cout << m_strName << "give [" << m_Girl->getName() << "] Dolls" << endl;
    }
    void giveFlowers(){
        cout << m_strName << "give [" << m_Girl->getName() << "] flowers" << endl;
    }
    void giveChocolate(){
        cout << m_strName << "give [" << m_Girl->getName() << "] chocolate" << endl;
    }
private:
    SchoolGirl* m_Girl;
    string m_strName;
};

class Proxy : public Gift
{
public:
    Proxy(SchoolGirl* pGirl){
        m_Pur = new Pursuit(pGirl);
        m_Pur->setName("胡汉三");
    }

    void giveDolls(){
        m_Pur->giveDolls();
    }
    void giveFlowers(){
        m_Pur->giveFlowers();
    }
    void giveChocolate(){
        m_Pur->giveChocolate();
    }
private:
    Pursuit* m_Pur;
};

int main()
{
    SchoolGirl* pJiaoJiao = new SchoolGirl;
    pJiaoJiao->setName("李娇娇");

    Proxy* pDali = new Proxy(pJiaoJiao);
    pDali->giveDolls();
    pDali->giveFlowers();
    pDali->giveChocolate();

    return 0;

}
