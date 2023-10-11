/**
 * 迭代器模式
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Aggregate
{
public:
    Aggregate(){}
    virtual ~Aggregate(){}
    virtual int Count() = 0;
    virtual string& operator [](int i) = 0;

    void Insert(string obj){
        m_Vec.push_back(obj);
    }
protected:
    vector<string> m_Vec;
};

class Iterator
{
public:
    Iterator(Aggregate* pAggre):m_Aggreate(pAggre){}
    virtual ~Iterator(){}

    virtual string First() = 0;
    virtual string Next() = 0;
    virtual bool isDone() = 0;
    virtual string getCurrentItem() = 0;
protected:
    Aggregate* m_Aggreate;
};

class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(Aggregate* pAggredate):Iterator(pAggredate){
        m_currentIndex = 0;
    }
    string First() override{
        return (*m_Aggreate)[0];
    }
    string Next() override{
        m_currentIndex++;
        if(m_currentIndex < m_Aggreate->Count()){
            return (*m_Aggreate)[m_currentIndex];
        }
        else {
            return "";
        }
    }
    bool isDone() override{
        return m_currentIndex >= m_Aggreate->Count() ? true : false;
    }
    string getCurrentItem() override{
        return (*m_Aggreate)[m_currentIndex];
    }
private:
    int m_currentIndex;
};

class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate(){}
    int Count() override{
        return static_cast<int>(m_Vec.size());
    }

    string &operator[](int i) override{
        return m_Vec[size_t(i)];
    }
private:
    Iterator* m_pIterator;
};

int main()
{
    Aggregate* pAgt = new ConcreteAggregate();
    pAgt->Insert("王二麻子");
    pAgt->Insert("张二蛋子");
    pAgt->Insert("李二狗子");
    pAgt->Insert("孙小花子");

    Iterator* iter = new ConcreteIterator(pAgt);
    while(!iter->isDone()){
        cout <<  iter->getCurrentItem()  << " 请出示你的车票" << endl;
        iter->Next();
    }

    return 0;
}