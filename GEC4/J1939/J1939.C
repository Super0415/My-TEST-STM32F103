#include "stm32f10x_conf.h"
#include "DB.h"
#include "ERR.h"
#include "CAN_PUBLIC.H"
#include "J1939.H"


INT16U usCANTimer;
INT16U usCANStatus;
CAN_PGN_TCB sCANRxPgnTbl[CAN_RX_PGN_MAX];
CAN_PGN_TCB sCANTxPgnTbl[CAN_TX_PGN_MAX];
CAN_CCP10_STR sCANRxCcpPar;

/* ******************************************************************** */
/*                           CANRxPgnTblInit()                          */
/* ******************************************************************** */ 
 void CANRxPgnTblInit (void)
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
    /* ********************** 2: CAN_RX_PGN_EEC2 ********************** */
   #ifdef CAN_RX_PGN_EEC2
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_EEC2];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EEC2);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ********************** 3: CAN_RX_PGN_EEC3 ********************** */
   #ifdef CAN_RX_PGN_EEC3
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_EEC3];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EEC3);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 500 / CAN_BASIC_TIME;
   #endif
    /* ********************** 4: CAN_RX_PGN_AMCON ********************* */
   #ifdef CAN_RX_PGN_AMCON
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_AMCON];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_AMCON);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ********************* 5: CAN_RX_PGN_VEHSPD ********************* */
   #ifdef CAN_RX_PGN_VEHSPD
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_VEHSPD];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_VEHSPD);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 200 / CAN_BASIC_TIME;
   #endif
    /* ******************** 6: CAN_RX_PGN_CNFPBAM ********************* */
   #ifdef CAN_RX_PGN_CNFPBAM
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_CNFPBAM];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CNFPBAM);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 7: CAN_RX_PGN_CNFPACK ********************* */
   #ifdef CAN_RX_PGN_CNFPACK
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_CNFPACK];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CNFPACK);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
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
    /* ********************** 9: CAN_RX_PGN_LFE *********************** */
   #ifdef CAN_RX_PGN_LFE
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_LFE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_LFE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 200 / CAN_BASIC_TIME;
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
    /* ********************** 11: CAN_RX_PGN_LFC ********************** */
   #ifdef CAN_RX_PGN_LFC
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_LFC];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_LFC);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************* 12: CAN_RX_PGN_DM1SINGLE ******************* */
   #ifdef CAN_RX_PGN_DM1SINGLE
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_DM1SINGLE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM1SINGLE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************* 13: CAN_RX_PGN_DM2SINGLE ******************* */
   #ifdef CAN_RX_PGN_DM2SINGLE
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_DM2SINGLE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM2SINGLE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************* 14: CAN_RX_PGN_DM4SINGLE ******************* */
   #ifdef CAN_RX_PGN_DM4SINGLE
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_DM4SINGLE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM4SINGLE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************* 15: CAN_RX_PGN_DM11ACK ********************* */
   #ifdef CAN_RX_PGN_DM11ACK
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_DM11ACK];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM11ACK);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 16: CAN_RX_PGN_INCON ********************** */
   #ifdef CAN_RX_PGN_INCON
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_INCON];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_INCON);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 17: CAN_RX_PGN_VEHPOW ********************* */
   #ifdef CAN_RX_PGN_VEHPOW
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_VEHPOW];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_VEHPOW);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 18: CAN_RX_PGN_ENGHOUR ******************** */
   #ifdef CAN_RX_PGN_ENGHOUR
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_ENGHOUR];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_ENGHOUR);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 19: CAN_RX_PGN_CRPRESS ******************** */
   #ifdef CAN_RX_PGN_CRPRESS
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_CRPRESS];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CRPRESS);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ********************** 20: CAN_RX_PGN_EBC1 ********************* */
   #ifdef CAN_RX_PGN_EBC1
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_EBC1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EBC1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ********************** 21: CAN_RX_PGN_EBC2 ********************* */
   #ifdef CAN_RX_PGN_EBC2
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_EBC2];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EBC2);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ********************** 22: CAN_RX_PGN_ETC1 ********************* */
   #ifdef CAN_RX_PGN_ETC1
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_ETC1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_ETC1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ********************* 23: CAN_RX_PGN_RXCCVS ******************** */
   #ifdef CAN_RX_PGN_RXCCVS
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_RXCCVS];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_RXCCVS);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 200 / CAN_BASIC_TIME;
   #endif
    /* ********************** 24: CAN_RX_PGN_HRVD ********************* */
   #ifdef CAN_RX_PGN_HRVD
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_HRVD];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_HRVD);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ********************* 25: CAN_RX_PGN_PGNRQ ********************* */
   #ifdef CAN_RX_PGN_PGNRQ
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_PGNRQ];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_PGNRQ);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 26: CAN_RX_PGN_RXAMCON ******************** */
   #ifdef CAN_RX_PGN_RXAMCON
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_RXAMCON];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_RXAMCON);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ********************** 27: CAN_RX_PGN_TCO1 ********************* */
   #ifdef CAN_RX_PGN_TCO1
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_TCO1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TCO1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ********************* 28: CAN_RX_PGN_TSC1AE ******************** */
   #ifdef CAN_RX_PGN_TSC1AE
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_TSC1AE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1AE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ******************** 29: CAN_RX_PGN_TSC1DE ********************* */
   #ifdef CAN_RX_PGN_TSC1DE
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_TSC1DE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1DE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ******************** 30: CAN_RX_PGN_TSC1PE ********************* */
   #ifdef CAN_RX_PGN_TSC1PE
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_TSC1PE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1PE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ******************** 31: CAN_RX_PGN_TSC1TE ********************* */
   #ifdef CAN_RX_PGN_TSC1TE
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_TSC1TE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1TE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ******************** 32: CAN_RX_PGN_TSC1VE ********************* */
   #ifdef CAN_RX_PGN_TSC1VE
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_TSC1VE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1VE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ********************* 33: CAN_RX_PGN_DM13 ********************** */
   #ifdef CAN_RX_PGN_DM13
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_DM13];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM13);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ********************* 34: CAN_RX_PGN_DEC1 ********************** */
   #ifdef CAN_RX_PGN_DEC1
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_DEC1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DEC1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ******************* 35: CAN_RX_PGN_CCP10REQ ******************** */
   #ifdef CAN_RX_PGN_CCP10REQ
   #if   (CAN_CCP_CCP10_ON == 1)
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_CCP10REQ];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CCP10REQ);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
   #endif
    /* ******************* 36: CAN_RX_PGN_CCP10PAR ******************** */
   #ifdef CAN_RX_PGN_CCP10PAR
   #if   (CAN_CCP_CCP10_ON == 1)
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_CCP10PAR];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CCP10PAR);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
   #endif
    /* ******************** 37: CAN_RX_PGN_ECULOCK ******************** */
   #ifdef CAN_RX_PGN_ECULOCK
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_ECULOCK];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_LOCK);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 38: CAN_RX_PGN_SLAVEERR ******************* */
   #ifdef CAN_RX_PGN_SLAVEERR
    pTcb = &sCANRxPgnTbl[CAN_RX_PGN_SLAVEERR];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_SLAVEERR);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_ERR_TIMEOUT;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 2000 / CAN_BASIC_TIME;
   #endif
    /* ******************* If RX Msg Only PGN Match ******************* */
   #if (CAN_RX_PGN_MATCH_ON == 1)
    for (i=0; i<CAN_RX_PGN_MAX; i++)
    {   sCANRxPgnTbl[i].uiID = CAN_CPU_TO_PGN32(sCANRxPgnTbl[i].uiID);
    }
   #endif

 }

