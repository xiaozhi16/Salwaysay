#ifndef CLIENT_H
#define CLIENT_H

#include<stdio.h>
#include<sys/socket.h>

#include "cjson/cJSON.h"
#include "tool.h"
#include "unp/unp.h"

/**********************input部分**************************/
int getString(char* tips,char* data);
int getInt(char * tips,int* data);


/*********************network部分***********************/
static int INIT_FLAG = 0;       //初始化标志

int network_init();

int getSocket();
//给sockfd发送数据
int send(char* data,int sockfd);
//从sockfd接收数据
int recive(char* data,int sockfd);

int network_close();

/*********************user部分*************************/
int usermain(char * op);
int login();
#endif


