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
    cJSON* from = NULL;
    cJSON* to   = NULL;
    cJSON* operate = NULL;
    cJSON* content = NULL;
    char buff[2048];    //缓存区
    int size = 0;       //实际读到的字节个数
    bzero(recivePacket,sizeof(*recivePacket));
    size = Read(clientSocket,buff,BUFF_LENGH);
    root = cJSON_Parse(buff);
    type = cJSON_GetObjectItem(root,"type");                //获取type报文类型
    from = cJSON_GetObjectItem(root,"from");
    to   = cJSON_GetObjectItem(root,"to");
    operate = cJSON_GetObjectItem(root,"operate");          //获取operator类型
    content = cJSON_GetObjectItem(root,"content");   //获取content 
    if(root==NULL || type==NULL || operate == NULL || content==NULL || from==NULL || to==NULL)
    {
        printf("报文格式无效!");
        return FALSE;
    }
    else
    {
        recivePacket->type = type->valueint;
        strcpy(recivePacket->from , from->valuestring);
        strcpy(recivePacket->to,to->valuestring);
        strcpy(recivePacket->operate,operate->valuestring);
        strcpy(recivePacket->content,content->valuestring);
        cJSON_Delete(root);
    }
    return TRUE;
}



int anlayzePacket(struct t_packet * recivePacket)
{
    switch (recivePacket->type)
    {
    case FILE:
        fileSend();
        break;
    case MESSAGE:
        contentSend();
        break;
    case REPORT:

        break;
    case ALIVE:
        keepAlive();
        break;
    default:
        break;
    }
    return TRUE;
}