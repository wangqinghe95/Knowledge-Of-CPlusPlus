#include<iostream>
#include<poll.h>    //struct pollfd
#include<sys/socket.h>
#include<netinet/in.h>  //struct sockaddr_in
#include<cstring>
#include<unistd.h>  //close
#include<arpa/inet.h>
// #include<sys/types.h>

using namespace std;

#define OPEN_MAX 1024
#define SERVER_PORT 8888
#define MAXLINE 80

int main(){

    struct pollfd client[OPEN_MAX];
    struct sockaddr_in server_addr, client_addr;

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(listen_fd, 10);

    client[0].fd = listen_fd;
    client[0].events = POLLRDNORM;

    for (int i = 1; i < OPEN_MAX; ++i){
        client[i].fd = -1;
    }

    int maxi = 0;   //poll 的第一个参数，表示监听的最大的文件描述符+1
    int nReady = 0;

    while (1)
    {
        nReady = poll(client, maxi+1, -1);

        //有客户端请求连接
        if (client[0].revents & POLLRDNORM){
            char str[INET_ADDRSTRLEN] = {0};
            socklen_t client_len = sizeof(client_addr);
            int connect_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);
            printf("received from %s at PORT %d\n",
                    inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)),
                    ntohs(client_addr.sin_port));

            for(int i = 1; i <= OPEN_MAX; ++i){
                if (client[i].fd < 0){
                    cout << "111" << endl;
                    if (i == OPEN_MAX){
                        cout << "Too many client requery" << endl;
                        close(listen_fd);
                        return -1;
                    }
                    client[i].fd = connect_fd;  //在链表中找到第一个未使用的结构体，给最新的连接使用；
                    client[i].events = POLLRDNORM;
                    maxi = maxi > i ? maxi : i;
                    cout << "client[i].fd = " << client[i].fd << endl;
                    cout << "maxi = " << maxi << endl;
                    break;
                }
            }

            if (--nReady <= 0){
                continue;
            }
        }

        for (int i = 1; i <= maxi; ++i){
            int sockfd = client[i].fd;
            if (sockfd < 0){
                continue;
            }

            if(client[i].revents & (POLLRDNORM | POLLERR)){
                char buf[MAXLINE] = {0};
                int read_ret = read(sockfd, buf, MAXLINE);
                if (0 == read_ret){
                    close(sockfd);
                    client[i].fd = -1;
                }
                else if (0 > read_ret)
                {
                     cout << "error when server read from client" << endl;
                     close(sockfd);
                     return -1;
                }
                else
                {
                    cout << "data from client" << buf;
                    for(int j = 0; j < read_ret; ++j){
                        buf[j] = toupper(buf[j]);
                    }
                    cout << "data send to client" << buf;
                    send(sockfd, buf, strlen(buf)+1, 0);
                }               
                
            }
        }
    }
    
    close(listen_fd);
    return 0;
}