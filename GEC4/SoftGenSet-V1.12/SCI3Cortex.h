/* ******************************************************************** */
/*                     MODBUS protocol Version 1.0                      */
/*                       Header File SCI3Cortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SCI3CORTEX_H

#define _SCI3CORTEX_H

#ifdef   SCI3_GLOBALS

#define  SCI3_EXT  

#else

#define  SCI3_EXT extern

#endif

/* ******************************************************************** */
/*  SCI3_VERSION  = 10xx: VEC1000 Application                           */
/*  SCI3_VERSION  = 40xx: VEC4000 Application                           */
/*  SCI3_VERSION  = 68xx: VEC6800 Application                           */
/*  SCI3_VERSION  = 69xx: VEC6900 Application                           */
/*  SCI3_VERSION  = 760x: GEC7600-Main Application                      */
/*  SCI3_VERSION  = 761x: GEC7600-Display Application                   */
/*  SCI3_VERSION  = 780x: GEC7800-Main Application                      */
/*  SCI3_VERSION  = 781x: GEC7800-Display Application                   */
/*  SCI3_VERSION  = 80xx: VEC8000 Application                           */
/*  SCI3_VERSION  = 90xx: VEC9000 Application                           */
/*  SCI3_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SCI3_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SCI3_1000_COMMON_ON       0
#define SCI3_4000_COMMON_ON       0
#define SCI3_6800_COMMON_ON       0
#define SCI3_6900_COMMON_ON       0
#define SCI3_7600_COMMON_ON       0
#define SCI3_7600_MAIN_CHIP_ON    0
#define SCI3_7600_AUX_CHIP_ON     0
#define SCI3_7800_COMMON_ON       0
#define SCI3_7800_MAIN_CHIP_ON    0
#define SCI3_7800_AUX_CHIP_ON     0
#define SCI3_8000_COMMON_ON       0
#define SCI3_9000_COMMON_ON       0
#define SCI3_9600_COMMON_ON       0
#if   ((SCI3_VERSION / 100)   == 10)
#undef  SCI3_1000_COMMON_ON
#define SCI3_1000_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 40)
#undef  SCI3_4000_COMMON_ON
#define SCI3_4000_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 68)
#undef  SCI3_6800_COMMON_ON
#define SCI3_6800_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 69)
#undef  SCI3_6900_COMMON_ON
#define SCI3_6900_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 76)
#undef  SCI3_7600_COMMON_ON
#define SCI3_7600_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 10)   == 760)
#undef  SCI3_7600_MAIN_CHIP_ON
#define SCI3_7600_MAIN_CHIP_ON    1
#endif
#if   ((SCI3_VERSION / 10)   == 761)
#undef  SCI3_7600_AUX_CHIP_ON
#define SCI3_7600_AUX_CHIP_ON     1
#endif
#if   ((SCI3_VERSION / 100)   == 78)
#undef  SCI3_7800_COMMON_ON
#define SCI3_7800_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 10)   == 780)
#undef  SCI3_7800_MAIN_CHIP_ON
#define SCI3_7800_MAIN_CHIP_ON    1
#endif
#if   ((SCI3_VERSION / 10)   == 781)
#undef  SCI3_7800_AUX_CHIP_ON
#define SCI3_7800_AUX_CHIP_ON     1
#endif
#if   ((SCI3_VERSION / 100)   == 80)
#undef  SCI3_8000_COMMON_ON
#define SCI3_8000_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 90)
#undef  SCI3_9000_COMMON_ON
#define SCI3_9000_COMMON_ON       1
#endif
#if   ((SCI3_VERSION / 100)   == 96)
#undef  SCI3_9600_COMMON_ON
#define SCI3_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SCI3_FUNCTION_ON          1
#define SCI3_CPU_9S12_ON          0
#define SCI3_CPU_POWERPC_ON       0
#define SCI3_CPU_STM32F1_ON       0
#define SCI3_CPU_STM32F103_ON     0
#define SCI3_CPU_STM32F105_ON     0
#if    (SCI3_1000_COMMON_ON    == 1)
#undef  SCI3_CPU_9S12_ON
#define SCI3_CPU_9S12_ON          1
#endif
#if    (SCI3_4000_COMMON_ON    == 1)
#undef  SCI3_CPU_9S12_ON
#define SCI3_CPU_9S12_ON          1
#endif
#if    (SCI3_6800_COMMON_ON    == 1)
#undef  SCI3_CPU_9S12_ON
#define SCI3_CPU_9S12_ON          1
#endif
#if    (SCI3_6900_COMMON_ON    == 1)
#undef  SCI3_CPU_POWERPC_ON
#define SCI3_CPU_POWERPC_ON       1
#endif
#if    (SCI3_7600_COMMON_ON    == 1)
#undef  SCI3_CPU_STM32F1_ON
#define SCI3_CPU_STM32F1_ON       1
#endif
#if    (SCI3_7600_MAIN_CHIP_ON == 1)
#undef  SCI3_CPU_STM32F105_ON
#define SCI3_CPU_STM32F105_ON     1
#undef  SCI3_FUNCTION_ON
#define SCI3_FUNCTION_ON          1
#endif
#if    (SCI3_7600_AUX_CHIP_ON  == 1)
#undef  SCI3_CPU_STM32F103_ON
#define SCI3_CPU_STM32F103_ON     1
#endif
#if    (SCI3_7800_COMMON_ON    == 1)
#undef  SCI3_CPU_STM32F1_ON
#define SCI3_CPU_STM32F1_ON       1
#endif
#if    (SCI3_7800_MAIN_CHIP_ON == 1)
#undef  SCI3_CPU_STM32F105_ON
#define SCI3_CPU_STM32F105_ON     1
#undef  SCI3_FUNCTION_ON
#define SCI3_FUNCTION_ON          1
#endif
#if    (SCI3_7800_AUX_CHIP_ON  == 1)
#undef  SCI3_CPU_STM32F103_ON
#define SCI3_CPU_STM32F103_ON     1
#endif
#if    (SCI3_8000_COMMON_ON    == 1)
#undef  SCI3_CPU_POWERPC_ON
#define SCI3_CPU_POWERPC_ON       1
#endif
#if    (SCI3_9000_COMMON_ON    == 1)
#undef  SCI3_CPU_POWERPC_ON
#define SCI3_CPU_POWERPC_ON       1
#endif
#if    (SCI3_9600_COMMON_ON    == 1)
#undef  SCI3_CPU_POWERPC_ON
#define SCI3_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                 F105 USART3 RX And TX Pin Definition                 */
/*    (Default: PB10 & PB11, Partial: PC10 & PC11, Full: PD8 & PD9)     */
/* ******************************************************************** */
#define SCI3_AFIO_REMAP1        AFIO_MAPR_USART3_REMAP_PARTIALREMAP
#define SCI3_AFIO_REMAP2        0
#define SCI3_GPO_PT_SCITX       PC10
#define SCI3_GPI_PT_SCIRX       PC11

