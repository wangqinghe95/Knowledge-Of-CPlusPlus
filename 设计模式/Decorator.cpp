
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