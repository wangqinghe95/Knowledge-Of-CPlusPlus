/**
 * 备忘录模式：在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态
 *              以便以后可将该对象恢复到原先保存的状态
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Memento
{
public:
    Memento(uint32_t uiHP, uint32_t uiLevel, uint32_t uiAttack)
            : m_uiHP(uiHP), m_uiLevel(uiLevel), m_uiAttack(uiAttack){}
public:
    uint32_t m_uiHP;
    uint32_t m_uiLevel;
    uint32_t m_uiAttack;
};

class GameRole
{
public:
    GameRole(string strName)
        : m_strName(strName)
        , m_uiHP(100)
        , m_uiLevel(1)
        , m_uiAttack(10)
        {}
    void show(){
        cout << "Name: " << m_strName << " Level: " << m_uiLevel << " HP: " << m_uiHP << " Attack: " << m_uiAttack << endl;
    }
    Memento* save(){
        Memento* pSaveInfo = new Memento(m_uiHP, m_uiLevel, m_uiAttack);
        return pSaveInfo;
    }
    void load(Memento* pMem){
        m_uiHP = pMem->m_uiHP;
        m_uiLevel = pMem->m_uiLevel;
        m_uiAttack = pMem->m_uiAttack;
    }

private:
    string m_strName;
public:
    uint32_t m_uiHP;
    uint32_t m_uiLevel;
    uint32_t m_uiAttack;   
};

class Recorder
{
public:
    void Record(Memento* pMem){
        vecMemento.push_back(pMem);
        cout << "Record save" << endl;
    }
    Memento* getMemento(uint32_t index){
        return vecMemento[index];
    }
private:
    vector<Memento*> vecMemento;
};

int main()
{
    Recorder CRecorder;
    GameRole CPlayer("Mark");
    CPlayer.show();

    CRecorder.Record(CPlayer.save());

    CPlayer.m_uiLevel = 100;
    CPlayer.m_uiHP = 1000;
    CPlayer.m_uiAttack = 300;
    CPlayer.show();

    CPlayer.load(CRecorder.getMemento(0));
    CPlayer.show();

    return 0;
}