/* ******************************************************************** */
/*                          CANTxPgnTblInit ()                          */
/* ******************************************************************** */
void CANTxPgnTblInit (void)
{   INT08U i;
    CAN_PGN_TCB *pTcb;
    for (i=0; i<CAN_TX_PGN_MAX; i++)
    {   sCANTxPgnTbl[i].ucEnable = CAN_DISABLE;
        sCANTxPgnTbl[i].ucState  = CAN_CODE_FREE;
    }
    /* ********************** 1: CAN_TX_PGN_EEC1 ********************** */
   #ifdef CAN_TX_PGN_EEC1
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_EEC1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EEC1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 10 / CAN_BASIC_TIME;
   #endif
    /* ********************** 2: CAN_TX_PGN_EEC2 ********************** */
   #ifdef CAN_TX_PGN_EEC2
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_EEC2];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EEC2);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 50 / CAN_BASIC_TIME;
   #endif
    /* ********************** 3: CAN_TX_PGN_EEC3 ********************** */
   #ifdef CAN_TX_PGN_EEC3
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_EEC3];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EEC3);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 250 / CAN_BASIC_TIME;
   #endif
    /* ********************** 4: CAN_TX_PGN_AMCON ********************* */
   #ifdef CAN_TX_PGN_AMCON
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_AMCON];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_AMCON);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
    /* ********************* 5: CAN_TX_PGN_VEHSPD ********************* */
   #ifdef CAN_TX_PGN_VEHSPD
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_VEHSPD];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_VEHSPD);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ******************** 6: CAN_TX_PGN_CNFPBAM ********************* */
   #ifdef CAN_TX_PGN_CNFPBAM
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_CNFPBAM];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CNFPBAM);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 5000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 7: CAN_TX_PGN_CNFPACK ********************* */
   #ifdef CAN_TX_PGN_CNFPACK
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_CNFPACK];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CNFPACK);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 65535;
   #endif
    /* ******************** 8: CAN_TX_PGN_ENGTEMP ********************* */
   #ifdef CAN_TX_PGN_ENGTEMP
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_ENGTEMP];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_ENGTEMP);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
    /* ********************** 9: CAN_TX_PGN_LFE *********************** */
   #ifdef CAN_TX_PGN_LFE
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_LFE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_LFE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ********************** 10: CAN_TX_PGN_EFL ********************** */
   #ifdef CAN_TX_PGN_EFL
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_EFL];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EFL);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 500 / CAN_BASIC_TIME;
   #endif
    /* ********************** 11: CAN_TX_PGN_LFC ********************** */
   #ifdef CAN_TX_PGN_LFC
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_LFC];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_LFC);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 65535;
   #if (CAN_6800_TBS_ON == 1)
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usPeriod = 10 / CAN_BASIC_TIME;
   #endif
   #if (CAN_6800_HUA_WEI_ON == 1)
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
   #if (CAN_6800_WATER_PUMP_ON == 1)
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usPeriod = 500 / CAN_BASIC_TIME;
   #endif
   #if (CAN_6800_TWO_FUEL_ON == 1) || (CAN_8000_TWO_FUEL_ON == 1)
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usPeriod = 500 / CAN_BASIC_TIME;
   #endif
   #endif
    /* ******************* 12: CAN_TX_PGN_DM1SINGLE ******************* */
   #ifdef CAN_TX_PGN_DM1SINGLE
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_DM1SINGLE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM1SINGLE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
    /* ******************* 13: CAN_TX_PGN_DM2SINGLE ******************* */
   #ifdef CAN_TX_PGN_DM2SINGLE
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_DM2SINGLE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM2SINGLE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 65535;
   #endif
    /* ******************* 14: CAN_TX_PGN_DM4SINGLE ******************* */
   #ifdef CAN_TX_PGN_DM4SINGLE
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_DM4SINGLE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM4SINGLE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 65535;
   #endif
    /* ******************* 15: CAN_TX_PGN_DM11ACK ********************* */
   #ifdef CAN_TX_PGN_DM11ACK
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_DM11ACK];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM11ACK);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 65535;
   #endif
    /* ******************** 16: CAN_TX_PGN_INCON ********************** */
   #ifdef CAN_TX_PGN_INCON
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_INCON];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_INCON);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 17: CAN_TX_PGN_VEHPOW ********************* */
   #ifdef CAN_TX_PGN_VEHPOW
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_VEHPOW];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_VEHPOW);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 18: CAN_TX_PGN_ENGHOUR ******************** */
   #ifdef CAN_TX_PGN_ENGHOUR
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_ENGHOUR];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_ENGHOUR);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 65535;
   #if (CAN_6800_SHAN_TUI_ON == 1)
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
   #endif
    /* ******************** 19: CAN_TX_PGN_CRPRESS ******************** */
   #ifdef CAN_TX_PGN_CRPRESS
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_CRPRESS];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CRPRESS);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 500 / CAN_BASIC_TIME;
   #endif
    /* ********************** 20: CAN_TX_PGN_EBC1 ********************* */
   #ifdef CAN_TX_PGN_EBC1
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_EBC1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EBC1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 20 / CAN_BASIC_TIME;
   #endif
    /* ********************** 21: CAN_TX_PGN_EBC2 ********************* */
   #ifdef CAN_TX_PGN_EBC2
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_EBC2];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_EBC2);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 50 / CAN_BASIC_TIME;
   #endif
    /* ********************** 22: CAN_TX_PGN_ETC1 ********************* */
   #ifdef CAN_TX_PGN_ETC1
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_ETC1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_ETC1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 10 / CAN_BASIC_TIME;
   #endif
    /* ********************* 23: CAN_TX_PGN_RXCCVS ******************** */
   #ifdef CAN_TX_PGN_RXCCVS
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_RXCCVS];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_RXCCVS);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 100 / CAN_BASIC_TIME;
   #endif
    /* ********************** 24: CAN_TX_PGN_HRVD ********************* */
   #ifdef CAN_TX_PGN_HRVD
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_HRVD];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_HRVD);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
    /* ********************* 25: CAN_TX_PGN_PGNRQ ********************* */
   #ifdef CAN_TX_PGN_PGNRQ
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_PGNRQ];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_PGNRQ);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
    /* ******************** 26: CAN_TX_PGN_RXAMCON ******************** */
   #ifdef CAN_TX_PGN_RXAMCON
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_RXAMCON];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_RXAMCON);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
    /* ********************** 27: CAN_TX_PGN_TCO1 ********************* */
   #ifdef CAN_TX_PGN_TCO1
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_TCO1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TCO1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 50 / CAN_BASIC_TIME;
   #endif
    /* ********************* 28: CAN_TX_PGN_TSC1AE ******************** */
   #ifdef CAN_TX_PGN_TSC1AE
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_TSC1AE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1AE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 10 / CAN_BASIC_TIME;
   #endif
    /* ******************** 29: CAN_TX_PGN_TSC1DE ********************* */
   #ifdef CAN_TX_PGN_TSC1DE
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_TSC1DE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1DE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 10 / CAN_BASIC_TIME;
   #endif
    /* ******************** 30: CAN_TX_PGN_TSC1PE ********************* */
   #ifdef CAN_TX_PGN_TSC1PE
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_TSC1PE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1PE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 10 / CAN_BASIC_TIME;
   #endif
    /* ******************** 31: CAN_TX_PGN_TSC1TE ********************* */
   #ifdef CAN_TX_PGN_TSC1TE
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_TSC1TE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1TE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 10 / CAN_BASIC_TIME;
   #endif
    /* ******************** 32: CAN_TX_PGN_TSC1VE ********************* */
   #ifdef CAN_TX_PGN_TSC1VE
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_TSC1VE];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_TSC1VE);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 10 / CAN_BASIC_TIME;
   #endif
    /* ********************* 33: CAN_TX_PGN_DM13 ********************** */
   #ifdef CAN_TX_PGN_DM13
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_DM13];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DM13);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
    /* ********************* 34: CAN_TX_PGN_DEC1 ********************** */
   #ifdef CAN_TX_PGN_DEC1
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_DEC1];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_DEC1);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_CYCLIC;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 20 / CAN_BASIC_TIME;
   #endif
    /* ******************* 35: CAN_TX_PGN_CCP10REQ ******************** */
   #ifdef CAN_TX_PGN_CCP10REQ
   #if   (CAN_CCP_CCP10_ON == 1)
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CCP10REQ);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 65535;
   #endif
   #endif
    /* ******************* 36: CAN_TX_PGN_CCP10PAR ******************** */
   #ifdef CAN_TX_PGN_CCP10PAR
   #if   (CAN_CCP_CCP10_ON == 1)
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_CCP10PAR];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_CCP10PAR);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 65535;
   #endif
   #endif
    /* ******************** 37: CAN_TX_PGN_ECULOCK ******************** */
   #ifdef CAN_TX_PGN_ECULOCK
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_ECULOCK];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_LOCK);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 500 / CAN_BASIC_TIME;
   #endif
    /* ******************** 38: CAN_TX_PGN_SLAVEERR ******************* */
   #ifdef CAN_TX_PGN_SLAVEERR
    pTcb = &sCANTxPgnTbl[CAN_TX_PGN_SLAVEERR];
    pTcb->uiID     = CAN_ID32_TO_CPU(CAN_ID_J1939_SLAVEERR);
    pTcb->ucEnable = CAN_ENABLE;
    pTcb->ucState  = CAN_CODE_FREE;
    pTcb->usTime   = usCANTimer;
    pTcb->usPeriod = 1000 / CAN_BASIC_TIME;
   #endif
}


/* ******************************************************************** */
/*                            GeneralJ1939Init                          */
/* ******************************************************************** */ 
void GeneralJ1939Init(void)
{
    CANRxPgnTblInit();
    CANTxPgnTblInit();
}

void DBPutFCBufCode (INT16U usCode, INT08U ucBuf)
{

}


/* ******************************************************************** */
/*                           1: CAN_TX_PGN_EEC1                         */
/* ******************************************************************** */

/* ****************************** TX_EEC1 ***************************** */
#ifdef CAN_TX_PGN_EEC1
void CANUpdateTxEEC1 (CAN_MSG *pMsg)
{
   #if (CAN_6800_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = usDBmFuelLimitMaxActive;
    if (usTemp == 0)
    {   pMsg->DAT08.ucDat2 = 0;
    }   else
    {   pMsg->DAT08.ucDat2 = (INT08U)((INT32U)usDBmFuelGovernor * 100 / (INT32U)usTemp);
    }
    usTemp             = usDBmSpeed * 2;
    pMsg->DAT08.ucDat3 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = CAN_UC_HIGH (usTemp);
    pMsg->DAT08.ucDat5 = CAN_MY_ADDRESS;
   #if (CAN_6800_WATER_PUMP_ON == 1)
    usTemp             = mWPInPressure > 1000 ? mWPInPressure - 1000 : 0;
    pMsg->DAT08.ucDat0 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = CAN_UC_HIGH (usTemp);
    usTemp             = mWPOutPressure > 1000 ? mWPOutPressure - 1000 : 0;
    pMsg->DAT08.ucDat6 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = CAN_UC_HIGH (usTemp);
   #endif
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp             = usDBmSpeed * 2;
    pMsg->DAT08.ucDat2 = (INT08U)usDBmEngineLoad;
    pMsg->DAT08.ucDat3 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = CAN_UC_HIGH (usTemp);
    pMsg->DAT08.ucDat5 = CAN_MY_ADDRESS;
   #endif
}
#endif

/* ****************************** RX_EEC1 ***************************** */
#ifdef CAN_RX_PGN_EEC1
void CANUpdateRxEEC1 (CAN_MSG *pMsg)
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
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usDBmEngineLoad = pMsg->DAT08.ucDat2;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat4);
    usDBmSpeed = usTemp / 2;
   #endif
}
#endif

/* ******************************************************************** */
/*                           2: CAN_TX_PGN_EEC2                         */
/* ******************************************************************** */
/* ****************************** TX_EEC2 ***************************** */
#ifdef CAN_TX_PGN_EEC2
void CANUpdateTxEEC2 (CAN_MSG *pMsg)
{
   #if (CAN_6800_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = usDBmSpeedMaxActive - usDBmSpeedIdleActive;
    if (usDBmSetp1Extern <= usDBmSpeedIdleActive)
    {   usTemp = 0;
    }   else if (usTemp != 0)
    {   usTemp = (INT16U)((INT32U)(usDBmSetp1Extern-usDBmSpeedIdleActive)*250/(INT32U)usTemp);
    }
    if (usTemp > 250)
    {   usTemp = 250;
    }
    pMsg->DAT08.ucDat1 = (INT08U)usTemp;
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    pMsg->DAT08.ucDat1 = (INT08U)usDBmPedalPosi;
   #endif
}
#endif

/* ****************************** RX_EEC2 ***************************** */
#ifdef CAN_RX_PGN_EEC2
void CANUpdateRxEEC2 (CAN_MSG *pMsg)
{
   #ifdef DB_NO_PEDAL_POSI
    INT16U usTemp;
    usTemp = pMsg->DAT08.ucDat1;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_PEDAL_POSI].ssValue = (usTemp * 2) / 5;
        aDBDisplay[DB_NO_PEDAL_POSI].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_PEDAL_POSI].ssValue = 0;
        aDBDisplay[DB_NO_PEDAL_POSI].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    usDBmPedalPosi = pMsg->DAT08.ucDat1;
   #endif
}
#endif

/* ******************************************************************** */
/*                           3: CAN_TX_PGN_EEC3                         */
/* ******************************************************************** */
/* ****************************** TX_EEC3 ***************************** */
#ifdef CAN_TX_PGN_EEC3
void CANUpdateTxEEC3 (CAN_MSG *pMsg)
{   INT16U usTemp;
    usTemp = usDBmSpeedSetp * 2;
    pMsg->DAT08.ucDat1 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat2 = CAN_UC_HIGH (usTemp);
}
#endif

/* ****************************** RX_EEC3 ***************************** */
#ifdef CAN_RX_PGN_EEC3
void CANUpdateRxEEC3 (CAN_MSG *pMsg)
{
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat2);
    usDBmSpeedSetp = usTemp / 2;
   #endif
    pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           4: CAN_TX_PGN_AMCON                        */
/* ******************************************************************** */
/* ****************************** TX_AMCON **************************** */
#ifdef CAN_TX_PGN_AMCON
void CANUpdateTxAMCON (CAN_MSG *pMsg)
{
   #if (CAN_6800_HUA_WEI_ON == 1)
    INT16U usTemp;
    usTemp = (INT16U)((INT32U)(mHWCabinetTemp - (DB_SIGNED_ZERO-2730)) * 16 / 5);
    pMsg->DAT08.ucDat0 = (INT08U)(usDBmAmbientPressure / 10);
    pMsg->DAT08.ucDat3 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = CAN_UC_HIGH (usTemp);
   #else
    INT16U usTemp;
    usTemp = (INT16U)((INT32U)(usDBmTempIntern - (DB_SIGNED_ZERO-2730)) * 16 / 5);
    pMsg->DAT08.ucDat0 = (INT08U)(usDBmAmbientPressure / 40);
    pMsg->DAT08.ucDat3 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = CAN_UC_HIGH (usTemp);
   #endif
}
#endif

/* ****************************** RX_AMCON **************************** */
#ifdef CAN_RX_PGN_AMCON
void CANUpdateRxAMCON (CAN_MSG *pMsg)
{
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usDBmAmbientPressure = (INT16U)(pMsg->DAT08.ucDat0) * 40;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat4);
    usDBmTempIntern = (INT16U)((INT32U)usTemp * 5 / 16 + (DB_SIGNED_ZERO-2730));
   #endif
    pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           5: CAN_TX_PGN_VEHSPD                       */
/* ******************************************************************** */
/* ****************************** TX_VEHSPD *************************** */
#ifdef CAN_TX_PGN_VEHSPD
void CANUpdateTxVEHSPD (CAN_MSG *pMsg)
{   INT16U usTemp;
    usTemp             = (INT16U)((INT32U)usDBmVeSpeed * 128 / 5);
    pMsg->DAT08.ucDat1 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat2 = CAN_UC_HIGH (usTemp);
}
#endif

/* ****************************** RX_VEHSPD *************************** */
#ifdef CAN_RX_PGN_VEHSPD
void CANUpdateRxVEHSPD (CAN_MSG *pMsg)
{
   #ifdef DB_NO_VEH_SPEED
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat2);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_VEH_SPEED].ssValue = usTemp / 256;
        aDBDisplay[DB_NO_VEH_SPEED].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_VEH_SPEED].ssValue = 0;
        aDBDisplay[DB_NO_VEH_SPEED].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat2);
    usDBmVeSpeed = (INT16U)((INT32U)usTemp * 5 / 128);
   #endif
}
#endif

/* ******************************************************************** */
/*                          6: CAN_TX_PGN_CNFPBAM                       */
/* ******************************************************************** */
/* ****************************** TX_CNFPBAM ************************** */
#ifdef CAN_TX_PGN_CNFPBAM
void CANUpdateTxCNFPBAM (CAN_MSG *pMsg)
{
   #if (CAN_6800_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = APP_VERSION;
    pMsg->DAT08.ucDat3 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = CAN_UC_HIGH (usTemp);
    pMsg->DAT08.ucDat5 = 0xE3;
    pMsg->DAT08.ucDat6 = 0xFE;
    pMsg->DAT08.ucDat7 = 0x00;
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = APP_VERSION;
    pMsg->DAT08.ucDat3 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat4 = CAN_UC_HIGH (usTemp);
    pMsg->DAT08.ucDat5 = 0xE3;
    pMsg->DAT08.ucDat6 = 0xFE;
    pMsg->DAT08.ucDat7 = 0x00;
   #endif
}
#endif

/* ****************************** RX_CNFPBAM ************************** */
#ifdef CAN_RX_PGN_CNFPBAM
void CANUpdateRxCNFPBAM (CAN_MSG *pMsg)
{
   #ifdef DB_NO_ENG_CONFIG
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat4);
    if (pMsg->DAT08.ucDat5 == 0xE3)
    {   aDBDisplay[DB_NO_ENG_CONFIG].ssValue = usTemp;
        aDBDisplay[DB_NO_ENG_CONFIG].ucErr   = CAN_NO_ERR;
    }
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat3, pMsg->DAT08.ucDat4);
    usDBmEngineConfig = usTemp;
   #endif
}
#endif

/* ******************************************************************** */
/*                          7: CAN_TX_PGN_CNFPACK                       */
/* ******************************************************************** */
/* ****************************** TX_CNFPACK ************************** */
#ifdef CAN_TX_PGN_CNFPACK
void CANUpdateTxCNFPACK (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_CNFPACK ************************** */
#ifdef CAN_RX_PGN_CNFPACK
void CANUpdateRxCNFPACK (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                          8: CAN_TX_PGN_ENGTEMP                       */
/* ******************************************************************** */
/* ****************************** TX_ENGTEMP ************************** */
#ifdef CAN_TX_PGN_ENGTEMP
void CANUpdateTxENGTEMP (CAN_MSG *pMsg)
{   INT16U usTemp;
    usTemp = usDBmCoolantTemp;
   #if (CAN_6800_SHAN_TUI_ON == 1)
    if (usTemp < mSTCoolantTemp2)
    {   usTemp = mSTCoolantTemp2;
    }
   #endif
    pMsg->DAT08.ucDat0 = (INT08U)((usTemp - (DB_SIGNED_ZERO-400)) / 10);
    pMsg->DAT08.ucDat1 = (INT08U)((usDBmFuelTemp - (DB_SIGNED_ZERO-400)) / 10);
    usTemp             = (INT16U)((INT32U)(usDBmOilTemp - (DB_SIGNED_ZERO-2730)) * 16 / 5);
    pMsg->DAT08.ucDat2 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = CAN_UC_HIGH (usTemp);
}
#endif

/* ****************************** RX_ENGTEMP ************************** */
#ifdef CAN_RX_PGN_ENGTEMP
void CANUpdateRxENGTEMP (CAN_MSG *pMsg)
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
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usDBmCoolantTemp = (INT16U)(pMsg->DAT08.ucDat0) * 10 + (DB_SIGNED_ZERO-400);
    usDBmFuelTemp    = (INT16U)(pMsg->DAT08.ucDat1) * 10 + (DB_SIGNED_ZERO-400);
    usTemp           = CAN_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    usDBmOilTemp     = (INT16U)((INT32U)usTemp * 5 / 16 + (DB_SIGNED_ZERO-2730));
   #endif
}
#endif

/* ******************************************************************** */
/*                           9: CAN_TX_PGN_LFE                          */
/* ******************************************************************** */
/* ****************************** TX_LFE ****************************** */
#ifdef CAN_TX_PGN_LFE
void CANUpdateTxLFE (CAN_MSG *pMsg)
{
   #if (CAN_6800_COMMON_ON == 1)
    pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp             = usDBmFuelRate;
    pMsg->DAT08.ucDat0 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = CAN_UC_HIGH (usTemp);
    usTemp             = usDBmFuelEconomy;
    pMsg->DAT08.ucDat2 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = CAN_UC_HIGH (usTemp);
   #endif
}
#endif

/* ****************************** RX_LFE ****************************** */
#ifdef CAN_RX_PGN_LFE
void CANUpdateRxLFE (CAN_MSG *pMsg)
{
   #ifdef DB_NO_FUEL_RATE
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat1);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_FUEL_RATE].ssValue = usTemp / 20;
        aDBDisplay[DB_NO_FUEL_RATE].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_FUEL_RATE].ssValue = 0;
        aDBDisplay[DB_NO_FUEL_RATE].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #ifdef DB_NO_FUEL_ECONOMY
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_FUEL_ECONOMY].ssValue = usTemp / 512;
        aDBDisplay[DB_NO_FUEL_ECONOMY].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_FUEL_ECONOMY].ssValue = 0;
        aDBDisplay[DB_NO_FUEL_ECONOMY].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat1);
    usDBmFuelRate = usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    usDBmFuelEconomy = usTemp;
   #endif
}
#endif

/* ******************************************************************** */
/*                           10: CAN_TX_PGN_EFL                         */
/* ******************************************************************** */
/* ****************************** TX_EFL ****************************** */
#ifdef CAN_TX_PGN_EFL
void CANUpdateTxEFL (CAN_MSG *pMsg)
{
   #if (CAN_6800_COMMON_ON == 1) || (CAN_8000_COMMON_ON == 1)
   #if (CAN_PRESS_RELATIVE_ON == 1)
    pMsg->DAT08.ucDat0 = 0;
    if (usDBmOilPressure > 1000)
    {   pMsg->DAT08.ucDat3 = (INT08U)((usDBmOilPressure - 1000) / 40);
    }   else
    {   pMsg->DAT08.ucDat3 = (INT08U)0;
    }
    pMsg->DAT08.ucDat7 = 0;
   #else
    pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat3 = (INT08U)(usDBmOilPressure / 40);
    pMsg->DAT08.ucDat7 = 0;
   #endif
   #endif
   #if (CAN_6800_SHAN_TUI_ON == 1)
    if((usDBmSwitchEngineStop != 0) ||
       (usDBmEngineStopping   != 0) ||
       (usDBmEngineRunning    != 0) ||
       (usDBmAirHeaterActive  != 0) ||
       (usDBmOilPumpActive    != 0) ||
       (usDBmSwitchClutch     != 0) )
    {   pMsg->DAT08.ucDat7 = 1;
    }   else
    {   pMsg->DAT08.ucDat7 = 0;
    }
   #endif
   #if (CAN_6800_WATER_PUMP_ON == 1)
    if (mWPFuelLevel > 1000)
    {   pMsg->DAT08.ucDat7 = 250;
    }   else
    {   pMsg->DAT08.ucDat7 = (INT08U)(mWPFuelLevel / 4);
    }
   #endif
   #if (CAN_4000_COMMON_ON == 1)
   #if (CAN_PRESS_RELATIVE_ON == 1)
    if (usDBmFuelPressure > 1000)
    {   pMsg->DAT08.ucDat0 = (INT08U)((usDBmFuelPressure - 1000) / 40);
    }   else
    {   pMsg->DAT08.ucDat0 = (INT08U)0;
    }
    if (usDBmOilPressure > 1000)
    {   pMsg->DAT08.ucDat3 = (INT08U)((usDBmOilPressure - 1000) / 40);
    }   else
    {   pMsg->DAT08.ucDat3 = (INT08U)0;
    }
    pMsg->DAT08.ucDat7 = 0;
   #else
    pMsg->DAT08.ucDat0 = (INT08U)(usDBmFuelPressure / 40);
    pMsg->DAT08.ucDat3 = (INT08U)(usDBmOilPressure / 40);
    pMsg->DAT08.ucDat7 = 0;
   #endif
   #endif
}
#endif

/* ****************************** RX_EFL ****************************** */
#ifdef CAN_RX_PGN_EFL
void CANUpdateRxEFL (CAN_MSG *pMsg)
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

/* ******************************************************************** */
/*                           11: CAN_TX_PGN_LFC                         */
/* ******************************************************************** */
/* ****************************** TX_LFC ****************************** */
#ifdef CAN_TX_PGN_LFC
void CANUpdateTxLFC (CAN_MSG *pMsg)
{
   #if (CAN_6800_TBS_ON == 1)
    INT16U usTemp;
    usTemp             = mTBSVoltage;
    pMsg->DAT08.ucDat0 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = CAN_UC_HIGH (usTemp);
    usTemp             = mTBSCurrent;
    pMsg->DAT08.ucDat2 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = CAN_UC_HIGH (usTemp);
    usTemp             = mTBSBattVoltage;
    pMsg->DAT08.ucDat4 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = CAN_UC_HIGH (usTemp);
    usTemp             = (INT16U)((INT32U)(mTBSBattTemp - (DB_SIGNED_ZERO-2730)) * 16 / 5);
    pMsg->DAT08.ucDat6 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = CAN_UC_HIGH (usTemp);
   #endif
   #if (CAN_6800_HUA_WEI_ON == 1)
    INT16U usTemp;
    usTemp             = mHWOilPressure0;
    pMsg->DAT08.ucDat0 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = CAN_UC_HIGH (usTemp);
    usTemp             = mHWFuelLevel;
    pMsg->DAT08.ucDat2 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = CAN_UC_HIGH (usTemp);
    usTemp             = mHWFillerCurrent;
    pMsg->DAT08.ucDat4 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = CAN_UC_HIGH (usTemp);
    usTemp             = mHWSwitchStatus;
    pMsg->DAT08.ucDat6 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = CAN_UC_HIGH (usTemp);
   #endif
   #if (CAN_6800_WATER_PUMP_ON == 1)
    INT16U usTemp;
    usTemp             = mWPBatteryVoltage1;
    pMsg->DAT08.ucDat0 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = CAN_UC_HIGH (usTemp);
    usTemp             = mWPBatteryVoltage2;
    pMsg->DAT08.ucDat2 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = CAN_UC_HIGH (usTemp);
    usTemp             = mWPChargerVoltage1;
    pMsg->DAT08.ucDat4 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = CAN_UC_HIGH (usTemp);
    usTemp             = mWPChargerVoltage2;
    pMsg->DAT08.ucDat6 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = CAN_UC_HIGH (usTemp);
   #endif
   #if (CAN_6800_TWO_FUEL_ON == 1) || (CAN_8000_TWO_FUEL_ON == 1)
    INT16U usTemp;
    usTemp             = usDBmFuelTemp;
    pMsg->DAT08.ucDat0 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = CAN_UC_HIGH (usTemp);
    usTemp             = mTFFuelPress;
    pMsg->DAT08.ucDat2 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = CAN_UC_HIGH (usTemp);
   #endif
    pMsg = pMsg;   
}
#endif

/* ****************************** RX_LFC ****************************** */
#ifdef CAN_RX_PGN_LFC
void CANUpdateRxLFC (CAN_MSG *pMsg)
{
   #if (CAN_1000_COMMON_ON == 1)
   #if (CAN_1000_TWO_FUEL_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat1);
    aDBDisplay[DB_NO_FUEL_TEMP].ssValue = (INT16S)(usTemp - DB_SIGNED_ZERO) / 10;
    aDBDisplay[DB_NO_FUEL_TEMP].ucErr   = CAN_NO_ERR;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    if (usTemp >= 1000)
    {   usTemp -= 1000;
    }   else
    {   usTemp  = 0;
    }
    aDBDisplay[DB_NO_FUEL_PRES].ssValue = usTemp / 10;
    aDBDisplay[DB_NO_FUEL_PRES].ucErr   = CAN_NO_ERR;
   #endif
   #endif
    pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                        12: CAN_TX_PGN_DM1SINGLE                      */
/* ******************************************************************** */
/* ****************************** TX_DM1 ****************************** */
#ifdef CAN_TX_PGN_DM1SINGLE
void CANUpdateTxDM1 (CAN_MSG *pMsg)
{   INT16U usTemp;
    INT32U uiTemp;
    if (SFCheckErrorsToStop() == 0)
    {   pMsg->DAT08.ucDat0  = 0x00;
    }   else
    {   pMsg->DAT08.ucDat0  = 0x10;
    }
    if (SFCheckErrorsToWarn() != 0)
    {   pMsg->DAT08.ucDat0 |= 0x04;
    }
    usTemp = SFGetNextCanTxCode(0);
   #if (CAN_TX_DM1_DM2_SPN_ON == 1)
    uiTemp = SFErrCodeToSpnCode(usTemp);
    pMsg->DAT08.ucDat2  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat4  = (INT08U)(uiTemp >> 11);
    pMsg->DAT08.ucDat4 &= 0xE0;
    pMsg->DAT08.ucDat4 |= SFErrCodeToFmiCode(usTemp);
    pMsg->DAT08.ucDat5  = (INT08U)(uiTemp >> 19);
   #else
    uiTemp = usTemp;
    pMsg->DAT08.ucDat2  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat4  = 0;
    pMsg->DAT08.ucDat5  = 0;
   #endif
}
#endif

/* ****************************** RX_DM1 ****************************** */
#ifdef CAN_RX_PGN_DM1SINGLE
void CANUpdateRxDM1 (CAN_MSG *pMsg)
{   INT16U usTemp;
    INT32U uiTemp;
   // usDBmStopLampActive = pMsg->DAT08.ucDat0 & 0x30;
   // usDBmWarnLampActive = pMsg->DAT08.ucDat0 & 0x0C;
    pMsg->DAT08.ucDat4 &= 0xE0;
    uiTemp  = (INT32U)(pMsg->DAT08.ucDat2) +
             ((INT32U)(pMsg->DAT08.ucDat3) << 8)  +
             ((INT32U)(pMsg->DAT08.ucDat4) << 11) +
             ((INT32U)(pMsg->DAT08.ucDat5) << 19) ;
    if (uiTemp >= (INT32U)520000)
    {   uiTemp -= (INT32U)520000;
    }
    usTemp = (INT16U)uiTemp;
   #ifdef DB_NO_ACT_FAULT
   #if (CAN_IGNORE_SPEED_ERROR == 1)
    if((usTemp == ERR_CODE_CRANK_SENSOR1) ||
       (usTemp == ERR_CODE_CRANK_SENSOR2) ||
       (usTemp == ERR_CODE_VSS_SENSOR) )
    {   usTemp  = 0;
    }
   #endif
   #if (CAN_IGNORE_RACK_ERROR == 1)
    if((usTemp == ERR_CODE_RACK_DELTA) ||
       (usTemp == ERR_CODE_RACK_WAVE ) )
    {   usTemp  = 0;
    }
   #endif
    DBPutFCBufCode(usTemp,0);
    aDBDisplay[DB_NO_ACT_FAULT].ssValue = usTemp;
    aDBDisplay[DB_NO_ACT_FAULT].ucErr   = CAN_NO_ERR;
   #endif
   #if (CAN_4000_COMMON_ON == 1)
   #if (CAN_IGNORE_SPEED_ERROR == 1)
    if((usTemp == ERR_CODE_CRANK_SENSOR1) ||
       (usTemp == ERR_CODE_CRANK_SENSOR2) ||
       (usTemp == ERR_CODE_VSS_SENSOR) )
    {   usTemp  = 0;
    }
   #endif
    usDBmActFault = usTemp;
   #endif
}
#endif

/* ******************************************************************** */
/*                        13: CAN_TX_PGN_DM2SINGLE                      */
/* ******************************************************************** */
/* ****************************** TX_DM2 ****************************** */
#ifdef CAN_TX_PGN_DM2SINGLE
void CANUpdateTxDM2 (CAN_MSG *pMsg)
{   INT16U usTemp;
    INT32U uiTemp;
    if (SFCheckErrorsToStop() == 0)
    {   pMsg->DAT08.ucDat0  = 0x00;
    }   else
    {   pMsg->DAT08.ucDat0  = 0x20;
    }
    if (SFCheckErrorsToWarn() != 0)
    {   pMsg->DAT08.ucDat0 |= 0x08;
    }
    usTemp = SFGetNextCanTxCode(1);
   #if (CAN_TX_DM1_DM2_SPN_ON == 1)
    uiTemp = SFErrCodeToSpnCode(usTemp);
    pMsg->DAT08.ucDat2  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat4  = (INT08U)(uiTemp >> 11);
    pMsg->DAT08.ucDat4 &= 0xE0;
    pMsg->DAT08.ucDat4 |= SFErrCodeToFmiCode(usTemp);
    pMsg->DAT08.ucDat5  = (INT08U)(uiTemp >> 19);
   #else
    uiTemp = usTemp;
    pMsg->DAT08.ucDat2  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat4  = 0;
    pMsg->DAT08.ucDat5  = 0;
   #endif
}
#endif

/* ****************************** RX_DM2 ****************************** */
#ifdef CAN_RX_PGN_DM2SINGLE
void CANUpdateRxDM2 (CAN_MSG *pMsg)
{   INT16U usTemp;
    INT32U uiTemp;
    pMsg->DAT08.ucDat4 &= 0xE0;
    uiTemp  = (INT32U)(pMsg->DAT08.ucDat2) +
             ((INT32U)(pMsg->DAT08.ucDat3) << 8)  +
             ((INT32U)(pMsg->DAT08.ucDat4) << 11) +
             ((INT32U)(pMsg->DAT08.ucDat5) << 19) ;
    if (uiTemp >= (INT32U)520000)
    {   uiTemp -= (INT32U)520000;
    }
    usTemp = (INT16U)uiTemp;
   #ifdef DB_NO_STO_FAULT
   #if (CAN_IGNORE_SPEED_ERROR == 1)
    if((usTemp == ERR_CODE_CRANK_SENSOR1) ||
       (usTemp == ERR_CODE_CRANK_SENSOR2) ||
       (usTemp == ERR_CODE_VSS_SENSOR) )
    {   usTemp  = 0;
    }
   #endif
   #if (CAN_IGNORE_RACK_ERROR == 1)
    if((usTemp == ERR_CODE_RACK_DELTA) ||
       (usTemp == ERR_CODE_RACK_WAVE ) )
    {   usTemp  = 0;
    }
   #endif
    DBPutFCBufCode(usTemp,1);
    aDBDisplay[DB_NO_STO_FAULT].ssValue = usTemp;
    aDBDisplay[DB_NO_STO_FAULT].ucErr   = CAN_NO_ERR;
   #endif
   #if (CAN_4000_COMMON_ON == 1)
   #if (CAN_IGNORE_SPEED_ERROR == 1)
    if((usTemp == ERR_CODE_CRANK_SENSOR1) ||
       (usTemp == ERR_CODE_CRANK_SENSOR2) ||
       (usTemp == ERR_CODE_VSS_SENSOR) )
    {   usTemp  = 0;
    }
   #endif
    usDBmStoFault = usTemp;
   #endif
}
#endif

/* ******************************************************************** */
/*                        14: CAN_TX_PGN_DM4SINGLE                      */
/* ******************************************************************** */
/* ****************************** TX_DM4 ****************************** */
#ifdef CAN_TX_PGN_DM4SINGLE
void CANUpdateTxDM4 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_DM4 ****************************** */
#ifdef CAN_RX_PGN_DM4SINGLE
void CANUpdateRxDM4 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                         15: CAN_TX_PGN_DM11ACK                       */
/* ******************************************************************** */
/* ****************************** TX_DM11 ***************************** */
#ifdef CAN_TX_PGN_DM11ACK
void CANUpdateTxDM11ACK (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_DM11 ***************************** */
#ifdef CAN_RX_PGN_DM11ACK
void CANUpdateRxDM11ACK (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                          16: CAN_TX_PGN_INCON                        */
/* ******************************************************************** */
/* ****************************** TX_INCON **************************** */
#ifdef CAN_TX_PGN_INCON
void CANUpdateTxINCON (CAN_MSG *pMsg)
{   INT16U usTemp, usPres;
    usTemp = usDBmBoostTemp;
    usPres = usDBmBoostPressure;
   #if (CAN_6800_SHAN_TUI_ON == 1)
    if (usTemp < mSTBoostTemp2)
    {   usTemp = mSTBoostTemp2;
    }
    if (usPres < mSTBoostPressure2)
    {   usPres = mSTBoostPressure2;
    }
   #endif
    pMsg->DAT08.ucDat2 = (INT08U)((usTemp - (DB_SIGNED_ZERO-400)) / 10);
   #if (CAN_PRESS_RELATIVE_ON == 1)
    if (usPres > 1000)
    {   pMsg->DAT08.ucDat3 = (INT08U)((usPres - 1000) / 20);
    }   else
    {   pMsg->DAT08.ucDat3 = (INT08U)0;
    }
   #else
    pMsg->DAT08.ucDat3 = (INT08U)(usPres / 20);
   #endif
   #if (CAN_6800_TWO_FUEL_ON == 1) || (CAN_8000_TWO_FUEL_ON == 1)
    usTemp = usDBmExhaustTemp;
    pMsg->DAT08.ucDat4 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = CAN_UC_HIGH (usTemp);
   #endif
}
#endif

/* ****************************** RX_INCON **************************** */
#ifdef CAN_RX_PGN_INCON
void CANUpdateRxINCON (CAN_MSG *pMsg)
{
   #ifdef DB_NO_AIR_TEMP
   #if (CAN_1000_TWO_FUEL_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    if (usTemp <= (INT16U)62768)
    {   aDBDisplay[DB_NO_AIR_TEMP].ssValue = (INT16S)(usTemp - DB_SIGNED_ZERO) / 10;
        aDBDisplay[DB_NO_AIR_TEMP].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_AIR_TEMP].ssValue = 0;
        aDBDisplay[DB_NO_AIR_TEMP].ucErr   = CAN_ERR_INVALID;
    }
   #else
    INT16U usTemp;
    usTemp = pMsg->DAT08.ucDat2;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_AIR_TEMP].ssValue = usTemp - 40;
        aDBDisplay[DB_NO_AIR_TEMP].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_AIR_TEMP].ssValue = 0;
        aDBDisplay[DB_NO_AIR_TEMP].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #endif
   #ifdef DB_NO_AIR_PRES
    usTemp = pMsg->DAT08.ucDat3;
    if (usTemp <= 250)
    {   aDBDisplay[DB_NO_AIR_PRES].ssValue = usTemp * 2;
        aDBDisplay[DB_NO_AIR_PRES].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_AIR_PRES].ssValue = 0;
        aDBDisplay[DB_NO_AIR_PRES].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #if (CAN_4000_COMMON_ON == 1)
   #if (CAN_PRESS_RELATIVE_ON == 1)
    usDBmBoostTemp = (INT16U)(pMsg->DAT08.ucDat2) * 10 + (DB_SIGNED_ZERO-400);
    usDBmBoostPressure = (INT16U)(pMsg->DAT08.ucDat3) * 20 + 1000;
   #else
    usDBmBoostTemp = (INT16U)(pMsg->DAT08.ucDat2) * 10 + (DB_SIGNED_ZERO-400);
    usDBmBoostPressure = (INT16U)(pMsg->DAT08.ucDat3) * 20;
   #endif
   #endif
}
#endif

