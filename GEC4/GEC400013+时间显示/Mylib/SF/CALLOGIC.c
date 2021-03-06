//#include "ALL_Includes.h"
#include "TYPCortex.h"
M_INT8U OP_PROTECT=0;
M_INT8U GEN_PROTECT=0;
M_INT8U TEST_AMF_OK=0;
M_INT8U NowMode=0;
M_INT8U GCBSTATE=0;
M_INT8U MCBSTATE=0;
M_INT32S KWHVALUE=0;
M_INT32U *KWH;
M_INT8U StartNum;
M_INT8U IDLECTL;
STRFLG16 GENSTA;
STRFLG8  CalFlag1;
STRFLG8 xiologicflag;
struct GENSETS MYSET;

extern void LCD_GEC4XX_InitJ1939CAN(void);

// A10 B11 C12 D13 E14 F15
// F E D C B A 9 8 7 6 5 4 3 2 1 0   
#define MASK_STOPALARM1 0x02FC //1 F E D C B A - 2 3 4 5 6 7 9  
#define MASK_STOPALARM2 0xBF00 
#define MASK_STOPALARM3 0x7E00 
#define MASK_TEMPHISTOP 0x0008 //B-3

//水温、油压传感器断线停机、报警
void CAL_TempOilSensorBreakAlarm(void) 
{  //温度断线动作
    if(WATERTEMP==-32768)
    {TimerEnArr[TMR_TempSonsorBreakDel]=1;    
    }
    else
    {TimerEnArr[TMR_TempSonsorBreakDel]=0;
     F_WARN_TEMP_LOST=0;        //温度传感器断线警告
     TmpBrkStopFlag=0;
    }
    if(TimerTrig[TMR_TempSonsorBreakDel])
    {TimerTrig[TMR_TempSonsorBreakDel]=0;
     switch(BREAK_TEMP_SENSOR) 
     {
      case 0:F_WARN_TEMP_LOST=0;//温度传感器断线警告
       break;
      case 1:F_WARN_TEMP_LOST=1;//温度传感器断线警告
       break;
      case 2:F_STOP_TEMP_LOST=1;//温度传感器断线警告
             if(!TmpBrkStopFlag) {
              MYSET.NOWSTATE=STOPOUTPUT;    //得电停机�
              TimerEnArr[TMR_DES_STOPOUTPUT_DEL]=1;
             }
             TmpBrkStopFlag=1;
       break;
     }
    }
    
    //压力传感器断线动作
    if(OILPRESSURE==-32768)
    {TimerEnArr[TMR_OilSonsorBreakDel]=1;    
    }
    else
    {TimerEnArr[TMR_OilSonsorBreakDel]=0;
     F_WARN_OP_LOST=0;         //油压传感器断线警告
     OilPreBrkStopFlag=0;
    }
    if(TimerTrig[TMR_OilSonsorBreakDel])
    {TimerTrig[TMR_OilSonsorBreakDel]=0;
     switch(BREAK_OP_SENSOR) 
     {
      case 0:F_WARN_OP_LOST=0;//油压传感器断线警告
       break;
      case 1:F_WARN_OP_LOST=1;//油压传感器断线警告
       break;
      case 2:F_STOP_OP_LOST=1;//油压传感器断线停机
             if(!OilPreBrkStopFlag){
              MYSET.NOWSTATE=STOPOUTPUT;    //得电停机
              TimerEnArr[TMR_DES_STOPOUTPUT_DEL]=1;
             }
             OilPreBrkStopFlag=1;
       break;
     }
    }    
}

M_INT8U CheckTEMPHI(void)
{
   if((RAMDATABASE[sRn_DES_ALA_DATA1].ByteInt & MASK_STOPALARM1)==MASK_TEMPHISTOP
    &&(RAMDATABASE[sRn_DES_ALA_DATA2].ByteInt & MASK_STOPALARM2)==0
    &&(RAMDATABASE[sRn_GEN_ALA_DATA1].ByteInt & MASK_STOPALARM3)==0
    )
    {
        return 1;   //判断只能是温度高报警停机
    }
    else
    {
        return 0;
    }
}

M_INT8U CheckStopAlarm(void)
{
    if( (RAMDATABASE[sRn_DES_ALA_DATA1].ByteInt & MASK_STOPALARM1)>0
      ||(RAMDATABASE[sRn_DES_ALA_DATA2].ByteInt & MASK_STOPALARM2)>0
      ||(RAMDATABASE[sRn_GEN_ALA_DATA1].ByteInt & MASK_STOPALARM3)>0 )
    {
        return 1;
    } 
    else
    {
        return 0;
    }
}

int TESTZCST[10];
void StatusCheck(void)
{
    //计算运行时间
    static M_INT08U FLAG_STARTSUCC=0;
	  unsigned char GenStartSuccFlag=0;
    if(CheckStopAlarm())
    {
        DO_COMMALARM_STOP=1;
    }
    else
    {
        DO_COMMALARM_STOP=0;
    }
    if(F_STA_START_SUCC && FLAG_STARTSUCC==0)
    {
        EPROM_STARTNUM++;
    }
     
    FLAG_STARTSUCC=F_STA_START_SUCC;
    
    if(TimerTrig[TMR_1000MS])
    {  		
      TimerTrig[TMR_1000MS]=0;
      KWH=&KWHH;
      KWHVALUE+=KWALL; 
      if(KWHVALUE>=3600)
      {
        *KWH+=(KWHVALUE/3600); 
		    KWHVALUE%=3600;
      }
	    if(KWHVALUE<0)KWHVALUE=0;

      if(F_STA_START_SUCC)
      {
         RUNNINGSEC++;
         if(RUNNINGSEC>=60)
         {
           RUNNINGSEC=0;
           RUNNINGMINUTE++;
           if(RUNNINGMINUTE>=60)
           {
               RUNNINGMINUTE=0;
               RUNNINGHOUR++;
           }
        }
      }
    }
 
    if(TimerTrig[TMR_MAINS_CHECK]==0)
    {
        return;
    }
      
    //报警停机标志位检查
    F_STA_STOPALARM= F_STOP_STOP_FAIL| F_STOP_EM|F_STOP_TEMP_HI|F_STOP_OP_LO|F_STOP_SPEED_HI|
          F_STOP_SPEED_LO|F_STOP_SPEED_LOST|F_STOP_START_FAIL|F_STOP_FUEL_LO|F_STOP_WATER_LO|F_STOP_TEMP_LOST|
          F_STOP_OP_LOST|F_STOP_MAINTAIN|F_STOP_VOLT_HI|F_STOP_VOLT_LO|F_STOP_CURRENT_HI|F_STOP_FREQ_HI|
          F_STOP_FREQ_LO|F_STOP_NOFREQ|F_STOP_EXTERN;
    
    //报警警告标志位检查
     F_STA_WARN= F_WARN_FUEL_LO|F_WARN_CHARGE_LO|F_WARN_BATT_LO|F_WARN_BATT_HI|F_WARN_WATER_LO|
                 F_WARN_MAINTAIN|F_WARN_CURRENT_HI|F_WARN_TEMP_LOST|F_WARN_OP_LOST;
    
    if(STOPFLAG)          //切换到停机模式
    {    
        NowMode=0;        
    }
    if(F_ENTER_MANUAL)    //切换到手动模式
    {
        NowMode=1;
    }
    if(F_ENTER_AUTO)      //切换到自动模式
    {
        NowMode=2;
    }
    if(F_ENTER_TEST)      //切换到试机模式
    {
      if(COMMON_MODEL==MODEL420)
      {          
          NowMode=3;
      }
    }
   
    if(COMMON_INPUTFUNC1==6||COMMON_INPUTFUNC2==6||COMMON_INPUTFUNC3==6)
    {
      F_SHOW_LED_GCB=DI_GCB;
    }
    else
    {
      if(DO_GCB||GCBSTATE)
       {
        F_SHOW_LED_GCB=1;
       }
      else
       {
        F_SHOW_LED_GCB=0;
       }    
    }
    
    if(COMMON_INPUTFUNC1==7||COMMON_INPUTFUNC2==7||COMMON_INPUTFUNC3==7)
    {
      F_SHOW_LED_MCB=DI_MCB;
    }
    else
    {
      if(DI_MCB||DO_MCB||MCBSTATE)   ///  DI_MCB???????????????????
       {
        F_SHOW_LED_MCB=1;
       }
      else
       {
        F_SHOW_LED_MCB=0;
       }
    }
    
    
    //发电指示灯    
    //F_SHOW_LED_GENSET=F_STA_GEN_RUN;
    
    if(VOLTAGEA1==0 && VOLTAGEB1==0 && VOLTAGEC1==0 && GEN_FREQ==0)
    {
        F_SHOW_LED_GENSET=0;
    }
    else if(F_STA_GEN_STOP)
    {
        F_SHOW_LED_GENSET=TIME_STAMP_500MS;
    }
    
    if(F_STA_GEN_RUN)
    {
        F_SHOW_LED_GENSET=1;
    }  
    
     
    
   //网电指示灯
    if((VOLTAGEA2==0 && VOLTAGEB2==0 && VOLTAGEC2==0 && BUS_FREQ==0) ||COMMON_MODEL==MODEL410)
    {
        F_SHOW_LED_MAINS=0;
    }
    else if(F_STA_MAINS_FAIL)
    {
        F_SHOW_LED_MAINS=TIME_STAMP_500MS;
    }
    
    if(F_STA_MAINS_RUN)
    {
        F_SHOW_LED_MAINS=1;
    }
    
    
    if(F_STA_STOPALARM|F_STA_WARN)
    {
        F_SHOW_LED_ALARM=TIME_STAMP_500MS;
    }
    else
    {
        F_SHOW_LED_ALARM=0;
    }		
    if(NowMode==0)       //点亮停机灯
    {
        F_SHOW_LED_STOP=1;
    }      
    else
    {
        F_SHOW_LED_STOP=0;
    }
    
    if(NowMode==1)        //点亮手动灯
    {
        F_SHOW_LED_MANUAL=1;
    }      
    else
    {
        F_SHOW_LED_MANUAL=0;
    }
    if(NowMode==2)       //点亮自动灯
    {
        F_SHOW_LED_AUTO=1;
    }      
    else
    {
        F_SHOW_LED_AUTO=0;
    }
    if(NowMode==3)      //点亮测试灯
    {
        F_SHOW_LED_TEST=1;
    }      
    else
    {
        F_SHOW_LED_TEST=0;
    }
    
    F_STA_STOPMODE=0;
    F_STA_MANMODE=0;
    F_STA_AUTOMODE=0;
    F_STA_TESTMODE=0;    
    
    if(NowMode==0)
    {
        F_STA_STOPMODE=1;
    }
    if(NowMode==1)
    {
        F_STA_MANMODE=1;
    }
    if(NowMode==2)
    {
        F_STA_AUTOMODE=1;
    }
    if(NowMode==3)
    {
        F_STA_TESTMODE=1;
    }
    
    switch(DES_STARTSUCC_CONDITION)   //起动成功条件判断
    {
       case 0:  //磁传感器
        if(DES_SPEED>DES_STARTSUCC_SPEED)
        {
            GenStartSuccFlag=1;
        }
        else
        {
            GenStartSuccFlag=0;
        }
        break;
        
       case 1:  //发电
        if(GEN_FREQ>DES_STARTSUCC_FREQ)
        {
            GenStartSuccFlag=1;
        }
        else
        {
            GenStartSuccFlag=0;
        }        
        break;
        
       case 2:  //磁传感器+发电
        if(DES_SPEED>DES_STARTSUCC_SPEED/*||GEN_FREQ>DES_STARTSUCC_FREQ*/)
        {
            GenStartSuccFlag=1;
        }
        else
        {
            GenStartSuccFlag=0;
        }
        break;
        
       case 3: //磁传感器+油压
        if(DES_SPEED>DES_STARTSUCC_SPEED||OILPRESSURE>DES_STARTSUCC_OP)
        {
            GenStartSuccFlag=1;
        }
        else
        {
            GenStartSuccFlag=0;
        }
        break;
        
       case 4: //发电+油压
        if(GEN_FREQ>DES_STARTSUCC_FREQ||OILPRESSURE>DES_STARTSUCC_OP)
        {
            GenStartSuccFlag=1;
        }
        else
        {
            GenStartSuccFlag=0;
        }        
        
        break;
        
       case 5:  //磁传感器+发电+油压
        if(DES_SPEED>DES_STARTSUCC_SPEED||GEN_FREQ>DES_STARTSUCC_FREQ||OILPRESSURE>DES_STARTSUCC_OP)
        {
            GenStartSuccFlag=1;
        }
        else
        {
            GenStartSuccFlag=0;
        }        
       break;
			 default:break;	
    }
			
    if(GenStartSuccFlag==1)
		{
		  TimerEnArr[TMR_GenStartSuccDel]=1;
		}
		else
		{
		  TimerEnArr[TMR_GenStartSuccDel]=0;
			TimerTrig[TMR_GenStartSuccDel]=0;
      F_STA_START_SUCC = 0;
		}
		
    if(TimerTrig[TMR_GenStartSuccDel])
    {
        TimerTrig[TMR_GenStartSuccDel]=0;
        F_STA_START_SUCC = 1;
    }
		
		F_STA_STOP=1-F_STA_START_SUCC;

    if((DES_STARTSUCC_CONDITION==1 ||DES_STARTSUCC_CONDITION==2
    ||DES_STARTSUCC_CONDITION==4||DES_STARTSUCC_CONDITION==5))
    {
      switch(GEN_VOLT_TYPE)//判断连接方式
      {
        case 0:      //三相四线制
                                
        if((VOLTAGEA1<GEN_VOLTLOW_STOP||VOLTAGEB1<GEN_VOLTLOW_STOP||VOLTAGEC1<GEN_VOLTLOW_STOP) && GEN_VOLTLOW_STOP!=30)
        {
            GEN_STA_VOLT_LOW=1;
        }
        else
        {
            GEN_STA_VOLT_LOW=0;
        }
        
        if((VOLTAGEA1>GEN_VOLTHIGH_STOP||VOLTAGEB1>GEN_VOLTHIGH_STOP||VOLTAGEC1>GEN_VOLTHIGH_STOP) && GEN_VOLTHIGH_STOP!=360)
        {
            GEN_STA_VOLT_HIGH=1;
        }
        else
        {
            GEN_STA_VOLT_HIGH=0;
        }
                
        break;
      
      case 1:  //两相三线制
      
        if((VOLTAGEA1<GEN_VOLTLOW_STOP||VOLTAGEB1<GEN_VOLTLOW_STOP) && GEN_VOLTLOW_STOP!=30)
        {
            GEN_STA_VOLT_LOW=1;
        }
        else
        {
            GEN_STA_VOLT_LOW=0;
        }
        
        if((VOLTAGEA1>GEN_VOLTHIGH_STOP||VOLTAGEB1>GEN_VOLTHIGH_STOP) && GEN_VOLTHIGH_STOP!=360)
        {
            GEN_STA_VOLT_HIGH=1;
        }
        else
        {
            GEN_STA_VOLT_HIGH=0;
        }
                  
      break;
      
      case 2://单相
	/*
        if(VOLTAGEA1<GEN_VOLTLOW_STOP && GEN_VOLTLOW_STOP!=30)
        {
            GEN_STA_VOLT_LOW=1;
        }
        else
        {
            GEN_STA_VOLT_LOW=0;
        }
        
        if(VOLTAGEA1>GEN_VOLTHIGH_STOP && GEN_VOLTHIGH_STOP!=360)
        {
            GEN_STA_VOLT_HIGH=1;
        }
        else
        {
            GEN_STA_VOLT_HIGH=0;
        }      
*/		//发电C相有频率检测电路，故只能接C相，电压检测、频率检测<<<<<<<<<<<<<<<<<<<<<<<<
			if(VOLTAGEC1<GEN_VOLTLOW_STOP && GEN_VOLTLOW_STOP!=30)
        {
            GEN_STA_VOLT_LOW=1;		//电压低
        }
        else
        {
            GEN_STA_VOLT_LOW=0;		//
        }
        
        if(VOLTAGEC1>GEN_VOLTHIGH_STOP && GEN_VOLTHIGH_STOP!=360)
        {
            GEN_STA_VOLT_HIGH=1;		//电压高
        }
        else
        {
            GEN_STA_VOLT_HIGH=0;
        }     
        
       break;
      }
       if(GEN_FREQ>GEN_FREQHIGH)
        {
            GEN_STA_FREQ_HIGH=1;
        }
        else
        {
            GEN_STA_FREQ_HIGH=0;
        }
        
        if(GEN_FREQ<GEN_FREQLOW)
        {
            GEN_STA_FREQ_LOW=1;
        }
        else
        {
            GEN_STA_FREQ_LOW=0;
        }
        
        if((GEN_STA_VOLT_LOW ||GEN_STA_VOLT_HIGH||GEN_STA_FREQ_HIGH||GEN_STA_FREQ_LOW))
        {
            if(MYSET.NOWSTATE==WAITLOAD||MYSET.NOWSTATE==RUNNING)
            {              
                TimerEnArr[TMR_GEN_ABNORMAL_DEL]=1;
            }  
            F_STA_GEN_RUN=0;
            F_STA_GEN_STOP=1;
         
        }
        else
        {
            if(DES_SPEED>DES_LOWSPEED)
            {              
                F_STA_GEN_RUN=1;
                F_STA_GEN_STOP=0;
            }
            //else if(DES_SPEED>DES_LOWSPEED)
            //{
            //    F_STA_GEN_RUN=1;
            //    F_STA_GEN_STOP=0;            
            //}
            
        }  
    }
    else if(DES_STARTSUCC_CONDITION==0 || DES_STARTSUCC_CONDITION==3)
    {
        if(DES_SPEED>DES_LOWSPEED)
        {
            F_STA_GEN_RUN=1;
        }
        else            
        {
            F_STA_GEN_RUN=0;
        }
    }
	
    MYSET.NOWMODE=NowMode;
    if(TimerEnArr[TMR_GEN_ABNORMAL_DEL]==0)
    {
        TimerTrig[TMR_GEN_ABNORMAL_DEL]=0;
    }
     //发电异常检测
    if((MYSET.NOWSTATE==WAITLOAD||MYSET.NOWSTATE==RUNNING)&&
    (DES_STARTSUCC_CONDITION==1 ||DES_STARTSUCC_CONDITION==2
    ||DES_STARTSUCC_CONDITION==4||DES_STARTSUCC_CONDITION==5)) //发电不正常延时到
    {        
        if(GEN_STA_VOLT_LOW)
        {   
            TimerEnArr[TMR_GEN_VOLTLOW_STOP_DEL]=1;  
        }else
        {   TimerEnArr[TMR_GEN_VOLTLOW_STOP_DEL]=0;
        }
        
        if(GEN_STA_VOLT_HIGH)
        {   
           TimerEnArr[TMR_GEN_VOLTHIGH_STOP_DEL]=1;  
        }else{
           TimerEnArr[TMR_GEN_VOLTHIGH_STOP_DEL]=0; 
        }
        
        if(GEN_STA_FREQ_LOW)
        {
           TimerEnArr[TMR_GEN_FREQLOW]=1;            
        }
        else
        {
           TimerEnArr[TMR_GEN_FREQLOW]=0;
        }
        
        if(GEN_STA_FREQ_HIGH)
        {
           TimerEnArr[TMR_GEN_FREQHIGH]=1;            
        }
        else
        {
           TimerEnArr[TMR_GEN_FREQHIGH]=0;
        }
        
        if(TimerTrig[TMR_GEN_VOLTLOW_STOP_DEL])
        {
           TimerTrig[TMR_GEN_VOLTLOW_STOP_DEL]=0;
           F_STOP_VOLT_LO=1;
        }
        
        if(TimerTrig[TMR_GEN_VOLTHIGH_STOP_DEL])
        {
           TimerTrig[TMR_GEN_VOLTHIGH_STOP_DEL]=0;
           F_STOP_VOLT_HI=1;
        }
        
        if(TimerTrig[TMR_GEN_FREQLOW])
        {
           TimerTrig[TMR_GEN_FREQLOW]=0;
           F_STOP_FREQ_LO=1;
        }
        
        if(TimerTrig[TMR_GEN_FREQHIGH])
        {
           TimerTrig[TMR_GEN_FREQHIGH]=0;
           F_STOP_FREQ_HI=1;
        }
    }
    else
    {
        TimerEnArr[TMR_GEN_VOLTLOW_STOP_DEL]=0;
        TimerEnArr[TMR_GEN_VOLTHIGH_STOP_DEL]=0;
        TimerEnArr[TMR_GEN_FREQLOW]=0;
        TimerEnArr[TMR_GEN_FREQHIGH]=0;
    }
    
   
   
   if((VOLTAGEA2>MAINS_VOLT_HIGH||VOLTAGEB2>MAINS_VOLT_HIGH||VOLTAGEC2>MAINS_VOLT_HIGH) && MAINS_VOLT_HIGH!=360 && COMMON_MODEL==MODEL420)
   {
       F_MAINS_VOLT_HI=1;
   }
   else if((VOLTAGEA2<MAINS_VOLT_HIGH-10 && VOLTAGEB2<MAINS_VOLT_HIGH-10 && VOLTAGEC2<MAINS_VOLT_HIGH-10)||MAINS_VOLT_HIGH==360 || COMMON_MODEL==MODEL410)
   {
       //市电大于设置回差值10V取消过压判断
       F_MAINS_VOLT_HI=0;
   }
   
   if((VOLTAGEA2<MAINS_VOLT_LOW||VOLTAGEB2<MAINS_VOLT_LOW||VOLTAGEC2<MAINS_VOLT_LOW) && MAINS_VOLT_LOW!=30 && COMMON_MODEL==MODEL420)
   {
       F_MAINS_VOLT_LO=1;
   }
   else if((VOLTAGEA2>MAINS_VOLT_LOW+10 && VOLTAGEB2>MAINS_VOLT_LOW+10 && VOLTAGEC2>MAINS_VOLT_LOW+10) || MAINS_VOLT_LOW==30|| COMMON_MODEL==MODEL410)   
   {
       //市电大于设置回差值10V取消欠压判断
       F_MAINS_VOLT_LO=0;
   }  
     
    
  
  if(COMMON_MODEL==MODEL420)
  {
    //市电异常判断       
   if((F_MAINS_VOLT_HI||F_MAINS_VOLT_LO) &&TimerEnArr[TMR_MAINS_NORMAL_DEL]==0&&F_STA_MAINS_FAIL==0)
    {
        TimerEnArr[TMR_MAINS_ABNORMAL_DEL]=1;
        F_STA_MAINS_FAIL_CHECK=1;
    }
    //市电正常判断   
    if((F_MAINS_VOLT_HI==0 && F_MAINS_VOLT_LO==0) &&TimerEnArr[TMR_MAINS_ABNORMAL_DEL]==0&&F_STA_MAINS_RUN==0)
    {
        TimerEnArr[TMR_MAINS_NORMAL_DEL]=1;
        F_STA_MAINS_NORMAL_CHECK=1;
    }
   //市电异常判断完毕
    if(TimerTrig[TMR_MAINS_ABNORMAL_DEL])
    {
        TimerTrig[TMR_MAINS_ABNORMAL_DEL]=0;
        
        if(F_MAINS_VOLT_HI||F_MAINS_VOLT_LO)
        {          
            F_STA_MAINS_RUN=0;
            F_STA_MAINS_FAIL=1;                                 
        }
        TimerEnArr[TMR_MAINS_ABNORMAL_DEL]=0;
         F_STA_MAINS_FAIL_CHECK=0; 
    }
    
    //市电正常判断完毕
    if(TimerTrig[TMR_MAINS_NORMAL_DEL])
    {
        TimerTrig[TMR_MAINS_NORMAL_DEL]=0;
        if(F_MAINS_VOLT_HI==0&&F_MAINS_VOLT_LO==0)
        {          
            F_STA_MAINS_FAIL=0;
            F_STA_MAINS_RUN=1; 
             
                       
        }
        TimerEnArr[TMR_MAINS_NORMAL_DEL]=0;
        F_STA_MAINS_NORMAL_CHECK=0;
    }
  }
  else
  {     
      F_STA_MAINS_RUN=0;
      F_STA_MAINS_FAIL=0;
      TimerEnArr[TMR_MAINS_ABNORMAL_DEL]=0;
      TimerTrig[TMR_MAINS_ABNORMAL_DEL]=0;
  
  }
     
   //无发电报警检测
   if(MYSET.NOWSTATE==WAITLOAD && (DES_STARTSUCC_CONDITION==1 
   ||DES_STARTSUCC_CONDITION==2
   ||DES_STARTSUCC_CONDITION==4
   ||DES_STARTSUCC_CONDITION==5))
   {
       if(GEN_FREQ==0)
       {      
           F_STOP_NOFREQ=1;
       }
   }
  
    
    //过流检测
    if((M_INT32U)CURRENTA*10/(M_INT32U)GEN_RATINGCURRENT>GEN_OVERCURRENT
    ||(M_INT32U)CURRENTB*10/(M_INT32U)GEN_RATINGCURRENT>GEN_OVERCURRENT
    ||(M_INT32U)CURRENTC*10/(M_INT32U)GEN_RATINGCURRENT>GEN_OVERCURRENT)
    {
        if(TimerSet[TMR_GEN_OVERCURRENT_DEL]>0)
        {
            TimerEnArr[TMR_GEN_OVERCURRENT_DEL]=1;
            if(TimerTrig[TMR_GEN_OVERCURRENT_DEL])
            {
                TimerTrig[TMR_GEN_OVERCURRENT_DEL]=0;
                F_STOP_CURRENT_HI=1;
            }
        }
        else
        {
            F_WARN_CURRENT_HI=1;
        }
        
    }
    else
    {
        F_WARN_CURRENT_HI=0;
        TimerEnArr[TMR_GEN_OVERCURRENT_DEL]=0;
    }
    
    //电池过压欠压警告
    if(PowerVoltage<DES_BATTLOW)
    {
        TimerEnArr[TMR_DES_BATTLOW_DEL]=1;
    }
    else
    {
        TimerEnArr[TMR_DES_BATTLOW_DEL]=0;
        F_WARN_BATT_LO=0;
    }
    
    if(PowerVoltage>DES_BATTHI)
    {
        TimerEnArr[TMR_DES_BATTHI_DEL]=1;
    }
    else
    {
        TimerEnArr[TMR_DES_BATTHI_DEL]=0;
        F_WARN_BATT_HI=0;
    }
    
    
    if(TimerTrig[TMR_DES_BATTHI_DEL])
    {
        TimerTrig[TMR_DES_BATTHI_DEL]=0;
        F_WARN_BATT_HI=1;
    }
    
    if(TimerTrig[TMR_DES_BATTLOW_DEL])
    {
        TimerTrig[TMR_DES_BATTLOW_DEL]=0;
        F_WARN_BATT_LO=1;
    }
    
    
    //D+失败检测
    
    if(ChargerVoltage<DES_CHARGEFAULT && MYSET.NOWSTATE==RUNNING)
    {
        TimerEnArr[TMR_DES_DFAIL]=1;    
    }
    else
    {      
        TimerEnArr[TMR_DES_DFAIL]=0;
        F_WARN_CHARGE_LO=0;
    }
    
    if(TimerTrig[TMR_DES_DFAIL])
    {
        TimerTrig[TMR_DES_DFAIL]=0;
        F_WARN_CHARGE_LO=1;
    }
    
      //油压低检测
    if(/*(MYSET.NOWSTATE==STARTWARM) ||*/(MYSET.NOWSTATE==WAITLOAD) || (MYSET.NOWSTATE==RUNNING))
    {
       //油压低并且无断线
       if(OILPRESSURE<DES_LOWOP&&OILPRESSURE!=-32768&& DES_LOWOP!=0) 
       {
         TimerEnArr[TMR_OILPRESSURE_LOW]=1; 
       }
       else
       {      
         TimerEnArr[TMR_OILPRESSURE_LOW]=0;
         TimerTrig[TMR_OILPRESSURE_LOW]=0;
         // F_WARN_OP_LO=0;
       }
       
       if(TimerTrig[TMR_OILPRESSURE_LOW]||DI_OPLOW)
       {
           TimerTrig[TMR_OILPRESSURE_LOW]=0;
           if(DES_OPLOW_NOSTOP==1||DI_OPLOW_NOSTOP)
           {            
               F_WARN_OP_LO=1;               
           }
           else
           {
               F_STOP_OP_LO=1;
           }
       }
      else
      {
        if(TimerEnArr[TMR_OILPRESSURE_LOW]==0)
        {
          F_WARN_OP_LO=0;
        }
      }
    } 
    else
    {
      TimerEnArr[TMR_OILPRESSURE_LOW]=0;
      TimerTrig[TMR_OILPRESSURE_LOW]=0;
    }
   ////水温高并且无断线
   if((MYSET.NOWSTATE==STARTWARM) ||(MYSET.NOWSTATE==WAITLOAD) || (MYSET.NOWSTATE==RUNNING))
   {
     //水温高并且无断线
       if((WATERTEMP>DES_HITEMP&&WATERTEMP!=-32768 && DES_HITEMP!=140)||DI_TEMPHIGH)
       {       
           if(DES_TEMPHIGH_NOSTOP==1||DI_TEMPHIGH_NOSTOP)
           {            
               F_WARN_TEMP_HI=1;               
           }
           else
           {            
               TimerEnArr[TMR_WaterTempHiStopDel]=1;
               if(TimerTrig[TMR_WaterTempHiStopDel]==1)
               {F_STOP_TEMP_HI=1;
                TimerTrig[TMR_WaterTempHiStopDel]=0;
               }
           }
       }
       else
       {
          F_WARN_TEMP_HI=0;
				  TimerEnArr[TMR_WaterTempHiStopDel]=0;
          TimerTrig[TMR_WaterTempHiStopDel]=0;
       }
   }
   else
   {
    TimerEnArr[TMR_WaterTempHiStopDel]=0;
    TimerTrig[TMR_WaterTempHiStopDel]=0;
   }
		
		
   //温度压力传感器断线动作
    CAL_TempOilSensorBreakAlarm();
    //超速报警
    if(DES_SPEED>DES_HIGHSPEED)
    {
        TimerEnArr[TMR_DES_SPEEDHI]=1;   
    }
    else
    {
        TimerEnArr[TMR_DES_SPEEDHI]=0;  
    }
    
    if(TimerTrig[TMR_DES_SPEEDHI])
    {
        TimerTrig[TMR_DES_SPEEDHI]=0;
        F_STOP_SPEED_HI=1;
    }
    
    //欠速报警    
    if(DES_SPEED<DES_LOWSPEED && F_STA_START_SUCC && (MYSET.NOWSTATE>STARTWARM && MYSET.NOWSTATE<STOPIDLE)&&DES_SPEED!=0)
    {
        TimerEnArr[TMR_DES_LOWSPEED]=1;
    } 
    else
    {
        TimerEnArr[TMR_DES_LOWSPEED]=0;
    }
    
    if(TimerTrig[TMR_DES_LOWSPEED])
    {
        TimerTrig[TMR_DES_LOWSPEED]=0;
        F_STOP_SPEED_LO=1;
    }
     
  //急停
	/*
  if((POWERLOSS==0)&&(F_INPUT_EMSTOP)) 
  {
    TimerEnArr[TMR_EMSTOPENABLE]=1;
  } 
  else
  {
    TimerEnArr[TMR_EMSTOPENABLE]=0;
    TimerTrig[TMR_EMSTOPENABLE]=0;
  }
  if(TimerTrig[TMR_EMSTOPENABLE])
  {
    TimerTrig[TMR_EMSTOPENABLE]=0;
    //if(ATD0DR6>560) F_STOP_EM=1;
  }
	*/
		
  F_STOP_EM = DI_F_STOP_EM ;//急停开关量输入
		
    //水位低报警停机
  if(DI_LOWLIQUID_STOP)
  {
      F_STOP_WATER_LO=1;
  }

//燃油位低警告输入或者检测油位低于阀值时警告

if(FUEL<DES_LOWLEVEL && DES_LOWLEVEL!=0  && FUEL !=-32768) 
{
    TimerEnArr[TMR_DES_LOWFUEL]=1;
}
else
{
    TimerEnArr[TMR_DES_LOWFUEL]=0;
    TimerTrig[TMR_DES_LOWFUEL]=0;
    F_WARN_FUEL_LO=0;
}

if(DI_LOWFUEL_WRN||TimerTrig[TMR_DES_LOWFUEL])
{
    TimerTrig[TMR_DES_LOWFUEL]=0;
    F_WARN_FUEL_LO=1;
}


if(F_OUTPUT_FUEL) //D+输出检测控制
{
 F_OUTPUT_DCHAR=1; 
}
else
{
 F_OUTPUT_DCHAR=0;
}

//燃油位低停机输入时报警停机
if(DI_LOWFUEL_STOP)
{
    F_STOP_FUEL_LO=1;
}

   
    //转速丢失信号检测
    if(DES_SPEED==0 && (MYSET.NOWSTATE>SAFERUNNING && MYSET.NOWSTATE<=STOPIDLE))
    {        
       TimerEnArr[TMR_DES_LOSTSPEED_DEL]=1;
       if(TimerTrig[TMR_DES_LOSTSPEED_DEL])
       { 
        TimerTrig[TMR_DES_LOSTSPEED_DEL]=0;
        if(TimerSet[TMR_DES_LOSTSPEED_DEL]==0){F_WARN_SPEEDLOST=1; }//转速丢失信号延时设置为0，只警告 
        else                                  {F_STOP_SPEED_LOST=1;}//转速丢失信号延时设置不为0，报警停机
       }
     }
     else
     {
         F_WARN_SPEEDLOST=0;
         TimerEnArr[TMR_DES_LOSTSPEED_DEL]=0;
         TimerTrig[TMR_DES_LOSTSPEED_DEL]=0;
     }
    
    if(F_STOP_STOP_FAIL)
    {
        if(F_STA_START_SUCC==0)
        {
            TimerEnArr[TMR_DES_STOPSUCC]=1;
        }
        else
        {
            TimerEnArr[TMR_DES_STOPSUCC]=0;
        }
    }
    
    if(TimerTrig[TMR_DES_STOPSUCC])
    {
        TimerTrig[TMR_DES_STOPSUCC]=0;
        F_STOP_STOP_FAIL=0;
    }
    
    if(MYSET.ALARMSTOP)    
    {
        if(CheckStopAlarm()==0)
        {
            MYSET.NOWSTATE=STOPED;
            MYSET.ALARMSTOP=0;
        }
        else
        {
            if(F_STA_START_SUCC==0)
            {
                MYSET.NOWSTATE=INHIBITSTART;
            }
        }
    }
		
		if((NowMode==0)||(MYSET.NOWSTATE==STOPOUTPUT)||(MYSET.NOWSTATE==INHIBITSTART)||MYSET.ALARMSTOP)//停机故障取消发电正常指示
		{
		  F_STA_GEN_RUN=0;
      F_STA_GEN_STOP=1;
		}
}

void StartStopLogic(void)
{
    if(STOPFLAG)           //停机模式处理（清标志位）
    {
        STOPFLAG=0;  
        MYSET.STOPREQ=1;              
    }    
    if(F_ENTER_MANUAL)    //手动模式处理（清标志位）
    {
     //   if(MYSET.NOWSTATE==STOPED)
     //   {
     //   }
        F_ENTER_MANUAL=0;        
    }
    if(F_ENTER_AUTO)     //自动模式处理（清标志位）
    {
        F_ENTER_AUTO=0;        
    }
    if(F_ENTER_TEST)      //测试模式处理（清标志位）
    {
        F_ENTER_TEST=0;        
    }    
    
    if(F_ENTER_START)    //起动处理（清标志位）
    {
        F_ENTER_START=0;
        if(NowMode==MODE_MAN||NowMode==MODE_TEST)
        {
            MYSET.STARTREQ=1;
        }
    }
        
    if(MYSET.STOPREQ) //停机请求
    {
     if(MYSET.ALARMSTOP==0 ||(DI_ENCOOLING && CheckTEMPHI()))//普通停机
     {                  
        if(MYSET.NOWSTATE==PREHEAT||MYSET.NOWSTATE==AMFSTART)
        {
            MYSET.NOWSTATE=STOPED;
        }
        if(MYSET.NOWSTATE==CRANKING||MYSET.NOWSTATE==FUELOUTPUT
           ||(MYSET.NOWSTATE==CRANKINT) 
           ||MYSET.NOWSTATE==SAFERUNNING||MYSET.NOWSTATE==STARTIDLE
           ||MYSET.NOWSTATE==STOPCOOLING||MYSET.NOWSTATE==STOPIDLE)
        {
            MYSET.NOWSTATE=STOPOUTPUT;
            TimerEnArr[TMR_DES_STOPOUTPUT_DEL]=1;
        }
        if(MYSET.NOWSTATE==STARTWARM)
        {
            MYSET.NOWSTATE=STOPIDLE;
            TimerEnArr[TMR_DES_STOPIDLE_DEL]=1;
        }
        if(MYSET.NOWSTATE==WAITLOAD||MYSET.NOWSTATE==RUNNING)
        {
            MYSET.NOWSTATE=STOPCOOLING;
            
            TimerEnArr[TMR_DES_COOLING_DEL]=1;
        }
     }
    else
     {
            if(F_STA_START_SUCC 
            && MYSET.NOWSTATE!=STOPOUTPUT 
            && MYSET.NOWSTATE!=WAITSTOP
            && MYSET.NOWSTATE!=STOPFAIL 
            && MYSET.NOWSTATE!=STOPED 
            && MYSET.NOWSTATE!=INHIBITSTART)
            {
                MYSET.NOWSTATE=STOPOUTPUT;
                TimerEnArr[TMR_DES_STOPOUTPUT_DEL]=1;
            }
      }
        MYSET.STOPREQ=0;
        MYSET.ALARMSTOP=0; 
        TimerEnArr[TMR_AMF_START_DEL]=0;
        TimerEnArr[TMR_AMF_STOP_DEL]=0;
    
    }
  
      if(MYSET.STARTREQ)
      {
          MYSET.STARTREQ=0;
          if(MYSET.NOWSTATE==STOPED)
          {
             if(MYSET.INHIBITSTART==0)
             {              
                 MYSET.NOWSTATE=PREHEAT;
                 TimerEnArr[TMR_DES_PREHEAT_DEL]=1;
             }         
          }
      }  
    
  if(MYSET.NOWMODE==AUTO)
    {

      if(((COMMON_MODEL==MODEL420&&F_STA_MAINS_FAIL)||(COMMON_MODEL==MODEL410&&DI_RMTSTART)) && F_STA_START_SUCC==0 && MYSET.INHIBITSTART==0 && MYSET.NOWSTATE==STOPED && DI_INHIBIT_AUTOSTART==0)
      {                          
          //MYSET.AUTOSTARTREQ=1;
          TimerEnArr[TMR_AMF_START_DEL]=1;//开机延时开始                    
      }else{
          TimerTrig[TMR_AMF_START_DEL]=0;
          TimerEnArr[TMR_AMF_START_DEL]=0; //开机延时终止2014-10-08
      }
      
      if(((COMMON_MODEL==MODEL420&&F_STA_MAINS_RUN)||(COMMON_MODEL==MODEL410&&DI_RMTSTART==0))||DI_INHIBIT_AUTOSTART==1)
      {                                    
          //MYSET.AUTOSTOPREQ=1;                    
          if(MYSET.NOWSTATE>=PREHEAT && MYSET.NOWSTATE<=RUNNING)
          {
              TimerEnArr[TMR_AMF_STOP_DEL]=1;//停机延时开始
          }
      }else{
          TimerTrig[TMR_AMF_STOP_DEL]=0;
          TimerEnArr[TMR_AMF_STOP_DEL]=0; //停机延时终止2014-10-08
      }
      
    }
      
    if(TimerEnArr[TMR_AMF_START_DEL]==1)
    {
        F_STA_STARTDEL=1;        
    }
    else
    {
        F_STA_STARTDEL=0;        
    }
    
    if(TimerEnArr[TMR_AMF_STOP_DEL]==1)
    {
        F_STA_STOPDEL=1;        
    }
    else
    {
        F_STA_STOPDEL=0;        
    }
    
    
    if(TimerTrig[TMR_AMF_START_DEL])
    {
        MYSET.STARTREQ=1;        
        TimerTrig[TMR_AMF_START_DEL]=0;
        TimerEnArr[TMR_AMF_START_DEL]=0;
    }   
    
    if(TimerTrig[TMR_AMF_STOP_DEL])
    {
        MYSET.STOPREQ=1;
        TimerTrig[TMR_AMF_STOP_DEL]=0;
        TimerEnArr[TMR_AMF_STOP_DEL]=0;
    }   
    
   if(MYSET.NOWSTATE==STOPED)
    {
        F_OUTPUT_FUEL=0;
        IDLECTL=0;
        if(F_STA_START_SUCC)//如果切为手动模式已起动成功则进入安全运行
        {
            if(MYSET.NOWMODE!=0)
            {              
                MYSET.NOWSTATE=SAFERUNNING;
                TimerEnArr[TMR_DES_SAFE_DEL]=1;
                F_OUTPUT_FUEL=1;
            }
        }
    }
    
    if(MYSET.NOWSTATE==PREHEAT)//如果在预热状态
    {      
        if(TimerTrig[TMR_DES_PREHEAT_DEL]==1) //判断预热是否结束
        {
            TimerTrig[TMR_DES_PREHEAT_DEL]=0; //清定时器标志
            MYSET.NOWSTATE=FUELOUTPUT;        //进入供油阶段
            TimerEnArr[TMR_DES_FUELOUT_DEL]=1;//燃油输出定时器开始
            F_OUTPUT_FUEL=1;                  //燃油输出 
        }
        F_STA_PRESTART=1;
        DO_PREHEAT=1;
    }
    else
    {
        TimerEnArr[TMR_DES_PREHEAT_DEL]=0;//不在预热状态清零定时器
        F_STA_PRESTART=0;
        DO_PREHEAT=0;
    }
    
    if(MYSET.NOWSTATE==FUELOUTPUT)
    {    
        if(TimerTrig[TMR_DES_FUELOUT_DEL]==1) //判断预热是否结束
        {
            TimerTrig[TMR_DES_FUELOUT_DEL]=0; //清定时器标志
            MYSET.NOWSTATE=CRANKING;        //进入供油阶段
            TimerEnArr[TMR_DES_CRANK_DEL]=1;//燃油输出定时器开始            
        }
        F_STA_FUELOUTPUT=1;
    }
    else
    {
        TimerEnArr[TMR_DES_FUELOUT_DEL]=0;
        F_STA_FUELOUTPUT=0;
    }
    
    if(MYSET.NOWSTATE==CRANKING)
    {   
        F_OUTPUT_CRANK=1;                  //起动输出 
        if(TimerTrig[TMR_DES_CRANK_DEL]==1) //判断起动延时是否结束
        {
            TimerTrig[TMR_DES_CRANK_DEL]=0; //清定时器标志
            StartNum++;
            if(StartNum>=DES_START_NUM)
            {
                StartNum=0;
                F_OUTPUT_CRANK=0;
                TimerEnArr[TMR_DES_CRANK_DEL]=0;  
                MYSET.ALARMSTOP=1;
                F_STOP_START_FAIL=1;              
            }
            else
            {            
                MYSET.NOWSTATE=CRANKINT;
                TimerEnArr[TMR_DES_CRANKINT_DEL]=1;
                F_OUTPUT_CRANK=0;
                F_OUTPUT_FUEL=0;
            }
        }                     
        F_STA_CRANK=1;
        if(F_STA_START_SUCC)//如果起动成功
        {
             StartNum=0;
             MYSET.NOWSTATE=SAFERUNNING;  //进入安全运行延时
             TimerEnArr[TMR_DES_SAFE_DEL]=1;
             F_OUTPUT_CRANK=0;            //起动马达脱开
        }
    }
    else
    {
        F_STA_CRANK=0;        
        F_OUTPUT_CRANK=0;
        TimerEnArr[TMR_DES_CRANK_DEL]=0;
    }
        
    if(MYSET.NOWSTATE==CRANKINT)         //起动间隔处理
    {
        if(TimerTrig[TMR_DES_CRANKINT_DEL])
        {
            TimerTrig[TMR_DES_CRANKINT_DEL]=0;
            TimerEnArr[TMR_DES_CRANK_DEL]=1;
            MYSET.NOWSTATE=FUELOUTPUT;
            TimerEnArr[TMR_DES_FUELOUT_DEL]=1;//燃油输出定时器开始
            F_OUTPUT_FUEL=1;                  //燃油输出 
        }
        
        if(F_STA_START_SUCC)//如果起动成功
        {
             StartNum=0;
             MYSET.NOWSTATE=SAFERUNNING;  //进入安全运行延时
             TimerEnArr[TMR_DES_SAFE_DEL]=1;
             F_OUTPUT_CRANK=0;            //起动马达脱开
        }
        F_STA_START_RETRY=1;
    }
    else
    {
        F_STA_START_RETRY=0;
        TimerEnArr[TMR_DES_CRANKINT_DEL]=0;
    }
    
    if(MYSET.NOWSTATE==STOPOUTPUT)StartNum=0; //得电停机状态复位起动次数
    
    if(MYSET.NOWSTATE==SAFERUNNING)          //安全运行状态
    {
        if(TimerTrig[TMR_DES_SAFE_DEL])
        {
            TimerTrig[TMR_DES_SAFE_DEL]=0;
            MYSET.NOWSTATE=STARTIDLE;
            TimerEnArr[TMR_DES_STARTIDLE_DEL]=1;
        }
        F_STA_TIMER_SAFE=1;
        F_OUTPUT_FUEL=1;
    }
    else
    {
        F_STA_TIMER_SAFE=0;
        TimerEnArr[TMR_DES_SAFE_DEL]=0;
    }
    
    if(MYSET.NOWSTATE==STARTIDLE)            //起动怠速状态
    {
        if(TimerTrig[TMR_DES_STARTIDLE_DEL])
        {
            TimerTrig[TMR_DES_STARTIDLE_DEL]=0;
            MYSET.NOWSTATE=STARTWARM;
            TimerEnArr[TMR_DES_WARM_DEL]=1;
        }
        F_STA_IDLE=1;
        
    }
    else
    {
        F_STA_IDLE=0;
        TimerEnArr[TMR_DES_STARTIDLE_DEL]=0;
    }    
    
    
    if(MYSET.NOWSTATE==STARTWARM)          //起动暖机状态
    {
        if(TimerTrig[TMR_DES_WARM_DEL])
        {
            TimerTrig[TMR_DES_WARM_DEL]=0;
            MYSET.NOWSTATE=WAITLOAD; 
            TimerEnArr[TMR_GEN_ABNORMAL_DEL]=1;           
        }
        F_STA_WARM=1;
        IDLECTL=1;
        DO_RAISE_SPEED=1;
        DO_HIGHSPEEDWARM=1;
    }
    else
    {
        F_STA_WARM=0;
        TimerEnArr[TMR_DES_WARM_DEL]=0;
        DO_RAISE_SPEED=0;
    }    
    
    if(MYSET.NOWSTATE==WAITLOAD)           //等待带载阶段                
    {
        if(F_STA_GEN_RUN)
        {
            //TimerEnArr[TMR_GEN_ABNORMAL_DEL]=0;
            MYSET.NOWSTATE=RUNNING;
        }
        F_STA_WAITLOAD=1;
    }
    else
    {
        //TimerEnArr[TMR_GEN_ABNORMAL_DEL]=0;           
        F_STA_WAITLOAD=0;       
    }  
    
    if(MYSET.NOWSTATE==WAITLOAD || MYSET.NOWSTATE==RUNNING)
    {
        TimerEnArr[TMR_GEN_ABNORMAL_DEL]=1;
    }
    else
    {
        TimerEnArr[TMR_GEN_ABNORMAL_DEL]=0;
    }
    
    if(MYSET.NOWSTATE==RUNNING)     //发电机正常运行
    {
        F_STA_GEN_SUPP=1;
        F_STA_DES_RUN=1;
    }
    else
    {
        F_STA_GEN_SUPP=0;
        F_STA_DES_RUN=0;
    }
            
      
    if(MYSET.NOWSTATE==STOPCOOLING)    //停机散热阶段
    {        
        
        if(TimerEnArr[TMR_DES_COOLING_DEL]==0)
        {
           TimerEnArr[TMR_DES_COOLING_DEL]=1;
        }
        
        if(TimerTrig[TMR_DES_COOLING_DEL])
        {
            TimerTrig[TMR_DES_COOLING_DEL]=0;
            TimerEnArr[TMR_DES_COOLING_DEL]=0;
            MYSET.NOWSTATE=STOPIDLE;
            TimerEnArr[TMR_DES_STOPIDLE_DEL]=1;
        }
        F_STA_COOL=1;
        
    }
    else
    {
        F_STA_COOL=0;
        TimerEnArr[TMR_DES_COOLING_DEL]=0;
    }
     
    
    if(MYSET.NOWSTATE==STOPIDLE)    //停机怠速阶段
    {        
        if(TimerTrig[TMR_DES_STOPIDLE_DEL])
        {
            TimerTrig[TMR_DES_STOPIDLE_DEL]=0;
            MYSET.NOWSTATE=STOPOUTPUT;
            TimerEnArr[TMR_DES_STOPOUTPUT_DEL]=1;
        }
        F_STA_STOP_IDLE=1;
        IDLECTL=0;
        DO_HIGHSPEEDWARM=0;        
    }
    else
    {
        F_STA_STOP_IDLE=0;
        TimerEnArr[TMR_DES_STOPIDLE_DEL]=0;
    }      
        
    if(F_STOP_EM==1)         //当急停时走得电停机
    {
      if(EM_OnPowerstopFlag==0) 
      {
        MYSET.NOWSTATE=STOPOUTPUT; 
        TimerEnArr[TMR_DES_STOPOUTPUT_DEL]=1;
        EM_OnPowerstopFlag=1; 
      }
    }
    else 
    {EM_OnPowerstopFlag=0;
    }
    
    if(MYSET.NOWSTATE==STOPOUTPUT)    //得电停机状态
    { 
/*			if(DES_SPEED<300)     //已经停机终止延时
        { TimerTrig[TMR_DES_STOPOUTPUT_DEL]=1;
          TimerEnArr[TMR_DES_STOPOUTPUT_DEL]=0; 
        }
*/      
        if(TimerTrig[TMR_DES_STOPOUTPUT_DEL])
        {
            TimerTrig[TMR_DES_STOPOUTPUT_DEL]=0;
            MYSET.NOWSTATE=WAITSTOP;
            TimerEnArr[TMR_DES_STOPSUCC_DEL]=1; 
        }
        F_STA_STOPOUTPUT=1;
        F_OUTPUT_FUEL=0;
        DO_STOPOUTPUT=1;
        IDLECTL=0;
    }
    else
    {
        F_STA_STOPOUTPUT=0;       
        TimerEnArr[TMR_DES_STOPOUTPUT_DEL]=0;
        DO_STOPOUTPUT=0;
    }
    if(MYSET.NOWSTATE==STOPIDLE||MYSET.NOWSTATE==STOPOUTPUT)
    {
        DO_REDUCE_SPEED=1;
        DO_HIGHSPEEDWARM=0;
    }
    if(MYSET.NOWSTATE==STOP)
    {
        DO_REDUCE_SPEED=0;
        DO_HIGHSPEEDWARM=0;
    }
    
    if(MYSET.NOWSTATE==RUNNING)
    {
        DO_DES_RUNNING=1;
    }
    
    if(DES_SPEED<DES_STARTSUCC_SPEED)
    {
        DO_DES_RUNNING=0;
    }
    if(MYSET.NOWSTATE==WAITSTOP)    //停稳检测状态
    {
        
        if(TimerTrig[TMR_DES_STOPSUCC_DEL])
        {
            TimerTrig[TMR_DES_STOPSUCC_DEL]=0;
            
            if(F_STA_START_SUCC==0)
            {              
                MYSET.NOWSTATE=STOPED;
            }
            else
            {
                MYSET.ALARMSTOP=1;
                F_STOP_STOP_FAIL=1;
                MYSET.NOWSTATE=STOPFAIL;
            }
        }
        F_STA_STOP_CHECK=1;
        IDLECTL=0;
    }
    else
    {
        F_STA_STOP_CHECK=0;
        TimerEnArr[TMR_DES_STOPSUCC_DEL]=0;
    }
    
    if(MYSET.NOWSTATE==STOPFAIL)
    {
        if(F_STOP_STOP_FAIL==0)
        {
            MYSET.NOWSTATE=STOPED;
        }        
    }
         
    if(MYSET.ALARMSTOP)      //报警停机状态
    {
        F_OUTPUT_FUEL=0;
        F_OUTPUT_CRANK=0;        
        //F_STA_STOP_FAIL=1;
    }
    else
    {
        //F_STA_STOP_FAIL=0;
    }
                
}


void Protection(void)
{
    
    if(CheckStopAlarm()==1 && (MYSET.NOWSTATE!=STOPED && MYSET.NOWSTATE!=STOPCOOLING && MYSET.NOWSTATE!=STOPIDLE && MYSET.NOWSTATE!=STOPOUTPUT && MYSET.NOWSTATE!=WAITSTOP))
    {
        MYSET.STOPREQ=1;
        MYSET.ALARMSTOP=1;            
    }
    
    if(MYSET.NOWSTATE==INHIBITSTART)
    {
        F_OUTPUT_FUEL=0;
    }
    

}


//AMF逻辑

void AmfLogic(void)
{        
   if(TimerSet[TMR_MAINS_TRANS_DEL]>0 && TimerEnArr[TMR_MAINS_TRANS_DEL]==1)
   {
       F_STA_TRANSCB=1;   //开关转换延时
   }
   else
   {
       F_STA_TRANSCB=0;
   }
   
   if(TimerTrig[TMR_MAINS_TRANS_DEL])
   {
       TimerTrig[TMR_MAINS_TRANS_DEL]=0;
       TimerEnArr[TMR_MAINS_TRANS_DEL]=0;   
   }   
  
   if((NowMode==0)||(MYSET.NOWSTATE==STOPOUTPUT)||(MYSET.NOWSTATE==INHIBITSTART)||MYSET.ALARMSTOP)//停机模式或者故障停机
   {
       if(MYSET.NOWSTATE!=RUNNING && GCBSTATE==1)
       {
         if(GCBSTATE==1)
          {
            if(TimerSet[TMR_GEN_GCB_DEL]>0)
            {                
             TimerEnArr[TMR_OFFCB]=1;
             DO_OFFCB=1;
            }
           }
          GCBSTATE=0;                   
        }
		   DO_GCB=0;  
       GCBSTATE=0;       
   }
   
	 if(F_STOP_EM)//紧急停机分闸
	 {
	       if(GCBSTATE==1)
          {
            if(TimerSet[TMR_GEN_GCB_DEL]>0)
            {                
             TimerEnArr[TMR_OFFCB]=1;
             DO_OFFCB=1;
            }
           }
          GCBSTATE=0;   
	 }
       //发电判断合闸/分闸
    if(COMMON_MODEL==MODEL420)
    {              
       if(NowMode==1) 
       {
          //if(F_ENTER_GENSCLOSE)
          //{
          //    F_ENTER_GENSCLOSE=0;
               if(GCBSTATE==0 && MYSET.NOWSTATE==RUNNING/*&& ((F_STA_MAINS_FAIL && NowMode!=3)|| NowMode==3)*/&&TimerEnArr[TMR_MAINS_TRANS_DEL]==0&&(DI_MCB==0&&DO_MCB==0)&&DO_OFFCB==0)
               {
                   GCBSTATE=1;
               }
               else 
               {
                  if(GCBSTATE==1)
                  {
                      if(TimerSet[TMR_GEN_GCB_DEL]>0)
                       {                
                           TimerEnArr[TMR_OFFCB]=1;
                           DO_OFFCB=1;
                       }
                  }
                  GCBSTATE=0;                   
               }
         // }
       }
       if(NowMode==2)
       {        
           if(MYSET.NOWSTATE==RUNNING&& ((F_STA_MAINS_FAIL && NowMode!=3)|| NowMode==3)&&TimerEnArr[TMR_MAINS_TRANS_DEL]==0&&(DI_MCB==0&&DO_MCB==0)&&DO_OFFCB==0)
           { 
               GCBSTATE=1;           
           }
           else
           {
               if(GCBSTATE==1)
               {
                   TimerEnArr[TMR_MAINS_TRANS_DEL]=1; //如果之前为合闸，转换延时开始计时
                   if(TimerSet[TMR_GEN_GCB_DEL]>0)
                   {                
                       TimerEnArr[TMR_OFFCB]=1;
                       DO_OFFCB=1;
                   }               
               }    
               GCBSTATE=0;
           }
       }
         
     }
       
    if(COMMON_MODEL==MODEL410)
     {
       if(NowMode==1) 
       {  
          //if(F_ENTER_MAINCLOSE)
          //{
          //    F_ENTER_MAINCLOSE=0;
               if(MYSET.NOWSTATE==RUNNING && DO_OFFCB==0 && GCBSTATE==0)
               {
                   GCBSTATE=1;
               }
               //else
							 ////////////
          //}
       }
       if(NowMode==2)
       {        
           if(MYSET.NOWSTATE==RUNNING&&DO_OFFCB==0)
           { 
              GCBSTATE=1;           
           }
           else
           {
               if(GCBSTATE==1)
               {
               //TimerEnArr[TMR_MAINS_TRANS_DEL]=1; //如果之前为合闸，转换延时开始计时
                   if(TimerSet[TMR_GEN_GCB_DEL]>0)
                   {                
                       TimerEnArr[TMR_OFFCB]=1;
                       DO_OFFCB=1;
                   }
               }
               GCBSTATE=0;
           }
        }
     }
       //市电判断合闸/分闸
       if(F_STA_MAINS_FAIL)
       {                      
           if(MCBSTATE==1)
           {
               TimerEnArr[TMR_MAINS_TRANS_DEL]=1; //如果之前为合闸，转换延时开始计时
               if(TimerSet[TMR_GEN_GCB_DEL]>0)
               {                
                   TimerEnArr[TMR_OFFCB]=1;
                   DO_OFFCB=1;
               }
           }
           MCBSTATE=0;                     
       }
       
     if(TimerTrig[TMR_OFFCB])
      {
         TimerTrig[TMR_OFFCB]=0;
         DO_OFFCB=0;
      }   
          
     if(F_STA_MAINS_RUN && TimerEnArr[TMR_MAINS_TRANS_DEL]==0 && (DO_GCB==0&&DI_GCB==0) && DO_OFFCB==0)
      {         
         if(NowMode==3 && MYSET.NOWSTATE==RUNNING) 
         {
             if(MCBSTATE==1)
             {
                 TimerEnArr[TMR_MAINS_TRANS_DEL]=1;
             }
             MCBSTATE=0;
         } 
         if(NowMode==2 )
         {
             MCBSTATE=1;
         }
         if(NowMode==1)
         {
             if(F_ENTER_MAINCLOSE)
             {
                F_ENTER_MAINCLOSE=0;                
                if(MCBSTATE==0)
                {                  
                    MCBSTATE=1;
                }
                else
                {
                    MCBSTATE=0;                
                }
             }                         
         }         
         /*
         else
         {
             MCBSTATE=1;
         }
         */
      }
      else
      {
          F_ENTER_MAINCLOSE=0;
      }
      
     if(MYSET.NOWSTATE==RUNNING && NowMode==3) 
     {
         if(MCBSTATE==1)
          {
              TimerEnArr[TMR_MAINS_TRANS_DEL]=1;
          }
         MCBSTATE=0;
     }
                                     
   
    if(TimerSet[TMR_GEN_GCB_DEL]>0)
    {      
        if(GCBSTATE)
        {
            TimerEnArr[TMR_GEN_GCB_DEL]=1;
            DO_GCB=1;
        }
        else
        {
            TimerEnArr[TMR_GEN_GCB_DEL]=0;
            TimerTrig[TMR_GEN_GCB_DEL]=0;  
            DO_GCB=0;        
        }
        
        if(MCBSTATE)
        {
            TimerEnArr[TMR_GEN_MCB_DEL]=1;
            DO_MCB=1;
        }
        else
        {
            TimerEnArr[TMR_GEN_MCB_DEL]=0;
            TimerTrig[TMR_GEN_MCB_DEL]=0; 
            DO_MCB=0;       
        }
        
        if(TimerTrig[TMR_GEN_GCB_DEL])
        {            
            DO_GCB=0;
        }         
    
        if(TimerTrig[TMR_GEN_MCB_DEL])
        {            
            DO_MCB=0;
        }    
    }
    else
    {
        DO_GCB=GCBSTATE;
        DO_MCB=MCBSTATE;
    }
}

void ResetProcess(void)
{
    
    if(RESETFLAG)
    {
       RESETFLAG=0;   /*||MYSET.NOWSTATE==INHIBITSTART||MYSET.NOWSTATE==STOPFAIL)*/
       if(CheckStopAlarm()==1 && F_STA_START_SUCC==0 && (MYSET.NOWSTATE==STOPED||MYSET.NOWSTATE==INHIBITSTART))
       {        
           RAMDATABASE[sRn_DES_ALA_DATA1].Sbyte=0;
           RAMDATABASE[sRn_DES_ALA_DATA2].Sbyte=0;
           RAMDATABASE[sRn_GEN_ALA_DATA1].Sbyte=0;
       }
    }
    
    if(F_STA_START_SUCC==0 && MYSET.NOWSTATE==STOPFAIL)
    {
        MYSET.NOWSTATE=STOPED;
    }
    
    if(MYSET.ALARMSTOP)    
    {
        if(CheckStopAlarm()==0)
        {
            MYSET.NOWSTATE=STOPED;
            MYSET.ALARMSTOP=0;
        }
    }
}




void TransValue(void)
{
    TimerSet[TMR_MAINS_NORMAL_DEL]        =  MAINS_NORMAL_DEL*10;
    TimerSet[TMR_MAINS_ABNORMAL_DEL]      =  MAINS_OBNORMAL_DEL*10;
    TimerSet[TMR_MAINS_TRANS_DEL]         =  MAINS_TRANS_DEL;
    TimerSet[TMR_AMF_START_DEL]           =  AMF_START_DEL*10;
    TimerSet[TMR_DES_PREHEAT_DEL]         =  DES_PREHEAT_DEL*10;
    TimerSet[TMR_DES_CRANK_DEL]           =  DES_CRANK_DEL*10;
    TimerSet[TMR_DES_CRANKINT_DEL]        =  DES_CRANKINT_DEL*10;
    TimerSet[TMR_DES_SAFE_DEL]            =  DES_SAFE_DEL*10;  
    TimerSet[TMR_DES_STARTIDLE_DEL]       =  DES_STARTIDLE_DEL*10;
    TimerSet[TMR_DES_WARM_DEL]            =  DES_WARM_DEL*10;
    TimerSet[TMR_DES_COOLING_DEL]         =  DES_COOLING_DEL*10;
    TimerSet[TMR_DES_STOPIDLE_DEL]        =  DES_STOPIDLE_DEL*10;
    TimerSet[TMR_DES_STOPOUTPUT_DEL]      =  DES_STOPOUTPUT_DEL*10;
    TimerSet[TMR_AMF_STOP_DEL]            =  AMF_STOP_DEL*10;
    TimerSet[TMR_DES_STOPSUCC_DEL]        =  DES_STOPSUCC_DEL*10;
    TimerSet[TMR_GEN_GCB_DEL]             =  GEN_MCBGCB_DEL;
    TimerSet[TMR_GEN_ABNORMAL_DEL]        =  GEN_OBNORMAL_DEL;
    TimerSet[TMR_GEN_VOLTHIGH_STOP_DEL]   =  GEN_OBNORMAL_DEL;
    TimerSet[TMR_GEN_VOLTLOW_STOP_DEL]    =  GEN_OBNORMAL_DEL;
    TimerSet[TMR_DES_LOSTSPEED_DEL]       =  DES_LOSTSPEED_DEL;
    TimerSet[TMR_GEN_OVERCURRENT_DEL]     =  GEN_OVERCURRENT_DEL*10;
    TimerSet[TMR_COMMON_INPUTFUNC1_DELAY] =  COMMON_INPUTFUNC1_DELAY;
    TimerSet[TMR_COMMON_INPUTFUNC2_DELAY] =  COMMON_INPUTFUNC2_DELAY;
    TimerSet[TMR_COMMON_INPUTFUNC3_DELAY] =  COMMON_INPUTFUNC3_DELAY;
    TimerSet[TMR_CAN_CheckTempBrk_Del]    =  20;
    TimerSet[TMR_CAN_CheckOilPreBrk_Del]  =  20;
    //TimerSet[TMR_COMMON_INPUTFUNC6_DELAY] =  COMMON_INPUTFUNC6_DELAY;
    //TimerSet[TMR_COMMON_INPUTFUNC7_DELAY] =  COMMON_INPUTFUNC7_DELAY;
    //TimerSet[TMR_COMMON_INPUTFUNC8_DELAY] =  COMMON_INPUTFUNC8_DELAY;
    TimerSet[TMR_DES_FUELOUT_DEL]         =  10;
    TimerSet[TMR_DES_STOPSUCC]            =  20;
    TimerSet[TMR_MAINS_CHECK]             =  10;   
    TimerSet[TMR_DES_BATTHI_DEL]          =  200;
    TimerSet[TMR_DES_BATTLOW_DEL]         =  200;
    TimerSet[TMR_DES_LOWFUEL]             =  100;    
    TimerSet[TMR_DES_DFAIL]               =  50;
    TimerSet[TMR_DES_SPEEDHI]             =  20;
    TimerSet[TMR_DES_LOWSPEED]            =  100;
    TimerSet[TMR_GEN_FREQLOW]             =  100;
    TimerSet[TMR_GEN_FREQHIGH]            =  20;
    TimerSet[TMR_OFFCB]                   =  40;
    TimerSet[TMR_EMSTOPENABLE]            =  10;
    TimerSet[TMR_OILPRESSURE_LOW]         =  20;    //低油压延时
    TimerSet[TMR_FUELPUMP_ON]             =  100;   //燃油泵开延时
    TimerSet[TMR_FUELPUMP_OFF]            =  100;   //燃油泵关延时
   // TimerSet[TMR_hArmonic_FREQ]           =   10;   //谐波干扰频率定时
	  TimerSet[TMR_TempSonsorBreakDel]      =   20;   //温度传感器断线检测延时
    TimerSet[TMR_OilSonsorBreakDel]       =   20;   //压力传感器断线检测延时
    TimerSet[TMR_GenStartSuccDel]         =   2;    //启动成功标志延时
	  TimerSet[TMR_WaterTempHiStopDel]      =   50;   //水温高停机延时
    LCD_GEC4XX_InitJ1939CAN();
 }
/* ******************************************************************** */
/*                         CALLOGIC_Init ()                             */
/* ******************************************************************** */
void CALLOGIC_Init (void)
{   
    TimerEnArr[TMR_MAINS_CHECK]=1;
    TimerEnArr[TMR_1000MS]=1;
    TimerEnArr[TMR_LCDDIS_LOGO]=1;
    TimerMode[TMR_1000MS]=1;
    TimerMode[TMR_GEN_ABNORMAL_DEL]=1;
    TimerSet[TMR_1000MS]=10;
    NowMode=DES_STARTINIT;
    TransValue();   
}

/* ******************************************************************** */
/*              CALLOGICSysPowerTooLowCheck ()                          */
/* ******************************************************************** */
static unsigned char cPowerDownSaveDataFlag=0;
void CALLOGICSysPowerTooLowCheck(void)   //系统电源过低检测
{
//  if((PowerVoltage>=48)&&(PowerVoltage<=65))
if((PowerVoltage>=140)&&(PowerVoltage<=150))
  { POWERLOSS=1;
    if(cPowerDownSaveDataFlag<2)
	  {
	    MSAVE_EPROMSTARTNUM=EPROM_STARTNUM; 	  //保存起动次数
      MSAVE_RUNNINGHOUR  =RUNNINGHOUR   ; 	  //保存运行累时
      MSAVE_RUNNINGMINUTE=RUNNINGMINUTE ; 	  //保存运行累分 
      MSAVE_RUNNINGSEC   =RUNNINGSEC    ; 	  //保存运行秒 
      MSAVE_KWHH         =KWHH          ; 	  //保存千瓦时高位
      MSAVE_KWHL         =KWHL          ;	  //保存千瓦时低位
	    //FLASH_SaveModifParm();
			FLASH_SaveOtherParm();
	    cPowerDownSaveDataFlag++;
	  }
  }
  else
  {	POWERLOSS=0;
    cPowerDownSaveDataFlag=0;
  }
}
/* ******************************************************************** */
/*                         CALLOGICRemoteCheck()                        */
/* ******************************************************************** */
void CALLOGICRemoteCheck(void)
{
    if(uFsCtl_CONTROL_CONFIRM==0xFFAA)
    {
        switch(uFsCtl_CONTROL_COMMAND)
        {
          case 0: F_ENTER_STOP_CAL=1;break;//停机
          case 1: F_ENTER_MANUAL=1;  break;//手动
          case 2: F_ENTER_AUTO=1;    break;//自动
          case 3:                    break;
          case 4: F_ENTER_START=1;   break;//复位                    
          case 5: RESETFLAG=1;       break;//起动  
          case 6: FLASH_SaveAllModifParm();       break;//数据保存 
          case 7: DBRestore_Factory_settings();   break;//恢复出厂设置 			
        }
        uFsCtl_CONTROL_CONFIRM=0;
        uFsCtl_CONTROL_COMMAND=0;
    }
}
/* ******************************************************************** */
/*                    CALLOGICLoopGensRuningSta()                       */
/* ******************************************************************** */
void CALLOGICLoopGensRuningSta(void)
{
  if(F_ENTER_STOP_CAL)
  {
		F_ENTER_STOP_CAL=0;
    if(NowMode==0)
    {//RESETFLAG=1;
    }
    STOPFLAG=1;
   }
   StatusCheck();
   ResetProcess();
   StartStopLogic();
   Protection();
   AmfLogic();
   CALLOGICSysPowerTooLowCheck();   //系统电源过低保存发动机运行参数检测
}
/* ******************************************************************** */
/*                         CALLOGIC_Loop ()                             */
/* ******************************************************************** */
void CALLOGIC_Loop (void)
{  
	if(HardTestModeEn)
	{
	 CALLOGICLoopGensRuningSta();
	 CALLOGICRemoteCheck();
	}
}



/* ******************************************************************** */
/*                               The END                                */
/* ******************************************************************** */

