#ifndef TOOL_H
#define TOOL_H

#define TRUE 1
#define FALSE 0

#include"../include/unp/unp.h"
/*
 *  @param  serveraddr  消息结构体
 *  @param  ip          字符串格式的ip
 *  @param  port        端口号
 *  @return   TRUE 设置成功 FALSE设置失败
 */
int setIPAddr(struct sockaddr_in * serveraddr, char *ip, int port);

#endif
