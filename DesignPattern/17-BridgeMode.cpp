/**
 * 桥接模式：将抽象部分和实现部分分离，使它们可以独立的变化
*/

/**
 * 例子，现在根据需求，设计一个用于和客户端通信的 conn 类
 * 支持 TCP协议，并序列话 json 和 xml
 * 由于需求增加，需要支持 UDP 和 HTTP
 * 
 * 实现：
 *  
*/

#include<iostream>
using namespace std;

class Serializer
{
public:
    string Ser;
    virtual string getSerializer(){}
};

class XmlSerializer : public Serializer
{
public:
    XmlSerializer(){
        Ser="XML";
    }
    string getSerializer(){
        return Ser;
    }
};

class JsonSerializer : public Serializer
{
public:
    JsonSerializer(){
        Ser="JSON";
    }
    string getSerializer(){
        return Ser;
    }  
};

class Connect
{
public:
    string comm_protocol;
    string m_string_ser;
    void show(){
        cout << "support " << comm_protocol << "--" << m_string_ser << endl;
    }
};

class TCPConn : public Connect
{
public:
    TCPConn(Serializer* Ser){
        comm_protocol = "TCP";
        m_serializer = Ser;
        m_string_ser = m_serializer->getSerializer();
    }
private:
    Serializer* m_serializer;
};

class HTTPConn : public Connect
{
public:
    HTTPConn(Serializer* Ser){
        comm_protocol = "HTTP";
        m_serializer = Ser;
        m_string_ser = m_serializer->getSerializer();
    }
private:
    Serializer* m_serializer;    
};

int main()
{
    TCPConn* CTCPConn = new TCPConn(new JsonSerializer());
    CTCPConn->show();
    delete CTCPConn;

    HTTPConn* CHTTPConn = new HTTPConn(new XmlSerializer());
    CHTTPConn->show();
    delete CHTTPConn;
}

