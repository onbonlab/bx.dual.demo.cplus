
#include "stdafx.h"
#include "logMsg.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

/*! ***************************************************************
* 函数名： writeLogMsg
* 参数名：
* 返回值：
* 功 能：写一个记录项到临时日志文件
* 注：
*
******************************************************************/
int writeLogMsg(LogType type, char *msg)
{
    char fullMsg[512] ;

    time_t t = time(0);
    strftime(fullMsg, sizeof(fullMsg), "[%Y-%m-%d %X]",localtime(&t));

    switch(type){
    case logType_critical:{
        strncat(fullMsg, " [TEST] [CRITICAL] ", 511 - strlen(fullMsg));
    }break;
    case LogType_Error:{
        strncat(fullMsg, " [TEST] [ERROR   ] ", 511 - strlen(fullMsg));
    }break;
    case LogType_Warn:{
        strncat(fullMsg, " [TEST] [WARNING ] ", 511 - strlen(fullMsg));
    }break;
    case LogType_Info:{
        strncat(fullMsg, " [TEST] [INFO    ] ", 511 - strlen(fullMsg));
    }break;
    case logType_debug:{
        strncat(fullMsg, " [TEST] [DEBUG   ] ", 511 - strlen(fullMsg));
    }break;
    }

    strncat(fullMsg,  "# DEMO # ", 511 - strlen(fullMsg));
    strncat(fullMsg,  msg, 511-strlen(fullMsg));
	strncat(fullMsg,  "\n", 511-strlen(fullMsg));


    FILE *file = fopen(LOG_FILE, "a+");
    if (!file){
        return -1;
    }
    fputs(fullMsg, file);

    fflush(file);
    fclose(file);

    return 0;
}
