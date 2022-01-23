
#include<iostream>

using namespace std;

class Functor {
private:
    int id;
public:
    void operator() (){
        std::cout << "id： " << id << endl;
        ++id;
    }
};

int main() {
    int id = 0;
    auto f = [id]() mutable {
        cout << "id: " << id << endl;
        ++id;
    };

    f();
    cout << id << endl;

    f();
    f();
    cout << id << endl;
    return 0;
}