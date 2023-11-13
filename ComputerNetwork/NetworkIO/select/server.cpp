#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/select.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<cstring>
#include<vector>

using namespace std;

#define MAXLINE 80
#define SERV_PORT 6666

int main(){

    char buf[MAXLINE] = {0};
    char str[INET_ADDRSTRLEN] = {0};

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);    //监听的文件描述符
    int connect_fd;
    struct sockaddr_in server_addr, client_addr;
    // vector<struct sockaddr_in> sock_addr ;   //问题1
    struct sockaddr_in sock_addr[FD_SETSIZE];
    memset(sock_addr, 0, sizeof(sock_addr));
    
    socklen_t client_len;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    if(bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        cout << "bind error" << endl;
        close(listen_fd);
        return -1;
    }

    listen(listen_fd, 20);

    cout << "Accepting connection ... " << endl;

    fd_set read_set;
    fd_set test_set;
    FD_ZERO(&read_set);
    FD_SET(listen_fd, &read_set);
    
    while (true)
    {
        int nRead = 0;
        test_set = read_set;
        int ret = select(FD_SETSIZE, &test_set, NULL,NULL,NULL);
        if (ret < 0){
            cout << "select error" << endl;
            close(listen_fd);
            return -1;
        }
        else if (0 == ret){
            continue;
        }
        else
        {
            for(int fd = 0; fd < FD_SETSIZE; ++fd){                
                if(FD_ISSET(fd, &test_set)){
                    if (fd == listen_fd){
                        client_len = sizeof(client_addr);
                        // int sock = accept(listen_fd, NULL, NULL);
                        int sock = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);
                        if (sock < 0){
                            printf("Received from %s at PORT %d error\n",
                                    inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)),
                                    ntohs(client_addr.sin_port));
                            close(listen_fd);
                            FD_CLR(listen_fd,&read_set);
                        }
                        else
                        {
                            // cout << "111" << endl;
                            sock_addr[sock] = client_addr;
                            // cout << "sock" << sock << endl;
                            FD_SET(sock,&read_set);
                            printf("Received from %s at PORT %d success\n",
                                    inet_ntop(AF_INET, &client_addr.sin_addr, str, sizeof(str)),
                                    ntohs(client_addr.sin_port));
                            cout << "222" << endl;
                        }                      

                    }
                    else
                    {
                        memset(buf, 0, sizeof(buf));
                        memset(str, 0, sizeof(str));
                        nRead = read(fd, buf, MAXLINE);
                        sockaddr_in temp_addr = sock_addr[fd];
                        if (nRead == 0){
                            close(fd);
                            FD_CLR(fd, &read_set);
                            printf("client %s at PORT %d removed",
                                    inet_ntop(AF_INET, &temp_addr.sin_addr, str, sizeof(str)),
                                    ntohs(temp_addr.sin_port),
                                    buf);
                            memset(sock_addr+fd, 0 , sizeof(sock_addr[0]));   //问题2                       
                        }
                        else
                        {
                            printf("Data from %s at PORT %d : %s",
                                    inet_ntop(AF_INET, &temp_addr.sin_addr, str, sizeof(str)),
                                    ntohs(temp_addr.sin_port),
                                    buf);                           
                            // cout << "Data recv from client: " << buf ; //buf 自带了换行符
                            for(int j = 0; j < nRead; ++j){
                                buf[j] = toupper(buf[j]);
                            }
                            // cout << "Data send to client: " << buf; 
                            printf("Data send to %s at PORT %d : %s",
                                    inet_ntop(AF_INET, &temp_addr.sin_addr, str, sizeof(str)),
                                    ntohs(temp_addr.sin_port),
                                    buf); 
                            send(fd, buf, strlen(buf)+1, 0);
                        }                        
                    }                    
                }
            }
        }        
    }
    close(listen_fd);
    return 0;    
}