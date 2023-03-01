/*
* 策略模式（strategy）：定义算法家族，分别封装起来，让算法之间可以相互替换，且不会影响到使用算法的使用者
*/

#include<iostream>
using namespace std;

// 抽象收费策略
class CashSuper
{
private:
    /* data */
public:
    virtual double acceptCash(double) = 0;
};

// 正常收费类
class CashNornal: public CashSuper{
public:
    virtual double acceptCash(double money){
        return money;
    }
};

// 打折收费类
class CashRebate : public CashSuper {
public:
    CashRebate(double money_rebate) {
        mMoneyRebate = money_rebate;
    }

    virtual double acceptCash(double money) {
        return money * mMoneyRebate;
    }
private:
    double mMoneyRebate = 1.0;
};

// 返利收费类
class CashReturn : public CashSuper {
public:
    CashReturn(double money_condition, double money_return) {
        mMoneyCondition = money_condition;
        mMoneyReturn = money_return;
    }

    virtual double acceptCash(double money){
        double result = money;
        if(money >= mMoneyCondition) {
            result = money - (int)(money / mMoneyCondition) * mMoneyReturn;
            return result;
        }
        return result;
    }
private:
    double mMoneyCondition = 0;
    double mMoneyReturn = 0;
};

class CashContext{
public:
    CashContext(CashSuper* pCashSuper){
        mPCashSuper = pCashSuper;
    }
    
    double ContextInterface(double money){
        return mPCashSuper->acceptCash(money);
    }

    ~CashContext(){
        if(this->mPCashSuper != nullptr){
            delete mPCashSuper;
        }
    }
public:
    CashSuper* mPCashSuper = nullptr;
};

int main()
{
    CashContext* context = NULL;
    context = new CashContext(new CashNornal());
    cout << "cahsNormal : " << context->ContextInterface(700) << endl;

    context = new CashContext(new CashRebate(0.8));
    cout << "CashRebate : " << context->ContextInterface(700) << endl;

    context = new CashContext(new CashReturn(300,100));
    cout << "CashRebate : " << context->ContextInterface(700) << endl;

    return 0;
}

