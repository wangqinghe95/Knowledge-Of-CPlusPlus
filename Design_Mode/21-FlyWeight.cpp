/**
 * 享元模式：通过共享技术有效地支持大量颗粒细度的对象
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class FlyWeight
{
public:
    virtual void Operation(const string& extrinsicState) = 0;
    string getIntrinsicState(){
        return m_intrinsicState;
    }
    virtual ~FlyWeight(){}
protected:
    FlyWeight(string intrinsicState){
        m_intrinsicState = intrinsicState;
    }
private:
    string m_intrinsicState;
};

class UnsharedConcreteFlyWeight : public FlyWeight
{
public:
    virtual void Operation(const string& extrinsicState){
        cout << extrinsicState << endl;
    }
    UnsharedConcreteFlyWeight(string intrinsicState):FlyWeight(intrinsicState){

    }
    ~UnsharedConcreteFlyWeight(){}
private:

};

class ConcreteFlyweight : public FlyWeight
{
public:
    virtual void Operation(const string& extrinsicState){
        cout << getIntrinsicState() << endl;
        cout << extrinsicState << endl;
    }
    ConcreteFlyweight(string intrisicState):FlyWeight(intrisicState){
        
    }
    ~ConcreteFlyweight(){}
private:

};

class FlyWeightFactory
{
public:
    FlyWeightFactory(){}
    ~FlyWeightFactory(){}
    FlyWeight* getFlyWeight(string key){
        vector<FlyWeight*>::iterator it = m_vecPFlyWeight.begin();
        for(; it != m_vecPFlyWeight.end(); ++it){
            if((*it)->getIntrinsicState() == key){
                return *it;
            }
        }

        FlyWeight* p_struFly = new ConcreteFlyweight(key);
        m_vecPFlyWeight.push_back(p_struFly);
        return p_struFly;
    }
    void getFlyWeightCount(){
        cout << m_vecPFlyWeight.size() << endl;
    }
private:
    vector<FlyWeight*> m_vecPFlyWeight;
};

class character
{
public:
    virtual ~character(){}
    virtual void display(int width, int height, int ascent, int descent, int pointSize) = 0;
    virtual char getSymbol() = 0;
protected:
    char m_symbol;
    int m_width;
    int m_height;
    int m_ascent;
    int m_descent;
    int m_pointSize;

    character(char c){
        m_symbol = c;
    }
};

class characterA : public character
{
public:
    characterA(char c):character(c){}
    ~characterA(){}
    virtual void display(int width, int height, int ascent, int descent, int pointSize){
        m_ascent = ascent;
        m_height = height;
        m_width = width;
        m_pointSize = pointSize;
        m_descent = descent;

        cout << m_symbol << " " << m_ascent << " " << m_descent << " " << m_height << " " << m_pointSize << " " << m_width << endl;
    }
    virtual char getSymbol(){
        return m_symbol;
    }
};

#if 0
class characterB : public character
{
public:
    characterB(char c):character(c){}
    ~characterB(){}
    virtual void display(int width, int height, int ascent, int descent, int pointSize);
    virtual char getSymbol(){
        return m_symbol;
    }
};

class characterC : public character
{
public:
    characterC(char c);
    ~characterC();
    virtual void display(int width, int height, int ascent, int descent, int pointSize);
    virtual char getSymbol();
};

class characterD : public character
{
public:
    characterD(char c);
    ~characterD();
    virtual void display(int width, int height, int ascent, int descent, int pointSize);
    virtual char getSymbol();
};
#endif

class characterFactory
{
public:
    characterFactory(){}
    ~characterFactory(){}
    character* getCharacter(char c){
        vector<character*>::iterator iter = m_vecCharacter.begin();
        for(; iter != m_vecCharacter.end(); ++iter){
            if((*iter)->getSymbol() == c) {
                return *iter;
            }
        }

        character* p_F = new characterA(c);
        m_vecCharacter.push_back(p_F);
        return p_F;

    }
    vector<character*>::size_type getCount(){
        return m_vecCharacter.size();
    }
private:
    vector<character*> m_vecCharacter;
};

int main()
{
    #if 0
    string extrinsicState = "ext";
    FlyWeightFactory* p_struFlyWeightFac = new FlyWeightFactory();
    FlyWeight* p_struFlyWeight = p_struFlyWeightFac->getFlyWeight("hello");
    // FlyWeight* p_struFlyWeight1 = p_struFlyWeightFac->getFlyWeight("hello");

    p_struFlyWeight->Operation(extrinsicState);

    p_struFlyWeightFac->getFlyWeightCount();

    #endif

    int ascent = 70;
    int descent = 0;
    int height = 100;
    int width = 120;
    int pointSize = 10;

    string test = "AABCDEEFGHO";
    string::iterator it = test.begin();
    characterFactory* pcF = new characterFactory();
    for (; it != test.end(); ++it)
    {
        pointSize++;
        char c = *it;
        character* p_charF = pcF->getCharacter(c);
        p_charF->display(width,height,ascent,descent,pointSize);
    }

    vector<character*>::size_type sizeChar = pcF->getCount();
    cout << "count: " << sizeChar << endl;

    return 0;
}