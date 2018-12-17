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
#define M410DelMainBusPg       5  //410�ͺ�ȥ���е粿�ֲ˵�
#define M410DelAdjMBusPg       3  //410�ͺ�ȥ���е粿�ֲ���У��˵�

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
 #define GensStopAlarm1       AlarmMaping[0]     //ͣ��״̬ӳ��
 #define GensStopAlarm2       AlarmMaping[1]
 #define GensWarningAlarm1    AlarmMaping[2]     //??
 #define GensWarningAlarm2    AlarmMaping[3]
 #define GensRunStation1      AlarmMaping[4]
 #define GensRunStation2      AlarmMaping[5]
 #define GensRunStation3      AlarmMaping[6]
 
 /***********************************************************************/
 /*                    ��ʱ���Ӷ���                                                 */
 /***********************************************************************/
#define sAdjParmPageCon          18   //GEC400�ز�������ҳ������
extern INT16U TESTZC[50];

/* ******************************************************************** */
/*                       ��ʾ����У��ӳ��                               */
/* ******************************************************************** */
 #define AdjDataMapCon		sAdjParmPageCon
  extern STRFLG16 AdjDataMapBuf[AdjDataMapCon];  //ʵʱ��ʾ�޸Ĳ���У������ӳ������
 
  #define AdjMapVOLTAGEA2       AdjDataMapBuf[0].Sbyte//�е�A��ѹУ��
  #define AdjMapVOLTAGEB2       AdjDataMapBuf[1].Sbyte//�е�B��ѹУ��
  #define AdjMapVOLTAGEC2       AdjDataMapBuf[2].Sbyte//�е�C��ѹУ��
  #define AdjMapVOLTAGEA1       AdjDataMapBuf[3].Sbyte//����A��ѹУ��
  #define AdjMapVOLTAGEB1       AdjDataMapBuf[4].Sbyte//����B��ѹУ��
  #define AdjMapVOLTAGEC1       AdjDataMapBuf[5].Sbyte//����C��ѹУ��
  #define AdjMapCURRENTA        AdjDataMapBuf[6].Sbyte//A�����У��
  #define AdjMapCURRENTB        AdjDataMapBuf[7].Sbyte//B�����У��
  #define AdjMapCURRENTC        AdjDataMapBuf[8].Sbyte//C�����У��
  #define AdjMapWATERTEMP       AdjDataMapBuf[9].Sbyte//ˮ����У��
  #define AdjMapOILPRESSURE     AdjDataMapBuf[10].Sbyte//����ѹ��У��
  #define AdjMapFUEL            AdjDataMapBuf[11].Sbyte//ȼ��λУ��
  #define AdjMapCustomAog       AdjDataMapBuf[12].Sbyte//�Զ���ģ����У��
  #define AdjMapPowerVoltage    AdjDataMapBuf[13].Sbyte//��ص�ѹУ��
  #define AdjMapChargerVoltage  AdjDataMapBuf[14].Sbyte//����D+
  #define AdjMapPhaseCOS        AdjDataMapBuf[15].Sbyte//���繦������

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


////////----------���Ա�־-------
//extern INT16U Language_select;     //��������   
#define  LCD_LanguageEnglish     0    //0:Ӣ��
#define  LCD_LanguageChinese     1	  //1:����

#define  GensRunMSaveCon     10                                    //���������в�������flashλ�� ����
#define  GensRunMSaveCtr     (FLASH_FLASH_ArrayCon-GensRunMSaveCon)  //���������в�������flashλ�� 
#define  GensDateErrStaCon   10                                    //���������в�������flashλ�� ����
#define  GensDateErrSta     (FLASH_RAM_ArrayCon-GensDateErrStaCon)   //��flash�ж�ȡ����״̬
/* ******************************************************************** */
/*                    ENUM  Flash Memery Definitions                    */
/* ******************************************************************** */

const typedef enum   //���������Ӳ˵�ö������  sPn --> sParmSetnum 
{
 /*-00-*/     sPn_NON_NON                =0 ,//����
 /*-01-*/     sPn_MAINS_NORMAL_DEL       =0 ,//�е�������ʱ
 /*-02-*/     sPn_MAINS_OBNORMAL_DEL     =1 ,//�е��쳣��ʱ
 /*-03-*/     sPn_MAINS_VOLT_LOW            ,//�е�Ƿѹ��ֵ
 /*-04-*/     sPn_MAINS_VOLT_HIGH           ,//�е��ѹ��ֵ      
 /*-05-*/     sPn_MAINS_TRANS_DEL           ,//����ת����ʱ
 /*-06-*/     sPn_AMF_START_DEL             ,//������ʱ
 /*-07-*/     sPn_AMF_STOP_DEL              ,//ͣ����ʱ
 /*-08-*/     sPn_DES_START_NUM             ,//�𶯴���
 /*-09-*/     sPn_DES_PREHEAT_DEL           ,//Ԥ��ʱ��
 /*-10-*/     sPn_DES_CRANK_DEL             ,//��ʱ��
 /*-11-*/     sPn_DES_CRANKINT_DEL          ,//�𶯼��ʱ��
 /*-12-*/     sPn_DES_SAFE_DEL              ,//��ȫ����ʱ��
 /*-13-*/     sPn_DES_STARTIDLE_DEL         ,//��������ʱ��
 /*-14-*/     sPn_DES_WARM_DEL              ,//ů��ʱ��
 /*-15-*/     sPn_DES_COOLING_DEL           ,//ɢ��ʱ��
 /*-16-*/     sPn_DES_STOPIDLE_DEL          ,//ͣ������ʱ��
 /*-17-*/     sPn_DES_STOPOUTPUT_DEL        ,//�õ�ͣ��ʱ��
 /*-18-*/     sPn_DES_STOPSUCC_DEL          ,//�ȴ�ͣ����ʱ
 /*-19-*/     sPn_GEN_MCBGCB_DEL            ,//���غ�բ��ʱ
 /*-20-*/     sPn_DES_GEARTEETH             ,//���ֳ���
 /*-21-*/     sPn_GEN_OBNORMAL_DEL          ,//�����쳣��ʱ
 /*-22-*/     sPn_GEN_VOLTHIGH_STOP         ,//�����ѹ��ֵͣ��
 /*-23-*/     sPn_GEN_VOLTLOW_STOP          ,//����Ƿѹ��ֵͣ��
 /*-24-*/     sPn_DES_LOWSPEED              ,//Ƿ�ٷ�ֵ
 /*-25-*/     sPn_DES_HIGHSPEED             ,//���ٷ�ֵ
 /*-26-*/     sPn_GEN_FREQLOW               ,//����ǷƵ��ֵ
 /*-27-*/     sPn_GEN_FREQHIGH              ,//�����Ƶ��ֵ
 /*-28-*/     sPn_DES_HITEMP                ,//��ˮ�·�ֵ
 /*-29-*/     sPn_DES_LOWOP                 ,//����ѹ��ֵ
 /*-30-*/     sPn_DES_LOWLEVEL              ,//ȼ��λ��ֵ
 /*-31-*/     sPn_DES_LOSTSPEED_DEL         ,//�ٶ��źŶ�ʧ��ʱ
 /*-32-*/     sPn_DES_CHARGEFAULT           ,//���ʧ�ܷ�ֵ
 /*-33-*/     sPn_DES_BATTHI                ,//��ع�ѹ��ֵ
 /*-34-*/     sPn_DES_BATTLOW               ,//���Ƿѹ��ֵ
 /*-35-*/     sPn_GEN_CT                    ,//�������������
 /*-36-*/     sPn_GEN_RATINGCURRENT         ,//���ص���
 /*-37-*/     sPn_GEN_OVERCURRENT           ,//�����ٷֱ�
 /*-38-*/     sPn_GEN_OVERCURRENT_DEL       ,//������ʱ
 /*-39-*/     sPn_DES_FUELPUMP_ON           ,//ȼ�ͱÿ���ֵ
 /*-40-*/     sPn_DES_FUELPUMP_OFF          ,//ȼ�ͱùط�ֵ
 /*-41-*/     sPn_COMMON_OUTPUTFUNC1        ,//�ɱ�����1����
 /*-42-*/     sPn_COMMON_OUTPUTFUNC2        ,//�ɱ�����2����
 /*-43-*/     sPn_COMMON_OUTPUTFUNC3        ,//�ɱ�����3����
 /*-44-*/     sPn_COMMON_OUTPUTFUNC4        ,//�ɱ�����4����
 /*-45-*/     sPn_COMMON_OUTPUTFUNC5        ,//�ɱ�����5����
 /*-46-*/     sPn_COMMON_OUTPUTFUNC6        ,//�ɱ�����6����
 /*-47-*/     sPn_COMMON_INPUTFUNC1         ,//�ɱ������1����
 /*-48-*/     sPn_COMMON_INPUTFUNC1_VALID   ,//�ɱ������1��Ч
 /*-49-*/     sPn_COMMON_INPUTFUNC1_DELAY   ,//�ɱ������1��ʱ
 /*-50-*/     sPn_COMMON_INPUTFUNC2         ,//�ɱ������2����
 /*-51-*/     sPn_COMMON_INPUTFUNC2_VALID   ,//�ɱ������2��Ч
 /*-52-*/     sPn_COMMON_INPUTFUNC2_DELAY   ,//�ɱ������2��ʱ
 /*-53-*/     sPn_COMMON_INPUTFUNC3         ,//�ɱ������3����
 /*-54-*/     sPn_COMMON_INPUTFUNC3_VALID   ,//�ɱ������3��Ч
 /*-55-*/     sPn_COMMON_INPUTFUNC3_DELAY   ,//�ɱ������3��ʱ
 /*-56-*/     sPn_DES_STARTINIT             ,//����״̬ѡ��
 /*-57-*/     sPn_COMMON_ADDR               ,//��������ַѡ��
 /*-58-*/     sPn_DES_PASSWORD              ,//��������
 /*-59-*/     sPn_DES_STARTSUCC_CONDITION   ,//�𶯳ɹ�����
 /*-60-*/     sPn_DES_STARTSUCC_SPEED       ,//�𶯳ɹ�ת��
 /*-61-*/     sPn_DES_STARTSUCC_FREQ        ,//�𶯳ɹ�Ƶ��
 /*-62-*/     sPn_DES_STARTSUCC_OP          ,//�𶯳ɹ���ѹ
 /*-63-*/     sPn_DES_TEMPHIGH_NOSTOP       ,//�¶ȸ߽�ֹͣ��
 /*-64-*/     sPn_DES_OPLOW_NOSTOP          ,//��ѹ�ͽ�ֹͣ��
 /*-65-*/     sPn_GEN_VOLT_TYPE             ,//��ѹ��������ѡ��
 /*-66-*/     sPn_DES_TEMP_SENSOR           ,//�¶ȴ�����ѡ��
 /*-67-*/     sPn_DES_OP_SENSOR             ,//ѹ��������ѡ��
 /*-68-*/     sPn_DES_LV_SENSOR             ,//Һλ������ѡ��
 /*-69-*/     sPn_GEN_POLENUM               ,//���������
 /*-70-*/     sPn_BREAK_TEMP_SENSOR         ,//�¶ȴ��������߶���ѡ��
 /*-71-*/     sPn_BREAK_OP_SENSOR           ,//ѹ�����������߶���ѡ��
 /*-72-*/     sPn_BREAK_LV_SENSOR           ,//Һλ��������·����
 /*-73-*/     sPn_CUSTOM_SENSOR_TYPE        ,//�Զ����������
 /*-74-*/     sPn_GENS_TYPE                 ,//���������� ��ͨ��/J1939�����
 /*-75-*/     sPn_LanguageTYPE_Selection    ,//��������������
/*-76-*/      sPa_VOLT_MAINS_A,//�е�A��ѹУ��	//����У��	 sPa --> sParmAdj 
/*-77-*/      sPa_VOLT_MAINS_B,//�е�B��ѹУ��
/*-78-*/      sPa_VOLT_MAINS_C,//�е�C��ѹУ��
/*-79-*/      sPa_VOLT_GEN_A  ,//����A��ѹУ��
/*-80-*/      sPa_VOLT_GEN_B  ,//����B��ѹУ��
/*-81-*/  	  sPa_VOLT_GEN_C  ,//����C��ѹУ��
/*-82-*/      sPa_CURRENT_A   ,//A�����У��
/*-83-*/      sPa_CURRENT_B   ,//B�����У��
/*-84-*/      sPa_CURRENT_C   ,//C�����У��
/*-85-*/      sPa_TEMP        ,//ˮ����У��
/*-86-*/  	  sPa_OP          ,//����ѹ��У��
/*-87-*/      sPa_LEVEL       ,//ȼ��λУ��	/�Զ���1
/*-88-*/      sPa_CustomAnalog,//           /�Զ���2
/*-89-*/      sPa_BATT        ,//��ص�ѹУ��
/*-90-*/      sPa_CHARGER     ,//����D+
/*-91-*/      sPa_COS         ,//���繦������
/*-92-*/      sPa_MODEL       ,//������ѡ��
/*-93-*/      sPa_RestFactory ,//�ָ�������������
/*-94-*/      sPc_TEMP_R1, //�¶��Զ��崫��������	sPc --> sParmCus 
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
/*-110-*/     sPc_OP_R1,   //ѹ���Զ��崫��������
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
/*-126-*/     sPc_LV_R1, 	//Һλ�Զ��崫�������� 
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
/*-142-*/     sPc_REUSE_R1, 	//�Զ��崫�������� ����2
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
/*-155-*/     sCtl_CONTROL_CONFIRM          ,//RS485ң��
/*-156-*/     sCtl_CONTROL_COMMAND          ,//RS485ң������ 
/*-157-*/     sPc_REUSE_V6,
/*-158-*/     sPc_REUSE_V7, 
/*-159-*/     sPc_REUSE_V8,
} sParmSetHeadnum;                       

			 
/* ******************************************************************** */
/*                    FLASH  Measurement Definitions                    */
/* ******************************************************************** */
							 
