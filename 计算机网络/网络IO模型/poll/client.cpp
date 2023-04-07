#include<iostream>
#include<cstring>
#include<netinet/in.h>  //struct sockaddr_in
#include<arpa/inet.h>   //inet_pton
#include<unistd.h>  //write
using namespace std;

#define SERVER_PORT 8888
#define SERVER_IP "127.0.0.1"
#define MAXLINE 80

using namespace std;

int main(){
    struct sockaddr_in server_addr;
    int connect_fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    int connect_ret = connect(connect_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (connect_ret < 0){
        cout << "connect_ret error " << endl;
        return -1;
    }

    char buf[MAXLINE] = {0};    //发给服务端的数据
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        write(connect_fd, buf, strlen(buf));
        int n_read = read(connect_fd, buf, MAXLINE);
        if (0 == n_read){
            cout << "The server is closed" << endl;
            break;
        }
        else
        {
            write(STDOUT_FILENO, buf, n_read);
        }        
    }
    
    close(connect_fd);
    return 0;
}