#include "include/client.h"

int main(int argc,char ** argv)
{
    struct sockaddr_in servaddr;

    if(argc < 2)
    {
        Log_to_file(ERROR,"usage:./client <IPaddress>","client.c");
    }
    
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(SERV_PORT);
    Inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

    return 0;
}