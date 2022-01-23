#include<iostream>

using namespace std;

void capturePassedByValueAll();
void capturePassedByReferenceAll();
void capturePassedByValueExceptSome();
void lambdaMutable();
void lambdaParameter();
void lambdaReturnType();

int main() {

    // passed by value
    capturePassedByValueAll();

    // passed by reference
    capturePassedByReferenceAll();

    // passed by value all excpet some
    capturePassedByValueExceptSome();

    // passed by value all and mutable
    lambdaMutable();

    // lambda in parameter
    lambdaParameter();

    // lambda in return
    lambdaReturnType();
    return 0;
}

void lambdaReturnType()
{  
    auto autoGetRetutnType = []() {
        return 5+3;
    };
    cout  << "lambdaReturnType = " << autoGetRetutnType() << endl;

    auto specifyReturnType = [](int x)->string {
        if (x > 0) {
            return "x more than zero";
        }
        else {
            return "x less than zero";
        }
    };
    cout  << "specifyReturnType = " << specifyReturnType(2) << endl;

}

void lambdaParameter()
{
    int a = 1;
    int b = 2;
    
    auto f = [](int a, int b) {
        return a > b ? a : b;
    };

    cout  << "lambdaParameter f(a,b) = " << f(a, b) << endl;
}

void lambdaMutable()
{
    int a = 1;
    int b = 2;

    auto passedByValueMutable = [=]()mutable {
        cout << "lambdaMutable start a :" << a << " b: " << b << endl;
        a++;
        b++;
        cout << "modify after a :" << a << " b: " << b << endl;
    };
    passedByValueMutable();
    cout << "lambdaMutable a :" << a << " b: " << b << endl;
}

void capturePassedByValueExceptSome()
{
    int a = 0;
    int b = 1;
    int c = 100;
    int d = 200;
    auto passedByValueExceptSome = [=, &c, &d]() {
        cout << "capturePassedByValueExceptSome start a = " << a << " b = " << b << endl;
        cout << "midify after c = " << c << " d = " << d << endl;
        
        c++;
        d++;
        cout << "midify after c = " << c << " d = " << d << endl;
        cout << "capturePassedByValueExceptSome end" << endl;

    };

    passedByValueExceptSome();
    cout << "a = " << a << " b = " << b << endl;    
}

void capturePassedByReferenceAll()
{
    int c = 100;
    int d = 200;
    auto passedByReference = [&] {
        cout << "passedByReference c = " << c << " d = " << d << endl;
        c++;
        d++;
        cout << "c = " << c << " d = " << d << endl;
        cout << "passedByReference end" << endl;
    };
    passedByReference();
    cout << "c = " << c << " d = " << d << endl;
}

void capturePassedByValueAll()
{
    int a = 0;
    int b = 1;
    auto passedByValue = [=]() {
        cout << "passedByValue start a = " << a << " b = " << b << endl;
        cout << "passedByValue end" << endl;
    };

    passedByValue();
    cout << "a = " << a << " b = " << b << endl;
}