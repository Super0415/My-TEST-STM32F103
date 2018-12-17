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
#define M410DelMainBusPg       5  //410ÐÍºÅÈ¥³ýÊÐµç²¿·Ö²Ëµ¥
#define M410DelAdjMBusPg       3  //410ÐÍºÅÈ¥³ýÊÐµç²¿·Ö²ÎÊýÐ£Ñé²Ëµ¥

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
 #define GensStopAlarm1       AlarmMaping[0]     //Í£»ú×´Ì¬Ó³Éä
 #define GensStopAlarm2       AlarmMaping[1]
 #define GensWarningAlarm1    AlarmMaping[2]     //??
 #define GensWarningAlarm2    AlarmMaping[3]
 #define GensRunStation1      AlarmMaping[4]
 #define GensRunStation2      AlarmMaping[5]
 #define GensRunStation3      AlarmMaping[6]
 
 /***********************************************************************/
 /*                    ÁÙÊ±Ôö¼Ó¶¨Òå                                                 */
 /***********************************************************************/
#define sAdjParmPageCon          18   //GEC400¿Ø²ÎÊýÕû¶¨Ò³ÃæÊýÁ¿
extern INT16U TESTZC[50];

/* ******************************************************************** */
/*                       ÏÔÊ¾²ÎÊýÐ£ÑéÓ³Éä                               */
/* ******************************************************************** */
 #define AdjDataMapCon		sAdjParmPageCon
  extern STRFLG16 AdjDataMapBuf[AdjDataMapCon];  //ÊµÊ±ÏÔÊ¾ÐÞ¸Ä²ÎÊýÐ£ÑéÊý¾ÝÓ³ÉäÊý×é
 
  #define AdjMapVOLTAGEA2       AdjDataMapBuf[0].Sbyte//ÊÐµçAµçÑ¹Ð£Ñé
  #define AdjMapVOLTAGEB2       AdjDataMapBuf[1].Sbyte//ÊÐµçBµçÑ¹Ð£Ñé
  #define AdjMapVOLTAGEC2       AdjDataMapBuf[2].Sbyte//ÊÐµçCµçÑ¹Ð£Ñé
  #define AdjMapVOLTAGEA1       AdjDataMapBuf[3].Sbyte//·¢µçAµçÑ¹Ð£Ñé
  #define AdjMapVOLTAGEB1       AdjDataMapBuf[4].Sbyte//·¢µçBµçÑ¹Ð£Ñé
  #define AdjMapVOLTAGEC1       AdjDataMapBuf[5].Sbyte//·¢µçCµçÑ¹Ð£Ñé
  #define AdjMapCURRENTA        AdjDataMapBuf[6].Sbyte//AÏàµçÁ÷Ð£Ñé
  #define AdjMapCURRENTB        AdjDataMapBuf[7].Sbyte//BÏàµçÁ÷Ð£Ñé
  #define AdjMapCURRENTC        AdjDataMapBuf[8].Sbyte//CÏàµçÁ÷Ð£Ñé
  #define AdjMapWATERTEMP       AdjDataMapBuf[9].Sbyte//Ë®¸×ÎÂÐ£Ñé
  #define AdjMapOILPRESSURE     AdjDataMapBuf[10].Sbyte//»úÓÍÑ¹Á¦Ð£Ñé
  #define AdjMapFUEL            AdjDataMapBuf[11].Sbyte//È¼ÓÍÎ»Ð£Ñé
  #define AdjMapCustomAog       AdjDataMapBuf[12].Sbyte//×Ô¶¨ÒåÄ£ÄâÁ¿Ð£Ñé
  #define AdjMapPowerVoltage    AdjDataMapBuf[13].Sbyte//µç³ØµçÑ¹Ð£Ñé
  #define AdjMapChargerVoltage  AdjDataMapBuf[14].Sbyte//³äµç»úD+
  #define AdjMapPhaseCOS        AdjDataMapBuf[15].Sbyte//·¢µç¹¦ÂÊÒòÊý

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


////////----------ÓïÑÔ±êÖ¾-------
//extern INT16U Language_select;     //ÓïÑÔÀàÐÍ   
#define  LCD_LanguageEnglish     0    //0:Ó¢ÎÄ
#define  LCD_LanguageChinese     1	  //1:ÖÐÎÄ

#define  GensRunMSaveCon     10                                    //·¢¶¯»úÔËÐÐ²ÎÊý±£´æflashÎ»ÖÃ ¸öÊý
#define  GensRunMSaveCtr     (FLASH_FLASH_ArrayCon-GensRunMSaveCon)  //·¢¶¯»úÔËÐÐ²ÎÊý±£´æflashÎ»ÖÃ 
#define  GensDateErrStaCon   10                                    //·¢¶¯»úÔËÐÐ²ÎÊý±£´æflashÎ»ÖÃ ¸öÊý
#define  GensDateErrSta     (FLASH_RAM_ArrayCon-GensDateErrStaCon)   //´ÓflashÖÐ¶ÁÈ¡²ÎÊý×´Ì¬
/* ******************************************************************** */
/*                    ENUM  Flash Memery Definitions                    */
/* ******************************************************************** */

