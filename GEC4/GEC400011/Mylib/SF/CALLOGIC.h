#ifndef  _CALLOGIC_H
#define  _CALLOGIC_H
 
 #include"DB.h"
/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */

extern M_INT8U  StartNum;
extern STRFLG16 GENSTA;
extern STRFLG8  CalFlag1;
extern M_INT8U  NowMode;  //0???,1???,2???,3???
extern M_INT8U  IDLECTL;
extern M_INT32U *KWH;
extern STRFLG8 xiologicflag;

enum EngineState
{
    STOPED,       //停机状态
    PREHEAT,      //预热状态
    FUELOUTPUT,   //供油输出状态
    CRANKING,     //起动输出状态
    CRANKINT,     //起动间隔状态
    SAFERUNNING,  //安全运行状态
    STARTIDLE,    //起动怠速状态
    STARTWARM,    //暖机状态
    WAITLOAD,     //等待带载状态
    RUNNING,      //运行状态
    STOPCOOLING,  //停机冷却状态
    STOPIDLE,     //停机怠速延时
    STOPOUTPUT,   //得电停机状态
    WAITSTOP,     //等待挺稳状态
    STOPFAIL,     //停机失败状态
    AMFSTART,     //AMF起动状态
    AMFSTOP,      //AMF停机状态
    INHIBITSTART, //故障停机状态
};

enum OperateMode
{
    STOP,
    MAN,
    AUTO,
    TEST
};

struct GENSETS 
{
    enum  EngineState NOWSTATE;
    enum  OperateMode NOWMODE;
    M_INT8U STARTREQ;
    M_INT8U AUTOSTARTREQ;
    M_INT8U AUTOSTOPREQ;
    M_INT8U STOPREQ;
    M_INT8U EMSTOPREQ;
    M_INT8U INHIBITSTART;
    M_INT8U INHIBITAUTOSTART;
    M_INT8U ALARMSTOP; 
};

#define MODE_STOP 0
#define MODE_MAN  1
#define MODE_AUTO 2
#define MODE_TEST 3
//extern GENSET MYSET;

#define STOPFLAG   CalFlag1.BITS.BIT0
#define RESETFLAG  CalFlag1.BITS.BIT1


#define GEN_STA_VOLT_LOW  GENSTA.BITS.BIT0
#define GEN_STA_VOLT_HIGH GENSTA.BITS.BIT1
#define GEN_STA_FREQ_LOW  GENSTA.BITS.BIT2
#define GEN_STA_FREQ_HIGH GENSTA.BITS.BIT3


#define EM_OnPowerstopFlag  xiologicflag.BITS.BIT0 //急停时得电停机标志
#define TmpBrkStopFlag      xiologicflag.BITS.BIT1 //温度传感器断线时得电停机标志
#define OilPreBrkStopFlag   xiologicflag.BITS.BIT2 //压力传感器断线时得电停机标志


/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
void CALLOGIC_Init (void);
void CALLOGIC_Loop (void);
void TransValue(void);

#define TMR_MAINS_NORMAL_DEL        0
#define TMR_MAINS_ABNORMAL_DEL      1
#define TMR_MAINS_TRANS_DEL         2
#define TMR_AMF_START_DEL           3
#define TMR_AMF_STOP_DEL            4
#define TMR_DES_PREHEAT_DEL         5
#define TMR_DES_CRANK_DEL           6
#define TMR_DES_CRANKINT_DEL        7
#define TMR_DES_SAFE_DEL            8
#define TMR_DES_STARTIDLE_DEL       9
#define TMR_DES_WARM_DEL            10
#define TMR_DES_COOLING_DEL         11
#define TMR_DES_STOPIDLE_DEL        12
#define TMR_DES_STOPOUTPUT_DEL      13
#define TMR_DES_STOPSUCC_DEL        14
#define TMR_GEN_GCB_DEL             15
#define TMR_GEN_ABNORMAL_DEL        16
#define TMR_GEN_VOLTHIGH_STOP_DEL   17
#define TMR_GEN_VOLTLOW_STOP_DEL    18
#define TMR_GEN_VOLTLOW_DEL         19
#define TMR_DES_LOSTSPEED_DEL       20
#define TMR_GEN_OVERCURRENT_DEL     21
#define TMR_COMMON_INPUTFUNC1_DELAY 22
#define TMR_COMMON_INPUTFUNC2_DELAY 23
#define TMR_COMMON_INPUTFUNC3_DELAY 24
#define TMR_CAN_CheckTempBrk_Del    25
#define TMR_CAN_CheckOilPreBrk_Del  26
#define TMR_DES_FUELOUT_DEL         27
#define TMR_GEN_MCB_DEL             28
#define TMR_DES_STOPSUCC            29
#define TMR_MAINS_CHECK             30
#define TMR_1000MS                  31
#define TMR_DES_BATTHI_DEL          32
#define TMR_DES_BATTLOW_DEL         33
#define TMR_DES_LOWFUEL             34   
#define TMR_DES_DFAIL               35  
#define TMR_DES_SPEEDHI             36
#define TMR_DES_LOWSPEED            37
#define TMR_GEN_FREQLOW             38
#define TMR_GEN_FREQHIGH            39
#define TMR_OFFCB                   40
//#define TMR_COMMON_INPUTFUNC6_DELAY 41
//#define TMR_COMMON_INPUTFUNC7_DELAY 42
//#define TMR_COMMON_INPUTFUNC8_DELAY 43
#define TMR_EMSTOPENABLE            44
#define TMR_OILPRESSURE_LOW         45
#define TMR_FUELPUMP_ON             46
#define TMR_FUELPUMP_OFF            47
#define TMR_LCDDIS_LOGO             48
#define TMR_TempSonsorBreakDel      49 //温度传感器断线检测延时
#define TMR_OilSonsorBreakDel       50 //压力传感器断线检测延时
#define TMR_GenStartSuccDel         51 //启动成功标志延时
#define TMR_WaterTempHiStopDel      52 //水温高停机延时

///////////共60个数组///////////////





#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */

