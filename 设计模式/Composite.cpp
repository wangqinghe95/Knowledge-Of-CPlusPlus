/**
 * 组合模式：将对象组合成树形结构以表示“部分-整体”的结构层次。
 *          组合模式使得用户对单个对象和组合对象的使用具有一致性
*/

#include<iostream>
#include<string>
#include<list>
using namespace std;

class Component
{
public:
    Component(string name) : m_strName(name){}
    virtual ~Component(){}

    virtual void add(Component* pCom, int depeth = 0) = 0;
    virtual void remove(Component* pCom) = 0;
    virtual void display() = 0;
    virtual void lineOfDuty() = 0;

    string getName(){
        return m_strName;
    }
    void setDepth(int depth){
        m_depth = depth;
    }
    int getDepth()
    {
        return m_depth;
    }
private:
    string m_strName;
    int m_depth;
};

class ConcreteCompany : public Component
{
public:
    ConcreteCompany(string strName):Component(strName){}
    virtual ~ConcreteCompany(){
        for(auto com : m_childCom){
            if(com){
                delete com;
                com = nullptr;
            }
        }
        m_childCom.clear();
    }
    virtual void add(Component* pCom, int depth = 0){
        pCom->setDepth(depth);
        m_childCom.push_back(pCom);
    }
    virtual void remove(Component* pCom){
        m_childCom.remove(pCom);
    }
    virtual void display(){
        string str;
        for(int i = 0; i < getDepth(); ++i) {
            str += "--";
        }
        cout << str << getName() << endl;
        for(auto com : m_childCom){
            com->display();
        }
    }
    virtual void lineOfDuty(){}
private:
    list<Component*> m_childCom;
};

class HRDepartment : public Component
{
public:
    HRDepartment(string strName):Component(strName){}
    virtual ~HRDepartment(){}
    virtual void add(Component* pCom, int depth = 0){
        pCom->setDepth(depth);
    }
    virtual void remove(Component* pCom){}
    virtual void display(){
        string str;
        for(int i = 0; i < getDepth(); ++i) {
            str += "--";
        }
        cout << str << getName() << endl;
    }
    virtual void lineOfDuty(){
        cout << "人力资源部 负责招聘" << endl;
    }
};


class ITDepartment : public Component
{
public:
    ITDepartment(string strName):Component(strName){}
    virtual ~ITDepartment(){}
    virtual void add(Component* pCom, int depth = 0){
        pCom->setDepth(depth);
    }
    virtual void remove(Component* pCom){}
    virtual void display(){
        string str;
        for(int i = 0; i < getDepth(); ++i) {
            str += "--";
        }
        cout << str << getName() << endl;
    }
    virtual void lineOfDuty(){
        cout << "研发部 负责写代码" << endl;
    }
};

class Marketing : public Component
{
public:
    Marketing(string strName):Component(strName){}
    virtual ~Marketing(){}
    virtual void add(Component* pCom, int depth = 0){
        pCom->setDepth(depth);
    }
    virtual void remove(Component* pCom){}
    virtual void display(){
        string str;
        for(int i = 0; i < getDepth(); ++i) {
            str += "--";
        }
        cout << str << getName() << endl;
    }
    virtual void lineOfDuty(){
        cout << "市场部 负责推广市场" << endl;
    }
};

int main()
{
    Component* pComponent = new ConcreteCompany("北京总部");
    pComponent->setDepth(0);
    pComponent->add(new HRDepartment("人力资源部"), 1);
    pComponent->add(new HRDepartment("IT部门"), 1);
    pComponent->add(new HRDepartment("市场部门"), 1);

    Component* pZZ = new ConcreteCompany("郑州办事处");
    pZZ->add(new HRDepartment("人力资源部"), 2);
    pZZ->add(new HRDepartment("IT部门"), 2);
    pZZ->add(new HRDepartment("市场部门"), 2);
    pComponent->add(pZZ,1);

    Component* pXA = new ConcreteCompany("郑州办事处");
    pXA->add(new HRDepartment("人力资源部"), 2);
    pXA->add(new HRDepartment("IT部门"), 2);
    pXA->add(new HRDepartment("市场部门"), 2);
    pComponent->add(pXA,1); 

    pComponent->display();
    return 0;  


}