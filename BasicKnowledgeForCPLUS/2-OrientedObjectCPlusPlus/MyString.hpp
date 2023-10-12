/*
String 类
*/
#include<iostream>
#include<assert.h>

/*************** string.h *******************/
char* strcpy(char* dest, const char* src)
{
    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }

    char* p = dest;
    while (*src != '\0') {
        *p++ = *src++;
    }

    *p = '\0';
    return dest;
}

int strlen(const char* str)
 {
    int res = 0;
    if (nullptr == str) {
        return -1;
    }
    else {
        while(*str++ != '\0') {
            res++;
        }
    }
    return res;
 }

int strcmp(const char* str1, const char* str2)
{
    while(*str1 &&(*str1 == *str2)) {
        ++str1;
        ++str2;
    }

    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

char* strcat(char* dest, const char* src)
{
    assert(dest != nullptr && src != nullptr);
    char* s1 = dest;
    while(*s1 != '\0') {
        s1++;
    }
    while(*s1++ = *src++);
    return dest;
}

/*************** string.h *******************/

class String
{
public:

    // consructor
    String() : data(new char[1]), length(0) {
        data[0] = '\0';
    }

    String(const char*str) : data(new char[strlen(str) +1]), length(strlen(str)){
        strcpy(data, str);
    }

    // copy consructor
    String(const String &rhs) : data(new char[rhs.length + 1]), length(rhs.length){
        strcpy(data, rhs.data);
    }

    // move construtor
    String(String&& rhs) : data(rhs.data), length(rhs.length){
        rhs.data = nullptr;
        rhs.data = 0;
    }

    // assign construtor
    String& operator=(const String &rhs){
        if(this != &rhs){
            String(rhs).swap(*this);
        }

        return *this;
    }

    // destructor
    ~String(){
        delete []data;
        length = 0;
    }

    // overload +
    String operator+(const String& str) const{
        String newString;
        newString.length = length + str.size();
        newString.data = new char[newString.length + 1];
        strcpy(newString.data, data);
        strcat(newString.data, str.data);
        return newString;
    }

    // overload +=
    String& operator+=(const String &str){
        length += str.length;
        char *newData = new char[length+1];
        strcpy(newData, data);
        strcat(newData, str.data);

        delete[] data;
        data = newData;
        return *this;
    }

    // overload ==
    bool operator==(const String &rhs) const {
        return strcmp(data, rhs.data) == 0;
    }

    // overload []
    char &operator[](int index) const {
        return data[index];
    }

    // get length
    size_t size() const {
        return length;
    }

    // get length for C pointer
    const char* c_str() const {
        return data;
    }

    // overlad >>
    friend std::istream& operator>> (std::istream &is, String &str){
        char tmp[1000] = {0};
        is >> tmp;
        str.length = strlen(tmp);
        str.data = new char[str.length + 1];
        strcpy(str.data, tmp);
        return is;
    }

    // overload <<
    friend std::ostream& operator<< (std::ostream &os, String &str)
    {
        os << str.c_str();
        return os;
    }

    void swap(String &rhs){
        std::swap(data, rhs.data);
        std::swap(length, rhs.length);
    }

private:
    char *data;
    size_t length;
};

int main()
{
    String s1("hello,");
    String s2("World!");

    s1 += s2;

    std::cout << "s1 : " <<  s1 << std::endl;
    std::cout << "s2 : " <<  s2 << std::endl;

    if(s1 == "hello,World!"){
        std::cout << "s1 is equal to hello,World!" << std::endl;
    }
    else {
        std::cout << "s1 is not equal to hello,World!" << std::endl;
    }

    std::cout << "The first charcater of s1 is : " << s1[0] << std::endl;

    return 0;
}
