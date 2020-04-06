#ifndef TOOL_H
#define TOOL_H

#define TRUE 1
#define FALSE 0

#include"../include/unp/unp.h"
#include<mysql/mysql.h>
/*
 *  @param  serveraddr  消息结构体
 *  @param  ip          字符串格式的ip
 *  @param  port        端口号
 *  @return   TRUE 设置成功 FALSE设置失败
 */
int setIPAddr(struct sockaddr_in * serveraddr, char *ip, int port);
//获取mysql可以操作的额参数
MYSQL connectToMysql();

/*****log模块******/
void Log(const char* level , const char * message);
#endif
