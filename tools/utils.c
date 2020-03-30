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
