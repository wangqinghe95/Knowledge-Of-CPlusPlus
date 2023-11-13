#include<iostream>
#include<string>
#include<cstring>
#include<unistd.h>
#include<cstdlib>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
using namespace std;

#define MAXLINE 80
#define SERV_PORT 8888

int main(int argc, char* argv[]){
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        write(sockfd, buf, strlen(buf));
        n = read(sockfd, buf, MAXLINE);
        if (n == 0)
        {
            printf("the other side has been closed.\n");
        }
        else
        {
           write(STDOUT_FILENO, buf, n);
        }
    }
    close(sockfd);
    return 0;
}