#include "TYPCortex.h"

volatile STRFLG16 TimeStamp;
M_INT8U POWERLOSS;
STRFLG16 RAMDATABASE[FLASH_RAM_ArrayCon];
STRFLG16 FLASHDATABASE[FLASH_FLASH_ArrayCon];
STRFLG16 AlarmMaping[ALARMINGCON];
STRFLG16 AdjDataMapBuf[AdjDataMapCon];  //实时显示修改参数校验数据映射数组
unsigned long LCD9341Delay;
//@@@
/* ****************** Part 12: Maps (380 - 559) *********************** */

INT16U aDBParam[DB_PARAM_SIZE];
INT16U aDBMeasu[DB_MEASU_SIZE];

void DBInit (void) 
{
    (void)DBResetParam();
}

/* ******************************************************************** */
/*                            DBResetParam()                            */
/* ******************************************************************** */
void DBResetParam (void)
{   usDBpGensCtRatio           = 1;
    usDBpAmpMainVoltA          = 1024;
    usDBpAmpMainVoltB          = 1024;
    usDBpAmpMainVoltC          = 1024;
    usDBpAmpMainVoltAB         = 1024;
    usDBpAmpMainVoltBC         = 1024;
    usDBpAmpMainVoltCA         = 1024;
    usDBpAmpGensVoltA          = 2248;//1024;
    usDBpAmpGensVoltB          = 2248;//1024;
    usDBpAmpGensVoltC          = 2248;//1024;
    usDBpAmpGensVoltAB         = 2248;//1024;
    usDBpAmpGensVoltBC         = 2248;//1024;
    usDBpAmpGensVoltCA         = 2248;//1024;
    usDBpAmpGensCurrA          = 3350;//1024;
    usDBpAmpGensCurrB          = 3350;//1024;
    usDBpAmpGensCurrC          = 3350;//1024;
    usDBpAdcChFilter0          = 16;
    usDBpAdcChFilter1          = 16;
    usDBpAdcChFilter2          = 16;
    usDBpAdcChFilter3          = 16;
    usDBpAdcChFilter4          = 16;
    usDBpAdcChFilter5          = 16;
    usDBpAdcChFilter6          = 16;
    usDBpAdcChFilter7          = 16;
    usDBpAdcChFilter8          = 16;
    usDBpAdcChRef0             = 2047;
    usDBpAdcChRef1             = 2047;
    usDBpAdcChRef2             = 2047;
    usDBpAdcChRef3             = 2047;
    usDBpAdcChRef4             = 2047;
    usDBpAdcChRef5             = 2047;
    usDBpAdcChRef6             = 2047;
    usDBpAdcChRef7             = 2047;
    usDBpAdcChRef8             = 2047;
    usDBpAdcChRef9             = 2047;
    usDBpAdcChRef10            = 2047;
    usDBpAdcChRef11            = 2047;
    usDBpAdcChRef12            = 2047;
    usDBpAdcChRef13            = 2047;
    usDBpAdcChRef14            = 2047;
    usDBpAdcChRef15            = 2047;
    usDBpAdcRefAutoOrFixed     = 1;
    
    usDBpVoltDifferMax         = 100;
    usDBpFreqDifferMax         = 100;
    usDBpPhaseDifferMax        = 100;
    usDBpGovTuneGain           = 0;
    usDBpGovTuneStability      = 0;
    usDBpGovTuneDerivative     = 0;
    ssDBpGovTuneCtrlInit       = 0;
    usDBpAvrTuneGain           = 0;
    usDBpAvrTuneStability      = 0;
    usDBpAvrTuneDerivative     = 0;
    ssDBpAvrTuneCtrlInit       = 0;
    
    usDBpTeethCrank1           = 115; //100
    usDBpTeethCrank2           = 115; //100
    usDBpSpeedFilter1          = 100;
    usDBpSpeedFilter2          = 100;
    usDBpStartSpeed1           = 40;
    usDBpStartSpeed2           = 400;
    usDBpSpeedIdle             = 600;
    usDBpSpeedIdleMin          = 550;
    usDBpSpeedIdleMax          = 650;
    usDBpSpeedRated            = 1500;
    usDBpSpeedRatedMin         = 1450;
    usDBpSpeedOverToWarn       = 1650;
    usDBpSpeedOverToStop       = 1700;
    usDBpSpeedOverStopDly      = 10;
    usDBpDroop                 = 0;
    usDBpDroopRefLow           = 100;
    usDBpDroopRefHigh          = 1000;
    usDBpDroopSpeedRef         = 1500;
    usDBpSpeedRampUp           = 100;
    usDBpSpeedRampDown         = 100;
    usDBpSpeedRampUp2          = 100;
    usDBpSpeedRampDown2        = 100;
    usDBpSpeedSwitchToRamp2    = 1000;
    usDBpSpeedRampDigitPot     = 100;
    
    usDBpStoppedToStartingDly  = 100;
    usDBpIdlingToRampUpDly     = 100;
    usDBpRatedToSynchringDly   = 100;
    usDBpWorkingToSwitchOffDly = 100;
    usDBpRatedToRampDowmDly    = 100;
    usDBpIdlingToStoppingDly   = 100;
    usDBpMainBreakerOnDly      = 100;
    usDBpGensBreakerOnDly      = 100;
    usDBpRampUpTimeMax         = 100;
    usDBpRampDownTimeMax       = 100;
    usDBpSynchronTimeMax       = 100;
    usDBpAirHeatTempCold       = 100;
    usDBpAirHeatTempWarm       = 100;
    usDBpAirHeatTimeAtCold     = 100;
    usDBpAirHeatTimeAtWarm     = 100;
    usDBpOilPumpOnTimeMax      = 100;
    usDBpOilPressMinAtStart    = 100;
    usDBpFanRefAssign          = 100;
    usDBpFanActiveTemp         = 100;
    usDBpFanActiveDly          = 100;
    usDBpStarterOnDly          = 100;
    usDBpStarterOffDly         = 100;
    usDBpStartFailMax          = 3;
    usDBpOperationMode         = 0;
    usDBpStatisticsTime        = 3000;
    
    usDBpModBusBaudrate        = 9600;
    usDBpModBusMyAddress       = 1;
    usDBpCan1Baudrate          = 250;
    usDBpCan1MyAddress         = 1;
    usDBpCan2Baudrate          = 250;
    usDBpCan2MyAddress         = 1;
    usDBpCan3Baudrate          = 250;
    usDBpCan3MyAddress         = 1;
    
    usDBpCoolantTempToWarn     = 0;
    usDBpCoolantTempToStop     = 0;
    usDBpCoolantTempStopDly    = 0;
    usDBpBoostTempToWarn       = 0;
    usDBpBoostTempToStop       = 0;
    usDBpBoostTempStopDly      = 0;
    usDBpOilTempToWarn         = 0;
    usDBpOilTempToStop         = 0;
    usDBpOilTempStopDly        = 0;
    usDBpInternTempToWarn      = 0;
    
    usDBpOilPressStartDly      = 0;
    usDBpOilPressWarnDly       = 0;
    usDBpOilPressStopDly       = 0;
    usDBpFuelLevelToWarn       = 0;
    usDBpFuelLevelWarnDly      = 0;
    usDBpFuelLevelToStop       = 0;
    usDBpFuelLevelStopDly      = 0;
    usDBpCoolantLevelToWarn    = 0;
    usDBpCoolantLevelWarnDly   = 0;
    usDBpCoolantLevelToStop    = 0;
    usDBpCoolantLevelStopDly   = 0;
    usDBpSupplyVoltWarnLow     = 0;
    usDBpSupplyVoltWarnHigh    = 0;
    usDBpSupplyVoltWarnDly     = 0;
    usDBpChargerVoltWarnLow    = 0;
    usDBpChargerVoltWarnHigh   = 0;
    usDBpChargerVoltWarnDly    = 0;
    usDBpChargerCurrToWarn     = 0;
    usDBpChargerCurrWarnDly    = 0;
    usDBpRackPositionToWarn    = 0;
    usDBpRackPositionWarnDly   = 0;
    usDBpAirFilterWarnDly      = 0;
    usDBpMainLnVoltErrLow      = 0;
    usDBpMainLnVoltErrHigh     = 0;
    usDBpMainLlVoltErrLow      = 0;
    usDBpMainLlVoltErrHigh     = 0;
    usDBpMainPhaseErrLow       = 0;
    usDBpMainPhaseErrHigh      = 0;
    usDBpMainFreqErrLow        = 0;
    usDBpMainFreqErrHigh       = 0;
    usDBpMainVoltErrorDly      = 0;
    usDBpMainVoltNormalDly     = 0;
    usDBpGensLnVoltErrLow      = 0;
    usDBpGensLnVoltErrHigh     = 0;
    usDBpGensLlVoltErrLow      = 0;
    usDBpGensLlVoltErrHigh     = 0;
    usDBpGensPhaseErrLow       = 0;
    usDBpGensPhaseErrHigh      = 0;
    usDBpGensFreqErrLow        = 0;
    usDBpGensFreqErrHigh       = 0;
    usDBpGensVoltErrorDly      = 0;
    usDBpGensVoltNormalDly     = 0;
    usDBpGensCurrErrHigh       = 0;
    usDBpGensCurrGdErrHigh    = 0;
    usDBpGensCurrErrorDly      = 0;
    usDBpGensCurrNormalDly     = 0;
    usDBpActPowerErrHigh       = 0;
    usDBpReactPowerErrHigh     = 0;
    usDBpAppPowerErrHigh       = 0;
    usDBpPowerFactorErrHigh    = 0;
    usDBpPowerFactorErrLow     = 0;
    usDBpGensPowerErrorDly     = 0;
    usDBpGensPowerNormalDly    = 0;
		
    /*Sensor Assignment*/     //传感器类型选择
    usDBpAssignOilTemp         = 65535;
    usDBpAssignFuelTemp        = 65535;
    usDBpAssignBoostTemp       = 65535;
    usDBpAssignCoolantTemp     = 9;  //水温在传感器数组中的位置
    usDBpAssignExhaustTemp     = 65535;
    usDBpAssignOilPress        = 10;     //油压在传感器数组中的位置
    usDBpAssignFuelPress       = 65535;
    usDBpAssignBoostPress      = 65535;
		usDBpAssignFuelLevel       = 12;     //液位在传感器数组中的位置
    
    /*Sensor Calibration*/   //传感器AD值限制范围 0Ω - 41   10000Ω - 3974    断线 - 4092
    usDBpOilPressErrLow = 10;
    usDBpOilPressErrHigh = 4000;	
    usDBpCoolantTempErrLow = 10;
    usDBpCoolantTempErrHigh = 4000;
    usDBpFuelLevelErrLow = 10;
    usDBpFuelLevelErrHigh = 4000;
    
}

//@@@
/*-----------------------------------------------------------------------
函数名称： INT08U DB_JudgeInitMemeryYN(INT16U JudgeSpData,INT08U ID) 
功能描述： 判断上电初始化后从非易失存储器中读出的数据是否在范围内
输入参数：JudgeSpData:预判断数据  ID:循环个数
输出参数：0 不在范围  1 在范围
----------------------------------------------------------------------- */
  
M_INT08U DB_JudgeInitMemeryYN(M_INT16U JudgeSpData,M_INT08U ID) 
{
  M_INT16U JudgeData1=0,JudgeData2=0;
  JudgeData1=MAINMENU.SubPtr[0]->SubItems[ID]->MinValue;  //范围 最小值 
  JudgeData2=MAINMENU.SubPtr[0]->SubItems[ID]->MaxValue;  //范围 最大值 
  if((JudgeSpData>=JudgeData1)&&(JudgeSpData<=JudgeData2)) return 1;
  else                                                     return 0;
}
/*-----------------------------------------------------------------------
函数名称： INT08U DB_JudgeAdjInitDRN(INT16U JudgeAdjData,INT08U AdjID) 
功能描述： 判断上电初始化后从非易失存储器中读出的数据是否在范围内
输入参数：JudgeAdjData:预判断数据  AdjID:循环个数
输出参数：0 不在范围  1 在范围
----------------------------------------------------------------------- */
M_INT08U DB_JudgeAdjInitDRN(M_INT16U JudgeAdjData,M_INT08U AdjID)
{
  M_INT16U JudgeData1=0,JudgeData2=0; 
  JudgeData1=SUBMENU_AdjustPARM.SubItems[AdjID]->MinValue;  //范围 最小值 
  JudgeData2=SUBMENU_AdjustPARM.SubItems[AdjID]->MaxValue;  //范围 最大值 
  if((JudgeAdjData>=JudgeData1)&&(JudgeAdjData<=JudgeData2))return 1;
  else                                                      return 0;
} 

/*-----------------------------------------------------------------------
函数名称： DB_JudgeCurveInitDRN(M_INT16U JudgeCurveData,M_INT08U CurveID)
功能描述： 判断上电初始化后从非易失存储器中读出的数据是否在范围内
输入参数：JudgeAdjData:预判断数据  AdjID:循环个数
输出参数：0 不在范围  1 在范围
----------------------------------------------------------------------- */
M_INT08U DB_JudgeCurveInitDRN(M_INT16U JudgeCurveData,M_INT08U CurvePgID,M_INT08U CurveID)
{ 
  M_INT16U JudgeData1=0,JudgeData2=0; 
  JudgeData1=MainCurvePage->cpCurveMainPg[CurvePgID]->CurvePages[CurveID]->CurveMin;  //范围 最小值 
  JudgeData2=MainCurvePage->cpCurveMainPg[CurvePgID]->CurvePages[CurveID]->CurveMax;  //范围 最大值 
  if((JudgeCurveData>=JudgeData1)&&(JudgeCurveData<=JudgeData2))return 1;
  else                                                          return 0;
}

/* ******************************************************************** */
/*             void DBRestoreFactorypParm()                        */
//                                  
/* ******************************************************************** */
void DBRestoreFactorypParm(void)
{
  M_INT08U i,ConBuf;
  Language_select=0;			       
  for(i=0;i<sParmSetnum_ForMainPage;i++)
  { 
   ConBuf=MAINMENU.SubPtr[0]->SubItems[i]->ParmSetHeadnum; 
   FLASHDATABASE[ConBuf].Sbyte=MAINMENU.SubPtr[0]->SubItems[i]->DefaultValue; 
  }
	FLASH_SavepParm();
}
/* ******************************************************************** */
/*             void DBRestoreFactorysAdjParm()                        */
//                                  
/* ******************************************************************** */
void DBRestoreFactorysAdjParm(void)
{
	M_INT08U i,ConBuf;
  for(i=0;i<sAdjParmPageCon;i++)      
  {
	 ConBuf=SUBMENU_AdjustPARM.SubItems[i]->ParmSetHeadnum; 
   FLASHDATABASE[ConBuf].Sbyte=SUBMENU_AdjustPARM.SubItems[i]->DefaultValue; 
  }
	FLASH_SavesAdjParm();	
}
/* ******************************************************************** */
/*             void DBRestoreFactorycCurveParm()                        */
//                                  
/* ******************************************************************** */
void DBRestoreFactorycCurveParm(void)
{
	M_INT08U i,ConBuf;
  M_INT08U k; 
  for(i=0;i<CurveMainPgCtr;i++)       
  {
	 for(k=0;k<CurveDotCtr*2;k++)
   {
		ConBuf=MainCurvePage->cpCurveMainPg[i]->CurvePages[k]->ParmSetHeadnum;
	  FLASHDATABASE[ConBuf].Sbyte=MainCurvePage->cpCurveMainPg[i]->CurvePages[k]->CurveDefault;
   }
  }
	FLASH_SavecCurveParm();
}
/* ******************************************************************** */
/*             void DBRestoreFactoryOtherParm()                        */
//                                  
/* ******************************************************************** */
void DBRestoreFactoryOtherParm(void)
{
 //FLASH_SaveOtherParm();
}
/* ******************************************************************** */
/*             void DBRestore_Factory_settings()                        */
                                  
/* ******************************************************************** */
INT08U  Restore_Factoryftest=0;
void DBRestore_Factory_settings(void) 
{
  DBRestoreFactorypParm();
  DBRestoreFactorysAdjParm();
  DBRestoreFactorycCurveParm();
  DBRestoreFactoryOtherParm();
}

/* ******************************************************************** */
/*                void DBJudgeReadOutpParm()                            */
//                                  
/* ******************************************************************** */
void DBJudgeReadOutpParm(void)
{
 M_INT08U i,buf=0;
 M_INT16U ErrCon=0;
 for(i=0;i<sParmSetnum_ForMainPage;i++)
 {
	 buf=DB_JudgeInitMemeryYN(FLASHDATABASE[MAINMENU.SubPtr[0]->SubItems[i]->ParmSetHeadnum].Sbyte,i);
   if(buf!=1) 
   {
	   ErrCon++;
		 sReadParameterErr=i;
		 break;
	 } 
 }
 if(Language_select>1)
 { 
	 Language_select=0;			  
   sReadLanguageErr=233;
	 ErrCon++;
 }
 if(ErrCon!=0) DBRestoreFactorypParm();
}
/* ******************************************************************** */
/*                void DBJudgeReadOutsAdjParm()                         */
//                                  
/* ******************************************************************** */
void DBJudgeReadOutsAdjParm(void)
{
 M_INT08U i,buf=0;
 M_INT16U ErrCon=0;
 for(i=0;i<sAdjParmPageCon;i++)
 {
	buf=DB_JudgeAdjInitDRN(FLASHDATABASE[SUBMENU_AdjustPARM.SubItems[i]->ParmSetHeadnum].Sbyte,i); 
  if(buf!=1) 
  { 
	 ErrCon++;
	 sReadAdjParmErr=i;
	 break;
  } 
 }
 if(ErrCon!=0)DBRestoreFactorysAdjParm();
}
/* ******************************************************************** */
/*               void DBJudgeReadOutcCurveParm()                        */
//                                  
/* ******************************************************************** */
void DBJudgeReadOutcCurveParm(void)
{
 M_INT08U i,buf=0;
 M_INT08U k=0;
 M_INT16U ErrCon=0;
 for(i=0;i<CurveMainPgCtr;i++)
 {
	 for(k=0;k<CurveDotCtr*2;k++)
   {
    buf=DB_JudgeCurveInitDRN(FLASHDATABASE[MainCurvePage->cpCurveMainPg[i]->CurvePages[k]->ParmSetHeadnum].Sbyte,i,k);
    if(buf!=1) 
     {
			 ErrCon++;
			 sReadCurveParmErr=i;
			 break;
		 } 
   }
 }
 if(ErrCon!=0)DBRestoreFactorycCurveParm();
}
/* ******************************************************************** */
/*                void DBJudgeReadOutOtherParm()                        */
//                                  
/* ******************************************************************** */
void DBJudgeReadOutOtherParm(void)
{
	M_INT16U ErrCon=0;
  if(ErrCon!=0) DBRestoreFactoryOtherParm();
}
/* ******************************************************************** */
/*                     void DB_JudgeParm()                              */
/*          判断所有参数是否为有效数据                                  */
/* ******************************************************************** */

void DB_JudgeParm(void)
{
 DBJudgeReadOutpParm();
 DBJudgeReadOutsAdjParm();	
 DBJudgeReadOutcCurveParm();
 DBJudgeReadOutOtherParm();
}


/****************The End ****************/
