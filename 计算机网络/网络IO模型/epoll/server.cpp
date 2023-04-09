#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/epoll.h>
#include<cstring>   //bzero
#include<unistd.h>
#include<arpa/inet.h>   //inet_ntop

using namespace std;

#define SERVER_PORT 9999
#define OPEN_MAX 1024
#define MAXLINE 80

int main(){

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr, client_addr;    //前者是绑定服务器本身的ip地址，后者是客户端连接地址
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(listen_fd, 20);

    struct epoll_event tep, ep[OPEN_MAX];
    int client[OPEN_MAX];
    for(int i = 0; i < OPEN_MAX; ++i){
        client[i] = -1;
    }

    int maxi = -1;  //最大的文件描述符

    int efd = epoll_create(OPEN_MAX);
    if (-1 == efd){
        cout << "epoll_create error" << endl;
        close(listen_fd);
        exit(-1);
    }

    tep.events = EPOLLIN;
    tep.data.fd = listen_fd;

    //把要监听的文件描述符（listen_fd）添加（EPOLL_CTL_ADD）到 epoll 创建的句柄中（efd），并指出监听方式（读监听，写监听，...）
    int res = epoll_ctl(efd, EPOLL_CTL_ADD, listen_fd, &tep);
    if (-1 == res){
        cout << "epoll_ctl error" << endl;
        close(listen_fd);
        exit(-1);        
    }

    while (1)
    {
        int nReady = epoll_wait(efd, ep, OPEN_MAX, -1);
        if (-1 == nReady){
            cout << "epoll_wait error" << endl;
            close(listen_fd);
            exit(-1);            
        }
        
        for (int i = 0; i < nReady; ++i){
            if (!(ep[i].events & EPOLLIN)){     //只找读事件的
                continue;
            }
            if (ep[i].data.fd == listen_fd){    //有客户端的连接请求
                char str[INET_ADDRSTRLEN];
                socklen_t client_len = sizeof(client_addr);
                int connect_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);
                // cout << "Receive From " << inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str))
                //     << " at Port " << ntohs(client_addr.sin_port) << endl;
                printf("received from %s at PORT %d\n",
                        inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)),
                        ntohs(client_addr.sin_port));                
                for (int j = 0; j <= OPEN_MAX; ++j){
                    if (client[j] < 0){
                        if (j == OPEN_MAX){
                            cout << "Too many clients" << endl;
                            close(listen_fd);
                            exit(-1);
                        }
                        client[j] = connect_fd;
                        maxi = maxi > j ? maxi : j;
                    }
                }

                tep.events = EPOLLIN;
                tep.data.fd = connect_fd;

                res = epoll_ctl(efd, EPOLL_CTL_ADD, connect_fd, &tep);
                if (-1 == res){
                    cout << "epoll_ctl_add error" << endl;
                    exit(-1);
                }                
            }
            else    //和客户端通信
            {
                char buf[MAXLINE] = {0};
                int sock_fd = ep[i].data.fd;
                int n_read = read(sock_fd, buf, MAXLINE);
                if (0 == n_read){
                    for(int j = 0; j <= maxi; ++j){
                        if (client[j] == sock_fd){
                            client[j] = -1;
                            break;
                        }
                    }

                    res = epoll_ctl(efd, EPOLL_CTL_DEL, sock_fd, NULL);
                    if (-1 == res){
                        cout << "epoll_ctl_del error" << endl;
                        exit(-1);                        
                    }
                    close(sock_fd);
                    cout << "client close connection" << endl;
                }
                else
                {
                    for (int j = 0; j < n_read; ++j){
                        buf[j] = toupper(buf[j]);
                    }
                    write(sock_fd, buf, n_read);
                }
                
            }
            
        }
    }

    close(listen_fd);
    close(efd);
    return 0;    
}