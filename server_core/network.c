#include "../include/server.h"
#define SERV_PORT 2013
#define SERV_ADDR INADDR_ANY

extern int clientfd=-1;
static struct sockaddr_in servaddr;

int network_init()
{
    setSockfd();    
    if(setServAddr(SERV_ADDR,SERV_PORT)<0)
        return -1;
    Connect(clientfd,(SA*)&servaddr,sizeof(servaddr));
    INIT_FLAG = 1;       //设置网络初始化标志
    return clientfd;
}

int setServAddr(char * present, int port)
{
    servaddr.sin_port = htons(port);
    servaddr.sin_family = AF_INET;
    Inet_pton(AF_INET,present,&(servaddr.sin_addr));
    return 1;
}
int setSockfd()
{
    if(clientfd = -1)
    {
        clientfd = Socket(AF_INET,SOCK_STREAM,0);
        return 0;
    }
    //已被初始化
    return -1;
}

int getSocket()
{
    if(INIT_FLAG==0)
    {
        network_init();
    }
    return clientfd;

}

//向服务器发送数据
int send(char* data,int sockfd)
{
    if(sockfd==0)
    {
        return -1;
    }
    Writen(sockfd,data,sizeof(data));
    return 0;
}

//向服务器接收数据
int recive(char* data,int sockfd)
{
    int sizerecv;
    char recvline[MAXLINE];
    if(sockfd==0)
    {
        return -1;
    }
    while((sizerecv=Readn(sockfd,recvline,MAXLINE))!=0)
    {
        strcat(data,recvline);
    }
    return 0;
}


int network_close()
{
    if(clientfd==0)
    {
        return -1;
    }
    close(clientfd);
    return 0;
}