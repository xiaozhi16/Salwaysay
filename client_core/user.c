#include<stdio.h>

#include "../include/client.h"
#include "../include/public.h"
extern char username[32];
extern char userlist[64][64];


int usermain(char * op)
{
    if(strcmp(op,"login"))
    {
        login();
    }
    else if(strcmp(op,"list_online"))
    {
        list_online(userlist);
    }
    else if(strcmp(op,"logout"))
    {
        logout();

    }
    else if(strcmp(op,""))
    return 0;
}

int list_online(char* userlist)
{
    //构建数据包
    
    return 0;
}


int login()
{
    char username[64];//用户名
    char password[64];//密码
    char* result;     //数据包字符串
    cJSON* packet;      //数据包json结构
    getString("请输入用户名(长度不能超过40个):",username);
    getString("请输入密码(长度不能超过40个):",password);
    packet = cJSON_CreateObject();
    cJSON_AddNumberToObject(packet,"type",USER);
    cJSON_AddStringToObject(packet,"operate","login");
    cJSON_AddStringToObject(packet,"username",username);
    cJSON_AddStringToObject(packet,"password",password);
    cJSON_AddStringToObject(packet,"from",username);
    cJSON_AddStringToObject(packet,"to","");
    cJSON_AddStringToObject(packet,"content","");
    result = cJSON_Print(packet);
    int sockfd = getSocket();
    writen(sockfd,result,sizeof(result));
    cJSON_free(result);
    cJSON_Delete(packet);
    result = (char *)malloc(65526*sizeof(char));
    recive(result,sockfd);
    printf("");
    free(result);

    //交换数据
    //打印结果
    return 0;
}

int list_friend()
{
    cJSON* packet;
    cJSON_AddNumberToObject(packet,"type",USER);
    cJSON_AddStringToObject(packet,"operate","listfriend");
    cJSON_AddStringToObject(packet,"username",username);
    cJSON_AddStringToObject(packet,"password","");
    cJSON_AddStringToObject(packet,"from",username);
    cJSON_AddStringToObject(packet,"to","");
    cJSON_AddStringToObject(packet,"content","");
    //交换数据switchdata();
    //打印数据
    return 0;
}

int registerity()
{
    char username[64];//用户名
    char password[64];//密码
    char nickname[64];//昵称
    char* result;     //数据包字符串
    cJSON* packet;      //数据包json结构
    getString("请输入用户名(长度不能超过40个):",username);
    getString("请输入密码(长度不能超过40个):",password);
    getString("请输入昵称(长度不能超过40个)",nickname);
    packet = cJSON_CreateObject();
    cJSON_AddNumberToObject(packet,"type",USER);
    cJSON_AddStringToObject(packet,"operate","register");
    cJSON_AddStringToObject(packet,"username",username);
    cJSON_AddStringToObject(packet,"password",password);
    cJSON_AddStringToObject(packet,"from",username);
    cJSON_AddStringToObject(packet,"to","");
    cJSON_AddStringToObject(packet,"content",nickname);
    result = cJSON_Print(packet);
    printf("%s",result);
    //int sockfd = getSocket();
    //writen(sockfd,result,sizeof(result));
    cJSON_free(result);
    cJSON_Delete(packet);
    //result = (char *)malloc(65526*sizeof(char));
    //recive(result,sockfd);
    printf("");
    //free(result);
    //交换数据
    //打印结果
    return 0;
}

int delete_friend()
{

    return 0;
}

int logout()
{

    return 0;
}