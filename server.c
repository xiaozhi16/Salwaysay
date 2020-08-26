#include<sys/socket.h>
#include<stdio.h>
#include"include/tool.h"
#include "include/server.h"
#include<cjson/cJSON.h>


int main()
{
    t_socketfd serverSocket=0;      //服务端套接字变量
    t_socketfd clientSocket=0;      //客户端套接字变量
    struct sockaddr_in serveraddr;  //服务器地址结构体
    struct t_packet recivePacket; //接收报文缓冲结构体
    socklen_t socklenth = 0;
    pid_t pid = 0;                                            
    
    //系统初始化

    
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
            getPacket(clientSocket,&recivePacket);                  //解析消息到消息结构体
            anlayzePacket(&recivePacket);                           //分析消息中所带的协议
                                                                    //依照分析然后给予响应的回应
            Close(serverSocket);
        }
    }
    return 0;
}