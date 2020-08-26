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
MYSQL getMysql();
void find(const char* table,const char* column,const char* where);
int update(const char* table,const char* column,const char* newData,const char * where);
int insert(const char* table,const char* column,char* type);
int delete(const char* table,const char* column,char * where);


/*****log模块******/
#define ERROR 3
#define WARNING 4
#define INFO 5
void log_to_file(int level , const char * message);
void log_more_info(int level,const char * message,const char* postion);
void log_to_console(int level,const char * message);

/*****time模块*******/
int get_now_readable_time(char * timeBuffer);
#endif
