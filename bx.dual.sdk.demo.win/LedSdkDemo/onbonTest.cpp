/**
 * @file onbonTest.h
 * @brief  所有的测试接口都会在下面函数调用逐一测试
 * @author FANTX
 * @date 2018-12-25
 * @version 0.1
 */

#include "stdafx.h"
#include "onbonTest.h"
#include "../LedEQSdk/bx_sdk_dual.h"
#include "logMsg.h"

#include<stdio.h>
#include<malloc.h>
#include <memory.h>
#include <string.h>
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#endif

Oint8 delete_programFile(Ouint8* ip, Ouint16 port)
{
	Oint8 ret;
	GetDirBlock_G56 driBlock;
	driBlock.fileNumber = 0;
	driBlock.fileType = 0;
	driBlock.dataAddre = NULL;
	ret = cmd_ofsReedDirBlock(ip, port, &driBlock);
	printf("programNub =========== %d \n", driBlock.fileNumber);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofsReedDirBlock run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofsReedDirBlock run succeed...");
	}
	printf("ret =====cmd_ofsReedDirBlock===== %d \n", ret);
	printf("\n");

	FileAttribute_G56 fileAttr;
	for (int i=0; i<driBlock.fileNumber; i++)
	{
		memset((void*)&fileAttr, 0, sizeof(fileAttr));
		ret = cmd_getFileAttr(&driBlock, i, &fileAttr);
		printf("fileAttr.fileName ======== %s \n",fileAttr.fileName);
		printf("fileAttr.fileType ======== %d \n",fileAttr.fileType);

		cmd_ofsDeleteFormatFile(ip, port, 1, fileAttr.fileName);
	}

	ret = cmd_ofs_freeDirBlock(&driBlock);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofs_freeDirBlock run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofs_freeDirBlock run succeed...");
	}
	printf("ret =====cmd_ofs_freeDirBlock===== %d \n", ret);
	printf("\n");
	return ret;
}

void tcp_cmd_test(Ouint8* ip, Ouint16 port)
{
	Oint8 ret;

#if DEBUG_SETCON	
	Ouint8 ssid[] = "bx-wifi_fantx";
	Ouint8 pwd[] = "12345678";
	ret = cmd_AT_setWifiSsidPwd(ssid, pwd);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_AT_setWifiSsidPwd run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_AT_setWifiSsidPwd run succeed...");
	}
	printf("cmd_AT_setWifiSsidPwd ** ret == %d \n", ret);
	printf("\n");
#endif

#if DEBUG_SETCON
	Ping_data S_retdata;
	ret = cmd_searchController((Ping_data*)&S_retdata);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_searchController run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_searchController run succeed...");
		memset((void*)ip, 0, sizeof(ip));
		memcpy((void*)ip, (void*)S_retdata.ipAdder, strlen((char*)S_retdata.ipAdder));
		printf("S_retdata.ipAdder =====%s \n", ip);
		printf("S_retdata.ControllerType == %x \n", S_retdata.ControllerType);
	}
	printf("cmd_searchController ** ret == %d \n", ret);
	printf("\n");
#endif

	ret = cmd_check_time(ip,port);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_check_time run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_check_time run succeed...");
	}
	printf("ret =====cmd_check_time===== %d \n", ret);
	printf("\n");

	//ret = cmd_coerceOnOff(ip,port,1);
	//printf("ret =====8===== %d \n", ret);

	//ret = cmd_coerceOnOff(ip,port,1);
	//printf("ret =====9===== %d \n", ret);

	/*unsigned char timeData[8] = {0};
	TimingOnOff t_data1;
	t_data1.onHour = 9;
	t_data1.onMinute = 30;
	t_data1.offHour = 15;
	t_data1.offMinute = 30;
	memcpy(timeData, (void*)&t_data1, sizeof(TimingOnOff));
	TimingOnOff t_data2;
	t_data2.onHour = 16;
	t_data2.onMinute = 30;
	t_data2.offHour = 17;
	t_data2.offMinute = 30;
	memcpy(timeData+sizeof(TimingOnOff), (void*)&t_data2, sizeof(TimingOnOff));
	ret = cmd_timingOnOff(ip, port, 2, timeData);
	printf("ret =====10===== %d \n", ret);*/

	/*ret = cmd_cancelTimingOnOff(ip, port);
	printf("ret =====11===== %d \n", ret);*/

	/*Brightness brightnessData;
	memset((void*)&brightnessData, 8, sizeof(Brightness));
	brightnessData.BrightnessMode = 0x01;
	ret = cmd_setBrightness(ip, port, (Brightness*)&brightnessData);
	printf("ret =====12===== %d \n", ret);*/

	/*unsigned char ControllerID[8];
	ret = cmd_readControllerID(ip, port, ControllerID);
	printf("ret =====13===== %d \n", ret);*/
	

	/*ret = cmd_screenLock(ip, port, 0, 0);
	printf("ret =====14===== %d \n", ret);*/


	/*ret = cmd_programLock(ip, port, 0, 1, "节目-1", 0xffff);
	printf("ret =====15===== %d \n", ret);*/

	/*ControllerStatus_G56 controllerStatus;
	ret = cmd_check_controllerStatus(ip, port, (ControllerStatus_G56*)&controllerStatus);
	printf("ret =====16===== %d \n", ret);*/

	//unsigned char oldpassword[6];
	//memset(oldpassword, 0, 6);
	/*unsigned char oldpassword[] = "123456";
	unsigned char newpassword[] = "456789";
	ret = cmd_setPassword(ip, port, oldpassword, newpassword);
	printf("ret =====17===== %d \n", ret);*/

	/*unsigned char password[] = "123456";
	ret = cmd_deletePassword(ip, port, password);
	printf("ret =====18===== %d \n", ret);*/


	/*ret = cmd_setDelayTime(ip, port, 0);
	printf("ret =====19===== %d \n", ret);*/


	/*ret = cmd_setBtnFunc(ip, port, 1);
	printf("ret =====20===== %d \n", ret);*/


	/*BattleTime retdata;
	ret = cmd_battieTime(ip, port, 0x00, (BattleTime*)&retdata);
	printf("ret =====25===== %d \n", ret);*/

	/*ret = cmd_setSpeedAdjust(ip, port, 2);
	printf("ret =====26===== %d \n", ret);*/

	/*ret = cmd_ofsFormat(ip, port);
	printf("ret =====27===== %d \n", ret);*/

	/*unsigned totaMem, availableMem;
	ret = cmd_ofsGetMemoryVolume(ip, port,(Ouint32*)&totaMem, (Ouint32*)&availableMem);
	printf("ret =====28===== %d \n", ret);
	printf("totaMem == %d, availableMem == %d", totaMem, availableMem);*/

	/*Ouint8 fileName[] = "P000";
	Ouint32 fileSize;
	Ouint32 fileCrc;
	ret = cmd_ofsStartReedFile(ip, port, fileName, (Ouint32*)&fileSize, (Ouint32*)&fileCrc);
	printf("ret =====35===== %d \n", ret);*/

	/*Ouint8 fileName[] = "P000";
	Ouint8* data = NULL;
	data = (Ouint8*)malloc(1024*1024);
	ret = cmd_ofsReedFileBlock(ip, port, fileName, data);
	printf("ret =====36===== %d \n", ret);
	free(data);*/
	
	//FILE *fp; 
	//unsigned char *data = NULL;
	//int len;
	////fp = fopen("P000", "rb");
	//fp = fopen("program.bin", "rb");
	//if(fp){
	//	fseek(fp,0,SEEK_END);
	//	len = (int)ftell(fp);
	//	data = (unsigned char*)malloc(len);
	//	fseek(fp,0,SEEK_SET);
	//	fread((void*)data, 1, len, fp);
	//	printf("fp->siz =========%d \n", len);
	//	printf("fp->siz =========%d \n", ftell(fp));
	//	ret = cmd_ofsWriteFile(ip, port, (Ouint8*)"P000", 0, len, 1, data);
	//	free(data);
	//}else{
	//	ret = -10;
	//}
	//printf("ret =====31===== %d \n", ret);
	
 	/*ret = program_pictureArea(ip, port);
	if(ret != 0){
		writeLogMsg(LogType_Error, "program_pictureArea run error...");
	}else{
		writeLogMsg(logType_debug, "program_pictureArea run succeed...");
	}
	printf("ret =====37===== %d \n", ret);*/

}

void udp_cmd_test()
{
	Oint8 ret;
	unsigned char ip[] = "192.168.66.199";
	unsigned short port = 5005;
	unsigned char mode = 2;
	unsigned char subnetMask[] = "255.255.255.0";
	unsigned char gateway[] = "192.168.66.1";
	unsigned char serverMode = 0;
	unsigned char serverIP[] = "192.168.195.1";
	short serverPort = 8001;
	unsigned char password[] = "";
	short heartbeat = 20;
	unsigned char netID[] = "BX-NET000001";
	ret = cmd_udpSetIP(mode, ip, subnetMask, gateway, port, serverMode, serverIP, serverPort, password, heartbeat, netID);
	printf("ret =====3===== %d \n", ret);

	
	unsigned char mac[] = "aa-bb-cc-12-a8-8a";
	ret = cmd_udpSetMac(mac);
	printf("ret =====4===== %d \n", ret);


	heartbeatData netHeartbeat;
	ret = cmd_udpNetworkSearch((heartbeatData *)&netHeartbeat);
	printf("ret =====5===== %d \n", ret);

	ret = cmd_sysReset(ip,port);
	printf("ret =====6===== %d \n", ret);

}

void addProgram_G5(Ouint16 c_type)
{
	program_setScreenParams_G56(eSCREEN_COLOR_DOUBLE, c_type, eDOUBLE_COLOR_PIXTYPE_2);

	EQprogramHeader header;
	header.FileType=0x00;
#if 0
	char pFileName[] = "P000";
	memcpy(header.ProgramName,pFileName,sizeof(header.ProgramName));
#else
	header.ProgramID = 0;
#endif
	header.ProgramStyle=0x00;
	header.ProgramPriority=0x00;
	header.ProgramPlayTimes=1;
	header.ProgramTimeSpan=0;
	header.ProgramWeek=0xff;
	header.ProgramLifeSpan_sy=0xffff;
	header.ProgramLifeSpan_sm=0x03;
	header.ProgramLifeSpan_sd=0x05;
	header.ProgramLifeSpan_ey=0xffff;
	header.ProgramLifeSpan_em=0x04;
	header.ProgramLifeSpan_ed=0x12;
	program_addProgram(&header);

	EQprogramppGrp_G56 ppHeader;
	ppHeader.playTimeGrpNum = 0;
	ppHeader.timeGrp0.StartHour = 15;
	ppHeader.timeGrp0.StartMinute = 0;
	ppHeader.timeGrp0.StartSecond = 0;
	ppHeader.timeGrp0.EndHour = 15;
	ppHeader.timeGrp0.EndMinute = 2;
	ppHeader.timeGrp0.EndSecond = 0;
	program_addPlayPeriodGrp(&ppHeader);


	EQscreenframeHeader sfheader;
	sfheader.FrameDispFlag = 0x01;
	sfheader.FrameDispStyle = 0x01;
	sfheader.FrameDispSpeed = 0x10;
	sfheader.FrameMoveStep = 0x01;
	sfheader.FrameWidth = 2;
	sfheader.FrameBackup = 0;
	//program_addFrame(&sfheader,(Ouint8*)"K:\\green_2Pixel.png");
}

int g_nCountG5 = 0;
void addPictureArea_G5()
{
	//Oint8 ret;
	EQareaHeader aheader;
	aheader.AreaType = 0x00;
	aheader.AreaX = 0;
	aheader.AreaY = 0;
	aheader.AreaWidth = 64;
	aheader.AreaHeight = 32;
	program_AddArea(0, &aheader);  //添加图文区域

	EQareaframeHeader afheader;
	afheader.AreaFFlag = 0x01;
	afheader.AreaFDispStyle = 0x01;
	afheader.AreaFDispSpeed = 0x08;
	afheader.AreaFMoveStep = 0x01;
	afheader.AreaFWidth = 2;
	afheader.AreaFBackup = 0;
	//program_picturesAreaAddFrame(0, &afheader, (Ouint8*)"K:\\green_2Pixel.png");


	//Ouint8 str[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ结束.";
	//Ouint8 str[] =  "和哥哥";
	Ouint8 str[16];
	//将整数转化为字符串
	sprintf((char*)str, "%d", g_nCountG5++ );


	EQpageHeader pheader;
	pheader.PageStyle = 0x00;
	pheader.DisplayMode = 0x04;//0x26;// 
	pheader.ClearMode = 0x01;
	pheader.Speed = 32;
	pheader.StayTime = 200;
	pheader.RepeatTime = 1;
	pheader.ValidLen = 0;
	pheader.arrMode = eSINGLELINE; //eMULTILINE;//
	pheader.fontSize = 24;// 24;
	pheader.color = eRED;// eYELLOW;
	pheader.fontBold = false;
	pheader.fontItalic = false;
	pheader.tdirection = pNORMAL;
	pheader.txtSpace = 0; 
	pheader.Halign = 2;
	pheader.Valign = 2;
	//program_picturesAreaAddTxt(0, str,(Ouint8*)"宋体",&pheader);
	program_fontPath_picturesAreaAddTxt(0,str,(Ouint8*)"allfonts/1.ttf", &pheader);




	
#if 0
	getPageData pageData;
	ret = program_pictureAreaGetOnePage(0,0,&pageData);
	printf("pageData.allPageNub =====%d \n", pageData.allPageNub);
	printf("pageData.pageLen =====%d \n", pageData.pageLen);

	std::ofstream ss;
	ss.open("png1.bin",std::ofstream::binary);
	ss.write((char*)pageData.fileAddre,pageData.pageLen);
	ss.close();

#endif
}

void addTimeArea_G5()
{
	EQareaHeader aheader1;
	aheader1.AreaType = 0x02;
	aheader1.AreaX = 16;
	aheader1.AreaY = 0;
	aheader1.AreaWidth = 64;
	aheader1.AreaHeight = 32;
	program_AddArea(0, &aheader1);  //添加时间区域

	EQtimeAreaData_G56 timeData2;
	timeData2.linestyle = eMULTILINE;
	timeData2.color = eRED;
	timeData2.fontName = (Ouint8*)malloc(40);
	strcpy((Oint8*)timeData2.fontName, "./allfonts/kt2.ttf");//"./allfonts/1.ttf"); //
	timeData2.fontSize = 12;
	timeData2.fontBold = 0;
	timeData2.fontItalic = 0;
	timeData2.fontUnderline = 0;
	timeData2.fontAlign = 1;  //0--左对齐，1-居中，2-右对齐
	timeData2.date_enable = true;
	timeData2.datestyle = (E_DateStyle)eMM_DD_CHS;// eYYYY_MM_DD_MINUS;
	timeData2.time_enable = true;
	timeData2.timestyle = (E_TimeStyle)eHH_MM_SS_COLON;
	timeData2.week_enable = true;
	timeData2.weekstyle = (E_WeekStyle)eMonday_CHS;

	//program_timeAreaAddContent(1,&timeData2);
	program_fontPath_timeAreaAddContent(0,&timeData2);

	free((void*)timeData2.fontName);

	//int r = program_MoveArea(2,0,0,80,32);
}

