/**
 * @file onbonTest.h
 * @brief  所有的测试接口都会在下面函数调用逐一测试
 * @author FANTX
 * @date 2018-12-25
 * @version 0.1
 */
#ifndef _fantx_onbon_test_h_
#define _fantx_onbon_test_h_

#include "../onbonDualSdk_h/Obasic_types.h"

#define DEBUG_TCP				1
#define DEBUG_UDP				0
#define DEBUG_UART				0
#define DEBUG_TEST				0
#define DEBUG_ONOFF				0
#define DEBUG_SETCON			0
#define DEBUG_G5                0
#define DEBUG_PICTUREAREA		1
#define DEBUG_TIMEAREA			0
#define DEBUG_CLOCK				0

#define DEBUG_G6				1
#define DEBUG_G6_PICTUREAREA	1
#define DEBUG_G6_TIMEAREA		0

#define DEBUG_G6_CLOCK          0
#define DEBUG_FILELIST			0
#define DEBUG_READCONFIG        0
#define DEBUG_SETCONFIG         0

Oint8 delete_programFile(Ouint8* ip, Ouint16 port);
void tcp_cmd_test(Ouint8* ip, Ouint16 port);
void udp_cmd_test();

void read_configFile(Ouint8* ip, Ouint16 port);
void send_ConfigFile_G6(Ouint8* ip, Ouint16 port);

void addProgram_G5(Ouint16 c_Type);
void addPictureArea_G5();
void addTimeArea_G5();
void addClockArea_G5();
void tcp_send_program_G5(Ouint8* ip, Ouint16 port);

void addProgram_G6(Ouint16 c_Type, Ouint8 nE_ScreenColor_G56);
void addPictureArea_G6();
void addTimeArea_G6();
void addClockArea_G6();
void tcp_send_program_G6(Ouint8* ip, Ouint16 port);
void uart_send_program_G6();
void dynamicArea_test();

void fantx_onbonTest(void);



#endif //_fantx_onbon_test_h_

