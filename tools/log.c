#include<cjson/cJSON.h>
#include"../include/tool.h"
#include<string.h>
#include <unistd.h>
#include<stdio.h>
#include<time.h>
static char format[20]="[%s]<%s>:%s\n";
static char timeFormat[20]="%Y-%m-%d %H:%M:%S";
static char filepath[30]="../logs/system.log";
static char errorlog[30]="../logs/error.log";

//打印出错到文件
void log_to_file(int level , const char * message)
{
    char timebuffer[30];
    FILE* logfile = fopen(filepath,"a");
    FILE* errorfile = fopen(errorlog,"a");
    if(logfile ==NULL)
    {
        log_to_console(ERROR,"日志文件打开失败");
    }
    //格式化时间
    get_now_readable_time(timebuffer);
    //判断log级别
    if(level == ERROR)
    {
        char errorFormat[30];
        sprintf(errorFormat,"\033[40;31m%s\033[0m",format);
        fprintf(logfile,format,timebuffer,"ERROR",message);
        fprintf(errorfile,format,timebuffer,"ERROR",message);
    }  
    else if(level == WARNING)
    {
        char warningFormat[30];
        sprintf(warningFormat,"\033[40;33m%s\033[0m",format);
        fprintf(logfile,format,timebuffer,"WARNING",message);
    }
        
    else if(level == INFO)
    {
        fprintf(logfile,format,timebuffer,"INFO",message);
    }
    fclose(logfile);
}

//打印出错位置
void log_more_info(int level,const char * message,const char* postion)
{
    char tmp[512];
    sprintf(tmp,"{%s}:%s",postion,message);
    log_to_file(level,tmp);
}

//打印到控制台
void log_to_console(int level,const char * message)
{
    time_t timer;
    time(&timer);
    char timebuffer[30];
    //格式化时间
    strftime(timebuffer, 80, timeFormat , gmtime(&timer));
    //判断log级别
    if(level == ERROR)
    {
        char errorFormat[30];
        sprintf(errorFormat,"\033[40;31m%s\033[0m",format);
        printf(errorFormat,timebuffer,"ERROR",message);
    }  
    else if(level == WARNING)
    {
        char warningFormat[30];
        sprintf(warningFormat,"\033[40;33m%s\033[0m",format);
        printf(warningFormat,timebuffer,"WARNING",message);
    }
        
    else if(level == INFO)
    {
        printf(format,timebuffer,"INFO",message);
    }   
}