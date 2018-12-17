#include "stm32f10x_conf.h"
#include "DB.h"
#include "ERR.h"
#include "J1939.h"
#include "CAN_PUBLIC.H"
#include "BOSCH_KHCB.h"
#include "ALL_Includes.h"
#include "delay.h"

INT16U usDBmErrCAN;
INT16U usDBmCanState;
INT16U usCANTimerBuf;
CAN_DATARXBUF CANRXBUF;
//CAN_MSG sFWCanIntrRxMsg;
DB_PAR_TCB aDBDisplay[DB_DISP_PAR_NUM];

/* ******************************************************************** */
/*                           CANGetStatus ()                            */
/* ******************************************************************** */
INT16U CANGetStatus (void)
{   return usCANStatus;
}
/* ******************************************************************** */
/*                           CANTimerInit ()                            */
/* ******************************************************************** */
void CANTimerInit (INT16U usTime)
{   usCANTimer = usTime;
}
/* ******************************************************************** */
/*                          CANClearStatus ()                           */
/* ******************************************************************** */
void CANClearStatus (INT16U usClear)
{   usCANStatus &= ~usClear;
}
/* ******************************************************************** */
/*                           CANSetStatus ()                            */
/* ******************************************************************** */
void CANSetStatus (INT16U usSet)
{   usCANStatus |= usSet;
}
/* ******************************************************************** */
/*                           CANCheckTime ()                            */
/* ******************************************************************** */
BOOL CANCheckTime (INT16U usOld, INT16U usNow, INT16U usPer)
{   INT16U usTemp;
    usTemp = usNow - usOld;
    if (usTemp >= usPer)
    {   return CAN_TRUE;
    }   else
    {   return CAN_FALSE;
    }
}
/* ******************************************************************** */
/*                        CANCheckRxAllTimeOut ()                       */
/* ******************************************************************** */
BOOL CANCheckRxAllTimeOut (void)
{   INT08U  i, ucFlag;
    CAN_PGN_TCB *pTcb;
    ucFlag = CAN_TRUE;
    for (i=0; i<CAN_RX_PGN_MAX; i++)
    {   pTcb = &sCANRxPgnTbl[i];
        if (pTcb->ucEnable == CAN_DISABLE)
        {   continue;
        }
        if (pTcb->ucState == CAN_NO_ERR)
        {   if (CANCheckTime(pTcb->usTime,usCANTimer,pTcb->usPeriod) != CAN_FALSE)
            {   pTcb->ucState = CAN_ERR_TIMEOUT;
            }   else
            {   ucFlag = CAN_FALSE;
            }
        }
    }
    return ucFlag;
}
/* ******************************************************************** */
/*                        CANBusTimeOutErrCheck ()                      */
/* ******************************************************************** */
void CANBusTimeOutErrCheck()
{
  /* ********************** CAN RX Message ********************** */
        if (CANCheckRxAllTimeOut() == CAN_FALSE)
        {   CANClearStatus (CAN_STS_RX_OK);
        }   else
        {   CANSetStatus (CAN_STS_RX_OK);
        }
        /* ********************** CAN TX Message ********************** */
      /*  if (CANProcessTxMsg(&sFWCanTaskTxMsg) == CAN_NO_ERR)
        {   CANClearStatus (CAN_STS_TX_OK);
        }   else
        {   CANSetStatus (CAN_STS_TX_OK);
        } */
        /* *********************** SET CAN Error ********************** */
        usDBmCanState = CANGetStatus();
       #if (FW_IGNORE_CAN_ERR_ON == 1)
        usDBmErrCAN = 0;
       #else
        if (usDBmCanState == CAN_STS_NORMAL)
        {   usDBmErrCAN = 0;
        }   else if ((usDBmCanState & CAN_STS_RX_OK) != 0)
        {   usDBmErrCAN = ERR_CODE_CAN_RX_TIMEOUT;
        }   else
        {   usDBmErrCAN = ERR_CODE_CAN_TX_TIMEOUT;
        }
       #endif
}
/* ******************************************************************** */
/*                           CANSystemInit ()                           */
/* ******************************************************************** */
void CANSystemInit()
{
    (void)CANTimerInit(0);
    (void)CANClearStatus(0xFFFF);
    //(void)CANRxPgnTblInit();
    //(void)CANTxPgnTblInit();
    CANSetStatus(CAN_STS_RX_OK | CAN_STS_TX_OK);
    usDBmErrCAN = ERR_CODE_CAN_RX_TIMEOUT;
    usDBmCanState = 0;
}
/* ******************************************************************** */
/*                            CANPUBInit ()                             */
/* ******************************************************************** */
void CANPUBInit(void)
{
    switch(GES_GENS_TYPE) 
    {
      case 0: break;                   //普通机组
      case 1: GeneralJ1939Init();break;//通用J1939机组        
      case 2: BOSCH_KHCBInit();  break;//BOSCH-KHCB
      case 3: break;
      case 4: break;
      default:break;
    }
}
/* ******************************************************************** */
/*                         CAN_J1939Public_Init ()                      */
/* ******************************************************************** */
void CAN_J1939Public_Init(void)
{
   CANSystemInit();
   CANPUBInit();
	 CANRXBUF.POINT=0;
   usCANTimer=0;
   usCANTimerBuf=0;
   usDBmErrCAN=0;
}
/* ******************************************************************** */
/*                         PublicChDecodeFault()                        */
/*  故障代码的转换                                                      */
/* ******************************************************************** */
INT16U PublicChDecodeFault(INT16U usCode)
{   INT16U usTemp = usCode;
    if (usTemp == ERR_CODE_CRANK_SENSOR1)
    {
    }
    else if (usTemp == ERR_CODE_CRANK_SENSOR2)
    {
    }
		else
    {
		}
    return usTemp;
}
/* ******************************************************************** */
/*                           CAN_PublicHookRx ()                        */
/* ******************************************************************** */
void CAN_PublicHookRx(CanRxMsg *pMsg)
{
	 CAN_MSG  *ptmp;
  if(CANRXBUF.POINT<CAN_RX_BUF_SIZE) 
  {
	 ptmp= &CANRXBUF.CAN_DATATBL[CANRXBUF.POINT];    
	 //ptmp->DAT32.uiID   = pMsg->StdId;
   //ptmp->DAT32.uiID   = pMsg->ExtId;				 //使用的扩展ID  
	 //ptmp->DAT32.uiID=CAN_CPU_TO_ID32(pMsg->ExtId);
	 ptmp->DAT32.uiID   = CAN_ID32_TO_CPU(pMsg->ExtId);
	 ptmp->DAT08.ucDat0 = pMsg->Data[0];
	 ptmp->DAT08.ucDat1 = pMsg->Data[1];
	 ptmp->DAT08.ucDat2 = pMsg->Data[2];
	 ptmp->DAT08.ucDat3 = pMsg->Data[3];
	 ptmp->DAT08.ucDat4 = pMsg->Data[4];
	 ptmp->DAT08.ucDat5 = pMsg->Data[5];
	 ptmp->DAT08.ucDat6 = pMsg->Data[6];
	 ptmp->DAT08.ucDat7 = pMsg->Data[7];
   CANRXBUF.POINT++; 
   //CANRXBUF.POINT=CAN_RX_BUF_SIZE-1;    
  }
}
/* ******************************************************************** */
/*                          CANProcessRxMsg ()                          */
/* ******************************************************************** */	
void CANProcessRxMsg(CAN_MSG *pMsg) 
{
    switch(GES_GENS_TYPE) 
    {
      case 0: break;                        //普通机组
      case 1: GeneralJ1939RxMsg(pMsg);break;//通用J1939机组     
      case 2: BOSCH_KHCBRxMsg(pMsg);  break;//BOSCH-KHCB科华船舶
      case 3: break;                        //DELPHI
      case 4: break;
      default:break;
    }
}