void addClockArea_G5()
{
	EQareaHeader aheader;
	aheader.AreaType = 0x02;
	aheader.AreaX = 16;
	aheader.AreaY = 0;
	aheader.AreaWidth = 64;
	aheader.AreaHeight = 32;
	program_AddArea(1, &aheader);  //添加时间区域

	EQAnalogClockHeader_G56 acheader;
	acheader.OrignPointX = 32;
	acheader.OrignPointY = 16;
	acheader.UnitMode = 0x00;
	acheader.HourHandWidth = 0x02;
	acheader.HourHandLen = 0x08;
	acheader.HourHandColor = 0x01;
	acheader.MinHandWidth = 0x02;
	acheader.MinHandLen = 0x0b;
	acheader.MinHandColor = 0x01;
	acheader.SecHandWidth = 0x02;
	acheader.SecHandLen = 0x0d;
	acheader.SecHandColor = 0x01;

	ClockColor_G56 clockColor;
	clockColor.Color369 = eRED;
	clockColor.ColorDot = eGREEN;
	clockColor.ColorBG = eYELLOW;

	program_timeAreaAddAnalogClock(1,&acheader,eSQUARE, &clockColor);

	//program_timeAreaChangeDialPic(1,(Ouint8*)"1-1-1.png");
#if 0
	Oint8 ret;
	getPageData pageData;
	ret = program_timeAreaGetOnePage(1,&pageData);
	printf("pageData.allPageNub =====%d \n", pageData.allPageNub);
	printf("pageData.pageLen =====%d \n", pageData.pageLen);
	std::ofstream ss;
	ss.open("png1.bin",std::ofstream::binary);
	ss.write((char*)pageData.fileAddre,pageData.pageLen);
	ss.close();
#endif
}

void tcp_send_program_G5(Ouint8* ip, Ouint16 port)
{
	Oint8 ret;
	ret = cmd_ofsStartFileTransf(ip, port);
	printf("tcp_send_program_G5L:cmd_ofsStartFileTransf===== %d \n", ret);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofsStartFileTransf run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofsStartFileTransf run succeed...");
	}

	EQprogram program;
	memset((void*)&program, 0, sizeof(program));
	program_IntegrateProgramFile(&program);

	ret = cmd_ofsWriteFile(ip, port, program.fileName, program.fileType, program.fileLen, 1, program.fileAddre);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofsWriteFile run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofsWriteFile run succeed...");
	}
	printf("tcp_send_program_G5:cmd_ofsWriteFile===== %d \n", ret);
	printf("fileName_G5 == %s \n", program.fileName);
	printf("fileType_G5 == %d \n", program.fileType);
	printf("fileLen_G5 == %d \n", program.fileLen);
	printf("fileCRC32_G5 == %d \n",program.fileCRC32);
	ret = cmd_ofsEndFileTransf(ip, port);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofsEndFileTransf run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofsEndFileTransf run succeed...");
	}
	printf("tcp_send_program_G5:cmd_ofsEndFileTransf===== %d \n", ret);
	
	//删除本地内存中的节目
	program_deleteProgram();
}




void addProgram_G6(Ouint16 c_Type, Ouint8 nE_ScreenColor_G56)
{
	//设置屏幕的一些参数
	//if (c_Type == 0x0474)
	{
		program_setScreenParams_G56(E_ScreenColor_G56(nE_ScreenColor_G56), c_Type, eDOUBLE_COLOR_PIXTYPE_1);
	}
	//else
	//{
	//	program_setScreenParams_G56(eSCREEN_COLOR_THREE, c_Type, eDOUBLE_COLOR_PIXTYPE_1);
	//	//program_setScreenParams_G56(eSCREEN_COLOR_DOUBLE, c_Type, eDOUBLE_COLOR_PIXTYPE_1);
	//}
	//添加节目
	EQprogramHeader_G6 pHeader;
	pHeader.FileType = 0x00;
	pHeader.ProgramID = 0;// 2;
	pHeader.ProgramStyle=0x00;
	pHeader.ProgramPriority=0x00;
	pHeader.ProgramPlayTimes=1;
	pHeader.ProgramTimeSpan=0;
	pHeader.SpecialFlag = 0;
	pHeader.CommExtendParaLen = 0x00;
	pHeader.ScheduNum = 0;
	pHeader.LoopValue = 0;
	pHeader.Intergrate = 0x00;
	pHeader.TimeAttributeNum = 0x00;
	pHeader.TimeAttribute0Offset = 0x0000;
	pHeader.ProgramWeek=0xff;
	pHeader.ProgramLifeSpan_sy=0xffff;
	pHeader.ProgramLifeSpan_sm=0x03;
	pHeader.ProgramLifeSpan_sd=0x14;
	pHeader.ProgramLifeSpan_ey=0xffff;
	pHeader.ProgramLifeSpan_em=0x03;
	pHeader.ProgramLifeSpan_ed=0x14;
	//pHeader.PlayPeriodGrpNum=0;

	program_addProgram_G6(&pHeader);

	EQprogramppGrp_G56 ppHeader;
	ppHeader.playTimeGrpNum = 1;
	ppHeader.timeGrp0.StartHour = 0x17;
	ppHeader.timeGrp0.StartMinute = 0;
	ppHeader.timeGrp0.StartSecond = 0;
	ppHeader.timeGrp0.EndHour = 0x17;
	ppHeader.timeGrp0.EndMinute = 0x50;
	ppHeader.timeGrp0.EndSecond = 0;
	program_addPlayPeriodGrp_G6(&ppHeader);

	//  修改节目的一些参数
	// 	EQprogramHeader_G6 pHeader1;
	// 	pHeader1.FileType = 0x00;
	// 	pHeader1.ProgramID = 1;
	// 	pHeader1.ProgramStyle=0x00;
	// 	pHeader1.ProgramPriority=0x00;
	// 	pHeader1.ProgramPlayTimes=1;
	// 	pHeader1.ProgramTimeSpan=0;
	// 	pHeader1.SpecialFlag = 0;
	// 	pHeader1.CommExtendParaLen = 0x00;
	// 	pHeader1.ScheduNum = 0;
	// 	pHeader1.LoopValue = 0;
	// 	pHeader1.Intergrate = 0x00;
	// 	pHeader1.TimeAttributeNum = 0x00;
	// 	pHeader1.TimeAttribute0Offset = 0x0000;
	// 	pHeader1.ProgramWeek=0xff;
	// 	pHeader1.ProgramLifeSpan_sy=0xffff;
	// 	pHeader1.ProgramLifeSpan_sm=0x03;
	// 	pHeader1.ProgramLifeSpan_sd=0x14;
	// 	pHeader1.ProgramLifeSpan_ey=0xffff;
	// 	pHeader1.ProgramLifeSpan_em=0x03;
	// 	pHeader1.ProgramLifeSpan_ed=0x14;
	// 	pHeader1.PlayPeriodGrpNum=0;
	// 	program_changeProgramParams_G6(&pHeader1);

	//节目添加边框
	EQscreenframeHeader_G6 fHeader;
	fHeader.FrameDispStype = 0x01;
	fHeader.FrameDispSpeed = 0x8;
	fHeader.FrameMoveStep = 0x01;
	fHeader.FrameUnitLength = 0x20;
	fHeader.FrameUnitWidth = 0x6;
	fHeader.FrameDirectDispBit = 0x01;
	//program_addFrame_G6(&fHeader,(Ouint8*)"D:/onbon_work/biankuang/led_bk8.png");
	//program_addFrame_G6(&fHeader, (Ouint8*)"‪K:\\3232C.png");

	//修改节目边框
	// 	fHeader.FrameDispStype = 0x01;
	// 	fHeader.FrameDispSpeed = 0x01;
	// 	fHeader.FrameMoveStep = 0x01;
	// 	fHeader.FrameUnitLength = 0x20;
	// 	fHeader.FrameUnitWidth = 0x04;
	// 	fHeader.FrameDirectDispBit = 0x01;
	//program_changeFrame_G6(&fHeader,(Ouint8*)"biankuang/led_bk3.png");

	//删除节目边框
	//program_removeFrame_G6();

}

int g_nCountG6 = 0;
void addPictureArea_G6(int nCount)
{
	//在已添加的节目中添加区域
	EQareaHeader_G6 aHeader1;
	aHeader1.AreaType = 0x00;
	aHeader1.AreaX = 0;
	aHeader1.AreaY = 0;

	aHeader1.AreaWidth = 160;//;

	aHeader1.AreaHeight = 32;
	aHeader1.BackGroundFlag = 0x00;
	aHeader1.Transparency = 101;
	aHeader1.AreaEqual = 0x00;
	//aHeader1.SoundFlag = 0x00;

	program_addArea_G6(1,&aHeader1);

	//在已添加的区域中添加文本
//	Ouint8 str[] = "led";

	Ouint8 str[] = "节目-图文-文本测试   节目-图文-文本测试";

	//Ouint8 str[] = "节目-图文-文本测试";

	//将整数转化为字符串
	//sprintf((char*)str, "%d", nCount + g_nCountG6++);


	EQpageHeader_G6 pheader1;
	pheader1.PageStyle = 0x00;
	pheader1.DisplayMode = 0x04;// 0x4;
	pheader1.ClearMode = 0x01;

	pheader1.Speed = 10;
	pheader1.StayTime = 200;

	pheader1.RepeatTime = 1;
	pheader1.ValidLen = 128;
	pheader1.CartoonFrameRate = 0x00;
	pheader1.BackNotValidFlag = 0x00;
	pheader1.arrMode = eSINGLELINE; //eMULTILINE;// 
	pheader1.fontSize = 20;
	pheader1.color = E_Color_G56::eRED;   // E_Color_G56
	pheader1.fontBold = false;
	pheader1.fontItalic = false;
	pheader1.tdirection = pNORMAL;
	pheader1.txtSpace = 0;
	pheader1.Valign = 3;
	pheader1.Halign = 3;

	program_picturesAreaAddTxt_G6(1,str,(Ouint8*)"宋体",&pheader1);
	//program_fontPath_picturesAreaChangeTxt_G6(0, str, &pheader1);
//	program_fontPath_picturesAreaAddTxt_G6(0,str,(Ouint8*)"D:/onbon_work/fonts/1.ttf",&pheader1);

	//program_fontPath_picturesAreaAddTxt_G6(1, str, (Ouint8*)"./allfonts/1.ttf", &pheader1); //C:/Users/onbon/Desktop/IlaSundaram/Uni Ila.Sundaram-01.ttf
	//program_fontPath_picturesAreaAddTxt_G6(0,str,(Ouint8*)"C:/Users/onbon/Desktop/TAC-Kaveri/TAC-Kaveri.ttf",&pheader1);
	//pheader1.color = eRED;
	//program_fontPath_picturesAreaChangeTxt_G6(0,str,&pheader1);

	//对已添加的文本进行修改，修改内容包括文本内容，字体，字体大小，字体颜色，和一些特技效果
	//program_picturesAreaChangeTxt_G6(0,str,(Ouint8*)"宋体",10,pYELLOW,&pheader1);

 	pheader1.StayTime = 100;
 	//program_pictureAreaAddPic_G6(1, 0, &pheader1, (Ouint8*)"K:/3232C.png");

 	//pheader1.StayTime = 300;
 	//program_pictureAreaAddPic_G6(1, 1, &pheader1, (Ouint8*)"K:/图片测试文件/3232绿.png");
// 	pheader1.StayTime = 900;
// 	program_pictureAreaAddPic_G6(0, 1, &pheader1, (Ouint8*)"yellow.png");

#if 0
	getPageData pageData;
	program_pictureAreaGetOnePage(1,0,&pageData);
	printf("pageData.allPageNub =====%d \n", pageData.allPageNub);
	printf("pageData.pageLen =====%d \n", pageData.pageLen);

	std::ofstream ss;
	ss.open("pic_g6.png",std::ofstream::binary);
	ss.write((char*)pageData.fileAddre,pageData.pageLen);
	ss.close();

#endif

}

void addTimeArea_G6()
{
	Ouint16 nAreaID = 3;
	//Oint8 ret;
	EQareaHeader_G6 aHeader1;
	aHeader1.AreaType = 0x02;
	aHeader1.AreaX = 0;
	aHeader1.AreaY = 0;
	aHeader1.AreaWidth = 64;//128;
	aHeader1.AreaHeight = 32;// 96;
	aHeader1.BackGroundFlag = 0x00;
	aHeader1.Transparency = 101;
	aHeader1.AreaEqual = 0x00;
	program_addArea_G6(nAreaID,&aHeader1);

	EQTimeAreaBattle_G6 bheader;
	bheader.BattleStartYear = 2019;
	bheader.BattleStartMonth = 4;
	bheader.BattleStartDate = 1;
	bheader.BattleStartHour = 12;
	bheader.BattleStartMinute = 0;
	bheader.BattleStartSecond = 0;
	bheader.BattleStartWeek = 1;
	bheader.StartUpMode = 0;
	//program_timeAreaSetBattleTime_G6(0,&bheader);

	//program_timeAreaCancleBattleTime_G6(1);

	EQtimeAreaData_G56 timeData;
	timeData.linestyle = eMULTILINE;
	timeData.color = eGREEN;
	timeData.fontName = (Ouint8*)malloc(sizeof(Ouint8)*40);
	//strcpy((Oint8*)timeData.fontName,"./allfonts/FouderKT.ttf");
	strcpy((Oint8*)timeData.fontName, "./allfonts/kt2.ttf");
	//strcpy((Oint8*)timeData.fontName, "./allfonts/1.ttf");
	
	
	
	//strcpy((Oint8*)timeData.fontName,"黑体");
	//timeData.fontSize = 12;// 16;//12
	//timeData.fontBold = 0;
	//timeData.fontItalic = 0;
	//timeData.fontUnderline = 0;
	//timeData.fontAlign = 1;  //0--左对齐，1-居中，2-右对齐
	//timeData.date_enable = true;
	//timeData.datestyle = (E_DateStyle)eMM_DD_CHS;
	//timeData.week_enable = true;
	//timeData.weekstyle = (E_WeekStyle)eMonday;//eMonday_CHS;// 
	//timeData.time_enable = false;
	//timeData.timestyle = (E_TimeStyle)eHH_MM_SS_CHS;// eHH_MM_CHS;
	
	timeData.fontSize = 12;
	timeData.fontBold = 0;
	timeData.fontItalic = 0;
	timeData.fontUnderline = 0;
	timeData.fontAlign = 1;  //0--左对齐，1-居中，2-右对齐
	timeData.date_enable = true;
	timeData.datestyle = (E_DateStyle)eYYYY_MM_DD_CHS;//eMM_DD_CHS;// //eYYYY_MM_DD_VIRGURE;// 
	timeData.week_enable = true;
	timeData.weekstyle = (E_WeekStyle)eMonday_CHS;
	timeData.time_enable = true;
	timeData.timestyle = (E_TimeStyle)eHH_MM_SS_COLON;


		//program_timeAreaAddContent_G6(0,&timeData);
	program_fontPath_timeAreaAddContent_G6(nAreaID,&timeData);

#if 0
	getPageData pageData;
	ret = program_timeAreaGetOnePage(1,&pageData);
	printf("pageData.allPageNub =====%d \n", pageData.allPageNub);
	printf("pageData.pageLen =====%d \n", pageData.pageLen);

	std::ofstream ss;
	ss.open("png0.bin",std::ofstream::binary);
	ss.write((char*)pageData.fileAddre,pageData.pageLen);
	ss.close();
#endif

}

void dynamicArea_test()
{

	EQareaHeader_G6 oAreaHeader_G6;
	oAreaHeader_G6.AreaType = 0x10; //0x10 动态区域

	oAreaHeader_G6.AreaX = 16;
	oAreaHeader_G6.AreaY = 16;
	oAreaHeader_G6.AreaWidth = 32;	// 64;
	oAreaHeader_G6.AreaHeight = 16;	// 32;
	//AreaFrame N 区域边框属性，详细参考
	oAreaHeader_G6.BackGroundFlag = 0x00;
	oAreaHeader_G6.Transparency = 101;
	oAreaHeader_G6.AreaEqual = 0x00;

	Ouint8* strSoundTxt = (Ouint8*)"仰邦。";
	Ouint8 nSize = sizeof(strSoundTxt);
	Ouint8 nStrLen = strlen((const char*)strSoundTxt);
	oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
	oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送

	{
		oAreaHeader_G6.stSoundData.SoundFlag = 0x01;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
		oAreaHeader_G6.stSoundData.SoundPerson = 0x01;	//1 0x00 发音人 该值范围是 0 - 5，共 6 种选择只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundVolum = 1;		//1 0x05 音量该值范围是 0~10，共 11 种，0表示静音只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oAreaHeader_G6.stSoundData.SoundSpeed = 0x2;	//1 0x05 语速该值范围是 0~10，共 11 种只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oAreaHeader_G6.stSoundData.SoundDataMode = 0x00;//1 0x00 SoundData 的编码格式：该值意义如下：0x00 GB2312; 0x01 GBK; 0x02 BIG5; 0x03 UNICODE只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundReplayTimes = 0x01;// 0xffffffff;	//4 0x00000000 重播次数该值为 0，表示播放 1 次该值为 1，表示播放 2 次
		//......
		//该值为 0xffffffff，表示播放无限次只有 SoundFlag（是否使能语播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundReplayDelay = 200;	//4 0x00000000 重播时间间隔该值表示两次播放语音的时间间隔，单位为 10ms只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundReservedParaLen = 0x03;//1 0x03 语音参数保留参数长度
		oAreaHeader_G6.stSoundData.Soundnumdeal = 0x00;		//1 0 0：自动判断1：数字作号码处理 2：数字作数值处理只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oAreaHeader_G6.stSoundData.Soundlanguages = 0x00;		// 1 0 0：自动判断语种1：阿拉伯数字、度量单位、特殊符号等合成为中文2：阿拉伯数字、度量单位、特殊符号等合成为英文只有当 SoundFlag 为 1 且 SoundReservedParaLen不为 0才发送此参数（目前只支持中英文）
		oAreaHeader_G6.stSoundData.Soundwordstyle = 0x00;		// 1 0 0：自动判断发音方式1：字母发音方式2：单词发音方式只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送

	}



	EQpageHeader_G6 stPageHeader;
	stPageHeader.PageStyle = 0x00;
	stPageHeader.DisplayMode = 0x04;
	stPageHeader.ClearMode = 0x00;
	stPageHeader.Speed = 64;
	stPageHeader.StayTime = 0;// 500;
	stPageHeader.RepeatTime = 1;
	stPageHeader.ValidLen = oAreaHeader_G6.AreaWidth;
	stPageHeader.CartoonFrameRate = 0x00;
	stPageHeader.BackNotValidFlag = 0x00;
	stPageHeader.arrMode = eSINGLELINE; //eMULTILINE;//
	stPageHeader.fontSize = 10;
	stPageHeader.color = eRED;
	stPageHeader.fontBold = false;
	stPageHeader.fontItalic = false;
	stPageHeader.tdirection = pNORMAL;
	stPageHeader.txtSpace = 0;
	stPageHeader.Valign = 1;
	stPageHeader.Halign = 1;


	Ouint8* pIP = (Ouint8*)"192.168.2.181";

		const Oint8 cnst_nAreaCount = 4;
		Oint8 pAreaID[cnst_nAreaCount];
		pAreaID[0] = 0;
		pAreaID[1] = 1;
		pAreaID[2] = 2;
		pAreaID[3] = 3;

		//dynamicArea_DelAreas_6G(pIP, 5005, cnst_nAreaCount, pAreaID);

		//dynamicArea_DelArea_6G(pIP, 5005, 0xff);

		//oAreaHeader_G6.stSoundData.SoundFlag = 0x00;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;

		Ouint16 nAreaID = 0;


		//测试使用字体文件
		int nRet = dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_DOUBLE/*eSCREEN_COLOR_THREE*/, nAreaID,
										   &oAreaHeader_G6, &stPageHeader, 
										   (Ouint8*)"K:/onbon/onbon_SDK_Demo/20190909_BX_SDK_Dual/LedSdkDemo/allfonts/1.ttf", 
									       (Ouint8*)"123456789中华人民共和国"
											   );
		
		/*
		测试使用长文本：2048*128点阵的LED屏幕上显示3屏的动态区内容；
		*/
		oAreaHeader_G6.AreaX = 0;
		oAreaHeader_G6.AreaY = 0;
		oAreaHeader_G6.AreaWidth = 2048;	// 64;
		oAreaHeader_G6.AreaHeight = 128;	// 32;

		stPageHeader.fontSize = 96;// 10;

		nRet = dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_DOUBLE/*eSCREEN_COLOR_THREE*/, nAreaID, &oAreaHeader_G6, &stPageHeader,
										 (Ouint8*)"宋体", (Ouint8*)"123456789\n中华人民\n共和国"
										);

}

void send_ConfigFile_G6_2(Ouint8* ip, Ouint16 port)
{
	Oint8 ret;
	Ouint32 fileLen = 0;
	Ouint32 fileCrc = 0;
	Ouint8 fileName[] = "C000";

#if DEBUG_G5
	ConfigFile configData;
#else
	ConfigFile_G6 configData;
#endif
	memset((void*)&configData, 0, sizeof(ConfigFile_G6));

	ret = cmd_confStartReedFile(ip, port, fileName, &fileLen, &fileCrc);
	if (ret != 0) {
		writeLogMsg(LogType_Error, "cmd_confStartReedFile run error...");
	}
	else {
		writeLogMsg(logType_debug, "cmd_confStartReedFile run succeed...");
	}
	printf("ret =====cmd_confStartReedFile===== %d \n", ret);

	printf("fileLen ============ %d \n", fileLen);
	printf("fileData len ============ %d \n", sizeof(configData));
	if (fileLen != sizeof(configData)) {
		printf("read config file failure");
	}

	ret = cmd_confReedFileBlock(ip, port, fileName, (Ouint8*)&configData);
	if (ret != 0) {
		writeLogMsg(LogType_Error, "cmd_confReedFileBlock run error...");
	}
	else {
		writeLogMsg(logType_debug, "cmd_confReedFileBlock run succeed...");
		printf("configData.ScreenWidth ======== %d \n", configData.ScreenWidth);
		printf("configData.ScreenHeight ======== %d \n", configData.ScreenHeight);

	}
	printf("ret =====cmd_confReedFileBlock===== %d \n", ret);

#if DEBUG_G5
	ret = cmd_sendConfigFile(ip, port, &configData);
#else
	ret = cmd_sendConfigFile_G6(ip, port, &configData);
#endif

	if (ret != 0) {
		writeLogMsg(LogType_Error, "cmd_sendConfigFile_G6 run error...");
	}
	else {
		writeLogMsg(logType_debug, "cmd_sendConfigFile_G6 run succeed...");
	}
	printf("ret =====cmd_sendConfigFile_G6===== %d \n", ret);

}

//测试网络搜索命令：三种通讯方式
void onbonTest_NetSearch()
{
#if 1  //测试网络搜索命令：三种通讯方式

	NetSearchCmdRet oNetSearchRet1;
	cmd_uart_search_Net_6G(&oNetSearchRet1, "COM3", 1);

	NetSearchCmdRet oNetSearchRet;
	cmd_udpNetworkSearch_6G(&oNetSearchRet);


	NetSearchCmdRet oNetSearchRet2;
	cmd_tcpNetworkSearch_6G((Ouint8*)"192.168.2.181", 5005, &oNetSearchRet2);

	NetSearchCmdRet_Web oNetSearchRet3;
	cmd_tcpNetworkSearch_6G_Web((Ouint8*)"192.168.2.181", 5005, &oNetSearchRet3);
#endif 
}

void onbonTest_DynamicArea_5G(void)
{
	printf("*****************************************\n");
	printf("*************** test start **************\n");
	printf("*****************************************\n");
	printf("\n");

	InitSdk();



#if 1   //测试5代动态区的接口
	{

		Ouint8* pIP = (Ouint8*)"192.168.0.182";
		Ouint32 nPort = 5005;
		E_ScreenColor_G56 color = E_ScreenColor_G56::eSCREEN_COLOR_DOUBLE;

		//先删除所有动态区
		dynamicArea_DelArea_5G(pIP, nPort, 0xff);


		Ouint8 uAreaId = 0;
		Ouint8 RunMode = 0x00;
		/*0x00 动态区运行模式
		0— 动态区数据循环显示。
			1— 动态区数据显示完成后静止显示最后一页数据。
			2— 动态区数据循环显示，超过设定时间后数据仍未更新时不再显示
			3— 动态区数据循环显示，超过设定时间后数据仍未更新时显示Logo 信息, Logo 信息即为动态区域的最后一页信息
			4— 动态区数据顺序显示，显示完最后一页后就不再显示
		*/
		Ouint16 Timeout = 3;		//Timeout 2 动态区数据超时时间，单位为秒
		Ouint8 RelateAllPro = 0;	//RelateAllPro 1 当该字节为 1 时，所有异步节目播放时都允许播放该动态区域；为 0 时，由接下来的规则来决定
		Ouint16 RelateProNum = 0;	//动态区域关联了多少个异步节目一旦关联了某个异步节目，则当该异步节目播放时允许播放该动态区域，否则，不允许播放该动态区域；以下的节目编号个数根据 RelateProNum 的值来确定，当该值为 0 时不发送；
		Ouint16* RelateProSerial = NULL;
		Ouint8 ImmePlay = 1;		//1 是否立即播放该字节为 0 时，该动态区域与异步节目一起播放；该字节为 1 时，异步节目停止播放，仅播放该动态区域该字节; 为 2 时，暂存该动态区域，当播放完节目编号最高的异步节目后播放该动态区域注意：当该字节为 0 时，RelateAllPro 到RelateProSerialN-1 的参数才有效，否则无效当该参数为 1 或 2 时，由于不与异步节目同时播放，为控制该动态区域能及时结束，可选择RunMode 参数为 2 或 4，当然也
		Ouint16 uAreaX = 16;
		Ouint16 uAreaY = 2;
		Ouint16 uWidth = 64;
		Ouint16 uHeight = 30;
		EQareaframeHeader oFrame; oFrame.AreaFFlag = 0;
		//PageStyle begin-------------------------------------------------------------------------------------------------------------------------------------------
		Ouint8 DisplayMode = 3;		//显示方式:  0x00 –随机显示 0x01 –静止显示 0x02 –快速打出 0x03 –向左移动 0x04 –向左连移 0x05 –向上移动 0x06 –向上连移 0x07 –闪烁 ......
		Ouint8 ClearMode = 0;		//退出方式/清屏方式: 每一页的退出方式；
		Ouint8 Speed = 32;			//速度等级
		Ouint16 StayTime = 200;		//停留时间，单位为 10ms
		Ouint8 RepeatTime = 3;
		//PageStyle End.

		//显示内容和字体格式 begin----------------------------------------------
		EQfontData oFont;
		oFont.arrMode = eMULTILINE;
		oFont.fontSize = 10;
		oFont.color = eRED;
		oFont.fontBold = false;
		oFont.fontItalic = false; oFont.tdirection = pNORMAL; oFont.txtSpace = 0; oFont.Halign = 1; oFont.Valign = 2;
		Ouint8* fontName = (Ouint8*)"宋体";
		Ouint8* strAreaTxtContent = (Ouint8*)"5E1动态-图文-文本测试。";// "5代动态区1开始测试，一起来看看吧...会有新发现的。";


															  
		//测试单区域多信息（文本/图片）接口
		DynamicAreaPicInfo_5G oPicInfo;
		oPicInfo.nType = 2;
		oPicInfo.DisplayMode = DisplayMode;
		oPicInfo.ClearMode = ClearMode;
		oPicInfo.Speed = Speed;
		oPicInfo.StayTime = StayTime;
		oPicInfo.RepeatTime = RepeatTime;
		oPicInfo.filePath = (Ouint8*)"K:/onbon/图片测试文件/3232黄.png";


		dynamicArea_DelArea_5G(pIP, nPort, uAreaId);

		uAreaX = 16;
		uAreaY = 0;
		uWidth = 64;
		uHeight = 32;
		dynamicArea_AddAreaWithPic_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示的图片文件所在目录和名称 begin---------
			(Ouint8*)"K:/onbon/图片测试文件/3232c.png"
			//end.
		);


		DisplayMode = 0x02;		//显示方式:  0x00 –随机显示 0x01 –静止显示 0x02 –快速打出 0x03 –向左移动 0x04 –向左连移 0x05 –向上移动 0x06 –向上连移 0x07 –闪烁 ......
								//0x25 –向右移动  0x26 –向右连移  0x27 –向下移动  0x28 –向下连移
		oFont.arrMode = eSINGLELINE;
		oFont.fontSize = 12;

		DynamicAreaTxtInfo_5G oTxtInfo;
		oTxtInfo.nType = 1;
		oTxtInfo.DisplayMode = DisplayMode;
		oTxtInfo.ClearMode = ClearMode;
		oTxtInfo.Speed = Speed;
		oTxtInfo.StayTime = StayTime;
		oTxtInfo.RepeatTime = RepeatTime;
		oTxtInfo.fontName = fontName;
		oTxtInfo.oFont = oFont;
		oTxtInfo.strAreaTxtContent = (Ouint8*)"T1-0123456789-abcdefghijklmnopqrst-结束|";

		DynamicAreaPicInfo_5G oPicInfo2;
		oPicInfo2.nType = 2;
		oPicInfo2.DisplayMode = DisplayMode;
		oPicInfo2.ClearMode = ClearMode;
		oPicInfo2.Speed = Speed;
		oPicInfo2.StayTime = StayTime;
		oPicInfo2.RepeatTime = RepeatTime;
		oPicInfo2.filePath = (Ouint8*)"K:/onbon/图片测试文件/3232c.png";


		DisplayMode = 0x26;		//显示方式:  0x00 –随机显示 0x01 –静止显示 0x02 –快速打出 0x03 –向左移动 0x04 –向左连移 0x05 –向上移动 0x06 –向上连移 0x07 –闪烁 ......
								//0x25 –向右移动  0x26 –向右连移  0x27 –向下移动  0x28 –向下连移
		oFont.arrMode = eSINGLELINE;// eMULTILINE;//eSINGLELINE; //
		oFont.fontSize = 10;
		oFont.color = eRED;
		oFont.fontBold = false;
		oFont.fontItalic = false; oFont.tdirection = pNORMAL; oFont.txtSpace = 0; oFont.Halign = 1; oFont.Valign = 2;
		fontName = (Ouint8*)"宋体";

		DynamicAreaTxtInfo_5G oTxtInfo2;
		oTxtInfo2.nType = 1;
		oTxtInfo2.DisplayMode = DisplayMode;
		oTxtInfo2.ClearMode = ClearMode;
		oTxtInfo2.Speed = Speed;
		oTxtInfo2.StayTime = StayTime;
		oTxtInfo2.RepeatTime = RepeatTime;
		oTxtInfo2.fontName = fontName;
		oTxtInfo2.oFont = oFont;
		oTxtInfo2.strAreaTxtContent = //(Ouint8*)"0123456789";// "T2-0123456789-abcdefghijklmnopqrst-结束|";// "单区域内第4条信息。";
			(Ouint8*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ结束.";// (Ouint8*)"012345678911111JQB";


		const Ouint8 cnst_InfoCount = 4;
		DynamicAreaBaseInfo_5G* stDynamicAreaBaseInfo_5G[cnst_InfoCount];
		stDynamicAreaBaseInfo_5G[0] = &oTxtInfo;
		stDynamicAreaBaseInfo_5G[1] = &oPicInfo;
		stDynamicAreaBaseInfo_5G[2] = &oPicInfo2;
		stDynamicAreaBaseInfo_5G[3] = &oTxtInfo2;

		dynamicArea_AddAreaInfos_5G( pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			cnst_InfoCount,
			stDynamicAreaBaseInfo_5G
		);

		//return;



		dynamicArea_AddAreaWithTxt_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示内容和字体格式 begin---------
			oFont,
			fontName,
			strAreaTxtContent
			//end.
		);

		//Sleep(3000);

		dynamicArea_DelArea_5G(pIP, nPort, 0xff);

		DisplayMode = 0x02;
		uAreaX = 16;
		uAreaY = 16;
		uWidth = 64;
		uHeight = 16;
		oFont.arrMode = eSINGLELINE; oFont.fontSize = 10;
		fontName = (Ouint8*)"黑体";
		strAreaTxtContent = (Ouint8*)"5代动态区2中华人民共和国70周年纪念，一起迎接这一伟大时刻的到来！";

		dynamicArea_AddAreaWithTxt_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示内容和字体格式 begin---------
			oFont,
			fontName,
			strAreaTxtContent
			//end.
		);


		//Sleep(5000);


		//删除动态区
		dynamicArea_DelArea_5G(pIP, nPort, uAreaId);

		uAreaX = 16;
		uAreaY = 0;
		uWidth = 32;
		uHeight = 32;
		dynamicArea_AddAreaWithPic_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示的图片文件所在目录和名称 begin---------
			(Ouint8*)"K:/onbon/图片测试文件/3232C.png"
			//end.
		);

		//Sleep(5000);


		uAreaId = 1;
		uAreaX = 48;
		uAreaY = 0;
		uWidth = 32;
		uHeight = 32;

		dynamicArea_AddAreaWithPic_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示的图片文件所在目录和名称 begin---------
			(Ouint8*)"K:/onbon/图片测试文件/3232绿.png"
			//end.
		);

		//Sleep(5000);
		//删除动态区
		dynamicArea_DelArea_5G(pIP, nPort, 0xff);

		uAreaX = 16;
		uAreaY = 0;
		uWidth = 64;
		uHeight = 32;
		dynamicArea_AddAreaWithPic_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示的图片文件所在目录和名称 begin---------
			(Ouint8*)"K:/onbon/图片测试文件/3232黄.png"
			//end.
		);

		//删除动态区
		dynamicArea_DelArea_5G(pIP, nPort, uAreaId);

		uAreaId = 0;
		uAreaX = 16;
		uAreaY = 0;
		uWidth = 32;
		uHeight = 32;
		dynamicArea_AddAreaWithPic_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示的图片文件所在目录和名称 begin---------
			(Ouint8*)"K:/onbon/图片测试文件/3232C.png"
			//end.
		);

		uAreaId = 1;
		uAreaX = 16 + 32;
		uAreaY = 0;
		uWidth = 32;
		uHeight = 16;
		dynamicArea_AddAreaWithPic_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示的图片文件所在目录和名称 begin---------
			(Ouint8*)"K:/onbon/图片测试文件/3232C.png"
			//end.
		);

		//Sleep(5000);


		uAreaId = 2;
		uAreaX = 48;
		uAreaY = 16;
		uWidth = 32;
		uHeight = 16;

		dynamicArea_AddAreaWithPic_5G(pIP, nPort, color,
			uAreaId,
			RunMode,
			Timeout,
			RelateAllPro,
			RelateProNum,
			RelateProSerial,
			ImmePlay,
			uAreaX, uAreaY, uWidth, uHeight,
			oFrame,
			//PageStyle begin--------
			DisplayMode,
			ClearMode,
			Speed,
			StayTime,
			RepeatTime,
			//PageStyle End.

			//显示的图片文件所在目录和名称 begin---------
			(Ouint8*)"K:/onbon/图片测试文件/3232绿.png"
			//end.
		);

		
		return;

	}

#endif

#if 1  //测试6代控制卡动态区更新、删除接口：TCP方式

	////dynamicArea_AddAreaWithTxt_6EnX(1, 0, 2, 64, 32, (Ouint8*)"宋体", (Ouint8*)"0123仰邦");
	////dynamicArea_AddAreaWithTxt_6EnX(0, 16, 8, 64, 32, (Ouint8*)"宋体", (Ouint8*)"1");
	////dynamicArea_AddAreaWithTxt_6EnX(0, 16, 2, 64, 32, (Ouint8*)"宋体", (Ouint8*)"12345_Onbon仰邦_6789");

	//dynamicArea_AddAreaWithTxt_6EnX((Ouint8*)"192.168.2.123", 5005, E_ScreenColor_G56::eSCREEN_COLOR_DOUBLE, 0, 16, 0, 64,16,(Ouint8*)"宋体", 10, (Ouint8*)"0中华人民共和国一");
	//dynamicArea_AddAreaWithTxt_6EnX((Ouint8*)"192.168.2.123", 5005, E_ScreenColor_G56::eSCREEN_COLOR_DOUBLE, 1, 16, 16,32,16,(Ouint8*)"黑体", 10, (Ouint8*)"1中华人民共和国一起成长");

	////dynamicArea_AddAreaWithTxt_6EnX( (Ouint8*)"192.168.2.123", 5005, E_ScreenColor_G56::eSCREEN_COLOR_DOUBLE, 1, 16, 16, 32, 16,		(Ouint8*)"宋体", 10, (Ouint8*)"2仰邦++++++++++++++++");
	////dynamicArea_AddAreaWithTxt_6EnX( (Ouint8*)"192.168.2.123", 5005, E_ScreenColor_G56::eSCREEN_COLOR_DOUBLE,   2, 16+32, 16, 32, 16,	(Ouint8*)"宋体", 12, (Ouint8*)"3上海================");


	EQareaHeader_G6 oAreaHeader_G6;
	oAreaHeader_G6.AreaType = 0x10; //0x10 动态区域

	oAreaHeader_G6.AreaX = 16;
	oAreaHeader_G6.AreaY = 16;
	oAreaHeader_G6.AreaWidth = 32;	// 64;
	oAreaHeader_G6.AreaHeight = 16;	// 32;
									//AreaFrame N 区域边框属性，详细参考
	oAreaHeader_G6.BackGroundFlag = 0x00;
	oAreaHeader_G6.Transparency = 101;
	oAreaHeader_G6.AreaEqual = 0x00;

	Ouint8* strSoundTxt = (Ouint8*)"仰邦。";
	Ouint8 nSize = sizeof(strSoundTxt);
	Ouint8 nStrLen = strlen((const char*)strSoundTxt);
	oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
	oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送

	{
		oAreaHeader_G6.stSoundData.SoundFlag = 0x01;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
		oAreaHeader_G6.stSoundData.SoundPerson = 0x01;	//1 0x00 发音人 该值范围是 0 - 5，共 6 种选择只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundVolum = 1;		//1 0x05 音量该值范围是 0~10，共 11 种，0表示静音只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oAreaHeader_G6.stSoundData.SoundSpeed = 0x2;	//1 0x05 语速该值范围是 0~10，共 11 种只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oAreaHeader_G6.stSoundData.SoundDataMode = 0x00;//1 0x00 SoundData 的编码格式：该值意义如下：0x00 GB2312; 0x01 GBK; 0x02 BIG5; 0x03 UNICODE只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundReplayTimes = 0x01;// 0xffffffff;	//4 0x00000000 重播次数该值为 0，表示播放 1 次该值为 1，表示播放 2 次
														//......
														//该值为 0xffffffff，表示播放无限次只有 SoundFlag（是否使能语播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundReplayDelay = 200;	//4 0x00000000 重播时间间隔该值表示两次播放语音的时间间隔，单位为 10ms只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundReservedParaLen = 0x03;//1 0x03 语音参数保留参数长度
		oAreaHeader_G6.stSoundData.Soundnumdeal = 0x00;		//1 0 0：自动判断1：数字作号码处理 2：数字作数值处理只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oAreaHeader_G6.stSoundData.Soundlanguages = 0x00;		// 1 0 0：自动判断语种1：阿拉伯数字、度量单位、特殊符号等合成为中文2：阿拉伯数字、度量单位、特殊符号等合成为英文只有当 SoundFlag 为 1 且 SoundReservedParaLen不为 0才发送此参数（目前只支持中英文）
		oAreaHeader_G6.stSoundData.Soundwordstyle = 0x00;		// 1 0 0：自动判断发音方式1：字母发音方式2：单词发音方式只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送

	}



	EQpageHeader_G6 stPageHeader;
	stPageHeader.PageStyle = 0x00;
	stPageHeader.DisplayMode = 0x04;
	stPageHeader.ClearMode = 0x00;
	stPageHeader.Speed = 64;
	stPageHeader.StayTime = 0;// 500;
	stPageHeader.RepeatTime = 1;
	stPageHeader.ValidLen = oAreaHeader_G6.AreaWidth;
	stPageHeader.CartoonFrameRate = 0x00;
	stPageHeader.BackNotValidFlag = 0x00;
	stPageHeader.arrMode = eSINGLELINE; //eMULTILINE;//
	stPageHeader.fontSize = 10;
	stPageHeader.color = eRED;
	stPageHeader.fontBold = false;
	stPageHeader.fontItalic = false;
	stPageHeader.tdirection = pNORMAL;
	stPageHeader.txtSpace = 0;
	stPageHeader.Valign = 1;
	stPageHeader.Halign = 1;


	Ouint8* pIP = (Ouint8*)"192.168.2.123";


	//for (int i = 0; i < 9999; i++)
	{
		const Oint8 cnst_nAreaCount = 4;
		Oint8 pAreaID[cnst_nAreaCount];
		pAreaID[0] = 0;
		pAreaID[1] = 1;
		pAreaID[2] = 2;
		pAreaID[3] = 3;

		dynamicArea_DelAreas_6G(pIP, 5005, cnst_nAreaCount, pAreaID);

		dynamicArea_DelArea_6G(pIP, 5005, 0xff);


		Ouint16 nAreaID = 0;

		//Ouint8* pIP = (Ouint8*)"192.168.66.189";


		Ouint16 uRelateProgID[3];  uRelateProgID[0] = 0; uRelateProgID[1] = 1; uRelateProgID[2] = 2;
		//dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, oAreaHeader_G6,stPageHeader, (Ouint8*)"宋体", (Ouint8*)"立即显示");
		//oAreaHeader_G6.stSoundData.SoundFlag = 0;
		oAreaHeader_G6.AreaX = 16;
		oAreaHeader_G6.AreaY = 16;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;

		{
			Ouint8* strSoundTxt = (Ouint8*)"与节目关联显示";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}


		//dynamicArea_AddAreaTxtDetails_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, oAreaHeader_G6, stPageHeader, (Ouint8*)"宋体", (Ouint8*)"与节目关联显示", 2, uRelateProgID);

		nAreaID = 1;
		stPageHeader.DisplayMode = 0x01;
		//0x04 –向左连移
		stPageHeader.DisplayMode = 0x04;

		{
			Ouint8* strSoundTxt = (Ouint8*)"图片与节目关联";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}

		dynamicArea_AddAreaPic_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, 16 + 32, 16, 32, 16, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232C.png", 2, uRelateProgID);


		//Sleep(3000);

		//oAreaHeader_G6.stSoundData.SoundFlag = 0x00;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;


		dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, &oAreaHeader_G6, &stPageHeader, (Ouint8*)"宋体", (Ouint8*)"123456789中华人民共和国");


		//同时更新多个动态区测试：开始--------------------------------------------------------------------------------------------------------------------------------------

		//oAreaHeader_G6.stSoundData.SoundFlag = 0x00;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
		{
			Ouint8* strSoundTxt = (Ouint8*)"1动态区1";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}

		//=======
		//>>>>>>> dded573302c5b163134609aaa786247882b89696
		oAreaHeader_G6.AreaX = 16;
		oAreaHeader_G6.AreaY = 16;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;

		DynamicAreaParams oAreaParams_1;
		oAreaParams_1.uAreaId = 0;
		oAreaParams_1.oAreaHeader_G6 = oAreaHeader_G6;
		oAreaParams_1.stPageHeader = stPageHeader;
		oAreaParams_1.strAreaTxtContent = (Ouint8*)"一起来到第3个动态区看看吧abcdefghijklmnopqrst......"; //(Ouint8*)"1中华人民共和国欢迎您。";
		oAreaParams_1.fontName = (Ouint8*)"宋体";


		oAreaHeader_G6.AreaX = 16 + 32;
		oAreaHeader_G6.AreaY = 16;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;
		{
			Ouint8* strSoundTxt = (Ouint8*)"2动态区2";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}

		DynamicAreaParams oAreaParams_2;
		oAreaParams_2.uAreaId = 1;
		oAreaParams_2.oAreaHeader_G6 = oAreaHeader_G6;
		oAreaParams_2.stPageHeader = stPageHeader;
		oAreaParams_2.strAreaTxtContent = (Ouint8*)"一起来到第3个动态区看看吧abcdefghijklmnopqrst......"; //(Ouint8*)"2中国上海仰邦欢迎您！";
		oAreaParams_2.fontName = (Ouint8*)"宋体";



		oAreaHeader_G6.AreaX = 16;
		oAreaHeader_G6.AreaY = 0;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;


		//stPageHeader.DisplayMode = 0x06;// –向上连移
		//stPageHeader.color = eGREEN;

		DynamicAreaParams oAreaParams_3;
		oAreaParams_3.uAreaId = 2;
		oAreaParams_3.oAreaHeader_G6 = oAreaHeader_G6;
		oAreaParams_3.stPageHeader = stPageHeader;
		oAreaParams_3.strAreaTxtContent = (Ouint8*)"一起来到第3个动态区看看吧abcdefghijklmnopqrst......";
		oAreaParams_3.fontName = (Ouint8*)"宋体";


		oAreaHeader_G6.AreaX = 16 + 32;
		oAreaHeader_G6.AreaY = 0;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;


		DynamicAreaParams oAreaParams_4;
		oAreaParams_4.uAreaId = 3;
		oAreaParams_4.oAreaHeader_G6 = oAreaHeader_G6;
		oAreaParams_4.stPageHeader = stPageHeader;
		oAreaParams_4.strAreaTxtContent = (Ouint8*)"一起来到第3个动态区看看吧abcdefghijklmnopqrst......"; //(Ouint8*)"4";
		oAreaParams_4.fontName = (Ouint8*)"宋体";



		const Ouint8 uAreaCount = 4;
		DynamicAreaParams arrParams[uAreaCount];
		arrParams[0] = oAreaParams_1;
		arrParams[1] = oAreaParams_2;
		arrParams[2] = oAreaParams_3;
		arrParams[3] = oAreaParams_4;



		Oint16 nRet = 0;
		nRet = dynamicAreaS_AddTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_THREE, 1, arrParams);


		//删除所有动态区
		dynamicArea_DelArea_6G(pIP, 5005, 0xff);


		const Ouint16 CNST_WITH_PROG_COUNT = 1;
		Ouint16 arrProgID[CNST_WITH_PROG_COUNT];	arrProgID[0] = 0;
		nRet = dynamicAreaS_AddTxtDetails_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, 2, arrParams, CNST_WITH_PROG_COUNT, arrProgID);
		if (nRet != 0)
		{
			printf("1同时更新多个动态区失败!\r\n");
		}

		nRet = dynamicAreaS_AddTxtDetails_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, 2, arrParams, (Oint8)0, arrProgID);
		if (nRet != 0)
		{
			printf("2同时更新多个动态区失败!\r\n");
		}

		nRet = dynamicAreaS_AddTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_THREE, 2, arrParams);
		if (nRet != 0)
		{
			printf("3同时更新多个动态区失败!\r\n");
		}



		//同时更新多个动态区测试：结束 #####################################################################################################################################################################

		//return;


		//Ouint16 uRelateProgID[3];  
		uRelateProgID[0] = 0; uRelateProgID[1] = 1; uRelateProgID[2] = 2;
		//dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, oAreaHeader_G6,stPageHeader, (Ouint8*)"宋体", (Ouint8*)"立即显示");
		//oAreaHeader_G6.stSoundData.SoundFlag = 0;
		oAreaHeader_G6.AreaX = 16;
		oAreaHeader_G6.AreaY = 16;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;

		{
			Ouint8* strSoundTxt = (Ouint8*)"与节目关联显示";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}



		dynamicArea_AddAreaTxtDetails_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, &oAreaHeader_G6, &stPageHeader, (Ouint8*)"宋体", (Ouint8*)"与节目关联显示", 2, uRelateProgID);




		nAreaID = 1;
		stPageHeader.DisplayMode = 0x01;
		dynamicArea_AddAreaPic_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, 16 + 32, 16, 32, 16, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232C.png", 2, uRelateProgID);

		//dynamicArea_AddAreaPic_6G(pIP, 5005, eSCREEN_COLOR_THREE, 2, 16 + 32 + 1, 0, 16, 16, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232C.png");

		//=======
		//dynamicArea_AddAreaPic_6G(pIP, 5005, eSCREEN_COLOR_THREE, 1, 16, 0, 32, 32, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/y.png");
		//dynamicArea_AddAreaPic_6G(pIP, 5005, eSCREEN_COLOR_THREE, 0, 16 + 32 + 1, 0, 16, 16, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232C.png");
		//>>>>>>> remotes/origin/develop
		//dynamicArea_AddAreaWithPic_6EnX((Ouint8*)"192.168.2.123", 5005, eSCREEN_COLOR_THREE/*eSCREEN_COLOR_DOUBLE*/, 0, 16, 0, 32, 32, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232绿.png");
		//dynamicArea_AddAreaWithPic_6EnX((Ouint8*)"192.168.2.123", 5005, eSCREEN_COLOR_DOUBLE, 1, 16 + 32, 0, 32, 32, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232黄.png");

		//Oint8 arrID[2]; arrID[0] = 0; arrID[1] = 2;
		//dynamicArea_DelAreas_6EnX( (Ouint8*)"192.168.2.123", 5005, 2, arrID);
		//dynamicArea_DelArea_6G(pIP, 5005, 0xff);
	}
