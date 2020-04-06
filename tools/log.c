#include<cjson/cJSON.h>
#include"tool.h"
#include<string.h>
#include<stdio.h>
#include<time.h>
static char format[15]="[%s]<%s>:%s\n";
static char timeFormat[20]="%Y-%m-%d %H:%M:%S";
static char filepath[30]="/root/alwaysay/logs/system.log";
void Log(const char* level , const char * message)
{
    time_t timer;
    time(&timer);
    char timebuffer[30];
    FILE* logfile = fopen(filepath,"a");
    if(logfile ==NULL)
    {
        printf("没了");
    }
    //格式化时间
    strftime(timebuffer, 80, timeFormat , gmtime(&timer));
    //判断log级别
    if(strcmp(level,"ERROR")==0)
    {
        char errorFormat[30];
        sprintf(errorFormat,"\033[40;31m%s\033[0m",format);
        printf(errorFormat,timebuffer,"ERROR",message);
        fprintf(logfile,format,timebuffer,"ERROR",message);
    }
    else if(strcmp(level,"WARNING")==0)
    {
        char warningFormat[30];
        sprintf(warningFormat,"\033[40;33m%s\033[0m",format);
        printf(warningFormat,timebuffer,"WARNING",message);
        fprintf(logfile,format,timebuffer,"WARNING",message);
    }
    else if(strcmp(level,"INFO")==0)
    {
        printf(format,timebuffer,"INFO",message);
        fprintf(logfile,format,timebuffer,"INFO",message);
    }
    fclose(logfile);
}