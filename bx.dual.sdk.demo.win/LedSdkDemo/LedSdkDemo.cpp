// LedSdkDemo.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include "onbonTest.h"

#include <windows.h>
#include <stdio.h>

//#pragma comment(lib,"../Debug/LedEQSdk.lib")
//#pragma comment(lib,"../x64/Release/LedEQSdk.lib")

int main(int argc, _TCHAR* argv[])
{
	printf("welcome to vs ... \n");

	fantx_onbonTest();
	//这里可以调用别人的测试函数
	

	while(1){
		Sleep(1000);
		;
	}

	return 0;
}

