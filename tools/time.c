#include<time.h>
#include "../include/tool.h"
static char timeFormat[20]="%Y-%m-%d %H:%M:%S";

int get_now_readable_time(char * timeBuffer)
{
    time_t timer;
    time(&timer);
    strftime(timeBuffer, 80, timeFormat , gmtime(&timer));
    return 0;
}

