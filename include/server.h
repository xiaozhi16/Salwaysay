#ifndef SERVER_H
#define SERVER_H

/***********文件包含区域*****************/
#include"unp/unp.h"
#include<cjson/cJSON.h>


/*端口号或缓存区域*/
#define PORT 2019               //服务器端口号
#define MESSAGE_LENGTH 1024     //t_message中message的长度
#define BUFF_LENGH 2048         //缓存区大小

/*定义packet的第一个字段type*/
#define FILE 0                  //文件类型定义为0
#define MESSAGE 1               //消息类型定义为1
#define REPORT 2                //报告类型定义为2
#define ALIVE 3                 //心跳类型定义为3

typedef int t_socketfd;         //套接字类可视化转换  

struct t_packet{
    int type;           //消息的类型
    char operate[40];   //消息请求的服务器操作类型
    char from[40];      //消息的发送方
    char to [40];       //消息的接收方
    char content[1024];
};

/***********函数声明区域*************/
/*
 *@description 用于获取客户端的消息同时将报文解析并存放在reciveMessage报文结构体中
 *@param clientSocket   客户端socket
 *@param reciveMessage  接受的消息的报文结构体
 *@return TRUE成功  FALSE失败
*/
int getPacket(t_socketfd clientSocket,struct t_packet * recivePacket);   //获取消息的消息

int anlayzePacket(struct t_packet * recivePacket);                      //分析应用层协议消息


#endif