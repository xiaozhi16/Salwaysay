#include<sys/socket.h>
#include<stdio.h>
#include"tools/tool.h"
#include "include/server.h"

void init();                //初始化运行环境

void anlayzeMessage();      //分析应用层协议

t_socketfd getConnect();

int main()
{
    t_socketfd serverSocket=0;      //服务端套接字变量
    t_socketfd clientSocket=0;      //客户端套接字变量
    struct sockaddr_in serveraddr;  //服务器地址结构体
    socklen_t socklenth = 0;
    pid_t pid = 0;                                            
    
    //首先套接字绑定
    setIPAddr(&serveraddr,"all",PORT);
    serverSocket = Socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    Bind(serverSocket,(SA *)&serveraddr,sizeof(serveraddr));
    Listen(serverSocket,LISTENQ);
    socklenth = sizeof(serveraddr);
    //循环处理请求
    for( ; ; )
    {
        
        clientSocket = Accept(serverSocket,(SA *)&serveraddr,&socklenth);
        pid = Fork();
        if(pid==0)
        {
            Close(serverSocket);
            Close(serverSocket);
        }

    }
    return 0;
}

void init()
{
    printf("this is init\n");
}

void anlayzeMessage()
{

}

t_socketfd getConnect()
{
    return 0;
}