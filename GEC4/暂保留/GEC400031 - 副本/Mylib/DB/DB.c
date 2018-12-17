#include "TYPCortex.h"

volatile STRFLG16 TimeStamp;
M_INT8U POWERLOSS;
STRFLG16 RAMDATABASE[FLASH_RAM_ArrayCon];
STRFLG16 FLASHDATABASE[FLASH_FLASH_ArrayCon];
STRFLG16 AlarmMaping[ALARMINGCON];
STRFLG16 AdjDataMapBuf[AdjDataMapCon];  //实时显示修改参数校验数据映射数组
unsigned long LCD9341Delay;

///*-----------------------------------------------------------------------
//函数名称： INT08U DB_JudgeInitMemeryYN(INT16U JudgeSpData,INT08U ID) 
//功能描述： 判断上电初始化后从非易失存储器中读出的数据是否在范围内
//输入参数：JudgeSpData:预判断数据  ID:循环个数
//输出参数：0 不在范围  1 在范围
//----------------------------------------------------------------------- */
//  
//M_INT08U DB_JudgeInitMemeryYN(M_INT16U JudgeSpData,M_INT08U ID) 
//{
//  M_INT16U JudgeData1=0,JudgeData2=0;
//  JudgeData1=MAINMENU.SubPtr[0]->SubItems[ID]->MinValue;  //范围 最小值 
//  JudgeData2=MAINMENU.SubPtr[0]->SubItems[ID]->MaxValue;  //范围 最大值 
//  if((JudgeSpData>=JudgeData1)&&(JudgeSpData<=JudgeData2)) return 1;
//  else                                                     return 0;
//}
///*-----------------------------------------------------------------------
//函数名称： INT08U DB_JudgeAdjInitDRN(INT16U JudgeAdjData,INT08U AdjID) 
//功能描述： 判断上电初始化后从非易失存储器中读出的数据是否在范围内
//输入参数：JudgeAdjData:预判断数据  AdjID:循环个数
//输出参数：0 不在范围  1 在范围
//----------------------------------------------------------------------- */
//M_INT08U DB_JudgeAdjInitDRN(M_INT16U JudgeAdjData,M_INT08U AdjID)
//{
//  M_INT16U JudgeData1=0,JudgeData2=0; 
//  JudgeData1=SUBMENU_AdjustPARM.SubItems[AdjID]->MinValue;  //范围 最小值 
//  JudgeData2=SUBMENU_AdjustPARM.SubItems[AdjID]->MaxValue;  //范围 最大值 
//  if((JudgeAdjData>=JudgeData1)&&(JudgeAdjData<=JudgeData2))return 1;
//  else                                                      return 0;
//} 

///*-----------------------------------------------------------------------
//函数名称： DB_JudgeCurveInitDRN(M_INT16U JudgeCurveData,M_INT08U CurveID)
//功能描述： 判断上电初始化后从非易失存储器中读出的数据是否在范围内
//输入参数：JudgeAdjData:预判断数据  AdjID:循环个数
//输出参数：0 不在范围  1 在范围
//----------------------------------------------------------------------- */
//M_INT08U DB_JudgeCurveInitDRN(M_INT16U JudgeCurveData,M_INT08U CurvePgID,M_INT08U CurveID)
//{ 
//  M_INT16U JudgeData1=0,JudgeData2=0; 
//  JudgeData1=MainCurvePage->cpCurveMainPg[CurvePgID]->CurvePages[CurveID]->CurveMin;  //范围 最小值 
//  JudgeData2=MainCurvePage->cpCurveMainPg[CurvePgID]->CurvePages[CurveID]->CurveMax;  //范围 最大值 
//  if((JudgeCurveData>=JudgeData1)&&(JudgeCurveData<=JudgeData2))return 1;
//  else                                                          return 0;
//}

///* ******************************************************************** */
///*             void DBRestoreFactorypParm()                        */
////                                  
///* ******************************************************************** */
//void DBRestoreFactorypParm(void)
//{
//  M_INT08U i,ConBuf;
//  Language_select=0;			       
//  for(i=0;i<sParmSetnum_ForMainPage;i++)
//  { 
//   ConBuf=MAINMENU.SubPtr[0]->SubItems[i]->ParmSetHeadnum; 
//   FLASHDATABASE[ConBuf].Sbyte=MAINMENU.SubPtr[0]->SubItems[i]->DefaultValue; 
//  }
//	FLASH_SavepParm();
//}
///* ******************************************************************** */
///*             void DBRestoreFactorysAdjParm()                        */
////                                  
///* ******************************************************************** */
//void DBRestoreFactorysAdjParm(void)
//{
//	M_INT08U i,ConBuf;
//  for(i=0;i<sAdjParmPageCon;i++)      
//  {
//	 ConBuf=SUBMENU_AdjustPARM.SubItems[i]->ParmSetHeadnum; 
//   FLASHDATABASE[ConBuf].Sbyte=SUBMENU_AdjustPARM.SubItems[i]->DefaultValue; 
//  }
//	FLASH_SavesAdjParm();	
//}
///* ******************************************************************** */
///*             void DBRestoreFactorycCurveParm()                        */
////                                  
///* ******************************************************************** */
//void DBRestoreFactorycCurveParm(void)
//{
//	M_INT08U i,ConBuf;
//  M_INT08U k; 
//  for(i=0;i<CurveMainPgCtr;i++)       
//  {
//	 for(k=0;k<CurveDotCtr*2;k++)
//   {
//		ConBuf=MainCurvePage->cpCurveMainPg[i]->CurvePages[k]->ParmSetHeadnum;
//	  FLASHDATABASE[ConBuf].Sbyte=MainCurvePage->cpCurveMainPg[i]->CurvePages[k]->CurveDefault;
//   }
//  }
//	FLASH_SavecCurveParm();
//}
///* ******************************************************************** */
///*             void DBRestoreFactoryOtherParm()                        */
////                                  
///* ******************************************************************** */
//void DBRestoreFactoryOtherParm(void)
//{
// //FLASH_SaveOtherParm();
//}
///* ******************************************************************** */
///*             void DBRestore_Factory_settings()                        */
////                                  
///* ******************************************************************** */
////INT08U  Restore_Factoryftest=0;
//void DBRestore_Factory_settings(void) 
//{
//  DBRestoreFactorypParm();
//  DBRestoreFactorysAdjParm();
//  DBRestoreFactorycCurveParm();
//  DBRestoreFactoryOtherParm();
//}

///* ******************************************************************** */
///*                void DBJudgeReadOutpParm()                            */
////                                  
///* ******************************************************************** */
//void DBJudgeReadOutpParm(void)
//{
// M_INT08U i,buf=0;
// M_INT16U ErrCon=0;
// for(i=0;i<sParmSetnum_ForMainPage;i++)
// {
//	 buf=DB_JudgeInitMemeryYN(FLASHDATABASE[MAINMENU.SubPtr[0]->SubItems[i]->ParmSetHeadnum].Sbyte,i);
//   if(buf!=1) 
//   {
//	   ErrCon++;
//		 sReadParameterErr=i;
//		 break;
//	 } 
// }
// if(Language_select>1)
// { 
//	 Language_select=0;			  
//   sReadLanguageErr=233;
//	 ErrCon++;
// }
// if(ErrCon!=0) DBRestoreFactorypParm();
//}
///* ******************************************************************** */
///*                void DBJudgeReadOutsAdjParm()                         */
////                                  
///* ******************************************************************** */
//void DBJudgeReadOutsAdjParm(void)
//{
// M_INT08U i,buf=0;
// M_INT16U ErrCon=0;
// for(i=0;i<sAdjParmPageCon;i++)
// {
//	buf=DB_JudgeAdjInitDRN(FLASHDATABASE[SUBMENU_AdjustPARM.SubItems[i]->ParmSetHeadnum].Sbyte,i); 
//  if(buf!=1) 
//  { 
//	 ErrCon++;
//	 sReadAdjParmErr=i;
//	 break;
//  } 
// }
// if(ErrCon!=0)DBRestoreFactorysAdjParm();
//}
///* ******************************************************************** */
///*               void DBJudgeReadOutcCurveParm()                        */
////                                  
///* ******************************************************************** */
//void DBJudgeReadOutcCurveParm(void)
//{
// M_INT08U i,buf=0;
// M_INT08U k=0;
// M_INT16U ErrCon=0;
// for(i=0;i<CurveMainPgCtr;i++)
// {
//	 for(k=0;k<CurveDotCtr*2;k++)
//   {
//    buf=DB_JudgeCurveInitDRN(FLASHDATABASE[MainCurvePage->cpCurveMainPg[i]->CurvePages[k]->ParmSetHeadnum].Sbyte,i,k);
//    if(buf!=1) 
//     {
//			 ErrCon++;
//			 sReadCurveParmErr=i;
//			 break;
//		 } 
//   }
// }
// if(ErrCon!=0)DBRestoreFactorycCurveParm();
//}
///* ******************************************************************** */
///*                void DBJudgeReadOutOtherParm()                        */
////                                  
///* ******************************************************************** */
//void DBJudgeReadOutOtherParm(void)
//{
//	M_INT16U ErrCon=0;
//  if(ErrCon!=0) DBRestoreFactoryOtherParm();
//}
///* ******************************************************************** */
///*                     void DB_JudgeParm()                              */
///*          判断所有参数是否为有效数据                                  */
///* ******************************************************************** */

//void DB_JudgeParm(void)
//{
// DBJudgeReadOutpParm();
// DBJudgeReadOutsAdjParm();	
// DBJudgeReadOutcCurveParm();
// DBJudgeReadOutOtherParm();
//}


/****************The End ****************/
