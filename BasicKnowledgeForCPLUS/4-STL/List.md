# List

## list 简单实现
```
#ifndef LIST_HPP_
#define LIST_HPP_

#include <iostream>
template<typename T>
class node
{
public:
    T value;
    node* next;
    node() : next(nullptr) {}
    node(T val, node* p = nullptr) : value(val), next(p){}
private:

};

template<typename T>
class my_list
{
public:

private:
    node<T> *head;
    node<T> *tail;
    int size;

private:
    class list_iterator
    {
    private:
        node<T>* ptr;
    public:
        list_iterator(node<T>* p = nullptr) : ptr(p){}
        T& operator*() const{
            return ptr->value;
        }
        node<T> *operator->() const {
            return ptr;
        }

        list_iterator &operator++(){
            ptr = ptr->next;
            return *this;
        }

        list_iterator operator++(int) {
            node<T>* tmp = ptr;
            ++(*this);
            return list_iterator(tmp);
        }

        bool operator==(const list_iterator& t) const{
            return t.ptr == this->ptr;
        }

        bool operator!=(const list_iterator &t) const {
            return t.ptr != this->ptr;
        }
    };

public:
    typedef list_iterator iterator;
    my_list() : head(nullptr), tail(nullptr), size(0){}

    void push_back(const T &value) {
        if(head == nullptr) {
            head = new node<T>(value);
            tail = head;
        }
        else {
            tail->next = new node<T>(value);
            tail = tail->next;
        }
        size++;
    }

    void print(std::ostream &os = std::cout) const {
        for(node<T> *ptr = head; ptr != tail->next; ptr = ptr->next){
            os << ptr->value << std::endl;
        }
    }

    iterator begin() const {
        return list_iterator(head);
    }

    iterator end() const {
        return list_iterator(tail->next);
    }
};

#endif // !LIST_HPP_
```

+ test
```
#include <string>
#include "list.hpp"

struct student
{
    std::string name;
    int age;

    student(std::string n, int a) : name(n), age(a){}

    friend std::ostream &operator<<(std::ostream &os, const student &stu){
        os << stu.name << " " << stu.age;
        return os;
    }
};

int main()
{
    my_list<student> list_stu;
    list_stu.push_back(student("bob",1));
    list_stu.push_back(student("allen",2));
    list_stu.push_back(student("anna",3));
    list_stu.print();

    for(my_list<student>::iterator iter = list_stu.begin(); iter != list_stu.end(); iter++){
        std::cout << *iter << std::endl;
        *iter = student("wengle", 18);
    }

    return 0;
}
```

+ 