/* ******************************************************************** */
/*                       CANProcessPublicRxMsg ()                       */
/* ******************************************************************** */	
void CANProcessPublicRxMsg (void)
{   usCANTimer=usCANTimerBuf;
    while(CANRXBUF.POINT>0)
    {  
       CANProcessRxMsg(&CANRXBUF.CAN_DATATBL[CANRXBUF.POINT-1]);
       CANRXBUF.POINT--;
    }
    CANBusTimeOutErrCheck(); //检测超时
 }

/* ******************************************************************** */
/*                       PubCAN_DisTblRefresh ()                        */
/* ******************************************************************** */	
void PubCAN_DisTblRefresh(void)
{ CAN_PGN_TCB *pTcb;
  if( GES_GENS_TYPE != 0 )
  {
		//if(usDBmErrCAN == ERR_CODE_CAN_RX_TIMEOUT){DES_SPEED=0;DES_DISPSPEED=DES_SPEED;}//转速断线
		//else {   DES_SPEED=aDBDisplay[DB_NO_ENG_SPEED].ssValue;DES_DISPSPEED=DES_SPEED;}
		
	  //if(usDBmErrCAN == ERR_CODE_CAN_RX_TIMEOUT)OILPRESSURE=-32768; //油压断线
		//else     OILPRESSURE=aDBDisplay[DB_NO_OIL_PRES].ssValue;	
		
	  //if(usDBmErrCAN == ERR_CODE_CAN_RX_TIMEOUT)WATERTEMP=-32768;   //温度断线
		//else     WATERTEMP=aDBDisplay[DB_NO_COOL_TEMP].ssValue;
    
    /* ****************** 转速 *********************/
    pTcb = &sCANRxPgnTbl[DB_NO_ENG_SPEED];
    pTcb->usPeriod = 600;
    if(pTcb->ucState == CAN_ERR_TIMEOUT){DES_SPEED=0;DES_DISPSPEED=DES_SPEED;}//转速断线
    else {   DES_SPEED=aDBDisplay[DB_NO_ENG_SPEED].ssValue;DES_DISPSPEED=DES_SPEED;}
    
    /* ****************** 油压断线 *********************/
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_EFL];
    pTcb->usPeriod = 1200;
    if(pTcb->ucState == CAN_ERR_TIMEOUT)
    {TimerEnArr[TMR_CAN_CheckOilPreBrk_Del]=1; 
    }else
    {TimerEnArr[TMR_CAN_CheckOilPreBrk_Del]=0; 
     TimerTrig[TMR_CAN_CheckOilPreBrk_Del]=0; 
    }    
    if(TimerTrig[TMR_CAN_CheckOilPreBrk_Del])
    {OILPRESSURE=-32768; //油压断线
    }else   
    {  OILPRESSURE=aDBDisplay[DB_NO_OIL_PRES].ssValue;	
    }
    
    /* ****************** 温度断线 *********************/
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_ENGTEMP];
    pTcb->usPeriod = 2000;
    if(pTcb->ucState == CAN_ERR_TIMEOUT)
    {TimerEnArr[TMR_CAN_CheckTempBrk_Del]=1; 
    }else
    {TimerEnArr[TMR_CAN_CheckTempBrk_Del]=0; 
     TimerTrig[TMR_CAN_CheckTempBrk_Del]=0; 
    }    
    if(TimerTrig[TMR_CAN_CheckTempBrk_Del])
    {WATERTEMP=-32768;   //温度断线
    }else    
    { WATERTEMP=aDBDisplay[DB_NO_COOL_TEMP].ssValue;
    }  
  }
}

/* ******************************************************************** */
/*                           CANTxCtlMsg ()                             */
/* ******************************************************************** */
void CANTxCtlMsg(void) 
{
    switch(GES_GENS_TYPE) 
    {
      case 0://未使用
      break;
      case 1://J1939
      break;
      case 2://BOSCH
      break;
      case 3://DELPHI
      break;
      case 4://BOSCH-KHCB科华船舶
        //BOSCH_KHCBSendCtrMsg(); 
      break;
      default:break;
    }
}
/* ******************************************************************** */
/*                        CANProcessPublicTxMsg ()                      */
/* ******************************************************************** */
void CANProcessPublicTxMsg(void)
{
  
}


