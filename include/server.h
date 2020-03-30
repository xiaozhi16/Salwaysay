#ifndef SERVER_H
#define SERVER_H

//声明类型和宏定义
#define PORT 2019
typedef int t_socketfd;  //套接字类可视化转换  

//包含文件begin
#include"unp/unp.h"


//声明函数section
void getMessage();      //获取服务端的消息


#endif