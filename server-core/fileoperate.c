#include<sys/socket.h>
#include<stdio.h>
#include<cjson/cJSON.h>
#include"../tools/tool.h"
#include "../include/server.h"


void filerecv(){

    
}

void filesend(struct t_packet * recivePacket)
{
    char* root = cJSON_Parse(recivePacket->content);
    

}