#endif

	return;
}

//同时更新多个动态区测试：图片
void onbonTesst_DynamicArea_6G_MultiAreasWithPic()
{
	Ouint8* pIP = (Ouint8*)"192.168.2.123";
	Ouint32 nPort = 5005;
	Ouint16 nAreaID = 0;
	E_ScreenColor_G56 eColor = E_ScreenColor_G56::eSCREEN_COLOR_THREE;

	//删除所有动态区
	dynamicArea_DelArea_6G(pIP, 5005, 0xff);

	EQareaHeader_G6 oAreaHeader_G6;
	oAreaHeader_G6.AreaType = 0x10; //0x10 动态区域

	oAreaHeader_G6.AreaX = 16;
	oAreaHeader_G6.AreaY = 16;
	oAreaHeader_G6.AreaWidth = 32;	// 64;
	oAreaHeader_G6.AreaHeight = 16;	// 32;
									//AreaFrame N 区域边框属性，详细参考
	oAreaHeader_G6.BackGroundFlag = 0x00;
	oAreaHeader_G6.Transparency = 101;
	oAreaHeader_G6.AreaEqual = 0x00;

	Ouint8* strSoundTxt = (Ouint8*)"仰邦。";
	Ouint8 nSize = sizeof(strSoundTxt);
	Ouint8 nStrLen = strlen((const char*)strSoundTxt);
	oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
	oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送

	{
		oAreaHeader_G6.stSoundData.SoundFlag = 0x01;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
		oAreaHeader_G6.stSoundData.SoundPerson = 0x01;	//1 0x00 发音人 该值范围是 0 - 5，共 6 种选择只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundVolum = 1;		//1 0x05 音量该值范围是 0~10，共 11 种，0表示静音只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oAreaHeader_G6.stSoundData.SoundSpeed = 0x2;	//1 0x05 语速该值范围是 0~10，共 11 种只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oAreaHeader_G6.stSoundData.SoundDataMode = 0x00;//1 0x00 SoundData 的编码格式：该值意义如下：0x00 GB2312; 0x01 GBK; 0x02 BIG5; 0x03 UNICODE只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundReplayTimes = 0x01;// 0xffffffff;	//4 0x00000000 重播次数该值为 0，表示播放 1 次该值为 1，表示播放 2 次
														   //......
														   //该值为 0xffffffff，表示播放无限次只有 SoundFlag（是否使能语播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundReplayDelay = 200;	//4 0x00000000 重播时间间隔该值表示两次播放语音的时间间隔，单位为 10ms只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundReservedParaLen = 0x03;//1 0x03 语音参数保留参数长度
		oAreaHeader_G6.stSoundData.Soundnumdeal = 0x00;		//1 0 0：自动判断1：数字作号码处理 2：数字作数值处理只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oAreaHeader_G6.stSoundData.Soundlanguages = 0x00;		// 1 0 0：自动判断语种1：阿拉伯数字、度量单位、特殊符号等合成为中文2：阿拉伯数字、度量单位、特殊符号等合成为英文只有当 SoundFlag 为 1 且 SoundReservedParaLen不为 0才发送此参数（目前只支持中英文）
		oAreaHeader_G6.stSoundData.Soundwordstyle = 0x00;		// 1 0 0：自动判断发音方式1：字母发音方式2：单词发音方式只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送

	}


	EQpageHeader_G6 stPageHeader;
	stPageHeader.PageStyle = 0x00;
	stPageHeader.DisplayMode = 0x04;
	stPageHeader.ClearMode = 0x00;
	stPageHeader.Speed = 64;
	stPageHeader.StayTime = 0;// 500;
	stPageHeader.RepeatTime = 1;
	stPageHeader.ValidLen = 64;
	stPageHeader.CartoonFrameRate = 0x00;
	stPageHeader.BackNotValidFlag = 0x00;
	stPageHeader.arrMode = eSINGLELINE; //eMULTILINE;//
	stPageHeader.fontSize = 10;
	stPageHeader.color = eRED;
	stPageHeader.fontBold = false;
	stPageHeader.fontItalic = false;
	stPageHeader.tdirection = pNORMAL;
	stPageHeader.txtSpace = 0;
	stPageHeader.Valign = 1;
	stPageHeader.Halign = 1;

	//oAreaHeader_G6.stSoundData.SoundFlag = 0x00;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
	{
		Ouint8* strSoundTxt = (Ouint8*)"1动态区1";
		Ouint8 nSize = sizeof(strSoundTxt);
		Ouint8 nStrLen = strlen((const char*)strSoundTxt);
		oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
	}

	oAreaHeader_G6.AreaX = 0;
	oAreaHeader_G6.AreaY = 0;
	oAreaHeader_G6.AreaWidth = 32;	// 64;
	oAreaHeader_G6.AreaHeight = 32;	// 32;

	DynamicAreaParams oAreaParams_1;
	oAreaParams_1.uAreaId = 0;
	oAreaParams_1.oAreaHeader_G6 = oAreaHeader_G6;
	oAreaParams_1.stPageHeader = stPageHeader;
	oAreaParams_1.strAreaTxtContent = (Ouint8*)"K:/onbon/图片测试文件/3232C.png"; //(Ouint8*)"1中华人民共和国欢迎您。";
	oAreaParams_1.fontName = (Ouint8*)"宋体";


	oAreaHeader_G6.AreaX = 32;
	oAreaHeader_G6.AreaY = 0;
	oAreaHeader_G6.AreaWidth = 32;	// 64;
	oAreaHeader_G6.AreaHeight = 32;	// 32;
	{
		Ouint8* strSoundTxt = (Ouint8*)"2动态区2";
		Ouint8 nSize = sizeof(strSoundTxt);
		Ouint8 nStrLen = strlen((const char*)strSoundTxt);
		oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
	}

	DynamicAreaParams oAreaParams_2;
	oAreaParams_2.uAreaId = 1;
	oAreaParams_2.oAreaHeader_G6 = oAreaHeader_G6;
	oAreaParams_2.stPageHeader = stPageHeader;
	oAreaParams_2.strAreaTxtContent = (Ouint8*)"K:/onbon/图片测试文件/3232黄.png"; //(Ouint8*)"2中国上海仰邦欢迎您！";
	oAreaParams_2.fontName = (Ouint8*)"宋体";



	oAreaHeader_G6.AreaX = 0;
	oAreaHeader_G6.AreaY = 32;
	oAreaHeader_G6.AreaWidth = 32;	// 64;
	oAreaHeader_G6.AreaHeight = 32;	// 32;


	//stPageHeader.DisplayMode = 0x06;// –向上连移
	//stPageHeader.color = eGREEN;

	DynamicAreaParams oAreaParams_3;
	oAreaParams_3.uAreaId = 2;
	oAreaParams_3.oAreaHeader_G6 = oAreaHeader_G6;
	oAreaParams_3.stPageHeader = stPageHeader;
	oAreaParams_3.strAreaTxtContent = (Ouint8*)"K:/onbon/图片测试文件/3232绿.png";
	oAreaParams_3.fontName = (Ouint8*)"宋体";


	oAreaHeader_G6.AreaX = 32;
	oAreaHeader_G6.AreaY = 32;
	oAreaHeader_G6.AreaWidth = 32;	// 64;
	oAreaHeader_G6.AreaHeight = 32;	// 32;


	DynamicAreaParams oAreaParams_4;
	oAreaParams_4.uAreaId = 3;
	oAreaParams_4.oAreaHeader_G6 = oAreaHeader_G6;
	oAreaParams_4.stPageHeader = stPageHeader;
	oAreaParams_4.strAreaTxtContent = (Ouint8*)"K:/onbon/图片测试文件/YangMi.png"; //(Ouint8*)"4";
	oAreaParams_4.fontName = (Ouint8*)"黑体";



	const Ouint8 uAreaCount = 4;
	DynamicAreaParams arrParams[uAreaCount];
	arrParams[0] = oAreaParams_1;
	arrParams[1] = oAreaParams_2;
	arrParams[2] = oAreaParams_3;
	arrParams[3] = oAreaParams_4;


	Oint16 nRet = 0;
	nRet = dynamicAreaS_AddAreaPic_6G(pIP, 5005, eSCREEN_COLOR_THREE, 4, arrParams);


	//删除所有动态区
	dynamicArea_DelArea_6G(pIP, 5005, 0xff);


	const Ouint16 CNST_WITH_PROG_COUNT = 1;
	Ouint16 arrProgID[CNST_WITH_PROG_COUNT];	arrProgID[0] = 0;
	nRet = dynamicAreaS_AddAreaPic_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, 4, arrParams, CNST_WITH_PROG_COUNT, arrProgID);
	if (nRet != 0)
	{
		printf("1同时更新多个动态区失败!\r\n");
	}

	nRet = dynamicAreaS_AddAreaPic_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, 2, arrParams, (Oint8)0, arrProgID);
	if (nRet != 0)
	{
		printf("2同时更新多个动态区失败!\r\n");
	}

	//nRet = dynamicAreaS_AddTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_THREE, 2, arrParams);
	//if (nRet != 0)
	//{
	//	printf("3同时更新多个动态区失败!\r\n");
	//}	

}


