#include "../include/client.h"
#include <stdio.h>

int getString(char* tips,char* data)
{
    printf("%s",tips);
    scanf("%s",data);
    return 0;
}

int getInt(char* tips, int * data)
{
    printf("%s",tips);
    scanf("%d",data);
    return 0;
} 
