#include<sys/socket.h>
#include<stdio.h>
#include"../tools/tool.h"
#include "../include/server.h"
#include<cjson/cJSON.h>
#include<mysql/mysql.h>
MYSQL connectToMysql()
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql,"127.0.0.1","MRx16","dpk176921","alwaysay",3306,NULL,0);
    mysql_set_character_set(&mysql,"utf8");
    unsigned int errNo = mysql_errno(&mysql);
    if(errNo==0)
    {

    }
    else
    {
        printf("mysql error:[%d]:%s",errNo,mysql_error(&mysql));
    }
    return mysql;
}

int update(MYSQL* mysql,const char* table,const char* column,const char* newData,const char * where)
{
    char query[2048];
    sprintf(query,"update %s set %s=%s where %s;",table,column,newData,where);
    printf("%s",query);
    return 0;
}

int main()
{
    // MYSQL mysql = connectToMysql();
    // update(&mysql,"test","username","\'mrx\'","username=\'dpkadmin\'");
    // mysql_close(&mysql);
    //Log("error","this is a error");
    Log("INFO","this is a info");
    Log("ERROR","this is a error");
    Log("WARNING","this is a warning");
    return 0;
}