void onbonTest_SoundIndepend()
{
	Ouint8* pIP = (Ouint8*)"192.168.2.100";
	Ouint32 nPort = 5005;
	Ouint16 nSoundDataCount = 1;  //语音队列中语音个数
	Ouint8 StoreFlag = 0;		  //是否保存语音；0-不保存；
	Ouint8 VoiceFlg = 1;
	int nRetInsert1 = 0;

	EQSoundDepend_6G oUpdateSound1;
	EQSoundDepend_6G oInsertSound1;


	{
		Ouint8* strSoundTxt = (Ouint8*)"abc1测试语音";
		Ouint8 nSize = sizeof(strSoundTxt);
		Ouint8 nStrLen = strlen((const char*)strSoundTxt);

		oUpdateSound1.VoiceID = 0;
		oUpdateSound1.stSound.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oUpdateSound1.stSound.SoundData = strSoundTxt;	// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oUpdateSound1.stSound.SoundFlag = 0x01;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
		oUpdateSound1.stSound.SoundPerson = 0x01;	//1 0x00 发音人 该值范围是 0 - 5，共 6 种选择只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oUpdateSound1.stSound.SoundVolum = 6;		//1 0x05 音量该值范围是 0~10，共 11 种，0表示静音只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oUpdateSound1.stSound.SoundSpeed = 0x2;	//1 0x05 语速该值范围是 0~10，共 11 种只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oUpdateSound1.stSound.SoundDataMode = 0x00;//1 0x00 SoundData 的编码格式：该值意义如下：0x00 GB2312; 0x01 GBK; 0x02 BIG5; 0x03 UNICODE只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oUpdateSound1.stSound.SoundReplayTimes = 0x01;// 0xffffffff;	//4 0x00000000 重播次数该值为 0，表示播放 1 次该值为 1，表示播放 2 次
														//......
														//该值为 0xffffffff，表示播放无限次只有 SoundFlag（是否使能语播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oUpdateSound1.stSound.SoundReplayDelay = 200;	//4 0x00000000 重播时间间隔该值表示两次播放语音的时间间隔，单位为 10ms只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oUpdateSound1.stSound.SoundReservedParaLen = 0x03;//1 0x03 语音参数保留参数长度
		oUpdateSound1.stSound.Soundnumdeal = 0x00;		//1 0 0：自动判断1：数字作号码处理 2：数字作数值处理只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oUpdateSound1.stSound.Soundlanguages = 0x00;		// 1 0 0：自动判断语种1：阿拉伯数字、度量单位、特殊符号等合成为中文2：阿拉伯数字、度量单位、特殊符号等合成为英文只有当 SoundFlag 为 1 且 SoundReservedParaLen不为 0才发送此参数（目前只支持中英文）
		oUpdateSound1.stSound.Soundwordstyle = 0x00;		// 1 0 0：自动判断发音方式1：字母发音方式2：单词发音方式只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oUpdateSound1.stSound.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oUpdateSound1.stSound.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
	}

	nSoundDataCount = 1;
	StoreFlag = 0;
	int nRet = dynamicArea_UpdateSoundIndepend(pIP, nPort, &oUpdateSound1, nSoundDataCount, StoreFlag);


	const int CNST_SOUND_COUNT = 3;
	const int CNST_SOUND_MAXLEN = 128;
	char cInt[10];
	EQSoundDepend_6G arrUpdateSound[CNST_SOUND_COUNT];
	Ouint8 strSoundTxt[CNST_SOUND_COUNT][CNST_SOUND_MAXLEN];// = (Ouint8*)"数组语音0abc";

	for (int i = 0; i < CNST_SOUND_COUNT; i++)
	{
		memset(strSoundTxt[i], 0, CNST_SOUND_MAXLEN);
		char* cTxt = "数组语音";
		strcat_s((char*)strSoundTxt[i], CNST_SOUND_MAXLEN, cTxt);
		for (int k = 0; k < 16; k++)
		{
			sprintf(cInt, "%d", i);
			strcat_s((char*)strSoundTxt[i], CNST_SOUND_MAXLEN, cInt);
		}
		Ouint8 nSize = sizeof(strSoundTxt[i]);
		Ouint8 nStrLen = strlen((const char*)strSoundTxt[i]);

		arrUpdateSound[i].VoiceID = i;
		arrUpdateSound[i].stSound.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		arrUpdateSound[i].stSound.SoundData = (strSoundTxt[i]);	// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		arrUpdateSound[i].stSound.SoundFlag = 0x01;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
		arrUpdateSound[i].stSound.SoundPerson = 0x02;	//1 0x00 发音人 该值范围是 0 - 5，共 6 种选择只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		arrUpdateSound[i].stSound.SoundVolum = 10;		//1 0x05 音量该值范围是 0~10，共 11 种，0表示静音只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		arrUpdateSound[i].stSound.SoundSpeed = 0x5;	//1 0x05 语速该值范围是 0~10，共 11 种只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		arrUpdateSound[i].stSound.SoundDataMode = 0x00;//1 0x00 SoundData 的编码格式：该值意义如下：0x00 GB2312; 0x01 GBK; 0x02 BIG5; 0x03 UNICODE只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		arrUpdateSound[i].stSound.SoundReplayTimes = 0x01;// 0xffffffff;	//4 0x00000000 重播次数该值为 0，表示播放 1 次该值为 1，表示播放 2 次 //该值为 0xffffffff，表示播放无限次只有 SoundFlag（是否使能语播放）为 1 时才发送该字节，否则不发送该值默认为 0
		arrUpdateSound[i].stSound.SoundReplayDelay = 200;	//4 0x00000000 重播时间间隔该值表示两次播放语音的时间间隔，单位为 10ms只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		arrUpdateSound[i].stSound.SoundReservedParaLen = 0x03;//1 0x03 语音参数保留参数长度
		arrUpdateSound[i].stSound.Soundnumdeal = 0x00;		//1 0 0：自动判断1：数字作号码处理 2：数字作数值处理只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		arrUpdateSound[i].stSound.Soundlanguages = 0x00;		// 1 0 0：自动判断语种1：阿拉伯数字、度量单位、特殊符号等合成为中文2：阿拉伯数字、度量单位、特殊符号等合成为英文只有当 SoundFlag 为 1 且 SoundReservedParaLen不为 0才发送此参数（目前只支持中英文）
		arrUpdateSound[i].stSound.Soundwordstyle = 0x00;		// 1 0 0：自动判断发音方式1：字母发音方式2：单词发音方式只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		arrUpdateSound[i].stSound.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		//arrUpdateSound[i].stSound.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
	}

	StoreFlag = 0;
	nRet = dynamicArea_UpdateSoundIndepend(pIP, nPort, arrUpdateSound, CNST_SOUND_COUNT, StoreFlag);



	////////////////////////////////////////////////////////////////////////////////////////////////////
	////开始插入语音测试
	//EQSoundDepend_6G oInsertSound1;

	{
		Ouint8* strSoundTxt = (Ouint8*)"从头插入语音";
		Ouint8 nSize = sizeof(strSoundTxt);
		Ouint8 nStrLen = strlen((const char*)strSoundTxt);

		oInsertSound1.VoiceID = 0;
		oInsertSound1.stSound.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oInsertSound1.stSound.SoundData = strSoundTxt;	// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oInsertSound1.stSound.SoundFlag = 0x01;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
		oInsertSound1.stSound.SoundPerson = 0x03;	//1 0x00 发音人 该值范围是 0 - 5，共 6 种选择只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oInsertSound1.stSound.SoundVolum = 7;		//1 0x05 音量该值范围是 0~10，共 11 种，0表示静音只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oInsertSound1.stSound.SoundSpeed = 0x5;	//1 0x05 语速该值范围是 0~10，共 11 种只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oInsertSound1.stSound.SoundDataMode = 0x00;//1 0x00 SoundData 的编码格式：该值意义如下：0x00 GB2312; 0x01 GBK; 0x02 BIG5; 0x03 UNICODE只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oInsertSound1.stSound.SoundReplayTimes = 0x01;// 0xffffffff;	//4 0x00000000 重播次数该值为 0，表示播放 1 次该值为 1，表示播放 2 次
													  //该值为 0xffffffff，表示播放无限次只有 SoundFlag（是否使能语播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oInsertSound1.stSound.SoundReplayDelay = 200;	//4 0x00000000 重播时间间隔该值表示两次播放语音的时间间隔，单位为 10ms只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oInsertSound1.stSound.SoundReservedParaLen = 0x03;//1 0x03 语音参数保留参数长度
		oInsertSound1.stSound.Soundnumdeal = 0x00;		//1 0 0：自动判断1：数字作号码处理 2：数字作数值处理只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oInsertSound1.stSound.Soundlanguages = 0x00;		// 1 0 0：自动判断语种1：阿拉伯数字、度量单位、特殊符号等合成为中文2：阿拉伯数字、度量单位、特殊符号等合成为英文只有当 SoundFlag 为 1 且 SoundReservedParaLen不为 0才发送此参数（目前只支持中英文）
		oInsertSound1.stSound.Soundwordstyle = 0x00;		// 1 0 0：自动判断发音方式1：字母发音方式2：单词发音方式只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oInsertSound1.stSound.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oInsertSound1.stSound.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
	}


	///*
	//功能：插入独立语音
	//参数：
	//Ouint8 VoiceFlg;		//1 1 语音属性 0：此条语音从头插入队列，且停止当前正在播放的语音 1：此条语音从头插入队列，不停止当前播报的语音 2：此条语音从尾插入队列
	//Ouint8 StoreFlag;		//1 0 该值为 1 表示需要存储到 FLASH 中，掉电信息不丢失该值为 0 表示需要存储到 RAM 中，掉电信息丢失
	//*/

	VoiceFlg = 1;
	StoreFlag = 0;
	nRetInsert1 = dynamicArea_InsertSoundIndepend(pIP, nPort, oInsertSound1, VoiceFlg, StoreFlag);

	VoiceFlg = 0;
	StoreFlag = 0;
	nRetInsert1 = dynamicArea_InsertSoundIndepend(pIP,nPort, oInsertSound1, VoiceFlg, StoreFlag);

	{

		const int CNST_SOUND_COUNT = 32;
		const int CNST_SOUND_MAXLEN = 128;
		char cInt[10];
		EQSoundDepend_6G arrUpdateSound[CNST_SOUND_COUNT];
		Ouint8 strSoundTxt[CNST_SOUND_COUNT][CNST_SOUND_MAXLEN];// = (Ouint8*)"数组语音0abc";

		for (int m = 0; m < CNST_SOUND_COUNT; m++)
		{
			memset(strSoundTxt[m], 0, CNST_SOUND_MAXLEN);
			char* cTxt = "尾插语音";
			strcat_s((char*)strSoundTxt[m], CNST_SOUND_MAXLEN, cTxt);
			for (int k = 0; k < 8; k++)
			{
				sprintf(cInt, "%d", m);
				strcat_s((char*)strSoundTxt[m], CNST_SOUND_MAXLEN, cInt);
			}

			//测试从尾插入语音
			{
				//Ouint8* strSoundTxt = (Ouint8*)"从尾插入语音";
				Ouint8 nStrLen = strlen((const char*)strSoundTxt[m]);

				oInsertSound1.stSound.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
				oInsertSound1.stSound.SoundData = strSoundTxt[m];		// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			}

			VoiceFlg = 2;
			StoreFlag = 0;
			nRetInsert1 = dynamicArea_InsertSoundIndepend(pIP, nPort, oInsertSound1, VoiceFlg, StoreFlag);

			Sleep(1000);
		}
	}

	{

		const int CNST_SOUND_COUNT = 32;
		const int CNST_SOUND_MAXLEN = 128;
		char cInt[10];
		EQSoundDepend_6G arrUpdateSound[CNST_SOUND_COUNT];
		Ouint8 strSoundTxt[CNST_SOUND_COUNT][CNST_SOUND_MAXLEN];// = (Ouint8*)"数组语音0abc";

		for (int m = 0; m < CNST_SOUND_COUNT; m++)
		{
			memset(strSoundTxt[m], 0, CNST_SOUND_MAXLEN);
			char* cTxt = "二尾";
			strcat_s((char*)strSoundTxt[m], CNST_SOUND_MAXLEN, cTxt);
			for (int k = 0; k < 8; k++)
			{
				sprintf(cInt, "%d", m);
				strcat_s((char*)strSoundTxt[m], CNST_SOUND_MAXLEN, cInt);
			}
			//测试从尾插入语音
			{
				//Ouint8* strSoundTxt = (Ouint8*)"从尾插入语音";
				Ouint8 nStrLen = strlen((const char*)strSoundTxt[m]);

				oInsertSound1.stSound.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
				oInsertSound1.stSound.SoundData = strSoundTxt[m];		// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			}

			VoiceFlg = 2;
			StoreFlag = 0;
			nRetInsert1 = dynamicArea_InsertSoundIndepend(pIP, nPort, oInsertSound1, VoiceFlg, StoreFlag);

			Sleep(1000);
		}
	}

	int iii = 0;
}



void onbonTest_DynamicArea_6G(void)
{
#if 1  //测试6代控制卡动态区更新、删除接口：TCP方式

	unsigned char pIP[16] = "222.66.141.10";  //上海牛工测试										 
	unsigned short nPort = 16814;

	//Ouint8* pIP = (Ouint8*)"192.168.2.181";
	//Ouint32 nPort = 5005;
	Ouint16 nAreaID = 0;
	E_ScreenColor_G56 eColor = E_ScreenColor_G56::eSCREEN_COLOR_DOUBLE;// eSCREEN_COLOR_THREE;


	//dynamicArea_DelArea_6G(pIP, 5005, 0xff);
	//dynamicArea_AddAreaTxt_6G((Ouint8*)pIP, nPort, eColor, 0, 16, 0, 64,16,(Ouint8*)"宋体", 10, (Ouint8*)"123456789");


	//dynamicArea_DelArea_6G(pIP, 5005, 0xff);
	EQpageHeader_G6 stPageHeader;
	stPageHeader.PageStyle = 0x00;
	stPageHeader.DisplayMode = 0x04;
	stPageHeader.ClearMode = 0x00;
	stPageHeader.Speed = 64;
	stPageHeader.StayTime = 0;// 500;
	stPageHeader.RepeatTime = 1;
	stPageHeader.ValidLen = 64;
	stPageHeader.CartoonFrameRate = 0x00;
	stPageHeader.BackNotValidFlag = 0x00;
	stPageHeader.arrMode = eSINGLELINE; //eMULTILINE;//
	stPageHeader.fontSize = 10;
	stPageHeader.color = eRED;
	stPageHeader.fontBold = false;
	stPageHeader.fontItalic = false;
	stPageHeader.tdirection = pNORMAL;
	stPageHeader.txtSpace = 0;
	stPageHeader.Valign = 1;
	stPageHeader.Halign = 1;

	//char strPathFileName[] = "‪k:\\图片测试文件\\3232C.png";
	//char strPathFileName = "‪c:\\3232C.png";
	char* pPicPath = "k:\\3232c.png";
	char* pPicPath3 = "K:/onbon/图片测试文件/3232c.png";
	for (int i = 0; i < 8; i++)
	{
		//dynamicArea_AddAreaPic_6G(pIP, nPort, eColor, 0, 16, 0, 32, 32, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232c.png");
		//dynamicArea_AddAreaPic_6G(pIP, nPort, eColor, 0, 16, 0, 32, 32, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232绿.png");
	}

	//return;

	//从6代的节目测试用例拷贝过来的：
	{
		EQareaHeader_G6 aHeader1;
		aHeader1.AreaType = 0x00;
		aHeader1.AreaX = 0;// 16;
		aHeader1.AreaY = 0;
		aHeader1.AreaWidth = 160;
		aHeader1.AreaHeight = 32;
		aHeader1.BackGroundFlag = 0x00;
		aHeader1.Transparency = 101;
		aHeader1.AreaEqual = 0x00;
		//aHeader1.SoundFlag = 0x00;


		//在已添加的区域中添加文本
		//	Ouint8 str[] = "led";
		Ouint8 str[] = "汉字测试123456789";
		EQpageHeader_G6 pheader1;
		pheader1.PageStyle = 0x00;
		pheader1.DisplayMode = 0x04;
		pheader1.ClearMode = 0x01;
		pheader1.Speed = 10;
		pheader1.StayTime = 500;
		pheader1.RepeatTime = 1;
		pheader1.ValidLen = 128;
		pheader1.CartoonFrameRate = 0x00;
		pheader1.BackNotValidFlag = 0x00;
		pheader1.arrMode = eMULTILINE;//eSINGLELINE;//
		pheader1.fontSize = 12;
		pheader1.color = 0xff00ff;
		pheader1.fontBold = false;
		pheader1.fontItalic = false;
		pheader1.tdirection = pNORMAL;
		pheader1.txtSpace = 0;
		pheader1.Valign = 2;
		pheader1.Halign = 3;

		dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_DOUBLE, nAreaID, &aHeader1, &pheader1, (Ouint8*)"宋体", (Ouint8*)str);
	}

	EQareaHeader_G6 oAreaHeader_G6;
	oAreaHeader_G6.AreaType = 0x10; //0x10 动态区域

	oAreaHeader_G6.AreaX = 16;
	oAreaHeader_G6.AreaY = 16;
	oAreaHeader_G6.AreaWidth = 32;	// 64;
	oAreaHeader_G6.AreaHeight = 16;	// 32;
									//AreaFrame N 区域边框属性，详细参考
	oAreaHeader_G6.BackGroundFlag = 0x00;
	oAreaHeader_G6.Transparency = 101;
	oAreaHeader_G6.AreaEqual = 0x00;

	Ouint8* strSoundTxt = (Ouint8*)"仰邦。";
	Ouint8 nSize = sizeof(strSoundTxt);
	Ouint8 nStrLen = strlen((const char*)strSoundTxt);
	oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
	oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送

	{
		oAreaHeader_G6.stSoundData.SoundFlag = 0x01;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
		oAreaHeader_G6.stSoundData.SoundPerson = 0x01;	//1 0x00 发音人 该值范围是 0 - 5，共 6 种选择只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundVolum = 1;		//1 0x05 音量该值范围是 0~10，共 11 种，0表示静音只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oAreaHeader_G6.stSoundData.SoundSpeed = 0x2;	//1 0x05 语速该值范围是 0~10，共 11 种只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 5
		oAreaHeader_G6.stSoundData.SoundDataMode = 0x00;//1 0x00 SoundData 的编码格式：该值意义如下：0x00 GB2312; 0x01 GBK; 0x02 BIG5; 0x03 UNICODE只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundReplayTimes = 0x01;// 0xffffffff;	//4 0x00000000 重播次数该值为 0，表示播放 1 次该值为 1，表示播放 2 次
														   //......
														   //该值为 0xffffffff，表示播放无限次只有 SoundFlag（是否使能语播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundReplayDelay = 200;	//4 0x00000000 重播时间间隔该值表示两次播放语音的时间间隔，单位为 10ms只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送该值默认为 0
		oAreaHeader_G6.stSoundData.SoundReservedParaLen = 0x03;//1 0x03 语音参数保留参数长度
		oAreaHeader_G6.stSoundData.Soundnumdeal = 0x00;		//1 0 0：自动判断1：数字作号码处理 2：数字作数值处理只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oAreaHeader_G6.stSoundData.Soundlanguages = 0x00;		// 1 0 0：自动判断语种1：阿拉伯数字、度量单位、特殊符号等合成为中文2：阿拉伯数字、度量单位、特殊符号等合成为英文只有当 SoundFlag 为 1 且 SoundReservedParaLen不为 0才发送此参数（目前只支持中英文）
		oAreaHeader_G6.stSoundData.Soundwordstyle = 0x00;		// 1 0 0：自动判断发音方式1：字母发音方式2：单词发音方式只有当 SoundFlag 为 1 且SoundReservedParaLen不为 0才发送此参数
		oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送

	}

	//删除所有动态区
	dynamicArea_DelArea_6G(pIP, 5005, 0xff);

	{
		const Oint8 cnst_nAreaCount = 4;
		Oint8 pAreaID[cnst_nAreaCount];
		pAreaID[0] = 0;
		pAreaID[1] = 1;
		pAreaID[2] = 2;
		pAreaID[3] = 3;

		dynamicArea_DelAreas_6G(pIP, 5005, cnst_nAreaCount, pAreaID);

		dynamicArea_DelArea_6G(pIP, 5005, 0xff);



		//Ouint8* pIP = (Ouint8*)"192.168.66.189";


		Ouint16 uRelateProgID[3];  uRelateProgID[0] = 0; uRelateProgID[1] = 1; uRelateProgID[2] = 2;		
		
		//oAreaHeader_G6.stSoundData.SoundFlag = 0;
		oAreaHeader_G6.AreaX = 16;
		oAreaHeader_G6.AreaY = 16;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;

		{
			Ouint8* strSoundTxt = (Ouint8*)"与节目关联显示";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}

		
		//dynamicArea_AddAreaTxtDetails_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, oAreaHeader_G6, stPageHeader, (Ouint8*)"宋体", (Ouint8*)"与节目关联显示", 2, uRelateProgID);

		nAreaID = 1;
		stPageHeader.DisplayMode = 0x01;
		//0x04 –向左连移
		stPageHeader.DisplayMode = 0x26;

		{
			Ouint8* strSoundTxt = (Ouint8*)"图片与节目关联";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}

		dynamicArea_AddAreaPic_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, 16 + 32, 16, 32, 16, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232C.png", 2, uRelateProgID);


		//Sleep(3000);

		//oAreaHeader_G6.stSoundData.SoundFlag = 0x00;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;

		//dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, oAreaHeader_G6, stPageHeader, (Ouint8*)"宋体", (Ouint8*)"立即显示");
		dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, &oAreaHeader_G6, &stPageHeader, (Ouint8*)"宋体", (Ouint8*)"123456789中华人民共和国");


		//删除所有动态区
		dynamicArea_DelArea_6G(pIP, 5005, 0xff);


		//同时更新多个动态区测试：开始--------------------------------------------------------------------------------------------------------------------------------------

		//oAreaHeader_G6.stSoundData.SoundFlag = 0x00;	//1 0x00 是否使能语音播放;0 表示不使能语音; 1 表示播放下文中;
		{
			Ouint8* strSoundTxt = (Ouint8*)"1动态区1";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}


		oAreaHeader_G6.AreaX = 16;
		oAreaHeader_G6.AreaY = 16;

		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;

		DynamicAreaParams oAreaParams_1;
		oAreaParams_1.uAreaId = 0;
		oAreaParams_1.oAreaHeader_G6 = oAreaHeader_G6;
		oAreaParams_1.stPageHeader = stPageHeader;
		oAreaParams_1.strAreaTxtContent = (Ouint8*)"季55555555555555555555555555555555555..."; //(Ouint8*)"1中华人民共和国欢迎您。";
		oAreaParams_1.fontName = (Ouint8*)"宋体";


		oAreaHeader_G6.AreaX = 16 + 32;
		oAreaHeader_G6.AreaY = 16;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;
		{
			Ouint8* strSoundTxt = (Ouint8*)"2动态区2";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;			// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}

		DynamicAreaParams oAreaParams_2;
		oAreaParams_2.uAreaId = 1;
		oAreaParams_2.oAreaHeader_G6 = oAreaHeader_G6;
		oAreaParams_2.stPageHeader = stPageHeader;
		oAreaParams_2.strAreaTxtContent = (Ouint8*)"一起来到第3个动态区看看吧abcdefghijklmnopqrst......"; //(Ouint8*)"2中国上海仰邦欢迎您！";
		oAreaParams_2.fontName = (Ouint8*)"宋体";


		oAreaHeader_G6.AreaX = 16;
		oAreaHeader_G6.AreaY = 0;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;


		//stPageHeader.DisplayMode = 0x06;// –向上连移
		//stPageHeader.color = eGREEN;

		DynamicAreaParams oAreaParams_3;
		oAreaParams_3.uAreaId = 2;
		oAreaParams_3.oAreaHeader_G6 = oAreaHeader_G6;
		oAreaParams_3.stPageHeader = stPageHeader;
		oAreaParams_3.strAreaTxtContent = (Ouint8*)"一起来到第3个动态区看看吧abcdefghijklmnopqrst......";
		oAreaParams_3.fontName = (Ouint8*)"宋体";


		oAreaHeader_G6.AreaX = 16 + 32;
		oAreaHeader_G6.AreaY = 0;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;


		DynamicAreaParams oAreaParams_4;
		oAreaParams_4.uAreaId = 3;
		oAreaParams_4.oAreaHeader_G6 = oAreaHeader_G6;
		oAreaParams_4.stPageHeader = stPageHeader;
		oAreaParams_4.strAreaTxtContent = (Ouint8*)"一起来到第3个动态区看看吧abcdefghijklmnopqrst......"; //(Ouint8*)"4";
		oAreaParams_4.fontName = (Ouint8*)"宋体";



		const Ouint8 uAreaCount = 4;
		DynamicAreaParams arrParams[uAreaCount];
		arrParams[0] = oAreaParams_1;
		arrParams[1] = oAreaParams_2;
		arrParams[2] = oAreaParams_3;
		arrParams[3] = oAreaParams_4;

		 

		Oint16 nRet = 0;
		nRet = dynamicAreaS_AddTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_FULLCOLOR/*eSCREEN_COLOR_THREE*/, 2, arrParams);


		//删除所有动态区
		dynamicArea_DelArea_6G(pIP, 5005, 0xff);


		const Ouint16 CNST_WITH_PROG_COUNT = 3;
		Ouint16 arrProgID[CNST_WITH_PROG_COUNT];	arrProgID[0] = 0; arrProgID[1] = 1; arrProgID[0] = 2;
		nRet = dynamicAreaS_AddTxtDetails_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_FULLCOLOR, 2, arrParams, CNST_WITH_PROG_COUNT, arrProgID);


		if (nRet != 0)
		{
			printf("1同时更新多个动态区失败!\r\n");
		}

		nRet = dynamicAreaS_AddTxtDetails_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_FULLCOLOR, 2, arrParams, (Oint8)0, arrProgID);
		if (nRet != 0)
		{
			printf("2同时更新多个动态区失败!\r\n");
		}

		nRet = dynamicAreaS_AddTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_FULLCOLOR, 2, arrParams);
		if (nRet != 0)
		{
			printf("3同时更新多个动态区失败!\r\n");
		}



		//同时更新多个动态区测试：结束 #####################################################################################################################################################################

		//return;


		//Ouint16 uRelateProgID[3];  
		uRelateProgID[0] = 0; uRelateProgID[1] = 1; uRelateProgID[2] = 2;
		//dynamicArea_AddAreaTxtDetails_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, oAreaHeader_G6,stPageHeader, (Ouint8*)"宋体", (Ouint8*)"立即显示");
		//oAreaHeader_G6.stSoundData.SoundFlag = 0;
		oAreaHeader_G6.AreaX = 16;
		oAreaHeader_G6.AreaY = 16;
		oAreaHeader_G6.AreaWidth = 32;	// 64;
		oAreaHeader_G6.AreaHeight = 16;	// 32;

		{
			Ouint8* strSoundTxt = (Ouint8*)"与节目关联显示";
			Ouint8 nSize = sizeof(strSoundTxt);
			Ouint8 nStrLen = strlen((const char*)strSoundTxt);
			oAreaHeader_G6.stSoundData.SoundDataLen = nStrLen;		// 4 语音数据长度; 只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
			oAreaHeader_G6.stSoundData.SoundData = strSoundTxt;		// N 语音数据只有 SoundFlag（是否使能语音播放）为 1 时才发送该字节，否则不发送
		}


		dynamicArea_DelArea_6G(pIP, 5005, 0xff);

		Ouint16 *uRelateProgID_Tmp = NULL;
		dynamicArea_AddAreaTxtDetails_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, &oAreaHeader_G6, &stPageHeader, (Ouint8*)"宋体", (Ouint8*)"与节目关联显示", 0, uRelateProgID_Tmp);


		nAreaID = 1;
		stPageHeader.DisplayMode = 0x01;
		dynamicArea_AddAreaPic_WithProgram_6G(pIP, 5005, eSCREEN_COLOR_THREE, nAreaID, 16 + 32, 16, 32, 16, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232C.png", 2, uRelateProgID);

		//dynamicArea_AddAreaPic_6G(pIP, 5005, eSCREEN_COLOR_THREE, 2, 16 + 32 + 1, 0, 16, 16, &stPageHeader, (Ouint8*)"K:/onbon/图片测试文件/3232C.png");


		dynamicArea_DelArea_6G(pIP, 5005, 0xff);

		dynamicArea_AddAreaPic_6G(pIP, 5005, eSCREEN_COLOR_THREE, 1, 16, 0, 32, 32, &stPageHeader, (Ouint8*)"K:/图片测试文件/3232C.png");
		dynamicArea_AddAreaPic_6G(pIP, 5005, eSCREEN_COLOR_THREE, 0, 16 + 32 + 1, 0, 16, 16, &stPageHeader, (Ouint8*)"K:/图片测试文件/3232绿.png");


	}
#endif

	return;
}



void addClockArea_G6()
{
	EQareaHeader_G6 aHeader1;
	aHeader1.AreaType = 0x02;
	aHeader1.AreaX = 16;
	aHeader1.AreaY = 0;
	aHeader1.AreaWidth = 64;
	aHeader1.AreaHeight = 32;
	aHeader1.BackGroundFlag = 0x00;
	aHeader1.Transparency = 101;
	aHeader1.AreaEqual = 0x00;
	program_addArea_G6(2,&aHeader1);

	EQAnalogClockHeader_G56 acheader;
	acheader.OrignPointX = 32;
	acheader.OrignPointY = 16;
	acheader.UnitMode = 0x00;
	acheader.HourHandWidth = 0x02;
	acheader.HourHandLen = 0x08;
	acheader.HourHandColor = eYELLOW;
	acheader.MinHandWidth = 0x02;
	acheader.MinHandLen = 0x0b;
	acheader.MinHandColor = eGREEN;
	acheader.SecHandWidth = 0x02;
	acheader.SecHandLen = 0x0d;
	acheader.SecHandColor = eRED;

	ClockColor_G56 clockColor;
	clockColor.Color369 = eGREEN;
	clockColor.ColorDot = eGREEN;
	clockColor.ColorBG = eGREEN;

	program_timeAreaAddAnalogClock_G6(2, &acheader, eLINE, &clockColor);
	//program_timeAreaChangeDialPic(2, (Ouint8* )"timg.png");

	Ouint32 buffLen = 1024 * 1024;
	Ouint8* buffer = (Ouint8*)malloc(buffLen);
	memset((void*)buffer, 0, buffLen);
	FILE* pFile = fopen("test1.png", "rb");
	if (pFile)
	{ 
		buffLen = fread(buffer, sizeof(char), buffLen, pFile);
		fclose(pFile);
	}
	//program_timeAreaChangeDialPicAdd_G56(2, buffer, buffLen);

	//program_timeAreaChangeDialPic(2, (Ouint8*)"timg.png");




#if 0
	getPageData pageData;
	ret = program_timeAreaGetOnePage(2,&pageData);
	printf("pageData.allPageNub ==11===%d \n", pageData.allPageNub);
	printf("pageData.pageLen =====%d \n", pageData.pageLen);

	std::ofstream ss;
	ss.open("png0.bin",std::ofstream::binary);
	ss.write((char*)pageData.fileAddre,pageData.pageLen);
	ss.close();
#endif
}

void tcp_send_program_G6(Ouint8* ip, Ouint16 port)
{
	Oint8 ret;
	EQprogram_G6 program;
	memset((void*)&program, 0, sizeof(program));
	program_IntegrateProgramFile_G6(&program);
	program_deleteProgram_G6();
	ret = cmd_ofsStartFileTransf(ip, port);
	printf("ret =====cmd_ofsStartFileTransf===== %d \n", ret);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofsStartFileTransf run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofsStartFileTransf run succeed...");
	}

	ret = cmd_ofsWriteFile(ip, port, program.dfileName, program.dfileType, program.dfileLen, 1, program.dfileAddre);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofsWriteFile run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofsWriteFile run succeed...");
	}
	printf("ret =====cmd_ofsWriteFile===== %d \n", ret);

	ret = cmd_ofsWriteFile(ip, port, program.fileName, program.fileType, program.fileLen, 1, program.fileAddre);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofsWriteFile run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofsWriteFile run succeed...");
	}
	printf("ret =====cmd_ofsWriteFile===== %d \n", ret);

	ret = cmd_ofsEndFileTransf(ip, port);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofsEndFileTransf run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofsEndFileTransf run succeed...");
	}
	printf("ret =====cmd_ofsEndFileTransf===== %d \n", ret);

	//删除本地内存中的节目
	program_freeBuffer_G6(&program);

}

void uart_send_program_G6(Oint8* COMPort)
{
	Oint8 ret;
	EQprogram_G6 program;
	memset((void*)&program, 0, sizeof(program));
	program_IntegrateProgramFile_G6(&program);

	ret = cmd_uart_ofsStartFileTransf(COMPort, 2);
	printf("ret =====cmd_ofsStartFileTransf===== %d \n", ret);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_ofsStartFileTransf run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_ofsStartFileTransf run succeed...");
	}

	ret = cmd_uart_ofsWriteFile(COMPort, 2, program.fileName, program.fileType, program.fileLen, 1, program.fileAddre);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_uart_ofsWriteFile run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_uart_ofsWriteFile run succeed...");
	}
	printf("ret =====cmd_uart_ofsWriteFile===== %d \n", ret);
	ret = cmd_uart_ofsWriteFile(COMPort, 2, program.dfileName, program.dfileType, program.dfileLen, 1, program.dfileAddre);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_uart_ofsWriteFile run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_uart_ofsWriteFile run succeed...");
	}
	printf("ret =====cmd_uart_ofsWriteFile===== %d \n", ret);

	

	ret = cmd_uart_ofsEndFileTransf(COMPort, 2);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_uart_ofsEndFileTransf run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_uart_ofsEndFileTransf run succeed...");
	}
	printf("ret =====cmd_uart_ofsEndFileTransf===== %d \n", ret);

	//删除节目
	program_deleteProgram_G6();

}

void read_configFile(Ouint8* ip, Ouint16 port)
{
	Oint8 ret;
	Ouint32 fileLen = 0;
	Ouint32 fileCrc = 0;
	Ouint8 fileName[] = "C000";
	ret = cmd_confStartReedFile(ip, port, fileName, &fileLen, &fileCrc);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_confStartReedFile run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_confStartReedFile run succeed...");
	}
	printf("ret =====cmd_confStartReedFile===== %d \n", ret);

#if DEBUG_G5
	ConfigFile fileData;
#else
	ConfigFile_G6 fileData;
#endif
	printf("fileLen ============ %d \n", fileLen);
	printf("fileData len ============ %d \n", sizeof(fileData));
	if(fileLen != sizeof(fileData)){
		printf("read config file failure");
	}

	cmd_confReedFileBlock(ip, port, fileName, (Ouint8*)&fileData); 

}


void send_ConfigFile_G6(Ouint8* ip, Ouint16 port)
{
	Oint8 ret;
	Ouint32 fileLen = 0;
	Ouint32 fileCrc = 0;
	Ouint8 fileName[] = "C000";

#if DEBUG_G5
	ConfigFile configData;
#else
	ConfigFile_G6 configData;
#endif
	memset((void*)&configData, 0, sizeof(ConfigFile_G6));

	ret = cmd_confStartReedFile(ip, port, fileName, &fileLen, &fileCrc);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_confStartReedFile run error...");
	}else{
		//writeLogMsg(logType_debug, "cmd_confStartReedFile run succeed...");
	}
	//printf("ret =====cmd_confStartReedFile===== %d \n", ret);

	//printf("fileLen ============ %d \n", fileLen);
	//printf("fileData len ============ %d \n", sizeof(configData));
	if(fileLen != sizeof(configData)){
		printf("read config file failure");
	}

	ret = cmd_confReedFileBlock(ip, port, fileName, (Ouint8*)&configData);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_confReedFileBlock run error...");
	}else{
		//writeLogMsg(logType_debug, "cmd_confReedFileBlock run succeed...");
		//printf("configData.ScreenWidth ======== %d \n", configData.ScreenWidth);
		//printf("configData.ScreenHeight ======== %d \n", configData.ScreenHeight);

	}
	//printf("ret =====cmd_confReedFileBlock===== %d \n", ret);

#if DEBUG_G5
	ret = cmd_sendConfigFile(ip, port, &configData);
#else
	ret = cmd_sendConfigFile_G6(ip, port, &configData);
#endif
	
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_sendConfigFile_G6 run error...");
	}else{
		//writeLogMsg(logType_debug, "cmd_sendConfigFile_G6 run succeed...");
	}
	printf("ret =====cmd_sendConfigFile_G6===== %d \n", ret);

}


void Test_Ultra()
{
	//(baudRate == 1) dcb.BaudRate = 9600;
	//(baudRate == 2) dcb.BaudRate = 57600;

	//测试串口波特率
	Oint8* uartPort = "com3";
	Ouint8 baudRate = 1;
	Ouint8 nonvolatile = 0; 
	Ouint8 lock = 1;
	Ouint8 *name = (Ouint8*)"P000"; 
	Ouint32 lockDuration = 0xffffffff;
	int nRet = cmd_uart_programLock_6G(uartPort, baudRate, nonvolatile, lock, name, lockDuration);
}


DWORD WINAPI ThreadFunc1_G5(LPVOID p)
{

	unsigned char ip[] = "192.168.2.5";  //5E
	unsigned short port = 5005;

	while (1)
	{

		printf("ThreadFunc1_G5,pid =============================== %d\n", GetCurrentThreadId());   //输出子线程pid

		Ping_data retdata;
		Ouint16 c_type = 0;
		int ret = cmd_tcpPing(ip, port, &retdata);
		if (ret != 0)
		{
			writeLogMsg(LogType_Error, "cmd_tcpPing run error...");
		}
		else {
			writeLogMsg(logType_debug, "cmd_tcpPing run succeed...");
			//memset((void*)ip, 0, sizeof(ip));
			//memcpy((void*)ip, (void*)retdata.ipAdder, strlen((char*)retdata.ipAdder));
			printf("retdata.ipAdder =====%s \n", ip);
			printf("retdata.ControllerType == 0x%x \n", retdata.ControllerType);
			c_type = retdata.ControllerType;
		}

		addProgram_G5(c_type);


		addPictureArea_G5();


		tcp_send_program_G5(ip, port);

		Sleep(2000);

		//return 0;
	}
}


DWORD WINAPI ThreadFunc1_G6(LPVOID p)
{
	unsigned char ip1[] = "192.168.2.6";  //5E1
	unsigned char ip2[] = "192.168.2.7";  //5E1
	unsigned short port = 5005;
	int nBeginCount = *(int*)p;
	unsigned char ip[16] = { 0 };
	memcpy(ip, ip1, 15);
	if( nBeginCount == 10 )
		memcpy(ip, ip2, 15);

	while (1)
	{
		printf("ThreadFunc1_G6, pid ==================================== %d\n", GetCurrentThreadId());   //输出子线程pid


		Ping_data retdata;
		Ouint16 c_type = 0;
		int ret = cmd_tcpPing(ip, port, &retdata);
		if (ret != 0) 
		{
			writeLogMsg(LogType_Error, "cmd_tcpPing run error...");
		}
		else {
			writeLogMsg(logType_debug, "cmd_tcpPing run succeed...");
			//memset((void*)ip, 0, sizeof(ip));
			//memcpy((void*)ip, (void*)retdata.ipAdder, strlen((char*)retdata.ipAdder));
			printf("retdata.ipAdder =====%s \n", ip);
			printf("retdata.ControllerType == 0x%x \n", retdata.ControllerType);
			c_type = retdata.ControllerType;
		}

		addProgram_G6(c_type, eSCREEN_COLOR_DOUBLE);// eSCREEN_COLOR_THREE);//

		addPictureArea_G6(nBeginCount);

		//再发送节目
		tcp_send_program_G6(ip, port);


		Sleep(2000);

		//return 0;
	}
}


void MultiThreadTest()
{

	InitSdk();

	HANDLE hThread;
	DWORD  threadId;


	//ThreadFunc1_G5(NULL);

	int nCount1 = 0;
	int nCount2 = 10;
	hThread = CreateThread(NULL, 0, ThreadFunc1_G6, (LPVOID)&nCount1, 0, &threadId); // 创建线程
	hThread = CreateThread(NULL, 0, ThreadFunc1_G6, (LPVOID)&nCount2, 0, &threadId); // 创建线程

	hThread = CreateThread(NULL, 0, ThreadFunc1_G5, 0, 0, &threadId); // 创建线程

}



void fantx_onbonTest(void)
{
	printf("*****************************************\n");
	printf("*************** test start **************\n");
	printf("*****************************************\n");
	printf("\n");
	InitSdk();

	//测试网络搜索命令：三种通讯方式
	//onbonTest_NetSearch();
	//return;

	//MultiThreadTest();
	//return;


	//测试串口
	//Test_Ultra();

	//return;


	//onbonTest_SoundIndepend();

	//return;


#if 0  //测试网络搜索命令：三种通讯方式

	NetSearchCmdRet oNetSearchRet1;
	cmd_uart_search_Net_6G(&oNetSearchRet1, "COM3", 1);

	NetSearchCmdRet oNetSearchRet;
	cmd_udpNetworkSearch_6G(&oNetSearchRet);


	NetSearchCmdRet oNetSearchRet2;
	cmd_tcpNetworkSearch_6G((Ouint8*)"192.168.2.123", 5005, &oNetSearchRet2);

	NetSearchCmdRet_Web oNetSearchRet3;
	cmd_tcpNetworkSearch_6G_Web((Ouint8*)"192.168.2.123", 5005, &oNetSearchRet3);
#endif 

#if DEBUG_G5
	unsigned char ip[] = "192.168.2.5";  //5E1
										 //unsigned char ip[] = "192.168.100.1";  //X-W4

#else


	//unsigned char ip[] = "192.168.66.189";
	//unsigned char ip[] = "192.168.66.168";
	//unsigned char ip[] = "192.168.66.199";


	//unsigned char ip[16] = "192.168.2.123";  //6E2X
	//unsigned char ip[16] = "192.168.2.6";  //WiFi
	//unsigned char ip[16] = "192.168.2.181";  //6E1X

	
	//unsigned char ip[16] = "222.66.141.10";  //上海牛工测试
	unsigned char ip[16] = "192.168.0.181";  //金斗


#endif

	unsigned short port = 5005;
	//unsigned short port = 16814; //上海牛工测试
	Oint8 COMPort[] = "COM3";
	int ret = 0;
	Ouint16 c_type = 0;

	//校时
	//cmd_check_time(ip, port);
	

#if /*DEBUG_TCP*/0
	Ping_data S_retdata;
	ret = cmd_searchController((Ping_data*)&S_retdata);
	if (ret != 0) {
		writeLogMsg(LogType_Error, "cmd_searchController run error...");
	}
	else {
		writeLogMsg(logType_debug, "cmd_searchController run succeed...");
		memset((void*)ip, 0, sizeof(ip));
		memcpy((void*)ip, (void*)S_retdata.ipAdder, strlen((char*)S_retdata.ipAdder));
		printf("S_retdata.ipAdder =====%s \n", ip);
		printf("S_retdata.ControllerType == %x \n", S_retdata.ControllerType);

		c_type = S_retdata.ControllerType;
}
	printf("cmd_searchController ** ret == %d \n", ret);
	printf("\n");
#endif


	//GetDirBlock_G56 oDirBlock;
	//cmd_ofsReedDirBlock(ip, port, &oDirBlock);


#if 1 //测试6代控制卡动态区更新、删除接口：TCP方式

	//测试6代卡动态区大面积
	//dynamicArea_test();

	//测试动态区的接口:完整的示例；
	//onbonTest_DynamicArea_6G();
	onbonTest_DynamicArea_5G();


	//仅测试6代动态区：多区域同时更新图片 功能；
	//onbonTesst_DynamicArea_6G_MultiAreasWithPic();
	//dynamicArea_DelArea_6G(ip, 5005, 0xff);

	//return;

#endif



//	Ouint8 firmware[] = "F001";
//	ret = cmd_firmwareActivate((Ouint8*)"192.168.100.1", port, firmware);
//	printf("cmd_firmwareActivate ** ret == %d \n", ret);

#if /*DEBUG_TCP*/0
	Ping_data S_retdata;
	ret = cmd_searchController((Ping_data*)&S_retdata);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_searchController run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_searchController run succeed...");
		memset((void*)ip, 0, sizeof(ip));
		memcpy((void*)ip, (void*)S_retdata.ipAdder, strlen((char*)S_retdata.ipAdder));
		printf("S_retdata.ipAdder =====%s \n", ip);
		printf("S_retdata.ControllerType == %x \n", S_retdata.ControllerType);
#endif


#if 0
	Ouint8 ssid[] = "wifi_fantx";
	Ouint8 pwd[] = "12345678";
	ret = cmd_AT_setWifiSsidPwd(ssid, pwd);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_AT_setWifiSsidPwd run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_AT_setWifiSsidPwd run succeed...");
	}
	printf("cmd_AT_setWifiSsidPwd ** ret == %d \n", ret);
	printf("\n");
#endif

#if 0
	for (Ouint8 i=0; i<10; i++)
	{
		Ouint8 ssid[30] = {0};
		Ouint8 pwd[30]  = {0};
		ret = cmd_AT_getWifiSsidPwd(ssid, pwd);
		printf("cmd_AT_getWifiSsidPwd ** ret == %d \n", ret);
		printf("cmd_AT_getWifiSsidPwd retturn ssid === %s \n", ssid);
		printf("cmd_AT_getWifiSsidPwd retturn ssid === %s \n", pwd);
		printf("\n");
	}
#endif

#if DEBUG_UDP

	Ping_data retdata;
	ret = cmd_udpPing((Ping_data*)(&retdata));
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_udpPing run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_udpPing run succeed...");
		memset((void*)ip, 0, sizeof(ip));
		memcpy((void*)ip, (void*)retdata.ipAdder, strlen((char*)retdata.ipAdder));
		printf("retdata.ipAdder =====%s \n", ip);
		printf("retdata.ControllerType == 0x%x \n", retdata.ControllerType);
		c_type = retdata.ControllerType;
	}
	printf("ret =====cmd_udpPing===== %d \n", ret);
	printf("\n");
#endif

#if 0 //DEBUG_TCP

	Ping_data retdata;
	port = 5005;
	ret = cmd_tcpPing(ip, port, &retdata);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_tcpPing run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_tcpPing run succeed...");
		//memset((void*)ip, 0, sizeof(ip));
		//memcpy((void*)ip, (void*)retdata.ipAdder, strlen((char*)retdata.ipAdder));
		printf("retdata.ipAdder =====%s \n", ip);
		printf("retdata.ControllerType == 0x%x \n", retdata.ControllerType);
		c_type = retdata.ControllerType;
	}
	printf("ret =====cmd_tcpPing===== %d \n", ret);
	printf("\n");

#endif


#if DEBUG_UART
	Ping_data uart_retdata;
	ret = cmd_uart_searchController((Ping_data*)&uart_retdata, COMPort);
	if(ret != 0){
		writeLogMsg(LogType_Error, "cmd_uart_searchController run error...");
	}else{
		writeLogMsg(logType_debug, "cmd_uart_searchController run succeed...");
		printf("uart_retdata.Baudrate =====%d \n", uart_retdata.Baudrate);
		printf("uart_retdata.ControllerType == %x \n", uart_retdata.ControllerType);
		c_type = uart_retdata.ControllerType;
	}
	printf("cmd_uart_searchController ** ret == %d \n", ret);
	printf("\n");

	//测试串口
	Test_Ultra();

#endif

#if DEBUG_READCONFIG
	read_configFile(ip ,port);
#endif

#if DEBUG_SETCONFIG
	for (int i = 0; i < 500; i++)
	{
		send_ConfigFile_G6(ip, port);
	}
#endif

#if DEBUG_FILELIST
	delete_programFile(ip, port);
#endif

#if DEBUG_G5

	addProgram_G5(c_type);

	#if DEBUG_PICTUREAREA
		addPictureArea_G5();
	#endif//DEBUG_PICTUREAREA

	#if DEBUG_CLOCK
		addClockArea_G5();
	#endif//DEBUG_TIMEAREA

	#if DEBUG_TIMEAREA
		addTimeArea_G5();
	#endif //DEBUG_TIMEAREA

	tcp_send_program_G5(ip, port);

#endif//DEBUG_G5

#if DEBUG_G6


	//set_packetLen(31*1024);

	addProgram_G6(c_type, eSCREEN_COLOR_DOUBLE);// eSCREEN_COLOR_FULLCOLOR);

	//addProgram_G6(c_type, eSCREEN_COLOR_THREE);//eSCREEN_COLOR_DOUBLE);// 


	#if DEBUG_G6_TIMEAREA
	addTimeArea_G6();
	#endif//DEBUG_G6_TIMEAREA

	#if DEBUG_G6_PICTUREAREA
		addPictureArea_G6(0);
	#endif//DEBUG_G6_PICTUREAREA

	#if DEBUG_G6_CLOCK
		addClockArea_G6();
	#endif//DEBUG_G6_CLOCK

	#if DEBUG_UART
		uart_send_program_G6(COMPort);
	#endif //DEBUG_UART

	#if DEBUG_TCP	

		//先删除所有动态区
		//dynamicArea_DelArea_6G(ip, 5005, 0xff);

		//再发送节目
		tcp_send_program_G6(ip, port);
	#endif

#endif //DEBUG_G6

	printf("\n");
	printf("*****************************************\n");
	printf("**************** test end ***************\n");
	printf("*****************************************\n");
}
