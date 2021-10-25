/*
String 类
*/
#include"String.hpp"

class String
{
    public:
        String(const char*str=NULL);    //构造函数
        String(const String &str);      //拷贝构造函数
        ~String();                      //析构函数
        String operator+(const String& str) const;  //重载+
        String& operator=(const String &str);        //重载=
        String& operator+=(const String &str);        //重载+=
        bool operator==(const String &str) const;    //重载==
        char &operator[](int n) const;              //重载 []

        size_t size() const;                         // 获取长度
        const char* c_str() const;                   //获取 C 字符段长度
        friend istream& operator>> (istream &is, String &str);  //输入
        friend istream& operator<< (ostream &os, String &str);  //输入
    private:
        char *data;
        size_t length;
};

String::String(const char*str = nullptr)
{
    if (!str){
        length = 0;
        data = new char[1];
        *data = '\0';
    }
    else{
        length = strlen(str);
        data = new char[length+1];
        strcpy(data, str);
    }
}

String::String(const String &str)
{
    length = str.size();
    data = new char[length + 1];
    strcpy(data, str.c_str());
}

String::~String()
{
    delete []data;
    length = 0;
}

String String::operator+(const String& str) const
{
    String newString;
    newString.length = length + str.size();
    newString.data = new char[newString.length + 1];
    strcpy(newString.data, data);
    strcat(newString.data, str.data);
    return newString;
}

String& String::operator=(const String &str)
{
    if (*this == str){
        return *this;
    }

    delete[] data;
    length = str.length;
    data = new char[length+1];
    strcpy(data, str.c_str());
    return *this;
}

String& String::operator+=(const String &str)
{
    length += str.length;
    char *newData = new char[length+1];
    strcpy(newData, str.c_str());
    strcat(newData, str.data);

    delete[] data;
    data = newData;
    return *this;
}

inline bool String::operator==(const String &str) const
{
    if (length != str.length){
        return false;
    }
    return strcmp(data, str.data) ? false : true;
}

inline char& String::operator[](int n) const
{
    if (n >= length){
        return data[length-1];
    }
    else{
        data[n];
    }
}

inline size_t String::size() const
{
    return length;
}

const char* String::c_str() const
{
    return data;
}

istream& operator>> (istream &is, String &str){
    char tmp[1000] = {0};
    is >> tem;
    str.length = strlen(tem);
    str.data = new char[str.length + 1];
    strcpy(str.data, tem);
    return is;
}

istream& operator<< (ostream &os, String &str)
{
    os << str.data;
    return os;
}

/**********************************/
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

int strcmp(const char* str1, char* str2)
{
    assert(str1 != nullptr && str2 != nullptr);

    for (; *str1 == *str2; str1++, str2++);

    if (*str1 == '\0' && *str2 == '\0'){
        return 0;
    }

    return ((unsigned char)*str1 < (unsigned char)*str2 ? -1 : 1);
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