/* ******************************************************************** */
/*                          17: CAN_TX_PGN_VEHPOW                       */
/* ******************************************************************** */
/* ****************************** TX_VEHPOW *************************** */
#ifdef CAN_TX_PGN_VEHPOW
void CANUpdateTxVEHPOW (CAN_MSG *pMsg)
{   INT16U usTemp;
    usTemp = (INT16U)((INT32U)usDBmPowerSupply * 220 / 819);
    pMsg->DAT08.ucDat6 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = CAN_UC_HIGH (usTemp);
}
#endif

/* ****************************** RX_VEHPOW *************************** */
#ifdef CAN_RX_PGN_VEHPOW
void CANUpdateRxVEHPOW (CAN_MSG *pMsg)
{
   #ifdef DB_NO_SYS_VOLT
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_SYS_VOLT].ssValue = usTemp / 20;
        aDBDisplay[DB_NO_SYS_VOLT].ucErr = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_SYS_VOLT].ssValue = 0;
        aDBDisplay[DB_NO_SYS_VOLT].ucErr = CAN_ERR_INVALID;
    }
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usDBmPowerSupply = (INT16U)((INT32U)usTemp * 819 / 220);
   #endif
}
#endif

/* ******************************************************************** */
/*                         18: CAN_TX_PGN_ENGHOUR                       */
/* ******************************************************************** */
/* ****************************** TX_ENGHOUR ************************** */
#ifdef CAN_TX_PGN_ENGHOUR
void CANUpdateTxENGHOUR (CAN_MSG *pMsg)
{   INT32U uiTemp;
    uiTemp = uiDBmTimer32 / (FW_FRQ_ENGINE_TIMER * 180);
    pMsg->DAT08.ucDat0  = (INT08U)uiTemp;
    pMsg->DAT08.ucDat1  = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat2  = (INT08U)(uiTemp >> 16);
    pMsg->DAT08.ucDat3  = (INT08U)(uiTemp >> 24);
}
#endif

/* ****************************** RX_ENGHOUR ************************** */
#ifdef CAN_RX_PGN_ENGHOUR
void CANUpdateRxENGHOUR (CAN_MSG *pMsg)
{
   #ifdef DB_NO_ENG_HOUR
    INT32U uiTemp;
    uiTemp  = (INT32U)(pMsg->DAT08.ucDat0) +
             ((INT32U)(pMsg->DAT08.ucDat1) << 8)  +
             ((INT32U)(pMsg->DAT08.ucDat2) << 16) +
             ((INT32U)(pMsg->DAT08.ucDat3) << 24) ;
    uiTemp /= 20;
    if (uiTemp < (INT32U)0x8000)
    {   aDBDisplay[DB_NO_ENG_HOUR].ssValue = (INT16S)uiTemp;
        //aDBDisplay[DB_NO_ENG_HOUR].pUnit   = &eHourUnit[0];
        aDBDisplay[DB_NO_ENG_HOUR].ucErr   = CAN_NO_ERR;
    }   else if (uiTemp < ((INT32U)0x8000 * 10))
    {   uiTemp /= 10;
        aDBDisplay[DB_NO_ENG_HOUR].ssValue = (INT16S)uiTemp;
        //aDBDisplay[DB_NO_ENG_HOUR].pUnit   = &eHourUnit2[0];
        aDBDisplay[DB_NO_ENG_HOUR].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_ENG_HOUR].ssValue = (INT16S)0x7FFF;
        //aDBDisplay[DB_NO_ENG_HOUR].pUnit   = &eHourUnit2[0];
        aDBDisplay[DB_NO_ENG_HOUR].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT32U uiTemp;
    uiTemp  = (INT32U)(pMsg->DAT08.ucDat0) +
             ((INT32U)(pMsg->DAT08.ucDat1) << 8)  +
             ((INT32U)(pMsg->DAT08.ucDat2) << 16) +
             ((INT32U)(pMsg->DAT08.ucDat3) << 24) ;
    uiDBmTimer32 = uiTemp * (FW_FRQ_ENGINE_TIMER * 180);
   #endif
}
#endif

/* ******************************************************************** */
/*                         19: CAN_TX_PGN_CRPRESS                       */
/* ******************************************************************** */
/* ****************************** TX_CRPRESS ************************** */
#ifdef CAN_TX_PGN_CRPRESS
void CANUpdateTxCRPRESS (CAN_MSG *pMsg)
{
   #if (CAN_6800_COMMON_ON == 1)
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = usDBmRailPressure;
    pMsg->DAT08.ucDat4 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = CAN_UC_HIGH (usTemp);
   #endif
}
#endif

/* ****************************** RX_CRPRESS ************************** */
#ifdef CAN_RX_PGN_CRPRESS
void CANUpdateRxCRPRESS (CAN_MSG *pMsg)
{
   #ifdef DB_NO_RAIL_PRES
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_RAIL_PRES].ssValue = usTemp / 100;
        aDBDisplay[DB_NO_RAIL_PRES].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_RAIL_PRES].ssValue = 0;
        aDBDisplay[DB_NO_RAIL_PRES].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usDBmRailPressure = usTemp;
   #endif
}
#endif

/* ******************************************************************** */
/*                           20: CAN_TX_PGN_EBC1                        */
/* ******************************************************************** */
/* ****************************** TX_EBC1 ***************************** */
#ifdef CAN_TX_PGN_EBC1
void CANUpdateTxEBC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_EBC1 ***************************** */
#ifdef CAN_RX_PGN_EBC1
void CANUpdateRxEBC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           21: CAN_TX_PGN_EBC2                        */
/* ******************************************************************** */
/* ****************************** TX_EBC2 ***************************** */
#ifdef CAN_TX_PGN_EBC2
void CANUpdateTxEBC2 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_EBC2 ***************************** */
#ifdef CAN_RX_PGN_EBC2
void CANUpdateRxEBC2 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           22: CAN_TX_PGN_ETC1                        */
/* ******************************************************************** */
/* ****************************** TX_ETC1 ***************************** */
#ifdef CAN_TX_PGN_ETC1
void CANUpdateTxETC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_ETC1 ***************************** */
#ifdef CAN_RX_PGN_ETC1
void CANUpdateRxETC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           23: CAN_TX_PGN_RXCCVS                      */
/* ******************************************************************** */
/* ****************************** TX_RXCCVS *************************** */
#ifdef CAN_TX_PGN_RXCCVS
void CANUpdateTxRXCCVS (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_RXCCVS *************************** */
#ifdef CAN_RX_PGN_RXCCVS
void CANUpdateRxRXCCVS (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                            24: CAN_TX_PGN_HRVD                       */
/* ******************************************************************** */
/* ****************************** TX_HRVD ***************************** */
#ifdef CAN_TX_PGN_HRVD
void CANUpdateTxHRVD (CAN_MSG *pMsg)
{   INT32U uiTemp;
    uiTemp = uiDBmMiles32;
    pMsg->DAT08.ucDat0 = (INT08U)uiTemp;
    pMsg->DAT08.ucDat1 = (INT08U)(uiTemp >> 8);
    pMsg->DAT08.ucDat2 = (INT08U)(uiTemp >> 16);
    pMsg->DAT08.ucDat3 = (INT08U)(uiTemp >> 24);
}
#endif

/* ****************************** RX_HRVD ***************************** */
#ifdef CAN_RX_PGN_HRVD
void CANUpdateRxHRVD (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                           25: CAN_TX_PGN_PGNRQ                       */
/* ******************************************************************** */
/* ****************************** TX_PGNRQ **************************** */
#ifdef CAN_TX_PGN_PGNRQ
void CANUpdateTxPGNRQ (CAN_MSG *pMsg)
{   static INT08U ucCANTxFlagPGNRQ = 0;
    if (ucCANTxFlagPGNRQ == 0)
    {   ucCANTxFlagPGNRQ  = 4;
    }   else
    {   ucCANTxFlagPGNRQ  = 0;
    }
    if (ucCANTxFlagPGNRQ == 0)
    {   pMsg->DAT08.ucDat0 = 0xCB;
    }   else if (ucCANTxFlagPGNRQ == 1)
    {   pMsg->DAT08.ucDat0 = 0xCD;
    }   else if (ucCANTxFlagPGNRQ == 2)
    {   pMsg->DAT08.ucDat0 = 0xD3;
    }   else if (ucCANTxFlagPGNRQ == 3)
    {   pMsg->DAT08.ucDat0 = 0x00;
    }   else if (ucCANTxFlagPGNRQ == 4)
    {   pMsg->DAT08.ucDat0 = 0xE5;
    }   else if (ucCANTxFlagPGNRQ == 5)
    {   pMsg->DAT08.ucDat0 = 0xE9;
    }   else if (ucCANTxFlagPGNRQ == 6)
    {   pMsg->DAT08.ucDat0 = 0xDA;
    }   else if (ucCANTxFlagPGNRQ == 7)
    {   pMsg->DAT08.ucDat0 = 0xEB;
    }   else
    {   pMsg->DAT08.ucDat0 = 0x00;
    }
    pMsg->DAT08.ucDat1 = 0xFE;
    pMsg->DAT08.ucDat2 = 0x00;
}
#endif

/* ****************************** RX_PGNRQ **************************** */
#ifdef CAN_RX_PGN_PGNRQ
void CANUpdateRxPGNRQ (CAN_MSG *pMsg)
{   INT08U ucFlag;
    ucFlag = 8;
    if ((pMsg->DAT08.ucDat1 == 0xFE) && (pMsg->DAT08.ucDat2 == 0x00))
    {   if (pMsg->DAT08.ucDat0 == 0xCB)
        {   ucFlag = 0;
        }   else if (pMsg->DAT08.ucDat0 == 0xCD)
        {   ucFlag = 1;
        }   else if (pMsg->DAT08.ucDat0 == 0xD3)
        {   ucFlag = 2;
        }   else if (pMsg->DAT08.ucDat0 == 0x00)
        {   ucFlag = 3;
        }   else if (pMsg->DAT08.ucDat0 == 0xE5)
        {   ucFlag = 4;
        }   else if (pMsg->DAT08.ucDat0 == 0xE9)
        {   ucFlag = 5;
        }   else if (pMsg->DAT08.ucDat0 == 0xDA)
        {   ucFlag = 6;
        }   else if (pMsg->DAT08.ucDat0 == 0xEB)
        {   ucFlag = 7;
        }
    }
    if (0) {;}
   #ifdef CAN_TX_PGN_DM2SINGLE
    else if (ucFlag == 0)
    {   if (sCANTxPgnTbl[CAN_TX_PGN_DM2SINGLE].ucEnable != CAN_DISABLE)
        {   sCANTxPgnTbl[CAN_TX_PGN_DM2SINGLE].ucState = CAN_CODE_IMMED;
        }
    }
   #endif
   #ifdef CAN_TX_PGN_DM4SINGLE
    else if (ucFlag == 1)
    {   if (sCANTxPgnTbl[CAN_TX_PGN_DM4SINGLE].ucEnable != CAN_DISABLE)
        {   sCANTxPgnTbl[CAN_TX_PGN_DM4SINGLE].ucState = CAN_CODE_IMMED;
        }
    }
   #endif
   #ifdef CAN_TX_PGN_DM11SINGLE
    else if (ucFlag == 2)
    {   if (sCANTxPgnTbl[CAN_TX_PGN_DM11SINGLE].ucEnable != CAN_DISABLE)
        {   sCANTxPgnTbl[CAN_TX_PGN_DM11SINGLE].ucState = CAN_CODE_IMMED;
        }
    }
   #endif
   #ifdef CAN_TX_PGN_ENGHOUR
    else if (ucFlag == 4)
    {   if (sCANTxPgnTbl[CAN_TX_PGN_ENGHOUR].ucEnable != CAN_DISABLE)
        {   sCANTxPgnTbl[CAN_TX_PGN_ENGHOUR].ucState = CAN_CODE_IMMED;
        }
    }
   #endif
}
#endif

/* ******************************************************************** */
/*                          26: CAN_TX_PGN_RXAMCON                      */
/* ******************************************************************** */
/* ****************************** TX_RXAMCON ************************** */
#ifdef CAN_TX_PGN_RXAMCON
void CANUpdateTxRXAMCON (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_RXAMCON ************************** */
#ifdef CAN_RX_PGN_RXAMCON
void CANUpdateRxRXAMCON (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                            27: CAN_TX_PGN_TCO1                       */
/* ******************************************************************** */
/* ****************************** TX_TCO1 ***************************** */
#ifdef CAN_TX_PGN_TCO1
void CANUpdateTxTCO1 (CAN_MSG *pMsg)
{   INT16U usTemp;
    usTemp = (INT16U)((INT32U)usDBmVeSpeed * 128 / 5);
    pMsg->DAT08.ucDat6 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = CAN_UC_HIGH (usTemp);
}
#endif

/* ****************************** RX_TCO1 ***************************** */
#ifdef CAN_RX_PGN_TCO1
void CANUpdateRxTCO1 (CAN_MSG *pMsg)
{
   #ifdef DB_NO_VEH_SPEED
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    if (usTemp <= 64255)
    {   aDBDisplay[DB_NO_VEH_SPEED].ssValue = usTemp / 256;
        aDBDisplay[DB_NO_VEH_SPEED].ucErr   = CAN_NO_ERR;
    }   else
    {   aDBDisplay[DB_NO_VEH_SPEED].ssValue = 0;
        aDBDisplay[DB_NO_VEH_SPEED].ucErr   = CAN_ERR_INVALID;
    }
   #endif
   #if (CAN_6800_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usDBmVeSpeed = (INT16U)((INT32U)usTemp * 5 / 128);
   #endif
   #if (CAN_4000_COMMON_ON == 1)
    INT16U usTemp;
    usTemp = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usDBmVeSpeed = (INT16U)((INT32U)usTemp * 5 / 128);
   #endif
}
#endif

/* ******************************************************************** */
/*                           28: CAN_TX_PGN_TSC1AE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1AE *************************** */
#ifdef CAN_TX_PGN_TSC1AE
void CANUpdateTxTSC1AE (CAN_MSG *pMsg)
{
   #if (CAN_6800_TWO_FUEL_ON == 1) || (CAN_8000_TWO_FUEL_ON == 1)
    INT16U usTemp;
    usTemp = mTFTxGasQuantity * 2;
    pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat2 = CAN_UC_HIGH (usTemp);
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
   #else
    pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
   #endif
}
#endif

/* ****************************** RX_TSC1AE *************************** */
#ifdef CAN_RX_PGN_TSC1AE
void CANUpdateRxTSC1AE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = CAN_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat2);
    usDBmCanSetpoint2 = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usDBmCanSetpoint3 = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat3);
    usTemp            = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                           29: CAN_TX_PGN_TSC1DE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1DE *************************** */
#ifdef CAN_TX_PGN_TSC1DE
void CANUpdateTxTSC1DE (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
}
#endif

/* ****************************** RX_TSC1DE *************************** */
#ifdef CAN_RX_PGN_TSC1DE
void CANUpdateRxTSC1DE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = CAN_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat2);
    usDBmCanSetpoint2 = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usDBmCanSetpoint3 = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat3);
    usTemp            = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                           30: CAN_TX_PGN_TSC1PE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1PE *************************** */
#ifdef CAN_TX_PGN_TSC1PE
void CANUpdateTxTSC1PE (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
}
#endif

/* ****************************** RX_TSC1PE *************************** */
#ifdef CAN_RX_PGN_TSC1PE
void CANUpdateRxTSC1PE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = CAN_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat2);
    usDBmCanSetpoint2 = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usDBmCanSetpoint3 = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat3);
    usTemp            = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                           31: CAN_TX_PGN_TSC1TE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1TE *************************** */
#ifdef CAN_TX_PGN_TSC1TE
void CANUpdateTxTSC1TE (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
}
#endif

/* ****************************** RX_TSC1TE *************************** */
#ifdef CAN_RX_PGN_TSC1TE
void CANUpdateRxTSC1TE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = CAN_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat2);
    usDBmCanSetpoint2 = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usDBmCanSetpoint3 = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat3);
    usTemp            = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                           32: CAN_TX_PGN_TSC1VE                      */
/* ******************************************************************** */
/* ****************************** TX_TSC1VE *************************** */
#ifdef CAN_TX_PGN_TSC1VE
void CANUpdateTxTSC1VE (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = 0;
    pMsg->DAT08.ucDat1 = 0;
    pMsg->DAT08.ucDat2 = 0;
    pMsg->DAT08.ucDat3 = 0;
    pMsg->DAT08.ucDat4 = 0;
    pMsg->DAT08.ucDat5 = 0;
    pMsg->DAT08.ucDat6 = 0;
    pMsg->DAT08.ucDat7 = 0;
}
#endif

/* ****************************** RX_TSC1VE *************************** */
#ifdef CAN_RX_PGN_TSC1VE
void CANUpdateRxTSC1VE (CAN_MSG *pMsg)
{   INT16U usTemp;
    usDBmCanSetpoint1 = CAN_US_CREAT (pMsg->DAT08.ucDat1, pMsg->DAT08.ucDat2);
    usDBmCanSetpoint2 = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usDBmCanSetpoint3 = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat3);
    usTemp            = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usTemp           &= 0x7FFF;
    if (usDBmCanSetpoint1 == 0)
    {   usTemp       |= 0x8000;
    }
    usDBmCanBinaryIn  = usTemp;
}
#endif

