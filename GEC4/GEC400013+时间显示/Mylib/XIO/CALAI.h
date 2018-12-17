#ifndef __CALAI_H
#define __CALAI_H
//#include"DB.h"
#include "TYPCortex.h"

#define INPUT_NUM   20
#define OUTPUT_NUM  20
#define AI_NUM      10

extern M_INT8U INPUT_TEMP[INPUT_NUM];
extern M_INT8U OUTPUT_TEMP[OUTPUT_NUM];

extern unsigned short int LED_GENSET;
extern unsigned short int LED_GCB;
extern unsigned short int LED_MAINS;
extern unsigned short int LED_MCB;


#define DI_NOTUSED                INPUT_TEMP[0]//未使用
#define DI_TEMPHIGH               INPUT_TEMP[1]//温度高停机
#define DI_OPLOW                  INPUT_TEMP[2]//油压低停机
#define DI_EXTERN_WRN             INPUT_TEMP[3]//外部输入报警
#define DI_EXTERN_STOP            INPUT_TEMP[4]//外部输入停机
#define DI_ENCOOLING              INPUT_TEMP[5]//允许高速散热停机
#define DI_GCB                    INPUT_TEMP[6]//发电合闸反馈
#define DI_MCB                    INPUT_TEMP[7]//市电合闸反馈
#define DI_TEMPHIGH_NOSTOP        INPUT_TEMP[8]//温度高禁止停机
#define DI_OPLOW_NOSTOP           INPUT_TEMP[9]//油压低不停机
#define DI_RMTSTART               INPUT_TEMP[10]//远程启动
#define DI_LOWFUEL_WRN            INPUT_TEMP[11]//低油位报警
#define DI_LOWLIQUID_WRN          INPUT_TEMP[12]//水位低报警
#define DI_LOWFUEL_STOP           INPUT_TEMP[13]//低油位停机  
#define DI_LOWLIQUID_STOP         INPUT_TEMP[14]//低水位停机
#define DI_INHIBIT_AUTOSTART      INPUT_TEMP[15]//禁止自启动
#define DI_F_STOP_EM              INPUT_TEMP[16]//紧急停机报警
#define DI_F_EDITOR_CONT          INPUT_TEMP[17]//菜单编程控制0-无限制1-无法更改菜单项


#define DO_NOTUSED                OUTPUT_TEMP[0]//不使用
#define DO_COMMALARM              OUTPUT_TEMP[1]//公共报警
#define DO_STOPOUTPUT             OUTPUT_TEMP[2]//得电停机输出
#define DO_IDLE                   OUTPUT_TEMP[3]//怠速控制(闭合怠速)
#define DO_PREHEAT                OUTPUT_TEMP[4]//预热控制
#define DO_GCB                    OUTPUT_TEMP[5]//GCB合闸
#define DO_MCB                    OUTPUT_TEMP[6]//市电合闸
#define DO_OFFCB                  OUTPUT_TEMP[7]//分闸
#define DO_RAISE_SPEED            OUTPUT_TEMP[8]//升速控制
#define DO_REDUCE_SPEED           OUTPUT_TEMP[9]//降速控制
#define DO_DES_RUNNING            OUTPUT_TEMP[10]//机组运行
#define DO_FUELPUMP               OUTPUT_TEMP[11]//燃油泵控制
#define DO_HIGHSPEEDWARM          OUTPUT_TEMP[12]//高速控制(暖机输出)
#define DO_AUTOMODE               OUTPUT_TEMP[13]//自动模式
#define DO_COMMALARM_STOP         OUTPUT_TEMP[14]//停机报警输出
#define F_OUTPUT_FUEL             OUTPUT_TEMP[15]//燃油输出
#define DO_IDLE_Close             OUTPUT_TEMP[16]//怠速控制(断开怠速)


void CAL_GEN_MAINVOL(void);
void XIOAiCheck(void);
void XIO_CALAI_LOOP(void);



#endif

/*************************/
