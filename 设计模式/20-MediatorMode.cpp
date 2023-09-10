/**
 * 中介者模式：用一个中介对象封装一系列的对象交互
 *          中介者使各对象不需要显示地互相引用，从而使其耦合松散
 *          而且可以独立地改变他们之间的交互
*/

#include <iostream>
#include <string>
using namespace std;

class Colleague;
class Mediator
{
public:
    virtual void send(string message, Colleague* colleague) = 0;
};

class Colleague
{
public:
    Colleague(Mediator *p_mediator): m_pMediator(p_mediator){}
    virtual void send(string message) = 0;
protected:
    Mediator* m_pMediator;
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator* p_mediator):Colleague(p_mediator){}
    virtual void send(string message){
        m_pMediator->send(message, this);
    }
    void notify(string messsage){
        cout << "Colleague 1 has received message: " << messsage << endl;
    }
};

class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator* p_mediator):Colleague(p_mediator){}
    virtual void send(string message){
        m_pMediator->send(message, this);
    }
    void notify(string messsage){
        cout << "Colleague 2 has received message: " << messsage << endl;
    }
};

class ConcreteMediator : public Mediator
{
public:
    virtual void send(string message, Colleague* p_struColleague){
        ConcreteColleague1* p_struConcreteColleague1 = dynamic_cast<ConcreteColleague1*>(p_struColleague);
        if(p_struConcreteColleague1){
            cout << "The message from Colleague1: " << message << endl;
            if(m_pstruColleague_2){
                m_pstruColleague_2->notify(message);
            }
        }
        else{
            cout << "The message from Colleague2: " << message << endl;
            if(m_pstruColleague_1){
                m_pstruColleague_1->notify(message);
            }
        }
    }
    void setColleague1(Colleague* p_struColleague){
        m_pstruColleague_1 = dynamic_cast<ConcreteColleague1*>(p_struColleague);
    }
    void setColleague2(Colleague* p_struColleague){
        m_pstruColleague_2 = dynamic_cast<ConcreteColleague2*>(p_struColleague);
    }
private:
    ConcreteColleague1* m_pstruColleague_1;
    ConcreteColleague2* m_pstruColleague_2;
};

int main() {
    Mediator* p_struMediator = new ConcreteMediator();
    Colleague* p_struColleague_1 = new ConcreteColleague1(p_struMediator);
    Colleague* p_struColleague_2 = new ConcreteColleague2(p_struMediator);
    
    ConcreteMediator* p_struConcreteMediator = dynamic_cast<ConcreteMediator*>(p_struMediator);
    p_struConcreteMediator->setColleague1(p_struColleague_1);
    p_struConcreteMediator->setColleague2(p_struColleague_2);

    string message1 = "Have you eat morning?";
    p_struColleague_1->send(message1);

    string message2 = "No, I haven't!";
    p_struColleague_2->send(message2);
    
    return 0;
}