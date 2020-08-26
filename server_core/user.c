#include<sys/socket.h>
#include<stdio.h>
#include<cjson/cJSON.h>
#include"../include/tool.h"
#include "../include/server.h"

//标识user是否登陆的一个全局变量，一般存储用户名
char userflag[256];


int usermain(char* operator,char* result)
{
    char username[256];
    char password[256];
    char nickname[256];
    char timebuffer[30];
    if(strcmp(operator,"login"))
    {        
        switch (login(username,password))
        {
        case 0:
            get_now_readable_time(timebuffer);
            sprintf(result,"<<<上线时间：%s>>>",timebuffer);
            break;
        case 1:
            sprintf(result,"<<<登陆失败!,用户名或密码错误>>>");
            break;
        case -1:
            sprintf(result,"<<<很抱歉,系统内部故障,请及时报告该问题>>>");
            break;
        default:
            break;
        }
    }
    else if (strcmp(operator,"logout"))
    {
        //logout();
    }
    else if(strcmp(operator,"registe"))
    {
        switch (registe(nickname,username,password))
        {
        case 0:
            get_now_readable_time(timebuffer);
            sprintf(result,"<<<注册成功时间：%s>>>",timebuffer);
            break;
        case 1:
            sprintf(result,"<<<注册失败!,已经存在该用户,请确保你的nickname和username都是独特>>>");
            break;
        case -1:
            sprintf(result,"<<<很抱歉,系统内部数据故障,请及时报告该问题>>>");
            break;
        default:
            break;
        }
    }
    else if(strcmp(operator,"listuser"))
    {
        list_online(result);
    }

    //交换数据
    return 0;
}
/*
 * @description 判断用户登陆所使用的用户名和密码
 * @param username 用户名 
 * @param password 密码
 * @return 0 登陆成功 -1 逻辑错误或数据库错误  1 密码不匹配
 */
int login(const char* username,const char* password)
{
    char query[512];
    MYSQL_RES* result = NULL;
    my_ulonglong row_num;
    MYSQL_ROW row;

    //加密在以后考虑
    sprintf(query,"select password from user where username=\'%s\' and password=\'%s\';",username,password);
    MYSQL mysql = getMysql();
    unsigned int ret = mysql_query(&mysql,query);
    if(mysql_errno(&mysql)!=0)
        return -1;
    if((result = mysql_store_result(&mysql))==NULL)
        return -1;
    row_num = mysql_num_rows(result);
    //当出现两个用户名显然不符合逻辑
    if((unsigned long )row_num!=1)
    {
        mysql_free_result(result);
        mysql_close(&mysql);
        if((unsigned long)row_num>0)
            return 1;
        else
            return -1;
    }
    bzero(query,sizeof(query));
    sprintf(query,"update user set status=1 where username=\'%s\'",username);
    mysql_query(&mysql,query);
    mysql_free_result(result);//释放result的内存
    mysql_close(&mysql);
    return 0;
}

/*
 * @description 用户注册，将用户的输入信息保存到数据库
 * @param nickname  昵称
 * @param username  用户名
 * @param password  密码
 * @return 0 注册成功 -1 系统插入错误   1 已存在和其相同用户名 已存在和其nickname相同的用户
 */
int registe(const char* nickname,const char* username,const char* password)
{
    char query[512];
    MYSQL_RES* result = NULL;
    my_ulonglong row_num;
    MYSQL_ROW row;
    MYSQL mysql = getMysql();
    sprintf(query,"select id from user where username='%s' or nickname='%s'",username,nickname);
    //printf("%s",query);
    mysql_query(&mysql,query);
    result = mysql_store_result(&mysql);
    row_num = mysql_num_rows(result);
    //如果已经存在该用户
    if(row_num!=0)
    {
        mysql_free_result(result);
        mysql_close(&mysql);
        return -1;
    }
    bzero(query,strlen(query));
    sprintf(query,"insert into user(username,password,nickname) values ('%s','%s','%s')",username,password,nickname);
    //printf("%s",query);
    mysql_query(&mysql,query);
    row_num = mysql_affected_rows(&mysql);
    if(row_num != 1)
    {
        mysql_free_result(result);
        mysql_close(&mysql);
        return -1;
    }
    mysql_free_result(result);
    mysql_close(&mysql);
    return 0;
}



/*
 * @description  列出在线的用户，
 * @param:
 * 
 * 
 * 
 */
int list_online(char* userlist)
{
    MYSQL mysql;
    MYSQL_RES * result=NULL;
    MYSQL_ROW row;
    //用1标识在线，用0来标识 下线，用-1来标识禁用
    char query[512]="select username from user_test where status =1";
    mysql = getMysql();
    mysql_query(&mysql,query);
    result = mysql_store_result(&mysql);
    while((row = mysql_fetch_row(result)))
    {
        strcat(userlist,"*");
        strcat(userlist,row[0]);
        strcat(userlist,"\n");
    }
    mysql_free_result(result);
    mysql_close(&mysql);
    return 0;
}


// int logout()
// {

//     return 0;
// }