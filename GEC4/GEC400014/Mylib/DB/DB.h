#ifndef __DB_H
#define __DB_H
 #include "TYPCortex.h"
//#include "GEC4xxFontDis.h"
typedef  unsigned long          M_ulong;
typedef  unsigned char          M_uchar;
typedef  unsigned int           M_uint;
typedef  signed int             M_sint;
typedef unsigned char           M_BOOL;
typedef unsigned char           M_BOOLEAN;
typedef unsigned char           M_INT8U;
typedef signed   char           M_INT8S;
typedef unsigned char           M_INT08U;
typedef signed   char           M_INT08S;
typedef volatile unsigned char  M_VINT8U;
typedef volatile signed   char  M_VINT8S;
typedef volatile unsigned char  M_VINT08U;
typedef volatile signed   char  M_VINT08S;
typedef signed   int            M_INT16S;
typedef volatile unsigned int   M_VINT16U;
typedef volatile signed   int   M_VINT16S;
typedef unsigned long           M_INT24U;
typedef signed   long           M_INT24S;
typedef volatile unsigned long  M_VINT24U;
typedef volatile signed   long  M_VINT24S;
typedef unsigned long           M_INT32U;
typedef signed   long           M_INT32S;
typedef volatile unsigned long  M_VINT32U;
typedef volatile signed   long  M_VINT32S;
typedef unsigned long long      M_INT64U;
typedef signed   long long      M_INT64S;
typedef volatile unsigned long long  M_VINT64U;
typedef volatile signed   long long  M_VINT64S;
typedef float                   M_FP32;
typedef double                  M_FP64;
typedef unsigned char           M_OS_STK;
typedef unsigned char           M_OS_CPU_SR;
typedef unsigned int            M_INT16U;
typedef unsigned char           byte;


typedef union
{
    byte Byte;
    struct
    {
        byte BIT0 : 1;
        byte BIT1 : 1;
        byte BIT2 : 1;
        byte BIT3 : 1;
        byte BIT4 : 1;
        byte BIT5 : 1;
        byte BIT6 : 1;
        byte BIT7 : 1;
    } BITS;

} STRFLG8;

typedef union
{
    unsigned  int ByteInt;
    signed  int Sbyte;
    struct
    {
        byte BIT0 : 1;
        byte BIT1 : 1;
        byte BIT2 : 1;
        byte BIT3 : 1;
        byte BIT4 : 1;
        byte BIT5 : 1;
        byte BIT6 : 1;
        byte BIT7 : 1;
        byte BIT8 : 1;
        byte BIT9 : 1;
        byte BITA : 1;
        byte BITB : 1;
        byte BITC : 1;
        byte BITD : 1;
        byte BITE : 1;
        byte BITF : 1;
    } BITS;
    struct
    {
        byte BYTEH: 8;
        byte BYTEL: 8;
        
    } BYTES;

} STRFLG16;

typedef union
{
    unsigned long UDWORD;
    long DWORD;
    
    struct
    {
        unsigned int WORDH: 16;
        unsigned int WORDL: 16;
    }WORDS;
     
    struct
    {
        byte BYTE4: 8;
        byte BYTE3: 8;
        byte BYTE2: 8;
        byte BYTE1: 8;        
    } BYTES; 
            
    struct
    {
        byte BIT0  : 1;
        byte BIT1  : 1;
        byte BIT2  : 1;
        byte BIT3  : 1;
        byte BIT4  : 1;
        byte BIT5  : 1;
        byte BIT6  : 1;
        byte BIT7  : 1;
        byte BIT8  : 1;
        byte BIT9  : 1;
        byte BIT10 : 1;
        byte BIT11 : 1;
        byte BIT12 : 1;
        byte BIT13 : 1;
        byte BIT14 : 1;
        byte BIT15 : 1;
        byte BIT16 : 1;
        byte BIT17 : 1;
        byte BIT18 : 1;
        byte BIT19 : 1;
        byte BIT20 : 1;
        byte BIT21 : 1;
        byte BIT22 : 1;
        byte BIT23 : 1;
        byte BIT24 : 1;
        byte BIT25 : 1;
        byte BIT26 : 1;
        byte BIT27 : 1;
        byte BIT28 : 1;
        byte BIT29 : 1;
        byte BIT30 : 1;
        byte BIT31 : 1;                
    } BITS;

} STRFLG32;



#define FLASH_RAM_ArrayCon    200
#define FLASH_FLASH_ArrayCon  200
#define MODEL420               1
#define MODEL410               0
#define M410DelMainBusPg       5  //410型号去除市电部分菜单
#define M410DelAdjMBusPg       3  //410型号去除市电部分参数校验菜单

extern volatile STRFLG16 TimeStamp;
#define TIME_STAMP_100MS TimeStamp.BITS.BIT0
#define TIME_STAMP_200MS TimeStamp.BITS.BIT1
#define TIME_STAMP_300MS TimeStamp.BITS.BIT2
#define TIME_STAMP_500MS TimeStamp.BITS.BIT3
#define TIME_STAMP_1S    TimeStamp.BITS.BIT4
#define TIME_STAMP_30S   TimeStamp.BITS.BIT5
#define TIME_STAMP_1MIN  TimeStamp.BITS.BIT6
#define TIME_STAMP_30MIN TimeStamp.BITS.BIT7
#define TIME_STAMP_1HOUR TimeStamp.BITS.BIT8

 #define ALARMINGCON  7 
 extern  STRFLG16 AlarmMaping[ALARMINGCON];
 #define GensStopAlarm1       AlarmMaping[0]     //停机状态映射
 #define GensStopAlarm2       AlarmMaping[1]
 #define GensWarningAlarm1    AlarmMaping[2]     //??
 #define GensWarningAlarm2    AlarmMaping[3]
 #define GensRunStation1      AlarmMaping[4]
 #define GensRunStation2      AlarmMaping[5]
 #define GensRunStation3      AlarmMaping[6]
 
 /***********************************************************************/
 /*                    临时增加定义                                                 */
 /***********************************************************************/
#define sAdjParmPageCon          18   //GEC400控参数整定页面数量

/* ******************************************************************** */
/*                       显示参数校验映射                               */
/* ******************************************************************** */
 #define AdjDataMapCon		sAdjParmPageCon
  extern STRFLG16 AdjDataMapBuf[AdjDataMapCon];  //实时显示修改参数校验数据映射数组
 
  #define AdjMapVOLTAGEA2       AdjDataMapBuf[0].Sbyte//市电A电压校验
  #define AdjMapVOLTAGEB2       AdjDataMapBuf[1].Sbyte//市电B电压校验
  #define AdjMapVOLTAGEC2       AdjDataMapBuf[2].Sbyte//市电C电压校验
  #define AdjMapVOLTAGEA1       AdjDataMapBuf[3].Sbyte//发电A电压校验
  #define AdjMapVOLTAGEB1       AdjDataMapBuf[4].Sbyte//发电B电压校验
  #define AdjMapVOLTAGEC1       AdjDataMapBuf[5].Sbyte//发电C电压校验
  #define AdjMapCURRENTA        AdjDataMapBuf[6].Sbyte//A相电流校验
  #define AdjMapCURRENTB        AdjDataMapBuf[7].Sbyte//B相电流校验
  #define AdjMapCURRENTC        AdjDataMapBuf[8].Sbyte//C相电流校验
  #define AdjMapWATERTEMP       AdjDataMapBuf[9].Sbyte//水缸温校验
  #define AdjMapOILPRESSURE     AdjDataMapBuf[10].Sbyte//机油压力校验
  #define AdjMapFUEL            AdjDataMapBuf[11].Sbyte//燃油位校验
  #define AdjMapCustomAog       AdjDataMapBuf[12].Sbyte//自定义模拟量校验
  #define AdjMapPowerVoltage    AdjDataMapBuf[13].Sbyte//电池电压校验
  #define AdjMapChargerVoltage  AdjDataMapBuf[14].Sbyte//充电机D+
  #define AdjMapPhaseCOS        AdjDataMapBuf[15].Sbyte//发电功率因数

void DB_JudgeParm(void);

extern STRFLG16 RAMDATABASE[FLASH_RAM_ArrayCon];
extern STRFLG16 FLASHDATABASE[FLASH_FLASH_ArrayCon];
extern M_INT8U  POWERLOSS;
 void DBRestore_Factory_settings(void);
 M_INT08U DB_JudgeCurveInitDRN(M_INT16U JudgeCurveData,M_INT08U CurvePgID,M_INT08U CurveID);
 void DBJudgeReadOutpParm(void);
 void DBJudgeReadOutsAdjParm(void);	
 void DBJudgeReadOutcCurveParm(void);
 void DBJudgeReadOutOtherParm(void);
 void PubCAN_DisTblRefresh(void);	


////////----------语言标志-------
//extern INT16U Language_select;     //语言类型   
#define  LCD_LanguageEnglish     0    //0:英文
#define  LCD_LanguageChinese     1	  //1:中文

#define  GensRunMSaveCon     10                                    //发动机运行参数保存flash位置 个数
#define  GensRunMSaveCtr     (FLASH_FLASH_ArrayCon-GensRunMSaveCon)  //发动机运行参数保存flash位置 
#define  GensDateErrStaCon   10                                    //发动机运行参数保存flash位置 个数
#define  GensDateErrSta     (FLASH_RAM_ArrayCon-GensDateErrStaCon)   //从flash中读取参数状态
/* ******************************************************************** */
/*                    ENUM  Flash Memery Definitions                    */
/* ******************************************************************** */

const typedef enum   //参数设置子菜单枚举类型  sPn --> sParmSetnum 
{
 /*-00-*/     sPn_NON_NON                =0 ,//备用
 /*-01-*/     sPn_MAINS_NORMAL_DEL       =0 ,//市电正常延时
 /*-02-*/     sPn_MAINS_OBNORMAL_DEL     =1 ,//市电异常延时
 /*-03-*/     sPn_MAINS_VOLT_LOW            ,//市电欠压阀值
 /*-04-*/     sPn_MAINS_VOLT_HIGH           ,//市电过压阀值      
 /*-05-*/     sPn_MAINS_TRANS_DEL           ,//开关转换延时
 /*-06-*/     sPn_AMF_START_DEL             ,//开机延时
 /*-07-*/     sPn_AMF_STOP_DEL              ,//停机延时
 /*-08-*/     sPn_DES_START_NUM             ,//起动次数
 /*-09-*/     sPn_DES_PREHEAT_DEL           ,//预热时间
 /*-10-*/     sPn_DES_CRANK_DEL             ,//起动时间
 /*-11-*/     sPn_DES_CRANKINT_DEL          ,//起动间隔时间
 /*-12-*/     sPn_DES_SAFE_DEL              ,//安全运行时间 
 /*-13-*/     sPn_DES_STARTIDLE_DEL         ,//开机怠速时间
 /*-14-*/     sPn_DES_WARM_DEL              ,//暖机时间
 /*-15-*/     sPn_DES_COOLING_DEL           ,//散热时间
 /*-16-*/     sPn_DES_STOPIDLE_DEL          ,//停机怠速时间
 /*-17-*/     sPn_DES_STOPOUTPUT_DEL        ,//得电停机时间
 /*-18-*/     sPn_DES_STOPSUCC_DEL          ,//等待停稳延时
 /*-19-*/     sPn_GEN_MCBGCB_DEL            ,//开关合闸延时
 /*-20-*/     sPn_DES_GEARTEETH             ,//飞轮齿数
 /*-21-*/     sPn_GEN_OBNORMAL_DEL          ,//发电异常延时
 /*-22-*/     sPn_GEN_VOLTHIGH_STOP         ,//发电过压阀值停机
 /*-23-*/     sPn_GEN_VOLTLOW_STOP          ,//发电欠压阀值停机
 /*-24-*/     sPn_DES_LOWSPEED              ,//欠速阀值
 /*-25-*/     sPn_DES_HIGHSPEED             ,//超速阀值
 /*-26-*/     sPn_GEN_FREQLOW               ,//发电欠频阀值
 /*-27-*/     sPn_GEN_FREQHIGH              ,//发电过频阀值
 /*-28-*/     sPn_DES_HITEMP                ,//高水温阀值
 /*-29-*/     sPn_DES_LOWOP                 ,//低油压阀值
 /*-30-*/     sPn_DES_LOWLEVEL              ,//燃油位阀值
 /*-31-*/     sPn_DES_LOSTSPEED_DEL         ,//速度信号丢失延时
 /*-32-*/     sPn_DES_CHARGEFAULT           ,//充电失败阀值
 /*-33-*/     sPn_DES_BATTHI                ,//电池过压阀值
 /*-34-*/     sPn_DES_BATTLOW               ,//电池欠压阀值
 /*-35-*/     sPn_GEN_CT                    ,//电流互感器变比
 /*-36-*/     sPn_GEN_RATINGCURRENT         ,//满载电流
 /*-37-*/     sPn_GEN_OVERCURRENT           ,//过流百分比
 /*-38-*/     sPn_GEN_OVERCURRENT_DEL       ,//过流延时
 /*-39-*/     sPn_DES_FUELPUMP_ON           ,//燃油泵开阀值
 /*-40-*/     sPn_DES_FUELPUMP_OFF          ,//燃油泵关阀值
 /*-41-*/     sPn_COMMON_OUTPUTFUNC1        ,//可编程输出1功能
 /*-42-*/     sPn_COMMON_OUTPUTFUNC2        ,//可编程输出2功能
 /*-43-*/     sPn_COMMON_OUTPUTFUNC3        ,//可编程输出3功能
 /*-44-*/     sPn_COMMON_OUTPUTFUNC4        ,//可编程输出4功能
 /*-45-*/     sPn_COMMON_OUTPUTFUNC5        ,//可编程输出5功能
 /*-46-*/     sPn_COMMON_OUTPUTFUNC6        ,//可编程输出6功能
 /*-47-*/     sPn_COMMON_INPUTFUNC1         ,//可编程输入1功能
 /*-48-*/     sPn_COMMON_INPUTFUNC1_VALID   ,//可编程输入1有效
 /*-49-*/     sPn_COMMON_INPUTFUNC1_DELAY   ,//可编程输入1延时
 /*-50-*/     sPn_COMMON_INPUTFUNC2         ,//可编程输入2功能
 /*-51-*/     sPn_COMMON_INPUTFUNC2_VALID   ,//可编程输入2有效
 /*-52-*/     sPn_COMMON_INPUTFUNC2_DELAY   ,//可编程输入2延时
 /*-53-*/     sPn_COMMON_INPUTFUNC3         ,//可编程输入3功能
 /*-54-*/     sPn_COMMON_INPUTFUNC3_VALID   ,//可编程输入3有效
 /*-55-*/     sPn_COMMON_INPUTFUNC3_DELAY   ,//可编程输入3延时
 /*-56-*/     sPn_DES_STARTINIT             ,//开机状态选择
 /*-57-*/     sPn_COMMON_ADDR               ,//控制器地址选择
 /*-58-*/     sPn_DES_PASSWORD              ,//口令设置
 /*-59-*/     sPn_DES_STARTSUCC_CONDITION   ,//起动成功条件
 /*-60-*/     sPn_DES_STARTSUCC_SPEED       ,//起动成功转速
 /*-61-*/     sPn_DES_STARTSUCC_FREQ        ,//起动成功频率
 /*-62-*/     sPn_DES_STARTSUCC_OP          ,//起动成功油压
 /*-63-*/     sPn_DES_TEMPHIGH_NOSTOP       ,//温度高禁止停机
 /*-64-*/     sPn_DES_OPLOW_NOSTOP          ,//油压低禁止停机
 /*-65-*/     sPn_GEN_VOLT_TYPE             ,//电压输入类型选择
 /*-66-*/     sPn_DES_TEMP_SENSOR           ,//温度传感器选择
 /*-67-*/     sPn_DES_OP_SENSOR             ,//压力传感器选择
 /*-68-*/     sPn_DES_LV_SENSOR             ,//液位传感器选择
 /*-69-*/     sPn_GEN_POLENUM               ,//发电机极数
 /*-70-*/     sPn_BREAK_TEMP_SENSOR         ,//温度传感器断线动作选择
 /*-71-*/     sPn_BREAK_OP_SENSOR           ,//压力传感器断线动作选择
 /*-72-*/     sPn_BREAK_LV_SENSOR           ,//液位传感器开路动作
 /*-73-*/     sPn_CUSTOM_SENSOR_TYPE        ,//自定义曲线序号
 /*-74-*/     sPn_GENS_TYPE                 ,//发动机类型 普通机/J1939电喷机
 /*-75-*/     sPn_LanguageTYPE_Selection    ,//控制器语言类型
/*-76-*/      sPa_VOLT_MAINS_A,//市电A电压校验	//参数校验	 sPa --> sParmAdj 
/*-77-*/      sPa_VOLT_MAINS_B,//市电B电压校验
/*-78-*/      sPa_VOLT_MAINS_C,//市电C电压校验
/*-79-*/      sPa_VOLT_GEN_A  ,//发电A电压校验
/*-80-*/      sPa_VOLT_GEN_B  ,//发电B电压校验
/*-81-*/  	  sPa_VOLT_GEN_C  ,//发电C电压校验
/*-82-*/      sPa_CURRENT_A   ,//A相电流校验
/*-83-*/      sPa_CURRENT_B   ,//B相电流校验
/*-84-*/      sPa_CURRENT_C   ,//C相电流校验
/*-85-*/      sPa_TEMP        ,//水缸温校验
/*-86-*/  	  sPa_OP          ,//机油压力校验
/*-87-*/      sPa_LEVEL       ,//燃油位校验	/自定义1
/*-88-*/      sPa_CustomAnalog,//           /自定义2
/*-89-*/      sPa_BATT        ,//电池电压校验
/*-90-*/      sPa_CHARGER     ,//充电机D+
/*-91-*/      sPa_COS         ,//发电功率因数
/*-92-*/      sPa_MODEL       ,//控制器选择
/*-93-*/      sPa_RestFactory ,//恢复出厂参数设置
/*-94-*/      sPc_TEMP_R1, //温度自定义传感器曲线	sPc --> sParmCus 
/*-95-*/      sPc_TEMP_R2,
/*-96-*/      sPc_TEMP_R3,
/*-97-*/      sPc_TEMP_R4,
/*-98-*/      sPc_TEMP_R5,
/*-99-*/      sPc_TEMP_R6,
/*-100-*/     sPc_TEMP_R7,
/*-101-*/     sPc_TEMP_R8,
/*-102-*/     sPc_TEMP_V1,
/*-103-*/     sPc_TEMP_V2,
/*-104-*/     sPc_TEMP_V3,
/*-105-*/     sPc_TEMP_V4,
/*-106-*/     sPc_TEMP_V5,
/*-107-*/     sPc_TEMP_V6,
/*-108-*/     sPc_TEMP_V7,
/*-109-*/     sPc_TEMP_V8,
/*-110-*/     sPc_OP_R1,   //压力自定义传感器曲线
/*-111-*/     sPc_OP_R2, 
/*-112-*/     sPc_OP_R3, 
/*-113-*/     sPc_OP_R4, 
/*-114-*/     sPc_OP_R5, 
/*-115-*/     sPc_OP_R6, 
/*-116-*/     sPc_OP_R7, 
/*-117-*/     sPc_OP_R8, 
/*-118-*/     sPc_OP_V1, 
/*-119-*/     sPc_OP_V2, 
/*-120-*/     sPc_OP_V3, 
/*-121-*/     sPc_OP_V4, 
/*-122-*/     sPc_OP_V5, 
/*-123-*/     sPc_OP_V6, 
/*-124-*/     sPc_OP_V7, 
/*-125-*/     sPc_OP_V8, 
/*-126-*/     sPc_LV_R1, 	//液位自定义传感器曲线 
/*-127-*/     sPc_LV_R2, 
/*-128-*/     sPc_LV_R3, 
/*-129-*/     sPc_LV_R4, 
/*-130-*/     sPc_LV_R5, 
/*-131-*/     sPc_LV_R6, 
/*-132-*/     sPc_LV_R7, 
/*-133-*/     sPc_LV_R8, 
/*-134-*/     sPc_LV_V1, 
/*-135-*/     sPc_LV_V2, 
/*-136-*/     sPc_LV_V3, 
/*-137-*/     sPc_LV_V4, 
/*-138-*/     sPc_LV_V5, 
/*-139-*/     sPc_LV_V6, 
/*-140-*/     sPc_LV_V7, 
/*-141-*/     sPc_LV_V8,
/*-142-*/     sPc_REUSE_R1, 	//自定义传感器曲线 复用2
/*-143-*/     sPc_REUSE_R2, 
/*-144-*/     sPc_REUSE_R3, 
/*-145-*/     sPc_REUSE_R4, 
/*-146-*/     sPc_REUSE_R5, 
/*-147-*/     sPc_REUSE_R6, 
/*-148-*/     sPc_REUSE_R7, 
/*-149-*/     sPc_REUSE_R8, 
/*-150-*/     sPc_REUSE_V1, 
/*-151-*/     sPc_REUSE_V2, 
/*-152-*/     sPc_REUSE_V3, 
/*-153-*/     sPc_REUSE_V4,
/*-154-*/     sPc_REUSE_V5,
/*-155-*/     sCtl_CONTROL_CONFIRM          ,//RS485遥控
/*-156-*/     sCtl_CONTROL_COMMAND          ,//RS485遥控命令 
/*-157-*/     sPc_REUSE_V6,
/*-158-*/     sPc_REUSE_V7, 
/*-159-*/     sPc_REUSE_V8,
} sParmSetHeadnum;                       

			 
/* ******************************************************************** */
/*                    FLASH  Measurement Definitions                    */
/* ******************************************************************** */
							 
/*-01-*/ #define MAINS_NORMAL_DEL             FLASHDATABASE[sPn_MAINS_NORMAL_DEL        ].Sbyte //市电正常延时
/*-02-*/ #define MAINS_OBNORMAL_DEL           FLASHDATABASE[sPn_MAINS_OBNORMAL_DEL      ].Sbyte //市电异常延时
/*-03-*/ #define MAINS_VOLT_LOW               FLASHDATABASE[sPn_MAINS_VOLT_LOW          ].Sbyte //市电欠压阀值
/*-04-*/ #define MAINS_VOLT_HIGH              FLASHDATABASE[sPn_MAINS_VOLT_HIGH         ].Sbyte //市电过压阀值      
/*-05-*/ #define MAINS_TRANS_DEL              FLASHDATABASE[sPn_MAINS_TRANS_DEL         ].Sbyte //开关转换延时
/*-06-*/ #define AMF_START_DEL                FLASHDATABASE[sPn_AMF_START_DEL           ].Sbyte //开机延时
/*-07-*/ #define AMF_STOP_DEL                 FLASHDATABASE[sPn_AMF_STOP_DEL            ].Sbyte //停机延时
/*-08-*/ #define DES_START_NUM                FLASHDATABASE[sPn_DES_START_NUM           ].Sbyte //启动次数
/*-09-*/ #define DES_PREHEAT_DEL              FLASHDATABASE[sPn_DES_PREHEAT_DEL         ].Sbyte //预热时间
/*-10-*/ #define DES_CRANK_DEL                FLASHDATABASE[sPn_DES_CRANK_DEL           ].Sbyte //启动时间
/*-11-*/ #define DES_CRANKINT_DEL             FLASHDATABASE[sPn_DES_CRANKINT_DEL        ].Sbyte//启动间隔时间
/*-12-*/ #define DES_SAFE_DEL                 FLASHDATABASE[sPn_DES_SAFE_DEL            ].Sbyte//安全运行时间
/*-13-*/ #define DES_STARTIDLE_DEL            FLASHDATABASE[sPn_DES_STARTIDLE_DEL       ].Sbyte//开机怠速时间
/*-14-*/ #define DES_WARM_DEL                 FLASHDATABASE[sPn_DES_WARM_DEL            ].Sbyte//暖机时间
/*-15-*/ #define DES_COOLING_DEL              FLASHDATABASE[sPn_DES_COOLING_DEL         ].Sbyte//散热时间
/*-16-*/ #define DES_STOPIDLE_DEL             FLASHDATABASE[sPn_DES_STOPIDLE_DEL        ].Sbyte//停机怠速时间
/*-17-*/ #define DES_STOPOUTPUT_DEL           FLASHDATABASE[sPn_DES_STOPOUTPUT_DEL      ].Sbyte//得电停机时间
/*-18-*/ #define DES_STOPSUCC_DEL             FLASHDATABASE[sPn_DES_STOPSUCC_DEL        ].Sbyte//等待停稳延时
/*-19-*/ #define GEN_MCBGCB_DEL               FLASHDATABASE[sPn_GEN_MCBGCB_DEL          ].Sbyte//开关合闸延时
/*-20-*/ #define DES_GEARTEETH                FLASHDATABASE[sPn_DES_GEARTEETH           ].Sbyte//飞轮齿数
/*-21-*/ #define GEN_OBNORMAL_DEL             FLASHDATABASE[sPn_GEN_OBNORMAL_DEL        ].Sbyte//发电异常延时
/*-22-*/ #define GEN_VOLTHIGH_STOP            FLASHDATABASE[sPn_GEN_VOLTHIGH_STOP       ].Sbyte//发电过压阀值停机
/*-23-*/ #define GEN_VOLTLOW_STOP             FLASHDATABASE[sPn_GEN_VOLTLOW_STOP        ].Sbyte//发电欠压阀值停机
/*-24-*/ #define DES_LOWSPEED                 FLASHDATABASE[sPn_DES_LOWSPEED            ].Sbyte//欠速阀值
/*-25-*/ #define DES_HIGHSPEED                FLASHDATABASE[sPn_DES_HIGHSPEED           ].Sbyte//超速阀值
/*-26-*/ #define GEN_FREQLOW                  FLASHDATABASE[sPn_GEN_FREQLOW             ].Sbyte//发电欠频阀值
/*-27-*/ #define GEN_FREQHIGH                 FLASHDATABASE[sPn_GEN_FREQHIGH            ].Sbyte//发电过频阀值
/*-28-*/ #define DES_HITEMP                   FLASHDATABASE[sPn_DES_HITEMP              ].Sbyte//高水温阀值
/*-29-*/ #define DES_LOWOP                    FLASHDATABASE[sPn_DES_LOWOP               ].Sbyte//低油压阀值
/*-30-*/ #define DES_LOWLEVEL                 FLASHDATABASE[sPn_DES_LOWLEVEL            ].Sbyte//燃油位阀值
/*-31-*/ #define DES_LOSTSPEED_DEL            FLASHDATABASE[sPn_DES_LOSTSPEED_DEL       ].Sbyte//速度信号丢失延时
/*-32-*/ #define DES_CHARGEFAULT              FLASHDATABASE[sPn_DES_CHARGEFAULT         ].Sbyte//充电失败阀值
/*-33-*/ #define DES_BATTHI                   FLASHDATABASE[sPn_DES_BATTHI              ].Sbyte//电池过压阀值
/*-34-*/ #define DES_BATTLOW                  FLASHDATABASE[sPn_DES_BATTLOW             ].Sbyte//电池欠压阀值
/*-35-*/ #define GEN_CT                       FLASHDATABASE[sPn_GEN_CT                  ].Sbyte//电流互感器变比
/*-36-*/ #define GEN_RATINGCURRENT            FLASHDATABASE[sPn_GEN_RATINGCURRENT       ].Sbyte//满载电流
/*-37-*/ #define GEN_OVERCURRENT              FLASHDATABASE[sPn_GEN_OVERCURRENT         ].Sbyte//过流百分比
/*-38-*/ #define GEN_OVERCURRENT_DEL          FLASHDATABASE[sPn_GEN_OVERCURRENT_DEL     ].Sbyte//过流延时
/*-39-*/ #define DES_FUELPUMP_ON              FLASHDATABASE[sPn_DES_FUELPUMP_ON         ].Sbyte//燃油泵开阀值
/*-40-*/ #define DES_FUELPUMP_OFF             FLASHDATABASE[sPn_DES_FUELPUMP_OFF        ].Sbyte//燃油泵关阀值
/*-41-*/ #define COMMON_OUTPUTFUNC1           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC1      ].Sbyte//可编程输出1功能
/*-42-*/ #define COMMON_OUTPUTFUNC2           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC2      ].Sbyte//可编程输出2功能
/*-43-*/ #define COMMON_OUTPUTFUNC3           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC3      ].Sbyte//可编程输出3功能
/*-44-*/ #define COMMON_OUTPUTFUNC4           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC4      ].Sbyte//可编程输出4功能
/*-45-*/ #define COMMON_OUTPUTFUNC5           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC5      ].Sbyte//可编程输出5功能
/*-46-*/ #define COMMON_OUTPUTFUNC6           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC6      ].Sbyte//可编程输出6功能
/*-47-*/ #define COMMON_INPUTFUNC1            FLASHDATABASE[sPn_COMMON_INPUTFUNC1       ].Sbyte//可编程输入1功能
/*-48-*/ #define COMMON_INPUTFUNC1_VALID      FLASHDATABASE[sPn_COMMON_INPUTFUNC1_VALID ].Sbyte//可编程输入1有效
/*-49-*/ #define COMMON_INPUTFUNC1_DELAY      FLASHDATABASE[sPn_COMMON_INPUTFUNC1_DELAY ].Sbyte//可编程输入1延时
/*-50-*/ #define COMMON_INPUTFUNC2            FLASHDATABASE[sPn_COMMON_INPUTFUNC2       ].Sbyte//可编程输入2功能
/*-51-*/ #define COMMON_INPUTFUNC2_VALID      FLASHDATABASE[sPn_COMMON_INPUTFUNC2_VALID ].Sbyte//可编程输入2有效
/*-52-*/ #define COMMON_INPUTFUNC2_DELAY      FLASHDATABASE[sPn_COMMON_INPUTFUNC2_DELAY ].Sbyte//可编程输入2延时
/*-53-*/ #define COMMON_INPUTFUNC3            FLASHDATABASE[sPn_COMMON_INPUTFUNC3       ].Sbyte//可编程输入3功能
/*-54-*/ #define COMMON_INPUTFUNC3_VALID      FLASHDATABASE[sPn_COMMON_INPUTFUNC3_VALID ].Sbyte//可编程输入3有效
/*-55-*/ #define COMMON_INPUTFUNC3_DELAY      FLASHDATABASE[sPn_COMMON_INPUTFUNC3_DELAY ].Sbyte//可编程输入3延时
/*-56-*/ #define DES_STARTINIT                FLASHDATABASE[sPn_DES_STARTINIT           ].Sbyte//开机状态选择
/*-57-*/ #define COMMON_ADDR                  FLASHDATABASE[sPn_COMMON_ADDR             ].Sbyte//控制器地址选择
/*-58-*/ #define DES_PASSWORD                 FLASHDATABASE[sPn_DES_PASSWORD            ].Sbyte//口令设置
/*-59-*/ #define DES_STARTSUCC_CONDITION      FLASHDATABASE[sPn_DES_STARTSUCC_CONDITION ].Sbyte//启动成功条件
/*-60-*/ #define DES_STARTSUCC_SPEED          FLASHDATABASE[sPn_DES_STARTSUCC_SPEED     ].Sbyte//启动成功转速
/*-61-*/ #define DES_STARTSUCC_FREQ           FLASHDATABASE[sPn_DES_STARTSUCC_FREQ      ].Sbyte//启动成功频率
/*-62-*/ #define DES_STARTSUCC_OP             FLASHDATABASE[sPn_DES_STARTSUCC_OP        ].Sbyte//启动成功油压
/*-63-*/ #define DES_TEMPHIGH_NOSTOP          FLASHDATABASE[sPn_DES_TEMPHIGH_NOSTOP     ].Sbyte//温度高禁止停机
/*-64-*/ #define DES_OPLOW_NOSTOP             FLASHDATABASE[sPn_DES_OPLOW_NOSTOP        ].Sbyte//油压低禁止停机
/*-65-*/ #define GEN_VOLT_TYPE                FLASHDATABASE[sPn_GEN_VOLT_TYPE           ].Sbyte//电压输入类型选择
/*-66-*/ #define DES_TEMP_SENSOR              FLASHDATABASE[sPn_DES_TEMP_SENSOR         ].Sbyte//温度传感器选择
/*-67-*/ #define DES_OP_SENSOR                FLASHDATABASE[sPn_DES_OP_SENSOR           ].Sbyte//压力传感器选择
/*-68-*/ #define DES_LV_SENSOR                FLASHDATABASE[sPn_DES_LV_SENSOR           ].Sbyte//液位传感器选择
/*-69-*/ #define GEN_POLENUM                  FLASHDATABASE[sPn_GEN_POLENUM             ].Sbyte//发电机极数
/*-70-*/ #define BREAK_TEMP_SENSOR            FLASHDATABASE[sPn_BREAK_TEMP_SENSOR       ].Sbyte//温度传感器断线动作选择
/*-71-*/ #define BREAK_OP_SENSOR    	        FLASHDATABASE[sPn_BREAK_OP_SENSOR         ].Sbyte//压力传感器断线动作选择
/*-72-*/ #define BREAK_LV_SENSOR	            FLASHDATABASE[sPn_BREAK_LV_SENSOR         ].Sbyte//液位传感器断线动作选择
/*-73-*/ #define CUSTOM_SENSOR_TYPE           FLASHDATABASE[sPn_CUSTOM_SENSOR_TYPE      ].Sbyte//自定义曲线序号
/*-74-*/ #define GES_GENS_TYPE                FLASHDATABASE[sPn_GENS_TYPE               ].Sbyte//发动机类型 普通机/J1939电喷机
/*-75-*/ #define Language_select              FLASHDATABASE[sPn_LanguageTYPE_Selection  ].Sbyte//控制器语言类型
/*-76-*/ #define RECAL_VOLT_MAINS_A           FLASHDATABASE[sPa_VOLT_MAINS_A            ].Sbyte//市电A电压校验	 // Adjust  Measurement Definitions  
/*-77-*/ #define RECAL_VOLT_MAINS_B           FLASHDATABASE[sPa_VOLT_MAINS_B            ].Sbyte//市电B电压校验
/*-78-*/ #define RECAL_VOLT_MAINS_C           FLASHDATABASE[sPa_VOLT_MAINS_C            ].Sbyte//市电C电压校验
/*-79-*/ #define RECAL_VOLT_GEN_A             FLASHDATABASE[sPa_VOLT_GEN_A              ].Sbyte//发电A电压校验
/*-80-*/ #define RECAL_VOLT_GEN_B             FLASHDATABASE[sPa_VOLT_GEN_B              ].Sbyte//发电B电压校验
/*-81-*/ #define RECAL_VOLT_GEN_C             FLASHDATABASE[sPa_VOLT_GEN_C              ].Sbyte//发电C电压校验
/*-82-*/ #define RECAL_CURRENT_A              FLASHDATABASE[sPa_CURRENT_A               ].Sbyte//A相电流校验
/*-83-*/ #define RECAL_CURRENT_B              FLASHDATABASE[sPa_CURRENT_B               ].Sbyte//B相电流校验
/*-84-*/ #define RECAL_CURRENT_C              FLASHDATABASE[sPa_CURRENT_C               ].Sbyte//C相电流校验
/*-85-*/ #define RECAL_TEMP                   FLASHDATABASE[sPa_TEMP                    ].Sbyte//水缸温校验
/*-86-*/ #define RECAL_OP                     FLASHDATABASE[sPa_OP                      ].Sbyte//机油压力校验
/*-87-*/ #define RECAL_LEVEL                  FLASHDATABASE[sPa_LEVEL                   ].Sbyte//燃油位校验
/*-88-*/ #define RECAL_CustomAnalog           FLASHDATABASE[sPa_CustomAnalog            ].Sbyte//自定义模拟量校验
/*-89-*/ #define RECAL_BATT                   FLASHDATABASE[sPa_BATT                    ].Sbyte//电池电压校验
/*-90-*/ #define RECAL_CHARGER                FLASHDATABASE[sPa_CHARGER                 ].Sbyte//充电机D+
/*-91-*/ #define RECAL_COS                    FLASHDATABASE[sPa_COS                     ].Sbyte//发电功率因数
/*-92-*/ #define COMMON_MODEL                 FLASHDATABASE[sPa_MODEL                   ].Sbyte//控制器选择
/*-93-*/ #define Ctl_RestFactory	            FLASHDATABASE[sPa_RestFactory             ].Sbyte //恢复出厂参数设置
/*-94-*/ #define DES_CUSTOM_SENSOR_TEMP_R1    FLASHDATABASE[sPc_TEMP_R1 ].Sbyte//温度自定义传感器曲线 
/*-95-*/ #define DES_CUSTOM_SENSOR_TEMP_R2    FLASHDATABASE[sPc_TEMP_R2 ].Sbyte
/*-96-*/ #define DES_CUSTOM_SENSOR_TEMP_R3    FLASHDATABASE[sPc_TEMP_R3 ].Sbyte
/*-97-*/ #define DES_CUSTOM_SENSOR_TEMP_R4    FLASHDATABASE[sPc_TEMP_R4 ].Sbyte
/*-98-*/ #define DES_CUSTOM_SENSOR_TEMP_R5    FLASHDATABASE[sPc_TEMP_R5 ].Sbyte
/*-99-*/ #define DES_CUSTOM_SENSOR_TEMP_R6    FLASHDATABASE[sPc_TEMP_R6 ].Sbyte
/*-100-*/#define DES_CUSTOM_SENSOR_TEMP_R7    FLASHDATABASE[sPc_TEMP_R7 ].Sbyte
/*-101-*/#define DES_CUSTOM_SENSOR_TEMP_R8    FLASHDATABASE[sPc_TEMP_R8 ].Sbyte
/*-102-*/#define DES_CUSTOM_SENSOR_TEMP_V1    FLASHDATABASE[sPc_TEMP_V1 ].Sbyte
/*-103-*/#define DES_CUSTOM_SENSOR_TEMP_V2    FLASHDATABASE[sPc_TEMP_V2 ].Sbyte
/*-104-*/#define DES_CUSTOM_SENSOR_TEMP_V3    FLASHDATABASE[sPc_TEMP_V3 ].Sbyte
/*-105-*/#define DES_CUSTOM_SENSOR_TEMP_V4    FLASHDATABASE[sPc_TEMP_V4 ].Sbyte
/*-106-*/#define DES_CUSTOM_SENSOR_TEMP_V5    FLASHDATABASE[sPc_TEMP_V5 ].Sbyte
/*-107-*/#define DES_CUSTOM_SENSOR_TEMP_V6    FLASHDATABASE[sPc_TEMP_V6 ].Sbyte
/*-108-*/#define DES_CUSTOM_SENSOR_TEMP_V7    FLASHDATABASE[sPc_TEMP_V7 ].Sbyte
/*-109-*/#define DES_CUSTOM_SENSOR_TEMP_V8    FLASHDATABASE[sPc_TEMP_V8 ].Sbyte
/*-110-*/#define DES_CUSTOM_SENSOR_OP_R1      FLASHDATABASE[sPc_OP_R1   ].Sbyte//压力自定义传感器曲线
/*-111-*/#define DES_CUSTOM_SENSOR_OP_R2      FLASHDATABASE[sPc_OP_R2   ].Sbyte
/*-112-*/#define DES_CUSTOM_SENSOR_OP_R3      FLASHDATABASE[sPc_OP_R3   ].Sbyte
/*-113-*/#define DES_CUSTOM_SENSOR_OP_R4      FLASHDATABASE[sPc_OP_R4   ].Sbyte
/*-114-*/#define DES_CUSTOM_SENSOR_OP_R5      FLASHDATABASE[sPc_OP_R5   ].Sbyte
/*-115-*/#define DES_CUSTOM_SENSOR_OP_R6      FLASHDATABASE[sPc_OP_R6   ].Sbyte
/*-116-*/#define DES_CUSTOM_SENSOR_OP_R7      FLASHDATABASE[sPc_OP_R7   ].Sbyte
/*-117-*/#define DES_CUSTOM_SENSOR_OP_R8      FLASHDATABASE[sPc_OP_R8   ].Sbyte
/*-118-*/#define DES_CUSTOM_SENSOR_OP_V1      FLASHDATABASE[sPc_OP_V1   ].Sbyte
/*-119-*/#define DES_CUSTOM_SENSOR_OP_V2      FLASHDATABASE[sPc_OP_V2   ].Sbyte
/*-120-*/#define DES_CUSTOM_SENSOR_OP_V3      FLASHDATABASE[sPc_OP_V3   ].Sbyte
/*-121-*/#define DES_CUSTOM_SENSOR_OP_V4      FLASHDATABASE[sPc_OP_V4   ].Sbyte
/*-122-*/#define DES_CUSTOM_SENSOR_OP_V5      FLASHDATABASE[sPc_OP_V5   ].Sbyte
/*-123-*/#define DES_CUSTOM_SENSOR_OP_V6      FLASHDATABASE[sPc_OP_V6   ].Sbyte
/*-124-*/#define DES_CUSTOM_SENSOR_OP_V7      FLASHDATABASE[sPc_OP_V7   ].Sbyte
/*-125-*/#define DES_CUSTOM_SENSOR_OP_V8      FLASHDATABASE[sPc_OP_V8   ].Sbyte
/*-126-*/#define DES_CUSTOM_SENSOR_LV_R1      FLASHDATABASE[sPc_LV_R1   ].Sbyte//液位自定义传感器曲线 复用1
/*-127-*/#define DES_CUSTOM_SENSOR_LV_R2      FLASHDATABASE[sPc_LV_R2   ].Sbyte
/*-128-*/#define DES_CUSTOM_SENSOR_LV_R3      FLASHDATABASE[sPc_LV_R3   ].Sbyte
/*-129-*/#define DES_CUSTOM_SENSOR_LV_R4      FLASHDATABASE[sPc_LV_R4   ].Sbyte
/*-130-*/#define DES_CUSTOM_SENSOR_LV_R5      FLASHDATABASE[sPc_LV_R5   ].Sbyte
/*-131-*/#define DES_CUSTOM_SENSOR_LV_R6      FLASHDATABASE[sPc_LV_R6   ].Sbyte
/*-132-*/#define DES_CUSTOM_SENSOR_LV_R7      FLASHDATABASE[sPc_LV_R7   ].Sbyte
/*-133-*/#define DES_CUSTOM_SENSOR_LV_R8      FLASHDATABASE[sPc_LV_R8   ].Sbyte
/*-134-*/#define DES_CUSTOM_SENSOR_LV_V1      FLASHDATABASE[sPc_LV_V1   ].Sbyte
/*-135-*/#define DES_CUSTOM_SENSOR_LV_V2      FLASHDATABASE[sPc_LV_V2   ].Sbyte
/*-136-*/#define DES_CUSTOM_SENSOR_LV_V3      FLASHDATABASE[sPc_LV_V3   ].Sbyte
/*-137-*/#define DES_CUSTOM_SENSOR_LV_V4      FLASHDATABASE[sPc_LV_V4   ].Sbyte
/*-138-*/#define DES_CUSTOM_SENSOR_LV_V5      FLASHDATABASE[sPc_LV_V5   ].Sbyte
/*-139-*/#define DES_CUSTOM_SENSOR_LV_V6      FLASHDATABASE[sPc_LV_V6   ].Sbyte
/*-140-*/#define DES_CUSTOM_SENSOR_LV_V7      FLASHDATABASE[sPc_LV_V7   ].Sbyte
/*-141-*/#define DES_CUSTOM_SENSOR_LV_V8      FLASHDATABASE[sPc_LV_V8   ].Sbyte
/*-142-*/#define DES_CUSTOM_SENSOR_REUSE_R1   FLASHDATABASE[sPc_REUSE_R1].Sbyte//自定义传感器曲线	复用2
/*-143-*/#define DES_CUSTOM_SENSOR_REUSE_R2   FLASHDATABASE[sPc_REUSE_R2].Sbyte
/*-144-*/#define DES_CUSTOM_SENSOR_REUSE_R3   FLASHDATABASE[sPc_REUSE_R3].Sbyte
/*-145-*/#define DES_CUSTOM_SENSOR_REUSE_R4   FLASHDATABASE[sPc_REUSE_R4].Sbyte
/*-146-*/#define DES_CUSTOM_SENSOR_REUSE_R5   FLASHDATABASE[sPc_REUSE_R5].Sbyte
/*-147-*/#define DES_CUSTOM_SENSOR_REUSE_R6   FLASHDATABASE[sPc_REUSE_R6].Sbyte
/*-148-*/#define DES_CUSTOM_SENSOR_REUSE_R7   FLASHDATABASE[sPc_REUSE_R7].Sbyte
/*-149-*/#define DES_CUSTOM_SENSOR_REUSE_R8   FLASHDATABASE[sPc_REUSE_R8].Sbyte
/*-150-*/#define DES_CUSTOM_SENSOR_REUSE_V1   FLASHDATABASE[sPc_REUSE_V1].Sbyte
/*-151-*/#define DES_CUSTOM_SENSOR_REUSE_V2   FLASHDATABASE[sPc_REUSE_V2].Sbyte
/*-152-*/#define DES_CUSTOM_SENSOR_REUSE_V3   FLASHDATABASE[sPc_REUSE_V3].Sbyte
/*-153-*/#define DES_CUSTOM_SENSOR_REUSE_V4   FLASHDATABASE[sPc_REUSE_V4].Sbyte
/*-154-*/#define DES_CUSTOM_SENSOR_REUSE_V5   FLASHDATABASE[sPc_REUSE_V5].Sbyte
/*-155-*/#define uFsCtl_CONTROL_CONFIRM       FLASHDATABASE[sCtl_CONTROL_CONFIRM].Sbyte//RS485遥控
/*-156-*/#define uFsCtl_CONTROL_COMMAND       FLASHDATABASE[sCtl_CONTROL_COMMAND].Sbyte//RS485遥控命令      
/*-157-*/#define DES_CUSTOM_SENSOR_REUSE_V6   FLASHDATABASE[sPc_REUSE_V6].Sbyte
/*-158-*/#define DES_CUSTOM_SENSOR_REUSE_V7   FLASHDATABASE[sPc_REUSE_V7].Sbyte
/*-159-*/#define DES_CUSTOM_SENSOR_REUSE_V8   FLASHDATABASE[sPc_REUSE_V8].Sbyte






///保存实时测量参数内存///
  #define MSAVE_EPROMSTARTNUM    FLASHDATABASE[GensRunMSaveCtr+0].ByteInt//保存起动次数
  #define MSAVE_RUNNINGHOUR      FLASHDATABASE[GensRunMSaveCtr+1].ByteInt//保存运行累时
  #define MSAVE_RUNNINGMINUTE    FLASHDATABASE[GensRunMSaveCtr+2].Sbyte  //保存运行累分
  #define MSAVE_RUNNINGSEC       FLASHDATABASE[GensRunMSaveCtr+3].Sbyte  //保存运行秒 
  #define MSAVE_KWHH             FLASHDATABASE[GensRunMSaveCtr+4].ByteInt//保存千瓦时高位
  #define MSAVE_KWHL             FLASHDATABASE[GensRunMSaveCtr+5].ByteInt//保存千瓦时低位


/* ******************************************************************** */
/*                      Measurement Definitions                         */
/* ******************************************************************** */

const typedef enum   //参数设置子菜单枚举类型 sRn--> sRAMMeasnum
{
 /*-00-*/ sRn_VOLTAGEAB2    =0,//市电AB线电压
 /*-01-*/ sRn_VOLTAGEBC2      ,//市电BC线电压
 /*-02-*/ sRn_VOLTAGECA2      ,//市电CA线电压 
 /*-03-*/ sRn_VOLTAGEA2       ,//市电A相电压
 /*-04-*/ sRn_VOLTAGEB2       ,//市电B相电压
 /*-05-*/ sRn_VOLTAGEC2       ,//市电C相电压
 /*-06-*/ sRn_VOLTAGEAB1      ,//油机AB线电压
 /*-07-*/ sRn_VOLTAGEBC1      ,//油机BC线电压
 /*-08-*/ sRn_VOLTAGECA1      ,//油机CA线电压 
 /*-09-*/ sRn_VOLTAGEA1       ,//油机A相电压
 /*-10-*/ sRn_VOLTAGEB1       ,//油机B相电压
 /*-11-*/ sRn_VOLTAGEC1       ,//油机C相电压
 /*-12-*/ sRn_CURRENTA        ,//油机A相电流
 /*-13-*/ sRn_CURRENTB        ,//油机B相电流
 /*-14-*/ sRn_CURRENTC        ,//油机C相电流
 /*-15-*/ sRn_PhaseCOS        ,//COS
 /*-16-*/ sRn_BUS_FREQ        ,//市电频率
 /*-17-*/ sRn_GEN_FREQ        ,//发电机频率
 /*-18-*/ sRn_KWALL           ,//油机总有功功率
 /*-19-*/ sRn_KVAALL          ,//油机总视在功率
 /*-20-*/ sRn_KVARALL         ,//油机总无功功率
 /*-21-*/ sRn_KWA             ,//油机A相有功功率
 /*-22-*/ sRn_KWB             ,//油机B相有功功率
 /*-23-*/ sRn_KWC             ,//油机C相有功功率 
 /*-24-*/ sRn_KVARA           ,//油机A相无功功率
 /*-25-*/ sRn_KVARB           ,//油机B相无功功率
 /*-26-*/ sRn_KVARC           ,//油机C相无功功率 
 /*-27-*/ sRn_KVAA            ,//油机A相视在功率
 /*-28-*/ sRn_KVAB            ,//油机B相视在功率
 /*-29-*/ sRn_KVAC            ,//油机C相视在功率
 /*-30-*/ sRn_PFA             ,//A相功率因数
 /*-31-*/ sRn_PFB             ,//B相功率因数
 /*-32-*/ sRn_PFC             ,//C相功率因数 
 /*-33-*/ sRn_WATERTEMP       ,//水温
 /*-34-*/ sRn_FUEL            ,//油位
 /*-35-*/ sRn_OILPRESSURE     ,//油压 
 /*-36-*/ sRn_REUSEOILTEMPL   ,//油温 复用      
 /*-37-*/ sRn_PowerVoltage    ,//电池电压
 /*-38-*/ sRn_ChargerVoltage  ,//充电机电压
 /*-39-*/ sRn_DES_SPEED       , //油机控制转速                        
 /*-40-*/ sRn_DES_DISPSPEED   , //油机显示转速                            
 /*-41-*/ sRn_NO_Use2         ,                            
 /*-42-*/ sRn_NO_Use3         ,                         
 /*-43-*/ sRn_NO_Use4         ,                         
 /*-44-*/ sRn_NO_Use5         ,                         
 /*-45-*/ sRn_NO_Use6         ,                         
 /*-46-*/ sRn_NO_Use7         ,                         
 /*-47-*/ sRn_DES_ALA_DATA1   ,//柴油机报警                        
 /*-48-*/ sRn_DES_ALA_DATA2   ,//柴油机报警2                        
 /*-49-*/ sRn_GEN_ALA_DATA1   ,//发电机报警                        
 /*-50-*/ sRn_MAIN_ALA_DATA1  ,//网电报警                        
 /*-51-*/ sRn_LIGHTSTATUS     ,//LED灯数据                        
 /*-52-*/ sRn_COMMON_STATUS   ,//通用状态1                        
 /*-53-*/ sRn_COMMON_STATUS2  ,//通用状态2                        
 /*-54-*/ sRn_COMMON_STATUS3  ,//通用状态3                        
 /*-55-*/ sRn_INPUTVALUE      ,//开关量输入                        
 /*-56-*/ sRn_OUTPUTVALUE     ,//开关量输出                        
 /*-57-*/ sRn_VALUER0         ,//电阻0                        
 /*-58-*/ sRn_VALUER1         ,//电阻1                        
 /*-59-*/ sRn_VALUER2         ,//电阻2                        
 /*-60-*/ sRn_VALUER3         ,//电阻3                        
 /*-61-*/ sRn_VALUER4         ,//电阻4                        
 /*-62-*/ sRn_BTNVALUE        ,//按钮                        
 /*-63-*/ sRn_EPROM_STARTNUMHH,//起动次数 EPROM_STARTNUM *9999                        
 /*-64-*/ sRn_EPROM_STARTNUM  ,  //起动次数低16位  
 /*-65-*/ sRn_KWHL            ,  //千瓦时                                       
 /*-66-*/ sRn_KWHH            ,  //千瓦时       //低位
 /*-67-*/ sRn_KVARHL          ,  //千乏时低位        
 /*-68-*/ sRn_KVARHH          ,  //千乏时高位
 /*-69-*/ sRn_RUNNINGHOURHH   ,  //运行累时高字节 RUNNINGHOURHH*9999 
 /*-70-*/ sRn_RUNNINGHOUR     ,  //运行累时
 /*-71-*/ sRn_RUNNINGMINUTE   ,  //运行累分
 /*-72-*/ sRn_RUNNINGSEC      ,  //运行秒 
							 
} sRAMMeasHeadnum;

