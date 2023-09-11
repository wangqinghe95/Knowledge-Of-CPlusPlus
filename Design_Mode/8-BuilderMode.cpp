/**
 * 建造者模式：将一个复杂的对象与它的表示分离，使得同样的构建过程可以创建不同的表示。
 *              用户只需要指定需要建造的类型就可以得到他们，而具体建造的过程和细节则是透明的。
*/

#include<iostream>
#include<string>
using namespace std;


// 要构建的对象
class Graphic
{
public:
    Graphic(){};
    void setShape(string strShape) {
        m_strShape = strShape;
    }
    void setColor(string strColor) {
        m_strColor = strColor;
    }
    void show(){
        cout << "color is " << m_strColor << " shape is " << m_strShape << endl;
    }

private:
    string m_strShape;
    string m_strColor;
};

// 建造者抽象类
class Builder
{
public:
    Builder() : m_pGraphic(NULL){}

    void createGraphic(){
        if(NULL == m_pGraphic){
            m_pGraphic = new Graphic();
        }
    }
    Graphic* getGraphic(){
        return m_pGraphic;
    }

    virtual void drawShape() = 0;
    virtual void drawColor() = 0;
protected:
    Graphic* m_pGraphic;
};

class GreenCircleBuilder: public Builder 
{
public:
    void drawShape(){
        if(NULL != m_pGraphic) {
            m_pGraphic->setShape("Circle");
        }
    }

    void drawColor(){
        if(NULL != m_pGraphic) {
            m_pGraphic->setColor("Green");
        }
    }
};

class RedRectangleBuilder : public Builder
{
public:
    void drawShape(){
        if(NULL != m_pGraphic){
            m_pGraphic->setShape("Rectangle");
        }
    }
    void drawColor(){
        if(NULL != m_pGraphic) {
            m_pGraphic->setColor("Red");
        }
    }
};

class BlueTriangleBuilder : public Builder
{
public:
    void drawShape(){
        if(NULL != m_pGraphic){
            m_pGraphic->setShape("Triangle");
        }
    }
    void drawColor(){
        if(NULL != m_pGraphic){
            m_pGraphic->setColor("Blue");
        }
    }
};

class Director
{
public:
    Director() : m_pBuilder(NULL){}
    void setBuilder(Builder& pBuilder){
        m_pBuilder = &pBuilder;
    }

    Graphic* drawGraphic(){
        if(NULL == m_pBuilder){
            return NULL;
        }

        m_pBuilder->createGraphic();
        m_pBuilder->drawShape();
        m_pBuilder->drawColor();
        return m_pBuilder->getGraphic();
    }
private:
    Builder* m_pBuilder;
};

int main()
{
    Director CDirector;
    GreenCircleBuilder CGreenCircleBuilder;
    CDirector.setBuilder(CGreenCircleBuilder);
    Graphic* pGraphicGreenCircle = CDirector.drawGraphic();
    pGraphicGreenCircle->show();


    RedRectangleBuilder CRedRectBuilder;
    CDirector.setBuilder(CRedRectBuilder);
    Graphic* pGraphicRedRect = CDirector.drawGraphic();
    pGraphicRedRect->show();

    BlueTriangleBuilder CBlueTriangBuilder;
    CDirector.setBuilder(CBlueTriangBuilder);
    Graphic* pBlueTriang = CDirector.drawGraphic();
    pBlueTriang->show();
    return 0;
}