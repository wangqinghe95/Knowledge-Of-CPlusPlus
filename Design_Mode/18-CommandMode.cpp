/**
 * Command: 抽象命令类，根据不同的命令类型，实现不同的命令
 * Concrete Command：具体命令类，完成了抽象命令的具体实现
 * Invoke：请求的发送者，它通过命令对象来执行请求，
 *         一个调用者并不需要在设计时就需要确定好其接收者，因此它只能与抽象命令之间存在联系
 * Receiver：接收者执行与请求相关的操作，真正执行命令的对象。具体实现对请求业务的处理
 *          未抽象时，实际执行操作内容的对象
 * Client：在客户类中需要创建调用对象，具体命令类对象，在创建具体命令对象时指定对应的接收者。
 *          发送者和接收者之间没有关系，都是通过命令对象来调用
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

class Receiver
{
public:
    void BakeMutton(){
        cout << "Bake mutton..." << endl;
    }
    void BakeChicken(){
        cout << "Bake chicken..." << endl;
    }
};

class Command
{
public:
    Command(Receiver* pstRecevier):m_pstReceiver(pstRecevier){}
    virtual void Excute() = 0;
protected:
    Receiver* m_pstReceiver;
};

class ConcreteCommandA : public Command
{
public:
    ConcreteCommandA(Receiver* pstReceiver):Command(pstReceiver){

    }

    virtual void Excute(){
        cout << "ConcreteCommandA excuting..." << endl;
        m_pstReceiver->BakeMutton();
    }
};

class ConcreteCommandB : public Command
{
public:
    ConcreteCommandB(Receiver* pstReceiver):Command(pstReceiver){

    }

    virtual void Excute(){
        cout << "ConcreteCommandB excuting..." << endl;
        m_pstReceiver->BakeChicken();
    }
};

class Invoke{
public:
    void Add(Command* pstCommand){
        m_vecPstCommand.push_back(pstCommand);
    }
    void Remove(Command* pstCommand){
        m_vecPstCommand.erase(find(m_vecPstCommand.begin(), m_vecPstCommand.end(),pstCommand));
    }
    void RemoveAll(){
        m_vecPstCommand.clear();
    }
    void Notify(){
        for(typeof(m_vecPstCommand.begin()) it = m_vecPstCommand.begin(); it != m_vecPstCommand.end(); it++){
            (*it)->Excute();
        }
    }
private:
    vector<Command*> m_vecPstCommand;
};

int main()
{
    Receiver* pstReceiver = new Receiver;
    Command* pstConcreteCommandA = new ConcreteCommandA(pstReceiver);
    Command* pstConcreteCommandB = new ConcreteCommandB(pstReceiver);
    Invoke* pstInvoke = new Invoke();

    pstInvoke->Add(pstConcreteCommandA);
    pstInvoke->Add(pstConcreteCommandA);
    pstInvoke->Add(pstConcreteCommandB);
    pstInvoke->Notify();

    cout << "-----------First Call End---------" << endl;

    pstInvoke->Remove(pstConcreteCommandA);
    pstInvoke->Remove(pstConcreteCommandB);
    pstInvoke->Notify();

    cout << "-----------Second Call End---------" << endl;

}