/*-01-*/ #define MAINS_NORMAL_DEL             FLASHDATABASE[sPn_MAINS_NORMAL_DEL        ].Sbyte //�е�������ʱ
/*-02-*/ #define MAINS_OBNORMAL_DEL           FLASHDATABASE[sPn_MAINS_OBNORMAL_DEL      ].Sbyte //�е��쳣��ʱ
/*-03-*/ #define MAINS_VOLT_LOW               FLASHDATABASE[sPn_MAINS_VOLT_LOW          ].Sbyte //�е�Ƿѹ��ֵ
/*-04-*/ #define MAINS_VOLT_HIGH              FLASHDATABASE[sPn_MAINS_VOLT_HIGH         ].Sbyte //�е��ѹ��ֵ      
/*-05-*/ #define MAINS_TRANS_DEL              FLASHDATABASE[sPn_MAINS_TRANS_DEL         ].Sbyte //����ת����ʱ
/*-06-*/ #define AMF_START_DEL                FLASHDATABASE[sPn_AMF_START_DEL           ].Sbyte //������ʱ
/*-07-*/ #define AMF_STOP_DEL                 FLASHDATABASE[sPn_AMF_STOP_DEL            ].Sbyte //ͣ����ʱ
/*-08-*/ #define DES_START_NUM                FLASHDATABASE[sPn_DES_START_NUM           ].Sbyte //��������
/*-09-*/ #define DES_PREHEAT_DEL              FLASHDATABASE[sPn_DES_PREHEAT_DEL         ].Sbyte //Ԥ��ʱ��
/*-10-*/ #define DES_CRANK_DEL                FLASHDATABASE[sPn_DES_CRANK_DEL           ].Sbyte //����ʱ��
/*-11-*/ #define DES_CRANKINT_DEL             FLASHDATABASE[sPn_DES_CRANKINT_DEL        ].Sbyte//�������ʱ��
/*-12-*/ #define DES_SAFE_DEL                 FLASHDATABASE[sPn_DES_SAFE_DEL            ].Sbyte//��ȫ����ʱ��
/*-13-*/ #define DES_STARTIDLE_DEL            FLASHDATABASE[sPn_DES_STARTIDLE_DEL       ].Sbyte//��������ʱ��
/*-14-*/ #define DES_WARM_DEL                 FLASHDATABASE[sPn_DES_WARM_DEL            ].Sbyte//ů��ʱ��
/*-15-*/ #define DES_COOLING_DEL              FLASHDATABASE[sPn_DES_COOLING_DEL         ].Sbyte//ɢ��ʱ��
/*-16-*/ #define DES_STOPIDLE_DEL             FLASHDATABASE[sPn_DES_STOPIDLE_DEL        ].Sbyte//ͣ������ʱ��
/*-17-*/ #define DES_STOPOUTPUT_DEL           FLASHDATABASE[sPn_DES_STOPOUTPUT_DEL      ].Sbyte//�õ�ͣ��ʱ��
/*-18-*/ #define DES_STOPSUCC_DEL             FLASHDATABASE[sPn_DES_STOPSUCC_DEL        ].Sbyte//�ȴ�ͣ����ʱ
/*-19-*/ #define GEN_MCBGCB_DEL               FLASHDATABASE[sPn_GEN_MCBGCB_DEL          ].Sbyte//���غ�բ��ʱ
/*-20-*/ #define DES_GEARTEETH                FLASHDATABASE[sPn_DES_GEARTEETH           ].Sbyte//���ֳ���
/*-21-*/ #define GEN_OBNORMAL_DEL             FLASHDATABASE[sPn_GEN_OBNORMAL_DEL        ].Sbyte//�����쳣��ʱ
/*-22-*/ #define GEN_VOLTHIGH_STOP            FLASHDATABASE[sPn_GEN_VOLTHIGH_STOP       ].Sbyte//�����ѹ��ֵͣ��
/*-23-*/ #define GEN_VOLTLOW_STOP             FLASHDATABASE[sPn_GEN_VOLTLOW_STOP        ].Sbyte//����Ƿѹ��ֵͣ��
/*-24-*/ #define DES_LOWSPEED                 FLASHDATABASE[sPn_DES_LOWSPEED            ].Sbyte//Ƿ�ٷ�ֵ
/*-25-*/ #define DES_HIGHSPEED                FLASHDATABASE[sPn_DES_HIGHSPEED           ].Sbyte//���ٷ�ֵ
/*-26-*/ #define GEN_FREQLOW                  FLASHDATABASE[sPn_GEN_FREQLOW             ].Sbyte//����ǷƵ��ֵ
/*-27-*/ #define GEN_FREQHIGH                 FLASHDATABASE[sPn_GEN_FREQHIGH            ].Sbyte//�����Ƶ��ֵ
/*-28-*/ #define DES_HITEMP                   FLASHDATABASE[sPn_DES_HITEMP              ].Sbyte//��ˮ�·�ֵ
/*-29-*/ #define DES_LOWOP                    FLASHDATABASE[sPn_DES_LOWOP               ].Sbyte//����ѹ��ֵ
/*-30-*/ #define DES_LOWLEVEL                 FLASHDATABASE[sPn_DES_LOWLEVEL            ].Sbyte//ȼ��λ��ֵ
/*-31-*/ #define DES_LOSTSPEED_DEL            FLASHDATABASE[sPn_DES_LOSTSPEED_DEL       ].Sbyte//�ٶ��źŶ�ʧ��ʱ
/*-32-*/ #define DES_CHARGEFAULT              FLASHDATABASE[sPn_DES_CHARGEFAULT         ].Sbyte//���ʧ�ܷ�ֵ
/*-33-*/ #define DES_BATTHI                   FLASHDATABASE[sPn_DES_BATTHI              ].Sbyte//��ع�ѹ��ֵ
/*-34-*/ #define DES_BATTLOW                  FLASHDATABASE[sPn_DES_BATTLOW             ].Sbyte//���Ƿѹ��ֵ
/*-35-*/ #define GEN_CT                       FLASHDATABASE[sPn_GEN_CT                  ].Sbyte//�������������
/*-36-*/ #define GEN_RATINGCURRENT            FLASHDATABASE[sPn_GEN_RATINGCURRENT       ].Sbyte//���ص���
/*-37-*/ #define GEN_OVERCURRENT              FLASHDATABASE[sPn_GEN_OVERCURRENT         ].Sbyte//�����ٷֱ�
/*-38-*/ #define GEN_OVERCURRENT_DEL          FLASHDATABASE[sPn_GEN_OVERCURRENT_DEL     ].Sbyte//������ʱ
/*-39-*/ #define DES_FUELPUMP_ON              FLASHDATABASE[sPn_DES_FUELPUMP_ON         ].Sbyte//ȼ�ͱÿ���ֵ
/*-40-*/ #define DES_FUELPUMP_OFF             FLASHDATABASE[sPn_DES_FUELPUMP_OFF        ].Sbyte//ȼ�ͱùط�ֵ
/*-41-*/ #define COMMON_OUTPUTFUNC1           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC1      ].Sbyte//�ɱ�����1����
/*-42-*/ #define COMMON_OUTPUTFUNC2           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC2      ].Sbyte//�ɱ�����2����
/*-43-*/ #define COMMON_OUTPUTFUNC3           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC3      ].Sbyte//�ɱ�����3����
/*-44-*/ #define COMMON_OUTPUTFUNC4           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC4      ].Sbyte//�ɱ�����4����
/*-45-*/ #define COMMON_OUTPUTFUNC5           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC5      ].Sbyte//�ɱ�����5����
/*-46-*/ #define COMMON_OUTPUTFUNC6           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC6      ].Sbyte//�ɱ�����6����
/*-47-*/ #define COMMON_INPUTFUNC1            FLASHDATABASE[sPn_COMMON_INPUTFUNC1       ].Sbyte//�ɱ������1����
/*-48-*/ #define COMMON_INPUTFUNC1_VALID      FLASHDATABASE[sPn_COMMON_INPUTFUNC1_VALID ].Sbyte//�ɱ������1��Ч
/*-49-*/ #define COMMON_INPUTFUNC1_DELAY      FLASHDATABASE[sPn_COMMON_INPUTFUNC1_DELAY ].Sbyte//�ɱ������1��ʱ
/*-50-*/ #define COMMON_INPUTFUNC2            FLASHDATABASE[sPn_COMMON_INPUTFUNC2       ].Sbyte//�ɱ������2����
/*-51-*/ #define COMMON_INPUTFUNC2_VALID      FLASHDATABASE[sPn_COMMON_INPUTFUNC2_VALID ].Sbyte//�ɱ������2��Ч
/*-52-*/ #define COMMON_INPUTFUNC2_DELAY      FLASHDATABASE[sPn_COMMON_INPUTFUNC2_DELAY ].Sbyte//�ɱ������2��ʱ
/*-53-*/ #define COMMON_INPUTFUNC3            FLASHDATABASE[sPn_COMMON_INPUTFUNC3       ].Sbyte//�ɱ������3����
/*-54-*/ #define COMMON_INPUTFUNC3_VALID      FLASHDATABASE[sPn_COMMON_INPUTFUNC3_VALID ].Sbyte//�ɱ������3��Ч
/*-55-*/ #define COMMON_INPUTFUNC3_DELAY      FLASHDATABASE[sPn_COMMON_INPUTFUNC3_DELAY ].Sbyte//�ɱ������3��ʱ
/*-56-*/ #define DES_STARTINIT                FLASHDATABASE[sPn_DES_STARTINIT           ].Sbyte//����״̬ѡ��
/*-57-*/ #define COMMON_ADDR                  FLASHDATABASE[sPn_COMMON_ADDR             ].Sbyte//��������ַѡ��
/*-58-*/ #define DES_PASSWORD                 FLASHDATABASE[sPn_DES_PASSWORD            ].Sbyte//��������
/*-59-*/ #define DES_STARTSUCC_CONDITION      FLASHDATABASE[sPn_DES_STARTSUCC_CONDITION ].Sbyte//�����ɹ�����
/*-60-*/ #define DES_STARTSUCC_SPEED          FLASHDATABASE[sPn_DES_STARTSUCC_SPEED     ].Sbyte//�����ɹ�ת��
/*-61-*/ #define DES_STARTSUCC_FREQ           FLASHDATABASE[sPn_DES_STARTSUCC_FREQ      ].Sbyte//�����ɹ�Ƶ��
/*-62-*/ #define DES_STARTSUCC_OP             FLASHDATABASE[sPn_DES_STARTSUCC_OP        ].Sbyte//�����ɹ���ѹ
/*-63-*/ #define DES_TEMPHIGH_NOSTOP          FLASHDATABASE[sPn_DES_TEMPHIGH_NOSTOP     ].Sbyte//�¶ȸ߽�ֹͣ��
/*-64-*/ #define DES_OPLOW_NOSTOP             FLASHDATABASE[sPn_DES_OPLOW_NOSTOP        ].Sbyte//��ѹ�ͽ�ֹͣ��
/*-65-*/ #define GEN_VOLT_TYPE                FLASHDATABASE[sPn_GEN_VOLT_TYPE           ].Sbyte//��ѹ��������ѡ��
/*-66-*/ #define DES_TEMP_SENSOR              FLASHDATABASE[sPn_DES_TEMP_SENSOR         ].Sbyte//�¶ȴ�����ѡ��
/*-67-*/ #define DES_OP_SENSOR                FLASHDATABASE[sPn_DES_OP_SENSOR           ].Sbyte//ѹ��������ѡ��
/*-68-*/ #define DES_LV_SENSOR                FLASHDATABASE[sPn_DES_LV_SENSOR           ].Sbyte//Һλ������ѡ��
/*-69-*/ #define GEN_POLENUM                  FLASHDATABASE[sPn_GEN_POLENUM             ].Sbyte//���������
/*-70-*/ #define BREAK_TEMP_SENSOR            FLASHDATABASE[sPn_BREAK_TEMP_SENSOR       ].Sbyte//�¶ȴ��������߶���ѡ��
/*-71-*/ #define BREAK_OP_SENSOR    	      FLASHDATABASE[sPn_BREAK_OP_SENSOR         ].Sbyte//ѹ�����������߶���ѡ��
/*-72-*/ #define BREAK_LV_SENSOR	          FLASHDATABASE[sPn_BREAK_LV_SENSOR         ].Sbyte//Һλ���������߶���ѡ��
/*-73-*/ #define CUSTOM_SENSOR_TYPE           FLASHDATABASE[sPn_CUSTOM_SENSOR_TYPE      ].Sbyte//�Զ����������
/*-74-*/ #define GES_GENS_TYPE                FLASHDATABASE[sPn_GENS_TYPE               ].Sbyte//���������� ��ͨ��/J1939�����
/*-75-*/ #define Language_select              FLASHDATABASE[sPn_LanguageTYPE_Selection  ].Sbyte//��������������
/*-76-*/ #define RECAL_VOLT_MAINS_A           FLASHDATABASE[sPa_VOLT_MAINS_A            ].Sbyte//�е�A��ѹУ��	 // Adjust  Measurement Definitions  
/*-77-*/ #define RECAL_VOLT_MAINS_B           FLASHDATABASE[sPa_VOLT_MAINS_B            ].Sbyte//�е�B��ѹУ��
/*-78-*/ #define RECAL_VOLT_MAINS_C           FLASHDATABASE[sPa_VOLT_MAINS_C            ].Sbyte//�е�C��ѹУ��
/*-79-*/ #define RECAL_VOLT_GEN_A             FLASHDATABASE[sPa_VOLT_GEN_A              ].Sbyte//����A��ѹУ��
/*-80-*/ #define RECAL_VOLT_GEN_B             FLASHDATABASE[sPa_VOLT_GEN_B              ].Sbyte//����B��ѹУ��
/*-81-*/ #define RECAL_VOLT_GEN_C             FLASHDATABASE[sPa_VOLT_GEN_C              ].Sbyte//����C��ѹУ��
/*-82-*/ #define RECAL_CURRENT_A              FLASHDATABASE[sPa_CURRENT_A               ].Sbyte//A�����У��
/*-83-*/ #define RECAL_CURRENT_B              FLASHDATABASE[sPa_CURRENT_B               ].Sbyte//B�����У��
/*-84-*/ #define RECAL_CURRENT_C              FLASHDATABASE[sPa_CURRENT_C               ].Sbyte//C�����У��
/*-85-*/ #define RECAL_TEMP                   FLASHDATABASE[sPa_TEMP                    ].Sbyte//ˮ����У��
/*-86-*/ #define RECAL_OP                     FLASHDATABASE[sPa_OP                      ].Sbyte//����ѹ��У��
/*-87-*/ #define RECAL_LEVEL                  FLASHDATABASE[sPa_LEVEL                   ].Sbyte//ȼ��λУ��
/*-88-*/ #define RECAL_CustomAnalog           FLASHDATABASE[sPa_CustomAnalog            ].Sbyte//�Զ���ģ����У��
/*-89-*/ #define RECAL_BATT                   FLASHDATABASE[sPa_BATT                    ].Sbyte//��ص�ѹУ��
/*-90-*/ #define RECAL_CHARGER                FLASHDATABASE[sPa_CHARGER                 ].Sbyte//����D+
/*-91-*/ #define RECAL_COS                    FLASHDATABASE[sPa_COS                     ].Sbyte//���繦������
/*-92-*/ #define COMMON_MODEL                 FLASHDATABASE[sPa_MODEL                   ].Sbyte//������ѡ��
/*-93-*/ #define Ctl_RestFactory	            FLASHDATABASE[sPa_RestFactory             ].Sbyte //�ָ�������������
/*-94-*/ #define DES_CUSTOM_SENSOR_TEMP_R1    FLASHDATABASE[sPc_TEMP_R1 ].Sbyte//�¶��Զ��崫�������� 
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
/*-110-*/#define DES_CUSTOM_SENSOR_OP_R1      FLASHDATABASE[sPc_OP_R1   ].Sbyte//ѹ���Զ��崫��������
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
/*-126-*/#define DES_CUSTOM_SENSOR_LV_R1      FLASHDATABASE[sPc_LV_R1   ].Sbyte//Һλ�Զ��崫�������� ����1
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
/*-142-*/#define DES_CUSTOM_SENSOR_REUSE_R1   FLASHDATABASE[sPc_REUSE_R1].Sbyte//�Զ��崫��������	����2
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
/*-155-*/#define uFsCtl_CONTROL_CONFIRM       FLASHDATABASE[sCtl_CONTROL_CONFIRM].Sbyte//RS485ң��
/*-156-*/#define uFsCtl_CONTROL_COMMAND       FLASHDATABASE[sCtl_CONTROL_COMMAND].Sbyte//RS485ң������      
/*-157-*/#define DES_CUSTOM_SENSOR_REUSE_V6   FLASHDATABASE[sPc_REUSE_V6].Sbyte
/*-158-*/#define DES_CUSTOM_SENSOR_REUSE_V7   FLASHDATABASE[sPc_REUSE_V7].Sbyte
/*-159-*/#define DES_CUSTOM_SENSOR_REUSE_V8   FLASHDATABASE[sPc_REUSE_V8].Sbyte






///����ʵʱ���������ڴ�///
  #define MSAVE_EPROMSTARTNUM    FLASHDATABASE[GensRunMSaveCtr+0].ByteInt//�����𶯴���
  #define MSAVE_RUNNINGHOUR      FLASHDATABASE[GensRunMSaveCtr+1].ByteInt//����������ʱ
  #define MSAVE_RUNNINGMINUTE    FLASHDATABASE[GensRunMSaveCtr+2].Sbyte  //���������۷�
  #define MSAVE_RUNNINGSEC       FLASHDATABASE[GensRunMSaveCtr+3].Sbyte  //���������� 
  #define MSAVE_KWHH             FLASHDATABASE[GensRunMSaveCtr+4].ByteInt//����ǧ��ʱ��λ
  #define MSAVE_KWHL             FLASHDATABASE[GensRunMSaveCtr+5].ByteInt//����ǧ��ʱ��λ


/* ******************************************************************** */
/*                      Measurement Definitions                         */
/* ******************************************************************** */

const typedef enum   //���������Ӳ˵�ö������ sRn--> sRAMMeasnum
{
 /*-00-*/ sRn_VOLTAGEAB2    =0,//�е�AB�ߵ�ѹ
 /*-01-*/ sRn_VOLTAGEBC2      ,//�е�BC�ߵ�ѹ
 /*-02-*/ sRn_VOLTAGECA2      ,//�е�CA�ߵ�ѹ 
 /*-03-*/ sRn_VOLTAGEA2       ,//�е�A���ѹ
 /*-04-*/ sRn_VOLTAGEB2       ,//�е�B���ѹ
 /*-05-*/ sRn_VOLTAGEC2       ,//�е�C���ѹ
 /*-06-*/ sRn_VOLTAGEAB1      ,//�ͻ�AB�ߵ�ѹ
 /*-07-*/ sRn_VOLTAGEBC1      ,//�ͻ�BC�ߵ�ѹ
 /*-08-*/ sRn_VOLTAGECA1      ,//�ͻ�CA�ߵ�ѹ 
 /*-09-*/ sRn_VOLTAGEA1       ,//�ͻ�A���ѹ
 /*-10-*/ sRn_VOLTAGEB1       ,//�ͻ�B���ѹ
 /*-11-*/ sRn_VOLTAGEC1       ,//�ͻ�C���ѹ
 /*-12-*/ sRn_CURRENTA        ,//�ͻ�A�����
 /*-13-*/ sRn_CURRENTB        ,//�ͻ�B�����
 /*-14-*/ sRn_CURRENTC        ,//�ͻ�C�����
 /*-15-*/ sRn_PhaseCOS        ,//COS
 /*-16-*/ sRn_BUS_FREQ        ,//�е�Ƶ��
 /*-17-*/ sRn_GEN_FREQ        ,//�����Ƶ��
 /*-18-*/ sRn_KWALL           ,//�ͻ����й�����
 /*-19-*/ sRn_KVAALL          ,//�ͻ������ڹ���
 /*-20-*/ sRn_KVARALL         ,//�ͻ����޹�����
 /*-21-*/ sRn_KWA             ,//�ͻ�A���й�����
 /*-22-*/ sRn_KWB             ,//�ͻ�B���й�����
 /*-23-*/ sRn_KWC             ,//�ͻ�C���й����� 
 /*-24-*/ sRn_KVARA           ,//�ͻ�A���޹�����
 /*-25-*/ sRn_KVARB           ,//�ͻ�B���޹�����
 /*-26-*/ sRn_KVARC           ,//�ͻ�C���޹����� 
 /*-27-*/ sRn_KVAA            ,//�ͻ�A�����ڹ���
 /*-28-*/ sRn_KVAB            ,//�ͻ�B�����ڹ���
 /*-29-*/ sRn_KVAC            ,//�ͻ�C�����ڹ���
 /*-30-*/ sRn_PFA             ,//A�๦������
 /*-31-*/ sRn_PFB             ,//B�๦������
 /*-32-*/ sRn_PFC             ,//C�๦������ 
 /*-33-*/ sRn_WATERTEMP       ,//ˮ��
 /*-34-*/ sRn_FUEL            ,//��λ
 /*-35-*/ sRn_OILPRESSURE     ,//��ѹ 
 /*-36-*/ sRn_REUSEOILTEMPL   ,//���� ����      
 /*-37-*/ sRn_PowerVoltage    ,//��ص�ѹ
 /*-38-*/ sRn_ChargerVoltage  ,//������ѹ
 /*-39-*/ sRn_DES_SPEED       , //�ͻ�����ת��                        
 /*-40-*/ sRn_DES_DISPSPEED   , //�ͻ���ʾת��                            
 /*-41-*/ sRn_NO_Use2         ,                            
 /*-42-*/ sRn_NO_Use3         ,                         
 /*-43-*/ sRn_NO_Use4         ,                         
 /*-44-*/ sRn_NO_Use5         ,                         
 /*-45-*/ sRn_NO_Use6         ,                         
 /*-46-*/ sRn_NO_Use7         ,                         
 /*-47-*/ sRn_DES_ALA_DATA1   ,//���ͻ�����                        
 /*-48-*/ sRn_DES_ALA_DATA2   ,//���ͻ�����2                        
 /*-49-*/ sRn_GEN_ALA_DATA1   ,//���������                        
 /*-50-*/ sRn_MAIN_ALA_DATA1  ,//���籨��                        
 /*-51-*/ sRn_LIGHTSTATUS     ,//LED������                        
 /*-52-*/ sRn_COMMON_STATUS   ,//ͨ��״̬1                        
 /*-53-*/ sRn_COMMON_STATUS2  ,//ͨ��״̬2                        
 /*-54-*/ sRn_COMMON_STATUS3  ,//ͨ��״̬3                        
 /*-55-*/ sRn_INPUTVALUE      ,//����������                        
 /*-56-*/ sRn_OUTPUTVALUE     ,//���������                        
 /*-57-*/ sRn_VALUER0         ,//����0                        
 /*-58-*/ sRn_VALUER1         ,//����1                        
 /*-59-*/ sRn_VALUER2         ,//����2                        
 /*-60-*/ sRn_VALUER3         ,//����3                        
 /*-61-*/ sRn_VALUER4         ,//����4                        
 /*-62-*/ sRn_BTNVALUE        ,//��ť                        
 /*-63-*/ sRn_EPROM_STARTNUMHH,//�𶯴��� EPROM_STARTNUM *9999                        
 /*-64-*/ sRn_EPROM_STARTNUM  ,  //�𶯴�����16λ  
 /*-65-*/ sRn_KWHL            ,  //ǧ��ʱ                                       
 /*-66-*/ sRn_KWHH            ,  //ǧ��ʱ       //��λ
 /*-67-*/ sRn_KVARHL          ,  //ǧ��ʱ��λ        
 /*-68-*/ sRn_KVARHH          ,  //ǧ��ʱ��λ
 /*-69-*/ sRn_RUNNINGHOURHH   ,  //������ʱ���ֽ� RUNNINGHOURHH*9999 
 /*-70-*/ sRn_RUNNINGHOUR     ,  //������ʱ
 /*-71-*/ sRn_RUNNINGMINUTE   ,  //�����۷�
 /*-72-*/ sRn_RUNNINGSEC      ,  //������ 
							 
} sRAMMeasHeadnum;

