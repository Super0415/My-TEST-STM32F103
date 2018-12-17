/* ******************************************************************** */
/*                  CAN2 Software for Elctronic Unit (V1.0)             */
/*                       Source File CAN2Cortex.c                       */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   CAN2_GLOBALS
#include "TYPCortex.h"

/* ******************************************************************** */
/*                              CAN2Init()                              */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Init (void)
{   usCAN2Timer = 0;
    usCAN2Status = 0;
    CAN2BufInit();
    SAEInit();
    CAN2HardInit();
}
#endif

/* ******************************************************************** */
/*                             CAN2Start()                              */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Start (void)
{   CAN2_TC_INT_DIS();
    CAN2_RX_INT_EN();
}
#endif

/* ******************************************************************** */
/*                            CAN2TaskLoop()                            */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2TaskLoop (void)
{   while (1)
    {   OSTimeDly(OS_TICKS_PER_SEC / CAN2_TASK_FRQ);
        /* ********************** CAN2 RX Message ********************* */
        while (CAN2IsRxBufEmpty() == CAN2_FALSE)
        {   (void)CAN2GetMsgFmRxBuf(0, &sCAN2TaskRxMsg);
            (void)SAEProcessRxMsg(&sCAN2TaskRxMsg);
        }
        /* ********************** CAN2 RX Message ********************* */
        if (SAECheckRxAllTimeOut() == SAE_FALSE)
        {   SAE_STS_CLR_BIT(SAE_STS_RX_ERR);
        }   else
        {   SAE_STS_SET_BIT(SAE_STS_RX_ERR);
        }
        /* ********************** CAN2 TX Message ********************* */
        if (SAEProcessTxMsg(&sCAN2TaskTxMsg) == SAE_NO_ERR)
        {   SAE_STS_CLR_BIT(SAE_STS_TX_ERR);
        }   else
        {   SAE_STS_SET_BIT(SAE_STS_TX_ERR);
        }
    }
}
#endif

/* ******************************************************************** */
/*                             CAN2TxIntHook()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2TxIntHook (void)
{   CAN2_TC_INT_DIS();
    if (CAN2GetTxMsgFmBuf(&sCAN2IntrTxMsg) == CAN2_NO_ERR)
    {   CAN2->sTxMailBox[0].TIR &= CAN_TI0R_TXRQ;
        CAN2->sTxMailBox[0].TIR |= sCAN2IntrTxMsg.DAT32.uiID;
        CAN2->sTxMailBox[0].TDTR = 8;
        CAN2->sTxMailBox[0].TDLR = sCAN2IntrTxMsg.DAT32.uiDat0;
        CAN2->sTxMailBox[0].TDHR = sCAN2IntrTxMsg.DAT32.uiDat1;
        CAN2->sTxMailBox[0].TIR |= CAN_TI0R_TXRQ;
        if (CAN2GetTxMsgFmBuf(&sCAN2IntrTxMsg) == CAN2_NO_ERR)
        {   CAN2->sTxMailBox[1].TIR &= CAN_TI1R_TXRQ;
            CAN2->sTxMailBox[1].TIR |= sCAN2IntrTxMsg.DAT32.uiID;
            CAN2->sTxMailBox[1].TDTR = 8;
            CAN2->sTxMailBox[1].TDLR = sCAN2IntrTxMsg.DAT32.uiDat0;
            CAN2->sTxMailBox[1].TDHR = sCAN2IntrTxMsg.DAT32.uiDat1;
            CAN2->sTxMailBox[1].TIR |= CAN_TI1R_TXRQ;
            if (CAN2GetTxMsgFmBuf(&sCAN2IntrTxMsg) == CAN2_NO_ERR)
            {   CAN2->sTxMailBox[2].TIR &= CAN_TI2R_TXRQ;
                CAN2->sTxMailBox[2].TIR |= sCAN2IntrTxMsg.DAT32.uiID;
                CAN2->sTxMailBox[2].TDTR = 8;
                CAN2->sTxMailBox[2].TDLR = sCAN2IntrTxMsg.DAT32.uiDat0;
                CAN2->sTxMailBox[2].TDHR = sCAN2IntrTxMsg.DAT32.uiDat1;
                CAN2->sTxMailBox[2].TIR |= CAN_TI2R_TXRQ;
            }
        }
        CAN2_TC_INT_EN();
    }
}
#endif

/* ******************************************************************** */
/*                             CAN2Rx0IntHook()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Rx0IntHook (void)
{   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[0].RIR & CAN2_CPU_ID_MSK;
    sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[0].RDLR;
    sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[0].RDHR;
    CAN2->RF0R                 |= CAN_RF0R_RFOM0;
    (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
    if ((CAN2->RF0R & CAN_RF0R_FMP0) != 0)
    {   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[0].RIR & CAN2_CPU_ID_MSK;
        sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[0].RDLR;
        sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[0].RDHR;
        CAN2->RF0R                 |= CAN_RF0R_RFOM0;
        (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
        if ((CAN2->RF0R & CAN_RF0R_FMP0) != 0)
        {   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[0].RIR & CAN2_CPU_ID_MSK;
            sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[0].RDLR;
            sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[0].RDHR;
            CAN2->RF0R                 |= CAN_RF0R_RFOM0;
            (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
        }
    }
}
#endif

/* ******************************************************************** */
/*                             CAN2Rx1IntHook()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2Rx1IntHook (void)
{   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[1].RIR & CAN2_CPU_ID_MSK;
    sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[1].RDLR;
    sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[1].RDHR;
    CAN2->RF1R                 |= CAN_RF1R_RFOM1;
    (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
    if ((CAN2->RF1R & CAN_RF1R_FMP1) != 0)
    {   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[1].RIR & CAN2_CPU_ID_MSK;
        sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[1].RDLR;
        sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[1].RDHR;
        CAN2->RF1R                 |= CAN_RF1R_RFOM1;
        (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
        if ((CAN2->RF1R & CAN_RF1R_FMP1) != 0)
        {   sCAN2IntrRxMsg.DAT32.uiID   = CAN2->sFIFOMailBox[1].RIR & CAN2_CPU_ID_MSK;
            sCAN2IntrRxMsg.DAT32.uiDat0 = CAN2->sFIFOMailBox[1].RDLR;
            sCAN2IntrRxMsg.DAT32.uiDat1 = CAN2->sFIFOMailBox[1].RDHR;
            CAN2->RF1R                 |= CAN_RF1R_RFOM1;
            (void)CAN2PutRxMsgToBuf(&sCAN2IntrRxMsg);
        }
    }
}
#endif

/* ******************************************************************** */
/*                            CAN2SceIntHook()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2SceIntHook (void)
{   INT32U uiTemp;
    uiTemp = CAN2->ESR;
    if ((uiTemp & CAN_ESR_BOFF) != 0)
    {   CAN2_STS_SET_BIT(CAN2_STS_BUS_OFF);
    }   else
    {   CAN2_STS_CLR_BIT(CAN2_STS_BUS_OFF);
    }
    if ((uiTemp & CAN_ESR_EWGF) != 0)
    {   CAN2_STS_SET_BIT(CAN2_STS_WARNING);
    }   else
    {   CAN2_STS_CLR_BIT(CAN2_STS_WARNING);
    }
    if ((uiTemp & CAN_ESR_EPVF) != 0)
    {   CAN2_STS_SET_BIT(CAN2_STS_OVERRUN);
    }   else
    {   CAN2_STS_CLR_BIT(CAN2_STS_OVERRUN);
    }
}
#endif

/* ******************************************************************** */
/*                             CAN2BufInit()                            */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2BufInit (void)
{   CAN2_RING *pbuf;
    pbuf = &sCAN2RingBuf;
    pbuf->usRingBufRxCtr   =  0;
    pbuf->pRingBufRxInPtr  = &pbuf->sRingBufRx[0];
    pbuf->pRingBufRxOutPtr = &pbuf->sRingBufRx[0];
    pbuf->pRingBufRxSem    =  OSSemCreate(0);
    pbuf->usRingBufTxCtr   =  0;
    pbuf->pRingBufTxInPtr  = &pbuf->sRingBufTx[0];
    pbuf->pRingBufTxOutPtr = &pbuf->sRingBufTx[0];
    pbuf->pRingBufTxSem    =  OSSemCreate(CAN2_TX_BUF_SIZE);
}
#endif

/* ******************************************************************** */
/*                            CAN2IsTxBufFull()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2IsTxBufFull (void)
{   OS_CPU_SR cpu_sr = 0;
    CAN2_RING *pbuf;
    pbuf = &sCAN2RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufTxCtr >= CAN2_TX_BUF_SIZE)
    {   OS_EXIT_CRITICAL();
        return CAN2_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return CAN2_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                           CAN2IsRxBufEmpty()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2IsRxBufEmpty (void)
{   OS_CPU_SR cpu_sr = 0;
    CAN2_RING *pbuf;
    pbuf = &sCAN2RingBuf;
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return CAN2_TRUE;
    }   else
    {   OS_EXIT_CRITICAL();
        return CAN2_FALSE;
    }
}
#endif

/* ******************************************************************** */
/*                           CAN2PutRxMsgToBuf()                        */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2PutRxMsgToBuf (CAN_MSG *msg)
{   CAN2_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
    pbuf = &sCAN2RingBuf;
    if (pbuf->usRingBufRxCtr < CAN2_RX_BUF_SIZE)
    {   pbuf->usRingBufRxCtr++;
        pmsg = msg;
        ptmp = pbuf->pRingBufRxInPtr;
        ptmp->DAT32.uiID   = pmsg->DAT32.uiID;
        ptmp->DAT32.uiDat0 = pmsg->DAT32.uiDat0;
        ptmp->DAT32.uiDat1 = pmsg->DAT32.uiDat1;
        pbuf->pRingBufRxInPtr++;
        if (pbuf->pRingBufRxInPtr == &pbuf->sRingBufRx[CAN2_RX_BUF_SIZE])
        {   pbuf->pRingBufRxInPtr  = &pbuf->sRingBufRx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufRxSem);
    }
}
#endif

