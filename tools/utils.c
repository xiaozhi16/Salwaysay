#include<sys/socket.h>
#include<cjson/cJSON.h>
#include "tool.h"
#include<string.h>
#include<stdio.h>
int setIPAddr(struct sockaddr_in * serveraddr,char *ip,int port)
{
    //init
    bzero(serveraddr,sizeof(*serveraddr));
    (*serveraddr).sin_family= AF_INET;
    (*serveraddr).sin_port  = htons(port);
    if(strcmp(ip,"all")==0)
    {
	    (*serveraddr).sin_addr.s_addr = htonl(INADDR_ANY);
    }
    else
    {
    	Inet_pton(AF_INET,ip,&(*serveraddr).sin_addr);
    }
    printf("========地址给予完毕=======\n");
    return TRUE;
}

MYSQL connectToMysql()
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql,"127.0.0.1","MRx16","dpk176921","alwaysay",3306,NULL,0);
    mysql_set_character_set(&mysql,"utf8");
    unsigned int errNo = mysql_errno(&mysql);
    if(errNo==0)
    {
        printf("[%s]连接成功!");
    }
    else
    {
        printf("mysql error:[%d]:%s",errNo,mysql_error(&mysql));
    }
    return mysql;
}

void find(const char* table,const char* column,const char* where)
{
    MYSQL mysql = connectToMysql();
    char query[2048];
    sprintf(query,"select %s from %s where %s",column,table,where);
    mysql_close(&mysql);
}

int update(const char* table,const char* column,const char* newData,const char * where)
{
    MYSQL mysql = connectToMysql();
    char query[2048];
    sprintf(query,"update %s set %s=%s where %s",table,column,newData,where);
    printf("%s",query);
    mysql_close(&mysql);
    return 0;
}

int insert(const char* table,const char* column,char* type)
{
    MYSQL mysql = connectToMysql();
    mysql_close(&mysql);
    return 0;
}