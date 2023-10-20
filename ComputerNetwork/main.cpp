#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include<string>
#include<cstring>
#include<cstdlib>
#include<arpa/inet.h>
#include<netdb.h>
#include <errno.h>
using namespace std;

#define MAXLINE 80
#define SERV_PORT 80
// const char* IP_ADDRESS = "202.89.233.100";

const char HOSTNAME[256] = "www.bing.com";

int getIPAddressFromHostname(const char* p_hostname, char* p_out_address)
{

    addrinfo hits, *res;
    memset(&hits, 0, sizeof(hits));

    hits.ai_family = AF_UNSPEC;
    hits.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(p_hostname, NULL, &hits, &res);

    if(status != 0) {
        fprintf(stderr, "getaddinfo: %s\n", gai_strerror(status));
        return -1;
    }
    
    printf("IP address for %s: \n\n", p_hostname);

    for(addrinfo* p = res; p != NULL; p = p->ai_next) {
        void *addr;
        char ip_address[INET6_ADDRSTRLEN];
        if(p->ai_family == AF_INET){
            sockaddr_in *ipv4 = (sockaddr_in*)p->ai_addr;
            addr = &(ipv4->sin_addr);
        }
        else {
            sockaddr_in6 *ipv6 = (sockaddr_in6*)p->ai_addr;
            addr = &(ipv6->sin6_addr);
        }

        inet_ntop(p->ai_family, addr, ip_address, sizeof(ip_address));
        // printf("%s\n", ip_address);

        static bool b_copy = false;
        if(!b_copy){
            strncpy(p_out_address, ip_address, sizeof(ip_address));
            b_copy = true;
        }
        // break;
    }

    freeaddrinfo(res);

    if(p_out_address != NULL) {
        return 0;
    }

    return -1;
}

int set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        return -1;
    }
    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        return -1;
    }
    return 0;
}

int connectTCP(const char* p_in_IPAddress)
{
# if 1
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, p_in_IPAddress, &servaddr.sin_addr);
    servaddr.sin_port = htons(SERV_PORT);

    int ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
#else

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERV_PORT);
    addr.sin_addr.s_addr = inet_addr(IP_ADDRESS);

    if (set_nonblocking(sockfd) == -1) {
        perror("set_nonblocking");
        return -1;
    }

    int ret = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    
    
#endif
    if (ret == -1) {
        perror("connect");
        return -1;
    }
    else {
        printf("connect successfully\n");
    }

    char send_buf[1024] = {0};
    sprintf(send_buf, "GET / HTTP/1.1\r\nHost: cn.bing.com\r\n\r\n");
    // sprintf(send_buf, "GET / HTTP/2\r\nHost: cn.bing.com\r\nUser-Agent: curl/7.58.0\r\nAccept: */*");

    printf("send IP:%s, data:\n%s\n",p_in_IPAddress,send_buf);
    
    // write(sockfd, send_buf, strlen(send_buf));
    send(sockfd, send_buf,  strlen(send_buf), 0);

    char *recv_buf = (char*)malloc(sizeof(char)*8192);
    int recv_len = recv(sockfd, recv_buf, 8191, 0);
    // int read_len = read(sockfd, recv_buf, 8191);
    recv_buf[8192] = '\0';
    printf("read byte:%d\n", recv_len);
    printf("read data = %s\n", recv_buf);
    // while(read_len != 0){
    //     printf("read byte:%d\n", read_len);
    //     write(STDOUT_FILENO, recv_buf, 8192);
    //     memset(recv_buf, 0, sizeof(recv_buf));
    //     read_len = read(sockfd, recv_buf, 8192);
    // }
/*
    fd_set write_fds;
    FD_ZERO(&write_fds);
    FD_SET(sockfd, &write_fds);

    struct timeval timeout;
    timeout.tv_sec = 5; // 设置超时时间为 5 秒
    timeout.tv_usec = 0;

    ret = select(sockfd + 1, NULL, &write_fds, NULL, &timeout);
    printf("select successfully\n");
    if (ret == -1) {
        perror("select");
        return -1;
    } else if (ret == 0) {
        printf("connect timeout\n");
        return -1;
    } else {
        int error = 0;
        socklen_t len = sizeof(error);
        getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len);
        if (error != 0) {
            printf("connect failed: %s\n", strerror(error));
            return -1;
        }
        printf("connect success\n");
        // 在这里可以进行数据传输
        close(sockfd);
        return 0;
    }
*/

/*
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
*/
    close(sockfd);  
}

int main(int argc, char* argv[]){

    char ip_address[INET6_ADDRSTRLEN] = {0};
    if(getIPAddressFromHostname(HOSTNAME, ip_address) == 0){
        printf("Get IP address successfully ：%s\n", ip_address);
    }
    else{
        printf("Get IP address error\n");
    }

    connectTCP(ip_address);

/*
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    int sockfd, n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, "", &servaddr.sin_addr);
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
*/
    return 0;
}