/* ******************************************************************** */
/*                          CAN2GetTxMsgFmBuf()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2GetTxMsgFmBuf (CAN_MSG *msg)
{   CAN2_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
    pbuf = &sCAN2RingBuf;
    if (pbuf->usRingBufTxCtr > 0)
    {   pbuf->usRingBufTxCtr--;
        pmsg = msg;
        ptmp = pbuf->pRingBufTxOutPtr;
        pmsg->DAT32.uiID   = ptmp->DAT32.uiID;
        pmsg->DAT32.uiDat0 = ptmp->DAT32.uiDat0;
        pmsg->DAT32.uiDat1 = ptmp->DAT32.uiDat1;
        pbuf->pRingBufTxOutPtr++;
        if (pbuf->pRingBufTxOutPtr == &pbuf->sRingBufTx[CAN2_TX_BUF_SIZE])
        {   pbuf->pRingBufTxOutPtr  = &pbuf->sRingBufTx[0];
        }
        (void)OSIntSemPost(pbuf->pRingBufTxSem);
        return CAN2_NO_ERR;
    }   else
    {   return CAN2_ERR_TX_EMPTY;
    }
}
#endif

/* ******************************************************************** */
/*                          CAN2GetMsgFmRxBuf()                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2GetMsgFmRxBuf (INT16U to, CAN_MSG *msg)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    CAN2_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
    pbuf = &sCAN2RingBuf;
    OSSemPend(pbuf->pRingBufRxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return CAN2_ERR_RX_TIMEOUT;
    }
    OS_ENTER_CRITICAL();
    if (pbuf->usRingBufRxCtr == 0)
    {   OS_EXIT_CRITICAL();
        return CAN2_ERR_RX_TIMEOUT;
    }
    pmsg = msg;
    pbuf->usRingBufRxCtr--;
    ptmp = pbuf->pRingBufRxOutPtr;
    pmsg->DAT32.uiID   = ptmp->DAT32.uiID;
    pmsg->DAT32.uiDat0 = ptmp->DAT32.uiDat0;
    pmsg->DAT32.uiDat1 = ptmp->DAT32.uiDat1;
    pbuf->pRingBufRxOutPtr++;
    if (pbuf->pRingBufRxOutPtr == &pbuf->sRingBufRx[CAN2_RX_BUF_SIZE])
    {   pbuf->pRingBufRxOutPtr  = &pbuf->sRingBufRx[0];
    }
    OS_EXIT_CRITICAL();
    return CAN2_NO_ERR;
}
#endif

/* ******************************************************************** */
/*                         CAN2PutMsgToTxBuf()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
INT08U CAN2PutMsgToTxBuf (INT16U to, CAN_MSG *msg)
{   OS_CPU_SR cpu_sr = 0;
    INT08U oserr;
    CAN2_RING *pbuf;
    CAN_MSG *pmsg, *ptmp;
    pbuf = &sCAN2RingBuf;
    OSSemPend(pbuf->pRingBufTxSem, to, &oserr);
    if (oserr != OS_NO_ERR)
    {   return CAN2_ERR_TX_TIMEOUT;
    }   else
    {   pmsg = msg;
        OS_ENTER_CRITICAL();
        pbuf->usRingBufTxCtr++;
        ptmp = pbuf->pRingBufTxInPtr;
        ptmp->DAT32.uiID   = pmsg->DAT32.uiID;
        ptmp->DAT32.uiDat0 = pmsg->DAT32.uiDat0;
        ptmp->DAT32.uiDat1 = pmsg->DAT32.uiDat1;
        pbuf->pRingBufTxInPtr++;
        if (pbuf->pRingBufTxInPtr == &pbuf->sRingBufTx[CAN2_TX_BUF_SIZE])
        {   pbuf->pRingBufTxInPtr  = &pbuf->sRingBufTx[0];
        }
        if (pbuf->usRingBufTxCtr  == 1)
        {   CAN2_TC_INT_EN();
        }
        OS_EXIT_CRITICAL();
        return CAN2_NO_ERR;
    }
}
#endif

/* ******************************************************************** */
/*                              CAN2HardInit()                          */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)
void CAN2HardInit (void)
{
#ifdef CAN2_ENABLE               //@@@@@@@@@²»Ê¹ÓÃCAN2
  RCC->APB1ENR  |=  RCC_APB1ENR_CAN2EN;
    RCC->APB1RSTR |=  RCC_APB1RSTR_CAN2RST;
    RCC->APB1RSTR &= ~RCC_APB1RSTR_CAN2RST;
    RCC->APB2ENR  |=  RCC_APB2ENR_IOPBEN;
    XIOConfigREMAP(CAN2_AFIO_REMAP1, CAN2_AFIO_REMAP2);
    XIOConfigGPIO(GPIOB, XIO_PT_BT5, XIO_PT_GPI_PULL,   XIO_PT_SET_1);
    XIOConfigGPIO(GPIOB, XIO_PT_BT6, XIO_PT_ALT_PP_50M, XIO_PT_SET_0);
    CAN2->MCR &= ~CAN_MCR_SLEEP;            /* Exit from sleep mode     */
    CAN2->MCR |=  CAN_MCR_INRQ;             /* Request initialisation   */
    while((CAN2->MSR & CAN_MSR_INAK) == 0); /* Wait the acknowledge     */
    CAN2->MCR &= ~CAN_MCR_TTCM              /* 0: Time Trigger mode dis */
              &  ~CAN_MCR_ABOM              /* 0: No bus-off management */
              &  ~CAN_MCR_AWUM              /* 0: No Automatic wakeup   */
              &  ~CAN_MCR_NART              /* automatic retransmission */
              &  ~CAN_MCR_RFLM;             /* 0: Receive FIFO not lock */
    CAN2->MCR |=  CAN_MCR_TXFP;             /* 1: Priority by the order */
   #if (CAN2_BAUD_RATE_KHZ == 250)
    CAN2->BTR  = ((INT32U)0 << 30)          /* 0: Normal operation mode */
              +  ((INT32U)1 << 24)          /* 1: Resynch jump width= 2 */
              +  ((INT32U)5 << 20)          /* 5: Time segment 2 = 6tq  */
              +  ((INT32U)8 << 16)          /* 8: Time segment 1 = 9tq  */
              +  ((INT32U)18 - 1);          /* Prescaler=18: Tq = 1/4us */
   #elif (CAN2_BAUD_RATE_KHZ == 500)
    CAN2->BTR  = ((INT32U)0 << 30)          /* 0: Normal operation mode */
              +  ((INT32U)1 << 24)          /* 1: Resynch jump width= 2 */
              +  ((INT32U)5 << 20)          /* 5: Time segment 2 = 6tq  */
              +  ((INT32U)8 << 16)          /* 8: Time segment 1 = 9tq  */
              +  ((INT32U)9 - 1);           /* Prescaler=9:  Tq = 1/8us */
   #elif (CAN2_BAUD_RATE_KHZ == 1000)
    CAN2->BTR  = ((INT32U)0 << 30)          /* 0: Normal operation mode */
              +  ((INT32U)0 << 24)          /* 0: Resynch jump width= 1 */
              +  ((INT32U)2 << 20)          /* 2: Time segment 2 = 3tq  */
              +  ((INT32U)3 << 16)          /* 3: Time segment 1 = 4tq  */
              +  ((INT32U)9 - 1);           /* Prescaler=9:  Tq = 1/8us */
   #endif
    CAN2->MCR &= ~CAN_MCR_INRQ;             /* Request leave initialie  */
    while((CAN2->MSR & CAN_MSR_INAK) != 0); /* Wait the acknowledge     */
    CAN2->FMR |=  CAN_FMR_FINIT;            /* 1: Initialization mode   */
    CAN2->FA1R =  0x00000000;               /* All Filters not active   */
    CAN2->FMR &= ~CAN_FMR_FINIT;            /* 0: Active filters mode   */
#endif
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */