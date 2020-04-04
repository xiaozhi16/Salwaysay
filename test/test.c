#include<sys/socket.h>
#include<stdio.h>
#include"../tools/tool.h"
#include "../include/server.h"
#include<cjson/cJSON.h>

int getTestMessage(char * buff,struct t_message * reciveMessage)
{
    cJSON* root = NULL;
    cJSON* type = NULL;
    cJSON* operate = NULL;
    cJSON* message = NULL;
    int size = 0;       //实际读到的字节个数
    root = cJSON_Parse(buff);
    type = cJSON_GetObjectItem(root,"type");                //获取type报文类型
    operate = cJSON_GetObjectItem(root,"operate");          //获取operator类型
    message = cJSON_GetObjectItem(root,"message");   //获取message 
    if(root==NULL || type==NULL || operate == NULL || message==NULL)
    {
        printf("报文格式无效!");
        return FALSE;
    }
    else
    {
        reciveMessage->type = type->valueint;
        strcpy(reciveMessage->operate,operate->valuestring);
        strcpy(reciveMessage->message,message->valuestring);
        printf("type是%d\n操作是%s\n消息是%s\n",reciveMessage->type,reciveMessage->operate,reciveMessage->message);
        cJSON_Delete(root);
        reciveMessage->type = type->valueint;
    }
    return TRUE;
}

int main()
{
    struct t_message reciveMessage; //接收报文缓冲结构体
    char buff[2048]="{\"type\":\"0\",\"operate\":\"send\",\"message\":\"hello 你好\"}" ;    //缓存区
    getTestMessage(buff,&reciveMessage);
    return 0;
}