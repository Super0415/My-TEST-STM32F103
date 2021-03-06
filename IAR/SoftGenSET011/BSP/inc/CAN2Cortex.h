/* ******************************************************************** */
/*                CAN2 Software for Elctronic Unit (V1.0)               */
/*                       Header File CAN2Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _CAN2CORTEX_H

#define _CAN2CORTEX_H

#ifdef   CAN2_GLOBALS

#define  CAN2_EXT  

#else

#define  CAN2_EXT extern

#endif

/* ******************************************************************** */
/*  CAN2_VERSION  = 10xx: VEC1000 Application                           */
/*  CAN2_VERSION  = 40xx: VEC4000 Application                           */
/*  CAN2_VERSION  = 68xx: VEC6800 Application                           */
/*  CAN2_VERSION  = 69xx: VEC6900 Application                           */
/*  CAN2_VERSION  = 760x: GEC7600-Main Application                      */
/*  CAN2_VERSION  = 761x: GEC7600-Display Application                   */
/*  CAN2_VERSION  = 780x: GEC7800-Main Application                      */
/*  CAN2_VERSION  = 781x: GEC7800-Display Application                   */
/*  CAN2_VERSION  = 80xx: VEC8000 Application                           */
/*  CAN2_VERSION  = 90xx: VEC9000 Application                           */
/*  CAN2_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define CAN2_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define CAN2_1000_COMMON_ON       0
#define CAN2_4000_COMMON_ON       0
#define CAN2_6800_COMMON_ON       0
#define CAN2_6900_COMMON_ON       0
#define CAN2_7600_COMMON_ON       0
#define CAN2_7600_MAIN_CHIP_ON    0
#define CAN2_7600_AUX_CHIP_ON     0
#define CAN2_7800_COMMON_ON       0
#define CAN2_7800_MAIN_CHIP_ON    0
#define CAN2_7800_AUX_CHIP_ON     0
#define CAN2_8000_COMMON_ON       0
#define CAN2_9000_COMMON_ON       0
#define CAN2_9600_COMMON_ON       0
#if   ((CAN2_VERSION / 100)   == 10)
#undef  CAN2_1000_COMMON_ON
#define CAN2_1000_COMMON_ON       1
#endif
#if   ((CAN2_VERSION / 100)   == 40)
#undef  CAN2_4000_COMMON_ON
#define CAN2_4000_COMMON_ON       1
#endif
#if   ((CAN2_VERSION / 100)   == 68)
#undef  CAN2_6800_COMMON_ON
#define CAN2_6800_COMMON_ON       1
#endif
#if   ((CAN2_VERSION / 100)   == 69)
#undef  CAN2_6900_COMMON_ON
#define CAN2_6900_COMMON_ON       1
#endif
#if   ((CAN2_VERSION / 100)   == 76)
#undef  CAN2_7600_COMMON_ON
#define CAN2_7600_COMMON_ON       1
#endif
#if   ((CAN2_VERSION / 10)   == 760)
#undef  CAN2_7600_MAIN_CHIP_ON
#define CAN2_7600_MAIN_CHIP_ON    1
#endif
#if   ((CAN2_VERSION / 10)   == 761)
#undef  CAN2_7600_AUX_CHIP_ON
#define CAN2_7600_AUX_CHIP_ON     1
#endif
#if   ((CAN2_VERSION / 100)   == 78)
#undef  CAN2_7800_COMMON_ON
#define CAN2_7800_COMMON_ON       1
#endif
#if   ((CAN2_VERSION / 10)   == 780)
#undef  CAN2_7800_MAIN_CHIP_ON
#define CAN2_7800_MAIN_CHIP_ON    1
#endif
#if   ((CAN2_VERSION / 10)   == 781)
#undef  CAN2_7800_AUX_CHIP_ON
#define CAN2_7800_AUX_CHIP_ON     1
#endif
#if   ((CAN2_VERSION / 100)   == 80)
#undef  CAN2_8000_COMMON_ON
#define CAN2_8000_COMMON_ON       1
#endif
#if   ((CAN2_VERSION / 100)   == 90)
#undef  CAN2_9000_COMMON_ON
#define CAN2_9000_COMMON_ON       1
#endif
#if   ((CAN2_VERSION / 100)   == 96)
#undef  CAN2_9600_COMMON_ON
#define CAN2_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define CAN2_FUNCTION_ON          0
#define CAN2_CPU_9S12_ON          0
#define CAN2_CPU_POWERPC_ON       0
#define CAN2_CPU_STM32F1_ON       0
#define CAN2_CPU_STM32F103_ON     0
#define CAN2_CPU_STM32F105_ON     0
#if    (CAN2_1000_COMMON_ON    == 1)
#undef  CAN2_CPU_9S12_ON
#define CAN2_CPU_9S12_ON          1
#endif
#if    (CAN2_4000_COMMON_ON    == 1)
#undef  CAN2_CPU_9S12_ON
#define CAN2_CPU_9S12_ON          1
#endif
#if    (CAN2_6800_COMMON_ON    == 1)
#undef  CAN2_CPU_9S12_ON
#define CAN2_CPU_9S12_ON          1
#endif
#if    (CAN2_6900_COMMON_ON    == 1)
#undef  CAN2_CPU_POWERPC_ON
#define CAN2_CPU_POWERPC_ON       1
#endif
#if    (CAN2_7600_COMMON_ON    == 1)
#undef  CAN2_CPU_STM32F1_ON
#define CAN2_CPU_STM32F1_ON       1
#endif
#if    (CAN2_7600_MAIN_CHIP_ON == 1)
#undef  CAN2_CPU_STM32F105_ON
#define CAN2_CPU_STM32F105_ON     1
#undef  CAN2_FUNCTION_ON
#define CAN2_FUNCTION_ON          1
#endif
#if    (CAN2_7600_AUX_CHIP_ON  == 1)
#undef  CAN2_CPU_STM32F103_ON
#define CAN2_CPU_STM32F103_ON     1
#endif
#if    (CAN2_7800_COMMON_ON    == 1)
#undef  CAN2_CPU_STM32F1_ON
#define CAN2_CPU_STM32F1_ON       1
#endif
#if    (CAN2_7800_MAIN_CHIP_ON == 1)
#undef  CAN2_CPU_STM32F105_ON
#define CAN2_CPU_STM32F105_ON     1
#undef  CAN2_FUNCTION_ON
#define CAN2_FUNCTION_ON          1
#endif
#if    (CAN2_7800_AUX_CHIP_ON  == 1)
#undef  CAN2_CPU_STM32F103_ON
#define CAN2_CPU_STM32F103_ON     1
#endif
#if    (CAN2_8000_COMMON_ON    == 1)
#undef  CAN2_CPU_POWERPC_ON
#define CAN2_CPU_POWERPC_ON       1
#endif
#if    (CAN2_9000_COMMON_ON    == 1)
#undef  CAN2_CPU_POWERPC_ON
#define CAN2_CPU_POWERPC_ON       1
#endif
#if    (CAN2_9600_COMMON_ON    == 1)
#undef  CAN2_CPU_POWERPC_ON
#define CAN2_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define CAN2_TRUE              (INT08U)1
#define CAN2_FALSE             (INT08U)0
#define CAN2_NO_ERR            (INT08U)0
#define CAN2_ERR_RX_FULL       (INT08U)1
#define CAN2_ERR_RX_EMPTY      (INT08U)2
#define CAN2_ERR_TX_FULL       (INT08U)3
#define CAN2_ERR_TX_EMPTY      (INT08U)4
#define CAN2_ERR_RX_TIMEOUT    (INT08U)5
#define CAN2_ERR_TX_TIMEOUT    (INT08U)6
#define CAN2_STS_NORMAL        (INT32U)0x00000000
#define CAN2_STS_RESET         (INT32U)0x00000001
#define CAN2_STS_WARNING       (INT32U)0x00000002
#define CAN2_STS_BUS_OFF       (INT32U)0x00000004
#define CAN2_STS_SLEEPING      (INT32U)0x00000008
#define CAN2_STS_OVERRUN       (INT32U)0x00000010
#define CAN2_STS_TX_ERR        (INT32U)0x00000020
#define CAN2_STS_RX_ERR        (INT32U)0x00000040
#define CAN2_STS_TO_START      (INT32U)0x00000100
#define CAN2_STS_TO_STOP       (INT32U)0x00000200
#define CAN2_STS_GET_BIT(m)    (uiCAN2Status & (m))
#define CAN2_STS_CLR_BIT(m)     uiCAN2Status &= ~(m)
#define CAN2_STS_SET_BIT(m)     uiCAN2Status |= (m)
#define CAN2_BAUDRATE_KHZ       250
#define CAN2_RX_BUF_SIZE        16
#define CAN2_TX_BUF_SIZE        2
#define CAN2_TASK_FRQ           200

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define CAN2_LS_ID831          (INT32U)0x00ABCD00
#define CAN2_LS_GET_ID32(a)  (((INT32U)(a)&0x00FF)|CAN2_LS_ID831)
#define CAN2_LS_TBL_SIZE        40
#define CAN2_LS_TX_FRQ          25
#define CAN2_LS_TX_TICKS       (OS_TICKS_PER_SEC/CAN2_LS_TX_FRQ)
#define CAN2_LS_RX_TO_TICKS    (CAN2_LS_TX_TICKS * 5)
#define CAN2_LS_MSK_ERROR      (INT16U)0x0001
#define CAN2_LS_MSK_STOP_CMD   (INT16U)0x0002
#define CAN2_LS_MSK_MODE       (INT16U)0x0004
#define CAN2_LS_MSK_MANUAL     (INT16U)0x0008
#define CAN2_LS_MSK_READY      (INT16U)0x0010
#define CAN2_LS_MSK_STARTING   (INT16U)0x0020
#define CAN2_LS_MSK_WORKING    (INT16U)0x0040
#define CAN2_LS_MSK_STOPPING   (INT16U)0x0080
#define CAN2_LS_ERR_MASK       ( CAN2_LS_MSK_ERROR \
                               | CAN2_LS_MSK_STOP_CMD \
                               | CAN2_LS_MSK_MODE \
                               | CAN2_LS_MSK_MANUAL )
#define CAN2_LS_ENG_MASK       ( CAN2_LS_MSK_ERROR \
                               | CAN2_LS_MSK_STOP_CMD \
                               | CAN2_LS_MSK_MODE \
                               | CAN2_LS_MSK_MANUAL \
                               | CAN2_LS_MSK_READY \
                               | CAN2_LS_MSK_STARTING \
                               | CAN2_LS_MSK_WORKING \
                               | CAN2_LS_MSK_STOPPING )
#define CAN2_LS_ENG_READY      (CAN2_LS_MSK_READY)
#define CAN2_LS_ENG_STARTING   (CAN2_LS_MSK_STARTING)
#define CAN2_LS_ENG_WORKING    (CAN2_LS_MSK_WORKING)
#define CAN2_LS_ENG_STOPPING   (CAN2_LS_MSK_STOPPING)
#define CAN2_LS_ENG_STS(x)     ((x)&CAN2_LS_ENG_MASK)

/* ******************************************************************** */
/*                  F105 CAN2 RX And TX Pin Definition                  */
/*               (Default: PB12 & PB13, Remap: PB5 & PB6)               */
/* ******************************************************************** */
#define CAN2_AFIO_REMAP1        AFIO_MAPR_CAN2_REMAP
#define CAN2_AFIO_REMAP2        0
#define CAN2_GPO_PT_CANTX       PB6
#define CAN2_GPI_PT_CANRX       PB5
#define CAN2_TX_PT              GPIOB
#define CAN2_TX_BT              6
#define CAN2_RX_PT              GPIOB
#define CAN2_RX_BT              5

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#if    (CAN2_CPU_9S12_ON == 1)
#define CAN2_RX_INT_EN()        CAN1RIER |= 0x01
#define CAN2_RX_INT_DIS()       CAN1RIER &= 0xFE
#define CAN2_TX0_INT_EN()       CAN1TIER |= 0x01
#define CAN2_TX1_INT_EN()       CAN1TIER |= 0x02
#define CAN2_TX2_INT_EN()       CAN1TIER |= 0x04
#define CAN2_TXALL_INT_EN()     CAN1TIER  = 0x07
#define CAN2_TX0_INT_DIS()      CAN1TIER &= 0xFE
#define CAN2_TX1_INT_DIS()      CAN1TIER &= 0xFD
#define CAN2_TX2_INT_DIS()      CAN1TIER &= 0xFB
#define CAN2_TXALL_INT_DIS()    CAN1TIER  = 0x00
#endif
#if    (CAN2_CPU_POWERPC_ON == 1)
#define CAN2_CANA_RX_BUF        0
#define CAN2_CANA_TX_BUF        1
#define CAN2_RX_INT_EN()        CAN_B.IMRL.R |=  (1 << CAN2_CANA_RX_BUF)
#define CAN2_RX_INT_DIS()       CAN_B.IMRL.R &= ~(1 << CAN2_CANA_RX_BUF)
#define CAN2_TX_INT_EN()        CAN_B.IMRL.R |=  (1 << CAN2_CANA_TX_BUF)
#define CAN2_TX_INT_DIS()       CAN_B.IMRL.R &= ~(1 << CAN2_CANA_TX_BUF)
#define CAN2_CLR_RX_FLAG()      CAN_B.IFRL.R  =  (1 << CAN2_CANA_RX_BUF)
#define CAN2_CLR_TX_FLAG()      CAN_B.IFRL.R  =  (1 << CAN2_CANA_TX_BUF)
#define CAN2_GET_RX_FLAG()     (CAN_B.IFRL.R  &  (1 << CAN2_CANA_RX_BUF))
#define CAN2_GET_TX_FLAG()     (CAN_B.IFRL.R  &  (1 << CAN2_CANA_TX_BUF))
#define CAN2_BOFF_INT_EN()      CAN_B.CR.B.BOFFMSK  = 1
#define CAN2_BOFF_INT_DIS()     CAN_B.CR.B.BOFFMSK  = 0
#define CAN2_CLR_BOFF_FLAG()    CAN_B.ESR.B.BOFFINT = 1
#define CAN2_ERR_INT_EN()       CAN_B.CR.B.ERRMSK   = 1
#define CAN2_ERR_INT_DIS()      CAN_B.CR.B.ERRMSK   = 0
#define CAN2_CLR_ERR_FLAG()     CAN_B.ESR.B.ERRINT  = 1
#define CAN2_CPU_TO_ID32(x)    ((x)&(INT32U)0x1FFFFFFF)
#define CAN2_ID32_TO_CPU(x)    ((x)&(INT32U)0x1FFFFFFF)
#define CAN2_CPU_TO_ID831(x)   ((x)&(INT32U)0x1FFFFF00)
#define CAN2_CPU_TO_ID07(x)    ((x)&(INT32U)0x000000FF)
#endif
#if    (CAN2_CPU_STM32F1_ON == 1)
#define CAN2_TC_INT_EN()        CAN2->IER |=   CAN_IER_TMEIE
#define CAN2_TC_INT_DIS()       CAN2->IER &=  ~CAN_IER_TMEIE
#define CAN2_RX_INT_EN()        CAN2->IER |=  (CAN_IER_FMPIE0 | CAN_IER_FMPIE1)
#define CAN2_RX_INT_DIS()       CAN2->IER &= ~(CAN_IER_FMPIE0 | CAN_IER_FMPIE1)
#define CAN2_CPU_ID_MSK        (INT32U)0xFFFFFFFC
#define CAN2_CPU_TO_ID32(x)    ((x)>>3)
#define CAN2_ID32_TO_CPU(x)    (((x)<<3)|(INT32U)0x04)
#define CAN2_CPU_TO_ID831(x)   (((x)>>3)&(INT32U)0xFFFFFF00)
#define CAN2_CPU_TO_ID07(x)    (((x)>>3)&(INT32U)0x000000FF)
#endif

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U     usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    CAN_MSG    *pRingBufRxInPtr;
    CAN_MSG    *pRingBufRxOutPtr;
    CAN_MSG    sRingBufRx[CAN2_RX_BUF_SIZE];
    INT16U     usRingBufTxCtr;
    OS_EVENT   *pRingBufTxSem;
    CAN_MSG    *pRingBufTxInPtr;
    CAN_MSG    *pRingBufTxOutPtr;
    CAN_MSG    sRingBufTx[CAN2_TX_BUF_SIZE];
}   CAN2_RING;

typedef struct
{   INT08U     ucEnable;
    INT08U     ucState;
    INT08U     ucAddress;
    INT08U     ucPriority;
    INT16U     usTime;
    INT16U     usPeriod;
    INT32U     uiID;
    INT16U     usEngState;
    INT16U     usActRated;
    INT16U     usRctRated;
    INT08U     ucActPrsnt;
    INT08U     ucRctPrsnt;
}   CAN2_LS_TCB;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)

CAN2_EXT INT32U  uiCAN2Status;
CAN2_EXT INT32U  uiCAN2SumWorkActLoad;
CAN2_EXT INT32U  uiCAN2SumReadyActRated;
CAN2_EXT INT32U  uiCAN2SumStartActRated;
CAN2_EXT INT32U  uiCAN2SumWorkActRated;
CAN2_EXT INT32U  uiCAN2SumTotalActRated;
CAN2_EXT INT32U  uiCAN2SumWorkRctLoad;
CAN2_EXT INT32U  uiCAN2SumReadyRctRated;
CAN2_EXT INT32U  uiCAN2SumStartRctRated;
CAN2_EXT INT32U  uiCAN2SumWorkRctRated;
CAN2_EXT INT32U  uiCAN2SumTotalRctRated;
CAN2_EXT INT08U  ucCAN2NumOfReady;
CAN2_EXT INT08U  ucCAN2NumOfStart;
CAN2_EXT INT08U  ucCAN2NumOfWork;
CAN2_EXT INT08U  ucCAN2NumOfTotal;
CAN2_EXT INT08U  ucCAN2PrioStartLow;
CAN2_EXT INT08U  ucCAN2PrioStartHigh;
CAN2_EXT INT08U  ucCAN2PrioReadyLow;
CAN2_EXT INT08U  ucCAN2PrioReadyHigh;
CAN2_EXT INT08U  ucCAN2PrioWorkLow;
CAN2_EXT INT08U  ucCAN2PrioWorkHigh;
CAN2_EXT INT08U  ucCAN2PrioTotalLow;
CAN2_EXT INT08U  ucCAN2PrioTotalHigh;
CAN2_EXT CAN_MSG sCAN2TaskRxMsg;
CAN2_EXT CAN_MSG sCAN2TaskTxMsg;
CAN2_EXT CAN_MSG sCAN2IntrRxMsg;
CAN2_EXT CAN_MSG sCAN2IntrTxMsg;
CAN2_EXT CAN2_RING sCAN2RingBuf;
CAN2_EXT CAN2_LS_TCB sCAN2EngTbl[CAN2_LS_TBL_SIZE];

#endif
/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (CAN2_FUNCTION_ON == 1)

CAN2_EXT void   CAN2Init(void);
CAN2_EXT void   CAN2Start(void);
CAN2_EXT void   CAN2TaskLoop(void);

CAN2_EXT void   CAN2EngTblInit(void);
CAN2_EXT void   CAN2CheckEngTblTimeOut(void);
CAN2_EXT void   CAN2PutRxMsgToEngTbl(CAN_MSG *pMsg);
CAN2_EXT void   CAN2SetupTxCanMsg(CAN_MSG *pMsg, CAN2_LS_TCB *pEng);
CAN2_EXT void   CAN2SetupTxEngTcb(CAN2_LS_TCB *pEng);
CAN2_EXT INT16U CAN2GetEngState(INT16U usPhase);
CAN2_EXT void   CAN2ProcessEngTbl(void);

CAN2_EXT INT16U CAN2GetCanSchedToStop(void);
CAN2_EXT INT16U CAN2GetCanSchedToSwitch(void);
CAN2_EXT INT16U CAN2GetCanSchedIsAlone(void);
CAN2_EXT INT16U CAN2GetCanSchedIsHighest(void);

CAN2_EXT void   CAN2TxIntHook(void);
CAN2_EXT void   CAN2Rx0IntHook(void);
CAN2_EXT void   CAN2Rx1IntHook(void);
CAN2_EXT void   CAN2SceIntHook(void);

CAN2_EXT void   CAN2BufInit(void);
CAN2_EXT INT08U CAN2IsTxBufFull(void);
CAN2_EXT INT08U CAN2IsRxBufEmpty(void);
CAN2_EXT void   CAN2PutRxMsgToBuf(CAN_MSG *msg);
CAN2_EXT INT08U CAN2GetTxMsgFmBuf(CAN_MSG *msg);
CAN2_EXT INT08U CAN2GetMsgFmRxBuf(INT16U to, CAN_MSG *msg);
CAN2_EXT INT08U CAN2PutMsgToTxBuf(INT16U to, CAN_MSG *msg);
CAN2_EXT void   CAN2HardInit(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */