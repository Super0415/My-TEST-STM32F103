//#include "ALL_Includes.h"//���������ͷ�ļ�
//#include "..\GUIinc\GUI.h"
//#include "..\uCGUIDemo\GUIDEMO.h"
#include "TYPCortex.h"


typedef unsigned char INT08U;
//typedef unsigned int INT16U;

INT16U Btn_buf;                                        //���尴������ֵ
INT08U KeyMenulevel=0;								                 //�˵�����
INT08U MainPageCon=0,MainPageConHis=0xff;              //������ʾ����������������¼
INT08U ParmMainPageCon=0,ParmMainPageConHis=0xff;      //�����������˵���������¼
INT08U ParmSubPageCon=0,ParmSubPageConHis=0xff;        //���������Ӳ˵���������¼
INT08U ParmMsgSubPageCon=0,ParmMsgSubPageConHis=0xff;  //��������Ϣ�˵���ҳ��¼
INT08U ParmLaguSubPageCon=0,ParmLaguSubPageConHis=0xff;//����������ѡ��˵���ҳ��¼
INT08U PassWordCursorMove=0,PassWordCursorMoveHis=0xff;//�����ƶ����
INT16U Password_Value=0;                               //������������
INT16U PaswordTypeToDisFlag=0;                         //���벻ͬ�����¼
INT08U MeunCon=0;
INT16U SystemParmModify=0;             //�����޸�����
INT08U SetCursorMove=0;                //�������ù��λ��
INT16U ParmSetCurDisFlag=0;            //���ò��������Ӱ
INT08U ChSpBuf,ChSpOffSet;
INT08U ChSpPosFlag;                    
INT08U ChAdjustPosFlag;                //��¼�޸Ĳ���У�������С������λ               
INT16U SpSetCursorMove;                //�����޸�������ѡ����λ��

INT08U pArmAdjPageCon=0,pArmAdjPageConHis=0xff;       //����У��ҳ�����
INT16U AdjParmModify;								  //����У���޸�
INT08U AdjSpPosFlag,AdjSetCursorMove;				  //����У����
INT08U AdjChMenuSpBuf;				                  //����У���Ƿ�Ϊ����˵�
INT16U AdjParmSetCurDisFlag=0;                        //����У�����ù����Ӱ
INT08U SpAdjSetCurMove=0,SpAdjOffSet=0;				  //����У������˵����
unsigned char AlarmflagHis=0xff;				      //�����б���ʷֵ
INT08U FirGuiDemoHis=0xff;                            //������ҳ���¼
INT08U SetCurveParmPgHis=0xff;                        //�޸���ʷ�Զ������߲�������
INT08U SetCurveConter=0;                              //�޸��Զ������߹�����
INT16U CurveParmModify1=0,CurveParmModify2=0;         //�Զ������߲����޸����ݻ���
INT16U CurveParmModifyBuf1=0,CurveParmModifyBuf2=0;   //�Զ������߲����޸����ݻ���
INT16U CurveMidfyBuf[CurveDotCtr*2];				  //�޸��Զ�������������ʱ����
INT08U CurveCtrHis=0xff;
//extern void CAN_J1939Public_Init(void);

typedef union
{
    unsigned char  Byte;
    struct
    {
        unsigned char  BIT0 : 1;
        unsigned char  BIT1 : 1;
        unsigned char  BIT2 : 1;
        unsigned char  BIT3 : 1;
        unsigned char  BIT4 : 1;
        unsigned char  BIT5 : 1;
        unsigned char  BIT6 : 1;
        unsigned char  BIT7 : 1;
    } BITS;

} GEC400LCD_STRFLG8;
 GEC400LCD_STRFLG8 LCDMapLastFlag;
 #define  LCDOctParmFlag               LCDMapLastFlag.BITS.BIT0   //????????????????
 #define  LCDBitParmFlag               LCDMapLastFlag.BITS.BIT1   //????????
 #define  LCDAdjParmFlag               LCDMapLastFlag.BITS.BIT2   //????????????
 #define  LCDAdjParmBLNoSaveFlag       LCDMapLastFlag.BITS.BIT3   //?????????????
 #define  LCDAdjParmCosNoSaveFlag      LCDMapLastFlag.BITS.BIT4   //???????????????
 
extern M_INT32S AI_OHM[AI_NUM];
extern M_INT16S PowerVoltageReal;
extern M_INT16S ChargerVoltageReal;
extern void GUI_DrawOpen(unsigned char Dtype);

INT32S REALDATA;
INT16S RECALDATA;

/*----------------------------------------------------------------------------
�������ƣ�   KeyCalRestFunAtLCD(void)
����������   ���ϸ�λ����
----------------------------------------------------------------------------*/
void KeyCalRestFunAtLCD(void) 
 {
  if(COMMON_MODEL==MODEL410)
    {
      if(KeyMenulevel==0)
      {
       if((DES_STARTSUCC_CONDITION==0)||(DES_STARTSUCC_CONDITION==3))//�Ŵ�����  �Ŵ�����+��ѹ
       {if(MainPageCon==3)  F_ENTER_STOP_CAL=1;    
       } 
       else
       { if(MainPageCon==0) F_ENTER_STOP_CAL=1;    
       }
      }
    }
   
   if(COMMON_MODEL==MODEL420) //�޸�ѡ���ͺ�Ϊ4020�������ɹ�����Ϊ 0����3�޷�ͣ������
   {
     if((KeyMenulevel==0)&&(MainPageCon==0)) F_ENTER_STOP_CAL=1; 
   }
 }
/*----------------------------------------------------------------------------
�������ƣ�   INT16S LCDTempUnitswitch(INT16U SwitchValue)
����������  ��ʾ�¶ȵ�λת��
���������   �A�Ϝض��c�z�ϜضȵēQ��Q�㹫ʽ: 
             (�A�Ϝض�-32)*5/9=�z�Ϝض� 
             �����¶�=(�����¶�*9/5)+32�� 
����������z�Ϝض�  �����¶�c ������ת��Ϊ�����¶�f ��ת����ʽΪ��f=c*9/5+32 
----------------------------------------------------------------------------*/
INT16S LCDTempUnitswitch(INT16S SwitchValue)
{
  INT16S ReturnSValue;
  if(SwitchValue!=0)
  {
   //SwitchValue=(SwitchValue+5)/10;        //ԭ������С10 ����������
   ReturnSValue= (SwitchValue*9/5+32)*10; //���㻪���¶Ȳ��Ŵ�10��
   ReturnSValue=(ReturnSValue+5)/10;      //���������ԭ
   return  ReturnSValue;                  //���صĽ���Ŵ���10��
  } 
  else  return  0;                        //�¶�Ϊ0ʱ
}
/*----------------------------------------------------------------------------
�������ƣ�   INT16S LCDPSIBarUnitswitch(INT16U SwitchValue,INT08U PressType)
����������  ��ʾѹ����λת��
���������  PressType=0   paת��kpa 
            PressType=1   PSIת�� 
            PressType=2   Barת�� 
  1����(MPa)=145��/ƽ��Ӣ��(psi)=10.2ǧ��/ƽ������ (kg/cm2)=10��(bar)=9.8����ѹ(atm)
���������  
----------------------------------------------------------------------------*/
INT16S LCDPSIBarUnitswitch(INT16U SwitchValue,INT08U PressType)
{
   float SValueBuf=0;
   INT16S ReturnSValue;
  // SValueBuf=(float)SwitchValue/10;            //��ԭ���Ŵ�����ݻ�ԭ
    switch(PressType)
    {
      case 0:         //����Paת��ΪKpa
         //  SValueBuf=SValueBuf/10;
         //  ReturnSValue=((INT16S)SValueBuf+5)/10;
         ReturnSValue=SwitchValue;
        break;
      case 1:         //����PSI
           SValueBuf=(float)SwitchValue*145;
           SValueBuf=(SValueBuf/10+5)/10;
           ReturnSValue=(INT16S)SValueBuf;
        break;
      case 2:         //����Bar
          // ReturnSValue=((INT16S)SValueBuf+5)/10;
          ReturnSValue=SwitchValue;
        break;
      default:break;  
    }
   return  ReturnSValue;                       //���صĽ���Ŵ���10�� 
}
 
//************************************************************************************
//�������ƣ�  INT08U LCDCalAllAlarmStation(INT08U ArryN)        
//����������  �������ݿ���״̬��
//���������  ���ݿ�״̬�������
//���������  ��ʾ��������λ�ú�λ״̬
//             ReturnAlmStatype
//             ReturnAlmStatBit
//************************************************************************************
#if(LCD_GEC400EN==1)

INT08U ReturnAlmStatype=0;
INT08U ReturnAlmStatBit=0; 
 
 
INT16U LCDdislogicDel()
{
  INT16U ReturnData=0;
  if(ReturnAlmStatype==5)
  {
    switch(ReturnAlmStatBit)
    {
      case 0: ReturnData=DELVAL_FUELOUTPUT;/* GUI_DispDecSpace(DELVAL_FUELOUTPUT, 3);*/  break;//ȼ�������ʱ 
      case 1: ReturnData=DELVAL_PRESTART;  /* GUI_DispDecSpace(DELVAL_PRESTART,   3);*/  break;//����Ԥ����ʱ 
      case 2: ReturnData=DELVAL_CRANK;     /* GUI_DispDecSpace(DELVAL_CRANK,      3);*/  break;//�������� 
      case 3:                              /*                                        */  break;  
      case 4: ReturnData=DELVAL_STARTIDLE; /* GUI_DispDecSpace(DELVAL_STARTIDLE,  3);*/  break;//�𶯵�����ʱ 
      case 5: ReturnData=DELVAL_WARM;      /* GUI_DispDecSpace(DELVAL_WARM,       3);*/  break;//ů����ʱ 
      case 6: ReturnData=DELVAL_SAFE;      /* GUI_DispDecSpace(DELVAL_SAFE,       3);*/  break;//��ȫ������ʱ        ��
      case 7: ReturnData=DELVAL_START;     /* GUI_DispDecSpace(DELVAL_START,      3);*/  break;//����ʱ
	  case 8 :ReturnData=DELVAL_STOP;      /* GUI_DispDecSpace(DELVAL_STOP,       3);*/  break;//ͣ����ʱ 
      case 9 :  break;
      case 10:  break;
      case 11:  break;
      case 12:ReturnData=DELVAL_TRANSCB;   /* GUI_DispDecSpace(DELVAL_TRANSCB,    3);*/  break;//����ת����ʱ 
      case 13:ReturnData=DELVAL_COOLING;   /* GUI_DispDecSpace(DELVAL_COOLING,    3);*/  break;//ͣ��ɢ����ʱ 
      case 14:ReturnData=DELVAL_STOPIDLE;  /* GUI_DispDecSpace(DELVAL_STOPIDLE,   3);*/  break;//ͣ��������ʱ 
      case 15:ReturnData=DELVAL_STOPCONFIRM;/* GUI_DispDecSpace(DELVAL_STOPCONFIRM,3);*/  break;//�ȴ�ͣ����ʱ 
              
      default:break;
    }
  } 
 if(ReturnAlmStatype==6)
  {
    switch(ReturnAlmStatBit)
    {
                                                   
      case 0: break;
      case 1: break;
      case 2: break;
      case 3: break;
      case 4: break;
      case 5: break;
      case 6: break;
      case 7: break;
	  case 8 : ReturnData=DELVAL_STARTINT;     /*GUI_DispDecSpace(DELVAL_STARTINT,     3);*/  break; //���������ʱ        ��
      case 9 : ReturnData=DELVAL_MAINSNORMAL;  /*GUI_DispDecSpace(DELVAL_MAINSNORMAL,  3);*/  break; //�е�����������ʱ        ��
      case 10: ReturnData=DELVAL_MAINSABNORMAL;/*GUI_DispDecSpace(DELVAL_MAINSABNORMAL,3);*/  break; //�е��쳣������ʱ        ��
      case 11: ReturnData=DELVAL_STOPOUTPUT;   /*GUI_DispDecSpace(DELVAL_STOPOUTPUT,   3);*/  break; //�õ�ͣ����ʱ        ��                                                       
      case 12: ReturnData=DELVAL_AMFSTART;     /*GUI_DispDecSpace(DELVAL_AMFSTART,     3);*/  break; //ʧ����������ʱ       ��
      case 13: ReturnData=DELVAL_AMFSTOP;      /*GUI_DispDecSpace(DELVAL_AMFSTOP,      3);*/  break; //�õ���ͣ����ʱ      ��
      case 14: ReturnData=DELVAL_OVERCURRENT;  /*GUI_DispDecSpace(DELVAL_OVERCURRENT,  3);*/  break; //�������ͣ����ʱ
      case 15:                                              break;
                       
      default: break;    
    }
  } 
  if(ReturnAlmStatype==7)
  {
    switch(ReturnAlmStatBit)
    {
      case 0:break; 
      case 1:break; 
      case 2:break; 
      case 3:break;
      case 4:break; 
      case 5:break; 
      case 6:break; 
      case 7:break;
                                                                    
      case 8: break;
      case 9: break;
      case 10:break;
      case 11:break;  
      case 12: break;
      case 13: break;
      case 14: break;
      case 15:break;
      default: break;    
    }
  }
  return ReturnData;
}


INT08U LCDCalAllAlarmStation(INT16U ArryDefineName,INT08U ArryN)
{
  INT08U i;
    for(i=0;i<16;i++)
    {
      if(ArryDefineName &(0x0001<<i))
      {
        ReturnAlmStatype=ArryN;
        ReturnAlmStatBit=i;
        return 1;
      } 
    } 
   return 0;
}
//************************************************************************************
//�������ƣ�  INT08U LCDDisCalAlarmAdress()       
//����������  ������ʾ����
//���������
//���������  
//************************************************************************************
INT08U LCDDisCalAlarmAdress() 
{
  if(LCDCalAllAlarmStation(GensStopAlarm1.Sbyte, 0))    return 1;      //����ͣ��1
  if(LCDCalAllAlarmStation(GensStopAlarm2.Sbyte, 1))    return 2;      //����ͣ��2
  
  if(LCDCalAllAlarmStation(GensRunStation1.Sbyte,5))    return 5;      //ͨ��״̬1
  if(LCDCalAllAlarmStation(GensRunStation2.Sbyte,6))    return 6;      //ͨ��״̬2
  if(LCDCalAllAlarmStation(GensRunStation3.Sbyte,7))    return 7;      //ͨ��״̬3
  
  if(LCDCalAllAlarmStation(GensWarningAlarm1.Sbyte,2))  return 3;      //����1
  if(LCDCalAllAlarmStation(GensWarningAlarm2.Sbyte,3))  return 4;      //����2
  
  ReturnAlmStatype=0xff;      //����ִ�е�����˵��û���κ���ʾ״̬
  return 0xff;
}
/*-----------------------------------------------------------------------
��������: void LCDCopyDBAlarmDataTOMapMemery(void)  
��������: //��DB���ݿ��и��Ʊ������ݵ�ӳ���ڴ�
�������: ˵��:���ݿ��Ѿ����ںò�����Ķ���Ϊ����lcd��ʾ��������
�������:      ����ӳ�䱨�����ݡ�
----------------------------------------------------------------------- */
void LCDCopyDBAlarmDataTOMapMemery(void)  //��DB���ݿ��и��Ʊ������ݵ�ӳ���ڴ�
{
     //����ͣ�� 47
  GensStopAlarm1.BITS.BIT0=F_STOP_EM;                                //����ͣ������          
  if(!F_DI_TEMPHI_STOP) GensStopAlarm1.BITS.BIT1=F_STOP_TEMP_HI;     //�¶ȸ߱���ͣ��        
  else                  GensStopAlarm1.BITS.BIT1=0;
  if(!F_DI_OILP_STOP)   GensStopAlarm1.BITS.BIT2=F_STOP_OP_LO;       //����ѹ����ͣ��        
  else                  GensStopAlarm1.BITS.BIT2=0;
  GensStopAlarm1.BITS.BIT3=F_STOP_SPEED_HI;                          //���糬�ٱ���ͣ��      
  GensStopAlarm1.BITS.BIT4=F_STOP_SPEED_LO;                          //����Ƿ�ٱ���ͣ��      
  GensStopAlarm1.BITS.BIT5=F_STOP_SPEED_LOST;                        //�ٶ��źŶ�ʧ����ͣ�� 
  GensStopAlarm1.BITS.BIT6=F_STOP_VOLT_HI;                           //�����ѹ����ͣ��      
  GensStopAlarm1.BITS.BIT7=F_STOP_VOLT_LO;                           //����Ƿѹ����ͣ��      
  GensStopAlarm1.BITS.BIT8=F_STOP_CURRENT_HI;                        //�����������ͣ��      
  GensStopAlarm1.BITS.BIT9=F_STOP_START_FAIL;                        //��ʧ�ܱ���ͣ��      
  GensStopAlarm1.BITS.BITA=F_STOP_FREQ_HI;                           //���糬Ƶ����ͣ��      
  GensStopAlarm1.BITS.BITB=F_STOP_FREQ_LO;                           //����ǷƵ����ͣ��      
  GensStopAlarm1.BITS.BITC=F_STOP_NOFREQ ;                           //�޷��籨��ͣ��        
  if(!F_DI_FUELLOW_STOP) GensStopAlarm1.BITS.BITD=F_STOP_FUEL_LO ;   //ȼ��λ�ͱ���ͣ��      
  else                   GensStopAlarm1.BITS.BITD=0 ;
  if(!F_DI_WATERLOW_STOP)GensStopAlarm1.BITS.BITE=F_STOP_WATER_LO;   //ˮλ�ͱ���ͣ��        
  else                   GensStopAlarm1.BITS.BITE=0;
 
 // GensStopAlarm1.BITS.BITF=;                                          15
  
      
      //����ͣ�� 48
  GensStopAlarm2.BITS.BIT0=F_DI_TEMPHI_STOP;                           //�¶ȸ߱���ͣ��   (IN)
  GensStopAlarm2.BITS.BIT1=F_DI_OILP_STOP;                             //����ѹ����ͣ��   (IN)
  GensStopAlarm2.BITS.BIT2=F_DI_FUELLOW_STOP;                          //ȼ��λ�ͱ���ͣ�� (IN) 
  GensStopAlarm2.BITS.BIT3=F_DI_WATERLOW_STOP;                         //ˮλ�ͱ���ͣ��   (IN)  
  GensStopAlarm2.BITS.BIT4=F_STOP_STOP_FAIL;                           //ͣ��ʧ�ܾ���   
  GensStopAlarm2.BITS.BIT5=F_STOP_EXTERN ;                             //�ⲿͣ����������
  GensStopAlarm2.BITS.BIT6=F_STOP_TEMP_LOST;                           //�¶ȴ���������ͣ��
  GensStopAlarm2.BITS.BIT7=F_STOP_OP_LOST;                             //ѹ������������ͣ��                     
     //���� 49
  GensWarningAlarm1.BITS.BIT0=F_WARN_SPEEDLOST;                        //�ٶ��źŶ�ʧ����  
  GensWarningAlarm1.BITS.BIT1=F_WARN_CURRENT_HI;                       //�����������      
//  GensWarningAlarm1.BITS.BIT2=;                   
  if(!F_DI_FUELLOW_WRN)GensWarningAlarm1.BITS.BIT3=F_WARN_FUEL_LO;     //ȼ��λ�;���      
  else                 GensWarningAlarm1.BITS.BIT3=0;
  GensWarningAlarm1.BITS.BIT4=F_WARN_CHARGE_LO;                        //���ʧ�ܾ���      
  GensWarningAlarm1.BITS.BIT5=F_WARN_BATT_LO;                          //���Ƿѹ����      
  GensWarningAlarm1.BITS.BIT6=F_WARN_BATT_HI;                          //��ع�ѹ����      
  GensWarningAlarm1.BITS.BIT7=F_MAINS_VOLT_LO;                         //�е�Ƿѹ����      
  GensWarningAlarm1.BITS.BIT8=F_MAINS_VOLT_HI;                         //�е��ѹ����      
  if(!F_DI_WATERLOW_WRN)GensWarningAlarm1.BITS.BIT9=F_WARN_WATER_LO;   //ˮλ�;���        
  else                  GensWarningAlarm1.BITS.BIT9=0;  
  GensWarningAlarm1.BITS.BITA=F_WARN_TEMP_HI;                          //�¶ȸ߾���        
  GensWarningAlarm1.BITS.BITB=F_WARN_OP_LO  ;                          //��ѹ�;���        
  GensWarningAlarm1.BITS.BITC=F_WARN_MAINTAIN ;                        //ά������          
  GensWarningAlarm1.BITS.BITD=F_WARN_EXTERN  ;                         //�ⲿ�澯����
  GensWarningAlarm1.BITS.BITE=F_WARN_TEMP_LOST;                        //�¶ȴ��������߾���
  GensWarningAlarm1.BITS.BITF=F_WARN_OP_LOST;                          //ѹ�����������߾���   
      
      //���� 50                                     
  GensWarningAlarm2.BITS.BIT0=F_DI_FUELLOW_WRN;                         //ȼ��λ�;���     (IN)  
  GensWarningAlarm2.BITS.BIT1=F_DI_WATERLOW_WRN;                        //ˮλ�;���       (IN)  

      //ͨ��״̬1 52
  GensRunStation1.BITS.BIT0=F_STA_FUELOUTPUT;//"ȼ�������ʱ        ��"
  GensRunStation1.BITS.BIT1=F_STA_PRESTART  ;//"����Ԥ����ʱ        ��"
  GensRunStation1.BITS.BIT2=F_STA_CRANK     ;//"������            ��"
  GensRunStation1.BITS.BIT3=F_STA_WAITLOAD  ;//"����ȴ�����"         
  GensRunStation1.BITS.BIT4=F_STA_IDLE      ;//"����������ʱ        ��"
  GensRunStation1.BITS.BIT5=F_STA_WARM      ;//"ů����ʱ            ��"
  GensRunStation1.BITS.BIT6=F_STA_TIMER_SAFE;//"��ȫ������ʱ        ��" 
  GensRunStation1.BITS.BIT7=F_STA_STARTDEL  ;//"������ʱ            ��"
  GensRunStation1.BITS.BIT8=F_STA_STOPDEL;   //"ͣ����ʱ            ��"
  //GensRunStation1.BITS.BIT9= 
  //GensRunStation1.BITS.BITA=;
  //GensRunStation1.BITS.BITB=;
  GensRunStation1.BITS.BITC=F_STA_TRANSCB;   //"����ת����ʱ        ��"
  GensRunStation1.BITS.BITD=F_STA_COOL      ;//"ͣ��ɢ����ʱ        ��"
  GensRunStation1.BITS.BITE=F_STA_STOP_IDLE ;//"ͣ��������ʱ        ��"
  GensRunStation1.BITS.BITF=F_STA_STOP_CHECK;//"�ȴ�ͣ����ʱ        ��"
  
      //ͨ��״̬2 53
  GensRunStation2.BITS.BIT0=F_STA_STOP_FAIL ;        //"ͣ��ʧ��״̬"           
  //GensRunStation2.BITS.BIT1=
  //GensRunStation2.BITS.BIT2=      
  //GensRunStation2.BITS.BIT3=
  //GensRunStation2.BITS.BIT4=      
  //GensRunStation2.BITS.BIT5=      
  //GensRunStation2.BITS.BIT6=
  //GensRunStation2.BITS.BIT7=
  GensRunStation2.BITS.BIT8=F_STA_START_RETRY       ;//"�𶯼����ʱ        ��"
  GensRunStation2.BITS.BIT9=F_STA_MAINS_NORMAL_CHECK;//"�е���������        ��" 
  GensRunStation2.BITS.BITA=F_STA_MAINS_FAIL_CHECK  ;//"�е��쳣����        ��" 
  GensRunStation2.BITS.BITB=F_STA_STOPOUTPUT        ;//"�õ�ͣ����ʱ        ��" 
  GensRunStation2.BITS.BITC=F_STA_AMFSTART          ;//"ʧ����������ʱ      ��"
  GensRunStation2.BITS.BITD=F_STA_AMFSTOP           ;//"�õ���ͣ����ʱ      ��"
 //GensRunStation2.BITS.BITE=TimerEnArr[TMR_GEN_OVERCURRENT_DEL]; //������ʱ
 //GensRunStation2.BITS.BITF=;//
                             
                             
      //ͨ��״̬3 54
  //GensRunStation3.BITS.BIT0=
  //GensRunStation3.BITS.BIT1=
  //GensRunStation3.BITS.BIT2=
    GensRunStation3.BITS.BIT3=F_STA_DES_RUN  ;         //"������������" 
  //GensRunStation3.BITS.BIT4=F_STA_MANMODE  ;         //"�ֶ�ģʽ"               
  //GensRunStation3.BITS.BIT5=F_STA_AUTOMODE ;         //"�Զ�ģʽ"               
  //GensRunStation3.BITS.BIT6=F_STA_TESTMODE ;         //"�ֶ��Ի�ģʽ" 
  //GensRunStation3.BITS.BIT7=F_STA_STOPMODE ;         //"ͣ��ģʽ"

 
}

//************************************************************************************
//�������ƣ�  void LCDCheckAlarmListFun() 
//����������  �����б���ʾ����
//���������    
//���������  
//************************************************************************************
INT08U LcdAlarmListCon=0,LcdAlarmListArray[80];
//INT08U AlarmListMeun=0,AlarmPagaCon=0;
//INT08U AlarmListStopDisF=0;

void LCDCheckAlarmListFun() 
{
  INT08U i,j;
  LcdAlarmListCon=0;
  for(i=0;i<4;i++) 
  {
    for(j=0;j<16;j++) 
    {
      if(AlarmMaping[i].ByteInt & (1<<j)) 
        {LcdAlarmListArray[LcdAlarmListCon]=i*16+j;LcdAlarmListCon++; //�������������
		 
        }
    }
  }
//  if(LcdAlarmListCon!=0)AlarmListMeun= (LcdAlarmListCon-1)/4;         //����������ж���ҳ
}

void LCD_GEC400_DisAlarmList(void)
{
  INT08U i;
  u8 j; 
  const  char *D_str;
   LCDCopyDBAlarmDataTOMapMemery();  //��DB���ݿ��и��Ʊ������ݵ�ӳ���ڴ�
   LCDCheckAlarmListFun();
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   if(LcdAlarmListCon!=AlarmflagHis)
   {GUI_Clear();   //����
   	AlarmflagHis=LcdAlarmListCon;
	  for(i=0;i<LcdAlarmListCon+1;i++)
    { 
	  if(i==0)					  //��ʾ�����ͷ
	  {GUI_SetFont(&GUI_FontHZ_hwhb_32);
	   if(!Language_select)GUI_DispStringAt("AlarmList",10,4);//Ӣ��	
	   else                GUI_DispStringAt("������   ",10,4);
	  }
	  else 
	  {GUI_SetColor(GUI_RED);
       for(j=0;j<30;j++)GUI_DrawLine (1,34*i+3+j,319,34*i+3+j);	//�����б���	  
   	}
	}
   }

   if(LcdAlarmListCon!=0)
   { GUI_SetBkColor(GUI_RED);
     GUI_SetColor(LCD_DisMDtColor);
     GUI_SetFont(&LCD_DisFont);
	for(i=0;i<LcdAlarmListCon;i++)
	{ 
	 if(Language_select)    
	 {D_str=(const char *)&AlarmStrings_CN[LcdAlarmListArray[i]/16].line[LcdAlarmListArray[i]%16][0];
	 }
	 else
	 {D_str=(const char *)&AlarmStrings_EN[LcdAlarmListArray[i]/16].line[LcdAlarmListArray[i]%16][0];
	 }
     if(i<7)GUI_DispStringAt(D_str,2,(i+1)*34+5);	 
	}
   }
   else
   {GUI_SetBkColor(LCD_DisBKColor);
    GUI_SetColor(LCD_DisMDtColor);
    GUI_SetFont(&LCD_DisFont); 
	if(Language_select)    
	{D_str=" �ޱ���                  ";
	}
	else
	{D_str=" No alarm                ";
	}
	GUI_DispStringAt(D_str,2,1*36+5);	
   }
}
/*-----------------------------------------------------------------------
�������ƣ�void LCDDispAlarmWarning(void)
���������� ������ʾ����
���������
���������
----------------------------------------------------------------------- */
 
void LCDDispAlarmWarning(void)          //������ʾ����
{
  const char *D_str;
  char DisNumBuf[40],j,Distr[4];
  INT16U TimerDel=0;
  LCDCopyDBAlarmDataTOMapMemery();  //��DB���ݿ��и��Ʊ������ݵ�ӳ���ڴ�
  LCDDisCalAlarmAdress() ;
 
  if(ReturnAlmStatype!=0xff)
  {
  	if(Language_select)    
  	{
      D_str=(const char *)&AlarmStrings_CN[ReturnAlmStatype].line[ReturnAlmStatBit][0];
	}
  	else
	{
      D_str=(const char *)&AlarmStrings_EN[ReturnAlmStatype].line[ReturnAlmStatBit][0];
  	}	
  	
  	if((ReturnAlmStatype!=5)&&(ReturnAlmStatype!=6)&&(ReturnAlmStatype!=7)) 
    {
       GUI_SetBkColor(LCD_AlarmColor);
	   GUI_SetColor(GUI_RED);
    } 
    else 
    {
	 //GUI_SetTextAlign(GUI_TA_RIGHT);
	  GUI_GotoXY(165,210); 
  	  GUI_SetBkColor(LCD_AlarmColor);
      GUI_SetColor(LCD_AlarmCharCol);
	  TimerDel=LCDdislogicDel();
	  
	  for(j=0;j<4;j++)   {Distr[3-j]=0x20;}//���ݷ���
	  for(j=0;j<40;j++)  { *(DisNumBuf+j)=*(D_str+j);}
	  j=0;
	  while(TimerDel)
	  {Distr[3-j]=TimerDel%10+'0';
	   TimerDel/=10;
	   j++;
	  }
	  for(j=0;j<4;j++)   {DisNumBuf[16+j]=Distr[j];}
	  
	  DisNumBuf[16+j]=0x20;
	  D_str=(const char *)DisNumBuf;
    }
  }
  else
  {	if(Language_select)D_str=(const char *)" ����                    ";					
    else               D_str=(const char *)" Standby                 ";    //Ӣ��
  }
  GUI_DispStringAt(D_str,2,210); 	 
}


void LCD_GEC400_AlarmStaDis(void)
 {
   GUI_SetBkColor(LCD_AlarmColor);
   GUI_SetColor(LCD_AlarmCharCol);
   GUI_SetFont(&LCD_DisFont);
   LCDDispAlarmWarning();
 }

#endif 

#if(LCD_GEC400EN==1)
/*-----------------------------------------------------------------------
�������ƣ� INT16U LcdCalSpChDataFv(INT16U DateBuf,INT08U ChSpPosF) 
���������� �޸Ĳ�����ȷ�ϱ��棬�������ʮ����������ת��Ϊʮ��������
��������� DateBuf:Ԥת������
           ChSpPosF:ת����������  ==0 4λ���� !=0 3λ����
��������� DataFv2 ʮ��������
----------------------------------------------------------------------- */
INT16U LcdCalSpChDataFv(INT16U DateBuf,INT08U ChSpPosF) 
{
  INT16U DataFv1,DataFv2=0;
  INT08U i,Distr[4];
  if(ChSpPosF==0)                                                        
  {
    DataFv2=DateBuf;
  } 
  else                                                    //�� 0x1234ת��Ϊ1234
  {
    DataFv1=DateBuf;
   for(i=0;i<4;i++)				  //���ݷ���
    {	 
	   Distr[3-i]=DataFv1%10;
	   DataFv1 /= 10 ;
    }
   DataFv2=Distr[0]*100+Distr[1]*10+Distr[3];
  }
  return DataFv2;
}
/*-----------------------------------------------------------------------
��������: INT16U LcdCalOctTOhex(INT16U DateOct,INT08U Flag) 
��������: ����ʮ��������ת��Ϊʮ����������
�������: DateOct:Ԥת������  PosFlag:��ʾ�޸ĵ����ݴ�С����
�������: DataFv2 ʮ����������
----------------------------------------------------------------------- */
INT16U LcdCalOctTOhex(INT16U DateOct,INT08U PosFlag) 
{
  INT16U DataFv1=0,DataFv2=0,buf;
    
  if(PosFlag==0)                                    //? 0x14???20
  { 
    buf=DateOct/100;
    DataFv1=buf/10%10;  DataFv2+=DataFv1*4096;
    DataFv1=buf%10;     DataFv2+=DataFv1*256;
    buf=DateOct%100;
    DataFv1=buf/10;     DataFv2+=DataFv1*16;
    DataFv1=buf%10;     DataFv2+=DataFv1; 
    //return DataFv2;
  } 
  else
  {                                                //? 0x124???12.4
    buf=DateOct/100;
  //  DataFv1=buf/10%10;  DataFv2+=DataFv1*4096;
    DataFv1=buf%10;     DataFv2+=DataFv1*4096;
    buf=DateOct%100;
    DataFv1=buf/10;     DataFv2+=DataFv1*256;
    DataFv1=buf%10;     DataFv2+=DataFv1;
    //return DataFv2;
  }
  return DataFv2;
}
/*-----------------------------------------------------------------------
�������ƣ� INT08U LcdJudgeSpDataYesorNot(INT16U JudgeSpData)
���������� �ж��޸ĵ������Ƿ����Ҫ�� 
���������Ԥ�ж�����
���������0 ���ڷ�Χ  1 �ڷ�Χ
----------------------------------------------------------------------- */
  
INT08U LcdJudgeSpDataYesorNot(INT16U JudgeSpData) 
{
  INT16U JudgeData1=0,JudgeData2=0;
  JudgeData1=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->MinValue;//��Χ ��Сֵ 
  JudgeData2=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->MaxValue;//��Χ ���ֵ 
  if((JudgeSpData>=JudgeData1)&&(JudgeSpData<=JudgeData2)) return 1;
  else return 0;
}

void LcdKeySaveParm()
{
  INT08U Buf1;
  switch(PaswordTypeToDisFlag)
  {
    case Password0x0318:
    case Password0x1234:
      ParmSetCurDisFlag=Password0x0318;
      if(ChSpBuf==0)   
      {
       SetCursorMove++;                                                                  //��ͨ����
       if((SetCursorMove==3)&&(ChSpPosFlag!=0))SetCursorMove++;                          //������������С���㣬���Ҫ����һλ
       if(SetCursorMove>4)
        {
          if(LcdJudgeSpDataYesorNot(LcdCalSpChDataFv(SystemParmModify,ChSpPosFlag)))     //�ж����������Ƿ��ڷ�Χ��
          {
           Buf1=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParmSetHeadnum; //��ǰֵ�������е�ƫ���� 
			     FLASHDATABASE[Buf1].Sbyte=LcdCalSpChDataFv(SystemParmModify,ChSpPosFlag);
			     //FLASH_SaveModifParm();                                                 //���浱ǰ�޸ĵĲ��� ��ͨ����
		       FLASH_SavepParm();
					}
          SetCursorMove=0;ParmSetCurDisFlag=0;SystemParmModify=0;KeyMenulevel=0x05;
        }
      } 
    break;

    default:break; 
  }
}

#endif

//--------------------------------------------------------
//Name:	               ��������У�麯��
//Function�� XIOCalRate(INT16U ParamNum,INT16S Value)
//Descreate: ParamNum--�������
//			 Value --  ��У�����ݲ���ʵʱֵ
//--------------------------------------------------------

INT16S XIOCalRate(INT16U ParamNum,INT16S Value)
{
    if(ParamNum==sPa_VOLT_MAINS_A)//A���е��ѹУ׼
    {      
       REALDATA=(INT32S)VOLTAGEA2*RECAL_VOLT_MAINS_A/10000;       
       RECALDATA=REALDATA*10000/(INT32S)Value;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_VOLT_MAINS_A;
       }       
    }
    
    if(ParamNum==sPa_VOLT_MAINS_B)//B���е��ѹУ׼
    {      
       REALDATA=(INT32S)VOLTAGEB2*RECAL_VOLT_MAINS_B/10000;       
       RECALDATA=REALDATA*10000/(INT32S)Value;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_VOLT_MAINS_B;
       }       
    }
    
    if(ParamNum==sPa_VOLT_MAINS_C)//C���е��ѹУ׼
    {      
       REALDATA=(INT32S)VOLTAGEC2*RECAL_VOLT_MAINS_C/10000;       
       RECALDATA=REALDATA*10000/(INT32S)Value;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_VOLT_MAINS_C;
       }       
    }
    
    if(ParamNum==sPa_VOLT_GEN_A)//A�෢���ѹУ׼
    {      
       REALDATA=(INT32S)VOLTAGEA1*RECAL_VOLT_GEN_A/10000;       
       RECALDATA=REALDATA*10000/(INT32S)Value;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_VOLT_GEN_A;
       }       
    }
    if(ParamNum==sPa_VOLT_GEN_B)//B�෢���ѹУ׼
    {      
       REALDATA=(INT32S)VOLTAGEB1*RECAL_VOLT_GEN_B/10000;       
       RECALDATA=REALDATA*10000/(INT32S)Value;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_VOLT_GEN_B;
       }       
    }
    if(ParamNum==sPa_VOLT_GEN_C)//C�෢���ѹУ׼
    {      
       REALDATA=(INT32S)VOLTAGEC1*RECAL_VOLT_GEN_C/10000;       
       RECALDATA=REALDATA*10000/(INT32S)Value;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_VOLT_GEN_C;
       }       
    }        
    
    if(ParamNum==sPa_CURRENT_A)//����A��У׼
    {      
       REALDATA=(INT32S)CURRENTA*RECAL_CURRENT_A/100000;       
       RECALDATA=REALDATA*10000/(INT32S)Value;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_CURRENT_A;
       }       
    }     
    if(ParamNum==sPa_CURRENT_B)//����B��У׼
    {      
       REALDATA=(INT32S)CURRENTB*RECAL_CURRENT_B/100000;       
       RECALDATA=REALDATA*10000/(INT32S)Value;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_CURRENT_B;
       }       
    } 
    if(ParamNum==sPa_CURRENT_C)//����C��У׼
    {      
       REALDATA=(INT32S)CURRENTC*RECAL_CURRENT_C/100000;       
       RECALDATA=REALDATA*10000/(INT32S)Value;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_CURRENT_C;
       }       
    }   
    
    if(ParamNum==sPa_TEMP)//ˮ����У��
    {      
       REALDATA=(INT32S)AI_OHM[1];
       RECALDATA=(INT32S)Value*10000 / REALDATA;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_TEMP ;
       }       
    } 
    if(ParamNum==sPa_OP) //����ѹ��У��
    {      
       REALDATA=(INT32S)AI_OHM[0];
       RECALDATA =(INT32S)Value*10000 / REALDATA;     
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_OP;
       }       
    } 
    if(ParamNum==sPa_LEVEL)//ȼ��λУ��
    {      
       REALDATA=(INT32S)AI_OHM[2];
       RECALDATA=(INT32S)Value*10000 / REALDATA;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_LEVEL;
       }       
    }       
      
    if(ParamNum==sPa_BATT)//У׼��ص�ѹ
    {      
       REALDATA=(INT32S)PowerVoltageReal;
       RECALDATA=(INT32S)(Value-6)*10000 / REALDATA;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_BATT;
       }       
    }    
    if(ParamNum==sPa_CHARGER)//У׼D+��ѹ
    {      
       REALDATA=(INT32S)ChargerVoltageReal;
       RECALDATA=(INT32S)(Value-6)*10000 / REALDATA;       
       if(RECALDATA<16000&&RECALDATA>4000)
       {
           return RECALDATA;
       }
       else
       {
           return RECAL_CHARGER;
       }       
    }
	
   return 10000;	     
}
/*-----------------------------------------------------------------------
�������ƣ� INT08U LcdJudgeAdjDataYesorNot(INT16U JudgeAdjData)
���������� �ж��޸ĵ������Ƿ����Ҫ�� 
���������Ԥ�ж�����
���������0 ���ڷ�Χ  1 �ڷ�Χ
----------------------------------------------------------------------- */
  
INT08U LcdJudgeAdjDataYesorNot(INT16U JudgeAdjData) 
{
  INT16U JudgeData1=0,JudgeData2=0;
  JudgeData1=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->MinValue;//��Χ ��Сֵ 
  JudgeData2=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->MaxValue;//��Χ ���ֵ 
  if((JudgeAdjData>=JudgeData1)&&(JudgeAdjData<=JudgeData2)) return 1;
  else                                                       return 0;
}

void LcdKeySaveAdjParm() 
{
  INT08U Buf1;
  INT16U SaveDBuf;
  switch(AdjParmSetCurDisFlag)	 
  {
    case Password0x0636:
     if(AdjChMenuSpBuf==0)   
      {AdjSetCursorMove++;                                                        //У�����
       if((AdjSetCursorMove==3)&&(AdjSpPosFlag!=0))AdjSetCursorMove++;            //У�������������С���㣬���Ҫ����һλ
       if(AdjSetCursorMove>4)
       { Buf1=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParmSetHeadnum;      //��ǰֵ�������е�ƫ���� 
	       SaveDBuf=XIOCalRate(Buf1,LcdCalSpChDataFv(AdjParmModify,AdjSpPosFlag));
          if(LcdJudgeAdjDataYesorNot(SaveDBuf)) //�ж����������Ƿ��ڷ�Χ��
          { FLASHDATABASE[Buf1].Sbyte=SaveDBuf;
			     // FLASH_SaveModifParm();                                              //���浱ǰ�޸ĵ�У����� 
            FLASH_SavesAdjParm();	
					}
          AdjSetCursorMove=0;AdjParmModify=0;
		      KeyMenulevel=0x07;
		      AdjParmSetCurDisFlag=0;
       }
      } 
    break;

    default:break; 
  }
}

/*-----------------------------------------------------------------------
�������ƣ� LCDSaveCurveParmSet
���������� �����޸ĵ��Զ�����������
���������
���������
----------------------------------------------------------------------- */
void LCDSaveCurveParmSet(void)
{
 INT08U buf=0,k;
 for(k=0;k<CurveDotCtr;k++)	  //�ж������޸ĵ������Ƿ��ںϷ���Χ��
 {if(DB_JudgeCurveInitDRN(CurveMidfyBuf[k*2],SpSetCursorMove,k)==0)              {buf++;}
  if(DB_JudgeCurveInitDRN(CurveMidfyBuf[k*2+1],SpSetCursorMove,k+CurveDotCtr)==0){buf++;}
 }
 if(buf==0)
 {for(k=0;k<CurveDotCtr;k++) //�ǺϷ��޸����ݱ��浽flash
  {buf=MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[k]->ParmSetHeadnum;
   FLASHDATABASE[buf].Sbyte=CurveMidfyBuf[k*2];
   buf=MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[k+CurveDotCtr]->ParmSetHeadnum;
   FLASHDATABASE[buf].Sbyte=CurveMidfyBuf[k*2+1];
  }
  //FLASH_SaveModifParm();                        //���浱ǰ�޸ĵ��Զ����������ݲ��� 
	FLASH_SavecCurveParm();
 }
} 
  
/*---------------------------------------------------------------------------
��������: void LCD_GEC400_MainPgMDataDis(void) 
��������:      �������ݽ�����ʾ   
----------------------------------------------------------------------------*/ 
#if(LCD_GEC400EN==1)
void LCD_GEC400_DisMTemp(void)
{
  if(WATERTEMP==-32768)
  {
   GUI_GotoXY(129,76);GUI_DispString("+++");
   GUI_GotoXY(236,76);GUI_DispString("+++");
  }
  else  
  { 
   GUI_GotoXY(118,76);GUI_DispDecSpace(WATERTEMP,4);
   GUI_GotoXY(225,76);GUI_DispDecSpace(LCDTempUnitswitch(WATERTEMP),4); 
  }
}

void LCD_GEC400_DisMOilPress(void)
{
 float LCD_DisNum;
 if(OILPRESSURE==-32768)
  {
   GUI_GotoXY(225,110);GUI_DispString("++++");
   GUI_GotoXY(74,142); GUI_DispString("+++++");
   GUI_GotoXY(225,142);GUI_DispString("++++");
  }
  else  
  { 
   GUI_GotoXY(225,110);GUI_DispDecSpace(LCDPSIBarUnitswitch(OILPRESSURE,0),4);
   LCD_DisNum=(float)LCDPSIBarUnitswitch(OILPRESSURE,1)/(float)10.0;
   GUI_GotoXY( 74,142);GUI_DispFloat(LCD_DisNum,5); 

   LCD_DisNum=(float)LCDPSIBarUnitswitch(OILPRESSURE,2)/(float)100.0;
   GUI_GotoXY(225,142);GUI_DispFloat(LCD_DisNum,4); 
  }
}

void LCD_GEC400_DisMFuel(void)
{
  if(FUEL==-32768)
  {
   GUI_GotoXY(260,44);GUI_DispString("+++");
  }
  else  
  { 
   GUI_GotoXY(249,44);GUI_DispDecSpace(FUEL,4); 
  }
}

void LCDisINSwitchStat(void)
{
 if(F_AUX_INPUT1)GUI_DispStringAt("��", 62,83);
 else			 GUI_DispStringAt("��", 62,83);
											 
 if(F_AUX_INPUT2)GUI_DispStringAt("��",96,83);
 else			 GUI_DispStringAt("��",96,83);
											 
 if(F_AUX_INPUT3)GUI_DispStringAt("��",130,83);
 else			 GUI_DispStringAt("��",130,83);
											 
 //if(F_AUX_INPUT4)GUI_DispStringAt("��",163,83);
 //else			 GUI_DispStringAt("��",163,83);

}

void LCDisOutSwitchStat(void)
{
 if(F_OUTPUT_CRANK)GUI_DispStringAt("��", 62,155);
 else			   GUI_DispStringAt("��", 62,155);

 if(F_AUX_OUTPUT1) GUI_DispStringAt("��", 96,155);
 else			   GUI_DispStringAt("��", 96,155);
												
 if(F_AUX_OUTPUT2) GUI_DispStringAt("��", 130,155);
 else			   GUI_DispStringAt("��", 130,155);
												
 if(F_AUX_OUTPUT3) GUI_DispStringAt("��", 163,155);
 else			   GUI_DispStringAt("��", 163,155);
												
 if(F_AUX_OUTPUT4) GUI_DispStringAt("��", 196,155);
 else			   GUI_DispStringAt("��",196,155);
												
 if(F_AUX_OUTPUT5) GUI_DispStringAt("��", 229,155);
 else			   GUI_DispStringAt("��", 229,155);
												
 if(F_AUX_OUTPUT6) GUI_DispStringAt("��", 263,155);
 else			   GUI_DispStringAt("��", 263,155);
}


void LCD_GEC400_MainPgMDataDis(void)
{  float LCD_DisNum;
	INT32U i;
   INT32U GensElectricity;
   GUI_SetBkColor(LCD_DisColor);
   GUI_SetColor(LCD_DisMDtColor);
   //GUI_SetFont(&GUI_Font32_ASCII);   
   GUI_SetFont(&LCD_DisFont);   
  switch(MainPageCon)
  {
   case 1:
		 if(GEN_VOLT_TYPE == 2)
		 {
			 for(i=0;i<31;i++)GUI_Line(80,33*1+8+i,220,33*1+8+i,GUI_WHITE);	//��ʾ�������ݱ���
			 for(i=0;i<31;i++)GUI_Line(80,33*2+8+i,220,33*2+8+i,GUI_WHITE);	//��ʾ�������ݱ���
			 for(i=0;i<31;i++)GUI_Line(80,33*3+8+i,220,33*3+8+i,GUI_WHITE);	//��ʾ�������ݱ���			 
		 }
		 else
		 {	
			 GUI_GotoXY( 85,45);  GUI_DispDecSpace(VOLTAGEA1,3);
			 GUI_GotoXY(170,45);  GUI_DispDecSpace(VOLTAGEB1,3); 
			 GUI_GotoXY( 85,77);  GUI_DispDecSpace(VOLTAGEAB1,3);
			 GUI_GotoXY(170,77);  GUI_DispDecSpace(VOLTAGEBC1,3);
			 GUI_GotoXY( 74,110); GUI_DispDecSpace(CURRENTA/10,4);
			 GUI_GotoXY(159,110); GUI_DispDecSpace(CURRENTB/10,4);			 
		 }
	 
//	  GUI_GotoXY( 85,45);  GUI_DispDecSpace(VOLTAGEA1,3);
//	  GUI_GotoXY(170,45);  GUI_DispDecSpace(VOLTAGEB1,3);
   	  GUI_GotoXY(255,45);  GUI_DispDecSpace(VOLTAGEC1,3);	   //����L-N
	  
//	  GUI_GotoXY( 85,77);  GUI_DispDecSpace(VOLTAGEAB1,3);
//	  GUI_GotoXY(170,77);  GUI_DispDecSpace(VOLTAGEBC1,3);
	   GUI_GotoXY(255,77); GUI_DispDecSpace(VOLTAGECA1,3);     //����L-L

//	  GUI_GotoXY( 74,110); GUI_DispDecSpace(CURRENTA/10,4);
//	  GUI_GotoXY(159,110); GUI_DispDecSpace(CURRENTB/10,4); 
	   GUI_GotoXY(244,110); GUI_DispDecSpace(CURRENTC/10,4);    //���� 
				
	  LCD_DisNum=(float)KWALL/(float)10.0;
	  GUI_GotoXY( 74,142); GUI_DispFloat(LCD_DisNum,4);	     //�й�����
	  LCD_DisNum=(float)KVARALL/(float)10.0;
	  GUI_GotoXY(202,142); GUI_DispFloat(LCD_DisNum,4); 	   //�޹�����
	  
	  LCD_DisNum=(float)PhaseCOS/(float)100.0;
	  GUI_GotoXY( 40,177); GUI_DispFloat(LCD_DisNum,4);	       //��������
	  
	  LCD_DisNum=(float)GEN_FREQ/(float)10.0;
	  GUI_GotoXY(110,177); GUI_DispFloat(LCD_DisNum,4);	       //����Ƶ��
		LCD_DisNum=(float)KVAALL/(float)10.0;
	  GUI_GotoXY(215,177); GUI_DispFloat(LCD_DisNum,4); 	   //���ڹ���
	  
	  break;
	 case 2://126 243 288
	   GensElectricity=(INT32U)EPROM_STARTNUM;
	   GUI_GotoXY(240, 43);GUI_DispDecSpace(GensElectricity,6); //�ۼƿ�������
	   GUI_GotoXY(146, 78);GUI_DispDecSpace(RUNNINGHOUR,8);	    //�ۼ�����ʱ�� ʱ
	   GUI_GotoXY(254, 78);GUI_DispDecSpace(RUNNINGMINUTE,2);   //�ۼ�����ʱ�� ��
	   GUI_GotoXY(288, 78);GUI_DispDecSpace(RUNNINGSEC,2);	    //�ۼ�����ʱ�� ��
//	   GensElectricity= *KWH;//@@@@@@@@@@ZC
	   GUI_GotoXY(170,110);GUI_DispDecSpace(GensElectricity/10,9); //�ۼƵ���
	  break;
	 case 3:
	  GUI_GotoXY(226,44); GUI_DispDecSpace(DES_DISPSPEED,4);	//ת��
	  LCD_GEC400_DisMTemp();							                    //ˮ��
	  LCD_GEC400_DisMOilPress();						                  //����ѹ��
	  LCD_DisNum=(float)PowerVoltage/(float)10.0;
	  GUI_GotoXY( 80,176);GUI_DispFloat(LCD_DisNum,4);	     //��ص�ѹ
	  LCD_DisNum=(float)ChargerVoltage/(float)10.0;		  
	  GUI_GotoXY(245,176);GUI_DispFloat(LCD_DisNum,4);	     //������ѹ
	  
	  break;
	 case 4:  
	  LCD_GEC400_DisMFuel();							  //ȼ��λ
	  break;
	 case 5:		 //I/O״̬��ʾ
	  GUI_SetBkColor(LCD_DisBKColor);
	  GUI_SetColor(GUI_WHITE);
	  LCDisINSwitchStat();
	  LCDisOutSwitchStat();
	  GUI_SetBkColor(LCD_DisColor);
	  GUI_SetColor(LCD_DisMDtColor);
	  break; 
	 default:break;
  }
}

#endif

/*---------------------------------------------------------------------------
��������: void LCD_GEC400_FirGUIDEMO(void) 
��������:      ����������ҳ��ʾ   
----------------------------------------------------------------------------*/  
#if(LCD_GEC400EN==1)

void LCD_GEC400_FirPagMTemp(unsigned short x,unsigned short y)
{
  if(WATERTEMP==-32768)
  {
   GUI_GotoXY(x,y);GUI_DispString("++++");
  }
  else  
  { 
   GUI_GotoXY(x,y);GUI_DispDecSpace(WATERTEMP,4);
  }
}
void LCD_GEC400_FirPagMOilPress(unsigned short x,unsigned short y)//Bar
{
 float LCD_DisNum;
 if(OILPRESSURE==-32768)
  {
   GUI_GotoXY(x,y);GUI_DispString("++++");
  }
  else  
  {
   LCD_DisNum=(float)LCDPSIBarUnitswitch(OILPRESSURE,2)/(float)100.0;
   GUI_GotoXY(x,y);GUI_DispFloat(LCD_DisNum,4);  
  }
}

void LCD_GEC400_FirPagMdis()
{
   float LCD_DisNum; 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   
   GUI_GotoXY( 80,20);LCD_DisNum=(float)KWALL/(float)10.0; 
	 GUI_DispFloat(LCD_DisNum,4);   //�й�����
   GUI_GotoXY(170,20); GUI_DispDecSpace(DES_DISPSPEED,4);//ת��
   if(GEN_VOLT_TYPE == 2){ GUI_GotoXY( 85,90); GUI_DispDecSpace(VOLTAGEC1,3); } //����L-N 
   else {GUI_GotoXY( 85,90); GUI_DispDecSpace(VOLTAGEA1,3); } //����L-N   
   LCD_GEC400_FirPagMOilPress(225,90);					       //����ѹ��
   GUI_GotoXY( 73,115);GUI_DispDecSpace(CURRENTA/10,4);//����
   LCD_GEC400_FirPagMTemp(225,115);						         //�¶�
   LCD_DisNum=(float)GEN_FREQ/(float)10.0;
   GUI_GotoXY( 73,140);GUI_DispFloat(LCD_DisNum,4);	   //����Ƶ��	
   LCD_DisNum=(float)PowerVoltage/(float)10.0;
   GUI_GotoXY(225,140);GUI_DispFloat(LCD_DisNum,4);	   //��ص�ѹ
    
}

#endif

/*---------------------------------------------------------------------------
��������: void LCD_GEC400FirPageLightDis(void) 
��������:      �ֽ���ָʾ����ʾ   
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)
 
void LCD_GEC400FirPageLightDis(void)
{
  unsigned char i;
  if(LED_GENSET==1)					  //��������ָʾ
  {  GUI_SetColor(LCDFirstLightOnCol); 
     GUI_FillCircle(102,70,12);
  }
  else
  {  GUI_SetColor(LCDFirstLightOffCol); 
     GUI_FillCircle(102,70,12);
  }
  
  if(LED_GCB)					   //�����բָʾ
  {	//GUI_SetColor(LCDFirstLightOnCol);
    //GUI_FillCircle(216,70,12);
		GUI_DrawOpen(1);
  }
  else
  {	//GUI_SetColor(LCDFirstLightOffCol);
    //GUI_FillCircle(216,70,12);
		GUI_DrawOpen(0);
  }

  if(F_SHOW_LED_STOP==1)				 //ͣ��
  {
   GUI_SetColor(LCDFirstLightOnCol); 
	 for (i=0; i<12; i++) GUI_DrawCircle(20,186,i); 	
  }
  else
  {
   GUI_SetColor(LCDFirstLightOffCol); 
   for (i=0; i<3; i++) GUI_DrawCircle(20,186,i+9); 
   GUI_SetColor(LCD_DisColor); 
   for (i=0; i<9; i++) GUI_DrawCircle(20,186,i); 
  }
	
  if(F_SHOW_LED_MANUAL==1)			     //�ֶ�
  {	
   GUI_SetColor(LCDFirstLightOnCol); 
   for (i=0; i<12; i++) GUI_DrawCircle(130,186,i); 		
  }
  else
  {
   GUI_SetColor(LCDFirstLightOffCol);
   for (i=0; i<3; i++) GUI_DrawCircle(130,186,i+9); 
   GUI_SetColor(LCD_DisColor); 
   for (i=0; i<9; i++) GUI_DrawCircle(130,186,i); 
  }
  if(F_SHOW_LED_AUTO==1)				 //�Զ�
  {
   GUI_SetColor(LCDFirstLightOnCol); 
   for (i=0; i<12; i++) GUI_DrawCircle(245,186,i); 	 
  }
  else
  {
   GUI_SetColor(LCDFirstLightOffCol);
   for (i=0; i<3; i++) GUI_DrawCircle(245,186,i+9); 
   GUI_SetColor(LCD_DisColor); 
   for (i=0; i<9; i++) GUI_DrawCircle(245,186,i); 
  }
}
#endif

/*---------------------------------------------------------------------------
��������: void LCD_GEC400_MainPgHeadDis(void) 
��������:      ������������ͷ��ʾ   
----------------------------------------------------------------------------*/  
#if(LCD_GEC400EN==1)

void LCDGEC400MPagHeadNumDis(void)  //����ҳ��ͷ�������ʾ
{ //GUI_SetFont(&GUI_Font24B_ASCII); //@@@@@@@@@@@@@@ZC
  switch(MainPageCon)
  {
    case 1:GUI_DispStringAt("1/2",280,15);break;
	  case 2:GUI_DispStringAt("2/2",280,15);break;
	  case 3:GUI_DispStringAt("1/2",280,15);break;
	  case 4:GUI_DispStringAt("2/2",280,15);break;
	  case 5:GUI_DispStringAt("1/1",280,15);break;
  }	  
}

void LCDGEC400HeadIOStatPagDis(void)  //I/O״̬��ʾҳ��
{  u8 j;
   GUI_SetFont(&GUI_FontHZ_hwhb_32); //
   if(!Language_select)GUI_DispStringAt("I/O    ",10,4);	//Ӣ��
   else				   GUI_DispStringAt("I/O״̬",10,4);
   LCDGEC400MPagHeadNumDis();                          //����ҳ��ͷ�������ʾ
   for(j=0;j<4;j++)GUI_Line(1,40+j,319,40+j,GUI_WHITE);//����
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_DispStringAt("IN:   1  2  3             ",2, 50);	
   GUI_DispStringAt("OUT:  C  1  2  3  4  5  6 ",2,118);	
}

void LCDGEC400OtherHeadPagDis(void)  //����ҳ��״̬��ʾҳ��
{ 
  u8 i;
  u8 j;
  const  char *D_str; 
  for(i=0;i<6;i++)
   { 
	  D_str=(const char *)PageShow.Pages[MainPageCon]->Pagept[Language_select*(PageShow.Pages[MainPageCon]->Disable)+i];
    if(i==0)					  //��ʾ�����ͷ
	 {GUI_SetFont(&GUI_FontHZ_hwhb_32);
	  GUI_DispStringAt(D_str,10,4);
	  LCDGEC400MPagHeadNumDis();  //����ҳ��ͷ�������ʾ
	 }
	 else 
	 {
	  for(j=0;j<31;j++)GUI_Line(1,33*i+8+j,319,33*i+8+j,GUI_WHITE);	//��ʾ�������ݱ���
	  GUI_SetBkColor(GUI_WHITE);
      GUI_SetColor(LCD_DisMDtColor);
	  GUI_SetFont(&LCD_DisFont);
	  switch(i)													    //��ʾ��������ͷ
	  {
	   case 1:GUI_DispStringAt(D_str,3, 44);break;
	   case 2:GUI_DispStringAt(D_str,3, 76);break;
	   case 3:GUI_DispStringAt(D_str,3,110);break;
	   case 4:GUI_DispStringAt(D_str,3,142);break;
	   case 5:GUI_DispStringAt(D_str,3,176);break;
	  }
	 }
   }
}
void LCD_GEC400_MainPgHeadDis(void)
 {
   u8 i; 
   	 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   GUI_Clear();   //����
   
   for(i=0;i<33;i++)GUI_Line(1,206+i,319,206+i,LCD_AlarmColor);	//������������ʾ
   if(MainPageCon==LCDIOStatPgCtr)LCDGEC400HeadIOStatPagDis();  //I/O״̬��ʾҳ��
   else                           LCDGEC400OtherHeadPagDis();  //����ҳ��״̬��ʾҳ��
   
 }

#endif
/*---------------------------------------------------------------------------
��������: void LCD_GEC400_MainPgOtherDisStartSpd(void) 
��������:   ���ݲ�ͬ�������ɹ�������ʾ�׽���   
 //0���Ÿ��� 3���Ŵ�����+��ѹ
----------------------------------------------------------------------------*/ 
#if(LCD_GEC400EN==1)

void LCD_GEC400_DisMOilPressSpd(void)
{
  float LCD_DisNum;
  if(OILPRESSURE==-32768)
  {
   GUI_GotoXY(228,76);  GUI_DispString("++++");
   GUI_GotoXY( 76,110); GUI_DispString("+++++");
   GUI_GotoXY(227,110); GUI_DispString("++++");
  }
  else  
  { 
   GUI_GotoXY(228,76); GUI_DispDecSpace(LCDPSIBarUnitswitch(OILPRESSURE,0),4);
   LCD_DisNum=(float)LCDPSIBarUnitswitch(OILPRESSURE,1)/(float)10.0;
   GUI_GotoXY( 76,110);GUI_DispFloat(LCD_DisNum,5); 

   LCD_DisNum=(float)LCDPSIBarUnitswitch(OILPRESSURE,2)/(float)100.0;
   GUI_GotoXY(227,110);GUI_DispFloat(LCD_DisNum,4); 
  }
 } 

void LCD_GEC400_MainPgMDataDisSpd(void)
{  float LCD_DisNum;
   INT32U GensElectricity;
   GUI_SetBkColor(LCD_DisColor);
   GUI_SetColor(LCD_DisMDtColor);
   GUI_SetFont(&LCD_DisFont);   
  switch(MainPageCon)
  {
   case 1:
	  GUI_GotoXY(226,44); GUI_DispDecSpace(DES_DISPSPEED,4);	//ת��
	  LCD_GEC400_DisMOilPressSpd();						                //����ѹ��
	  break;
	 case 2:
	   GensElectricity=(INT32U)EPROM_STARTNUM;
	   GUI_GotoXY(240, 43);GUI_DispDecSpace(GensElectricity,6); //�ۼƿ�������
	   GUI_GotoXY(146, 78);GUI_DispDecSpace(RUNNINGHOUR,8);	    //�ۼ�����ʱ�� ʱ
	   GUI_GotoXY(254, 78);GUI_DispDecSpace(RUNNINGMINUTE,2);   //�ۼ�����ʱ�� ��
	   GUI_GotoXY(288, 78);GUI_DispDecSpace(RUNNINGSEC,2);	    //�ۼ�����ʱ�� ��
	  break;
	 case 3:		 //I/O״̬��ʾ
	   GUI_SetBkColor(LCD_DisBKColor);
	   GUI_SetColor(GUI_WHITE);
	   LCDisINSwitchStat();
	   LCDisOutSwitchStat();
	   GUI_SetBkColor(LCD_DisColor);
	   GUI_SetColor(LCD_DisMDtColor);
	  break;
	 default:break;
  }
}

void LCD_GEC400_DisFirPageFuel(void)
{
  if(FUEL==-32768)
  {
   GUI_GotoXY(235,115);GUI_DispString("+++");
  }
  else  
  { 
   GUI_GotoXY(224,115);GUI_DispDecSpace(FUEL,4); 
  }
}

void LCD_GEC400_FirPagMdisSpd()
{
   float LCD_DisNum; 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   
   LCD_GEC400_FirPagMOilPress(73,90);					         //����ѹ��
   LCD_GEC400_FirPagMTemp(73,115);						         //�¶�
   LCD_DisNum=(float)PowerVoltage/(float)10.0;
   GUI_GotoXY(73,140);GUI_DispFloat(LCD_DisNum,4);	   //��ص�ѹ
	
	 GUI_GotoXY(225,90); GUI_DispDecSpace(DES_DISPSPEED,4);//ת��
   LCD_GEC400_DisFirPageFuel();						             //ȼ��λ
   LCD_DisNum=(float)ChargerVoltage/(float)10.0;
   GUI_GotoXY(225,140);GUI_DispFloat(LCD_DisNum,4);	   //������ѹ
}
 
void LCDGEC400MPagHeadNumDisStartSpd(void)  //����ҳ��ͷ�������ʾ
{// GUI_SetFont(&GUI_Font24B_ASCII);  //@@@@@@@@@@@@@ZC
  switch(MainPageCon)
  {
    case 1:GUI_DispStringAt("1/2",280,15);break;
	  case 2:GUI_DispStringAt("2/2",280,15);break;
	  case 3:GUI_DispStringAt("1/1",280,15);break;
	  default:GUI_DispStringAt("1/1",280,15);break;
  }	  
}

void LCDGEC400HeadIOStatPagDisStartSpd(void)  //I/O״̬��ʾҳ��
{  u8 j;
   GUI_SetFont(&GUI_FontHZ_hwhb_32); //
   if(!Language_select)GUI_DispStringAt("I/O    ",10,4);	//Ӣ��
   else				         GUI_DispStringAt("I/O״̬",10,4);
   LCDGEC400MPagHeadNumDisStartSpd();                     //����ҳ��ͷ�������ʾ
   for(j=0;j<4;j++)GUI_Line(1,40+j,319,40+j,GUI_WHITE);//����
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_DispStringAt("IN:   1  2  3             ",2, 50);	
   GUI_DispStringAt("OUT:  C  1  2  3  4  5  6 ",2,118);	
}

void LCDGEC400OtherHeadPagDisStartSpd(void)  //����ҳ��״̬��ʾҳ��
{ 
  u8 i;
  u8 j;
  const  char *D_str; 
  for(i=0;i<6;i++)
  { 
	  if((!Language_select)&&(i==PageShowSpd.Pages[MainPageCon]->Disable)){break;}
	  D_str=(const char *)PageShowSpd.Pages[MainPageCon]->Pagept[Language_select*(PageShowSpd.Pages[MainPageCon]->Disable)+i];
    if(i==0)					  //��ʾ�����ͷ
	  { GUI_SetFont(&GUI_FontHZ_hwhb_32);
	    GUI_DispStringAt(D_str,10,4);
	    LCDGEC400MPagHeadNumDisStartSpd();  //����ҳ��ͷ�������ʾ
	  }
	  else 
	  {
	     for(j=0;j<31;j++)GUI_Line(1,33*i+8+j,319,33*i+8+j,GUI_WHITE);	//��ʾ�������ݱ���
	     GUI_SetBkColor(GUI_WHITE);
       GUI_SetColor(LCD_DisMDtColor);
	     GUI_SetFont(&LCD_DisFont);
	     switch(i)													    //��ʾ��������ͷ
	     {
	      case 1:GUI_DispStringAt(D_str,3, 44);break;
	      case 2:GUI_DispStringAt(D_str,3, 76);break;
	      case 3:GUI_DispStringAt(D_str,3,110);break;
	      case 4:GUI_DispStringAt(D_str,3,142);break;
	      case 5:GUI_DispStringAt(D_str,3,176);break;
	     }
	   }
   }
}

void LCD_GEC400_MainPgHeadDisStartSpd(void)
 {
   u8 i; 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   GUI_Clear();   //����
   for(i=0;i<33;i++)GUI_Line(1,206+i,319,206+i,LCD_AlarmColor);	//������������ʾ
   if(MainPageCon==3)LCDGEC400HeadIOStatPagDisStartSpd();       //I/O״̬��ʾҳ��
   else              LCDGEC400OtherHeadPagDisStartSpd();        //����ҳ��״̬��ʾҳ��
 }
 
void LCD_GEC400_MainPgOtherDisStartSpd(void)
{
  if(MainPageCon!=MainPageConHis)
  {
	 MainPageConHis=MainPageCon;
	 LCD_GEC400_MainPgHeadDisStartSpd();
  }
  LCD_GEC400_MainPgMDataDisSpd(); 
 }

 void LCD_GEC400_MainPgDis_STARTSUCC_CONDITIONVol(void)
 {
   if(MainPageCon!=0) 
   {
     if(MainPageCon!=4){LCD_GEC400_MainPgOtherDisStartSpd();AlarmflagHis=0xff;}
	   else				       {LCD_GEC400_DisAlarmList();MainPageConHis=0xff;}//�����б���ʾ
   	 FirGuiDemoHis=0xff;
   }
   else 							//��ʾ�׽�����ʾ
   {
    MainPageConHis=0xff;AlarmflagHis=0xff;
    GUI_SetBkColor(LCD_DisBKColor);
    GUI_SetColor(LCD_DisColor);
    GUI_SetFont(&LCD_DisFont);
    GUI_SetTextMode(GUI_TEXTMODE_NORMAL); 
		if(FirGuiDemoHis!=0)
		{
		 FirGuiDemoHis=0; 
		 GUI_Clear();
		 GUIDEMO_AutomotiveSpd();
		}
		LCD_GEC400FirPageLightDis();
		LCD_GEC400_FirPagMdisSpd();
   }
  if(MainPageCon!=4)LCD_GEC400_AlarmStaDis();//��������ʾ
 }
 
 #endif
/*---------------------------------------------------------------------------
��������: void LCD_GEC400_MainPgDis_STARTSUCC_CONDITION03(void) 
��������:   ���ݲ�ͬ�������ɹ�������ʾ�׽��� 
//1������    2���Ŵ�����+����    4������+��ѹ  5���Ŵ�����+����+��ѹ 
----------------------------------------------------------------------------*/
 
#if(LCD_GEC400EN==1)
 
void LCD_GEC400_MainPgOtherDis(void)
{
  if(MainPageCon!=MainPageConHis)
  {
	 MainPageConHis=MainPageCon;
	 LCD_GEC400_MainPgHeadDis();
  }
  LCD_GEC400_MainPgMDataDis(); 
 }

 void LCD_GEC400_MainPgDis_STARTSUCC_CONDITION03(void)
 {
   if(MainPageCon!=0) 
   {
     if(MainPageCon!=LCDAlarmListPg){LCD_GEC400_MainPgOtherDis();AlarmflagHis=0xff;}
	   else				            {LCD_GEC400_DisAlarmList();MainPageConHis=0xff;}//�����б���ʾ
   	 FirGuiDemoHis=0xff;
   }
   else 							//��ʾ�׽�����ʾ
   {
    MainPageConHis=0xff;AlarmflagHis=0xff;
    GUI_SetBkColor(LCD_DisBKColor);
    GUI_SetColor(LCD_DisColor);
    GUI_SetFont(&LCD_DisFont);
    GUI_SetTextMode(GUI_TEXTMODE_NORMAL); 
		if(FirGuiDemoHis!=0)
		{
		 FirGuiDemoHis=0; 
		 GUI_Clear();
		 GUIDEMO_Automotive();
		}
		LCD_GEC400FirPageLightDis();
		LCD_GEC400_FirPagMdis();
   }
  if(MainPageCon!=LCDAlarmListPg)LCD_GEC400_AlarmStaDis();//��������ʾ
 } 
#endif
/*---------------------------------------------------------------------------
��������: void LCD_GEC400_MainPgDis(void) 
��������:     �׽�����ʾ   
----------------------------------------------------------------------------*/ 
#if(LCD_GEC400EN==1)
void LCD_GEC400_MainPgDis(void)
 {
	 if((DES_STARTSUCC_CONDITION==0)||(DES_STARTSUCC_CONDITION==3))//0���Ÿ��� 3���Ŵ�����+��ѹ
	 {
		 if(MainPageCon>(PageShowSpd.PageNums-1)){MainPageCon=0;}//�Ӷ�˵��л����ٲ˵�
	   LCD_GEC400_MainPgDis_STARTSUCC_CONDITIONVol();
	 }
   else                   //1������    2���Ŵ�����+����    4������+��ѹ  5���Ŵ�����+����+��ѹ
	 {
     LCD_GEC400_MainPgDis_STARTSUCC_CONDITION03();
	 }
 }
#endif 
/*---------------------------------------------------------------------------
��������: void LCD_GEC400_MenuPgDis(void) 
��������:     �˵�ѡ�������ʾ   
----------------------------------------------------------------------------*/ 
#if(LCD_GEC400EN==1)
 void LCD_GEC400_MenuPgHeadDis(void)
 {
   u8 i,menui;
   const  char *D_str;	 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisParmSetCl);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   if(ParmMainPageConHis==0xff)
   {ParmMainPageConHis=0x00;
   	GUI_Clear();   //����
   }
   menui=MAINMENU.MENUNUM;
   for(i=0;i<menui;i++)
   { 	 
	  if(Language_select==LCD_LanguageEnglish)      D_str=(const char *)MAINMENU.SubPtr[i]->ptNameStrEN;
	  else if(Language_select==LCD_LanguageChinese) D_str=(const char *)MAINMENU.SubPtr[i]->ptNameStrCN;
	  else {} //��չ��������
  	  if(i==ParmMainPageCon)GUI_SetBkColor(LCD_MenuSelColor);
	  else					        GUI_SetBkColor(LCD_DisBKColor);
	  GUI_DispStringAt(D_str,2,i*34+5);
   }
 } 
 void LCD_GEC400_MenuPgDis(void)
 {
   //if(ParmMainPageConHis==ParmMainPageCon)
   //{
   //  ParmMainPageConHis=ParmMainPageCon;
	 LCD_GEC400_MenuPgHeadDis();
   //}
 }
#endif

 
/*---------------------------------------------------------------------------
��������: void LCD_GEC400_PassWordPgDis(void) 
��������:  ˢ������������ʾ����    
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)
  
void LCD_GEC400_PassWordInNumDis(void)
{
  u8 i;
  u8 Pwstr[4];
  Pwstr[0]=Password_Value>>12&0x0f; Pwstr[1]=Password_Value>>8&0x0f;
  Pwstr[2]=Password_Value>>4&0x0f;  Pwstr[3]=Password_Value&0x0f;

  GUI_SetFont(&GUI_Font32_ASCII);
  for(i=0;i<4;i++)
  {
   if(i==PassWordCursorMove)
   {
	  GUI_SetBkColor(LCD_MenuSelColor);
    GUI_DispDecAt(Pwstr[i],148+(16*i),3*34+5,1);
   }
   else
   {
		GUI_SetBkColor(LCD_DisBKColor);
	  GUI_DispStringAt("*",148+(16*i),3*34+5);
   }
  }
}

void LCD_GEC400_PassWordHeadDis(void)
{
   u8 i;
   const  char *D_str;	 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisParmSetCl);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   GUI_Clear();   //����
   for(i=0;i<2;i++)
   { 
	  if(i==0)
	  {
	   if(Language_select==LCD_LanguageEnglish)      D_str="Input PassWord:";
	   else if(Language_select==LCD_LanguageChinese) D_str="���������:";
	   else {} //��չ��������
	   GUI_DispStringAt(D_str,2,2*34+5);
	  }	  								 
   }												
}

void LCD_GEC400_PassWordPgDis(void)
{
  if(PassWordCursorMoveHis==0xff)
  {	PassWordCursorMoveHis=0x00;
	  LCD_GEC400_PassWordHeadDis();	   
  }
  LCD_GEC400_PassWordInNumDis();
}

#endif

/*---------------------------------------------------------------------------
��������: void LCD_GEC400_MsgSelPgDis(void) 
��������:  ˢ�¿�������Ϣ��ʾ����    
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)

void LCD_GEC400_MsgSelHeadDis(void)
{
   u8 i,menui;
   const  char *D_str;	 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisParmSetCl);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   GUI_Clear();   //����
   menui=SysMsgPageShow.Pages[ParmMsgSubPageCon]->Disable;
   for(i=0;i<menui;i++)
   { 
	  if(Language_select==LCD_LanguageEnglish)      D_str=(const char *)SysMsgPageShow.Pages[ParmMsgSubPageCon]->Pagept[menui*0+i];
	  else if(Language_select==LCD_LanguageChinese) D_str=(const char *)SysMsgPageShow.Pages[ParmMsgSubPageCon]->Pagept[menui*1+i];
	  else {} //��չ��������
	  GUI_DispStringAt(D_str,2,i*34+5);
   }
}
void LCD_GEC400_MsgSelPgDis(void)
{
  if(ParmMsgSubPageConHis!=ParmMsgSubPageCon)
   {
     ParmMsgSubPageConHis=ParmMsgSubPageCon;
	 LCD_GEC400_MsgSelHeadDis();
   }
}
#endif

/*---------------------------------------------------------------------------
��������: void LCD_GEC400_MsgSelPgDis(void) 
��������:  ˢ�¿�������Ϣ��ʾ����    
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)

void LCD_GEC400_LagSelHeadDis(void)
{
   u8 i,menui;
   const  char *D_str;	 
   
   menui=MAINMENU.SubPtr[ParmMainPageCon]->MaxItem+1;
   for(i=0;i<menui;i++)
   { 
	  if(Language_select==LCD_LanguageEnglish)      D_str=(const char *)MAINMENU.SubPtr[ParmMainPageCon]->SubItems[i]->NameStrEN;
	  else if(Language_select==LCD_LanguageChinese) D_str=(const char *)MAINMENU.SubPtr[ParmMainPageCon]->SubItems[i]->NameStrCN;
	  else {} //��չ��������
  	  if(i==(ParmLaguSubPageCon+1))GUI_SetBkColor(LCD_MenuSelColor);
	  else				   	       GUI_SetBkColor(LCD_DisBKColor);
	  GUI_DispStringAt(D_str,2,i*34+5);
   }
}

void LCD_GEC400_LagSelPgDis(void)
{
 if(ParmLaguSubPageConHis==0xff)
 { ParmLaguSubPageConHis=0;
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisParmSetCl);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   GUI_Clear();   //����
  }  
  LCD_GEC400_LagSelHeadDis();
}
#endif
/*---------------------------------------------------------------------------
��������: void LCD_GEC400_ParmSetPgDis(void) 
��������:  ˢ�²���������ʾ����    
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)

INT16U LCD_GEC4xx_ChagePosDate(INT16U ParmChage,INT08U POS)
{
   u8 i;
   u8 Distr[4];
   u16 DisNum,ReturnNum=0;
   DisNum=ParmChage;
   for(i=0;i<4;i++)				  //���ݷ���
   {	 
	  Distr[3-i]=DisNum%10;
	  DisNum /= 10 ;
   }
   switch(POS)                  //С���㴦��
   {
  	 case 1:
	   ReturnNum=Distr[1]*1000+Distr[2]*100+Distr[3];
	  break;   
   }
  return ReturnNum;
}
void LCD_GEC4xx_DisOldParmNumSet(u16 x, u16 y,u16 DisNumP,u8 NumPos)
{  
   u8 i;
   u8 Distr[4];
   u16 DisNum;float F_DisNum;
   DisNum=DisNumP;
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisParmSetCl);
   GUI_SetFont(&LCD_DisFont);
   for(i=0;i<4;i++)				  //���ݷ���
   {	 
	  Distr[3-i]=DisNum%10;
	  DisNum /= 10 ;
   }
   switch(NumPos)                  //С���㴦��
   {
  	case 0:for(i=0;i<4;i++)GUI_DispDecAt(Distr[i],x+(12*i),y,1);
		 break;
	  case 1: 
		 // F_DisNum=(float)(DisNumP)/(float)10.0;
     // GUI_GotoXY(x,y);		
		 // GUI_DispFloatFix(F_DisNum,4,1);
      Distr[0]=Distr[1];Distr[1]=Distr[2];
		  for(i=0;i<4;i++)
		  {
			  if(i!=2)GUI_DispDecAt(Distr[i],x+(12*i),y,1);
		    else    GUI_DispStringAt(".",x+(12*i),y);
		  }
	   break;
	  default:break;
   }
}
void LCD_GEC4xx_DisAdjParmNumSet(u16 x, u16 y,u16 DisNumP,u8 NumPos,u8 curre)
{  
   u8 i;
   u8 Distr[4];
   u16 DisNum;
   DisNum=DisNumP;
   for(i=0;i<4;i++)				  //���ݷ���
   {	 
	  Distr[3-i]=DisNum%10;
	  DisNum /= 10 ;
   }
   switch(NumPos)                  //С���㴦��
   {
  	 case 0:                       //�޸���С��������
	    for(i=0;i<4;i++)
	    {
			  if((curre-1)==i) GUI_SetBkColor(LCD_MenuSelColor);
			  else             GUI_SetBkColor(LCD_DisBKColor);
			  GUI_DispDecAt(Distr[i],x+(12*i),y,1);
	    }
	   break;
	  case 1:                      //�޸�С��������
		 //for(i=0;i<2;i++){Distr[i]=Distr[i+1];}
		 for(i=0;i<4;i++)
		 {
	     if((curre-1)==i) GUI_SetBkColor(LCD_MenuSelColor);
			 else             GUI_SetBkColor(LCD_DisBKColor);
			 if(i!=2)GUI_DispDecAt(Distr[i],x+(12*i),y,1);
		 }
	   break;
	  default:break;
   }
}

void LCD_GEC4xx_DisSubParmSpecial(u8 ParmOffBuf,u8 ParmPosBuf,u8 DisLine) 
{
   u8 ParmOffset,ParmPosSet,SpMeunBuf;
   u8 SpOffSet,Spbuf;
   const  char *D_str;	 
	
   ParmOffset=ParmOffBuf;                      //��ǰֵ�������е�ƫ���� 
   ChSpPosFlag=ParmPosSet=ParmPosBuf&0x03;     //����С����λ��
   ChSpBuf=SpMeunBuf=(ParmPosBuf&0x7c)>>2;     //�жϵ�ǰ�����Ƿ�Ϊ�˵�����
	 if(SpMeunBuf==0)                            //�趨ֵ��ʾ
	 {
      if(ParmSetCurDisFlag==Password0x0318)    //����ȷ�ϼ��޸�����
      {if(!LCDOctParmFlag)
	     {LCDOctParmFlag=1;SystemParmModify=FLASHDATABASE[ParmOffset].Sbyte;//�����ϴ�����
		     if(ChSpPosFlag!=0)SystemParmModify=LCD_GEC4xx_ChagePosDate(SystemParmModify,ChSpPosFlag);
	      }   
		    LCD_GEC4xx_DisAdjParmNumSet(115,DisLine*35+2,SystemParmModify,ChSpPosFlag,SetCursorMove);//��ʾ��ǰ�����޸�����
      }                                                                           
	    else {LCDOctParmFlag=0;LCD_GEC4xx_DisOldParmNumSet(115,DisLine*35+2,0,ParmPosSet);} 
    }
	 else
	 {
       Spbuf=(MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ScaleStr[0])-0x30;    
       SpOffSet=(MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ScaleStr[1])-0x30; //�������������ָ��λ��
       ChSpOffSet=SpOffSet=Spbuf*10+SpOffSet;                                            
       Spbuf=(SpManyShow.Pages[SpOffSet]->Disable)*Language_select;                             //�����������
       GUI_SetBkColor(LCD_DisBKColor);
       GUI_SetColor(LCD_DisParmSetCl);
       GUI_SetFont(&LCD_DisFont);
		 
	     if((!LCDBitParmFlag)&&(KeyMenulevel==0x06)){LCDBitParmFlag=1;SpSetCursorMove=FLASHDATABASE[ParmOffset].Sbyte;} //�����ϴ����������
       if(ParmSetCurDisFlag==Password0x0318)
       { GUI_SetBkColor(LCD_MenuSelColor);                                                                            //�޸��������
         D_str=(const char *)SpManyShow.Pages[SpOffSet]->Pagept[SpSetCursorMove+Spbuf];
       } 
       else                                                                           
       {GUI_SetBkColor(LCD_DisBKColor);
		    D_str=(const char *)SpManyShow.Pages[SpOffSet]->Pagept[FLASHDATABASE[ParmOffset].Sbyte+Spbuf]; //ȡ��������ʾ����
       }
       GUI_DispStringAt(D_str,2,DisLine*34+5);
   }
}

void LCD_GEC400_DisParmSet()
{  
  u8 ParmOffset,ParmPosSet;   
  ParmOffset=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParmSetHeadnum; //��ǰֵ�������е�ƫ���� 
  ParmPosSet=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->Mode;           //��ǰֵ��С����λ��
  LCD_GEC4xx_DisOldParmNumSet(115,2*35+5,FLASHDATABASE[ParmOffset].Sbyte,ParmPosSet&0x03);//��ʾ�ϴ��趨������ 
  LCD_GEC4xx_DisSubParmSpecial(ParmOffset,ParmPosSet,3);    //��ʾ�������õĵ�ǰֵ
}
  
void LCD_GEC400_ParmSetHeadDis(void)
{
   u8 i,menui;
   u8 DisNumBuf[GECx_DisCon],j;
   const  char *D_str;	 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisParmSetCl);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   GUI_Clear();   //���� 
   for(i=0;i<4;i++)
   { 
	  if(Language_select==LCD_LanguageEnglish)
	  {
	   switch(i)
	   {
	    case 0:D_str=(const char *)MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->NameStrEN; break;
	   	case 1:D_str=(const char *)MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParamStrEN;break;
	   	case 2:D_str="Current:"; break;
		  case 3:D_str="SetValue:  "; break;
	   }
	  }     
	  else if(Language_select==LCD_LanguageChinese)
	  {
	   switch(i)
	   {
	    case 0:D_str=(const char *)MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->NameStrCN; break;
	   	case 1:D_str=(const char *)MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParamStrCN;break;
	   	case 2:D_str="��ǰֵ:"; break;
		  case 3:D_str="�趨ֵ:     "; break;
	   }
	  } 
	  else {} //��չ��������
	  if(i==0)//���²˵����
	  {	
	   menui=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParmSetHeadnum+1;
		 if(COMMON_MODEL==MODEL410)menui-=M410DelMainBusPg;
		 for(j=0;j<GECx_DisCon;j++) *(DisNumBuf+j)=*(D_str+j);
		 DisNumBuf[0]=menui/10%10+'0';DisNumBuf[1]=menui%10+'0';
		 D_str=(const char *)DisNumBuf;
	  }
	  GUI_DispStringAt(D_str,2,i*34+5);
   }
}

void LCD_GEC400_ParmSetPgDis(void)
{
  if(ParmSubPageConHis!=ParmSubPageCon)
  {
  	ParmSubPageConHis=ParmSubPageCon;
	  LCD_GEC400_ParmSetHeadDis();	
  }
  LCD_GEC400_DisParmSet();

}

#endif


#if(LCD_GEC400EN==1)
/*-----------------------------------------------------------------------
�������ƣ�LCDMapAdjDatafromRAMDATABASE() 
���������� ������0x636�޸Ĳ���У��ʱӳ��ʵʱ��������

--------------------------------------------------------------------------*/
void LCDMapAdjDatafromRAMDATABASE(void)
{
  AdjMapVOLTAGEA2     = VOLTAGEA2;       //�е�A��ѹУ��  
  AdjMapVOLTAGEB2     = VOLTAGEB2;       //�е�B��ѹУ��  
  AdjMapVOLTAGEC2     = VOLTAGEC2;       //�е�C��ѹУ��  
  AdjMapVOLTAGEA1     = VOLTAGEA1;       //����A��ѹУ��  
  AdjMapVOLTAGEB1     = VOLTAGEB1;       //����B��ѹУ��  
  AdjMapVOLTAGEC1     = VOLTAGEC1;       //����C��ѹУ��  
  AdjMapCURRENTA      = CURRENTA/10;     //A�����У�� 
  AdjMapCURRENTB      = CURRENTB/10;     //B�����У�� 
  AdjMapCURRENTC      = CURRENTC/10;     //C�����У�� 
  
  AdjMapWATERTEMP     = VALUER1;         //ˮ����У��      
  AdjMapOILPRESSURE   = VALUER0;         //����ѹ��У��       
  AdjMapFUEL          = VALUER2;         //ȼ��λУ�� 
  AdjMapCustomAog	  = VALUER3;		 //�Զ���ģ����У�� 
       
  AdjMapPowerVoltage  = PowerVoltage;    //��ص�ѹУ��   
  AdjMapChargerVoltage= ChargerVoltage;  //����D+       
  AdjMapPhaseCOS      = PhaseCOS;        //���繦������   
}
/*-----------------------------------------------------------------------
�������ƣ�LCD_GEC4xx_DisAdjParmSet() 
���������� 

--------------------------------------------------------------------------*/

void LCD_GEC4xx_DisAdjParmSet(u8 ParmOffBuf,u8 ParmPosBuf,u8 DisLine) 
{
   u8 ParmOffset,ParmPosSet,SpMeunBuf;
   u8 SpOffSet,Spbuf;
   static unsigned char LCDRdAdjOldParmFlg;
   const  char *D_str;	 
	
   ParmOffset=ParmOffBuf;                     //��ǰֵ�������е�ƫ���� 
   AdjSpPosFlag=ParmPosSet=ParmPosBuf&0x03;   //����С����λ��
   AdjChMenuSpBuf=SpMeunBuf=(ParmPosBuf&0x7c)>>2; //�жϵ�ǰ�����Ƿ�Ϊ�˵�����
	if(SpMeunBuf==0)                          //�趨ֵ��ʾ
	{
     if(AdjParmSetCurDisFlag==Password0x0636)    //����ȷ�ϼ��޸�����
     {if(!LCDRdAdjOldParmFlg)
	    {LCDRdAdjOldParmFlg=1;AdjParmModify=AdjDataMapBuf[pArmAdjPageCon].Sbyte;//�����ϴ�����
		   if(AdjSpPosFlag!=0)AdjParmModify=LCD_GEC4xx_ChagePosDate(AdjParmModify,AdjSpPosFlag);
		  } 
		   LCD_GEC4xx_DisAdjParmNumSet(115,DisLine*35+2,AdjParmModify,AdjSpPosFlag,AdjSetCursorMove); //��ʾ��ǰ����У�������޸�����
     }                                                             	             
	   else{ LCDRdAdjOldParmFlg=0;LCD_GEC4xx_DisOldParmNumSet(115,DisLine*35+2,0,ParmPosSet);} 
    }
	else
	 {
       Spbuf=(SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ScaleStr[0])-0x30;    
       SpOffSet=(SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ScaleStr[1])-0x30; //�������������ָ��λ��
       SpAdjOffSet=SpOffSet=Spbuf*10+SpOffSet;                                            
       Spbuf=(SpAdjSubPgShow.Pages[SpOffSet]->Disable)*Language_select;                             //�����������
       GUI_SetBkColor(LCD_DisBKColor);
       GUI_SetColor(LCD_DisColor);
       GUI_SetFont(&LCD_DisFont);
	// if((!LCDBitParmFlag)&&(KeyMenulevel==0x06)){LCDBitParmFlag=1;SpSetCursorMove=FLASHDATABASE[ParmOffset].Sbyte;} //�����ϴ����������
       if(AdjParmSetCurDisFlag==Password0x0636)
       { GUI_SetBkColor(LCD_MenuSelColor);                                                                            //�޸��������
         D_str=(const char *)SpAdjSubPgShow.Pages[SpOffSet]->Pagept[SpAdjSetCurMove+Spbuf];
       } 
       else                                                                           
       {GUI_SetBkColor(LCD_DisBKColor);
		    D_str=(const char *)SpAdjSubPgShow.Pages[SpOffSet]->Pagept[FLASHDATABASE[ParmOffset].Sbyte+Spbuf]; //ȡ��������ʾ����
       }
       GUI_DispStringAt(D_str,2,DisLine*34+5);
     }
}

/*---------------------------------------------------------------------------
��������: void LCD_GEC400_DisAdjParmSet(void) 
��������:  ˢ�²���У����ʾ����    
----------------------------------------------------------------------------*/
void LCD_GEC400_DisAdjParmSet()
{  
  u8 AdjParmOffset,AdjParmPosSet;   
  AdjParmOffset=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParmSetHeadnum; //��ǰֵ�������е�ƫ���� 
  AdjParmPosSet=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->Mode;           //��ǰֵ��С����λ��
  LCDMapAdjDatafromRAMDATABASE();											 //����У��ʱӳ��ʵʱ��������
  LCD_GEC4xx_DisOldParmNumSet(115,2*35+5,AdjDataMapBuf[pArmAdjPageCon].Sbyte,AdjParmPosSet&0x03); 
  LCD_GEC4xx_DisAdjParmSet(AdjParmOffset,AdjParmPosSet,3);    //��ʾ����У�����õ�ֵ
}

/*---------------------------------------------------------------------------
��������: void LCD_GEC400_AdjParmSetHeadDis(void) 
��������:  ��ʾ����У��ͷ����   
----------------------------------------------------------------------------*/  
void LCD_GEC400_AdjParmSetHeadDis(void)
{
   u8 i,menui;
   u8 DisNumBuf[GECx_DisCon],j;
   const  char *D_str;	 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisParmSetCl);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   GUI_Clear();   //���� 
   for(i=0;i<4;i++)
   { 
	  if(Language_select==LCD_LanguageEnglish)
	  {
	   switch(i)								   
	   {
	    case 0:D_str=(const char *)SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->NameStrEN;  break;
	   	case 1:D_str=(const char *)SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParamStrEN; break;
	   	case 2:D_str="Current:"; break;
		  case 3:D_str="SetValue:  "; break;
	   }
	  }     
	  else if(Language_select==LCD_LanguageChinese)
	  {
	   switch(i)
	   {
	    case 0:D_str=(const char *)SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->NameStrCN; break;
	   	case 1:D_str=(const char *)SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParamStrCN;break;
	   	case 2:D_str="��ǰֵ:"; break;
		  case 3:D_str="�趨ֵ:     "; break;
	   }
	  } 
	  else {} //��չ��������
	  if(i==0)//���²˵����
	  {
	   menui=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParmSetHeadnum+1;
		 if(COMMON_MODEL==MODEL410)menui=menui-sParmSetnum_ForMainPage-1-M410DelAdjMBusPg; //
		 for(j=0;j<GECx_DisCon;j++) *(DisNumBuf+j)=*(D_str+j); //��ԭ��ʾ�ַ������ƺ��޸���ʾ���
		 DisNumBuf[0]=menui/10%10+'0';DisNumBuf[1]=menui%10+'0';
		 D_str=(const char *)DisNumBuf;
	  }
	  GUI_DispStringAt(D_str,2,i*34+5);
   }
}

void LCD_GEC400_AdjSetPgDis(void)
{
  if(pArmAdjPageConHis!=pArmAdjPageCon)
  {
  	pArmAdjPageConHis=pArmAdjPageCon;
	  LCD_GEC400_AdjParmSetHeadDis();	
   }
  LCD_GEC400_DisAdjParmSet();
}

#endif

#if(LCD_GEC400EN==1)
/*-----------------------------------------------------------------------
�������ƣ� LCD_GEC400_SenCurvePgDis() 
���������� �Զ��崫�������߲���������ʾҳ��

--------------------------------------------------------------------------*/
#define cURVEDisCon 27
void LCD_GEC400_CurveParmSetHeadDis(void)
{
   u8 i;
   u8 DisNumBuf[cURVEDisCon],j;
   u8  Ctr=0;
   u16 DisV=0;
   const  char *D_str;	 
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisParmSetCl);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   GUI_Clear();   //���� 
 for(i=0;i<7;i++)
 {if(Language_select==LCD_LanguageEnglish)
	{switch(i)								   
	 {
	  case 0:D_str=(const char *)MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurveHeadStr->cpParamStrEN; break;
	  case 1:D_str=(const char *)MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurveHeadStr->cpParamScope; break;
	  case 2:D_str="                         "; break;
	 }			   
	}     
	else if(Language_select==LCD_LanguageChinese)
	{switch(i)
	 {
	  case 0:D_str=(const char *)MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurveHeadStr->cpParamStrCN; break;
	  case 1:D_str=(const char *)MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurveHeadStr->cpParamScope; break;
	  case 2:D_str="                         "; break;
	 }
	} 
	else {} //��չ��������
	if(i>2)//���²˵����
	{
    for(j=0;j<cURVEDisCon;j++) *(DisNumBuf+j)=*(D_str+j); //��ԭ��ʾ�ַ������ƺ��޸���ʾ���
	  DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2]->ParmSetHeadnum].Sbyte;
	  for(j=4;j;j--){DisNumBuf[j-1+2]=DisV%10+'0';DisV/=10;} //����ֵ
	  DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2+CurveDotCtr]->ParmSetHeadnum].Sbyte;
	  for(j=4;j;j--){DisNumBuf[j-1+7]=DisV%10+'0';DisV/=10;} //��Ӧ����
	  
	  DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2+1]->ParmSetHeadnum].Sbyte;
	  for(j=4;j;j--){DisNumBuf[j-1+16]=DisV%10+'0';DisV/=10;} //����ֵ
	  DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2+CurveDotCtr+1]->ParmSetHeadnum].Sbyte;
	  for(j=4;j;j--){DisNumBuf[j-1+21]=DisV%10+'0';DisV/=10;} //��Ӧ����

	  DisNumBuf[ 0]=(Ctr*2)%10+'1';DisNumBuf[ 1]=':';DisNumBuf[ 6]='|'; 
	  DisNumBuf[14]=(Ctr*2)%10+'2';DisNumBuf[15]=':';DisNumBuf[20]='|';

	  D_str=(const char *)DisNumBuf;
	  Ctr++;
	 }
	 GUI_DispStringAt(D_str,2,i*34+5);
  }
}
void LCD_GEC400_CurveSetNumDis(void)
{
  u8 i,x;
  u8 Custr[4];
  u8  Ctr=0;
  u16 DisV=0;
  Ctr =SetCurveConter/16;
  switch(SetCurveConter/4)	//�����ϴε�����
  {case 0:
   case 4:
   case 8:
   case 12:x=25;
    DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2]->ParmSetHeadnum].Sbyte;
   break;
   case 1:
   case 5:
   case 9:
   case 13:x=80;
    DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2+CurveDotCtr]->ParmSetHeadnum].Sbyte;
   break;
   case 2:
   case 6:
   case 10:
   case 14:x=179;
    DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2+1]->ParmSetHeadnum].Sbyte;
   break;
   case 3:
   case 7:
   case 11:
   case 15:x=234;
    DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2+CurveDotCtr+1]->ParmSetHeadnum].Sbyte;
   break;
  }
  Ctr =SetCurveConter/4+1;	 //���´��޸�����

  if(CurveCtrHis!=Ctr)
  {CurveCtrHis=Ctr;
   CurveParmModify1=DisV;
  }
  DisV=CurveParmModify1;
  Custr[3]=DisV%10;DisV/=10; Custr[2]=DisV%10;DisV/=10;
  Custr[1]=DisV%10;DisV/=10; Custr[0]=DisV%10;DisV/=10;
  
  Ctr =SetCurveConter/16;
  for(i=0;i<4;i++)			 //�޸�������Ӱ��ʾ
  {
   if(i==(SetCurveConter%4))
   {GUI_SetBkColor(LCD_MenuSelColor);
    GUI_DispDecAt(Custr[i],11*i+x,(Ctr+3)*34+5,1);
   }
   else
   {GUI_SetBkColor(LCD_DisBKColor);
	  GUI_DispDecAt(Custr[i],11*i+x,(Ctr+3)*34+5,1);
   }
  }
  CurveMidfyBuf[SetCurveConter/4]=CurveParmModify1;	//���޸ĵ����ݷ��뻺����������
}

void LCD_GEC400_SenCurvePgDis(void)
{
  if(SetCurveParmPgHis!=0xff)
  {
   SetCurveParmPgHis=0xff;
   LCD_GEC400_CurveParmSetHeadDis();
  }
  LCD_GEC400_CurveSetNumDis();
}

#endif

/*---------------------------------------------------------------------------
��������: void LCD_RefreshDisPage(void) 
��������:  ˢ����ʾ����    
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)
void LCD_RefreshDisPage(void)
{
  switch(KeyMenulevel)
  {
   case 0:LCD_GEC400_MainPgDis();    break;	//����ҳ����ʾ
	 case 1:LCD_GEC400_MenuPgDis();    break;	//�˵�ѡ����ʾҳ��
	 case 2:LCD_GEC400_PassWordPgDis();break;	//����������ʾҳ��
	 case 3:LCD_GEC400_MsgSelPgDis();  break;	//��������Ϣѡ����ʾҳ��
	 case 4:LCD_GEC400_LagSelPgDis();  break;	//����������ѡ����ʾҳ��
	 case 5:
	 case 6:LCD_GEC400_ParmSetPgDis(); break;	//����������������ʾҳ��
	 case 7:
	 case 8:LCD_GEC400_AdjSetPgDis();  break;	//����������У��������ʾҳ��
   case 9:LCD_GEC400_SenCurvePgDis();break;	//�Զ��崫�������߲���������ʾҳ��
  } 
}
#endif

/*---------------------------------------------------------------------------
��������: void LCDMeunKeyCal(void) 
��������:      
----------------------------------------------------------------------------*/ 
#if(LCD_GEC400EN==1)

/*---------------------------------------------------------------------
????: void LCDSubParmChange_KeyPAGEDW()
????: ???0318?????????????
????:
????:
----------------------------------------------------------------------- */
void LCDSubParmChange_KeyPAGEDW()
{
  INT08U i,parmbuf[4];
  INT16U ParmValue;
  if(ChSpBuf==0)                                                     //??????
  { ParmValue=SystemParmModify;
    for(i=0;i<4;i++){parmbuf[3-i]=ParmValue%10;ParmValue/=10;}
	switch(SetCursorMove)                                           //????
    {
     case 1:if(parmbuf[0]>0)parmbuf[0]-=1; else parmbuf[0]=9;break;
	 case 2:if(parmbuf[1]>0)parmbuf[1]-=1; else parmbuf[1]=9;break;
     case 3:if(parmbuf[2]>0)parmbuf[2]-=1; else parmbuf[2]=9;break;
     case 4:if(parmbuf[3]>0)parmbuf[3]-=1; else parmbuf[3]=9;break;
     default:break;
    }
	SystemParmModify=parmbuf[0]*1000+parmbuf[1]*100+parmbuf[2]*10+parmbuf[3];
  } 
  else                                                             //??????
  {
   if(SpSetCursorMove>0)SpSetCursorMove--;
   else SpSetCursorMove=SpManyShow.Pages[ChSpOffSet]->Disable-1;
  }
}
/*---------------------------------------------------------------------
????: void LCDSubParmChange_KeyPAGEDW()
????: ???0318 ?????????????
????:
????:
-----------------------------------------------------------------------*/

 void LCDSubParmChange_KeyPAGEUP()
 {
  INT08U i,parmbuf[4];
  INT16U ParmValue;
  if(ChSpBuf==0)                                                    //??????
  { ParmValue=SystemParmModify;
    for(i=0;i<4;i++){parmbuf[3-i]=ParmValue%10;ParmValue/=10;}
	switch(SetCursorMove)                                           //????
    {
	 case 1:if(parmbuf[0]<9)parmbuf[0]+=1; else parmbuf[0]=0;break;
	 case 2:if(parmbuf[1]<9)parmbuf[1]+=1; else parmbuf[1]=0;break;
	 case 3:if(parmbuf[2]<9)parmbuf[2]+=1; else parmbuf[2]=0;break;
	 case 4:if(parmbuf[3]<9)parmbuf[3]+=1; else parmbuf[3]=0;break;
	 default:break;
	}
	SystemParmModify=parmbuf[0]*1000+parmbuf[1]*100+parmbuf[2]*10+parmbuf[3];
   } 
  else
  {
   if(SpSetCursorMove<SpManyShow.Pages[ChSpOffSet]->Disable-1) SpSetCursorMove++;
   else SpSetCursorMove=0;
  }
}

void LCDAdjParmChange_KeyPAGEDW()
{
  INT08U i,parmbuf[4];
  INT16U ParmValue;
  if(AdjChMenuSpBuf==0)                                                     //??????
  { ParmValue=AdjParmModify;
    for(i=0;i<4;i++){parmbuf[3-i]=ParmValue%10;ParmValue/=10;}
	switch(AdjSetCursorMove)                                           //????
    {
     case 1:if(parmbuf[0]>0)parmbuf[0]-=1; else parmbuf[0]=9;break;
	 case 2:if(parmbuf[1]>0)parmbuf[1]-=1; else parmbuf[1]=9;break;
     case 3:if(parmbuf[2]>0)parmbuf[2]-=1; else parmbuf[2]=9;break;
     case 4:if(parmbuf[3]>0)parmbuf[3]-=1; else parmbuf[3]=9;break;
     default:break;
    }
	AdjParmModify=parmbuf[0]*1000+parmbuf[1]*100+parmbuf[2]*10+parmbuf[3];
  } 
  else                                                         //����У���е��������ѡ��
  {
   if(SpAdjSetCurMove>0)SpAdjSetCurMove--;
   else SpAdjSetCurMove=SpAdjSubPgShow.Pages[SpAdjOffSet]->Disable-1;
  }
}

 void LCDAdjParmChange_KeyPAGEUP()
 {
  INT08U i,parmbuf[4];
  INT16U ParmValue;
  if(AdjChMenuSpBuf==0)                                                     //??????
  { ParmValue=AdjParmModify;
    for(i=0;i<4;i++){parmbuf[3-i]=ParmValue%10;ParmValue/=10;}
	switch(AdjSetCursorMove)                                           //????
    {
	 case 1:if(parmbuf[0]<9)parmbuf[0]+=1; else parmbuf[0]=0;break;
	 case 2:if(parmbuf[1]<9)parmbuf[1]+=1; else parmbuf[1]=0;break;
	 case 3:if(parmbuf[2]<9)parmbuf[2]+=1; else parmbuf[2]=0;break;
	 case 4:if(parmbuf[3]<9)parmbuf[3]+=1; else parmbuf[3]=0;break;
	 default:break;
	}
	AdjParmModify=parmbuf[0]*1000+parmbuf[1]*100+parmbuf[2]*10+parmbuf[3];
  } 
  else											 //����У���е��������ѡ��
  {
   if(SpAdjSetCurMove<SpAdjSubPgShow.Pages[SpAdjOffSet]->Disable-1) SpAdjSetCurMove++;
   else SpAdjSetCurMove=0;
  }
}

/*---------------------------------------------------------------------
�������ƣ�  void LCDCureParmChange_KeyPAGEUP()
���������� �Զ��������޸Ĳ������ð��¼��޸�����
���������
���������
-----------------------------------------------------------------------*/
 void LCDCureParmChange_KeyPAGEUP() 
 {
  INT08U i,parmbuf[4];
  INT16U ParmValue;
   ParmValue=CurveParmModify1;
	for(i=0;i<4;i++){parmbuf[3-i]=ParmValue%10;ParmValue/=10;}
	switch(SetCurveConter%4)                                   //�Զ������߲����޸�
    {
	 case 0:if(parmbuf[0]<9)parmbuf[0]+=1; else parmbuf[0]=0;break;
	 case 1:if(parmbuf[1]<9)parmbuf[1]+=1; else parmbuf[1]=0;break;
	 case 2:if(parmbuf[2]<9)parmbuf[2]+=1; else parmbuf[2]=0;break;
	 case 3:if(parmbuf[3]<9)parmbuf[3]+=1; else parmbuf[3]=0;break;
	 default:break;
	}
	CurveParmModify1=parmbuf[0]*1000+parmbuf[1]*100+parmbuf[2]*10+parmbuf[3];
 }
/*---------------------------------------------------------------------
�������ƣ�  void LCDCureParmChange_KeyPAGEDONW()
���������� �Զ��������޸Ĳ������ð��¼��޸�����
���������
���������
-----------------------------------------------------------------------*/
 void LCDCureParmChange_KeyPAGEDONW() 
 {
  INT08U i,parmbuf[4];
  INT16U ParmValue;
  ParmValue=CurveParmModify1;
	for(i=0;i<4;i++){parmbuf[3-i]=ParmValue%10;ParmValue/=10;}
	switch(SetCurveConter%4)                                   //�Զ������߲����޸�
  {
	 case 0:if(parmbuf[0]>0)parmbuf[0]-=1; else parmbuf[0]=9;break;
	 case 1:if(parmbuf[1]>0)parmbuf[1]-=1; else parmbuf[1]=9;break;
	 case 2:if(parmbuf[2]>0)parmbuf[2]-=1; else parmbuf[2]=9;break;
	 case 3:if(parmbuf[3]>0)parmbuf[3]-=1; else parmbuf[3]=9;break;
	 default:break;
	}
	CurveParmModify1=parmbuf[0]*1000+parmbuf[1]*100+parmbuf[2]*10+parmbuf[3];
 }


INT08U LCDMeunKeyCal(void) 
{  INT08U LishBuf;                                              //��ҳ������ʾ��������
   if(KeyMenulevel==0x00)                       
    {
      if((DES_STARTSUCC_CONDITION==0)||(DES_STARTSUCC_CONDITION==3))//0���Ÿ��� 3���Ŵ�����+��ѹ
			{				
			 MeunCon=PageShowSpd.PageNums;
			}else                  //1������    2���Ŵ�����+����    4������+��ѹ  5���Ŵ�����+����+��ѹ
			{
			 MeunCon=PageShow.PageNums;
			}
      switch(Btn_buf)
      {         
        case MASK_BTN_PAGEUP:
              if(MainPageCon>0)MainPageCon--;
              else             MainPageCon=MeunCon-1;
             break;
         case MASK_BTN_PAGEDW:
              if(MainPageCon<MeunCon-1)MainPageCon++;
              else                     MainPageCon=0;
             break;
        case MASK_BTN_PGTURN:
             KeyMenulevel=0x01;
			       ParmMainPageConHis=0xff;  //ˢ����ʾ�˵�ѡ��ҳ��  
        break;
       
        case MASK_BTN_STOP:                  //��λȡ������
             KeyMenulevel=0;
             MainPageCon=0;
            
        break;                              
        default:break;
      }
      return 0;
    }
	if(KeyMenulevel==0x01)                   //��ʾ�˵�ѡ��ҳ��    
    {
       MeunCon=MAINMENU.MENUNUM;
       switch(Btn_buf)
        {         
         case MASK_BTN_PAGEUP:
              if(ParmMainPageCon>0)ParmMainPageCon--;
              else                 ParmMainPageCon=MeunCon-1;
             break;
         case MASK_BTN_PAGEDW:
              if(ParmMainPageCon<MeunCon-1)ParmMainPageCon++;
              else                         ParmMainPageCon=0;
             break;
         case MASK_BTN_PGTURN:
			       if(ParmMainPageCon==0)     {KeyMenulevel=0x02;PassWordCursorMoveHis=0xff;}//��������˵�
			       else if(ParmMainPageCon==1){KeyMenulevel=0x03;ParmMsgSubPageConHis=0xff; }//��������Ϣ
			       else if(ParmMainPageCon==2){KeyMenulevel=0x04;ParmLaguSubPageConHis=0xff;}//����ѡ��
			       else{} 
            break;
       
         case MASK_BTN_STOP:                 //��λȡ������
             KeyMenulevel=0;
             ParmMainPageCon=0;
			       MainPageConHis=0xff;           //ˢ�·��ز�������ҳ��
        	   AlarmflagHis=0xff;			    //��ǰҳ�洦�ڱ����б�ʱˢ����ʾ
			       FirGuiDemoHis=0xff;			//��ǰҳ�洦�ڲ�����ҳ��
		        break;                              
         default:break;
       }
      return 1;
    }
	if(KeyMenulevel==0x02)                  //��������˵�               
    {
      switch(Btn_buf)
      {         
        case MASK_BTN_PAGEDW:
             switch(PassWordCursorMove)                                           //����ֵ�ļ�
             {
              case 0:if((Password_Value&0xf000)>0x0000)Password_Value-=0x1000; else Password_Value|=0x9000;break;
              case 1:if((Password_Value&0x0f00)>0x0000)Password_Value-=0x0100; else Password_Value|=0x0900;break;
              case 2:if((Password_Value&0x00f0)>0x0000)Password_Value-=0x0010; else Password_Value|=0x0090;break;
              case 3:if((Password_Value&0x000f)>0x0000)Password_Value-=0x0001; else Password_Value|=0x0009;break;
              default:break;
             }
             break;
         case MASK_BTN_PAGEUP:
              switch(PassWordCursorMove)                                          //����ֵ�ļ�
              {
               case 0:if((Password_Value&0xf000)>=0x9000)Password_Value&=0x0fff; else Password_Value+=0x1000;break;
               case 1:if((Password_Value&0x0f00)>=0x0900)Password_Value&=0xf0ff; else Password_Value+=0x0100;break;
               case 2:if((Password_Value&0x00f0)>=0x0090)Password_Value&=0xff0f; else Password_Value+=0x0010;break;
               case 3:if((Password_Value&0x000f)>=0x0009)Password_Value&=0xfff0; else Password_Value+=0x0001;break;
               default:break;
              } 
             break;
        case MASK_BTN_PGTURN:
              PassWordCursorMove+=1;		   //�ƶ�������
              if(PassWordCursorMove>=4)
              { 
							 switch(Password_Value)
							 {
								case Password0x0318:
									 if(COMMON_MODEL==MODEL410){ParmSubPageCon=M410DelMainBusPg;}
									 KeyMenulevel=5; 		    //�����������
									 PaswordTypeToDisFlag=Password0x0318;
									 ParmSubPageConHis=0xff;//ˢ����ʾ��������ҳ��
								  break;
								case Password0x1234:
								  break;
								case Password0x0636:
									 if(COMMON_MODEL==MODEL410){pArmAdjPageCon=M410DelAdjMBusPg;}
									 KeyMenulevel=7; 		    //�������У��
									 pArmAdjPageConHis=0xff;	//���²���У����ʾͷ
								  break;
								 default:
									 KeyMenulevel=1;
									 ParmMainPageConHis=0xff;    //ˢ����ʾ�˵�ѡ��ҳ��  
								 break;
							 }
							PassWordCursorMove=0;
							Password_Value=0;
             }
             break;
       
        case MASK_BTN_STOP:
             KeyMenulevel=1;
             ParmMainPageConHis=0xff;         //ˢ����ʾ�˵�ѡ��ҳ�� 
			       PassWordCursorMove=0;
             Password_Value=0;
             PaswordTypeToDisFlag=0;				
            break;                              
        default:break;
      }
      return 2;
    }
	if(KeyMenulevel==0x03)//��������Ϣ                       
    {
      MeunCon=MAINMENU.SubPtr[ParmMainPageCon]->MaxItem;
      switch(Btn_buf)
      {         
        case MASK_BTN_PAGEUP:
              if(ParmMsgSubPageCon>0)ParmMsgSubPageCon--;
              else                   ParmMsgSubPageCon=MeunCon-1;
             break;
        case MASK_BTN_PAGEDW:
              if(ParmMsgSubPageCon<MeunCon-1)ParmMsgSubPageCon++;
              else                           ParmMsgSubPageCon=0;
             break;
        case MASK_BTN_PGTURN:
        case MASK_BTN_STOP:                
             KeyMenulevel=1;
             ParmMsgSubPageCon=0;
			       ParmMainPageConHis=0xff;  //ˢ����ʾ�˵�ѡ��ҳ�� 
        break;                              
        default:break;
      }
      return 3;
    }
	if(KeyMenulevel==0x04)//����ѡ��                       
    {
      MeunCon=MAINMENU.SubPtr[ParmMainPageCon]->MaxItem;
      switch(Btn_buf)
      {         
        case MASK_BTN_PAGEUP:
              if(ParmLaguSubPageCon>0)ParmLaguSubPageCon--;
              else                    ParmLaguSubPageCon=MeunCon-1;
             break;
        case MASK_BTN_PAGEDW:
              if(ParmLaguSubPageCon<MeunCon-1)ParmLaguSubPageCon++;
              else                            ParmLaguSubPageCon=0;
             break;
        case MASK_BTN_PGTURN:
             Language_select=ParmLaguSubPageCon;
			      // FLASH_SaveModifParm();	//�������Բ���
				     FLASH_SavepParm();
          //break;
       
        case MASK_BTN_STOP:                 
             KeyMenulevel=1;
             ParmLaguSubPageCon=0;
			       ParmMainPageConHis=0xff;  //ˢ����ʾ�˵�ѡ��ҳ�� 
             
        break;                              
        default:break;
      }
      return 4;
    }
	if(KeyMenulevel==0x05)    //�����������        
    { 
	   MeunCon=MAINMENU.SubPtr[ParmMainPageCon]->MaxItem;
     switch(Btn_buf)
     {         
		  case MASK_BTN_PAGEUP:
			 if(COMMON_MODEL==MODEL410)
			 {if(ParmSubPageCon>M410DelMainBusPg)ParmSubPageCon--;
        else                               ParmSubPageCon=MeunCon-1; 
			 }
			 else
			 {if(ParmSubPageCon>0)ParmSubPageCon--;
        else                ParmSubPageCon=MeunCon-1; 
			 }
      break;
      case MASK_BTN_PAGEDW:
		   if(COMMON_MODEL==MODEL410)
			 {if(ParmSubPageCon<MeunCon-1)ParmSubPageCon++;
        else                        ParmSubPageCon=M410DelMainBusPg;
			 }
       else
			 {if(ParmSubPageCon<MeunCon-1)ParmSubPageCon++;
        else                        ParmSubPageCon=0;
			 }
      break;
	 	
      case MASK_BTN_PGTURN:
           KeyMenulevel=0x06;
			     LcdKeySaveParm();
      break;
      case MASK_BTN_STOP:                
           KeyMenulevel=1;
			     ParmMainPageConHis=0xff;  //ˢ����ʾ�˵�ѡ��ҳ�� 
           ParmSubPageCon=0;
      break;                              
      default:break;
     }
     return 5;
    }
	if(KeyMenulevel==0x06)    //����ȷ�ϼ��޸Ĳ���          
    {
      switch(Btn_buf)
      {         
        case MASK_BTN_PAGEUP:
             if(ParmSetCurDisFlag==Password0x0318){LCDSubParmChange_KeyPAGEUP();}
			//if(ParmSetCurDisFlag==Password0x0636){LCDAdjustParmChange_KeyPAGEUP();}
             break;
        case MASK_BTN_PAGEDW:
					   if(ParmSetCurDisFlag==Password0x0318){LCDSubParmChange_KeyPAGEDW();}
			//if(ParmSetCurDisFlag==Password0x0636){LCDAdjustParmChange_KeyPAGEDW();}
             break;
        case MASK_BTN_PGTURN:
              LcdKeySaveParm();                                    //������ͨ���ò���
              if((ChSpBuf!=0)&&(ParmSetCurDisFlag==Password0x0318))//���������������
              {
			         LishBuf=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParmSetHeadnum; //���������ݿ��е�ƫ����
               FLASHDATABASE[LishBuf].Sbyte=SpSetCursorMove;
               //FLASH_SaveModifParm();                             //�����������ò���
							 FLASH_SavepParm();
               ChSpPosFlag=0;ParmSetCurDisFlag=0; LCDBitParmFlag=0;
			         KeyMenulevel=0x05; 
              }
			        if(sPn_CUSTOM_SENSOR_TYPE==(MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParmSetHeadnum))//�ж��Ƿ�Ϊ�Զ���������
              {KeyMenulevel=0x09;         //�����Զ�������
			         SetCurveParmPgHis=0; 		  //ˢ���Զ���������ʾ
			        }   
        break;
       
        case MASK_BTN_STOP:                
             KeyMenulevel=0x01;
			       ParmMainPageConHis=0xff;  //ˢ����ʾ�˵�ѡ��ҳ�� 
               ParmSubPageCon=0;
               ParmSetCurDisFlag=0;
               SetCursorMove=0;                 //�����޸Ĺ�긴λ
               SpSetCursorMove=0;               //��λ����˵����
               SystemParmModify=0;              //����ϴ��޸ĵĲ�����ʱֵ
               ChSpPosFlag=0,ChAdjustPosFlag=0;
               PassWordCursorMove=0;            //��λ������
               PaswordTypeToDisFlag=0;          //��λ������
        break;                              
        default:break;
      }
      return 6;
    }

	if(KeyMenulevel==0x07)    // ����У��          
    {
      MeunCon=SUBMENU_AdjustPARM.MaxItem;
      switch(Btn_buf)
      {         
        case MASK_BTN_PAGEUP:		  
		         if(COMMON_MODEL==MODEL410)
			       {if(pArmAdjPageCon>M410DelAdjMBusPg)pArmAdjPageCon--;
              else                               pArmAdjPageCon=MeunCon-1;
			       }
			       else 
			       {if(pArmAdjPageCon>0)pArmAdjPageCon--;
              else                pArmAdjPageCon=MeunCon-1;
			       } 
            break;
        case MASK_BTN_PAGEDW:
		         if(COMMON_MODEL==MODEL410)
		         {if(pArmAdjPageCon<MeunCon-1)pArmAdjPageCon++;
              else                        pArmAdjPageCon=M410DelAdjMBusPg;
		         }
			       else
			       {if(pArmAdjPageCon<MeunCon-1)pArmAdjPageCon++;
              else                        pArmAdjPageCon=0;
		         }
            break;
        case MASK_BTN_PGTURN:
          	 AdjParmSetCurDisFlag=Password0x0636;
			       KeyMenulevel=0x08;		 //����У������޸�
		    //	 pArmAdjPageConHis=0xff;	//���²���У����ʾͷ
			       LcdKeySaveAdjParm();
        break;

        case MASK_BTN_STOP:                
          	 KeyMenulevel=1;
			       ParmMainPageConHis=0xff;  //ˢ����ʾ�˵�ѡ��ҳ�� 
             PaswordTypeToDisFlag=0;
			       AdjParmSetCurDisFlag=0;
			       pArmAdjPageCon=0;
        break;                              
        default:break;
      }
      return 7;
    }
	if(KeyMenulevel==0x08)          //����ȷ�����޸�У�����       
    {
      switch(Btn_buf)
      {         
        case MASK_BTN_PAGEUP:
              LCDAdjParmChange_KeyPAGEUP();
             break;
         case MASK_BTN_PAGEDW:
				      LCDAdjParmChange_KeyPAGEDW();
             break;
        case MASK_BTN_PGTURN:
          	 LcdKeySaveAdjParm();  //�������У��ֵ
			       if((AdjChMenuSpBuf!=0)&&(AdjParmSetCurDisFlag==Password0x0636)) //�����������У�����
             {
							LishBuf=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParmSetHeadnum; //���������ݿ��е�ƫ����
							FLASHDATABASE[LishBuf].Sbyte=SpAdjSetCurMove;
              //FLASH_SaveModifParm();
							FLASH_SavesAdjParm();
		          LishBuf=sPa_RestFactory-sParmSetnum_ForMainPage-1;
			        if((pArmAdjPageCon==LishBuf)&&(SpAdjSetCurMove==1))DBRestore_Factory_settings();//ѡ���˻ָ�������������  
			        AdjParmSetCurDisFlag=0;
			        SpAdjSetCurMove=0;
			        KeyMenulevel=0x07;     
			       }
        break;
       
        case MASK_BTN_STOP:                
          	 KeyMenulevel=1;
			       ParmMainPageConHis=0xff;  //ˢ����ʾ�˵�ѡ��ҳ�� 
             PaswordTypeToDisFlag=0;
			       AdjParmSetCurDisFlag=0;
             AdjSetCursorMove=0;
			       AdjSpPosFlag=0;
			       AdjParmModify=0;
			       pArmAdjPageCon=0;
        break;                              
        default:break;
      }
      return 8;
    } 
	
	if(KeyMenulevel==0x09)    //�����Զ�����������            
    { 
       switch(Btn_buf)
       {         
         case MASK_BTN_PAGEDW: 
              LCDCureParmChange_KeyPAGEDONW();
         break;
         case MASK_BTN_PAGEUP:
              LCDCureParmChange_KeyPAGEUP();
         break;
         case MASK_BTN_PGTURN:
              SetCurveConter++;
			        if(SetCurveConter>=64)
			        {SetCurveConter=0;
               LCDSaveCurveParmSet();         //�����Զ������߲���
               ParmSubPageConHis=0xff;       //������ʾ
               CurveCtrHis=0xff;
			         KeyMenulevel=0x05;
               SetCurveConter=0;
			         CurveParmModify1=0;
				     CurveCtrHis = 0;
			        }
         break;
         case MASK_BTN_STOP:
               KeyMenulevel=0x05;
			         ParmSubPageConHis=0xff;       //������ʾ
               CurveCtrHis=0xff;
               SetCurveConter=0;
			         CurveParmModify1=0;
		       CurveCtrHis = 0;
         break;
         default:break;  
       }
      return 9;   
    }  
	
	if(KeyMenulevel==0x0a)    //           
    {
     
      switch(Btn_buf)
      {         
        case MASK_BTN_PAGEUP:
             
             break;
         case MASK_BTN_PAGEDW:
              
             break;
        case MASK_BTN_PGTURN:
          
        break;
       
        case MASK_BTN_STOP:                
          
            
        break;                              
        default:break;
      }
      return 10;
    }                 
  return 0;
}
#endif
/*---------------------------------------------------------------------------
��������: void LCDCheckDBKeyValue(void) 
��������:       ͨ�����ݿ��жϰ���
�������: XIOģ��ɼ�����ֵ�����DB���ݿ��У�LCD��DB���ݿ��а�����Ϣת��Ϊ
          LCDģ��Ĳ˵�������Ϣ��  
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)
void LCDCheckDBKeyValue(void)            //ͨ�����ݿ��жϰ���
{
  if((F_ENTER_STOP_LCD!=0)||(F_ENTER_ENTER!=0)||(F_ENTER_UP!=0)||(F_ENTER_DOWN!=0))
  {
     if(F_ENTER_STOP_LCD==1)Btn_buf=MASK_BTN_STOP;
     if(F_ENTER_ENTER==1)   Btn_buf=MASK_BTN_PGTURN;
     if(F_ENTER_UP==1)      Btn_buf=MASK_BTN_PAGEUP;
     if(F_ENTER_DOWN==1)    Btn_buf=MASK_BTN_PAGEDW;
   
  //   LCDLitBackLight();                   //�а������¿������⡣ 
     LCDMeunKeyCal();                    //�а������¸��²˵���־λ�� 
     F_ENTER_STOP_LCD=0;
     F_ENTER_ENTER=0;
     F_ENTER_UP=0;
     F_ENTER_DOWN=0;
     Btn_buf=0;
  }
}
#endif

/*---------------------------------------------------------------------------
��������: void LCDCombClearAccumuDate(void) 
��������:  �����������������
----------------------------------------------------------------------------*/
void LCDCombClearAccumuDate(void)
{
    EPROM_STARTNUM = 0;
	  RUNNINGHOUR    = 0;
	  RUNNINGMINUTE  = 0;
	  RUNNINGSEC     = 0;
	  KWHH           = 0;
	  KWHL           = 0;
	  MSAVE_EPROMSTARTNUM=EPROM_STARTNUM; 	  //�����𶯴���
    MSAVE_RUNNINGHOUR  =RUNNINGHOUR   ; 	  //����������ʱ
    MSAVE_RUNNINGMINUTE=RUNNINGMINUTE ; 	  //���������۷� 
    MSAVE_RUNNINGSEC   =RUNNINGSEC    ; 	  //���������� 
    MSAVE_KWHH         =KWHH          ; 	  //����ǧ��ʱ��λ
    MSAVE_KWHL         =KWHL          ;	    //����ǧ��ʱ��λ
	  FLASH_SaveOtherParm();
	  KeyMenulevel=0;
    ParmMainPageCon=0;
	  MainPageConHis=0xff;                    //ˢ�·��ز�������ҳ��
    AlarmflagHis=0xff;			                //��ǰҳ�洦�ڱ����б�ʱˢ����ʾ
	  FirGuiDemoHis=0xff;			                //��ǰҳ�洦�ڲ�����ҳ��
}

/*---------------------------------------------------------------------------
��������: void LCDCheckChangeHardTmode(void) 
��������:  �л���Ӳ������ģʽ
----------------------------------------------------------------------------*/
void LCDCheckChangeHardTmode(void)
{
	//@@@@@@@@@@@ZC
// if((KeyMenulevel==0x02)&&(Password_Value==0x1000)) 
// {
//   if((K_ENTER)&&(K_UP)&&(K_DOWN))
//    {HardTestModeEn=0;
//		}
// }
// if((KeyMenulevel==0x02)&&(Password_Value==0x9890)) 
// { 
//	 if((K_UP)&&(K_DOWN)) LCDCombClearAccumuDate();
// }
}
/*---------------------------------------------------------------------------
��������: void LCD_GEC400_App(void) 
��������:  Һ����ʾ����    
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)
void LCD_GEC400_App(void)
{ 
	//@@@@@@@@@@@@ZC
	 if(HardTestModeEn)
   {
		 LCDCheckDBKeyValue();     //ͨ�����ݿ��жϰ���
     LCD_RefreshDisPage();
	   LCDCheckChangeHardTmode();//�л�������ģʽ
	 } else
  {
		 HardTestLoop();          //Ӳ�����Գ���
	}
}
 
#endif

void LCD_GEC4XX_InitJ1939CAN(void)
{
  if((KeyMenulevel==6)&&(ParmSubPageCon==sPn_GENS_TYPE))
  {
    CAN_J1939Public_Init();
  }
}

#if (Boot_animation == 1)
void Boot_Intro(void)
{
 int xCenter = LCD_GET_XSIZE() / 2;
 int y;
 char acText[50] = "Version of GEC4000: ";
  
  strcat(acText, GUI_GetVersionString());
  
  GUI_SetBkColor(GUI_RED);
  GUI_SetColor(GUI_WHITE);
  GUI_Clear();
  GUI_SetFont(&GUI_Font24B_1);
  GUI_DispStringHCenterAt("GEN CONTROLER", xCenter, y= 15);
    
  GUI_SetFont(&GUI_Font13HB_1);
  GUI_SetColor(GUI_WHITE);
  GUI_DispStringHCenterAt(acText, xCenter, y += 26);
  
  GUI_DrawBitmap(&bmMicriumLogo, (LCD_GET_XSIZE() - bmMicriumLogo.XSize) / 2, y += 16);

  GUI_Line(0, y+45, 320-1, y+45, GUI_WHITE);
  GUI_Line(0, y+46, 320-1, y+46, GUI_WHITE);
  
  GUI_SetColor(GUI_BLUE);
	GUI_SetFont(GUI_FONT_SUIT);
  GUI_DispStringHCenterAt("������������", (LCD_GET_XSIZE() / 2)+5, y += 50);	  

  GUI_SetFont(&GUI_Font13HB_1);
  GUI_SetColor(GUI_WHITE);
  GUI_DispStringHCenterAt("www.fortrust.cn", LCD_GET_XSIZE()/ 2, y += 36);
	Delay_100ms(10);
}
#endif

void GUIDEMO_Automotive(void) 
{
   unsigned char i;
   GUI_DrawBitmap(&bmGen1,    5, 5); 
   GUI_DrawBitmap(&bmFac1,  260, 5);
   GUI_DrawBitmap(&bmOilTP1,170,95);
   for(i=0;i<4;i++)
   {
    GUI_Line( 58,69+i, 86,69+i,GUI_WHITE);
    GUI_Line(232,69+i,260,69+i,GUI_WHITE);
    GUI_Line(120,69+i,200,69+i,GUI_WHITE);
   }
   GUI_DispStringAt("    kW", 90,20);      GUI_DispStringAt("    RPM", 175, 20);
   GUI_DispStringAt("L-N        V ",5, 90);GUI_DispStringAt("    Bar",230, 90);
   GUI_DispStringAt("Amp        A ",5,115);GUI_DispStringAt("    �� ",230,115);
   GUI_DispStringAt("F          Hz",5,140);GUI_DispStringAt("     V ",230,140);
   for(i=0;i<33;i++)
   {
    GUI_Line(1,170+i,319,170+i,GUI_WHITE);
   }
   for(i=0;i<33;i++)
   {
    GUI_Line(1,206+i,319,206+i,LCD_AlarmColor);
   }
   GUI_SetBkColor(GUI_WHITE);
   GUI_SetColor(0X0000);
   if(!Language_select)GUI_DispStringAt("   Stop      Manual    Auto ",4,174);//Ӣ��
   else                GUI_DispStringAt("   ͣ��      �ֶ�      �Զ� ",4,174);
}

void GUIDEMO_AutomotiveSpd(void) 
{
   unsigned char i;
   GUI_DrawBitmap(&bmGen1,    5, 5); 
   GUI_DrawBitmap(&bmFac1,  260, 5);
   GUI_DrawBitmap(&bmOilTP1,  5,95);
	 GUI_DrawBitmap(&bmspdlc, 175,95);
   for(i=0;i<4;i++)
   {
    GUI_Line( 58,69+i, 86,69+i,GUI_WHITE);
    GUI_Line(232,69+i,260,69+i,GUI_WHITE);
    GUI_Line(120,69+i,200,69+i,GUI_WHITE);
   }
  // GUI_DispStringAt("    RPM", 170, 20);
   GUI_DispStringAt("    Bar", 75, 90);GUI_DispStringAt("    RPM",230, 90);
   GUI_DispStringAt("    �� ", 75,115);GUI_DispStringAt("     % ",230,115);
   GUI_DispStringAt("     V ", 75,140);GUI_DispStringAt("     V ",230,140);
   for(i=0;i<33;i++)
   {
    GUI_Line(1,170+i,319,170+i,GUI_WHITE);
   }
   for(i=0;i<33;i++)
   {
    GUI_Line(1,206+i,319,206+i,LCD_AlarmColor);
   }
   GUI_SetBkColor(GUI_WHITE);
   GUI_SetColor(0X0000);
   if(!Language_select)GUI_DispStringAt("   Stop      Manual    Auto ",4,174);//Ӣ��
   else                GUI_DispStringAt("   ͣ��      �ֶ�      �Զ� ",4,174);
}

void GUI_DrawOpen(unsigned char Dtype)
{if(Dtype==0)GUI_DrawBitmap(&bmopen, 200,58);
 else        GUI_DrawBitmap(&bmclose,200,58); 	
}


///********************The End *****************/
