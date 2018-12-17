//#include "ALL_Includes.h"//包含所需的头文件
//#include "..\GUIinc\GUI.h"
//#include "..\uCGUIDemo\GUIDEMO.h"
#include "TYPCortex.h"


typedef unsigned char INT08U;
//typedef unsigned int INT16U;

INT16U Btn_buf;                                        //定义按键返回值
INT08U KeyMenulevel=0;								                 //菜单级别
INT08U MainPageCon=0,MainPageConHis=0xff;              //首屏显示测量参数，翻屏记录
INT08U ParmMainPageCon=0,ParmMainPageConHis=0xff;      //参数设置主菜单，翻屏记录
INT08U ParmSubPageCon=0,ParmSubPageConHis=0xff;        //参数设置子菜单，翻屏记录
INT08U ParmMsgSubPageCon=0,ParmMsgSubPageConHis=0xff;  //控制器信息菜单翻页记录
INT08U ParmLaguSubPageCon=0,ParmLaguSubPageConHis=0xff;//控制器语言选择菜单翻页记录
INT08U PassWordCursorMove=0,PassWordCursorMoveHis=0xff;//密码移动光标
INT16U Password_Value=0;                               //密码输入数据
INT16U PaswordTypeToDisFlag=0;                         //输入不同密码记录
INT08U MeunCon=0;
INT16U SystemParmModify=0;             //参数修改数据
INT08U SetCursorMove=0;                //参数设置光标位置
INT16U ParmSetCurDisFlag=0;            //设置参数光标阴影
INT08U ChSpBuf,ChSpOffSet;
INT08U ChSpPosFlag;                    
INT08U ChAdjustPosFlag;                //记录修改参数校验参数中小数点跳位               
INT16U SpSetCursorMove;                //参数修改中特殊选项光标位置

INT08U pArmAdjPageCon=0,pArmAdjPageConHis=0xff;       //参数校验页面计数
INT16U AdjParmModify;								  //参数校验修改
INT08U AdjSpPosFlag,AdjSetCursorMove;				  //参数校验光标
INT08U AdjChMenuSpBuf;				                  //参数校验是否为特殊菜单
INT16U AdjParmSetCurDisFlag=0;                        //参数校验设置光标阴影
INT08U SpAdjSetCurMove=0,SpAdjOffSet=0;				  //参数校验特殊菜单光标
unsigned char AlarmflagHis=0xff;				      //报警列表历史值
INT08U FirGuiDemoHis=0xff;                            //测量首页面记录
INT08U SetCurveParmPgHis=0xff;                        //修改历史自定义曲线参数设置
INT08U SetCurveConter=0;                              //修改自定义曲线光标计数
INT16U CurveParmModify1=0,CurveParmModify2=0;         //自定义曲线参数修改数据缓存
INT16U CurveParmModifyBuf1=0,CurveParmModifyBuf2=0;   //自定义曲线参数修改数据缓存
INT16U CurveMidfyBuf[CurveDotCtr*2];				  //修改自定义曲线数据临时缓存
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
函数名称：   KeyCalRestFunAtLCD(void)
功能描述：   故障复位功能
----------------------------------------------------------------------------*/
void KeyCalRestFunAtLCD(void) 
 {
  if(COMMON_MODEL==MODEL410)
    {
      if(KeyMenulevel==0)
      {
       if((DES_STARTSUCC_CONDITION==0)||(DES_STARTSUCC_CONDITION==3))//磁传感器  磁传感器+油压
       {if(MainPageCon==3)  F_ENTER_STOP_CAL=1;    
       } 
       else
       { if(MainPageCon==0) F_ENTER_STOP_CAL=1;    
       }
      }
    }
   
   if(COMMON_MODEL==MODEL420) //修改选择型号为4020、启动成功条件为 0或者3无法停机问题
   {
     if((KeyMenulevel==0)&&(MainPageCon==0)) F_ENTER_STOP_CAL=1; 
   }
 }
/*----------------------------------------------------------------------------
函数名称：   INT16S LCDTempUnitswitch(INT16U SwitchValue)
功能描述：  显示温度单位转换
输入参数：   華氏溫度與攝氏溫度的換算換算公式: 
             (華氏溫度-32)*5/9=攝氏溫度 
             华氏温度=(摄氏温度*9/5)+32度 
输出参数：攝氏溫度  摄氏温度c ，将其转化为华氏温度f ，转换公式为：f=c*9/5+32 
----------------------------------------------------------------------------*/
INT16S LCDTempUnitswitch(INT16S SwitchValue)
{
  INT16S ReturnSValue;
  if(SwitchValue!=0)
  {
   //SwitchValue=(SwitchValue+5)/10;        //原数据缩小10 现四舍五入
   ReturnSValue= (SwitchValue*9/5+32)*10; //计算华氏温度并放大10倍
   ReturnSValue=(ReturnSValue+5)/10;      //四舍五入后还原
   return  ReturnSValue;                  //返回的结果放大了10倍
  } 
  else  return  0;                        //温度为0时
}
/*----------------------------------------------------------------------------
函数名称：   INT16S LCDPSIBarUnitswitch(INT16U SwitchValue,INT08U PressType)
功能描述：  显示压力单位转换
输入参数：  PressType=0   pa转换kpa 
            PressType=1   PSI转换 
            PressType=2   Bar转换 
  1兆帕(MPa)=145磅/平方英寸(psi)=10.2千克/平方厘米 (kg/cm2)=10巴(bar)=9.8大气压(atm)
输出参数：  
----------------------------------------------------------------------------*/
INT16S LCDPSIBarUnitswitch(INT16U SwitchValue,INT08U PressType)
{
   float SValueBuf=0;
   INT16S ReturnSValue;
  // SValueBuf=(float)SwitchValue/10;            //将原来放大的数据还原
    switch(PressType)
    {
      case 0:         //计算Pa转换为Kpa
         //  SValueBuf=SValueBuf/10;
         //  ReturnSValue=((INT16S)SValueBuf+5)/10;
         ReturnSValue=SwitchValue;
        break;
      case 1:         //计算PSI
           SValueBuf=(float)SwitchValue*145;
           SValueBuf=(SValueBuf/10+5)/10;
           ReturnSValue=(INT16S)SValueBuf;
        break;
      case 2:         //计算Bar
          // ReturnSValue=((INT16S)SValueBuf+5)/10;
          ReturnSValue=SwitchValue;
        break;
      default:break;  
    }
   return  ReturnSValue;                       //返回的结果放大了10倍 
}
 
//************************************************************************************
//函数名称：  INT08U LCDCalAllAlarmStation(INT08U ArryN)        
//功能描述：  计算数据库中状态量
//输入参数：  数据库状态数组序号
//输出参数：  显示数据数组位置和位状态
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
      case 0: ReturnData=DELVAL_FUELOUTPUT;/* GUI_DispDecSpace(DELVAL_FUELOUTPUT, 3);*/  break;//燃油输出延时 
      case 1: ReturnData=DELVAL_PRESTART;  /* GUI_DispDecSpace(DELVAL_PRESTART,   3);*/  break;//开机预热延时 
      case 2: ReturnData=DELVAL_CRANK;     /* GUI_DispDecSpace(DELVAL_CRANK,      3);*/  break;//正在启动 
      case 3:                              /*                                        */  break;  
      case 4: ReturnData=DELVAL_STARTIDLE; /* GUI_DispDecSpace(DELVAL_STARTIDLE,  3);*/  break;//起动怠速延时 
      case 5: ReturnData=DELVAL_WARM;      /* GUI_DispDecSpace(DELVAL_WARM,       3);*/  break;//暖机延时 
      case 6: ReturnData=DELVAL_SAFE;      /* GUI_DispDecSpace(DELVAL_SAFE,       3);*/  break;//安全运行延时        秒
      case 7: ReturnData=DELVAL_START;     /* GUI_DispDecSpace(DELVAL_START,      3);*/  break;//起动延时
	  case 8 :ReturnData=DELVAL_STOP;      /* GUI_DispDecSpace(DELVAL_STOP,       3);*/  break;//停机延时 
      case 9 :  break;
      case 10:  break;
      case 11:  break;
      case 12:ReturnData=DELVAL_TRANSCB;   /* GUI_DispDecSpace(DELVAL_TRANSCB,    3);*/  break;//开关转换延时 
      case 13:ReturnData=DELVAL_COOLING;   /* GUI_DispDecSpace(DELVAL_COOLING,    3);*/  break;//停机散热延时 
      case 14:ReturnData=DELVAL_STOPIDLE;  /* GUI_DispDecSpace(DELVAL_STOPIDLE,   3);*/  break;//停机怠速延时 
      case 15:ReturnData=DELVAL_STOPCONFIRM;/* GUI_DispDecSpace(DELVAL_STOPCONFIRM,3);*/  break;//等待停稳延时 
              
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
	  case 8 : ReturnData=DELVAL_STARTINT;     /*GUI_DispDecSpace(DELVAL_STARTINT,     3);*/  break; //启动间隔延时        秒
      case 9 : ReturnData=DELVAL_MAINSNORMAL;  /*GUI_DispDecSpace(DELVAL_MAINSNORMAL,  3);*/  break; //市电正常鉴别延时        秒
      case 10: ReturnData=DELVAL_MAINSABNORMAL;/*GUI_DispDecSpace(DELVAL_MAINSABNORMAL,3);*/  break; //市电异常鉴别延时        秒
      case 11: ReturnData=DELVAL_STOPOUTPUT;   /*GUI_DispDecSpace(DELVAL_STOPOUTPUT,   3);*/  break; //得电停机延时        秒                                                       
      case 12: ReturnData=DELVAL_AMFSTART;     /*GUI_DispDecSpace(DELVAL_AMFSTART,     3);*/  break; //失电自启动延时       秒
      case 13: ReturnData=DELVAL_AMFSTOP;      /*GUI_DispDecSpace(DELVAL_AMFSTOP,      3);*/  break; //得电自停机延时      秒
      case 14: ReturnData=DELVAL_OVERCURRENT;  /*GUI_DispDecSpace(DELVAL_OVERCURRENT,  3);*/  break; //发电过流停机延时
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
//函数名称：  INT08U LCDDisCalAlarmAdress()       
//功能描述：  报警显示界面
//输入参数：
//输出参数：  
//************************************************************************************
INT08U LCDDisCalAlarmAdress() 
{
  if(LCDCalAllAlarmStation(GensStopAlarm1.Sbyte, 0))    return 1;      //报警停机1
  if(LCDCalAllAlarmStation(GensStopAlarm2.Sbyte, 1))    return 2;      //报警停机2
  
  if(LCDCalAllAlarmStation(GensRunStation1.Sbyte,5))    return 5;      //通用状态1
  if(LCDCalAllAlarmStation(GensRunStation2.Sbyte,6))    return 6;      //通用状态2
  if(LCDCalAllAlarmStation(GensRunStation3.Sbyte,7))    return 7;      //通用状态3
  
  if(LCDCalAllAlarmStation(GensWarningAlarm1.Sbyte,2))  return 3;      //警告1
  if(LCDCalAllAlarmStation(GensWarningAlarm2.Sbyte,3))  return 4;      //警告2
  
  ReturnAlmStatype=0xff;      //程序执行到这里说明没有任何显示状态
  return 0xff;
}
/*-----------------------------------------------------------------------
函数名称: void LCDCopyDBAlarmDataTOMapMemery(void)  
功能描述: //从DB数据库中复制报警数据到映射内存
输入参数: 说明:数据库已经定于好不方便改动，为了让lcd显示报警归类
输出参数:      重新映射报警数据。
----------------------------------------------------------------------- */
void LCDCopyDBAlarmDataTOMapMemery(void)  //从DB数据库中复制报警数据到映射内存
{
     //报警停机 47
  GensStopAlarm1.BITS.BIT0=F_STOP_EM;                                //紧急停机报警          
  if(!F_DI_TEMPHI_STOP) GensStopAlarm1.BITS.BIT1=F_STOP_TEMP_HI;     //温度高报警停机        
  else                  GensStopAlarm1.BITS.BIT1=0;
  if(!F_DI_OILP_STOP)   GensStopAlarm1.BITS.BIT2=F_STOP_OP_LO;       //低油压报警停机        
  else                  GensStopAlarm1.BITS.BIT2=0;
  GensStopAlarm1.BITS.BIT3=F_STOP_SPEED_HI;                          //发电超速报警停机      
  GensStopAlarm1.BITS.BIT4=F_STOP_SPEED_LO;                          //发电欠速报警停机      
  GensStopAlarm1.BITS.BIT5=F_STOP_SPEED_LOST;                        //速度信号丢失报警停机 
  GensStopAlarm1.BITS.BIT6=F_STOP_VOLT_HI;                           //发电过压报警停机      
  GensStopAlarm1.BITS.BIT7=F_STOP_VOLT_LO;                           //发电欠压报警停机      
  GensStopAlarm1.BITS.BIT8=F_STOP_CURRENT_HI;                        //发电过流报警停机      
  GensStopAlarm1.BITS.BIT9=F_STOP_START_FAIL;                        //起动失败报警停机      
  GensStopAlarm1.BITS.BITA=F_STOP_FREQ_HI;                           //发电超频报警停机      
  GensStopAlarm1.BITS.BITB=F_STOP_FREQ_LO;                           //发电欠频报警停机      
  GensStopAlarm1.BITS.BITC=F_STOP_NOFREQ ;                           //无发电报警停机        
  if(!F_DI_FUELLOW_STOP) GensStopAlarm1.BITS.BITD=F_STOP_FUEL_LO ;   //燃油位低报警停机      
  else                   GensStopAlarm1.BITS.BITD=0 ;
  if(!F_DI_WATERLOW_STOP)GensStopAlarm1.BITS.BITE=F_STOP_WATER_LO;   //水位低报警停机        
  else                   GensStopAlarm1.BITS.BITE=0;
 
 // GensStopAlarm1.BITS.BITF=;                                          15
  
      
      //报警停机 48
  GensStopAlarm2.BITS.BIT0=F_DI_TEMPHI_STOP;                           //温度高报警停机   (IN)
  GensStopAlarm2.BITS.BIT1=F_DI_OILP_STOP;                             //低油压报警停机   (IN)
  GensStopAlarm2.BITS.BIT2=F_DI_FUELLOW_STOP;                          //燃油位低报警停机 (IN) 
  GensStopAlarm2.BITS.BIT3=F_DI_WATERLOW_STOP;                         //水位低报警停机   (IN)  
  GensStopAlarm2.BITS.BIT4=F_STOP_STOP_FAIL;                           //停机失败警告   
  GensStopAlarm2.BITS.BIT5=F_STOP_EXTERN ;                             //外部停机报警输入
  GensStopAlarm2.BITS.BIT6=F_STOP_TEMP_LOST;                           //温度传感器断线停机
  GensStopAlarm2.BITS.BIT7=F_STOP_OP_LOST;                             //压力传感器断线停机                     
     //警告 49
  GensWarningAlarm1.BITS.BIT0=F_WARN_SPEEDLOST;                        //速度信号丢失警告  
  GensWarningAlarm1.BITS.BIT1=F_WARN_CURRENT_HI;                       //发电过流警告      
//  GensWarningAlarm1.BITS.BIT2=;                   
  if(!F_DI_FUELLOW_WRN)GensWarningAlarm1.BITS.BIT3=F_WARN_FUEL_LO;     //燃油位低警告      
  else                 GensWarningAlarm1.BITS.BIT3=0;
  GensWarningAlarm1.BITS.BIT4=F_WARN_CHARGE_LO;                        //充电失败警告      
  GensWarningAlarm1.BITS.BIT5=F_WARN_BATT_LO;                          //电池欠压警告      
  GensWarningAlarm1.BITS.BIT6=F_WARN_BATT_HI;                          //电池过压警告      
  GensWarningAlarm1.BITS.BIT7=F_MAINS_VOLT_LO;                         //市电欠压警告      
  GensWarningAlarm1.BITS.BIT8=F_MAINS_VOLT_HI;                         //市电过压警告      
  if(!F_DI_WATERLOW_WRN)GensWarningAlarm1.BITS.BIT9=F_WARN_WATER_LO;   //水位低警告        
  else                  GensWarningAlarm1.BITS.BIT9=0;  
  GensWarningAlarm1.BITS.BITA=F_WARN_TEMP_HI;                          //温度高警告        
  GensWarningAlarm1.BITS.BITB=F_WARN_OP_LO  ;                          //油压低警告        
  GensWarningAlarm1.BITS.BITC=F_WARN_MAINTAIN ;                        //维护警告          
  GensWarningAlarm1.BITS.BITD=F_WARN_EXTERN  ;                         //外部告警输入
  GensWarningAlarm1.BITS.BITE=F_WARN_TEMP_LOST;                        //温度传感器断线警告
  GensWarningAlarm1.BITS.BITF=F_WARN_OP_LOST;                          //压力传感器断线警告   
      
      //警告 50                                     
  GensWarningAlarm2.BITS.BIT0=F_DI_FUELLOW_WRN;                         //燃油位低警告     (IN)  
  GensWarningAlarm2.BITS.BIT1=F_DI_WATERLOW_WRN;                        //水位低警告       (IN)  

      //通用状态1 52
  GensRunStation1.BITS.BIT0=F_STA_FUELOUTPUT;//"燃油输出延时        秒"
  GensRunStation1.BITS.BIT1=F_STA_PRESTART  ;//"开机预热延时        秒"
  GensRunStation1.BITS.BIT2=F_STA_CRANK     ;//"正在起动            秒"
  GensRunStation1.BITS.BIT3=F_STA_WAITLOAD  ;//"机组等待带载"         
  GensRunStation1.BITS.BIT4=F_STA_IDLE      ;//"开机怠速延时        秒"
  GensRunStation1.BITS.BIT5=F_STA_WARM      ;//"暖机延时            秒"
  GensRunStation1.BITS.BIT6=F_STA_TIMER_SAFE;//"安全运行延时        秒" 
  GensRunStation1.BITS.BIT7=F_STA_STARTDEL  ;//"开机延时            秒"
  GensRunStation1.BITS.BIT8=F_STA_STOPDEL;   //"停机延时            秒"
  //GensRunStation1.BITS.BIT9= 
  //GensRunStation1.BITS.BITA=;
  //GensRunStation1.BITS.BITB=;
  GensRunStation1.BITS.BITC=F_STA_TRANSCB;   //"开关转换延时        秒"
  GensRunStation1.BITS.BITD=F_STA_COOL      ;//"停机散热延时        秒"
  GensRunStation1.BITS.BITE=F_STA_STOP_IDLE ;//"停机怠速延时        秒"
  GensRunStation1.BITS.BITF=F_STA_STOP_CHECK;//"等待停稳延时        秒"
  
      //通用状态2 53
  GensRunStation2.BITS.BIT0=F_STA_STOP_FAIL ;        //"停机失败状态"           
  //GensRunStation2.BITS.BIT1=
  //GensRunStation2.BITS.BIT2=      
  //GensRunStation2.BITS.BIT3=
  //GensRunStation2.BITS.BIT4=      
  //GensRunStation2.BITS.BIT5=      
  //GensRunStation2.BITS.BIT6=
  //GensRunStation2.BITS.BIT7=
  GensRunStation2.BITS.BIT8=F_STA_START_RETRY       ;//"起动间隔延时        秒"
  GensRunStation2.BITS.BIT9=F_STA_MAINS_NORMAL_CHECK;//"市电正常鉴别        秒" 
  GensRunStation2.BITS.BITA=F_STA_MAINS_FAIL_CHECK  ;//"市电异常鉴别        秒" 
  GensRunStation2.BITS.BITB=F_STA_STOPOUTPUT        ;//"得电停机延时        秒" 
  GensRunStation2.BITS.BITC=F_STA_AMFSTART          ;//"失电自启动延时      秒"
  GensRunStation2.BITS.BITD=F_STA_AMFSTOP           ;//"得电自停机延时      秒"
 //GensRunStation2.BITS.BITE=TimerEnArr[TMR_GEN_OVERCURRENT_DEL]; //过流延时
 //GensRunStation2.BITS.BITF=;//
                             
                             
      //通用状态3 54
  //GensRunStation3.BITS.BIT0=
  //GensRunStation3.BITS.BIT1=
  //GensRunStation3.BITS.BIT2=
    GensRunStation3.BITS.BIT3=F_STA_DES_RUN  ;         //"机组正常运行" 
  //GensRunStation3.BITS.BIT4=F_STA_MANMODE  ;         //"手动模式"               
  //GensRunStation3.BITS.BIT5=F_STA_AUTOMODE ;         //"自动模式"               
  //GensRunStation3.BITS.BIT6=F_STA_TESTMODE ;         //"手动试机模式" 
  //GensRunStation3.BITS.BIT7=F_STA_STOPMODE ;         //"停机模式"

 
}

//************************************************************************************
//函数名称：  void LCDCheckAlarmListFun() 
//功能描述：  报警列表显示界面
//输入参数：    
//输出参数：  
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
        {LcdAlarmListArray[LcdAlarmListCon]=i*16+j;LcdAlarmListCon++; //计算出报警个数
		 
        }
    }
  }
//  if(LcdAlarmListCon!=0)AlarmListMeun= (LcdAlarmListCon-1)/4;         //计算出报警有多少页
}

void LCD_GEC400_DisAlarmList(void)
{
  INT08U i;
  u8 j; 
  const  char *D_str;
   LCDCopyDBAlarmDataTOMapMemery();  //从DB数据库中复制报警数据到映射内存
   LCDCheckAlarmListFun();
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
   if(LcdAlarmListCon!=AlarmflagHis)
   {GUI_Clear();   //清屏
   	AlarmflagHis=LcdAlarmListCon;
	  for(i=0;i<LcdAlarmListCon+1;i++)
    { 
	  if(i==0)					  //显示大号字头
	  {GUI_SetFont(&GUI_FontHZ_hwhb_32);
	   if(!Language_select)GUI_DispStringAt("AlarmList",10,4);//英文	
	   else                GUI_DispStringAt("报警表   ",10,4);
	  }
	  else 
	  {GUI_SetColor(GUI_RED);
       for(j=0;j<30;j++)GUI_DrawLine (1,34*i+3+j,319,34*i+3+j);	//报警列表背景	  
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
	{D_str=" 无报警                  ";
	}
	else
	{D_str=" No alarm                ";
	}
	GUI_DispStringAt(D_str,2,1*36+5);	
   }
}
/*-----------------------------------------------------------------------
函数名称：void LCDDispAlarmWarning(void)
功能描述： 报警显示界面
输入参数：
输出参数：
----------------------------------------------------------------------- */
 
void LCDDispAlarmWarning(void)          //报警显示界面
{
  const char *D_str;
  char DisNumBuf[40],j,Distr[4];
  INT16U TimerDel=0;
  LCDCopyDBAlarmDataTOMapMemery();  //从DB数据库中复制报警数据到映射内存
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
	  
	  for(j=0;j<4;j++)   {Distr[3-j]=0x20;}//数据分离
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
  {	if(Language_select)D_str=(const char *)" 待机                    ";					
    else               D_str=(const char *)" Standby                 ";    //英文
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
函数名称： INT16U LcdCalSpChDataFv(INT16U DateBuf,INT08U ChSpPosF) 
功能描述： 修改参数后确认保存，将输入的十六进制数据转换为十进制数据
输入参数： DateBuf:预转换数据
           ChSpPosF:转换数据类型  ==0 4位数据 !=0 3位数据
输出参数： DataFv2 十进制数据
----------------------------------------------------------------------- */
INT16U LcdCalSpChDataFv(INT16U DateBuf,INT08U ChSpPosF) 
{
  INT16U DataFv1,DataFv2=0;
  INT08U i,Distr[4];
  if(ChSpPosF==0)                                                        
  {
    DataFv2=DateBuf;
  } 
  else                                                    //如 0x1234转换为1234
  {
    DataFv1=DateBuf;
   for(i=0;i<4;i++)				  //数据分离
    {	 
	   Distr[3-i]=DataFv1%10;
	   DataFv1 /= 10 ;
    }
   DataFv2=Distr[0]*100+Distr[1]*10+Distr[3];
  }
  return DataFv2;
}
/*-----------------------------------------------------------------------
函数名称: INT16U LcdCalOctTOhex(INT16U DateOct,INT08U Flag) 
功能描述: 输入十进制数据转换为十六进制数据
输入参数: DateOct:预转换数据  PosFlag:表示修改的数据带小数点
输出参数: DataFv2 十六进制数据
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
函数名称： INT08U LcdJudgeSpDataYesorNot(INT16U JudgeSpData)
功能描述： 判断修改的数据是否符合要求 
输入参数：预判断数据
输出参数：0 不在范围  1 在范围
----------------------------------------------------------------------- */
  
INT08U LcdJudgeSpDataYesorNot(INT16U JudgeSpData) 
{
  INT16U JudgeData1=0,JudgeData2=0;
  JudgeData1=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->MinValue;//范围 最小值 
  JudgeData2=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->MaxValue;//范围 最大值 
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
       SetCursorMove++;                                                                  //普通参数
       if((SetCursorMove==3)&&(ChSpPosFlag!=0))SetCursorMove++;                          //参数设置中有小数点，光标要多跳一位
       if(SetCursorMove>4)
        {
          if(LcdJudgeSpDataYesorNot(LcdCalSpChDataFv(SystemParmModify,ChSpPosFlag)))     //判断输入数据是否在范围内
          {
           Buf1=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParmSetHeadnum; //当前值在数组中的偏移量 
			     FLASHDATABASE[Buf1].Sbyte=LcdCalSpChDataFv(SystemParmModify,ChSpPosFlag);
			     //FLASH_SaveModifParm();                                                 //保存当前修改的参数 普通参数
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
//Name:	               测量数据校验函数
//Function： XIOCalRate(INT16U ParamNum,INT16S Value)
//Descreate: ParamNum--参数序号
//			 Value --  被校验数据测量实时值
//--------------------------------------------------------

INT16S XIOCalRate(INT16U ParamNum,INT16S Value)
{
    if(ParamNum==sPa_VOLT_MAINS_A)//A相市电电压校准
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
    
    if(ParamNum==sPa_VOLT_MAINS_B)//B相市电电压校准
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
    
    if(ParamNum==sPa_VOLT_MAINS_C)//C相市电电压校准
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
    
    if(ParamNum==sPa_VOLT_GEN_A)//A相发电电压校准
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
    if(ParamNum==sPa_VOLT_GEN_B)//B相发电电压校准
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
    if(ParamNum==sPa_VOLT_GEN_C)//C相发电电压校准
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
    
    if(ParamNum==sPa_CURRENT_A)//电流A相校准
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
    if(ParamNum==sPa_CURRENT_B)//电流B相校准
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
    if(ParamNum==sPa_CURRENT_C)//电流C相校准
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
    
    if(ParamNum==sPa_TEMP)//水缸温校验
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
    if(ParamNum==sPa_OP) //机油压力校验
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
    if(ParamNum==sPa_LEVEL)//燃油位校验
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
      
    if(ParamNum==sPa_BATT)//校准电池电压
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
    if(ParamNum==sPa_CHARGER)//校准D+电压
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
函数名称： INT08U LcdJudgeAdjDataYesorNot(INT16U JudgeAdjData)
功能描述： 判断修改的数据是否符合要求 
输入参数：预判断数据
输出参数：0 不在范围  1 在范围
----------------------------------------------------------------------- */
  
INT08U LcdJudgeAdjDataYesorNot(INT16U JudgeAdjData) 
{
  INT16U JudgeData1=0,JudgeData2=0;
  JudgeData1=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->MinValue;//范围 最小值 
  JudgeData2=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->MaxValue;//范围 最大值 
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
      {AdjSetCursorMove++;                                                        //校验参数
       if((AdjSetCursorMove==3)&&(AdjSpPosFlag!=0))AdjSetCursorMove++;            //校验参数设置中有小数点，光标要多跳一位
       if(AdjSetCursorMove>4)
       { Buf1=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParmSetHeadnum;      //当前值在数组中的偏移量 
	       SaveDBuf=XIOCalRate(Buf1,LcdCalSpChDataFv(AdjParmModify,AdjSpPosFlag));
          if(LcdJudgeAdjDataYesorNot(SaveDBuf)) //判断输入数据是否在范围内
          { FLASHDATABASE[Buf1].Sbyte=SaveDBuf;
			     // FLASH_SaveModifParm();                                              //保存当前修改的校验参数 
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
函数名称： LCDSaveCurveParmSet
功能描述： 保存修改的自定义曲线数据
输入参数：
输出参数：
----------------------------------------------------------------------- */
void LCDSaveCurveParmSet(void)
{
 INT08U buf=0,k;
 for(k=0;k<CurveDotCtr;k++)	  //判断所有修改的数据是否在合法范围内
 {if(DB_JudgeCurveInitDRN(CurveMidfyBuf[k*2],SpSetCursorMove,k)==0)              {buf++;}
  if(DB_JudgeCurveInitDRN(CurveMidfyBuf[k*2+1],SpSetCursorMove,k+CurveDotCtr)==0){buf++;}
 }
 if(buf==0)
 {for(k=0;k<CurveDotCtr;k++) //是合法修改数据保存到flash
  {buf=MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[k]->ParmSetHeadnum;
   FLASHDATABASE[buf].Sbyte=CurveMidfyBuf[k*2];
   buf=MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[k+CurveDotCtr]->ParmSetHeadnum;
   FLASHDATABASE[buf].Sbyte=CurveMidfyBuf[k*2+1];
  }
  //FLASH_SaveModifParm();                        //保存当前修改的自定义曲线数据参数 
	FLASH_SavecCurveParm();
 }
} 
  
/*---------------------------------------------------------------------------
函数名称: void LCD_GEC400_MainPgMDataDis(void) 
功能描述:      测量数据界面显示   
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
 if(F_AUX_INPUT1)GUI_DispStringAt("■", 62,83);
 else			 GUI_DispStringAt("□", 62,83);
											 
 if(F_AUX_INPUT2)GUI_DispStringAt("■",96,83);
 else			 GUI_DispStringAt("□",96,83);
											 
 if(F_AUX_INPUT3)GUI_DispStringAt("■",130,83);
 else			 GUI_DispStringAt("□",130,83);
											 
 //if(F_AUX_INPUT4)GUI_DispStringAt("■",163,83);
 //else			 GUI_DispStringAt("□",163,83);

}

void LCDisOutSwitchStat(void)
{
 if(F_OUTPUT_CRANK)GUI_DispStringAt("■", 62,155);
 else			   GUI_DispStringAt("□", 62,155);

 if(F_AUX_OUTPUT1) GUI_DispStringAt("■", 96,155);
 else			   GUI_DispStringAt("□", 96,155);
												
 if(F_AUX_OUTPUT2) GUI_DispStringAt("■", 130,155);
 else			   GUI_DispStringAt("□", 130,155);
												
 if(F_AUX_OUTPUT3) GUI_DispStringAt("■", 163,155);
 else			   GUI_DispStringAt("□", 163,155);
												
 if(F_AUX_OUTPUT4) GUI_DispStringAt("■", 196,155);
 else			   GUI_DispStringAt("□",196,155);
												
 if(F_AUX_OUTPUT5) GUI_DispStringAt("■", 229,155);
 else			   GUI_DispStringAt("□", 229,155);
												
 if(F_AUX_OUTPUT6) GUI_DispStringAt("■", 263,155);
 else			   GUI_DispStringAt("□", 263,155);
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
			 for(i=0;i<31;i++)GUI_Line(80,33*1+8+i,220,33*1+8+i,GUI_WHITE);	//显示测量数据背景
			 for(i=0;i<31;i++)GUI_Line(80,33*2+8+i,220,33*2+8+i,GUI_WHITE);	//显示测量数据背景
			 for(i=0;i<31;i++)GUI_Line(80,33*3+8+i,220,33*3+8+i,GUI_WHITE);	//显示测量数据背景			 
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
   	  GUI_GotoXY(255,45);  GUI_DispDecSpace(VOLTAGEC1,3);	   //发电L-N
	  
//	  GUI_GotoXY( 85,77);  GUI_DispDecSpace(VOLTAGEAB1,3);
//	  GUI_GotoXY(170,77);  GUI_DispDecSpace(VOLTAGEBC1,3);
	   GUI_GotoXY(255,77); GUI_DispDecSpace(VOLTAGECA1,3);     //发电L-L

//	  GUI_GotoXY( 74,110); GUI_DispDecSpace(CURRENTA/10,4);
//	  GUI_GotoXY(159,110); GUI_DispDecSpace(CURRENTB/10,4); 
	   GUI_GotoXY(244,110); GUI_DispDecSpace(CURRENTC/10,4);    //电流 
				
	  LCD_DisNum=(float)KWALL/(float)10.0;
	  GUI_GotoXY( 74,142); GUI_DispFloat(LCD_DisNum,4);	     //有功功率
	  LCD_DisNum=(float)KVARALL/(float)10.0;
	  GUI_GotoXY(202,142); GUI_DispFloat(LCD_DisNum,4); 	   //无功功率
	  
	  LCD_DisNum=(float)PhaseCOS/(float)100.0;
	  GUI_GotoXY( 40,177); GUI_DispFloat(LCD_DisNum,4);	       //功率因数
	  
	  LCD_DisNum=(float)GEN_FREQ/(float)10.0;
	  GUI_GotoXY(110,177); GUI_DispFloat(LCD_DisNum,4);	       //发电频率
		LCD_DisNum=(float)KVAALL/(float)10.0;
	  GUI_GotoXY(215,177); GUI_DispFloat(LCD_DisNum,4); 	   //视在功率
	  
	  break;
	 case 2://126 243 288
	   GensElectricity=(INT32U)EPROM_STARTNUM;
	   GUI_GotoXY(240, 43);GUI_DispDecSpace(GensElectricity,6); //累计开机次数
	   GUI_GotoXY(146, 78);GUI_DispDecSpace(RUNNINGHOUR,8);	    //累计运行时间 时
	   GUI_GotoXY(254, 78);GUI_DispDecSpace(RUNNINGMINUTE,2);   //累计运行时间 分
	   GUI_GotoXY(288, 78);GUI_DispDecSpace(RUNNINGSEC,2);	    //累计运行时间 秒
//	   GensElectricity= *KWH;//@@@@@@@@@@ZC
	   GUI_GotoXY(170,110);GUI_DispDecSpace(GensElectricity/10,9); //累计电能
	  break;
	 case 3:
	  GUI_GotoXY(226,44); GUI_DispDecSpace(DES_DISPSPEED,4);	//转速
	  LCD_GEC400_DisMTemp();							                    //水温
	  LCD_GEC400_DisMOilPress();						                  //机油压力
	  LCD_DisNum=(float)PowerVoltage/(float)10.0;
	  GUI_GotoXY( 80,176);GUI_DispFloat(LCD_DisNum,4);	     //电池电压
	  LCD_DisNum=(float)ChargerVoltage/(float)10.0;		  
	  GUI_GotoXY(245,176);GUI_DispFloat(LCD_DisNum,4);	     //充电机电压
	  
	  break;
	 case 4:  
	  LCD_GEC400_DisMFuel();							  //燃油位
	  break;
	 case 5:		 //I/O状态显示
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
函数名称: void LCD_GEC400_FirGUIDEMO(void) 
功能描述:      参数测量首页显示   
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
	 GUI_DispFloat(LCD_DisNum,4);   //有功功率
   GUI_GotoXY(170,20); GUI_DispDecSpace(DES_DISPSPEED,4);//转速
   if(GEN_VOLT_TYPE == 2){ GUI_GotoXY( 85,90); GUI_DispDecSpace(VOLTAGEC1,3); } //发电L-N 
   else {GUI_GotoXY( 85,90); GUI_DispDecSpace(VOLTAGEA1,3); } //发电L-N   
   LCD_GEC400_FirPagMOilPress(225,90);					       //机油压力
   GUI_GotoXY( 73,115);GUI_DispDecSpace(CURRENTA/10,4);//电流
   LCD_GEC400_FirPagMTemp(225,115);						         //温度
   LCD_DisNum=(float)GEN_FREQ/(float)10.0;
   GUI_GotoXY( 73,140);GUI_DispFloat(LCD_DisNum,4);	   //发电频率	
   LCD_DisNum=(float)PowerVoltage/(float)10.0;
   GUI_GotoXY(225,140);GUI_DispFloat(LCD_DisNum,4);	   //电池电压
    
}

#endif

/*---------------------------------------------------------------------------
函数名称: void LCD_GEC400FirPageLightDis(void) 
功能描述:      手界面指示灯显示   
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)
 
void LCD_GEC400FirPageLightDis(void)
{
  unsigned char i;
  if(LED_GENSET==1)					  //发电正常指示
  {  GUI_SetColor(LCDFirstLightOnCol); 
     GUI_FillCircle(102,70,12);
  }
  else
  {  GUI_SetColor(LCDFirstLightOffCol); 
     GUI_FillCircle(102,70,12);
  }
  
  if(LED_GCB)					   //发电合闸指示
  {	//GUI_SetColor(LCDFirstLightOnCol);
    //GUI_FillCircle(216,70,12);
		GUI_DrawOpen(1);
  }
  else
  {	//GUI_SetColor(LCDFirstLightOffCol);
    //GUI_FillCircle(216,70,12);
		GUI_DrawOpen(0);
  }

  if(F_SHOW_LED_STOP==1)				 //停机
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
	
  if(F_SHOW_LED_MANUAL==1)			     //手动
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
  if(F_SHOW_LED_AUTO==1)				 //自动
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
函数名称: void LCD_GEC400_MainPgHeadDis(void) 
功能描述:      参数测量界面头显示   
----------------------------------------------------------------------------*/  
#if(LCD_GEC400EN==1)

void LCDGEC400MPagHeadNumDis(void)  //测量页面头部序号显示
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

void LCDGEC400HeadIOStatPagDis(void)  //I/O状态显示页面
{  u8 j;
   GUI_SetFont(&GUI_FontHZ_hwhb_32); //
   if(!Language_select)GUI_DispStringAt("I/O    ",10,4);	//英文
   else				   GUI_DispStringAt("I/O状态",10,4);
   LCDGEC400MPagHeadNumDis();                          //测量页面头部序号显示
   for(j=0;j<4;j++)GUI_Line(1,40+j,319,40+j,GUI_WHITE);//划线
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_DispStringAt("IN:   1  2  3             ",2, 50);	
   GUI_DispStringAt("OUT:  C  1  2  3  4  5  6 ",2,118);	
}

void LCDGEC400OtherHeadPagDis(void)  //其他页面状态显示页面
{ 
  u8 i;
  u8 j;
  const  char *D_str; 
  for(i=0;i<6;i++)
   { 
	  D_str=(const char *)PageShow.Pages[MainPageCon]->Pagept[Language_select*(PageShow.Pages[MainPageCon]->Disable)+i];
    if(i==0)					  //显示大号字头
	 {GUI_SetFont(&GUI_FontHZ_hwhb_32);
	  GUI_DispStringAt(D_str,10,4);
	  LCDGEC400MPagHeadNumDis();  //测量页面头部序号显示
	 }
	 else 
	 {
	  for(j=0;j<31;j++)GUI_Line(1,33*i+8+j,319,33*i+8+j,GUI_WHITE);	//显示测量数据背景
	  GUI_SetBkColor(GUI_WHITE);
      GUI_SetColor(LCD_DisMDtColor);
	  GUI_SetFont(&LCD_DisFont);
	  switch(i)													    //显示测量参数头
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
   GUI_Clear();   //清屏
   
   for(i=0;i<33;i++)GUI_Line(1,206+i,319,206+i,LCD_AlarmColor);	//报警条背景显示
   if(MainPageCon==LCDIOStatPgCtr)LCDGEC400HeadIOStatPagDis();  //I/O状态显示页面
   else                           LCDGEC400OtherHeadPagDis();  //其他页面状态显示页面
   
 }

#endif
/*---------------------------------------------------------------------------
函数名称: void LCD_GEC400_MainPgOtherDisStartSpd(void) 
功能描述:   根据不同的启动成功条件显示首界面   
 //0：磁感器 3：磁传感器+油压
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
	  GUI_GotoXY(226,44); GUI_DispDecSpace(DES_DISPSPEED,4);	//转速
	  LCD_GEC400_DisMOilPressSpd();						                //机油压力
	  break;
	 case 2:
	   GensElectricity=(INT32U)EPROM_STARTNUM;
	   GUI_GotoXY(240, 43);GUI_DispDecSpace(GensElectricity,6); //累计开机次数
	   GUI_GotoXY(146, 78);GUI_DispDecSpace(RUNNINGHOUR,8);	    //累计运行时间 时
	   GUI_GotoXY(254, 78);GUI_DispDecSpace(RUNNINGMINUTE,2);   //累计运行时间 分
	   GUI_GotoXY(288, 78);GUI_DispDecSpace(RUNNINGSEC,2);	    //累计运行时间 秒
	  break;
	 case 3:		 //I/O状态显示
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
   
   LCD_GEC400_FirPagMOilPress(73,90);					         //机油压力
   LCD_GEC400_FirPagMTemp(73,115);						         //温度
   LCD_DisNum=(float)PowerVoltage/(float)10.0;
   GUI_GotoXY(73,140);GUI_DispFloat(LCD_DisNum,4);	   //电池电压
	
	 GUI_GotoXY(225,90); GUI_DispDecSpace(DES_DISPSPEED,4);//转速
   LCD_GEC400_DisFirPageFuel();						             //燃油位
   LCD_DisNum=(float)ChargerVoltage/(float)10.0;
   GUI_GotoXY(225,140);GUI_DispFloat(LCD_DisNum,4);	   //充电机电压
}
 
void LCDGEC400MPagHeadNumDisStartSpd(void)  //测量页面头部序号显示
{// GUI_SetFont(&GUI_Font24B_ASCII);  //@@@@@@@@@@@@@ZC
  switch(MainPageCon)
  {
    case 1:GUI_DispStringAt("1/2",280,15);break;
	  case 2:GUI_DispStringAt("2/2",280,15);break;
	  case 3:GUI_DispStringAt("1/1",280,15);break;
	  default:GUI_DispStringAt("1/1",280,15);break;
  }	  
}

void LCDGEC400HeadIOStatPagDisStartSpd(void)  //I/O状态显示页面
{  u8 j;
   GUI_SetFont(&GUI_FontHZ_hwhb_32); //
   if(!Language_select)GUI_DispStringAt("I/O    ",10,4);	//英文
   else				         GUI_DispStringAt("I/O状态",10,4);
   LCDGEC400MPagHeadNumDisStartSpd();                     //测量页面头部序号显示
   for(j=0;j<4;j++)GUI_Line(1,40+j,319,40+j,GUI_WHITE);//划线
   GUI_SetBkColor(LCD_DisBKColor);
   GUI_SetColor(LCD_DisColor);
   GUI_SetFont(&LCD_DisFont);
   GUI_DispStringAt("IN:   1  2  3             ",2, 50);	
   GUI_DispStringAt("OUT:  C  1  2  3  4  5  6 ",2,118);	
}

void LCDGEC400OtherHeadPagDisStartSpd(void)  //其他页面状态显示页面
{ 
  u8 i;
  u8 j;
  const  char *D_str; 
  for(i=0;i<6;i++)
  { 
	  if((!Language_select)&&(i==PageShowSpd.Pages[MainPageCon]->Disable)){break;}
	  D_str=(const char *)PageShowSpd.Pages[MainPageCon]->Pagept[Language_select*(PageShowSpd.Pages[MainPageCon]->Disable)+i];
    if(i==0)					  //显示大号字头
	  { GUI_SetFont(&GUI_FontHZ_hwhb_32);
	    GUI_DispStringAt(D_str,10,4);
	    LCDGEC400MPagHeadNumDisStartSpd();  //测量页面头部序号显示
	  }
	  else 
	  {
	     for(j=0;j<31;j++)GUI_Line(1,33*i+8+j,319,33*i+8+j,GUI_WHITE);	//显示测量数据背景
	     GUI_SetBkColor(GUI_WHITE);
       GUI_SetColor(LCD_DisMDtColor);
	     GUI_SetFont(&LCD_DisFont);
	     switch(i)													    //显示测量参数头
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
   GUI_Clear();   //清屏
   for(i=0;i<33;i++)GUI_Line(1,206+i,319,206+i,LCD_AlarmColor);	//报警条背景显示
   if(MainPageCon==3)LCDGEC400HeadIOStatPagDisStartSpd();       //I/O状态显示页面
   else              LCDGEC400OtherHeadPagDisStartSpd();        //其他页面状态显示页面
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
	   else				       {LCD_GEC400_DisAlarmList();MainPageConHis=0xff;}//报警列表显示
   	 FirGuiDemoHis=0xff;
   }
   else 							//显示首界面显示
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
  if(MainPageCon!=4)LCD_GEC400_AlarmStaDis();//报警条显示
 }
 
 #endif
/*---------------------------------------------------------------------------
函数名称: void LCD_GEC400_MainPgDis_STARTSUCC_CONDITION03(void) 
功能描述:   根据不同的启动成功条件显示首界面 
//1：发电    2：磁传感器+发电    4：发电+油压  5：磁传感器+发电+油压 
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
	   else				            {LCD_GEC400_DisAlarmList();MainPageConHis=0xff;}//报警列表显示
   	 FirGuiDemoHis=0xff;
   }
   else 							//显示首界面显示
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
  if(MainPageCon!=LCDAlarmListPg)LCD_GEC400_AlarmStaDis();//报警条显示
 } 
#endif
/*---------------------------------------------------------------------------
函数名称: void LCD_GEC400_MainPgDis(void) 
功能描述:     首界面显示   
----------------------------------------------------------------------------*/ 
#if(LCD_GEC400EN==1)
void LCD_GEC400_MainPgDis(void)
 {
	 if((DES_STARTSUCC_CONDITION==0)||(DES_STARTSUCC_CONDITION==3))//0：磁感器 3：磁传感器+油压
	 {
		 if(MainPageCon>(PageShowSpd.PageNums-1)){MainPageCon=0;}//从多菜单切换到少菜单
	   LCD_GEC400_MainPgDis_STARTSUCC_CONDITIONVol();
	 }
   else                   //1：发电    2：磁传感器+发电    4：发电+油压  5：磁传感器+发电+油压
	 {
     LCD_GEC400_MainPgDis_STARTSUCC_CONDITION03();
	 }
 }
#endif 
/*---------------------------------------------------------------------------
函数名称: void LCD_GEC400_MenuPgDis(void) 
功能描述:     菜单选择界面显示   
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
   	GUI_Clear();   //清屏
   }
   menui=MAINMENU.MENUNUM;
   for(i=0;i<menui;i++)
   { 	 
	  if(Language_select==LCD_LanguageEnglish)      D_str=(const char *)MAINMENU.SubPtr[i]->ptNameStrEN;
	  else if(Language_select==LCD_LanguageChinese) D_str=(const char *)MAINMENU.SubPtr[i]->ptNameStrCN;
	  else {} //扩展其他语言
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
函数名称: void LCD_GEC400_PassWordPgDis(void) 
功能描述:  刷新密码输入显示界面    
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
   GUI_Clear();   //清屏
   for(i=0;i<2;i++)
   { 
	  if(i==0)
	  {
	   if(Language_select==LCD_LanguageEnglish)      D_str="Input PassWord:";
	   else if(Language_select==LCD_LanguageChinese) D_str="请输入口令:";
	   else {} //扩展其他语言
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
函数名称: void LCD_GEC400_MsgSelPgDis(void) 
功能描述:  刷新控制器信息显示界面    
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
   GUI_Clear();   //清屏
   menui=SysMsgPageShow.Pages[ParmMsgSubPageCon]->Disable;
   for(i=0;i<menui;i++)
   { 
	  if(Language_select==LCD_LanguageEnglish)      D_str=(const char *)SysMsgPageShow.Pages[ParmMsgSubPageCon]->Pagept[menui*0+i];
	  else if(Language_select==LCD_LanguageChinese) D_str=(const char *)SysMsgPageShow.Pages[ParmMsgSubPageCon]->Pagept[menui*1+i];
	  else {} //扩展其他语言
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
函数名称: void LCD_GEC400_MsgSelPgDis(void) 
功能描述:  刷新控制器信息显示界面    
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
	  else {} //扩展其他语言
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
   GUI_Clear();   //清屏
  }  
  LCD_GEC400_LagSelHeadDis();
}
#endif
/*---------------------------------------------------------------------------
函数名称: void LCD_GEC400_ParmSetPgDis(void) 
功能描述:  刷新参数设置显示界面    
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)

INT16U LCD_GEC4xx_ChagePosDate(INT16U ParmChage,INT08U POS)
{
   u8 i;
   u8 Distr[4];
   u16 DisNum,ReturnNum=0;
   DisNum=ParmChage;
   for(i=0;i<4;i++)				  //数据分离
   {	 
	  Distr[3-i]=DisNum%10;
	  DisNum /= 10 ;
   }
   switch(POS)                  //小数点处理
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
   for(i=0;i<4;i++)				  //数据分离
   {	 
	  Distr[3-i]=DisNum%10;
	  DisNum /= 10 ;
   }
   switch(NumPos)                  //小数点处理
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
   for(i=0;i<4;i++)				  //数据分离
   {	 
	  Distr[3-i]=DisNum%10;
	  DisNum /= 10 ;
   }
   switch(NumPos)                  //小数点处理
   {
  	 case 0:                       //修改无小数点数据
	    for(i=0;i<4;i++)
	    {
			  if((curre-1)==i) GUI_SetBkColor(LCD_MenuSelColor);
			  else             GUI_SetBkColor(LCD_DisBKColor);
			  GUI_DispDecAt(Distr[i],x+(12*i),y,1);
	    }
	   break;
	  case 1:                      //修改小数点数据
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
	
   ParmOffset=ParmOffBuf;                      //当前值在数组中的偏移量 
   ChSpPosFlag=ParmPosSet=ParmPosBuf&0x03;     //参数小数点位置
   ChSpBuf=SpMeunBuf=(ParmPosBuf&0x7c)>>2;     //判断当前参数是否为菜单参数
	 if(SpMeunBuf==0)                            //设定值显示
	 {
      if(ParmSetCurDisFlag==Password0x0318)    //按下确认键修改数据
      {if(!LCDOctParmFlag)
	     {LCDOctParmFlag=1;SystemParmModify=FLASHDATABASE[ParmOffset].Sbyte;//读出上次数据
		     if(ChSpPosFlag!=0)SystemParmModify=LCD_GEC4xx_ChagePosDate(SystemParmModify,ChSpPosFlag);
	      }   
		    LCD_GEC4xx_DisAdjParmNumSet(115,DisLine*35+2,SystemParmModify,ChSpPosFlag,SetCursorMove);//显示当前正在修改数据
      }                                                                           
	    else {LCDOctParmFlag=0;LCD_GEC4xx_DisOldParmNumSet(115,DisLine*35+2,0,ParmPosSet);} 
    }
	 else
	 {
       Spbuf=(MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ScaleStr[0])-0x30;    
       SpOffSet=(MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ScaleStr[1])-0x30; //读出特殊参数在指针位置
       ChSpOffSet=SpOffSet=Spbuf*10+SpOffSet;                                            
       Spbuf=(SpManyShow.Pages[SpOffSet]->Disable)*Language_select;                             //特殊参数语言
       GUI_SetBkColor(LCD_DisBKColor);
       GUI_SetColor(LCD_DisParmSetCl);
       GUI_SetFont(&LCD_DisFont);
		 
	     if((!LCDBitParmFlag)&&(KeyMenulevel==0x06)){LCDBitParmFlag=1;SpSetCursorMove=FLASHDATABASE[ParmOffset].Sbyte;} //读出上次特殊参数项
       if(ParmSetCurDisFlag==Password0x0318)
       { GUI_SetBkColor(LCD_MenuSelColor);                                                                            //修改特殊参数
         D_str=(const char *)SpManyShow.Pages[SpOffSet]->Pagept[SpSetCursorMove+Spbuf];
       } 
       else                                                                           
       {GUI_SetBkColor(LCD_DisBKColor);
		    D_str=(const char *)SpManyShow.Pages[SpOffSet]->Pagept[FLASHDATABASE[ParmOffset].Sbyte+Spbuf]; //取出参数显示内容
       }
       GUI_DispStringAt(D_str,2,DisLine*34+5);
   }
}

void LCD_GEC400_DisParmSet()
{  
  u8 ParmOffset,ParmPosSet;   
  ParmOffset=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParmSetHeadnum; //当前值在数组中的偏移量 
  ParmPosSet=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->Mode;           //当前值的小数点位置
  LCD_GEC4xx_DisOldParmNumSet(115,2*35+5,FLASHDATABASE[ParmOffset].Sbyte,ParmPosSet&0x03);//显示上次设定的数据 
  LCD_GEC4xx_DisSubParmSpecial(ParmOffset,ParmPosSet,3);    //显示参数设置的当前值
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
   GUI_Clear();   //清屏 
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
	   	case 2:D_str="当前值:"; break;
		  case 3:D_str="设定值:     "; break;
	   }
	  } 
	  else {} //扩展其他语言
	  if(i==0)//更新菜单序号
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
函数名称：LCDMapAdjDatafromRAMDATABASE() 
功能描述： 当密码0x636修改参数校验时映射实时测量数据

--------------------------------------------------------------------------*/
void LCDMapAdjDatafromRAMDATABASE(void)
{
  AdjMapVOLTAGEA2     = VOLTAGEA2;       //市电A电压校验  
  AdjMapVOLTAGEB2     = VOLTAGEB2;       //市电B电压校验  
  AdjMapVOLTAGEC2     = VOLTAGEC2;       //市电C电压校验  
  AdjMapVOLTAGEA1     = VOLTAGEA1;       //发电A电压校验  
  AdjMapVOLTAGEB1     = VOLTAGEB1;       //发电B电压校验  
  AdjMapVOLTAGEC1     = VOLTAGEC1;       //发电C电压校验  
  AdjMapCURRENTA      = CURRENTA/10;     //A相电流校验 
  AdjMapCURRENTB      = CURRENTB/10;     //B相电流校验 
  AdjMapCURRENTC      = CURRENTC/10;     //C相电流校验 
  
  AdjMapWATERTEMP     = VALUER1;         //水缸温校验      
  AdjMapOILPRESSURE   = VALUER0;         //机油压力校验       
  AdjMapFUEL          = VALUER2;         //燃油位校验 
  AdjMapCustomAog	  = VALUER3;		 //自定义模拟量校验 
       
  AdjMapPowerVoltage  = PowerVoltage;    //电池电压校验   
  AdjMapChargerVoltage= ChargerVoltage;  //充电机D+       
  AdjMapPhaseCOS      = PhaseCOS;        //发电功率因数   
}
/*-----------------------------------------------------------------------
函数名称：LCD_GEC4xx_DisAdjParmSet() 
功能描述： 

--------------------------------------------------------------------------*/

void LCD_GEC4xx_DisAdjParmSet(u8 ParmOffBuf,u8 ParmPosBuf,u8 DisLine) 
{
   u8 ParmOffset,ParmPosSet,SpMeunBuf;
   u8 SpOffSet,Spbuf;
   static unsigned char LCDRdAdjOldParmFlg;
   const  char *D_str;	 
	
   ParmOffset=ParmOffBuf;                     //当前值在数组中的偏移量 
   AdjSpPosFlag=ParmPosSet=ParmPosBuf&0x03;   //参数小数点位置
   AdjChMenuSpBuf=SpMeunBuf=(ParmPosBuf&0x7c)>>2; //判断当前参数是否为菜单参数
	if(SpMeunBuf==0)                          //设定值显示
	{
     if(AdjParmSetCurDisFlag==Password0x0636)    //按下确认键修改数据
     {if(!LCDRdAdjOldParmFlg)
	    {LCDRdAdjOldParmFlg=1;AdjParmModify=AdjDataMapBuf[pArmAdjPageCon].Sbyte;//读出上次数据
		   if(AdjSpPosFlag!=0)AdjParmModify=LCD_GEC4xx_ChagePosDate(AdjParmModify,AdjSpPosFlag);
		  } 
		   LCD_GEC4xx_DisAdjParmNumSet(115,DisLine*35+2,AdjParmModify,AdjSpPosFlag,AdjSetCursorMove); //显示当前参数校验正在修改数据
     }                                                             	             
	   else{ LCDRdAdjOldParmFlg=0;LCD_GEC4xx_DisOldParmNumSet(115,DisLine*35+2,0,ParmPosSet);} 
    }
	else
	 {
       Spbuf=(SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ScaleStr[0])-0x30;    
       SpOffSet=(SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ScaleStr[1])-0x30; //读出特殊参数在指针位置
       SpAdjOffSet=SpOffSet=Spbuf*10+SpOffSet;                                            
       Spbuf=(SpAdjSubPgShow.Pages[SpOffSet]->Disable)*Language_select;                             //特殊参数语言
       GUI_SetBkColor(LCD_DisBKColor);
       GUI_SetColor(LCD_DisColor);
       GUI_SetFont(&LCD_DisFont);
	// if((!LCDBitParmFlag)&&(KeyMenulevel==0x06)){LCDBitParmFlag=1;SpSetCursorMove=FLASHDATABASE[ParmOffset].Sbyte;} //读出上次特殊参数项
       if(AdjParmSetCurDisFlag==Password0x0636)
       { GUI_SetBkColor(LCD_MenuSelColor);                                                                            //修改特殊参数
         D_str=(const char *)SpAdjSubPgShow.Pages[SpOffSet]->Pagept[SpAdjSetCurMove+Spbuf];
       } 
       else                                                                           
       {GUI_SetBkColor(LCD_DisBKColor);
		    D_str=(const char *)SpAdjSubPgShow.Pages[SpOffSet]->Pagept[FLASHDATABASE[ParmOffset].Sbyte+Spbuf]; //取出参数显示内容
       }
       GUI_DispStringAt(D_str,2,DisLine*34+5);
     }
}

/*---------------------------------------------------------------------------
函数名称: void LCD_GEC400_DisAdjParmSet(void) 
功能描述:  刷新参数校验显示界面    
----------------------------------------------------------------------------*/
void LCD_GEC400_DisAdjParmSet()
{  
  u8 AdjParmOffset,AdjParmPosSet;   
  AdjParmOffset=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParmSetHeadnum; //当前值在数组中的偏移量 
  AdjParmPosSet=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->Mode;           //当前值的小数点位置
  LCDMapAdjDatafromRAMDATABASE();											 //参数校验时映射实时测量数据
  LCD_GEC4xx_DisOldParmNumSet(115,2*35+5,AdjDataMapBuf[pArmAdjPageCon].Sbyte,AdjParmPosSet&0x03); 
  LCD_GEC4xx_DisAdjParmSet(AdjParmOffset,AdjParmPosSet,3);    //显示参数校验设置的值
}

/*---------------------------------------------------------------------------
函数名称: void LCD_GEC400_AdjParmSetHeadDis(void) 
功能描述:  显示参数校验头内容   
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
   GUI_Clear();   //清屏 
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
	   	case 2:D_str="当前值:"; break;
		  case 3:D_str="设定值:     "; break;
	   }
	  } 
	  else {} //扩展其他语言
	  if(i==0)//更新菜单序号
	  {
	   menui=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParmSetHeadnum+1;
		 if(COMMON_MODEL==MODEL410)menui=menui-sParmSetnum_ForMainPage-1-M410DelAdjMBusPg; //
		 for(j=0;j<GECx_DisCon;j++) *(DisNumBuf+j)=*(D_str+j); //将原显示字符串复制后修改显示序号
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
函数名称： LCD_GEC400_SenCurvePgDis() 
功能描述： 自定义传感器曲线参数设置显示页面

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
   GUI_Clear();   //清屏 
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
	else {} //扩展其他语言
	if(i>2)//更新菜单序号
	{
    for(j=0;j<cURVEDisCon;j++) *(DisNumBuf+j)=*(D_str+j); //将原显示字符串复制后修改显示序号
	  DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2]->ParmSetHeadnum].Sbyte;
	  for(j=4;j;j--){DisNumBuf[j-1+2]=DisV%10+'0';DisV/=10;} //电阻值
	  DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2+CurveDotCtr]->ParmSetHeadnum].Sbyte;
	  for(j=4;j;j--){DisNumBuf[j-1+7]=DisV%10+'0';DisV/=10;} //对应数据
	  
	  DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2+1]->ParmSetHeadnum].Sbyte;
	  for(j=4;j;j--){DisNumBuf[j-1+16]=DisV%10+'0';DisV/=10;} //电阻值
	  DisV=FLASHDATABASE[MainCurvePage->cpCurveMainPg[SpSetCursorMove]->CurvePages[Ctr*2+CurveDotCtr+1]->ParmSetHeadnum].Sbyte;
	  for(j=4;j;j--){DisNumBuf[j-1+21]=DisV%10+'0';DisV/=10;} //对应数据

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
  switch(SetCurveConter/4)	//读出上次的数据
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
  Ctr =SetCurveConter/4+1;	 //更新待修改数据

  if(CurveCtrHis!=Ctr)
  {CurveCtrHis=Ctr;
   CurveParmModify1=DisV;
  }
  DisV=CurveParmModify1;
  Custr[3]=DisV%10;DisV/=10; Custr[2]=DisV%10;DisV/=10;
  Custr[1]=DisV%10;DisV/=10; Custr[0]=DisV%10;DisV/=10;
  
  Ctr =SetCurveConter/16;
  for(i=0;i<4;i++)			 //修改数据阴影显示
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
  CurveMidfyBuf[SetCurveConter/4]=CurveParmModify1;	//将修改的数据放入缓存区待保存
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
函数名称: void LCD_RefreshDisPage(void) 
功能描述:  刷新显示界面    
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)
void LCD_RefreshDisPage(void)
{
  switch(KeyMenulevel)
  {
   case 0:LCD_GEC400_MainPgDis();    break;	//测量页面显示
	 case 1:LCD_GEC400_MenuPgDis();    break;	//菜单选择显示页面
	 case 2:LCD_GEC400_PassWordPgDis();break;	//密码输入显示页面
	 case 3:LCD_GEC400_MsgSelPgDis();  break;	//控制器信息选择显示页面
	 case 4:LCD_GEC400_LagSelPgDis();  break;	//控制器语言选择显示页面
	 case 5:
	 case 6:LCD_GEC400_ParmSetPgDis(); break;	//控制器参数设置显示页面
	 case 7:
	 case 8:LCD_GEC400_AdjSetPgDis();  break;	//控制器参数校验设置显示页面
   case 9:LCD_GEC400_SenCurvePgDis();break;	//自定义传感器曲线参数设置显示页面
  } 
}
#endif

/*---------------------------------------------------------------------------
函数名称: void LCDMeunKeyCal(void) 
功能描述:      
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
  else                                                         //参数校验中的特殊参数选项
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
  else											 //参数校验中的特殊参数选项
  {
   if(SpAdjSetCurMove<SpAdjSubPgShow.Pages[SpAdjOffSet]->Disable-1) SpAdjSetCurMove++;
   else SpAdjSetCurMove=0;
  }
}

/*---------------------------------------------------------------------
函数名称：  void LCDCureParmChange_KeyPAGEUP()
功能描述： 自定义曲线修改参数设置按下键修改数据
输入参数：
输出参数：
-----------------------------------------------------------------------*/
 void LCDCureParmChange_KeyPAGEUP() 
 {
  INT08U i,parmbuf[4];
  INT16U ParmValue;
   ParmValue=CurveParmModify1;
	for(i=0;i<4;i++){parmbuf[3-i]=ParmValue%10;ParmValue/=10;}
	switch(SetCurveConter%4)                                   //自定义曲线参数修改
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
函数名称：  void LCDCureParmChange_KeyPAGEDONW()
功能描述： 自定义曲线修改参数设置按下键修改数据
输入参数：
输出参数：
-----------------------------------------------------------------------*/
 void LCDCureParmChange_KeyPAGEDONW() 
 {
  INT08U i,parmbuf[4];
  INT16U ParmValue;
  ParmValue=CurveParmModify1;
	for(i=0;i<4;i++){parmbuf[3-i]=ParmValue%10;ParmValue/=10;}
	switch(SetCurveConter%4)                                   //自定义曲线参数修改
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
{  INT08U LishBuf;                                              //首页主屏显示测量参数
   if(KeyMenulevel==0x00)                       
    {
      if((DES_STARTSUCC_CONDITION==0)||(DES_STARTSUCC_CONDITION==3))//0：磁感器 3：磁传感器+油压
			{				
			 MeunCon=PageShowSpd.PageNums;
			}else                  //1：发电    2：磁传感器+发电    4：发电+油压  5：磁传感器+发电+油压
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
			       ParmMainPageConHis=0xff;  //刷新显示菜单选择页面  
        break;
       
        case MASK_BTN_STOP:                  //复位取消按键
             KeyMenulevel=0;
             MainPageCon=0;
            
        break;                              
        default:break;
      }
      return 0;
    }
	if(KeyMenulevel==0x01)                   //显示菜单选择页面    
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
			       if(ParmMainPageCon==0)     {KeyMenulevel=0x02;PassWordCursorMoveHis=0xff;}//密码输入菜单
			       else if(ParmMainPageCon==1){KeyMenulevel=0x03;ParmMsgSubPageConHis=0xff; }//控制器信息
			       else if(ParmMainPageCon==2){KeyMenulevel=0x04;ParmLaguSubPageConHis=0xff;}//语言选择
			       else{} 
            break;
       
         case MASK_BTN_STOP:                 //复位取消按键
             KeyMenulevel=0;
             ParmMainPageCon=0;
			       MainPageConHis=0xff;           //刷新返回参数测量页面
        	   AlarmflagHis=0xff;			    //当前页面处于报警列表时刷新显示
			       FirGuiDemoHis=0xff;			//当前页面处于测量首页面
		        break;                              
         default:break;
       }
      return 1;
    }
	if(KeyMenulevel==0x02)                  //密码输入菜单               
    {
      switch(Btn_buf)
      {         
        case MASK_BTN_PAGEDW:
             switch(PassWordCursorMove)                                           //密码值的减
             {
              case 0:if((Password_Value&0xf000)>0x0000)Password_Value-=0x1000; else Password_Value|=0x9000;break;
              case 1:if((Password_Value&0x0f00)>0x0000)Password_Value-=0x0100; else Password_Value|=0x0900;break;
              case 2:if((Password_Value&0x00f0)>0x0000)Password_Value-=0x0010; else Password_Value|=0x0090;break;
              case 3:if((Password_Value&0x000f)>0x0000)Password_Value-=0x0001; else Password_Value|=0x0009;break;
              default:break;
             }
             break;
         case MASK_BTN_PAGEUP:
              switch(PassWordCursorMove)                                          //密码值的加
              {
               case 0:if((Password_Value&0xf000)>=0x9000)Password_Value&=0x0fff; else Password_Value+=0x1000;break;
               case 1:if((Password_Value&0x0f00)>=0x0900)Password_Value&=0xf0ff; else Password_Value+=0x0100;break;
               case 2:if((Password_Value&0x00f0)>=0x0090)Password_Value&=0xff0f; else Password_Value+=0x0010;break;
               case 3:if((Password_Value&0x000f)>=0x0009)Password_Value&=0xfff0; else Password_Value+=0x0001;break;
               default:break;
              } 
             break;
        case MASK_BTN_PGTURN:
              PassWordCursorMove+=1;		   //移动密码光标
              if(PassWordCursorMove>=4)
              { 
							 switch(Password_Value)
							 {
								case Password0x0318:
									 if(COMMON_MODEL==MODEL410){ParmSubPageCon=M410DelMainBusPg;}
									 KeyMenulevel=5; 		    //进入参数设置
									 PaswordTypeToDisFlag=Password0x0318;
									 ParmSubPageConHis=0xff;//刷新显示参数设置页面
								  break;
								case Password0x1234:
								  break;
								case Password0x0636:
									 if(COMMON_MODEL==MODEL410){pArmAdjPageCon=M410DelAdjMBusPg;}
									 KeyMenulevel=7; 		    //进入参数校验
									 pArmAdjPageConHis=0xff;	//更新参数校验显示头
								  break;
								 default:
									 KeyMenulevel=1;
									 ParmMainPageConHis=0xff;    //刷新显示菜单选择页面  
								 break;
							 }
							PassWordCursorMove=0;
							Password_Value=0;
             }
             break;
       
        case MASK_BTN_STOP:
             KeyMenulevel=1;
             ParmMainPageConHis=0xff;         //刷新显示菜单选择页面 
			       PassWordCursorMove=0;
             Password_Value=0;
             PaswordTypeToDisFlag=0;				
            break;                              
        default:break;
      }
      return 2;
    }
	if(KeyMenulevel==0x03)//控制器信息                       
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
			       ParmMainPageConHis=0xff;  //刷新显示菜单选择页面 
        break;                              
        default:break;
      }
      return 3;
    }
	if(KeyMenulevel==0x04)//语言选择                       
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
			      // FLASH_SaveModifParm();	//保存语言参数
				     FLASH_SavepParm();
          //break;
       
        case MASK_BTN_STOP:                 
             KeyMenulevel=1;
             ParmLaguSubPageCon=0;
			       ParmMainPageConHis=0xff;  //刷新显示菜单选择页面 
             
        break;                              
        default:break;
      }
      return 4;
    }
	if(KeyMenulevel==0x05)    //进入参数设置        
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
			     ParmMainPageConHis=0xff;  //刷新显示菜单选择页面 
           ParmSubPageCon=0;
      break;                              
      default:break;
     }
     return 5;
    }
	if(KeyMenulevel==0x06)    //按下确认键修改参数          
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
              LcdKeySaveParm();                                    //保存普通设置参数
              if((ChSpBuf!=0)&&(ParmSetCurDisFlag==Password0x0318))//保存特殊参数参数
              {
			         LishBuf=MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParmSetHeadnum; //参数在数据库中的偏移量
               FLASHDATABASE[LishBuf].Sbyte=SpSetCursorMove;
               //FLASH_SaveModifParm();                             //保存特殊设置参数
							 FLASH_SavepParm();
               ChSpPosFlag=0;ParmSetCurDisFlag=0; LCDBitParmFlag=0;
			         KeyMenulevel=0x05; 
              }
			        if(sPn_CUSTOM_SENSOR_TYPE==(MAINMENU.SubPtr[ParmMainPageCon]->SubItems[ParmSubPageCon]->ParmSetHeadnum))//判断是否为自定义曲线项
              {KeyMenulevel=0x09;         //进入自定义曲线
			         SetCurveParmPgHis=0; 		  //刷新自定义曲线显示
			        }   
        break;
       
        case MASK_BTN_STOP:                
             KeyMenulevel=0x01;
			       ParmMainPageConHis=0xff;  //刷新显示菜单选择页面 
               ParmSubPageCon=0;
               ParmSetCurDisFlag=0;
               SetCursorMove=0;                 //参数修改光标复位
               SpSetCursorMove=0;               //复位特殊菜单光标
               SystemParmModify=0;              //清除上次修改的参数临时值
               ChSpPosFlag=0,ChAdjustPosFlag=0;
               PassWordCursorMove=0;            //复位密码光标
               PaswordTypeToDisFlag=0;          //复位密码光标
        break;                              
        default:break;
      }
      return 6;
    }

	if(KeyMenulevel==0x07)    // 参数校验          
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
			       KeyMenulevel=0x08;		 //进入校验参数修改
		    //	 pArmAdjPageConHis=0xff;	//更新参数校验显示头
			       LcdKeySaveAdjParm();
        break;

        case MASK_BTN_STOP:                
          	 KeyMenulevel=1;
			       ParmMainPageConHis=0xff;  //刷新显示菜单选择页面 
             PaswordTypeToDisFlag=0;
			       AdjParmSetCurDisFlag=0;
			       pArmAdjPageCon=0;
        break;                              
        default:break;
      }
      return 7;
    }
	if(KeyMenulevel==0x08)          //按下确定键修改校验参数       
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
          	 LcdKeySaveAdjParm();  //保存参数校验值
			       if((AdjChMenuSpBuf!=0)&&(AdjParmSetCurDisFlag==Password0x0636)) //保存特殊参数校验序号
             {
							LishBuf=SUBMENU_AdjustPARM.SubItems[pArmAdjPageCon]->ParmSetHeadnum; //参数在数据库中的偏移量
							FLASHDATABASE[LishBuf].Sbyte=SpAdjSetCurMove;
              //FLASH_SaveModifParm();
							FLASH_SavesAdjParm();
		          LishBuf=sPa_RestFactory-sParmSetnum_ForMainPage-1;
			        if((pArmAdjPageCon==LishBuf)&&(SpAdjSetCurMove==1))DBRestore_Factory_settings();//选择了恢复出厂参数设置  
			        AdjParmSetCurDisFlag=0;
			        SpAdjSetCurMove=0;
			        KeyMenulevel=0x07;     
			       }
        break;
       
        case MASK_BTN_STOP:                
          	 KeyMenulevel=1;
			       ParmMainPageConHis=0xff;  //刷新显示菜单选择页面 
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
	
	if(KeyMenulevel==0x09)    //进入自定义曲线设置            
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
               LCDSaveCurveParmSet();         //保存自定义曲线参数
               ParmSubPageConHis=0xff;       //更新显示
               CurveCtrHis=0xff;
			         KeyMenulevel=0x05;
               SetCurveConter=0;
			         CurveParmModify1=0;
				     CurveCtrHis = 0;
			        }
         break;
         case MASK_BTN_STOP:
               KeyMenulevel=0x05;
			         ParmSubPageConHis=0xff;       //更新显示
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
函数名称: void LCDCheckDBKeyValue(void) 
功能描述:       通过数据库判断按键
输入参数: XIO模块采集按键值后放入DB数据库中，LCD将DB数据库中按键信息转化为
          LCD模块的菜单按键信息。  
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)
void LCDCheckDBKeyValue(void)            //通过数据库判断按键
{
  if((F_ENTER_STOP_LCD!=0)||(F_ENTER_ENTER!=0)||(F_ENTER_UP!=0)||(F_ENTER_DOWN!=0))
  {
     if(F_ENTER_STOP_LCD==1)Btn_buf=MASK_BTN_STOP;
     if(F_ENTER_ENTER==1)   Btn_buf=MASK_BTN_PGTURN;
     if(F_ENTER_UP==1)      Btn_buf=MASK_BTN_PAGEUP;
     if(F_ENTER_DOWN==1)    Btn_buf=MASK_BTN_PAGEDW;
   
  //   LCDLitBackLight();                   //有按键按下开启背光。 
     LCDMeunKeyCal();                    //有按键按下更新菜单标志位。 
     F_ENTER_STOP_LCD=0;
     F_ENTER_ENTER=0;
     F_ENTER_UP=0;
     F_ENTER_DOWN=0;
     Btn_buf=0;
  }
}
#endif

/*---------------------------------------------------------------------------
函数名称: void LCDCombClearAccumuDate(void) 
功能描述:  清除发动机运行数据
----------------------------------------------------------------------------*/
void LCDCombClearAccumuDate(void)
{
    EPROM_STARTNUM = 0;
	  RUNNINGHOUR    = 0;
	  RUNNINGMINUTE  = 0;
	  RUNNINGSEC     = 0;
	  KWHH           = 0;
	  KWHL           = 0;
	  MSAVE_EPROMSTARTNUM=EPROM_STARTNUM; 	  //保存起动次数
    MSAVE_RUNNINGHOUR  =RUNNINGHOUR   ; 	  //保存运行累时
    MSAVE_RUNNINGMINUTE=RUNNINGMINUTE ; 	  //保存运行累分 
    MSAVE_RUNNINGSEC   =RUNNINGSEC    ; 	  //保存运行秒 
    MSAVE_KWHH         =KWHH          ; 	  //保存千瓦时高位
    MSAVE_KWHL         =KWHL          ;	    //保存千瓦时低位
	  FLASH_SaveOtherParm();
	  KeyMenulevel=0;
    ParmMainPageCon=0;
	  MainPageConHis=0xff;                    //刷新返回参数测量页面
    AlarmflagHis=0xff;			                //当前页面处于报警列表时刷新显示
	  FirGuiDemoHis=0xff;			                //当前页面处于测量首页面
}

/*---------------------------------------------------------------------------
函数名称: void LCDCheckChangeHardTmode(void) 
功能描述:  切换到硬件测试模式
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
函数名称: void LCD_GEC400_App(void) 
功能描述:  液晶显示界面    
----------------------------------------------------------------------------*/
#if(LCD_GEC400EN==1)
void LCD_GEC400_App(void)
{ 
	//@@@@@@@@@@@@ZC
	 if(HardTestModeEn)
   {
		 LCDCheckDBKeyValue();     //通过数据库判断按键
     LCD_RefreshDisPage();
	   LCDCheckChangeHardTmode();//切换到测试模式
	 } else
  {
		 HardTestLoop();          //硬件测试程序
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
  GUI_DispStringHCenterAt("发电机组控制器", (LCD_GET_XSIZE() / 2)+5, y += 50);	  

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
   GUI_DispStringAt("Amp        A ",5,115);GUI_DispStringAt("    ℃ ",230,115);
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
   if(!Language_select)GUI_DispStringAt("   Stop      Manual    Auto ",4,174);//英文
   else                GUI_DispStringAt("   停机      手动      自动 ",4,174);
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
   GUI_DispStringAt("    ℃ ", 75,115);GUI_DispStringAt("     % ",230,115);
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
   if(!Language_select)GUI_DispStringAt("   Stop      Manual    Auto ",4,174);//英文
   else                GUI_DispStringAt("   停机      手动      自动 ",4,174);
}

void GUI_DrawOpen(unsigned char Dtype)
{if(Dtype==0)GUI_DrawBitmap(&bmopen, 200,58);
 else        GUI_DrawBitmap(&bmclose,200,58); 	
}


///********************The End *****************/
