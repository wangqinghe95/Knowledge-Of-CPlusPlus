
/*
* 装饰器模式：
*/

#include<iostream>
#include<string>
using namespace std;

void print(const char* str) {
    cout << "├───────────────────────────────" << endl << "|" <<  str << endl;
}

class absTable{
public:
    virtual void putTable() = 0;
};

class BaseTable : public absTable {
public:
    virtual void putTable(){
        print("name");
        print("gender");
        print("education");
        print("age");
        cout << "├───────────────────────────────" << endl;
    }

};

class Decorator : public absTable {
public:
    Decorator (absTable* concrateTb) : m_pAbsTable(concrateTb){}
    virtual void putTable(){
        m_pAbsTable->putTable();
    }

private:
    absTable* m_pAbsTable;
};

class EnglishDeco : public Decorator {
public:
    EnglishDeco(absTable* pTb):Decorator(pTb){}

    virtual void putTable(){
        print("English level");
        Decorator::putTable();
    }
};

class CurWage : public Decorator {
public:
    CurWage(absTable* pTb) : Decorator(pTb){};
    virtual void putTable(){
        print("Current wage");
        Decorator::putTable();
    }
};

class Experience : public Decorator {
public:
    Experience(absTable* pTb) : Decorator(pTb){};
    virtual void putTable(){
        print("Program Experience");
        Decorator::putTable();
    }
};

int main()
{
    BaseTable CTable;
    cout << "the original table:" << endl;
    CTable.putTable();

    cout << "the table one : " << endl;
    EnglishDeco CEngTable(&CTable);
    CEngTable.putTable();

    cout << "the table two : " << endl;
    CurWage CCurWage(&CEngTable);
    CCurWage.putTable();

    cout << "the table three : " << endl;
    Experience CExperience(&CCurWage);
    CExperience.putTable();

    return 0;
}

/**
 * @brief 
 * Component: Car
 * ConcreteComponent：TOYOYO、VOLOVL
 * Decorator：Function
 * ConcreteDecorator: Navigator、AutoDrive、SpeechControl
 */
#include<iostream>
#include<string>
using namespace std;

// abstract component class
class Car
{
public:
    virtual void showInfo() = 0;
};


// concrete component class 
class TOYOTO : public Car
{
public:
    TOYOTO(){}
    TOYOTO(string name) {
        m_name = name;
    }
    void showInfo(){
        cout << m_name << endl;
    }
private:
    string m_name;
};

class VOLOVL : public Car
{
public:
    VOLOVL(){}
    VOLOVL(string name) {
        m_name = name;
    }
    void showInfo(){
        cout << m_name << endl;
    }
private:
    string m_name;
};

// abstract decorator
class Function : public Car
{
protected:
    Car* m_pCar;
public:
    void Decorate(Car* pCar){
        m_pCar = pCar;
    }
    void showInfo(){
        if(m_pCar != NULL){
            m_pCar->showInfo();
        }
    }
};

// concrete decorator
class Navigator : public Function
{
public:
    void showInfo(){
        cout << "Navigator: ";
        Function::showInfo();
    }
};

// automatic drive
class AutoDrive : public Function
{
public:
    void showInfo(){
        cout << "AutoDrive: ";
        Function::showInfo();
    }
};

// speech control
class SpeechControl : public Function
{
public:
    void showInfo(){
        cout << "SpeechControl: ";
        Function::showInfo();
    }
};

int main()
{
    Car* p_CToyota = new TOYOTO("toyoto");
    Navigator* p_CNavi = new Navigator();
    AutoDrive* p_CAuto = new AutoDrive();
    p_CNavi->Decorate(p_CToyota);
    p_CAuto->Decorate(p_CNavi);
    p_CAuto->showInfo();

    Car* p_CVolo = new VOLOVL("Volovo");
    Navigator* p_CNa2 = new Navigator();
    SpeechControl* p_CSpeech = new SpeechControl();
    p_CNa2->Decorate(p_CVolo);
    p_CSpeech->Decorate(p_CNa2);
    p_CSpeech->showInfo();

    return 0;
}