/* ******************************************************************** */
/*                 F105 USART4 RX And TX Pin Definition                 */
/*                   (Default: PC10 & PC11, No Remap)                   */
/* ******************************************************************** */
#define SCI4_AFIO_REMAP         0
#define SCI4_GPO_PT_SCITX       PC10
#define SCI4_GPI_PT_SCIRX       PC11

/* ******************************************************************** */
/*                 F105 USART5 RX And TX Pin Definition                 */
/*                   (Default: PC12 & PD2, No Remap)                    */
/* ******************************************************************** */
#define SCI5_AFIO_REMAP         0
#define SCI5_GPO_PT_SCITX       PC12
#define SCI5_GPI_PT_SCIRX       PD2

/* ******************************************************************** */
/*                           Hardware Difference                        */
/* ******************************************************************** */
#if    (SCI3_CPU_9S12_ON == 1)
#define SCI3_SCI_RX_EN()        SCI0CR2_RE    = 1
#define SCI3_SCI_RX_DIS()       SCI0CR2_RE    = 0
#define SCI3_SCI_RX_INT_EN()    SCI0CR2_RIE   = 1
#define SCI3_SCI_RX_INT_DIS()   SCI0CR2_RIE   = 0
#define SCI3_SCI_TX_EN()        SCI0CR2_TE    = 1
#define SCI3_SCI_TX_DIS()       SCI0CR2_TE    = 0
#define SCI3_SCI_TC_INT_EN()    SCI0CR2_TCIE  = 1
#define SCI3_SCI_TC_INT_DIS()   SCI0CR2_TCIE  = 0
#define SCI3_SCI_TX_INT_EN()    SCI0CR2_SCTIE = 1
#define SCI3_SCI_TX_INT_DIS()   SCI0CR2_SCTIE = 0
#endif
#if    (OS_CPU_POWERPC_ON == 1)
#define SCI3_SCI_RX_EN()        ESCI_A.CR1.B.RE   = 1
#define SCI3_SCI_RX_DIS()       ESCI_A.CR1.B.RE   = 0
#define SCI3_SCI_RX_INT_EN()    ESCI_A.CR1.B.RIE  = 1
#define SCI3_SCI_RX_INT_DIS()   ESCI_A.CR1.B.RIE  = 0
#define SCI3_SCI_TX_EN()        ESCI_A.CR1.B.TE   = 1
#define SCI3_SCI_TX_DIS()       ESCI_A.CR1.B.TE   = 0
#define SCI3_SCI_TC_INT_EN()    ESCI_A.CR1.B.TCIE = 1
#define SCI3_SCI_TC_INT_DIS()   ESCI_A.CR1.B.TCIE = 0
#define SCI3_SCI_TX_INT_EN()    ESCI_A.CR1.B.TIE  = 1
#define SCI3_SCI_TX_INT_DIS()   ESCI_A.CR1.B.TIE  = 0
#endif
#if    (SCI3_CPU_STM32F1_ON == 1)
#define SCI3_FRQ_CLK           (INT32U)72000000     /* PCLK1 for USART3 */
#define SCI3_BAUD_DEFAULT       9600
#define SCI3_SCI_RX_EN()        USART3->CR1 |=  USART_CR1_RE
#define SCI3_SCI_RX_DIS()       USART3->CR1 &= ~USART_CR1_RE
#define SCI3_SCI_RX_INT_EN()    USART3->CR1 |=  USART_CR1_RXNEIE
#define SCI3_SCI_RX_INT_DIS()   USART3->CR1 &= ~USART_CR1_RXNEIE
#define SCI3_SCI_TX_EN()        USART3->CR1 |=  USART_CR1_TE
#define SCI3_SCI_TX_DIS()       USART3->CR1 &= ~USART_CR1_TE
#define SCI3_SCI_TC_INT_EN()    USART3->CR1 |=  USART_CR1_TCIE
#define SCI3_SCI_TC_INT_DIS()   USART3->CR1 &= ~USART_CR1_TCIE
#define SCI3_SCI_TX_INT_EN()    USART3->CR1 |=  USART_CR1_TXEIE
#define SCI3_SCI_TX_INT_DIS()   USART3->CR1 &= ~USART_CR1_TXEIE
#endif

/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define SCI3_TRUE               1
#define SCI3_FALSE              0
#define SCI3_NO_ERR             0
#define SCI3_ERR_EVENT_TYPE     1
#define SCI3_ERR_PEND_ISR       2
#define SCI3_ERR_BAD_CH         3
#define SCI3_ERR_RX_EMPTY       4
#define SCI3_ERR_TX_FULL        5
#define SCI3_ERR_TX_EMPTY       6
#define SCI3_ERR_RX_TIMEOUT     7
#define SCI3_ERR_TX_TIMEOUT     8
#define SCI3_STS_NORMAL         0
#define SCI3_STS_RESET          1
#define SCI3_STS_WARNING        2
#define SCI3_STS_BUS_OFF        4
#define SCI3_STS_SLEEPING       8
#define SCI3_STS_OVERRUN        16
#define SCI3_STS_TX_ERR         32
#define SCI3_STS_RX_ERR         64
#define SCI3_STS_GET_BIT(m)    (usSCI3Status & (m))
#define SCI3_STS_CLR_BIT(m)     usSCI3Status &= ~(m)
#define SCI3_STS_SET_BIT(m)     usSCI3Status |= (m)

/* ******************************************************************** */
/*                          Control Definition                          */
/* ******************************************************************** */
#define SCI3_RX_BUF_SIZE        8
#define SCI3_TX_BUF_SIZE        8
#define SCI3_RX_TO_TICKS        10
#define SCI3_TX_TO_TICKS        10

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
typedef struct
{   INT16U      usRingBufRxCtr;
    OS_EVENT   *pRingBufRxSem;
    INT08U     *pRingBufRxInPtr;
    INT08U     *pRingBufRxOutPtr;
    INT08U      ucRingBufRx[SCI3_RX_BUF_SIZE];
    INT16U      usRingBufTxCtr;
    OS_EVENT   *pRingBufTxSem;
    INT08U     *pRingBufTxInPtr;
    INT08U     *pRingBufTxOutPtr;
    INT08U      ucRingBufTx[SCI3_TX_BUF_SIZE];
}   SCI3_RING_STR;

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
SCI3_EXT INT16U usSCI3Timer;
SCI3_EXT INT16U usSCI3Status;
#if (SCI3_FUNCTION_ON == 1)
SCI3_EXT SCI3_RING_STR sSCI3RingBuf;
#endif

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SCI3_FUNCTION_ON == 1)

SCI3_EXT void   SCI3Init(void);
SCI3_EXT void   SCI3Start(void);
SCI3_EXT void   SCI3TaskLoop(void);
SCI3_EXT void   SCI3TxRxIntHook(void);
SCI3_EXT INT08U SCI3CheckTime(INT16U usOld, INT16U usPer);
SCI3_EXT void   SCI3BufInit(void);
SCI3_EXT INT08U SCI3IsTxFull(void);
SCI3_EXT INT08U SCI3IsRxEmpty(void);
SCI3_EXT void   SCI3PutRxChar(INT08U c);
SCI3_EXT INT08U SCI3GetTxChar(INT08U *err);
SCI3_EXT INT08U SCI3GetChar(INT16U to, INT08U *err);
SCI3_EXT INT08U SCI3PutChar(INT16U to, INT08U c);
SCI3_EXT void   SCI3HardInit(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */