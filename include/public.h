#ifndef PUBLIC_H
#define PUBLIC_H

#define FILETYPE 0                  //文件类型定义为0
#define MESSAGE 1               //消息类型定义为1
#define REPORT 2                //报告类型定义为2
#define ALIVE 3                 //心跳类型定义为3
#define USER 4                   //用户操作
typedef int t_socketfd;         //套接字类可视化转换  

struct t_packet{
    int type;           //消息的类型
    char operate[40];   //消息请求的服务器操作类型
    char username[64];  //用户名字段
    char password[64];  //密码字段
    char from[40];      //消息的发送方
    char to[40];       //消息的接收方
    char content[1024];
};


#endif