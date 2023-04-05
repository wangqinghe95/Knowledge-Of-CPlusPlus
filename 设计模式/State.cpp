
/**
 * 允许一个对象在其内部状态改变时改变它的行为
*/
#include<iostream>
#include<string>
#include<memory>
using namespace std;

class Context;

class State
{
public:
    virtual void Handle(Context* pContext) = 0;
};

class ConcreteStateA : public State
{
public:
    virtual void Handle(Context* pContext){
        cout << "I'm  ConcreteStateA" << endl;
    }
};

class ConcreteStateB : public State
{
public:
    virtual void Handle(Context* pContext){
        cout << "I'm  ConcreteStateB" << endl;
    }
};

class Context
{
public:
    Context(State* pState) : m_pState(pState){}

    void Request(){
        if(m_pState){
            m_pState->Handle(this);
        }
    }

    void changeState(State* pState){
        m_pState = pState;
    }

private:
    State* m_pState;
};

int main()
{
    State* pStateA = new ConcreteStateA();
    State* pStateB = new ConcreteStateB();

    Context* pContext = new Context(pStateA);
    pContext->Request();

    pContext->changeState(pStateB);
    pContext->Request();

    return 0;

}

/*
class People;

class State
{
public:
    State(string context);
    virtual ~State();
    virtual void handle(People* pPeo) = 0;

    string Content();
protected:
    string m_Content;
private:
    int m_Time;
};

class People
{
public:
    People(State* pState):m_State(pState){}

    void changeState(State* pState){
        m_State = pState;
    }
    void show(){
        cout << "show current state: " << m_State->Content() << endl;
    }

    void setTime(int time){
        m_timeNow = time;
        m_State->handle(this);
    }

    int getTime(){
        return m_timeNow;
    }

private:
    int m_timeNow;
    State* m_State;
};

class workState : public State
{
public:
    workState(string content="work_state"):State(content){}
    void handle(People* pPeo)  {
        int n_time = pPeo->getTime();
        if(n_time > 0 && n_time <= 9) {
            State* pState = new playState();
            pPeo->changeState();
        }
    }

};

class playState : public State
{
public:
    playState(string content="play_state"):State(content){}
    void handle(People* pPeo)  {
        int n_time = pPeo->getTime();
        if(n_time > 18 && n_time <= 22) {
            pPeo->changeState(new lifeState("life_state"));
        }
    }   
};

class lifeState : public State
{
public:
    lifeState(string content):State(content){}
    void handle(People* pPeo)  {
        int n_time = pPeo->getTime();
        if(n_time > 9 && n_time < 18) {
            pPeo->changeState(new workState("work_state"));
        }
    }
};

int main()
{
    shared_ptr<State> pState = make_shared<workState>();
    People pPeo(pState.get());

    pPeo.show();
    return 0;
}
*/