/* ******************************************************************** */
/*                        Measurement Definitions                       */
/* ******************************************************************** */
/*-00-*/#define VOLTAGEAB2       RAMDATABASE[sRn_VOLTAGEAB2      ].Sbyte  //�е�AB�ߵ�ѹ
/*-01-*/#define VOLTAGEBC2       RAMDATABASE[sRn_VOLTAGEBC2      ].Sbyte  //�е�BC�ߵ�ѹ
/*-02-*/#define VOLTAGECA2       RAMDATABASE[sRn_VOLTAGECA2      ].Sbyte  //�е�CA�ߵ�ѹ 
/*-03-*/#define VOLTAGEA2        RAMDATABASE[sRn_VOLTAGEA2       ].Sbyte  //�е�A���ѹ
/*-04-*/#define VOLTAGEB2        RAMDATABASE[sRn_VOLTAGEB2       ].Sbyte  //�е�B���ѹ
/*-05-*/#define VOLTAGEC2        RAMDATABASE[sRn_VOLTAGEC2       ].Sbyte  //�е�C���ѹ
/*-06-*/#define VOLTAGEAB1       RAMDATABASE[sRn_VOLTAGEAB1      ].Sbyte  //�ͻ�AB�ߵ�ѹ
/*-07-*/#define VOLTAGEBC1       RAMDATABASE[sRn_VOLTAGEBC1      ].Sbyte  //�ͻ�BC�ߵ�ѹ
/*-08-*/#define VOLTAGECA1       RAMDATABASE[sRn_VOLTAGECA1      ].Sbyte  //�ͻ�CA�ߵ�ѹ 
/*-09-*/#define VOLTAGEA1        RAMDATABASE[sRn_VOLTAGEA1       ].Sbyte  //�ͻ�A���ѹ
/*-10-*/#define VOLTAGEB1        RAMDATABASE[sRn_VOLTAGEB1       ].Sbyte  //�ͻ�B���ѹ
/*-11-*/#define VOLTAGEC1        RAMDATABASE[sRn_VOLTAGEC1       ].Sbyte  //�ͻ�C���ѹ
/*-12-*/#define CURRENTA         RAMDATABASE[sRn_CURRENTA        ].ByteInt//�ͻ�A�����
/*-13-*/#define CURRENTB         RAMDATABASE[sRn_CURRENTB        ].ByteInt//�ͻ�B�����
/*-14-*/#define CURRENTC         RAMDATABASE[sRn_CURRENTC        ].ByteInt//�ͻ�C�����
/*-15-*/#define PhaseCOS         RAMDATABASE[sRn_PhaseCOS        ].Sbyte  //COS
/*-16-*/#define BUS_FREQ         RAMDATABASE[sRn_BUS_FREQ        ].Sbyte  //�е�Ƶ��
/*-17-*/#define GEN_FREQ         RAMDATABASE[sRn_GEN_FREQ        ].Sbyte  //�����Ƶ��
/*-18-*/#define KWALL            RAMDATABASE[sRn_KWALL           ].Sbyte  //�ͻ����й�����
/*-19-*/#define KVAALL           RAMDATABASE[sRn_KVAALL          ].Sbyte  //�ͻ������ڹ���
/*-20-*/#define KVARALL          RAMDATABASE[sRn_KVARALL         ].Sbyte  //�ͻ����޹�����
/*-21-*/#define KWA              RAMDATABASE[sRn_KWA             ].Sbyte  //�ͻ�A���й�����
/*-22-*/#define KWB              RAMDATABASE[sRn_KWB             ].Sbyte  //�ͻ�B���й�����
/*-23-*/#define KWC              RAMDATABASE[sRn_KWC             ].Sbyte  //�ͻ�C���й����� 
/*-24-*/#define KVARA            RAMDATABASE[sRn_KVARA           ].Sbyte  //�ͻ�A���޹�����
/*-25-*/#define KVARB            RAMDATABASE[sRn_KVARB           ].Sbyte  //�ͻ�B���޹�����
/*-26-*/#define KVARC            RAMDATABASE[sRn_KVARC           ].Sbyte  //�ͻ�C���޹����� 
/*-27-*/#define KVAA             RAMDATABASE[sRn_KVAA            ].Sbyte  //�ͻ�A�����ڹ���
/*-28-*/#define KVAB             RAMDATABASE[sRn_KVAB            ].Sbyte  //�ͻ�B�����ڹ���
/*-29-*/#define KVAC             RAMDATABASE[sRn_KVAC            ].Sbyte  //�ͻ�C�����ڹ���
/*-30-*/#define PFA              RAMDATABASE[sRn_PFA             ].Sbyte  //A�๦������
/*-31-*/#define PFB              RAMDATABASE[sRn_PFB             ].Sbyte  //B�๦������
/*-32-*/#define PFC              RAMDATABASE[sRn_PFC             ].Sbyte  //C�๦������ 
/*-33-*/#define WATERTEMP        RAMDATABASE[sRn_WATERTEMP       ].Sbyte  //ˮ��
/*-34-*/#define FUEL             RAMDATABASE[sRn_FUEL            ].Sbyte  //��λ
/*-35-*/#define OILPRESSURE      RAMDATABASE[sRn_OILPRESSURE     ].Sbyte  //��ѹ 
/*-36-*/#define REUSEOILTEMPL    RAMDATABASE[sRn_REUSEOILTEMPL   ].Sbyte  //�����¶�ѹ��Һλ       
/*-37-*/#define PowerVoltage     RAMDATABASE[sRn_PowerVoltage    ].Sbyte  //��ص�ѹ
/*-38-*/#define ChargerVoltage   RAMDATABASE[sRn_ChargerVoltage  ].Sbyte  //������ѹ
/*-39-*/#define DES_SPEED        RAMDATABASE[sRn_DES_SPEED       ].Sbyte  //�ͻ�ת��
/*-40-*/#define DES_DISPSPEED    RAMDATABASE[sRn_DES_DISPSPEED   ].Sbyte //��ʾת��
/*-41-*/#define NO_Use2          RAMDATABASE[sRn_NO_Use2         ].Sbyte    
/*-42-*/#define NO_Use3          RAMDATABASE[sRn_NO_Use3         ].Sbyte 
/*-43-*/#define NO_Use4          RAMDATABASE[sRn_NO_Use4         ].Sbyte 
/*-44-*/#define NO_Use5          RAMDATABASE[sRn_NO_Use5         ].Sbyte 
/*-45-*/#define NO_Use6          RAMDATABASE[sRn_NO_Use6         ].Sbyte 
/*-46-*/#define NO_Use7          RAMDATABASE[sRn_NO_Use7         ].Sbyte 
/*-47-*/#define DES_ALA_DATA1    RAMDATABASE[sRn_DES_ALA_DATA1   ].Sbyte  //���ͻ�����
/*-48-*/#define DES_ALA_DATA2    RAMDATABASE[sRn_DES_ALA_DATA2   ].Sbyte  //���ͻ�����2
/*-49-*/#define GEN_ALA_DATA2    RAMDATABASE[sRn_GEN_ALA_DATA1   ].Sbyte  //���������
/*-50-*/#define MAIN_ALA_DATA1   RAMDATABASE[sRn_MAIN_ALA_DATA1  ].Sbyte  //���籨��
/*-51-*/#define LIGHTSTATUS      RAMDATABASE[sRn_LIGHTSTATUS     ].Sbyte  //LED������
/*-52-*/#define COMMON_STATUS    RAMDATABASE[sRn_COMMON_STATUS   ].Sbyte  //ͨ��״̬1
/*-53-*/#define COMMON_STATUS2   RAMDATABASE[sRn_COMMON_STATUS2  ].Sbyte  //ͨ��״̬2
/*-54-*/#define COMMON_STATUS3   RAMDATABASE[sRn_COMMON_STATUS3  ].Sbyte  //ͨ��״̬3
/*-55-*/#define INPUTVALUE       RAMDATABASE[sRn_INPUTVALUE      ].Sbyte  //����������
/*-56-*/#define OUTPUTVALUE      RAMDATABASE[sRn_OUTPUTVALUE     ].Sbyte  //���������
/*-57-*/#define VALUER0          RAMDATABASE[sRn_VALUER0         ].Sbyte  //����0ѹ��
/*-58-*/#define VALUER1          RAMDATABASE[sRn_VALUER1         ].Sbyte  //����1�¶�
/*-59-*/#define VALUER2          RAMDATABASE[sRn_VALUER2         ].Sbyte  //����2����1Ĭ��Һλ
/*-60-*/#define VALUER3          RAMDATABASE[sRn_VALUER3         ].Sbyte  //����3����2Ĭ�Ͽ�����3
/*-61-*/#define VALUER4          RAMDATABASE[sRn_VALUER4         ].Sbyte  //����4
/*-62-*/#define BTNVALUE         RAMDATABASE[sRn_BTNVALUE        ].Sbyte  //��ť
/*-63-*/#define EPROM_STARTNUMHH RAMDATABASE[sRn_EPROM_STARTNUMHH].ByteInt //�𶯴��� EPROM_STARTNUM *9999
/*-64-*/#define EPROM_STARTNUM   RAMDATABASE[sRn_EPROM_STARTNUM  ].ByteInt//�𶯴���
/*-65-*/#define KWHH             RAMDATABASE[sRn_KWHH            ].ByteInt//ǧ��ʱ��λ
/*-66-*/#define KWHL             RAMDATABASE[sRn_KWHL            ].ByteInt//ǧ��ʱ��λ          
/*-67-*/#define KVARHH           RAMDATABASE[sRn_KVARHH          ].Sbyte  //ǧ��ʱ��λ
/*-68-*/#define KVARHL           RAMDATABASE[sRn_KVARHL          ].Sbyte  //ǧ��ʱ��λ 
/*-69-*/#define RUNNINGHOURHH    RAMDATABASE[sRn_RUNNINGHOURHH   ].ByteInt //������ʱ���ֽ� RUNNINGHOURHH*9999 
/*-70-*/#define RUNNINGHOUR      RAMDATABASE[sRn_RUNNINGHOUR     ].ByteInt//������ʱ
/*-71-*/#define RUNNINGMINUTE    RAMDATABASE[sRn_RUNNINGMINUTE   ].Sbyte  //�����۷�
/*-72-*/#define RUNNINGSEC       RAMDATABASE[sRn_RUNNINGSEC      ].Sbyte  //������ 


        #define sReadParameterErr   RAMDATABASE[GensDateErrSta +0  ].Sbyte//��ȡ��������
				#define sReadAdjParmErr     RAMDATABASE[GensDateErrSta +1  ].Sbyte//��ȡУ���������
				#define sReadCurveParmErr   RAMDATABASE[GensDateErrSta +2  ].Sbyte//��ȡ���߲�������
				#define sReadLanguageErr    RAMDATABASE[GensDateErrSta +3  ].Sbyte//��ȡ���Բ�������




