/*
 * @file logMsg.h
 * @brief  用来记录代码各种类型信息
 * @author FANTX
 * @date 2018-12-25
 * @version 0.1
 */

#ifndef _LOG_MSG_H_
#define _LOG_MSG_H_


#ifdef __cplusplus
extern "C" {
#endif

#pragma once

#define LOG_FILE 			    "testDemoLog"     //! 日志文件


typedef enum _LogType{
    logType_critical,
    LogType_Error,
    LogType_Warn,
    LogType_Info,
    logType_debug
}LogType;


#pragma region Common operation 


int writeLogMsg(LogType type, char *msg);


#pragma endregion Common operation

#ifdef __cplusplus
}
#endif

#endif //end of LOG_MSG_H_