const typedef enum   //²ÎÊýÉèÖÃ×Ó²Ëµ¥Ã¶¾ÙÀàÐÍ  sPn --> sParmSetnum 
{
 /*-00-*/     sPn_NON_NON                =0 ,//±¸ÓÃ
 /*-01-*/     sPn_MAINS_NORMAL_DEL       =0 ,//ÊÐµçÕý³£ÑÓÊ±
 /*-02-*/     sPn_MAINS_OBNORMAL_DEL     =1 ,//ÊÐµçÒì³£ÑÓÊ±
 /*-03-*/     sPn_MAINS_VOLT_LOW            ,//ÊÐµçÇ·Ñ¹·§Öµ
 /*-04-*/     sPn_MAINS_VOLT_HIGH           ,//ÊÐµç¹ýÑ¹·§Öµ      
 /*-05-*/     sPn_MAINS_TRANS_DEL           ,//¿ª¹Ø×ª»»ÑÓÊ±
 /*-06-*/     sPn_AMF_START_DEL             ,//¿ª»úÑÓÊ±
 /*-07-*/     sPn_AMF_STOP_DEL              ,//Í£»úÑÓÊ±
 /*-08-*/     sPn_DES_START_NUM             ,//Æð¶¯´ÎÊý
 /*-09-*/     sPn_DES_PREHEAT_DEL           ,//Ô¤ÈÈÊ±¼ä
 /*-10-*/     sPn_DES_CRANK_DEL             ,//Æð¶¯Ê±¼ä
 /*-11-*/     sPn_DES_CRANKINT_DEL          ,//Æð¶¯¼ä¸ôÊ±¼ä
 /*-12-*/     sPn_DES_SAFE_DEL              ,//°²È«ÔËÐÐÊ±¼ä
 /*-13-*/     sPn_DES_STARTIDLE_DEL         ,//¿ª»úµ¡ËÙÊ±¼ä
 /*-14-*/     sPn_DES_WARM_DEL              ,//Å¯»úÊ±¼ä
 /*-15-*/     sPn_DES_COOLING_DEL           ,//É¢ÈÈÊ±¼ä
 /*-16-*/     sPn_DES_STOPIDLE_DEL          ,//Í£»úµ¡ËÙÊ±¼ä
 /*-17-*/     sPn_DES_STOPOUTPUT_DEL        ,//µÃµçÍ£»úÊ±¼ä
 /*-18-*/     sPn_DES_STOPSUCC_DEL          ,//µÈ´ýÍ£ÎÈÑÓÊ±
 /*-19-*/     sPn_GEN_MCBGCB_DEL            ,//¿ª¹ØºÏÕ¢ÑÓÊ±
 /*-20-*/     sPn_DES_GEARTEETH             ,//·ÉÂÖ³ÝÊý
 /*-21-*/     sPn_GEN_OBNORMAL_DEL          ,//·¢µçÒì³£ÑÓÊ±
 /*-22-*/     sPn_GEN_VOLTHIGH_STOP         ,//·¢µç¹ýÑ¹·§ÖµÍ£»ú
 /*-23-*/     sPn_GEN_VOLTLOW_STOP          ,//·¢µçÇ·Ñ¹·§ÖµÍ£»ú
 /*-24-*/     sPn_DES_LOWSPEED              ,//Ç·ËÙ·§Öµ
 /*-25-*/     sPn_DES_HIGHSPEED             ,//³¬ËÙ·§Öµ
 /*-26-*/     sPn_GEN_FREQLOW               ,//·¢µçÇ·Æµ·§Öµ
 /*-27-*/     sPn_GEN_FREQHIGH              ,//·¢µç¹ýÆµ·§Öµ
 /*-28-*/     sPn_DES_HITEMP                ,//¸ßË®ÎÂ·§Öµ
 /*-29-*/     sPn_DES_LOWOP                 ,//µÍÓÍÑ¹·§Öµ
 /*-30-*/     sPn_DES_LOWLEVEL              ,//È¼ÓÍÎ»·§Öµ
 /*-31-*/     sPn_DES_LOSTSPEED_DEL         ,//ËÙ¶ÈÐÅºÅ¶ªÊ§ÑÓÊ±
 /*-32-*/     sPn_DES_CHARGEFAULT           ,//³äµçÊ§°Ü·§Öµ
 /*-33-*/     sPn_DES_BATTHI                ,//µç³Ø¹ýÑ¹·§Öµ
 /*-34-*/     sPn_DES_BATTLOW               ,//µç³ØÇ·Ñ¹·§Öµ
 /*-35-*/     sPn_GEN_CT                    ,//µçÁ÷»¥¸ÐÆ÷±ä±È
 /*-36-*/     sPn_GEN_RATINGCURRENT         ,//ÂúÔØµçÁ÷
 /*-37-*/     sPn_GEN_OVERCURRENT           ,//¹ýÁ÷°Ù·Ö±È
 /*-38-*/     sPn_GEN_OVERCURRENT_DEL       ,//¹ýÁ÷ÑÓÊ±
 /*-39-*/     sPn_DES_FUELPUMP_ON           ,//È¼ÓÍ±Ã¿ª·§Öµ
 /*-40-*/     sPn_DES_FUELPUMP_OFF          ,//È¼ÓÍ±Ã¹Ø·§Öµ
 /*-41-*/     sPn_COMMON_OUTPUTFUNC1        ,//¿É±à³ÌÊä³ö1¹¦ÄÜ
 /*-42-*/     sPn_COMMON_OUTPUTFUNC2        ,//¿É±à³ÌÊä³ö2¹¦ÄÜ
 /*-43-*/     sPn_COMMON_OUTPUTFUNC3        ,//¿É±à³ÌÊä³ö3¹¦ÄÜ
 /*-44-*/     sPn_COMMON_OUTPUTFUNC4        ,//¿É±à³ÌÊä³ö4¹¦ÄÜ
 /*-45-*/     sPn_COMMON_OUTPUTFUNC5        ,//¿É±à³ÌÊä³ö5¹¦ÄÜ
 /*-46-*/     sPn_COMMON_OUTPUTFUNC6        ,//¿É±à³ÌÊä³ö6¹¦ÄÜ
 /*-47-*/     sPn_COMMON_INPUTFUNC1         ,//¿É±à³ÌÊäÈë1¹¦ÄÜ
 /*-48-*/     sPn_COMMON_INPUTFUNC1_VALID   ,//¿É±à³ÌÊäÈë1ÓÐÐ§
 /*-49-*/     sPn_COMMON_INPUTFUNC1_DELAY   ,//¿É±à³ÌÊäÈë1ÑÓÊ±
 /*-50-*/     sPn_COMMON_INPUTFUNC2         ,//¿É±à³ÌÊäÈë2¹¦ÄÜ
 /*-51-*/     sPn_COMMON_INPUTFUNC2_VALID   ,//¿É±à³ÌÊäÈë2ÓÐÐ§
 /*-52-*/     sPn_COMMON_INPUTFUNC2_DELAY   ,//¿É±à³ÌÊäÈë2ÑÓÊ±
 /*-53-*/     sPn_COMMON_INPUTFUNC3         ,//¿É±à³ÌÊäÈë3¹¦ÄÜ
 /*-54-*/     sPn_COMMON_INPUTFUNC3_VALID   ,//¿É±à³ÌÊäÈë3ÓÐÐ§
 /*-55-*/     sPn_COMMON_INPUTFUNC3_DELAY   ,//¿É±à³ÌÊäÈë3ÑÓÊ±
 /*-56-*/     sPn_DES_STARTINIT             ,//¿ª»ú×´Ì¬Ñ¡Ôñ
 /*-57-*/     sPn_COMMON_ADDR               ,//¿ØÖÆÆ÷µØÖ·Ñ¡Ôñ
 /*-58-*/     sPn_DES_PASSWORD              ,//¿ÚÁîÉèÖÃ
 /*-59-*/     sPn_DES_STARTSUCC_CONDITION   ,//Æð¶¯³É¹¦Ìõ¼þ
 /*-60-*/     sPn_DES_STARTSUCC_SPEED       ,//Æð¶¯³É¹¦×ªËÙ
 /*-61-*/     sPn_DES_STARTSUCC_FREQ        ,//Æð¶¯³É¹¦ÆµÂÊ
 /*-62-*/     sPn_DES_STARTSUCC_OP          ,//Æð¶¯³É¹¦ÓÍÑ¹
 /*-63-*/     sPn_DES_TEMPHIGH_NOSTOP       ,//ÎÂ¶È¸ß½ûÖ¹Í£»ú
 /*-64-*/     sPn_DES_OPLOW_NOSTOP          ,//ÓÍÑ¹µÍ½ûÖ¹Í£»ú
 /*-65-*/     sPn_GEN_VOLT_TYPE             ,//µçÑ¹ÊäÈëÀàÐÍÑ¡Ôñ
 /*-66-*/     sPn_DES_TEMP_SENSOR           ,//ÎÂ¶È´«¸ÐÆ÷Ñ¡Ôñ
 /*-67-*/     sPn_DES_OP_SENSOR             ,//Ñ¹Á¦´«¸ÐÆ÷Ñ¡Ôñ
 /*-68-*/     sPn_DES_LV_SENSOR             ,//ÒºÎ»´«¸ÐÆ÷Ñ¡Ôñ
 /*-69-*/     sPn_GEN_POLENUM               ,//·¢µç»ú¼«Êý
 /*-70-*/     sPn_BREAK_TEMP_SENSOR         ,//ÎÂ¶È´«¸ÐÆ÷¶ÏÏß¶¯×÷Ñ¡Ôñ
 /*-71-*/     sPn_BREAK_OP_SENSOR           ,//Ñ¹Á¦´«¸ÐÆ÷¶ÏÏß¶¯×÷Ñ¡Ôñ
 /*-72-*/     sPn_BREAK_LV_SENSOR           ,//ÒºÎ»´«¸ÐÆ÷¿ªÂ·¶¯×÷
 /*-73-*/     sPn_CUSTOM_SENSOR_TYPE        ,//×Ô¶¨ÒåÇúÏßÐòºÅ
 /*-74-*/     sPn_GENS_TYPE                 ,//·¢¶¯»úÀàÐÍ ÆÕÍ¨»ú/J1939µçÅç»ú
 /*-75-*/     sPn_LanguageTYPE_Selection    ,//¿ØÖÆÆ÷ÓïÑÔÀàÐÍ
/*-76-*/      sPa_VOLT_MAINS_A,//ÊÐµçAµçÑ¹Ð£Ñé	//²ÎÊýÐ£Ñé	 sPa --> sParmAdj 
/*-77-*/      sPa_VOLT_MAINS_B,//ÊÐµçBµçÑ¹Ð£Ñé
/*-78-*/      sPa_VOLT_MAINS_C,//ÊÐµçCµçÑ¹Ð£Ñé
/*-79-*/      sPa_VOLT_GEN_A  ,//·¢µçAµçÑ¹Ð£Ñé
/*-80-*/      sPa_VOLT_GEN_B  ,//·¢µçBµçÑ¹Ð£Ñé
/*-81-*/  	  sPa_VOLT_GEN_C  ,//·¢µçCµçÑ¹Ð£Ñé
/*-82-*/      sPa_CURRENT_A   ,//AÏàµçÁ÷Ð£Ñé
/*-83-*/      sPa_CURRENT_B   ,//BÏàµçÁ÷Ð£Ñé
/*-84-*/      sPa_CURRENT_C   ,//CÏàµçÁ÷Ð£Ñé
/*-85-*/      sPa_TEMP        ,//Ë®¸×ÎÂÐ£Ñé
/*-86-*/  	  sPa_OP          ,//»úÓÍÑ¹Á¦Ð£Ñé
/*-87-*/      sPa_LEVEL       ,//È¼ÓÍÎ»Ð£Ñé	/×Ô¶¨Òå1
/*-88-*/      sPa_CustomAnalog,//           /×Ô¶¨Òå2
/*-89-*/      sPa_BATT        ,//µç³ØµçÑ¹Ð£Ñé
/*-90-*/      sPa_CHARGER     ,//³äµç»úD+
/*-91-*/      sPa_COS         ,//·¢µç¹¦ÂÊÒòÊý
/*-92-*/      sPa_MODEL       ,//¿ØÖÆÆ÷Ñ¡Ôñ
/*-93-*/      sPa_RestFactory ,//»Ö¸´³ö³§²ÎÊýÉèÖÃ
/*-94-*/      sPc_TEMP_R1, //ÎÂ¶È×Ô¶¨Òå´«¸ÐÆ÷ÇúÏß	sPc --> sParmCus 
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
/*-110-*/     sPc_OP_R1,   //Ñ¹Á¦×Ô¶¨Òå´«¸ÐÆ÷ÇúÏß
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
/*-126-*/     sPc_LV_R1, 	//ÒºÎ»×Ô¶¨Òå´«¸ÐÆ÷ÇúÏß 
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
/*-142-*/     sPc_REUSE_R1, 	//×Ô¶¨Òå´«¸ÐÆ÷ÇúÏß ¸´ÓÃ2
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
/*-155-*/     sCtl_CONTROL_CONFIRM          ,//RS485Ò£¿Ø
/*-156-*/     sCtl_CONTROL_COMMAND          ,//RS485Ò£¿ØÃüÁî 
/*-157-*/     sPc_REUSE_V6,
/*-158-*/     sPc_REUSE_V7, 
/*-159-*/     sPc_REUSE_V8,
} sParmSetHeadnum;                       

			 
/* ******************************************************************** */
/*                    FLASH  Measurement Definitions                    */
/* ******************************************************************** */
							 
/*-01-*/ #define MAINS_NORMAL_DEL             FLASHDATABASE[sPn_MAINS_NORMAL_DEL        ].Sbyte //ÊÐµçÕý³£ÑÓÊ±
/*-02-*/ #define MAINS_OBNORMAL_DEL           FLASHDATABASE[sPn_MAINS_OBNORMAL_DEL      ].Sbyte //ÊÐµçÒì³£ÑÓÊ±
/*-03-*/ #define MAINS_VOLT_LOW               FLASHDATABASE[sPn_MAINS_VOLT_LOW          ].Sbyte //ÊÐµçÇ·Ñ¹·§Öµ
/*-04-*/ #define MAINS_VOLT_HIGH              FLASHDATABASE[sPn_MAINS_VOLT_HIGH         ].Sbyte //ÊÐµç¹ýÑ¹·§Öµ      
/*-05-*/ #define MAINS_TRANS_DEL              FLASHDATABASE[sPn_MAINS_TRANS_DEL         ].Sbyte //¿ª¹Ø×ª»»ÑÓÊ±
/*-06-*/ #define AMF_START_DEL                FLASHDATABASE[sPn_AMF_START_DEL           ].Sbyte //¿ª»úÑÓÊ±
/*-07-*/ #define AMF_STOP_DEL                 FLASHDATABASE[sPn_AMF_STOP_DEL            ].Sbyte //Í£»úÑÓÊ±
/*-08-*/ #define DES_START_NUM                FLASHDATABASE[sPn_DES_START_NUM           ].Sbyte //Æô¶¯´ÎÊý
/*-09-*/ #define DES_PREHEAT_DEL              FLASHDATABASE[sPn_DES_PREHEAT_DEL         ].Sbyte //Ô¤ÈÈÊ±¼ä
/*-10-*/ #define DES_CRANK_DEL                FLASHDATABASE[sPn_DES_CRANK_DEL           ].Sbyte //Æô¶¯Ê±¼ä
/*-11-*/ #define DES_CRANKINT_DEL             FLASHDATABASE[sPn_DES_CRANKINT_DEL        ].Sbyte//Æô¶¯¼ä¸ôÊ±¼ä
/*-12-*/ #define DES_SAFE_DEL                 FLASHDATABASE[sPn_DES_SAFE_DEL            ].Sbyte//°²È«ÔËÐÐÊ±¼ä
/*-13-*/ #define DES_STARTIDLE_DEL            FLASHDATABASE[sPn_DES_STARTIDLE_DEL       ].Sbyte//¿ª»úµ¡ËÙÊ±¼ä
/*-14-*/ #define DES_WARM_DEL                 FLASHDATABASE[sPn_DES_WARM_DEL            ].Sbyte//Å¯»úÊ±¼ä
/*-15-*/ #define DES_COOLING_DEL              FLASHDATABASE[sPn_DES_COOLING_DEL         ].Sbyte//É¢ÈÈÊ±¼ä
/*-16-*/ #define DES_STOPIDLE_DEL             FLASHDATABASE[sPn_DES_STOPIDLE_DEL        ].Sbyte//Í£»úµ¡ËÙÊ±¼ä
/*-17-*/ #define DES_STOPOUTPUT_DEL           FLASHDATABASE[sPn_DES_STOPOUTPUT_DEL      ].Sbyte//µÃµçÍ£»úÊ±¼ä
/*-18-*/ #define DES_STOPSUCC_DEL             FLASHDATABASE[sPn_DES_STOPSUCC_DEL        ].Sbyte//µÈ´ýÍ£ÎÈÑÓÊ±
/*-19-*/ #define GEN_MCBGCB_DEL               FLASHDATABASE[sPn_GEN_MCBGCB_DEL          ].Sbyte//¿ª¹ØºÏÕ¢ÑÓÊ±
/*-20-*/ #define DES_GEARTEETH                FLASHDATABASE[sPn_DES_GEARTEETH           ].Sbyte//·ÉÂÖ³ÝÊý
/*-21-*/ #define GEN_OBNORMAL_DEL             FLASHDATABASE[sPn_GEN_OBNORMAL_DEL        ].Sbyte//·¢µçÒì³£ÑÓÊ±
/*-22-*/ #define GEN_VOLTHIGH_STOP            FLASHDATABASE[sPn_GEN_VOLTHIGH_STOP       ].Sbyte//·¢µç¹ýÑ¹·§ÖµÍ£»ú
/*-23-*/ #define GEN_VOLTLOW_STOP             FLASHDATABASE[sPn_GEN_VOLTLOW_STOP        ].Sbyte//·¢µçÇ·Ñ¹·§ÖµÍ£»ú
/*-24-*/ #define DES_LOWSPEED                 FLASHDATABASE[sPn_DES_LOWSPEED            ].Sbyte//Ç·ËÙ·§Öµ
/*-25-*/ #define DES_HIGHSPEED                FLASHDATABASE[sPn_DES_HIGHSPEED           ].Sbyte//³¬ËÙ·§Öµ
/*-26-*/ #define GEN_FREQLOW                  FLASHDATABASE[sPn_GEN_FREQLOW             ].Sbyte//·¢µçÇ·Æµ·§Öµ
/*-27-*/ #define GEN_FREQHIGH                 FLASHDATABASE[sPn_GEN_FREQHIGH            ].Sbyte//·¢µç¹ýÆµ·§Öµ
/*-28-*/ #define DES_HITEMP                   FLASHDATABASE[sPn_DES_HITEMP              ].Sbyte//¸ßË®ÎÂ·§Öµ
/*-29-*/ #define DES_LOWOP                    FLASHDATABASE[sPn_DES_LOWOP               ].Sbyte//µÍÓÍÑ¹·§Öµ
/*-30-*/ #define DES_LOWLEVEL                 FLASHDATABASE[sPn_DES_LOWLEVEL            ].Sbyte//È¼ÓÍÎ»·§Öµ
/*-31-*/ #define DES_LOSTSPEED_DEL            FLASHDATABASE[sPn_DES_LOSTSPEED_DEL       ].Sbyte//ËÙ¶ÈÐÅºÅ¶ªÊ§ÑÓÊ±
/*-32-*/ #define DES_CHARGEFAULT              FLASHDATABASE[sPn_DES_CHARGEFAULT         ].Sbyte//³äµçÊ§°Ü·§Öµ
/*-33-*/ #define DES_BATTHI                   FLASHDATABASE[sPn_DES_BATTHI              ].Sbyte//µç³Ø¹ýÑ¹·§Öµ
/*-34-*/ #define DES_BATTLOW                  FLASHDATABASE[sPn_DES_BATTLOW             ].Sbyte//µç³ØÇ·Ñ¹·§Öµ
/*-35-*/ #define GEN_CT                       FLASHDATABASE[sPn_GEN_CT                  ].Sbyte//µçÁ÷»¥¸ÐÆ÷±ä±È
/*-36-*/ #define GEN_RATINGCURRENT            FLASHDATABASE[sPn_GEN_RATINGCURRENT       ].Sbyte//ÂúÔØµçÁ÷
/*-37-*/ #define GEN_OVERCURRENT              FLASHDATABASE[sPn_GEN_OVERCURRENT         ].Sbyte//¹ýÁ÷°Ù·Ö±È
/*-38-*/ #define GEN_OVERCURRENT_DEL          FLASHDATABASE[sPn_GEN_OVERCURRENT_DEL     ].Sbyte//¹ýÁ÷ÑÓÊ±
/*-39-*/ #define DES_FUELPUMP_ON              FLASHDATABASE[sPn_DES_FUELPUMP_ON         ].Sbyte//È¼ÓÍ±Ã¿ª·§Öµ
/*-40-*/ #define DES_FUELPUMP_OFF             FLASHDATABASE[sPn_DES_FUELPUMP_OFF        ].Sbyte//È¼ÓÍ±Ã¹Ø·§Öµ
/*-41-*/ #define COMMON_OUTPUTFUNC1           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC1      ].Sbyte//¿É±à³ÌÊä³ö1¹¦ÄÜ
/*-42-*/ #define COMMON_OUTPUTFUNC2           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC2      ].Sbyte//¿É±à³ÌÊä³ö2¹¦ÄÜ
/*-43-*/ #define COMMON_OUTPUTFUNC3           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC3      ].Sbyte//¿É±à³ÌÊä³ö3¹¦ÄÜ
/*-44-*/ #define COMMON_OUTPUTFUNC4           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC4      ].Sbyte//¿É±à³ÌÊä³ö4¹¦ÄÜ
/*-45-*/ #define COMMON_OUTPUTFUNC5           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC5      ].Sbyte//¿É±à³ÌÊä³ö5¹¦ÄÜ
/*-46-*/ #define COMMON_OUTPUTFUNC6           FLASHDATABASE[sPn_COMMON_OUTPUTFUNC6      ].Sbyte//¿É±à³ÌÊä³ö6¹¦ÄÜ
/*-47-*/ #define COMMON_INPUTFUNC1            FLASHDATABASE[sPn_COMMON_INPUTFUNC1       ].Sbyte//¿É±à³ÌÊäÈë1¹¦ÄÜ
/*-48-*/ #define COMMON_INPUTFUNC1_VALID      FLASHDATABASE[sPn_COMMON_INPUTFUNC1_VALID ].Sbyte//¿É±à³ÌÊäÈë1ÓÐÐ§
/*-49-*/ #define COMMON_INPUTFUNC1_DELAY      FLASHDATABASE[sPn_COMMON_INPUTFUNC1_DELAY ].Sbyte//¿É±à³ÌÊäÈë1ÑÓÊ±
/*-50-*/ #define COMMON_INPUTFUNC2            FLASHDATABASE[sPn_COMMON_INPUTFUNC2       ].Sbyte//¿É±à³ÌÊäÈë2¹¦ÄÜ
/*-51-*/ #define COMMON_INPUTFUNC2_VALID      FLASHDATABASE[sPn_COMMON_INPUTFUNC2_VALID ].Sbyte//¿É±à³ÌÊäÈë2ÓÐÐ§
/*-52-*/ #define COMMON_INPUTFUNC2_DELAY      FLASHDATABASE[sPn_COMMON_INPUTFUNC2_DELAY ].Sbyte//¿É±à³ÌÊäÈë2ÑÓÊ±
/*-53-*/ #define COMMON_INPUTFUNC3            FLASHDATABASE[sPn_COMMON_INPUTFUNC3       ].Sbyte//¿É±à³ÌÊäÈë3¹¦ÄÜ
/*-54-*/ #define COMMON_INPUTFUNC3_VALID      FLASHDATABASE[sPn_COMMON_INPUTFUNC3_VALID ].Sbyte//¿É±à³ÌÊäÈë3ÓÐÐ§
/*-55-*/ #define COMMON_INPUTFUNC3_DELAY      FLASHDATABASE[sPn_COMMON_INPUTFUNC3_DELAY ].Sbyte//¿É±à³ÌÊäÈë3ÑÓÊ±
/*-56-*/ #define DES_STARTINIT                FLASHDATABASE[sPn_DES_STARTINIT           ].Sbyte//¿ª»ú×´Ì¬Ñ¡Ôñ
/*-57-*/ #define COMMON_ADDR                  FLASHDATABASE[sPn_COMMON_ADDR             ].Sbyte//¿ØÖÆÆ÷µØÖ·Ñ¡Ôñ
/*-58-*/ #define DES_PASSWORD                 FLASHDATABASE[sPn_DES_PASSWORD            ].Sbyte//¿ÚÁîÉèÖÃ
/*-59-*/ #define DES_STARTSUCC_CONDITION      FLASHDATABASE[sPn_DES_STARTSUCC_CONDITION ].Sbyte//Æô¶¯³É¹¦Ìõ¼þ
/*-60-*/ #define DES_STARTSUCC_SPEED          FLASHDATABASE[sPn_DES_STARTSUCC_SPEED     ].Sbyte//Æô¶¯³É¹¦×ªËÙ
/*-61-*/ #define DES_STARTSUCC_FREQ           FLASHDATABASE[sPn_DES_STARTSUCC_FREQ      ].Sbyte//Æô¶¯³É¹¦ÆµÂÊ
/*-62-*/ #define DES_STARTSUCC_OP             FLASHDATABASE[sPn_DES_STARTSUCC_OP        ].Sbyte//Æô¶¯³É¹¦ÓÍÑ¹
/*-63-*/ #define DES_TEMPHIGH_NOSTOP          FLASHDATABASE[sPn_DES_TEMPHIGH_NOSTOP     ].Sbyte//ÎÂ¶È¸ß½ûÖ¹Í£»ú
/*-64-*/ #define DES_OPLOW_NOSTOP             FLASHDATABASE[sPn_DES_OPLOW_NOSTOP        ].Sbyte//ÓÍÑ¹µÍ½ûÖ¹Í£»ú
/*-65-*/ #define GEN_VOLT_TYPE                FLASHDATABASE[sPn_GEN_VOLT_TYPE           ].Sbyte//µçÑ¹ÊäÈëÀàÐÍÑ¡Ôñ
/*-66-*/ #define DES_TEMP_SENSOR              FLASHDATABASE[sPn_DES_TEMP_SENSOR         ].Sbyte//ÎÂ¶È´«¸ÐÆ÷Ñ¡Ôñ
/*-67-*/ #define DES_OP_SENSOR                FLASHDATABASE[sPn_DES_OP_SENSOR           ].Sbyte//Ñ¹Á¦´«¸ÐÆ÷Ñ¡Ôñ
/*-68-*/ #define DES_LV_SENSOR                FLASHDATABASE[sPn_DES_LV_SENSOR           ].Sbyte//ÒºÎ»´«¸ÐÆ÷Ñ¡Ôñ
/*-69-*/ #define GEN_POLENUM                  FLASHDATABASE[sPn_GEN_POLENUM             ].Sbyte//·¢µç»ú¼«Êý
/*-70-*/ #define BREAK_TEMP_SENSOR            FLASHDATABASE[sPn_BREAK_TEMP_SENSOR       ].Sbyte//ÎÂ¶È´«¸ÐÆ÷¶ÏÏß¶¯×÷Ñ¡Ôñ
/*-71-*/ #define BREAK_OP_SENSOR    	      FLASHDATABASE[sPn_BREAK_OP_SENSOR         ].Sbyte//Ñ¹Á¦´«¸ÐÆ÷¶ÏÏß¶¯×÷Ñ¡Ôñ
/*-72-*/ #define BREAK_LV_SENSOR	          FLASHDATABASE[sPn_BREAK_LV_SENSOR         ].Sbyte//ÒºÎ»´«¸ÐÆ÷¶ÏÏß¶¯×÷Ñ¡Ôñ
/*-73-*/ #define CUSTOM_SENSOR_TYPE           FLASHDATABASE[sPn_CUSTOM_SENSOR_TYPE      ].Sbyte//×Ô¶¨ÒåÇúÏßÐòºÅ
/*-74-*/ #define GES_GENS_TYPE                FLASHDATABASE[sPn_GENS_TYPE               ].Sbyte//·¢¶¯»úÀàÐÍ ÆÕÍ¨»ú/J1939µçÅç»ú
/*-75-*/ #define Language_select              FLASHDATABASE[sPn_LanguageTYPE_Selection  ].Sbyte//¿ØÖÆÆ÷ÓïÑÔÀàÐÍ
/*-76-*/ #define RECAL_VOLT_MAINS_A           FLASHDATABASE[sPa_VOLT_MAINS_A            ].Sbyte//ÊÐµçAµçÑ¹Ð£Ñé	 // Adjust  Measurement Definitions  
/*-77-*/ #define RECAL_VOLT_MAINS_B           FLASHDATABASE[sPa_VOLT_MAINS_B            ].Sbyte//ÊÐµçBµçÑ¹Ð£Ñé
/*-78-*/ #define RECAL_VOLT_MAINS_C           FLASHDATABASE[sPa_VOLT_MAINS_C            ].Sbyte//ÊÐµçCµçÑ¹Ð£Ñé
/*-79-*/ #define RECAL_VOLT_GEN_A             FLASHDATABASE[sPa_VOLT_GEN_A              ].Sbyte//·¢µçAµçÑ¹Ð£Ñé
/*-80-*/ #define RECAL_VOLT_GEN_B             FLASHDATABASE[sPa_VOLT_GEN_B              ].Sbyte//·¢µçBµçÑ¹Ð£Ñé
/*-81-*/ #define RECAL_VOLT_GEN_C             FLASHDATABASE[sPa_VOLT_GEN_C              ].Sbyte//·¢µçCµçÑ¹Ð£Ñé
/*-82-*/ #define RECAL_CURRENT_A              FLASHDATABASE[sPa_CURRENT_A               ].Sbyte//AÏàµçÁ÷Ð£Ñé
/*-83-*/ #define RECAL_CURRENT_B              FLASHDATABASE[sPa_CURRENT_B               ].Sbyte//BÏàµçÁ÷Ð£Ñé
/*-84-*/ #define RECAL_CURRENT_C              FLASHDATABASE[sPa_CURRENT_C               ].Sbyte//CÏàµçÁ÷Ð£Ñé
/*-85-*/ #define RECAL_TEMP                   FLASHDATABASE[sPa_TEMP                    ].Sbyte//Ë®¸×ÎÂÐ£Ñé
/*-86-*/ #define RECAL_OP                     FLASHDATABASE[sPa_OP                      ].Sbyte//»úÓÍÑ¹Á¦Ð£Ñé
/*-87-*/ #define RECAL_LEVEL                  FLASHDATABASE[sPa_LEVEL                   ].Sbyte//È¼ÓÍÎ»Ð£Ñé
/*-88-*/ #define RECAL_CustomAnalog           FLASHDATABASE[sPa_CustomAnalog            ].Sbyte//×Ô¶¨ÒåÄ£ÄâÁ¿Ð£Ñé
/*-89-*/ #define RECAL_BATT                   FLASHDATABASE[sPa_BATT                    ].Sbyte//µç³ØµçÑ¹Ð£Ñé
/*-90-*/ #define RECAL_CHARGER                FLASHDATABASE[sPa_CHARGER                 ].Sbyte//³äµç»úD+
/*-91-*/ #define RECAL_COS                    FLASHDATABASE[sPa_COS                     ].Sbyte//·¢µç¹¦ÂÊÒòÊý
/*-92-*/ #define COMMON_MODEL                 FLASHDATABASE[sPa_MODEL                   ].Sbyte//¿ØÖÆÆ÷Ñ¡Ôñ
/*-93-*/ #define Ctl_RestFactory	            FLASHDATABASE[sPa_RestFactory             ].Sbyte //»Ö¸´³ö³§²ÎÊýÉèÖÃ
/*-94-*/ #define DES_CUSTOM_SENSOR_TEMP_R1    FLASHDATABASE[sPc_TEMP_R1 ].Sbyte//ÎÂ¶È×Ô¶¨Òå´«¸ÐÆ÷ÇúÏß 
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
/*-110-*/#define DES_CUSTOM_SENSOR_OP_R1      FLASHDATABASE[sPc_OP_R1   ].Sbyte//Ñ¹Á¦×Ô¶¨Òå´«¸ÐÆ÷ÇúÏß
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
/*-126-*/#define DES_CUSTOM_SENSOR_LV_R1      FLASHDATABASE[sPc_LV_R1   ].Sbyte//ÒºÎ»×Ô¶¨Òå´«¸ÐÆ÷ÇúÏß ¸´ÓÃ1
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
/*-142-*/#define DES_CUSTOM_SENSOR_REUSE_R1   FLASHDATABASE[sPc_REUSE_R1].Sbyte//×Ô¶¨Òå´«¸ÐÆ÷ÇúÏß	¸´ÓÃ2
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
/*-155-*/#define uFsCtl_CONTROL_CONFIRM       FLASHDATABASE[sCtl_CONTROL_CONFIRM].Sbyte//RS485Ò£¿Ø
/*-156-*/#define uFsCtl_CONTROL_COMMAND       FLASHDATABASE[sCtl_CONTROL_COMMAND].Sbyte//RS485Ò£¿ØÃüÁî      
/*-157-*/#define DES_CUSTOM_SENSOR_REUSE_V6   FLASHDATABASE[sPc_REUSE_V6].Sbyte
/*-158-*/#define DES_CUSTOM_SENSOR_REUSE_V7   FLASHDATABASE[sPc_REUSE_V7].Sbyte
/*-159-*/#define DES_CUSTOM_SENSOR_REUSE_V8   FLASHDATABASE[sPc_REUSE_V8].Sbyte






///±£´æÊµÊ±²âÁ¿²ÎÊýÄÚ´æ///
  #define MSAVE_EPROMSTARTNUM    FLASHDATABASE[GensRunMSaveCtr+0].ByteInt//±£´æÆð¶¯´ÎÊý
  #define MSAVE_RUNNINGHOUR      FLASHDATABASE[GensRunMSaveCtr+1].ByteInt//±£´æÔËÐÐÀÛÊ±
  #define MSAVE_RUNNINGMINUTE    FLASHDATABASE[GensRunMSaveCtr+2].Sbyte  //±£´æÔËÐÐÀÛ·Ö
  #define MSAVE_RUNNINGSEC       FLASHDATABASE[GensRunMSaveCtr+3].Sbyte  //±£´æÔËÐÐÃë 
  #define MSAVE_KWHH             FLASHDATABASE[GensRunMSaveCtr+4].ByteInt//±£´æÇ§ÍßÊ±¸ßÎ»
  #define MSAVE_KWHL             FLASHDATABASE[GensRunMSaveCtr+5].ByteInt//±£´æÇ§ÍßÊ±µÍÎ»


/* ******************************************************************** */
/*                      Measurement Definitions                         */
/* ******************************************************************** */

const typedef enum   //²ÎÊýÉèÖÃ×Ó²Ëµ¥Ã¶¾ÙÀàÐÍ sRn--> sRAMMeasnum
{
 /*-00-*/ sRn_VOLTAGEAB2    =0,//ÊÐµçABÏßµçÑ¹
 /*-01-*/ sRn_VOLTAGEBC2      ,//ÊÐµçBCÏßµçÑ¹
 /*-02-*/ sRn_VOLTAGECA2      ,//ÊÐµçCAÏßµçÑ¹ 
 /*-03-*/ sRn_VOLTAGEA2       ,//ÊÐµçAÏàµçÑ¹
 /*-04-*/ sRn_VOLTAGEB2       ,//ÊÐµçBÏàµçÑ¹
 /*-05-*/ sRn_VOLTAGEC2       ,//ÊÐµçCÏàµçÑ¹
 /*-06-*/ sRn_VOLTAGEAB1      ,//ÓÍ»úABÏßµçÑ¹
 /*-07-*/ sRn_VOLTAGEBC1      ,//ÓÍ»úBCÏßµçÑ¹
 /*-08-*/ sRn_VOLTAGECA1      ,//ÓÍ»úCAÏßµçÑ¹ 
 /*-09-*/ sRn_VOLTAGEA1       ,//ÓÍ»úAÏàµçÑ¹
 /*-10-*/ sRn_VOLTAGEB1       ,//ÓÍ»úBÏàµçÑ¹
 /*-11-*/ sRn_VOLTAGEC1       ,//ÓÍ»úCÏàµçÑ¹
 /*-12-*/ sRn_CURRENTA        ,//ÓÍ»úAÏàµçÁ÷
 /*-13-*/ sRn_CURRENTB        ,//ÓÍ»úBÏàµçÁ÷
 /*-14-*/ sRn_CURRENTC        ,//ÓÍ»úCÏàµçÁ÷
 /*-15-*/ sRn_PhaseCOS        ,//COS
 /*-16-*/ sRn_BUS_FREQ        ,//ÊÐµçÆµÂÊ
 /*-17-*/ sRn_GEN_FREQ        ,//·¢µç»úÆµÂÊ
 /*-18-*/ sRn_KWALL           ,//ÓÍ»ú×ÜÓÐ¹¦¹¦ÂÊ
 /*-19-*/ sRn_KVAALL          ,//ÓÍ»ú×ÜÊÓÔÚ¹¦ÂÊ
 /*-20-*/ sRn_KVARALL         ,//ÓÍ»ú×ÜÎÞ¹¦¹¦ÂÊ
 /*-21-*/ sRn_KWA             ,//ÓÍ»úAÏàÓÐ¹¦¹¦ÂÊ
 /*-22-*/ sRn_KWB             ,//ÓÍ»úBÏàÓÐ¹¦¹¦ÂÊ
 /*-23-*/ sRn_KWC             ,//ÓÍ»úCÏàÓÐ¹¦¹¦ÂÊ 
 /*-24-*/ sRn_KVARA           ,//ÓÍ»úAÏàÎÞ¹¦¹¦ÂÊ
 /*-25-*/ sRn_KVARB           ,//ÓÍ»úBÏàÎÞ¹¦¹¦ÂÊ
 /*-26-*/ sRn_KVARC           ,//ÓÍ»úCÏàÎÞ¹¦¹¦ÂÊ 
 /*-27-*/ sRn_KVAA            ,//ÓÍ»úAÏàÊÓÔÚ¹¦ÂÊ
 /*-28-*/ sRn_KVAB            ,//ÓÍ»úBÏàÊÓÔÚ¹¦ÂÊ
 /*-29-*/ sRn_KVAC            ,//ÓÍ»úCÏàÊÓÔÚ¹¦ÂÊ
 /*-30-*/ sRn_PFA             ,//AÏà¹¦ÂÊÒòÊý
 /*-31-*/ sRn_PFB             ,//BÏà¹¦ÂÊÒòÊý
 /*-32-*/ sRn_PFC             ,//CÏà¹¦ÂÊÒòÊý 
 /*-33-*/ sRn_WATERTEMP       ,//Ë®ÎÂ
 /*-34-*/ sRn_FUEL            ,//ÓÍÎ»
 /*-35-*/ sRn_OILPRESSURE     ,//ÓÍÑ¹ 
 /*-36-*/ sRn_REUSEOILTEMPL   ,//ÓÍÎÂ ¸´ÓÃ      
 /*-37-*/ sRn_PowerVoltage    ,//µç³ØµçÑ¹
 /*-38-*/ sRn_ChargerVoltage  ,//³äµç»úµçÑ¹
 /*-39-*/ sRn_DES_SPEED       , //ÓÍ»ú¿ØÖÆ×ªËÙ                        
 /*-40-*/ sRn_DES_DISPSPEED   , //ÓÍ»úÏÔÊ¾×ªËÙ                            
 /*-41-*/ sRn_NO_Use2         ,                            
 /*-42-*/ sRn_NO_Use3         ,                         
 /*-43-*/ sRn_NO_Use4         ,                         
 /*-44-*/ sRn_NO_Use5         ,                         
 /*-45-*/ sRn_NO_Use6         ,                         
 /*-46-*/ sRn_NO_Use7         ,                         
 /*-47-*/ sRn_DES_ALA_DATA1   ,//²ñÓÍ»ú±¨¾¯                        
 /*-48-*/ sRn_DES_ALA_DATA2   ,//²ñÓÍ»ú±¨¾¯2                        
 /*-49-*/ sRn_GEN_ALA_DATA1   ,//·¢µç»ú±¨¾¯                        
 /*-50-*/ sRn_MAIN_ALA_DATA1  ,//Íøµç±¨¾¯                        
 /*-51-*/ sRn_LIGHTSTATUS     ,//LEDµÆÊý¾Ý                        
 /*-52-*/ sRn_COMMON_STATUS   ,//Í¨ÓÃ×´Ì¬1                        
 /*-53-*/ sRn_COMMON_STATUS2  ,//Í¨ÓÃ×´Ì¬2                        
 /*-54-*/ sRn_COMMON_STATUS3  ,//Í¨ÓÃ×´Ì¬3                        
 /*-55-*/ sRn_INPUTVALUE      ,//¿ª¹ØÁ¿ÊäÈë                        
 /*-56-*/ sRn_OUTPUTVALUE     ,//¿ª¹ØÁ¿Êä³ö                        
 /*-57-*/ sRn_VALUER0         ,//µç×è0                        
 /*-58-*/ sRn_VALUER1         ,//µç×è1                        
 /*-59-*/ sRn_VALUER2         ,//µç×è2                        
 /*-60-*/ sRn_VALUER3         ,//µç×è3                        
 /*-61-*/ sRn_VALUER4         ,//µç×è4                        
 /*-62-*/ sRn_BTNVALUE        ,//°´Å¥                        
 /*-63-*/ sRn_EPROM_STARTNUMHH,//Æð¶¯´ÎÊý EPROM_STARTNUM *9999                        
 /*-64-*/ sRn_EPROM_STARTNUM  ,  //Æð¶¯´ÎÊýµÍ16Î»  
 /*-65-*/ sRn_KWHL            ,  //Ç§ÍßÊ±                                       
 /*-66-*/ sRn_KWHH            ,  //Ç§ÍßÊ±       //µÍÎ»
 /*-67-*/ sRn_KVARHL          ,  //Ç§·¦Ê±µÍÎ»        
 /*-68-*/ sRn_KVARHH          ,  //Ç§·¦Ê±¸ßÎ»
 /*-69-*/ sRn_RUNNINGHOURHH   ,  //ÔËÐÐÀÛÊ±¸ß×Ö½Ú RUNNINGHOURHH*9999 
 /*-70-*/ sRn_RUNNINGHOUR     ,  //ÔËÐÐÀÛÊ±
 /*-71-*/ sRn_RUNNINGMINUTE   ,  //ÔËÐÐÀÛ·Ö
 /*-72-*/ sRn_RUNNINGSEC      ,  //ÔËÐÐÃë 
							 
} sRAMMeasHeadnum;

/* ******************************************************************** */
/*                        Measurement Definitions                       */
/* ******************************************************************** */
/*-00-*/#define VOLTAGEAB2       RAMDATABASE[sRn_VOLTAGEAB2      ].Sbyte  //ÊÐµçABÏßµçÑ¹
/*-01-*/#define VOLTAGEBC2       RAMDATABASE[sRn_VOLTAGEBC2      ].Sbyte  //ÊÐµçBCÏßµçÑ¹
/*-02-*/#define VOLTAGECA2       RAMDATABASE[sRn_VOLTAGECA2      ].Sbyte  //ÊÐµçCAÏßµçÑ¹ 
/*-03-*/#define VOLTAGEA2        RAMDATABASE[sRn_VOLTAGEA2       ].Sbyte  //ÊÐµçAÏàµçÑ¹
/*-04-*/#define VOLTAGEB2        RAMDATABASE[sRn_VOLTAGEB2       ].Sbyte  //ÊÐµçBÏàµçÑ¹
/*-05-*/#define VOLTAGEC2        RAMDATABASE[sRn_VOLTAGEC2       ].Sbyte  //ÊÐµçCÏàµçÑ¹
/*-06-*/#define VOLTAGEAB1       RAMDATABASE[sRn_VOLTAGEAB1      ].Sbyte  //ÓÍ»úABÏßµçÑ¹
/*-07-*/#define VOLTAGEBC1       RAMDATABASE[sRn_VOLTAGEBC1      ].Sbyte  //ÓÍ»úBCÏßµçÑ¹
/*-08-*/#define VOLTAGECA1       RAMDATABASE[sRn_VOLTAGECA1      ].Sbyte  //ÓÍ»úCAÏßµçÑ¹ 
/*-09-*/#define VOLTAGEA1        RAMDATABASE[sRn_VOLTAGEA1       ].Sbyte  //ÓÍ»úAÏàµçÑ¹
/*-10-*/#define VOLTAGEB1        RAMDATABASE[sRn_VOLTAGEB1       ].Sbyte  //ÓÍ»úBÏàµçÑ¹
/*-11-*/#define VOLTAGEC1        RAMDATABASE[sRn_VOLTAGEC1       ].Sbyte  //ÓÍ»úCÏàµçÑ¹
/*-12-*/#define CURRENTA         RAMDATABASE[sRn_CURRENTA        ].ByteInt//ÓÍ»úAÏàµçÁ÷
/*-13-*/#define CURRENTB         RAMDATABASE[sRn_CURRENTB        ].ByteInt//ÓÍ»úBÏàµçÁ÷
/*-14-*/#define CURRENTC         RAMDATABASE[sRn_CURRENTC        ].ByteInt//ÓÍ»úCÏàµçÁ÷
/*-15-*/#define PhaseCOS         RAMDATABASE[sRn_PhaseCOS        ].Sbyte  //COS
/*-16-*/#define BUS_FREQ         RAMDATABASE[sRn_BUS_FREQ        ].Sbyte  //ÊÐµçÆµÂÊ
/*-17-*/#define GEN_FREQ         RAMDATABASE[sRn_GEN_FREQ        ].Sbyte  //·¢µç»úÆµÂÊ
/*-18-*/#define KWALL            RAMDATABASE[sRn_KWALL           ].Sbyte  //ÓÍ»ú×ÜÓÐ¹¦¹¦ÂÊ
/*-19-*/#define KVAALL           RAMDATABASE[sRn_KVAALL          ].Sbyte  //ÓÍ»ú×ÜÊÓÔÚ¹¦ÂÊ
/*-20-*/#define KVARALL          RAMDATABASE[sRn_KVARALL         ].Sbyte  //ÓÍ»ú×ÜÎÞ¹¦¹¦ÂÊ
/*-21-*/#define KWA              RAMDATABASE[sRn_KWA             ].Sbyte  //ÓÍ»úAÏàÓÐ¹¦¹¦ÂÊ
/*-22-*/#define KWB              RAMDATABASE[sRn_KWB             ].Sbyte  //ÓÍ»úBÏàÓÐ¹¦¹¦ÂÊ
/*-23-*/#define KWC              RAMDATABASE[sRn_KWC             ].Sbyte  //ÓÍ»úCÏàÓÐ¹¦¹¦ÂÊ 
/*-24-*/#define KVARA            RAMDATABASE[sRn_KVARA           ].Sbyte  //ÓÍ»úAÏàÎÞ¹¦¹¦ÂÊ
/*-25-*/#define KVARB            RAMDATABASE[sRn_KVARB           ].Sbyte  //ÓÍ»úBÏàÎÞ¹¦¹¦ÂÊ
/*-26-*/#define KVARC            RAMDATABASE[sRn_KVARC           ].Sbyte  //ÓÍ»úCÏàÎÞ¹¦¹¦ÂÊ 
/*-27-*/#define KVAA             RAMDATABASE[sRn_KVAA            ].Sbyte  //ÓÍ»úAÏàÊÓÔÚ¹¦ÂÊ
/*-28-*/#define KVAB             RAMDATABASE[sRn_KVAB            ].Sbyte  //ÓÍ»úBÏàÊÓÔÚ¹¦ÂÊ
/*-29-*/#define KVAC             RAMDATABASE[sRn_KVAC            ].Sbyte  //ÓÍ»úCÏàÊÓÔÚ¹¦ÂÊ
/*-30-*/#define PFA              RAMDATABASE[sRn_PFA             ].Sbyte  //AÏà¹¦ÂÊÒòÊý
/*-31-*/#define PFB              RAMDATABASE[sRn_PFB             ].Sbyte  //BÏà¹¦ÂÊÒòÊý
/*-32-*/#define PFC              RAMDATABASE[sRn_PFC             ].Sbyte  //CÏà¹¦ÂÊÒòÊý 
/*-33-*/#define WATERTEMP        RAMDATABASE[sRn_WATERTEMP       ].Sbyte  //Ë®ÎÂ
/*-34-*/#define FUEL             RAMDATABASE[sRn_FUEL            ].Sbyte  //ÓÍÎ»
/*-35-*/#define OILPRESSURE      RAMDATABASE[sRn_OILPRESSURE     ].Sbyte  //ÓÍÑ¹ 
/*-36-*/#define REUSEOILTEMPL    RAMDATABASE[sRn_REUSEOILTEMPL   ].Sbyte  //¸´ÓÃÎÂ¶ÈÑ¹Á¦ÒºÎ»       
/*-37-*/#define PowerVoltage     RAMDATABASE[sRn_PowerVoltage    ].Sbyte  //µç³ØµçÑ¹
/*-38-*/#define ChargerVoltage   RAMDATABASE[sRn_ChargerVoltage  ].Sbyte  //³äµç»úµçÑ¹
/*-39-*/#define DES_SPEED        RAMDATABASE[sRn_DES_SPEED       ].Sbyte  //ÓÍ»ú×ªËÙ
/*-40-*/#define DES_DISPSPEED    RAMDATABASE[sRn_DES_DISPSPEED   ].Sbyte //ÏÔÊ¾×ªËÙ
/*-41-*/#define NO_Use2          RAMDATABASE[sRn_NO_Use2         ].Sbyte    
/*-42-*/#define NO_Use3          RAMDATABASE[sRn_NO_Use3         ].Sbyte 
/*-43-*/#define NO_Use4          RAMDATABASE[sRn_NO_Use4         ].Sbyte 
/*-44-*/#define NO_Use5          RAMDATABASE[sRn_NO_Use5         ].Sbyte 
/*-45-*/#define NO_Use6          RAMDATABASE[sRn_NO_Use6         ].Sbyte 
/*-46-*/#define NO_Use7          RAMDATABASE[sRn_NO_Use7         ].Sbyte 
/*-47-*/#define DES_ALA_DATA1    RAMDATABASE[sRn_DES_ALA_DATA1   ].Sbyte  //²ñÓÍ»ú±¨¾¯
/*-48-*/#define DES_ALA_DATA2    RAMDATABASE[sRn_DES_ALA_DATA2   ].Sbyte  //²ñÓÍ»ú±¨¾¯2
/*-49-*/#define GEN_ALA_DATA2    RAMDATABASE[sRn_GEN_ALA_DATA1   ].Sbyte  //·¢µç»ú±¨¾¯
/*-50-*/#define MAIN_ALA_DATA1   RAMDATABASE[sRn_MAIN_ALA_DATA1  ].Sbyte  //Íøµç±¨¾¯
/*-51-*/#define LIGHTSTATUS      RAMDATABASE[sRn_LIGHTSTATUS     ].Sbyte  //LEDµÆÊý¾Ý
/*-52-*/#define COMMON_STATUS    RAMDATABASE[sRn_COMMON_STATUS   ].Sbyte  //Í¨ÓÃ×´Ì¬1
/*-53-*/#define COMMON_STATUS2   RAMDATABASE[sRn_COMMON_STATUS2  ].Sbyte  //Í¨ÓÃ×´Ì¬2
/*-54-*/#define COMMON_STATUS3   RAMDATABASE[sRn_COMMON_STATUS3  ].Sbyte  //Í¨ÓÃ×´Ì¬3
/*-55-*/#define INPUTVALUE       RAMDATABASE[sRn_INPUTVALUE      ].Sbyte  //¿ª¹ØÁ¿ÊäÈë
/*-56-*/#define OUTPUTVALUE      RAMDATABASE[sRn_OUTPUTVALUE     ].Sbyte  //¿ª¹ØÁ¿Êä³ö
/*-57-*/#define VALUER0          RAMDATABASE[sRn_VALUER0         ].Sbyte  //µç×è0Ñ¹Á¦
/*-58-*/#define VALUER1          RAMDATABASE[sRn_VALUER1         ].Sbyte  //µç×è1ÎÂ¶È
/*-59-*/#define VALUER2          RAMDATABASE[sRn_VALUER2         ].Sbyte  //µç×è2¸´ÓÃ1Ä¬ÈÏÒºÎ»
/*-60-*/#define VALUER3          RAMDATABASE[sRn_VALUER3         ].Sbyte  //µç×è3¸´ÓÃ2Ä¬ÈÏ¿ª¹ØÁ¿3
/*-61-*/#define VALUER4          RAMDATABASE[sRn_VALUER4         ].Sbyte  //µç×è4
/*-62-*/#define BTNVALUE         RAMDATABASE[sRn_BTNVALUE        ].Sbyte  //°´Å¥
/*-63-*/#define EPROM_STARTNUMHH RAMDATABASE[sRn_EPROM_STARTNUMHH].ByteInt //Æð¶¯´ÎÊý EPROM_STARTNUM *9999
/*-64-*/#define EPROM_STARTNUM   RAMDATABASE[sRn_EPROM_STARTNUM  ].ByteInt//Æð¶¯´ÎÊý
/*-65-*/#define KWHH             RAMDATABASE[sRn_KWHH            ].ByteInt//Ç§ÍßÊ±¸ßÎ»
/*-66-*/#define KWHL             RAMDATABASE[sRn_KWHL            ].ByteInt//Ç§ÍßÊ±µÍÎ»          
/*-67-*/#define KVARHH           RAMDATABASE[sRn_KVARHH          ].Sbyte  //Ç§·¦Ê±¸ßÎ»
/*-68-*/#define KVARHL           RAMDATABASE[sRn_KVARHL          ].Sbyte  //Ç§·¦Ê±µÍÎ» 
/*-69-*/#define RUNNINGHOURHH    RAMDATABASE[sRn_RUNNINGHOURHH   ].ByteInt //ÔËÐÐÀÛÊ±¸ß×Ö½Ú RUNNINGHOURHH*9999 
/*-70-*/#define RUNNINGHOUR      RAMDATABASE[sRn_RUNNINGHOUR     ].ByteInt//ÔËÐÐÀÛÊ±
/*-71-*/#define RUNNINGMINUTE    RAMDATABASE[sRn_RUNNINGMINUTE   ].Sbyte  //ÔËÐÐÀÛ·Ö
/*-72-*/#define RUNNINGSEC       RAMDATABASE[sRn_RUNNINGSEC      ].Sbyte  //ÔËÐÐÃë 


        #define sReadParameterErr   RAMDATABASE[GensDateErrSta +0  ].Sbyte//¶ÁÈ¡²ÎÊý´íÎó
				#define sReadAdjParmErr     RAMDATABASE[GensDateErrSta +1  ].Sbyte//¶ÁÈ¡Ð£Ñé²ÎÊý´íÎó
				#define sReadCurveParmErr   RAMDATABASE[GensDateErrSta +2  ].Sbyte//¶ÁÈ¡ÇúÏß²ÎÊý´íÎó
				#define sReadLanguageErr    RAMDATABASE[GensDateErrSta +3  ].Sbyte//¶ÁÈ¡ÓïÑÔ²ÎÊý´íÎó




/* ******************************************************************** */
/*                          BIT Definitions                             */
/* ******************************************************************** */

//¼ü´¦Àí±êÖ¾
#define F_ENTER_UP           RAMDATABASE[sRn_BTNVALUE].BITS.BIT8//ÉÏ·­Ò³
#define F_ENTER_DOWN         RAMDATABASE[sRn_BTNVALUE].BITS.BIT9//ÏÂ·­Ò³
#define F_ENTER_START        RAMDATABASE[sRn_BTNVALUE].BITS.BITA//Æð¶¯
#define F_ENTER_STOP_LCD     RAMDATABASE[sRn_BTNVALUE].BITS.BITB//Í£»ú_LCDÓÃ
#define F_ENTER_TEST         RAMDATABASE[sRn_BTNVALUE].BITS.BITC//²âÊÔ
#define F_ENTER_MANUAL       RAMDATABASE[sRn_BTNVALUE].BITS.BITD//ÊÖ¶¯
#define F_ENTER_AUTO         RAMDATABASE[sRn_BTNVALUE].BITS.BITE//×Ô¶¯
#define F_ENTER_SETUP        RAMDATABASE[sRn_BTNVALUE].BITS.BITF//ÉèÖÃ
#define F_ENTER_STOP_CAL     RAMDATABASE[sRn_BTNVALUE].BITS.BIT0//Í£»ú_CALÓÃ
#define F_ENTER_ENTER		     RAMDATABASE[sRn_BTNVALUE].BITS.BIT1//È·¶¨°´¼ü
#define F_ENTER_MAINCLOSE    RAMDATABASE[sRn_BTNVALUE].BITS.BIT2//ÊÐµçºÏÕ¢
#define F_ENTER_GENSCLOSE    RAMDATABASE[sRn_BTNVALUE].BITS.BIT3//·¢µçºÏÕ¢

//LEDµÆ±êÊ¶
#define F_SHOW_LED_STOP      RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT8//Í£»úµÆ
#define F_SHOW_LED_MANUAL    RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT9//ÊÖ¶¯µÆ
#define F_SHOW_LED_AUTO      RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITA//×Ô¶¯µÆ
#define F_SHOW_LED_TEST      RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITB//²âÊÔµÆ
#define F_SHOW_LED_GENSET    RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITC//·¢µç»ú×éÕý³£µÆ
#define F_SHOW_LED_GCB       RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITD//»ú×éºÏÕ¢µÆ
#define F_SHOW_LED_MCB       RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITE//ÊÐµçºÏÕ¢µÆ      
#define F_SHOW_LED_MAINS     RAMDATABASE[sRn_LIGHTSTATUS].BITS.BITF//ÊÐµçÕý³£µÆ
#define F_SHOW_LED_ALARM     RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT0//×ÛºÏ±¨¾¯µÆ
#define F_FLICKER_LED_GENSET RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT1//»ú×éÕý³£µÆÉÁ±êÖ¾ 
#define F_FLICKER_LED_MAINS  RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT2//ÊÐµçÕý³£µÆÉÁ±êÖ¾
#define F_FLICKER_LED_ALARM  RAMDATABASE[sRn_LIGHTSTATUS].BITS.BIT3//×ÛºÏ±¨¾¯µÆÉÁ±êÖ¾

//ÊäÈë
#define F_AUX_INPUT1         RAMDATABASE[sRn_INPUTVALUE].BITS.BIT8//×Ô¶¨ÒåÊäÈë1-8×´Ì¬
#define F_AUX_INPUT2         RAMDATABASE[sRn_INPUTVALUE].BITS.BIT9
#define F_AUX_INPUT3         RAMDATABASE[sRn_INPUTVALUE].BITS.BITA
#define F_AUX_INPUT4         RAMDATABASE[sRn_INPUTVALUE].BITS.BITB
#define F_AUX_INPUT5         RAMDATABASE[sRn_INPUTVALUE].BITS.BITC
#define F_AUX_INPUT6         RAMDATABASE[sRn_INPUTVALUE].BITS.BITD
#define F_AUX_INPUT7         RAMDATABASE[sRn_INPUTVALUE].BITS.BITE
#define F_AUX_INPUT8         RAMDATABASE[sRn_INPUTVALUE].BITS.BITF
#define F_INPUT_EMSTOP       RAMDATABASE[sRn_INPUTVALUE].BITS.BIT0//¼±Í£   
//Êä³ö
#define F_OUTPUT_DCHAR       RAMDATABASE[sRn_OUTPUTVALUE].BITS.BIT8//D+Êä³ö
#define F_OUTPUT_CRANK       RAMDATABASE[sRn_OUTPUTVALUE].BITS.BIT9//Æð¶¯Êä³ö
#define F_AUX_OUTPUT1        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITA//×Ô¶¨ÒåÊä³ö1-6×´Ì¬
#define F_AUX_OUTPUT2        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITB
#define F_AUX_OUTPUT3        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITC
#define F_AUX_OUTPUT4        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITD
#define F_AUX_OUTPUT5        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITE
#define F_AUX_OUTPUT6        RAMDATABASE[sRn_OUTPUTVALUE].BITS.BITF

//·¢¶¯»ú±¨¾¯
#define F_WARN_SPEEDLOST     RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT8//ËÙ¶È¶ªÊ§¾¯±¨
#define F_STOP_STOP_FAIL     RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT9//Í£»úÊ§°Ü¾¯±¨
#define F_WARN_FUEL_LO       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITA//È¼ÓÍÎ»µÍ¾¯±¨
#define F_WARN_CHARGE_LO     RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITB//³äµçÊ§°Ü¾¯±¨
#define F_WARN_BATT_LO       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITC//µç³ØµçÑ¹µÍ¾¯±¨
#define F_WARN_BATT_HI       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITD//µç³ØµçÑ¹¸ß¾¯±¨
#define F_WARN_WATER_LO      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITE//Ë®Î»µÍ¾¯±¨
#define F_WARN_TEMP_HI       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BITF//ÎÂ¶È¸ß¾¯±¨
#define F_WARN_OP_LO         RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT0//ÓÍÑ¹µÍ¾¯±¨
#define F_WARN_MAINTAIN      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT1//Î¬»¤¾¯±¨
#define F_STOP_EM            RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT2//½ô¼±Í£»ú±¨¾¯
#define F_STOP_TEMP_HI       RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT3//ÎÂ¶È¸ßÍ£»ú±¨¾¯
#define F_STOP_OP_LO         RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT4//ÓÍÑ¹µÍÍ£»ú±¨¾¯
#define F_STOP_SPEED_HI      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT5//³¬ËÙÍ£»ú±¨¾¯
#define F_STOP_SPEED_LO      RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT6//Ç·ËÙÍ£»ú±¨¾¯
#define F_STOP_SPEED_LOST    RAMDATABASE[sRn_DES_ALA_DATA1].BITS.BIT7//ËÙ¶È¶ªÊ§±¨¾¯

#define F_STOP_START_FAIL    RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT8//Æð¶¯Ê§°Ü±¨¾¯
#define F_STOP_FUEL_LO       RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT9//È¼ÓÍÎ»µÍÍ£»ú±¨¾¯
#define F_STOP_WATER_LO      RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITA//Ë®Î»µÍÍ£»ú±¨¾¯
#define F_STOP_TEMP_LOST     RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITB//ÎÂ¶È´«¸ÐÆ÷¶ÏÏßÍ£»ú±¨¾¯
#define F_STOP_OP_LOST       RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITC//ÓÍÑ¹´«¸ÐÆ÷¶ÏÏßÍ£»ú±¨¾¯
#define F_STOP_MAINTAIN      RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITD//Î¬»¤Í£»ú±¨¾¯
#define F_WARN_EXTERN        RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITE//Íâ²¿¸æ¾¯
#define F_STOP_EXTERN        RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BITF//Íâ²¿Í£»ú¸æ¾¯
#define F_WARN_TEMP_LOST     RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT0//ÎÂ¶È´«¸ÐÆ÷¶ÏÏß¾¯¸æ¯
#define F_WARN_OP_LOST       RAMDATABASE[sRn_DES_ALA_DATA2].BITS.BIT1//ÓÍÑ¹´«¸ÐÆ÷¶ÏÏß¾¯¸æ


//·¢µç»ú±¨¾¯
#define F_WARN_CURRENT_HI    RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BIT8//·¢µç»ú¹ýÁ÷¾¯¸æ
#define F_STOP_VOLT_HI       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BIT9//·¢µç»ú¹ýÑ¹Í£»ú±¨¾¯
#define F_STOP_VOLT_LO       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITA//·¢µç»úÇ·Ñ¹Í£»ú±¨¾¯
#define F_STOP_CURRENT_HI    RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITB//·¢µç»ú¹ýÁ÷Í£»ú±¨¾¯
#define F_STOP_FREQ_HI       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITC//·¢µç»úÆµÂÊ¸ßÍ£»ú±¨¾¯
#define F_STOP_FREQ_LO       RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITD//·¢µç»úÆµÂÊµÍÍ£»ú±¨¾¯
#define F_STOP_NOFREQ        RAMDATABASE[sRn_GEN_ALA_DATA1].BITS.BITE//·¢µç»úÎÞ·¢µçÍ£»ú±¨¾¯

//Íøµç±¨¾¯
#define F_MAINS_VOLT_HI      RAMDATABASE[sRn_MAIN_ALA_DATA1].BITS.BIT8//ÊÐµçµçÑ¹¸ß
#define F_MAINS_VOLT_LO      RAMDATABASE[sRn_MAIN_ALA_DATA1].BITS.BIT9//ÊÐµçµçÑ¹µÍ


//×´Ì¬Î»

#define F_STA_FUELOUTPUT          RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT8//¹©ÓÍ
#define F_STA_PRESTART            RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT9//Ô¤ÈÈ×´Ì¬
#define F_STA_CRANK               RAMDATABASE[sRn_COMMON_STATUS].BITS.BITA//Æð¶¯×´Ì¬
#define F_STA_WAITLOAD            RAMDATABASE[sRn_COMMON_STATUS].BITS.BITB//»ú×éµÈ´ý´øÔØ
#define F_STA_IDLE                RAMDATABASE[sRn_COMMON_STATUS].BITS.BITC//Æð¶¯µ¡ËÙ×´Ì¬
#define F_STA_WARM                RAMDATABASE[sRn_COMMON_STATUS].BITS.BITD//Å¯»ú×´Ì¬
#define F_STA_DES_RUN             RAMDATABASE[sRn_COMMON_STATUS].BITS.BITE//·¢¶¯»úÔËÐÐ×´Ì¬
#define F_STA_STARTDEL            RAMDATABASE[sRn_COMMON_STATUS].BITS.BITF//Æð¶¯ÑÓÊ±×´Ì¬
#define F_STA_STOPDEL             RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT0//Í£»úÑÓÊ±×´Ì¬
#define F_STA_COOL                RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT1//Í£»úÉ¢ÈÈ×´Ì¬
#define F_STA_STOP_IDLE           RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT2//Í£»úµ¡ËÙ×´Ì¬
#define F_STA_STOP_CHECK          RAMDATABASE[sRn_COMMON_STATUS].BITS.BIT3//Í£»ú¼ì²â×´Ì¬

#define F_STA_STOP_FAIL           RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT8//Í£»úÊ§°Ü×´Ì¬
#define F_STA_WARN                RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT9//¾¯¸æ×´Ì¬
#define F_STA_STOPALARM           RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITA//±¨¾¯Í£»ú×´Ì¬
#define F_STA_TIMER_SAFE          RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITB//°²È«ÑÓÊ±×´Ì¬
#define F_STA_MANMODE             RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITC //ÊÖ¶¯Ä£Ê½
#define F_STA_AUTOMODE            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITD //×Ô¶¯Ä£Ê½
#define F_STA_TESTMODE            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITE //²âÊÔÄ£Ê½
#define F_STA_STOPMODE            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BITF //Í£»úÄ£Ê½
#define F_STA_START_RETRY         RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT0 //Æð¶¯¼ä¸ô
#define F_STA_MAINS_NORMAL_CHECK  RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT1 //ÊÐµçÕý³£¼ì²â
#define F_STA_MAINS_FAIL_CHECK    RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT2 //ÊÐµçÒì³£¼ì²â
#define F_STA_STOPOUTPUT          RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT3//µÃµçÍ£»úÑÓÊ±×´Ì¬
#define F_STA_AMFSTART            RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT4//Ê§µç×ÔÆô¶¯ÑÓÊ±
#define F_STA_AMFSTOP             RAMDATABASE[sRn_COMMON_STATUS2].BITS.BIT5//µÃµç×ÔÍ£»úÑÓÊ±

#define F_STA_STOP                RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT8//Í£»ú×´Ì¬
#define F_STA_START_SUCC          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT9//Æð¶¯³É¹¦×´Ì¬
#define F_STA_GEN_RUN             RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITA//·¢µç»úÔËÐÐ×´Ì¬
#define F_STA_GEN_SUPP            RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITB//·¢µç»ú×é¹©µç×´Ì¬
#define F_STA_GEN_STOP            RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITC//·¢µç»ú×éÍ£Ö¹×´Ì¬
#define F_STA_MAINS_FAIL          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITD//ÊÐµçÍ£Ö¹×´Ì¬
#define F_STA_MAINS_RUN           RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITE//ÊÐµçÔËÐÐ×´Ì¬
#define F_STA_MAINS_SUPP          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BITF//ÊÐµç¹©µç×´Ì¬
#define F_STA_TRANSCB             RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT0//¿ª¹Ø×ª»»×´Ì¬
#define F_DI_TEMPHI_STOP          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT1//¿ª¹ØÁ¿ÎÂ¶È¸ß±¨¾¯Í£»ú
#define F_DI_OILP_STOP            RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT2//¿ª¹ØÁ¿ÓÍÑ¹µÍ±¨¾¯Í£»ú
#define F_DI_FUELLOW_WRN          RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT3//¿ª¹ØÁ¿ÓÍÎ»µÍ¾¯¸æ
#define F_DI_WATERLOW_WRN         RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT4//¿ª¹ØÁ¿Ë®Î»µÍ¾¯¸æ
#define F_DI_FUELLOW_STOP         RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT5//¿ª¹ØÁ¿ÓÍÎ»µÍ±¨¾¯Í£»ú
#define F_DI_WATERLOW_STOP        RAMDATABASE[sRn_COMMON_STATUS3].BITS.BIT6//¿ª¹ØÁ¿Ë®Î»µÍ±¨¾¯Í£»ú
                          

/* ******************************************************************** */
/*                   AlamrRun Delay Definitions                         */
/* ******************************************************************** */

//Ô¤ÈÈÑÓÊ±
#define DELVAL_PRESTART           (INT16U)(TimerSet[TMR_DES_PREHEAT_DEL]-TimerValue[TMR_DES_PREHEAT_DEL])/10+1

//È¼ÓÍÊä³öÑÓÊ±
#define DELVAL_FUELOUTPUT         (INT16U)(TimerSet[TMR_DES_FUELOUT_DEL]-TimerValue[TMR_DES_FUELOUT_DEL])/10+1

//Æð¶¯Êä³öÑÓÊ±
#define DELVAL_CRANK              (INT16U)(TimerSet[TMR_DES_CRANK_DEL]-TimerValue[TMR_DES_CRANK_DEL])/10+1 

//°²È«ÔËÐÐÑÓÊ±
#define DELVAL_SAFE               (INT16U)(TimerSet[TMR_DES_SAFE_DEL]-TimerValue[TMR_DES_SAFE_DEL])/10+1 

//Æð¶¯µ¡ËÙÑÓÊ±
#define DELVAL_STARTIDLE          (INT16U)(TimerSet[TMR_DES_STARTIDLE_DEL]-TimerValue[TMR_DES_STARTIDLE_DEL])/10+1 

//Å¯»úÑÓÊ±
#define DELVAL_WARM               (INT16U)(TimerSet[TMR_DES_WARM_DEL]-TimerValue[TMR_DES_WARM_DEL])/10+1 

//Í£»úÉ¢ÈÈÑÓÊ±
#define DELVAL_COOLING            (INT16U)(TimerSet[TMR_DES_COOLING_DEL]-TimerValue[TMR_DES_COOLING_DEL])/10+1 

//Í£»úµ¡ËÙÑÓÊ±
#define DELVAL_STOPIDLE           (INT16U)(TimerSet[TMR_DES_STOPIDLE_DEL]-TimerValue[TMR_DES_STOPIDLE_DEL])/10+1 

//µÃµçÍ£»úÑÓÊ±
#define DELVAL_STOPOUTPUT         (INT16U)(TimerSet[TMR_DES_STOPOUTPUT_DEL]-TimerValue[TMR_DES_STOPOUTPUT_DEL])/10+1 

//µÈ´ýÍ£ÎÈ
#define DELVAL_STOPCONFIRM        (INT16U)(TimerSet[TMR_DES_STOPSUCC_DEL]-TimerValue[TMR_DES_STOPSUCC_DEL])/10+1 

//Ê§µç×ÔÆô¶¯ÑÓÊ±
#define DELVAL_AMFSTART           (INT16U)(TimerSet[TMR_DES_COOLING_DEL]-TimerValue[TMR_DES_COOLING_DEL])/10+1 

//µÃµç×ÔÍ£»úÑÓÊ±
#define DELVAL_AMFSTOP            (INT16U)(TimerSet[TMR_AMF_STOP_DEL]-TimerValue[TMR_AMF_STOP_DEL])/10+1 

//Æð¶¯¼ä¸ô
#define DELVAL_STARTINT           (INT16U)(TimerSet[TMR_DES_CRANKINT_DEL]-TimerValue[TMR_DES_CRANKINT_DEL])/10+1 

//ÊÐµçÕý³£ÑÓÊ±
#define DELVAL_MAINSNORMAL        (INT16U)(TimerSet[TMR_MAINS_NORMAL_DEL]-TimerValue[TMR_MAINS_NORMAL_DEL])/10+1 

//ÊÐµçÒì³£ÑÓÊ±
#define DELVAL_MAINSABNORMAL      (INT16U)(TimerSet[TMR_MAINS_ABNORMAL_DEL]-TimerValue[TMR_MAINS_ABNORMAL_DEL])/10+1 

//×ª»»ÑÓÊ±
#define DELVAL_TRANSCB            (INT16U)(TimerSet[TMR_MAINS_TRANS_DEL]-TimerValue[TMR_MAINS_TRANS_DEL])/10+1 

//Æð¶¯ÑÓÊ±
#define DELVAL_START              (INT16U)(TimerSet[TMR_AMF_START_DEL]-TimerValue[TMR_AMF_START_DEL])/10+1 

//Í£»úÑÓÊ±
#define DELVAL_STOP               (INT16U)(TimerSet[TMR_AMF_STOP_DEL]-TimerValue[TMR_AMF_STOP_DEL])/10+1 

//¹ýÁ÷ÑÓÊ±
#define DELVAL_OVERCURRENT        (INT16U)(TimerSet[TMR_GEN_OVERCURRENT_DEL]-TimerValue[TMR_GEN_OVERCURRENT_DEL])/10+1 
    

#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */




