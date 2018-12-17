/*--------------------------------------------------
      BOSCH-KHCB:科华船舶电喷
 ---------------------------------------------------*/
#include "stm32f10x_conf.h"
#include "DB.h"
#include "ERR.h"
#include "CAN_PUBLIC.H"
#include "J1939.H"
#include "BOSCH_KHCB.h"

/* ******************************************************************** 
                           BOSCH-KHCB科华船舶  
   初始化                                             
 ******************************************************************** */

void BOSCH_KHCBInit(void)//BOSCH-KHCB科华船舶
{
    INT08U i;
    CAN_PGN_TCB *pTcb;
    for (i=0; i<CAN_RX_PGN_MAX; i++)
    {   sCANRxPgnTbl[i].ucEnable = CAN_DISABLE;
        sCANRxPgnTbl[i].ucState  = CAN_ERR_TIMEOUT;
    }
    /* ********************** 1: CAN_RX_PGN_EEC1 ********************** */
   #ifdef CAN_RX_PGN_EEC1
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_EEC1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EEC1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
   
    /* ******************** 8: CAN_RX_PGN_ENGTEMP ********************* */
   #ifdef CAN_RX_PGN_ENGTEMP
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_ENGTEMP];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_ENGTEMP);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    
    /* ********************** 10: CAN_RX_PGN_EFL ********************** */
   #ifdef CAN_RX_PGN_EFL
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_EFL];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EFL);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
 }


/* ******************************************************************** 
                           BOSCH-KHCB科华船舶  
   接受数据处理                                        
 ******************************************************************** */
/* ****************************** RX_ENSPEED ************************** */ 
#ifdef CAN_RX_PGN_EEC1
void BOSCHKHCB_CANUpdateRxEEC1 (CAN_MSG *pMsg)
{
   #ifdef DB_NO_ENG_SPEED
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat4);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_ENG_SPEED].ssValue = usTemp / 8;
        aDBDisplay[DB_NO_ENG_SPEED].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_ENG_SPEED].ssValue = 0;
        aDBDisplay[DB_NO_ENG_SPEED].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #ifdef DB_NO_ENG_LOAD
    usTemp = pMsg->DAT08.ucDat2;
    if (usTemp <= 125)
    {   aDBDisplay[DB_NO_ENG_LOAD].ssValue  = usTemp;
        aDBDisplay[DB_NO_ENG_LOAD].ucErr    = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_ENG_LOAD].ssValue  = 0;
        aDBDisplay[DB_NO_ENG_LOAD].ucErr    = CAN_ERR_INVALID;
    }
   #endif

}
#endif 

/* ****************************** RX_ENGTEMP ************************** */
#ifdef CAN_RX_PGN_ENGTEMP
void BOSCHKHCB_CANUpdateRxENGTEMP (CAN_MSG *pMsg)
{
   #ifdef DB_NO_COOL_TEMP
    INT16U usTemp;
    usTemp = pMsg->DAT08.ucDat0;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_COOL_TEMP].ssValue = usTemp - 40;
        aDBDisplay[DB_NO_COOL_TEMP].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_COOL_TEMP].ssValue = 0;
        aDBDisplay[DB_NO_COOL_TEMP].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #ifdef DB_NO_FUEL_TEMP
   #if (CAN_1000_TWO_FUEL_ON == 0)
    usTemp = pMsg->DAT08.ucDat1;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_FUEL_TEMP].ssValue = usTemp - 40;
        aDBDisplay[DB_NO_FUEL_TEMP].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_FUEL_TEMP].ssValue = 0;
        aDBDisplay[DB_NO_FUEL_TEMP].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #endif
   #ifdef DB_NO_OIL_TEMP
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_OIL_TEMP].ssValue  = usTemp / 32 - 273;
        aDBDisplay[DB_NO_OIL_TEMP].ucErr    = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_OIL_TEMP].ssValue  = 0;
        aDBDisplay[DB_NO_OIL_TEMP].ucErr    = CAN_ERR_INVALID;
    }
   #endif
  
}
#endif

/* ****************************** RX_EFL ****************************** */
#ifdef CAN_RX_PGN_EFL
void BOSCHKHCB_CANUpdateRxEFL (CAN_MSG *pMsg)
{
   #ifdef DB_NO_OIL_PRES
    INT16U usTemp;
    usTemp = pMsg->DAT08.ucDat3;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_OIL_PRES].ssValue = usTemp * 4;
        aDBDisplay[DB_NO_OIL_PRES].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_OIL_PRES].ssValue = 0;
        aDBDisplay[DB_NO_OIL_PRES].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #ifdef DB_NO_FUEL_PRES
   #if (CAN_1000_TWO_FUEL_ON == 0)
    usTemp = pMsg->DAT08.ucDat0;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_FUEL_PRES].ssValue = usTemp * 4;
        aDBDisplay[DB_NO_FUEL_PRES].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_FUEL_PRES].ssValue = 0;
        aDBDisplay[DB_NO_FUEL_PRES].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #endif
   #if (CAN_4000_COMMON_ON == 1)
   #if (CAN_PRESS_RELATIVE_ON == 1)
    usDBmFuelPressure = (INT16U)(pMsg->DAT08.ucDat0) * 40 + 1000;
    usDBmOilPressure  = (INT16U)(pMsg->DAT08.ucDat3) * 40 + 1000;
   #else
    usDBmFuelPressure = (INT16U)(pMsg->DAT08.ucDat0) * 40;
    usDBmOilPressure  = (INT16U)(pMsg->DAT08.ucDat3) * 40;
   #endif
   #endif
}
#endif

/* ******************************************************************** 
                           BOSCH-KHCB科华船舶  
   接受到CAN数据处理 写入相应的显示缓存区                                               
 ******************************************************************** */

INT8U BOSCH_KHCBRxMsg(CAN_MSG *pMsg) //BOSCH-KHCB科华船舶
{
    INT08U  i;
    INT32U  uiTemp;
    CAN_PGN_TCB *pTcb;
    uiTemp = pMsg->DAT32.uiID;

    for (i=0; i<CAN_RX_PGN_MAX; i++)
    {   pTcb = &sCANRxPgnTbl[i];
        if (pTcb->ucEnable == CAN_DISABLE)
        {   continue;
        }
        if (pTcb->uiID != uiTemp)
        {   continue;
        }
        
        if (CANCheckTime(pTcb->usTime,usCANTimer,pTcb->usPeriod) != CAN_FALSE)
        {   pTcb->ucState = CAN_ERR_TIMEOUT;
            pTcb->usTime  = usCANTimer;
        }   else
        {   pTcb->ucState = CAN_NO_ERR;
            pTcb->usTime  = usCANTimer;
        }
       
       #ifdef CAN_RX_PGN_EEC1
        if (i == CAN_RX_PGN_EEC1)
        {   BOSCHKHCB_CANUpdateRxEEC1 (pMsg);
        }
       #endif

       #ifdef CAN_RX_PGN_ENGTEMP
        else if (i == CAN_RX_PGN_ENGTEMP)
        {   BOSCHKHCB_CANUpdateRxENGTEMP (pMsg);
        }
       #endif
       
       #ifdef CAN_RX_PGN_EFL
        else if (i == CAN_RX_PGN_EFL)
        {   BOSCHKHCB_CANUpdateRxEFL (pMsg);
        }
       #endif
       
       return CAN_TRUE; 
    }
   return CAN_FALSE;
}


/* ******************************************************************** 
                           BOSCH-KHCB科华船舶  
   接受到CAN数据处理 写入相应的显示缓存区                                               
 ******************************************************************** */
#define KHCB_CAN_CtrID_TSC1TE  (INT32U)0x18000017//(INT32U)0x0c000003 
#define KHCB_CAN_CtrID_CCVSV  (INT32U)0x18fef117

void  BOSCH_KHCBSendCtrMsg(void) //BOSCH-KHCB科华船舶
{
}




