/**
 * 抽象工厂模式：提供一个创建一系列相关或者相互依赖对象的接口，而无需指定他们具体的类。
 * 包含了四个角色：
 *  1. 抽象工厂
 *  2. 具体工厂
 *  3. 抽象产品
 *  4. 具体产品
*/

#include<iostream>
using namespace std;

// abstract factory mode

// abstract class User
class AbstractUser
{
public:
    virtual void insert() = 0;
};

// concrete class User
class SqlserverUser : public AbstractUser
{
public:
    virtual void insert(){
        cout << "Insert a record for User table in SQL server" << endl;
    }
};

class AccessUser : public AbstractUser
{
public:
    virtual void insert(){
        cout << "Insert a record for User table in Access server" << endl;
    }   
};


// abstract class Department
class AbstractDepartment
{
public:
    virtual void insert() = 0;
};


// concrete class Deparment
class SqlserverDepartment : public AbstractDepartment
{
public:
    virtual void insert(){
        cout << "Insert a record for Department table in SQL server" << endl; 
    }
};

class AccessDepartment : public AbstractDepartment
{
public:
    virtual void insert(){
        cout << "Insert a record for Department table in Access server" << endl; 
    }
};

// abstract Factory class
class AbstractFactory
{
public:
    virtual AbstractUser* user()=0;
    virtual AbstractDepartment* department()=0;
};

// concrete Factory class
class SqlserverFactory : public AbstractFactory 
{
public:
    virtual AbstractUser* user(){
        return new SqlserverUser;
    }
    virtual AbstractDepartment* department(){
        return new SqlserverDepartment;
    }
};

class AccessFactory : public AbstractFactory 
{
public:
    virtual AbstractUser* user(){
        return new AccessUser;
    }
    virtual AbstractDepartment* department(){
        return new AccessDepartment;
    }
};

int main(){
    AbstractFactory* pFactory = NULL;
    AbstractUser* pUser = NULL;
    AbstractDepartment* pDeparment = NULL;

    pFactory = new AccessFactory;
    pUser = pFactory->user();
    pUser->insert();
    pDeparment = pFactory->department();
    pDeparment->insert();

    delete pUser;
    delete pFactory;
    delete pDeparment;

    pFactory = new SqlserverFactory;
    pDeparment = pFactory->department();
    pDeparment->insert();
    pUser = pFactory->user();
    pUser->insert();

    delete pDeparment;
    delete pFactory;
    delete pUser;

    return 0;
}