/* ******************************************************************** */
/*                          BIT Definitions                             */
/* ******************************************************************** */

//�������־
#define F_ENTER_UP           RAMDATABASE[sRn_BTNVALUE].BITS.BIT8//�Ϸ�ҳ
#define F_ENTER_DOWN         RAMDATABASE[sRn_BTNVALUE].BITS.BIT9//�·�ҳ
#define F_ENTER_START        RAMDATABASE[sRn_BTNVALUE].BITS.BITA//��
#define F_ENTER_STOP_LCD     RAMDATABASE[sRn_BTNVALUE].BITS.BITB//ͣ��_LCD��
#define F_ENTER_TEST         RAMDATABASE[sRn_BTNVALUE].BITS.BITC//����
#define F_ENTER_MANUAL       RAMDATABASE[sRn_BTNVALUE].BITS.BITD//�ֶ�
#define F_ENTER_AUTO         RAMDATABASE[sRn_BTNVALUE].BITS.BITE//�Զ�
#define F_ENTER_SETUP        RAMDATABASE[sRn_BTNVALUE].BITS.BITF//����
#define F_ENTER_STOP_CAL     RAMDATABASE[sRn_BTNVALUE].BITS.BIT0//ͣ��_CAL��
#define F_ENTER_ENTER		     RAMDATABASE[sRn_BTNVALUE].BITS.BIT1//ȷ������
#define F_ENTER_MAINCLOSE    RAMDATABASE[sRn_BTNVALUE].BITS.BIT2//�е��բ
#define F_ENTER_GENSCLOSE    RAMDATABASE[sRn_BTNVALUE].BITS.BIT3//�����բ

//LED�Ʊ�ʶ
#define F_SHOW_LED_STOP      RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT8//ͣ����
#define F_SHOW_LED_MANUAL    RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT9//�ֶ���
#define F_SHOW_LED_AUTO      RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITA//�Զ���
#define F_SHOW_LED_TEST      RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITB//���Ե�
#define F_SHOW_LED_GENSET    RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITC//�������������
#define F_SHOW_LED_GCB       RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITD//�����բ��
#define F_SHOW_LED_MCB       RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITE//�е��բ��      
#define F_SHOW_LED_MAINS     RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITF//�е�������
#define F_SHOW_LED_ALARM     RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT0//�ۺϱ�����
#define F_FLICKER_LED_GENSET RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT1//��������������־ 
#define F_FLICKER_LED_MAINS  RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT2//�е�����������־
#define F_FLICKER_LED_ALARM  RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT3//�ۺϱ���������־

//����
#define F_AUX_INPUT1         RAMDATABASE[sRn_INPUTVALUE].BITS.BIT8//�Զ�������1-8״̬
#define F_AUX_INPUT2         RAMDATABASE[sRn_INPUTVALUE].BITS.BIT9
#define F_AUX_INPUT3         RAMDATABASE[sRn_INPUTVALUE].BITS.BITA
#define F_AUX_INPUT4         RAMDATABASE[sRn_INPUTVALUE].BITS.BITB
#define F_AUX_INPUT5         RAMDATABASE[sRn_INPUTVALUE].BITS.BITC
#define F_AUX_INPUT6         RAMDATABASE[sRn_INPUTVALUE].BITS.BITD
#define F_AUX_INPUT7         RAMDATABASE[sRn_INPUTVALUE].BITS.BITE
#define F_AUX_INPUT8         RAMDATABASE[sRn_INPUTVALUE].BITS.BITF
#define F_INPUT_EMSTOP       RAMDATABASE[sRn_INPUTVALUE].BITS.BIT0//��ͣ   
//���
#define F_OUTPUT_DCHAR       RAMDATABASE[sRn_OUTPUTVALUE].BITS.BIT8//D+���
#define F_OUTPUT_CRANK       RAMDATABASE[sRn_OUTPUTVALUE].BITS.BIT9//�����
#define F_AUX_OUTPUT1        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITA//�Զ������1-6״̬
#define F_AUX_OUTPUT2        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITB
#define F_AUX_OUTPUT3        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITC
#define F_AUX_OUTPUT4        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITD
#define F_AUX_OUTPUT5        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITE
#define F_AUX_OUTPUT6        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITF

//����������
#define F_WARN_SPEEDLOST     RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT8//�ٶȶ�ʧ����
#define F_STOP_STOP_FAIL     RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT9//ͣ��ʧ�ܾ���
#define F_WARN_FUEL_LO       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITA//ȼ��λ�;���
#define F_WARN_CHARGE_LO     RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITB//���ʧ�ܾ���
#define F_WARN_BATT_LO       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITC//��ص�ѹ�;���
#define F_WARN_BATT_HI       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITD//��ص�ѹ�߾���
#define F_WARN_WATER_LO      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITE//ˮλ�;���
#define F_WARN_TEMP_HI       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITF//�¶ȸ߾���
#define F_WARN_OP_LO         RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT0//��ѹ�;���
#define F_WARN_MAINTAIN      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT1//ά������
#define F_STOP_EM            RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT2//����ͣ������
#define F_STOP_TEMP_HI       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT3//�¶ȸ�ͣ������
#define F_STOP_OP_LO         RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT4//��ѹ��ͣ������
#define F_STOP_SPEED_HI      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT5//����ͣ������
#define F_STOP_SPEED_LO      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT6//Ƿ��ͣ������
#define F_STOP_SPEED_LOST    RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT7//�ٶȶ�ʧ����

#define F_STOP_START_FAIL    RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT8//��ʧ�ܱ���
#define F_STOP_FUEL_LO       RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT9//ȼ��λ��ͣ������
#define F_STOP_WATER_LO      RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITA//ˮλ��ͣ������
#define F_STOP_TEMP_LOST     RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITB//�¶ȴ���������ͣ������
#define F_STOP_OP_LOST       RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITC//��ѹ����������ͣ������
#define F_STOP_MAINTAIN      RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITD//ά��ͣ������
#define F_WARN_EXTERN        RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITE//�ⲿ�澯
#define F_STOP_EXTERN        RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITF//�ⲿͣ���澯
#define F_WARN_TEMP_LOST     RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT0//�¶ȴ��������߾���
#define F_WARN_OP_LOST       RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT1//��ѹ���������߾���


//���������
#define F_WARN_CURRENT_HI    RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BIT8//�������������
#define F_STOP_VOLT_HI       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BIT9//�������ѹͣ������
#define F_STOP_VOLT_LO       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITA//�����Ƿѹͣ������
#define F_STOP_CURRENT_HI    RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITB//���������ͣ������
#define F_STOP_FREQ_HI       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITC//�����Ƶ�ʸ�ͣ������
#define F_STOP_FREQ_LO       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITD//�����Ƶ�ʵ�ͣ������
#define F_STOP_NOFREQ        RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITE//������޷���ͣ������

//���籨��
#define F_MAINS_VOLT_HI      RAMDATABASE[sRn_MAIN_ALA_DATA1].BITS.BIT8//�е��ѹ��
#define F_MAINS_VOLT_LO      RAMDATABASE[sRn_MAIN_ALA_DATA1].BITS.BIT9//�е��ѹ��


//״̬λ

#define F_STA_FUELOUTPUT          RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT8//����
#define F_STA_PRESTART            RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT9//Ԥ��״̬
#define F_STA_CRANK               RAMDATABASE[sRn_COMMON_STATUS].BITS.BITA//��״̬
#define F_STA_WAITLOAD            RAMDATABASE[sRn_COMMON_STATUS].BITS.BITB//����ȴ�����
#define F_STA_IDLE                RAMDATABASE[sRn_COMMON_STATUS].BITS.BITC//�𶯵���״̬
#define F_STA_WARM                RAMDATABASE[sRn_COMMON_STATUS].BITS.BITD//ů��״̬
#define F_STA_DES_RUN             RAMDATABASE[sRn_COMMON_STATUS].BITS.BITE//����������״̬
#define F_STA_STARTDEL            RAMDATABASE[sRn_COMMON_STATUS].BITS.BITF//����ʱ״̬
#define F_STA_STOPDEL             RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT0//ͣ����ʱ״̬
#define F_STA_COOL                RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT1//ͣ��ɢ��״̬
#define F_STA_STOP_IDLE           RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT2//ͣ������״̬
#define F_STA_STOP_CHECK          RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT3//ͣ�����״̬

#define F_STA_STOP_FAIL           RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT8//ͣ��ʧ��״̬
#define F_STA_WARN                RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT9//����״̬
#define F_STA_STOPALARM           RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITA//����ͣ��״̬
#define F_STA_TIMER_SAFE          RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITB//��ȫ��ʱ״̬
#define F_STA_MANMODE             RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITC //�ֶ�ģʽ
#define F_STA_AUTOMODE            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITD //�Զ�ģʽ
#define F_STA_TESTMODE            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITE //����ģʽ
#define F_STA_STOPMODE            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITF //ͣ��ģʽ
#define F_STA_START_RETRY         RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT0 //�𶯼��
#define F_STA_MAINS_NORMAL_CHECK  RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT1 //�е��������
#define F_STA_MAINS_FAIL_CHECK    RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT2 //�е��쳣���
#define F_STA_STOPOUTPUT          RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT3//�õ�ͣ����ʱ״̬
#define F_STA_AMFSTART            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT4//ʧ����������ʱ
#define F_STA_AMFSTOP             RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT5//�õ���ͣ����ʱ

#define F_STA_STOP                RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT8//ͣ��״̬
#define F_STA_START_SUCC          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT9//�𶯳ɹ�״̬
#define F_STA_GEN_RUN             RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITA//���������״̬
#define F_STA_GEN_SUPP            RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITB//������鹩��״̬
#define F_STA_GEN_STOP            RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITC//�������ֹͣ״̬
#define F_STA_MAINS_FAIL          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITD//�е�ֹͣ״̬
#define F_STA_MAINS_RUN           RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITE//�е�����״̬
#define F_STA_MAINS_SUPP          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITF//�е繩��״̬
#define F_STA_TRANSCB             RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT0//����ת��״̬
#define F_DI_TEMPHI_STOP          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT1//�������¶ȸ߱���ͣ��
#define F_DI_OILP_STOP            RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT2//��������ѹ�ͱ���ͣ��
#define F_DI_FUELLOW_WRN          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT3//��������λ�;���
#define F_DI_WATERLOW_WRN         RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT4//������ˮλ�;���
#define F_DI_FUELLOW_STOP         RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT5//��������λ�ͱ���ͣ��
#define F_DI_WATERLOW_STOP        RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT6//������ˮλ�ͱ���ͣ��
                          

/* ******************************************************************** */
/*                   AlamrRun Delay Definitions                         */
/* ******************************************************************** */

//Ԥ����ʱ
#define DELVAL_PRESTART           (INT16U)(TimerSet[TMR_DES_PREHEAT_DEL]-TimerValue[TMR_DES_PREHEAT_DEL])/10+1

//ȼ�������ʱ
#define DELVAL_FUELOUTPUT         (INT16U)(TimerSet[TMR_DES_FUELOUT_DEL]-TimerValue[TMR_DES_FUELOUT_DEL])/10+1

//�������ʱ
#define DELVAL_CRANK              (INT16U)(TimerSet[TMR_DES_CRANK_DEL]-TimerValue[TMR_DES_CRANK_DEL])/10+1 

//��ȫ������ʱ
#define DELVAL_SAFE               (INT16U)(TimerSet[TMR_DES_SAFE_DEL]-TimerValue[TMR_DES_SAFE_DEL])/10+1 

//�𶯵�����ʱ
#define DELVAL_STARTIDLE          (INT16U)(TimerSet[TMR_DES_STARTIDLE_DEL]-TimerValue[TMR_DES_STARTIDLE_DEL])/10+1 

//ů����ʱ
#define DELVAL_WARM               (INT16U)(TimerSet[TMR_DES_WARM_DEL]-TimerValue[TMR_DES_WARM_DEL])/10+1 

//ͣ��ɢ����ʱ
#define DELVAL_COOLING            (INT16U)(TimerSet[TMR_DES_COOLING_DEL]-TimerValue[TMR_DES_COOLING_DEL])/10+1 

//ͣ��������ʱ
#define DELVAL_STOPIDLE           (INT16U)(TimerSet[TMR_DES_STOPIDLE_DEL]-TimerValue[TMR_DES_STOPIDLE_DEL])/10+1 

//�õ�ͣ����ʱ
#define DELVAL_STOPOUTPUT         (INT16U)(TimerSet[TMR_DES_STOPOUTPUT_DEL]-TimerValue[TMR_DES_STOPOUTPUT_DEL])/10+1 

//�ȴ�ͣ��
#define DELVAL_STOPCONFIRM        (INT16U)(TimerSet[TMR_DES_STOPSUCC_DEL]-TimerValue[TMR_DES_STOPSUCC_DEL])/10+1 

//ʧ����������ʱ
#define DELVAL_AMFSTART           (INT16U)(TimerSet[TMR_DES_COOLING_DEL]-TimerValue[TMR_DES_COOLING_DEL])/10+1 

//�õ���ͣ����ʱ
#define DELVAL_AMFSTOP            (INT16U)(TimerSet[TMR_AMF_STOP_DEL]-TimerValue[TMR_AMF_STOP_DEL])/10+1 

//�𶯼��
#define DELVAL_STARTINT           (INT16U)(TimerSet[TMR_DES_CRANKINT_DEL]-TimerValue[TMR_DES_CRANKINT_DEL])/10+1 

//�е�������ʱ
#define DELVAL_MAINSNORMAL        (INT16U)(TimerSet[TMR_MAINS_NORMAL_DEL]-TimerValue[TMR_MAINS_NORMAL_DEL])/10+1 

//�е��쳣��ʱ
#define DELVAL_MAINSABNORMAL      (INT16U)(TimerSet[TMR_MAINS_ABNORMAL_DEL]-TimerValue[TMR_MAINS_ABNORMAL_DEL])/10+1 

//ת����ʱ
#define DELVAL_TRANSCB            (INT16U)(TimerSet[TMR_MAINS_TRANS_DEL]-TimerValue[TMR_MAINS_TRANS_DEL])/10+1 

//����ʱ
#define DELVAL_START              (INT16U)(TimerSet[TMR_AMF_START_DEL]-TimerValue[TMR_AMF_START_DEL])/10+1 

//ͣ����ʱ
#define DELVAL_STOP               (INT16U)(TimerSet[TMR_AMF_STOP_DEL]-TimerValue[TMR_AMF_STOP_DEL])/10+1 

//������ʱ
#define DELVAL_OVERCURRENT        (INT16U)(TimerSet[TMR_GEN_OVERCURRENT_DEL]-TimerValue[TMR_GEN_OVERCURRENT_DEL])/10+1 
    

#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */




