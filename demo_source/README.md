## windows平台onbon SDK DEMO说明

### 目录说明

./include 存放头文件，其中bx_dual_sdk.h文件中包含所有SDK函数的声明和说明；

./project 存放基于windows visual studio VS2010版本的C++ demo代码；

./lib	存放基于windows visual studio VS2010版本的C++ demo生成windows32位平台的可执行文件及所有依赖库；



### SDK使用主要步骤

初始化SDK库

调用节目接口发送节目显示/调用动态区接口发送动态区显示内容

释放SDK库



### SDK动态区接口详细说明：



SDK中 增加多条信息（文本/图片）到单个动态区 的接口函数为：

```C++
/*
功能说明：增加多条信息（文本/图片）到指定的动态区，并可以关联这个动态区到指定的节目；
*/
BXDUAL_API int _CALL_STD bxDual_dynamicArea_AddAreaInfos_6G(Ouint8* pIP, Ouint32 nPort, E_ScreenColor_G56 color,
	Ouint8 uAreaId,
	Ouint8 RunMode,
	Ouint16 Timeout,
	Ouint8 RelateAllPro,
	Ouint16 RelateProNum,
	Ouint16* RelateProSerial,
	Ouint8 ImmePlay,
	Ouint16 uAreaX, Ouint16 uAreaY, Ouint16 uWidth, Ouint16 uHeight,
	EQareaframeHeader oFrame,

	Ouint8 nInfoCount,
	onbon_DynamicAreaInfo_G6** pInfo
)
```



demo中 测试单个动态区中显示多信息（文本/图片）接口为：

```C++
/*
*-------------------------------------------------------------------------------------
* 开始测试
* 测试单区域多信息（文本/图片）接口
*-------------------------------------------------------------------------------------
*/
void onbonTest_DynamicArea_6G(unsigned char* pIP)
```

