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
    STOPED,       //ͣ��״̬
    PREHEAT,      //Ԥ��״̬
    FUELOUTPUT,   //�������״̬
    CRANKING,     //�����״̬
    CRANKINT,     //�𶯼��״̬
    SAFERUNNING,  //��ȫ����״̬
    STARTIDLE,    //�𶯵���״̬
    STARTWARM,    //ů��״̬
    WAITLOAD,     //�ȴ�����״̬
    RUNNING,      //����״̬
    STOPCOOLING,  //ͣ����ȴ״̬
    STOPIDLE,     //ͣ��������ʱ
    STOPOUTPUT,   //�õ�ͣ��״̬
    WAITSTOP,     //�ȴ�ͦ��״̬
    STOPFAIL,     //ͣ��ʧ��״̬
    AMFSTART,     //AMF��״̬
    AMFSTOP,      //AMFͣ��״̬
    INHIBITSTART, //����ͣ��״̬
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


#define EM_OnPowerstopFlag  xiologicflag.BITS.BIT0 //��ͣʱ�õ�ͣ����־
#define TmpBrkStopFlag      xiologicflag.BITS.BIT1 //�¶ȴ���������ʱ�õ�ͣ����־
#define OilPreBrkStopFlag   xiologicflag.BITS.BIT2 //ѹ������������ʱ�õ�ͣ����־


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
#define TMR_TempSonsorBreakDel      49 //�¶ȴ��������߼����ʱ
#define TMR_OilSonsorBreakDel       50 //ѹ�����������߼����ʱ
#define TMR_GenStartSuccDel         51 //�����ɹ���־��ʱ
#define TMR_WaterTempHiStopDel      52 //ˮ�¸�ͣ����ʱ

///////////��60������///////////////





#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */

