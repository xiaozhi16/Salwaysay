#ifndef SERVER_H
#define SERVER_H


#include "public.h"
/***********文件包含区域*****************/
#include"unp/unp.h"
#include "cjson/cJSON.h"


/*端口号或缓存区域*/
#define PORT 2019               //服务器端口号
#define MESSAGE_LENGTH 1024     //t_message中message的长度
#define BUFF_LENGH 2048         //缓存区大小

/*定义packet的第一个字段type*/


/***********函数声明区域*************/
/*
 *@description 用于获取客户端的消息同时将报文解析并存放在reciveMessage报文结构体中
 *@param clientSocket   客户端socket
 *@param reciveMessage  接受的消息的报文结构体
 *@return TRUE成功  FALSE失败
*/
int getPacket(t_socketfd clientSocket,struct t_packet * recivePacket);   //获取消息的消息

int anlayzePacket(struct t_packet * recivePacket);                      //分析应用层协议消息



/***********network.c**************/
static int INIT_FLAG = 0;



/***********user.c*****************/

int login(const char* username,const char* password);
/*
 * @description 用户注册，将用户的输入信息保存到数据库
 * @param nickname  昵称
 * @param username  用户名
 * @param password  密码
 * @return 0 注册成功 -1 系统插入错误   1 已存在和其相同用户名 已存在和其nickname相同的用户
 */
int registe(const char* nickname,const char* username,const char* password);

int list_online(char* userlist);
#endif