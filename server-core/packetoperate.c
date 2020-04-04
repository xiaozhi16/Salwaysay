#include<sys/socket.h>
#include<stdio.h>
#include"tools/tool.h"
#include "include/server.h"
#include<cjson/cJSON.h>

/*
 *@description 从套接口获取报文，并将报文放置到recivePacket结构体中，用于下一步的分析
 *@param    clientSocket接收到的客户端套接字 
 *@param    recivePacket本地接收报文的结构体 
 *@return   TRUE成功 FALSE失败
 */
int getPacket(t_socketfd clientSocket,struct t_packet * recivePacket)
{
    cJSON* root = NULL;
    cJSON* type = NULL;
    cJSON* operate = NULL;
    cJSON* message = NULL;
    char buff[2048];    //缓存区
    int size = 0;       //实际读到的字节个数
    bzero(recivePacket,sizeof(*recivePacket));
    size = Read(clientSocket,buff,BUFF_LENGH);
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
        recivePacket->type = type->valueint;
        strcpy(recivePacket->operate,operate->valuestring);
        strcpy(recivePacket->message,message->valuestring);
        cJSON_Delete(root);
    }
    return TRUE;
}


int anlayzePacket(struct t_packet * recivePacket)
{
    switch (recivePacket->type)
    {
    case FILE:
        
        break;
    case MESSAGE:
    
        break;
    default:
        break;
    }
    return TRUE;
}