/* ******************************************************************** */
/*                        Measurement Definitions                       */
/* ******************************************************************** */
/*-00-*/#define VOLTAGEAB2       RAMDATABASE[sRn_VOLTAGEAB2      ].Sbyte  //市电AB线电压
/*-01-*/#define VOLTAGEBC2       RAMDATABASE[sRn_VOLTAGEBC2      ].Sbyte  //市电BC线电压
/*-02-*/#define VOLTAGECA2       RAMDATABASE[sRn_VOLTAGECA2      ].Sbyte  //市电CA线电压 
/*-03-*/#define VOLTAGEA2        RAMDATABASE[sRn_VOLTAGEA2       ].Sbyte  //市电A相电压
/*-04-*/#define VOLTAGEB2        RAMDATABASE[sRn_VOLTAGEB2       ].Sbyte  //市电B相电压
/*-05-*/#define VOLTAGEC2        RAMDATABASE[sRn_VOLTAGEC2       ].Sbyte  //市电C相电压
/*-06-*/#define VOLTAGEAB1       RAMDATABASE[sRn_VOLTAGEAB1      ].Sbyte  //油机AB线电压
/*-07-*/#define VOLTAGEBC1       RAMDATABASE[sRn_VOLTAGEBC1      ].Sbyte  //油机BC线电压
/*-08-*/#define VOLTAGECA1       RAMDATABASE[sRn_VOLTAGECA1      ].Sbyte  //油机CA线电压 
/*-09-*/#define VOLTAGEA1        RAMDATABASE[sRn_VOLTAGEA1       ].Sbyte  //油机A相电压
/*-10-*/#define VOLTAGEB1        RAMDATABASE[sRn_VOLTAGEB1       ].Sbyte  //油机B相电压
/*-11-*/#define VOLTAGEC1        RAMDATABASE[sRn_VOLTAGEC1       ].Sbyte  //油机C相电压
/*-12-*/#define CURRENTA         RAMDATABASE[sRn_CURRENTA        ].ByteInt//油机A相电流
/*-13-*/#define CURRENTB         RAMDATABASE[sRn_CURRENTB        ].ByteInt//油机B相电流
/*-14-*/#define CURRENTC         RAMDATABASE[sRn_CURRENTC        ].ByteInt//油机C相电流
/*-15-*/#define PhaseCOS         RAMDATABASE[sRn_PhaseCOS        ].Sbyte  //COS
/*-16-*/#define BUS_FREQ         RAMDATABASE[sRn_BUS_FREQ        ].Sbyte  //市电频率
/*-17-*/#define GEN_FREQ         RAMDATABASE[sRn_GEN_FREQ        ].Sbyte  //发电机频率
/*-18-*/#define KWALL            RAMDATABASE[sRn_KWALL           ].Sbyte  //油机总有功功率
/*-19-*/#define KVAALL           RAMDATABASE[sRn_KVAALL          ].Sbyte  //油机总视在功率
/*-20-*/#define KVARALL          RAMDATABASE[sRn_KVARALL         ].Sbyte  //油机总无功功率
/*-21-*/#define KWA              RAMDATABASE[sRn_KWA             ].Sbyte  //油机A相有功功率
/*-22-*/#define KWB              RAMDATABASE[sRn_KWB             ].Sbyte  //油机B相有功功率
/*-23-*/#define KWC              RAMDATABASE[sRn_KWC             ].Sbyte  //油机C相有功功率 
/*-24-*/#define KVARA            RAMDATABASE[sRn_KVARA           ].Sbyte  //油机A相无功功率
/*-25-*/#define KVARB            RAMDATABASE[sRn_KVARB           ].Sbyte  //油机B相无功功率
/*-26-*/#define KVARC            RAMDATABASE[sRn_KVARC           ].Sbyte  //油机C相无功功率 
/*-27-*/#define KVAA             RAMDATABASE[sRn_KVAA            ].Sbyte  //油机A相视在功率
/*-28-*/#define KVAB             RAMDATABASE[sRn_KVAB            ].Sbyte  //油机B相视在功率
/*-29-*/#define KVAC             RAMDATABASE[sRn_KVAC            ].Sbyte  //油机C相视在功率
/*-30-*/#define PFA              RAMDATABASE[sRn_PFA             ].Sbyte  //A相功率因数
/*-31-*/#define PFB              RAMDATABASE[sRn_PFB             ].Sbyte  //B相功率因数
/*-32-*/#define PFC              RAMDATABASE[sRn_PFC             ].Sbyte  //C相功率因数 
/*-33-*/#define WATERTEMP        RAMDATABASE[sRn_WATERTEMP       ].Sbyte  //水温
/*-34-*/#define FUEL             RAMDATABASE[sRn_FUEL            ].Sbyte  //油位
/*-35-*/#define OILPRESSURE      RAMDATABASE[sRn_OILPRESSURE     ].Sbyte  //油压 
/*-36-*/#define REUSEOILTEMPL    RAMDATABASE[sRn_REUSEOILTEMPL   ].Sbyte  //复用温度压力液位       
/*-37-*/#define PowerVoltage     RAMDATABASE[sRn_PowerVoltage    ].Sbyte  //电池电压
/*-38-*/#define ChargerVoltage   RAMDATABASE[sRn_ChargerVoltage  ].Sbyte  //充电机电压
/*-39-*/#define DES_SPEED        RAMDATABASE[sRn_DES_SPEED       ].Sbyte  //油机转速
/*-40-*/#define DES_DISPSPEED    RAMDATABASE[sRn_DES_DISPSPEED   ].Sbyte //显示转速
/*-41-*/#define NO_Use2          RAMDATABASE[sRn_NO_Use2         ].Sbyte    
/*-42-*/#define NO_Use3          RAMDATABASE[sRn_NO_Use3         ].Sbyte 
/*-43-*/#define NO_Use4          RAMDATABASE[sRn_NO_Use4         ].Sbyte 
/*-44-*/#define NO_Use5          RAMDATABASE[sRn_NO_Use5         ].Sbyte 
/*-45-*/#define NO_Use6          RAMDATABASE[sRn_NO_Use6         ].Sbyte 
/*-46-*/#define NO_Use7          RAMDATABASE[sRn_NO_Use7         ].Sbyte 
/*-47-*/#define DES_ALA_DATA1    RAMDATABASE[sRn_DES_ALA_DATA1   ].Sbyte  //柴油机报警
/*-48-*/#define DES_ALA_DATA2    RAMDATABASE[sRn_DES_ALA_DATA2   ].Sbyte  //柴油机报警2
/*-49-*/#define GEN_ALA_DATA2    RAMDATABASE[sRn_GEN_ALA_DATA1   ].Sbyte  //发电机报警
/*-50-*/#define MAIN_ALA_DATA1   RAMDATABASE[sRn_MAIN_ALA_DATA1  ].Sbyte  //网电报警
/*-51-*/#define LIGHTSTATUS      RAMDATABASE[sRn_LIGHTSTATUS     ].Sbyte  //LED灯数据
/*-52-*/#define COMMON_STATUS    RAMDATABASE[sRn_COMMON_STATUS   ].Sbyte  //通用状态1
/*-53-*/#define COMMON_STATUS2   RAMDATABASE[sRn_COMMON_STATUS2  ].Sbyte  //通用状态2
/*-54-*/#define COMMON_STATUS3   RAMDATABASE[sRn_COMMON_STATUS3  ].Sbyte  //通用状态3
/*-55-*/#define INPUTVALUE       RAMDATABASE[sRn_INPUTVALUE      ].Sbyte  //开关量输入
/*-56-*/#define OUTPUTVALUE      RAMDATABASE[sRn_OUTPUTVALUE     ].Sbyte  //开关量输出
/*-57-*/#define VALUER0          RAMDATABASE[sRn_VALUER0         ].Sbyte  //电阻0压力
/*-58-*/#define VALUER1          RAMDATABASE[sRn_VALUER1         ].Sbyte  //电阻1温度
/*-59-*/#define VALUER2          RAMDATABASE[sRn_VALUER2         ].Sbyte  //电阻2复用1默认液位
/*-60-*/#define VALUER3          RAMDATABASE[sRn_VALUER3         ].Sbyte  //电阻3复用2默认开关量3
/*-61-*/#define VALUER4          RAMDATABASE[sRn_VALUER4         ].Sbyte  //电阻4
/*-62-*/#define BTNVALUE         RAMDATABASE[sRn_BTNVALUE        ].Sbyte  //按钮
/*-63-*/#define EPROM_STARTNUMHH RAMDATABASE[sRn_EPROM_STARTNUMHH].ByteInt //起动次数 EPROM_STARTNUM *9999
/*-64-*/#define EPROM_STARTNUM   RAMDATABASE[sRn_EPROM_STARTNUM  ].ByteInt//起动次数
/*-65-*/#define KWHH             RAMDATABASE[sRn_KWHH            ].ByteInt//千瓦时高位
/*-66-*/#define KWHL             RAMDATABASE[sRn_KWHL            ].ByteInt//千瓦时低位          
/*-67-*/#define KVARHH           RAMDATABASE[sRn_KVARHH          ].Sbyte  //千乏时高位
/*-68-*/#define KVARHL           RAMDATABASE[sRn_KVARHL          ].Sbyte  //千乏时低位 
/*-69-*/#define RUNNINGHOURHH    RAMDATABASE[sRn_RUNNINGHOURHH   ].ByteInt //运行累时高字节 RUNNINGHOURHH*9999 
/*-70-*/#define RUNNINGHOUR      RAMDATABASE[sRn_RUNNINGHOUR     ].ByteInt//运行累时
/*-71-*/#define RUNNINGMINUTE    RAMDATABASE[sRn_RUNNINGMINUTE   ].Sbyte  //运行累分
/*-72-*/#define RUNNINGSEC       RAMDATABASE[sRn_RUNNINGSEC      ].Sbyte  //运行秒 


        #define sReadParameterErr   RAMDATABASE[GensDateErrSta +0  ].Sbyte//读取参数错误
				#define sReadAdjParmErr     RAMDATABASE[GensDateErrSta +1  ].Sbyte//读取校验参数错误
				#define sReadCurveParmErr   RAMDATABASE[GensDateErrSta +2  ].Sbyte//读取曲线参数错误
				#define sReadLanguageErr    RAMDATABASE[GensDateErrSta +3  ].Sbyte//读取语言参数错误




/* ******************************************************************** */
/*                          BIT Definitions                             */
/* ******************************************************************** */

//键处理标志
#define F_ENTER_UP           RAMDATABASE[sRn_BTNVALUE].BITS.BIT8//上翻页
#define F_ENTER_DOWN         RAMDATABASE[sRn_BTNVALUE].BITS.BIT9//下翻页
#define F_ENTER_START        RAMDATABASE[sRn_BTNVALUE].BITS.BITA//起动
#define F_ENTER_STOP_LCD     RAMDATABASE[sRn_BTNVALUE].BITS.BITB//停机_LCD用
#define F_ENTER_TEST         RAMDATABASE[sRn_BTNVALUE].BITS.BITC//测试
#define F_ENTER_MANUAL       RAMDATABASE[sRn_BTNVALUE].BITS.BITD//手动
#define F_ENTER_AUTO         RAMDATABASE[sRn_BTNVALUE].BITS.BITE//自动
#define F_ENTER_SETUP        RAMDATABASE[sRn_BTNVALUE].BITS.BITF//设置
#define F_ENTER_STOP_CAL     RAMDATABASE[sRn_BTNVALUE].BITS.BIT0//停机_CAL用
#define F_ENTER_ENTER		     RAMDATABASE[sRn_BTNVALUE].BITS.BIT1//确定按键
#define F_ENTER_MAINCLOSE    RAMDATABASE[sRn_BTNVALUE].BITS.BIT2//市电合闸
#define F_ENTER_GENSCLOSE    RAMDATABASE[sRn_BTNVALUE].BITS.BIT3//发电合闸

//LED灯标识
#define F_SHOW_LED_STOP      RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT8//停机灯
#define F_SHOW_LED_MANUAL    RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT9//手动灯
#define F_SHOW_LED_AUTO      RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITA//自动灯
#define F_SHOW_LED_TEST      RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITB//测试灯
#define F_SHOW_LED_GENSET    RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITC//发电机组正常灯
#define F_SHOW_LED_GCB       RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITD//机组合闸灯
#define F_SHOW_LED_MCB       RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITE//市电合闸灯      
#define F_SHOW_LED_MAINS     RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITF//市电正常灯
#define F_SHOW_LED_ALARM     RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT0//综合报警灯
#define F_FLICKER_LED_GENSET RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT1//机组正常灯闪标志 
#define F_FLICKER_LED_MAINS  RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT2//市电正常灯闪标志
#define F_FLICKER_LED_ALARM  RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT3//综合报警灯闪标志

//输入
#define F_AUX_INPUT1         RAMDATABASE[sRn_INPUTVALUE].BITS.BIT8//自定义输入1-8状态
#define F_AUX_INPUT2         RAMDATABASE[sRn_INPUTVALUE].BITS.BIT9
#define F_AUX_INPUT3         RAMDATABASE[sRn_INPUTVALUE].BITS.BITA
#define F_AUX_INPUT4         RAMDATABASE[sRn_INPUTVALUE].BITS.BITB
#define F_AUX_INPUT5         RAMDATABASE[sRn_INPUTVALUE].BITS.BITC
#define F_AUX_INPUT6         RAMDATABASE[sRn_INPUTVALUE].BITS.BITD
#define F_AUX_INPUT7         RAMDATABASE[sRn_INPUTVALUE].BITS.BITE
#define F_AUX_INPUT8         RAMDATABASE[sRn_INPUTVALUE].BITS.BITF
#define F_INPUT_EMSTOP       RAMDATABASE[sRn_INPUTVALUE].BITS.BIT0//急停   
//输出
#define F_OUTPUT_DCHAR       RAMDATABASE[sRn_OUTPUTVALUE].BITS.BIT8//D+输出
#define F_OUTPUT_CRANK       RAMDATABASE[sRn_OUTPUTVALUE].BITS.BIT9//起动输出
#define F_AUX_OUTPUT1        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITA//自定义输出1-6状态
#define F_AUX_OUTPUT2        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITB
#define F_AUX_OUTPUT3        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITC
#define F_AUX_OUTPUT4        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITD
#define F_AUX_OUTPUT5        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITE
#define F_AUX_OUTPUT6        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITF

//发动机报警
#define F_WARN_SPEEDLOST     RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT8//速度丢失警报
#define F_STOP_STOP_FAIL     RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT9//停机失败警报
#define F_WARN_FUEL_LO       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITA//燃油位低警报
#define F_WARN_CHARGE_LO     RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITB//充电失败警报
#define F_WARN_BATT_LO       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITC//电池电压低警报
#define F_WARN_BATT_HI       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITD//电池电压高警报
#define F_WARN_WATER_LO      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITE//水位低警报
#define F_WARN_TEMP_HI       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITF//温度高警报
#define F_WARN_OP_LO         RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT0//油压低警报
#define F_WARN_MAINTAIN      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT1//维护警报
#define F_STOP_EM            RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT2//紧急停机报警
#define F_STOP_TEMP_HI       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT3//温度高停机报警
#define F_STOP_OP_LO         RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT4//油压低停机报警
#define F_STOP_SPEED_HI      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT5//超速停机报警
#define F_STOP_SPEED_LO      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT6//欠速停机报警
#define F_STOP_SPEED_LOST    RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT7//速度丢失报警

#define F_STOP_START_FAIL    RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT8//起动失败报警
#define F_STOP_FUEL_LO       RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT9//燃油位低停机报警
#define F_STOP_WATER_LO      RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITA//水位低停机报警
#define F_STOP_TEMP_LOST     RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITB//温度传感器断线停机报警
#define F_STOP_OP_LOST       RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITC//油压传感器断线停机报警
#define F_STOP_MAINTAIN      RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITD//维护停机报警
#define F_WARN_EXTERN        RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITE//外部告警
#define F_STOP_EXTERN        RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITF//外部停机告警
#define F_WARN_TEMP_LOST     RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT0//温度传感器断线警告
#define F_WARN_OP_LOST       RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT1//油压传感器断线警告


//发电机报警
#define F_WARN_CURRENT_HI    RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BIT8//发电机过流警告
#define F_STOP_VOLT_HI       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BIT9//发电机过压停机报警
#define F_STOP_VOLT_LO       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITA//发电机欠压停机报警
#define F_STOP_CURRENT_HI    RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITB//发电机过流停机报警
#define F_STOP_FREQ_HI       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITC//发电机频率高停机报警
#define F_STOP_FREQ_LO       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITD//发电机频率低停机报警
#define F_STOP_NOFREQ        RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITE//发电机无发电停机报警

//网电报警
#define F_MAINS_VOLT_HI      RAMDATABASE[sRn_MAIN_ALA_DATA1].BITS.BIT8//市电电压高
#define F_MAINS_VOLT_LO      RAMDATABASE[sRn_MAIN_ALA_DATA1].BITS.BIT9//市电电压低


//状态位

#define F_STA_FUELOUTPUT          RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT8//供油
#define F_STA_PRESTART            RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT9//预热状态
#define F_STA_CRANK               RAMDATABASE[sRn_COMMON_STATUS].BITS.BITA//起动状态
#define F_STA_WAITLOAD            RAMDATABASE[sRn_COMMON_STATUS].BITS.BITB//机组等待带载
#define F_STA_IDLE                RAMDATABASE[sRn_COMMON_STATUS].BITS.BITC//起动怠速状态
#define F_STA_WARM                RAMDATABASE[sRn_COMMON_STATUS].BITS.BITD//暖机状态
#define F_STA_DES_RUN             RAMDATABASE[sRn_COMMON_STATUS].BITS.BITE//发动机运行状态
#define F_STA_STARTDEL            RAMDATABASE[sRn_COMMON_STATUS].BITS.BITF//起动延时状态
#define F_STA_STOPDEL             RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT0//停机延时状态
#define F_STA_COOL                RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT1//停机散热状态
#define F_STA_STOP_IDLE           RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT2//停机怠速状态
#define F_STA_STOP_CHECK          RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT3//停机检测状态

#define F_STA_STOP_FAIL           RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT8//停机失败状态
#define F_STA_WARN                RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT9//警告状态
#define F_STA_STOPALARM           RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITA//报警停机状态
#define F_STA_TIMER_SAFE          RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITB//安全延时状态
#define F_STA_MANMODE             RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITC //手动模式
#define F_STA_AUTOMODE            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITD //自动模式
#define F_STA_TESTMODE            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITE //测试模式
#define F_STA_STOPMODE            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITF //停机模式
#define F_STA_START_RETRY         RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT0 //起动间隔
#define F_STA_MAINS_NORMAL_CHECK  RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT1 //市电正常检测
#define F_STA_MAINS_FAIL_CHECK    RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT2 //市电异常检测
#define F_STA_STOPOUTPUT          RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT3//得电停机延时状态
#define F_STA_AMFSTART            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT4//失电自启动延时
#define F_STA_AMFSTOP             RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT5//得电自停机延时

#define F_STA_STOP                RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT8//停机状态
#define F_STA_START_SUCC          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT9//起动成功状态
#define F_STA_GEN_RUN             RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITA//发电机运行状态
#define F_STA_GEN_SUPP            RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITB//发电机组供电状态
#define F_STA_GEN_STOP            RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITC//发电机组停止状态
#define F_STA_MAINS_FAIL          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITD//市电停止状态
#define F_STA_MAINS_RUN           RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITE//市电运行状态
#define F_STA_MAINS_SUPP          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITF//市电供电状态
#define F_STA_TRANSCB             RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT0//开关转换状态
#define F_DI_TEMPHI_STOP          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT1//开关量温度高报警停机
#define F_DI_OILP_STOP            RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT2//开关量油压低报警停机
#define F_DI_FUELLOW_WRN          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT3//开关量油位低警告
#define F_DI_WATERLOW_WRN         RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT4//开关量水位低警告
#define F_DI_FUELLOW_STOP         RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT5//开关量油位低报警停机
#define F_DI_WATERLOW_STOP        RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT6//开关量水位低报警停机
                          

/* ******************************************************************** */
/*                   AlamrRun Delay Definitions                         */
/* ******************************************************************** */

//预热延时
#define DELVAL_PRESTART           (INT16U)(TimerSet[TMR_DES_PREHEAT_DEL]-TimerValue[TMR_DES_PREHEAT_DEL])/10+1

//燃油输出延时
#define DELVAL_FUELOUTPUT         (INT16U)(TimerSet[TMR_DES_FUELOUT_DEL]-TimerValue[TMR_DES_FUELOUT_DEL])/10+1

//起动输出延时
#define DELVAL_CRANK              (INT16U)(TimerSet[TMR_DES_CRANK_DEL]-TimerValue[TMR_DES_CRANK_DEL])/10+1 

//安全运行延时
#define DELVAL_SAFE               (INT16U)(TimerSet[TMR_DES_SAFE_DEL]-TimerValue[TMR_DES_SAFE_DEL])/10+1 

//起动怠速延时
#define DELVAL_STARTIDLE          (INT16U)(TimerSet[TMR_DES_STARTIDLE_DEL]-TimerValue[TMR_DES_STARTIDLE_DEL])/10+1 

//暖机延时
#define DELVAL_WARM               (INT16U)(TimerSet[TMR_DES_WARM_DEL]-TimerValue[TMR_DES_WARM_DEL])/10+1 

//停机散热延时
#define DELVAL_COOLING            (INT16U)(TimerSet[TMR_DES_COOLING_DEL]-TimerValue[TMR_DES_COOLING_DEL])/10+1 

//停机怠速延时
#define DELVAL_STOPIDLE           (INT16U)(TimerSet[TMR_DES_STOPIDLE_DEL]-TimerValue[TMR_DES_STOPIDLE_DEL])/10+1 

//得电停机延时
#define DELVAL_STOPOUTPUT         (INT16U)(TimerSet[TMR_DES_STOPOUTPUT_DEL]-TimerValue[TMR_DES_STOPOUTPUT_DEL])/10+1 

//等待停稳
#define DELVAL_STOPCONFIRM        (INT16U)(TimerSet[TMR_DES_STOPSUCC_DEL]-TimerValue[TMR_DES_STOPSUCC_DEL])/10+1 

//失电自启动延时
#define DELVAL_AMFSTART           (INT16U)(TimerSet[TMR_DES_COOLING_DEL]-TimerValue[TMR_DES_COOLING_DEL])/10+1 

//得电自停机延时
#define DELVAL_AMFSTOP            (INT16U)(TimerSet[TMR_AMF_STOP_DEL]-TimerValue[TMR_AMF_STOP_DEL])/10+1 

//起动间隔
#define DELVAL_STARTINT           (INT16U)(TimerSet[TMR_DES_CRANKINT_DEL]-TimerValue[TMR_DES_CRANKINT_DEL])/10+1 

//市电正常延时
#define DELVAL_MAINSNORMAL        (INT16U)(TimerSet[TMR_MAINS_NORMAL_DEL]-TimerValue[TMR_MAINS_NORMAL_DEL])/10+1 

//市电异常延时
#define DELVAL_MAINSABNORMAL      (INT16U)(TimerSet[TMR_MAINS_ABNORMAL_DEL]-TimerValue[TMR_MAINS_ABNORMAL_DEL])/10+1 

//转换延时
#define DELVAL_TRANSCB            (INT16U)(TimerSet[TMR_MAINS_TRANS_DEL]-TimerValue[TMR_MAINS_TRANS_DEL])/10+1 

//起动延时
#define DELVAL_START              (INT16U)(TimerSet[TMR_AMF_START_DEL]-TimerValue[TMR_AMF_START_DEL])/10+1 

//停机延时
#define DELVAL_STOP               (INT16U)(TimerSet[TMR_AMF_STOP_DEL]-TimerValue[TMR_AMF_STOP_DEL])/10+1 

//过流延时
#define DELVAL_OVERCURRENT        (INT16U)(TimerSet[TMR_GEN_OVERCURRENT_DEL]-TimerValue[TMR_GEN_OVERCURRENT_DEL])/10+1 
    

#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */




