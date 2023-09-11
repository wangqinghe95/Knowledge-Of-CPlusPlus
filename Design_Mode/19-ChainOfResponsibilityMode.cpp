/**
 * Chain of responsibility
 * 该模式属于行为型模式
 * 当一条请求可能需要多个对面处理时，就将所有对象串成一个责任链模式，让请求沿着这个责任链传递
 * 对请求的发送者和接收者进行解耦
 * 
 * 角色：
 * Hanlder：处理者抽象角色，所有处理者的抽象类
 * ConcreteHandler：具体的处理者，是 Handler 对象的具体实现
 * Client：请求的调用者
*/

#include <iostream>
using namespace std;

class Leader
{
public:
    void setNext(Leader* nextLeader){
        m_pstNextLeader = nextLeader;
    }

    Leader* getNext(){
        return m_pstNextLeader;
    }

    virtual ~Leader(){}
    virtual void handleRequest(int leaveDays) = 0;

private:
    Leader* m_pstNextLeader;
};

class ClassAdviser : public Leader
{
public:
    void handleRequest(int leaveDays){
        if(leaveDays <= 2) {
            cout << "ClassAdviser have permitted your holiday: " << leaveDays << endl;
        }
        else{
            if(getNext() != nullptr){
                getNext()->handleRequest(leaveDays);
            }
            else{
                cout << "Holiday is too big, and nobody can perimit" << endl;
            }
        }
    }
private:
};

class DepartmentHead : public Leader
{
public:
    void handleRequest(int leaveDays){
        if(leaveDays <= 7){
            cout << "DepartmentHead have permitted your holiady: " << leaveDays << endl;
        }
        else{
            if(getNext() != nullptr){
                getNext()->handleRequest(leaveDays);
            }
            else{
                cout << "Holiday is too big, and nobody can perimit" << endl;
            }
        }
    }
private:

};

class Dean : public Leader
{
public:
    void handleRequest(int leaveDays){
        if(leaveDays <= 10){
            cout << "Dean have permitted your holiady: " << leaveDays << endl;
        }
        else{
            if(getNext() != nullptr){
                getNext()->handleRequest(leaveDays);
            }
            else{
                cout << "Holiday is too big, and nobody can perimit" << endl;
            }
        }       
    }
private:

};

int main()
{
    Leader* pstClassAdviser = new ClassAdviser();
    Leader* pstDepartment = new DepartmentHead();
    Leader* pstDean = new Dean();

    pstClassAdviser->setNext(pstDepartment);
    pstDepartment->setNext(pstDean);

    int leaveDays[5] = {1, 5, 7, 10, 13};
    for(int i = 0; i < (int)(sizeof(leaveDays)/sizeof(leaveDays[0])); ++i){
        pstClassAdviser->handleRequest(leaveDays[i]);
    }

    return 0;
    
}