/* ******************************************************************** */
/*                            33: CAN_TX_PGN_DM13                       */
/* ******************************************************************** */
/* ****************************** TX_DM13 ***************************** */
#ifdef CAN_TX_PGN_DM13
void CANUpdateTxDM13 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_DM13 ***************************** */
#ifdef CAN_RX_PGN_DM13
void CANUpdateRxDM13 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                            34: CAN_TX_PGN_DEC1                       */
/* ******************************************************************** */
/* ****************************** TX_DEC1 ***************************** */
#ifdef CAN_TX_PGN_DEC1
void CANUpdateTxDEC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_DEC1 ***************************** */
#ifdef CAN_RX_PGN_DEC1
void CANUpdateRxDEC1 (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ******************************************************************** */
/*                          35: CAN_TX_PGN_CCP10REQ                     */
/* ******************************************************************** */
/* ****************************** TX_CCPREQ *************************** */
#ifdef CAN_TX_PGN_CCP10REQ
#if   (CAN_CCP_CCP10_ON == 1)
void CANUpdateTxCCPREQ (CAN_MSG *pMsg)
{   INT16U usTemp, usSum;
    usTemp  = sCANTxCcpReq.usCode;
    usSum   = usTemp;
    pMsg->DAT08.ucDat0 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = CAN_UC_HIGH (usTemp);
    usTemp  = sCANTxCcpReq.usWhich;
    usSum  += usTemp;
    pMsg->DAT08.ucDat2 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = CAN_UC_HIGH (usTemp);
    usTemp  = sCANTxCcpReq.usValue;
    usSum  += usTemp;
    pMsg->DAT08.ucDat4 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = CAN_UC_HIGH (usTemp);
    usTemp  = usSum;
    pMsg->DAT08.ucDat6 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = CAN_UC_HIGH (usTemp);
}
/* ************************* CANCcpParaRead () ************************ */
BOOL CANCcpParaRead (INT16U usWhich, INT16U *pResult)
{   static INT08U ucCANCcpReading = 0;
    OS_CPU_SR cpu_sr = 0;
    if (sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucEnable == CAN_DISABLE)
    {   return CAN_FALSE;
    }
    OS_ENTER_CRITICAL();
    if (ucCANCcpReading != 0)
    {   OS_EXIT_CRITICAL();
        return CAN_FALSE;
    }
    if (sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucState != CAN_CODE_FREE)
    {   OS_EXIT_CRITICAL();
        OSTimeDly(2);
        OS_ENTER_CRITICAL();
        if (sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucState != CAN_CODE_FREE)
        {   OS_EXIT_CRITICAL();
            return CAN_FALSE;
        }
    }
    ucCANCcpReading      = 1;
    sCANRxCcpPar.usCode  = 0;
    sCANRxCcpPar.usWhich = 0;
    sCANRxCcpPar.usValue = 0;
    sCANTxCcpReq.usCode  = CAN_CCP10_CODE_READ;
    sCANTxCcpReq.usWhich = usWhich;
    sCANTxCcpReq.usValue = 0;
    sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucState = CAN_CODE_IMMED;
    OS_EXIT_CRITICAL();
    OSTimeDly(1);
    if((sCANRxCcpPar.usCode == CAN_CCP10_CODE_PARA) && (sCANRxCcpPar.usWhich == usWhich))
    {   *pResult = sCANRxCcpPar.usValue;
        ucCANCcpReading = 0;
        return CAN_TRUE;
    }
    OSTimeDly(1);
    if((sCANRxCcpPar.usCode == CAN_CCP10_CODE_PARA) && (sCANRxCcpPar.usWhich == usWhich))
    {   *pResult = sCANRxCcpPar.usValue;
        ucCANCcpReading = 0;
        return CAN_TRUE;
    }
    OSTimeDly(1);
    if((sCANRxCcpPar.usCode == CAN_CCP10_CODE_PARA) && (sCANRxCcpPar.usWhich == usWhich))
    {   *pResult = sCANRxCcpPar.usValue;
        ucCANCcpReading = 0;
        return CAN_TRUE;
    }
    OSTimeDly(1);
    if((sCANRxCcpPar.usCode == CAN_CCP10_CODE_PARA) && (sCANRxCcpPar.usWhich == usWhich))
    {   *pResult = sCANRxCcpPar.usValue;
        ucCANCcpReading = 0;
        return CAN_TRUE;
    }
    OSTimeDly(1);
    if((sCANRxCcpPar.usCode == CAN_CCP10_CODE_PARA) && (sCANRxCcpPar.usWhich == usWhich))
    {   *pResult = sCANRxCcpPar.usValue;
        ucCANCcpReading = 0;
        return CAN_TRUE;
    }
    ucCANCcpReading = 0;
    return CAN_FALSE;
}

/* ************************* CANCcpParaWrite () *********************** */
BOOL CANCcpParaWrite (INT16U usWhich, INT16U usValue)
{   OS_CPU_SR cpu_sr = 0;
    if (sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucEnable == CAN_DISABLE)
    {   return CAN_FALSE;
    }
    OS_ENTER_CRITICAL();
    if (sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucState != CAN_CODE_FREE)
    {   OS_EXIT_CRITICAL();
        OSTimeDly(2);
        OS_ENTER_CRITICAL();
        if (sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucState != CAN_CODE_FREE)
        {   OS_EXIT_CRITICAL();
            return CAN_FALSE;
        }
    }
    sCANTxCcpReq.usCode  = CAN_CCP10_CODE_WRITE;
    sCANTxCcpReq.usWhich = usWhich;
    sCANTxCcpReq.usValue = usValue;
    sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucState = CAN_CODE_IMMED;
    OS_EXIT_CRITICAL();
    return CAN_TRUE;
}
/* ************************* CANCcpParaSave () ************************ */
BOOL CANCcpParaSave (INT16U usWhich)
{   OS_CPU_SR cpu_sr = 0;
    if (sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucEnable == CAN_DISABLE)
    {   return CAN_FALSE;
    }
    OS_ENTER_CRITICAL();
    if (sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucState != CAN_CODE_FREE)
    {   OS_EXIT_CRITICAL();
        OSTimeDly(2);
        OS_ENTER_CRITICAL();
        if (sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucState != CAN_CODE_FREE)
        {   OS_EXIT_CRITICAL();
            return CAN_FALSE;
        }
    }
    sCANTxCcpReq.usCode  = CAN_CCP10_CODE_SAVE;
    sCANTxCcpReq.usWhich = usWhich;
    sCANTxCcpReq.usValue = 0;
    sCANTxPgnTbl[CAN_TX_PGN_CCP10REQ].ucState = CAN_CODE_IMMED;
    OS_EXIT_CRITICAL();
    return CAN_TRUE;
}
#endif
#endif

/* ****************************** RX_CCPREQ *************************** */
#ifdef CAN_RX_PGN_CCP10REQ
#if   (CAN_CCP_CCP10_ON == 1)
void CANUpdateRxCCPREQ (CAN_MSG *pMsg)
{   INT16U usComd, usWhich;
    if (sCANTxPgnTbl[CAN_TX_PGN_CCP10PAR].ucEnable == CAN_DISABLE)
    {   return;
    }
    sCANRxCcpReq.usCode  = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat1);
    sCANRxCcpReq.usWhich = CAN_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    sCANRxCcpReq.usValue = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usWhich              = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    usComd   = sCANRxCcpReq.usCode + sCANRxCcpReq.usWhich + sCANRxCcpReq.usValue;
    if (usComd != usWhich)
    {   return;
    }
    usComd  = sCANRxCcpReq.usWhich & CAN_CCP10_IS_MASK;
    usWhich = sCANRxCcpReq.usWhich - usComd;
    if (sCANRxCcpReq.usCode == CAN_CCP10_CODE_READ)
    {   if (usComd == CAN_CCP10_IS_PARAM)
        {   if (usWhich < DB_PARAM_SIZE)
            {   sCANTxCcpPar.usCode  = CAN_CCP10_CODE_PARA;
                sCANTxCcpPar.usWhich = usWhich + usComd;
                sCANTxCcpPar.usValue = aDBParam[usWhich];
                sCANTxPgnTbl[CAN_TX_PGN_CCP10PAR].ucState = CAN_CODE_IMMED;
            }
        }
        else if (usComd == CAN_CCP10_IS_MEASU)
        {   if (usWhich < DB_MEASU_SIZE)
            {   sCANTxCcpPar.usCode  = CAN_CCP10_CODE_PARA;
                sCANTxCcpPar.usWhich = usWhich + usComd;
                sCANTxCcpPar.usValue = aDBMeasu[usWhich];
                sCANTxPgnTbl[CAN_TX_PGN_CCP10PAR].ucState = CAN_CODE_IMMED;
            }
        }
        else if (usComd == CAN_CCP10_IS_FUNCT)
        {   if (usWhich < DB_FUNCT_SIZE)
            {   sCANTxCcpPar.usCode  = CAN_CCP10_CODE_PARA;
                sCANTxCcpPar.usWhich = usWhich + usComd;
                sCANTxCcpPar.usValue = aDBFunct[usWhich];
                sCANTxPgnTbl[CAN_TX_PGN_CCP10PAR].ucState = CAN_CODE_IMMED;
            }
        }
        else if (usComd == CAN_CCP10_IS_CURVE)
        {   if (usWhich < DB_CURVE_SIZE)
            {   sCANTxCcpPar.usCode  = CAN_CCP10_CODE_PARA;
                sCANTxCcpPar.usWhich = usWhich + usComd;
                sCANTxCcpPar.usValue = aDBCurve[usWhich];
                sCANTxPgnTbl[CAN_TX_PGN_CCP10PAR].ucState = CAN_CODE_IMMED;
            }
        }
    }
    else if (sCANRxCcpReq.usCode == CAN_CCP10_CODE_WRITE)
    {   if (usComd == CAN_CCP10_IS_PARAM)
        {   if (usWhich < DB_PARAM_SIZE)
            {   aDBParam[usWhich] = sCANRxCcpReq.usValue;
            }
        }
        else if (usComd == CAN_CCP10_IS_MEASU)
        {   if (usWhich < DB_MEASU_SIZE)
            {   aDBMeasu[usWhich] = sCANRxCcpReq.usValue;
            }
        }
        else if (usComd == CAN_CCP10_IS_FUNCT)
        {   if (usWhich < DB_FUNCT_SIZE)
            {   aDBFunct[usWhich] = sCANRxCcpReq.usValue;
            }
        }
        else if (usComd == CAN_CCP10_IS_CURVE)
        {   if (usWhich < DB_CURVE_SIZE)
            {   aDBCurve[usWhich] = sCANRxCcpReq.usValue;
            }
        }
    }
    else if ((sCANRxCcpReq.usCode == CAN_CCP10_CODE_SAVE) && (usWhich == 0))
    {   if (usComd == CAN_CCP10_IS_PARAM)
        {   OSSpiPutComd(FW_SPI_SAVE_PARAM);
        }
        else if (usComd == CAN_CCP10_IS_MEASU)
        {   OSSpiPutComd(FW_SPI_SAVE_MEASU);
            OSSpiPutComd(FW_SPI_SAVE_HIST);
        }
        else if (usComd == CAN_CCP10_IS_FUNCT)
        {   OSSpiPutComd(FW_SPI_SAVE_FUNCT);
        }
        else if (usComd == CAN_CCP10_IS_CURVE)
        {   OSSpiPutComd(FW_SPI_SAVE_CURVE);
            OSSpiPutComd(FW_SPI_SAVE_STAT);
        }
    }
}
#endif
#endif

/* ******************************************************************** */
/*                          36: CAN_TX_PGN_CCP10PAR                     */
/* ******************************************************************** */
/* ****************************** TX_CCPPAR *************************** */
#ifdef CAN_TX_PGN_CCP10PAR
#if   (CAN_CCP_CCP10_ON == 1)
void CANUpdateTxCCPPAR (CAN_MSG *pMsg)
{   INT16U usTemp, usSum;
    usTemp  = sCANTxCcpPar.usCode;
    usSum   = usTemp;
    pMsg->DAT08.ucDat0 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat1 = CAN_UC_HIGH (usTemp);
    usTemp  = sCANTxCcpPar.usWhich;
    usSum  += usTemp;
    pMsg->DAT08.ucDat2 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat3 = CAN_UC_HIGH (usTemp);
    usTemp  = sCANTxCcpPar.usValue;
    usSum  += usTemp;
    pMsg->DAT08.ucDat4 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat5 = CAN_UC_HIGH (usTemp);
    usTemp  = usSum;
    pMsg->DAT08.ucDat6 = CAN_UC_LOW (usTemp);
    pMsg->DAT08.ucDat7 = CAN_UC_HIGH (usTemp);
}
#endif
#endif
/* ****************************** RX_CCPPAR *************************** */
#ifdef CAN_RX_PGN_CCP10PAR
#if   (CAN_CCP_CCP10_ON == 1)
void CANUpdateRxCCPPAR (CAN_MSG *pMsg)
{   INT16U usD0, usD1, usD2, usD3;
    usD0 = CAN_US_CREAT (pMsg->DAT08.ucDat0, pMsg->DAT08.ucDat1);
    usD1 = CAN_US_CREAT (pMsg->DAT08.ucDat2, pMsg->DAT08.ucDat3);
    usD2 = CAN_US_CREAT (pMsg->DAT08.ucDat4, pMsg->DAT08.ucDat5);
    usD3 = CAN_US_CREAT (pMsg->DAT08.ucDat6, pMsg->DAT08.ucDat7);
    if (usD3 == (usD0 + usD1 + usD2))
    {   sCANRxCcpPar.usCode  = usD0;
        sCANRxCcpPar.usWhich = usD1;
        sCANRxCcpPar.usValue = usD2;
    }
}
#endif
#endif
/* ******************************************************************** */
/*                          37: CAN_TX_PGN_ECULOCK                      */
/* ******************************************************************** */
/* ****************************** TX_ECULOCK ************************** */
#ifdef CAN_TX_PGN_ECULOCK
void CANUpdateTxEcuLock (CAN_MSG *pMsg)
{   pMsg->DAT08.ucDat0 = (INT08U)mSTEcuLockCode;
}
#endif

/* ****************************** RX_ECULOCK ************************** */
#ifdef CAN_RX_PGN_ECULOCK
void CANUpdateRxEcuLock (CAN_MSG *pMsg)
{   mSTEcuLockCode = (INT16U)(pMsg->DAT08.ucDat0);
}
#endif

/* ******************************************************************** */
/*                          38: CAN_TX_PGN_SLAVEERR                     */
/* ******************************************************************** */
/* ****************************** TX_SLAVEERR ************************* */
#ifdef CAN_TX_PGN_SLAVEERR
void CANUpdateTxSlaveErr (CAN_MSG *pMsg)
{   pMsg = pMsg;
}
#endif

/* ****************************** RX_SLAVEERR ************************* */
#ifdef CAN_RX_PGN_SLAVEERR
void CANUpdateRxSlaveErr (CAN_MSG *pMsg)
{   mTFRxSlaveError = (INT16U)(pMsg->DAT08.ucDat0 & 0x30);
}
#endif



/* ******************************************************************** */
/*                        GeneralJ1939RxMsg()                           */
/* ******************************************************************** */
INT8U GeneralJ1939RxMsg(CAN_MSG *pMsg) 
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
        //if (0) {;}
       #ifdef CAN_RX_PGN_EEC1
        if (i == CAN_RX_PGN_EEC1)
        {   CANUpdateRxEEC1 (pMsg); 
        }
       #endif
       
       #ifdef CAN_RX_PGN_EEC2
        else if (i == CAN_RX_PGN_EEC2)
        {   CANUpdateRxEEC2 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_EEC3
        else if (i == CAN_RX_PGN_EEC3)
        {   CANUpdateRxEEC3 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_AMCON
        else if (i == CAN_RX_PGN_AMCON)
        {   CANUpdateRxAMCON (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_VEHSPD
        else if (i == CAN_RX_PGN_VEHSPD)
        {   CANUpdateRxVEHSPD (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_CNFPBAM
        else if (i == CAN_RX_PGN_CNFPBAM)
        {   CANUpdateRxCNFPBAM (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_CNFPACK
        else if (i == CAN_RX_PGN_CNFPACK)
        {   CANUpdateRxCNFPACK (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_ENGTEMP
        else if (i == CAN_RX_PGN_ENGTEMP)
        {   CANUpdateRxENGTEMP (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_LFE
        else if (i == CAN_RX_PGN_LFE)
        {   CANUpdateRxLFE (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_EFL
        else if (i == CAN_RX_PGN_EFL)
        {   CANUpdateRxEFL (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_LFC
        else if (i == CAN_RX_PGN_LFC)
        {   CANUpdateRxLFC (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_DM1SINGLE
        else if (i == CAN_RX_PGN_DM1SINGLE)
        {   CANUpdateRxDM1 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_DM2SINGLE
        else if (i == CAN_RX_PGN_DM2SINGLE)
        {   CANUpdateRxDM2 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_DM4SINGLE
        else if (i == CAN_RX_PGN_DM4SINGLE)
        {   CANUpdateRxDM4 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_DM11ACK
        else if (i == CAN_RX_PGN_DM11ACK)
        {   CANUpdateRxDM11ACK (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_INCON
        else if (i == CAN_RX_PGN_INCON)
        {   CANUpdateRxINCON (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_VEHPOW
        else if (i == CAN_RX_PGN_VEHPOW)
        {   CANUpdateRxVEHPOW (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_ENGHOUR
        else if (i == CAN_RX_PGN_ENGHOUR)
        {   CANUpdateRxENGHOUR (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_CRPRESS
        else if (i == CAN_RX_PGN_CRPRESS)
        {   CANUpdateRxCRPRESS (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_EBC1
        else if (i == CAN_RX_PGN_EBC1)
        {   CANUpdateRxEBC1 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_EBC2
        else if (i == CAN_RX_PGN_EBC2)
        {   CANUpdateRxEBC2 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_ETC1
        else if (i == CAN_RX_PGN_ETC1)
        {   CANUpdateRxETC1 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_RXCCVS
        else if (i == CAN_RX_PGN_RXCCVS)
        {   CANUpdateRxRXCCVS (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_HRVD
        else if (i == CAN_RX_PGN_HRVD)
        {   CANUpdateRxHRVD (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_PGNRQ
        else if (i == CAN_RX_PGN_PGNRQ)
        {   CANUpdateRxPGNRQ (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_RXAMCON
        else if (i == CAN_RX_PGN_RXAMCON)
        {   CANUpdateRxRXAMCON (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_TCO1
        else if (i == CAN_RX_PGN_TCO1)
        {   CANUpdateRxTCO1 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_TSC1AE
        else if (i == CAN_RX_PGN_TSC1AE)
        {   CANUpdateRxTSC1AE (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_TSC1DE
        else if (i == CAN_RX_PGN_TSC1DE)
        {   CANUpdateRxTSC1DE (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_TSC1PE
        else if (i == CAN_RX_PGN_TSC1PE)
        {   CANUpdateRxTSC1PE (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_TSC1TE
        else if (i == CAN_RX_PGN_TSC1TE)
        {   CANUpdateRxTSC1TE (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_TSC1VE
        else if (i == CAN_RX_PGN_TSC1VE)
        {   CANUpdateRxTSC1VE (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_DM13
        else if (i == CAN_RX_PGN_DM13)
        {   CANUpdateRxDM13 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_DEC1
        else if (i == CAN_RX_PGN_DEC1)
        {   CANUpdateRxDEC1 (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_CCP10REQ
       #if   (CAN_CCP_CCP10_ON == 1)
        else if (i == CAN_RX_PGN_CCP10REQ)
        {   CANUpdateRxCCPREQ (pMsg);
        }
       #endif
       #endif
       #ifdef CAN_RX_PGN_CCP10PAR
       #if   (CAN_CCP_CCP10_ON == 1)
        else if (i == CAN_RX_PGN_CCP10PAR)
        {   CANUpdateRxCCPPAR (pMsg);
        }
       #endif
       #endif
       #ifdef CAN_RX_PGN_ECULOCK
        else if (i == CAN_RX_PGN_ECULOCK)
        {   CANUpdateRxEcuLock (pMsg);
        }
       #endif
       #ifdef CAN_RX_PGN_SLAVEERR
        else if (i == CAN_RX_PGN_SLAVEERR)
        {   CANUpdateRxSlaveErr (pMsg);
        }
       #endif
      
      return CAN_TRUE; 
    }
   return CAN_FALSE;
}


/* ******************************************************************** */
/*                        GeneralJ1939TxMsg ()                          */
/* ******************************************************************** */
INT08U GeneralJ1939TxMsg (CAN_MSG *pMsg)
{   INT08U  i;
    CAN_PGN_TCB *pTcb;
    for (i=0; i<CAN_TX_PGN_MAX; i++)
    {   pTcb = &sCANTxPgnTbl[i];
        if (pTcb->ucEnable == CAN_DISABLE)
        {   continue;
        }
        if (pTcb->ucState == CAN_CODE_IMMED)
        {   pTcb->ucState  = CAN_CODE_FREE;
        }
        else if (pTcb->ucState != CAN_CODE_CYCLIC)
        {   continue;
        }
        else if (CANCheckTime(pTcb->usTime,usCANTimer,pTcb->usPeriod) != CAN_FALSE)
        {   pTcb->usTime = usCANTimer;
        }
        else
        {   continue;
        }
        pMsg->DAT32.uiID   = pTcb->uiID;
        pMsg->DAT16.usDat0 = 0xFFFF;
        pMsg->DAT16.usDat1 = 0xFFFF;
        pMsg->DAT16.usDat2 = 0xFFFF;
        pMsg->DAT16.usDat3 = 0xFFFF;
      //  if (0) {;}
       #ifdef CAN_TX_PGN_EEC1
        else if (i == CAN_TX_PGN_EEC1)
        {   CANUpdateTxEEC1 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_EEC2
        else if (i == CAN_TX_PGN_EEC2)
        {   CANUpdateTxEEC2 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_EEC3
        else if (i == CAN_TX_PGN_EEC3)
        {   CANUpdateTxEEC3 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_AMCON
        else if (i == CAN_TX_PGN_AMCON)
        {   CANUpdateTxAMCON (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_VEHSPD
        else if (i == CAN_TX_PGN_VEHSPD)
        {   CANUpdateTxVEHSPD (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_CNFPBAM
        else if (i == CAN_TX_PGN_CNFPBAM)
        {   CANUpdateTxCNFPBAM (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_CNFPACK
        else if (i == CAN_TX_PGN_CNFPACK)
        {   CANUpdateTxCNFPACK (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_ENGTEMP
        else if (i == CAN_TX_PGN_ENGTEMP)
        {   CANUpdateTxENGTEMP (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_LFE
        else if (i == CAN_TX_PGN_LFE)
        {   CANUpdateTxLFE (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_EFL
        else if (i == CAN_TX_PGN_EFL)
        {   CANUpdateTxEFL (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_LFC
        else if (i == CAN_TX_PGN_LFC)
        {   CANUpdateTxLFC (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_DM1SINGLE
        else if (i == CAN_TX_PGN_DM1SINGLE)
        {   CANUpdateTxDM1 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_DM2SINGLE
        else if (i == CAN_TX_PGN_DM2SINGLE)
        {   CANUpdateTxDM2 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_DM4SINGLE
        else if (i == CAN_TX_PGN_DM4SINGLE)
        {   CANUpdateTxDM4 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_DM11ACK
        else if (i == CAN_TX_PGN_DM11ACK)
        {   CANUpdateTxDM11ACK (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_INCON
        else if (i == CAN_TX_PGN_INCON)
        {   CANUpdateTxINCON (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_VEHPOW
        else if (i == CAN_TX_PGN_VEHPOW)
        {   CANUpdateTxVEHPOW (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_ENGHOUR
        else if (i == CAN_TX_PGN_ENGHOUR)
        {   CANUpdateTxENGHOUR (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_CRPRESS
        else if (i == CAN_TX_PGN_CRPRESS)
        {   CANUpdateTxCRPRESS (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_EBC1
        else if (i == CAN_TX_PGN_EBC1)
        {   CANUpdateTxEBC1 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_EBC2
        else if (i == CAN_TX_PGN_EBC2)
        {   CANUpdateTxEBC2 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_ETC1
        else if (i == CAN_TX_PGN_ETC1)
        {   CANUpdateTxETC1 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_RXCCVS
        else if (i == CAN_TX_PGN_RXCCVS)
        {   CANUpdateTxRXCCVS (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_HRVD
        else if (i == CAN_TX_PGN_HRVD)
        {   CANUpdateTxHRVD (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_PGNRQ
        else if (i == CAN_TX_PGN_PGNRQ)
        {   CANUpdateTxPGNRQ (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_RXAMCON
        else if (i == CAN_TX_PGN_RXAMCON)
        {   CANUpdateTxRXAMCON (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_TCO1
        else if (i == CAN_TX_PGN_TCO1)
        {   CANUpdateTxTCO1 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_TSC1AE
        else if (i == CAN_TX_PGN_TSC1AE)
        {   CANUpdateTxTSC1AE (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_TSC1DE
        else if (i == CAN_TX_PGN_TSC1DE)
        {   CANUpdateTxTSC1DE (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_TSC1PE
        else if (i == CAN_TX_PGN_TSC1PE)
        {   CANUpdateTxTSC1PE (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_TSC1TE
        else if (i == CAN_TX_PGN_TSC1TE)
        {   CANUpdateTxTSC1TE (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_TSC1VE
        else if (i == CAN_TX_PGN_TSC1VE)
        {   CANUpdateTxTSC1VE (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_DM13
        else if (i == CAN_TX_PGN_DM13)
        {   CANUpdateTxDM13 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_DEC1
        else if (i == CAN_TX_PGN_DEC1)
        {   CANUpdateTxDEC1 (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_CCP10REQ
       #if   (CAN_CCP_CCP10_ON == 1)
        else if (i == CAN_TX_PGN_CCP10REQ)
        {   CANUpdateTxCCPREQ (pMsg);
        }
       #endif
       #endif
       #ifdef CAN_TX_PGN_CCP10PAR
       #if   (CAN_CCP_CCP10_ON == 1)
        else if (i == CAN_TX_PGN_CCP10PAR)
        {   CANUpdateTxCCPPAR (pMsg);
        }
       #endif
       #endif
       #ifdef CAN_TX_PGN_ECULOCK
        else if (i == CAN_TX_PGN_ECULOCK)
        {   CANUpdateTxEcuLock (pMsg);
        }
       #endif
       #ifdef CAN_TX_PGN_SLAVEERR
        else if (i == CAN_TX_PGN_SLAVEERR)
        {   CANUpdateTxSlaveErr (pMsg);
        }
       #endif
        //if (OSCanPutMsg(10,pMsg) != OS_NO_ERR)
        //{   return CAN_ERR_TIMEOUT;
        //}
    }
    return CAN_NO_ERR;
}


/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */






