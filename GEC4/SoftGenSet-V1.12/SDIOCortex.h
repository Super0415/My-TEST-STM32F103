/* ******************************************************************** */
/*                     MODBUS protocol Version 1.0                      */
/*                       Header File SDIOCortex.h                       */
/*                              2017-11-02                              */
/* ******************************************************************** */

#ifndef _SDIOCORTEX_H

#define _SDIOCORTEX_H

#ifdef   SDIO_GLOBALS

#define  SDIO_EXT  

#else

#define  SDIO_EXT extern

#endif

/* ******************************************************************** */
/*  SDIO_VERSION  = 10xx: VEC1000 Application                           */
/*  SDIO_VERSION  = 40xx: VEC4000 Application                           */
/*  SDIO_VERSION  = 68xx: VEC6800 Application                           */
/*  SDIO_VERSION  = 69xx: VEC6900 Application                           */
/*  SDIO_VERSION  = 760x: GEC7600-Main Application                      */
/*  SDIO_VERSION  = 761x: GEC7600-Display Application                   */
/*  SDIO_VERSION  = 780x: GEC7800-Main Application                      */
/*  SDIO_VERSION  = 781x: GEC7800-Display Application                   */
/*  SDIO_VERSION  = 80xx: VEC8000 Application                           */
/*  SDIO_VERSION  = 90xx: VEC9000 Application                           */
/*  SDIO_VERSION  = 96xx: VEC9600 Application                           */
/* ******************************************************************** */

#define SDIO_VERSION           7800

/* ******************************************************************** */
/*                         Application Difference                       */
/* ******************************************************************** */
#define SDIO_1000_COMMON_ON       0
#define SDIO_4000_COMMON_ON       0
#define SDIO_6800_COMMON_ON       0
#define SDIO_6900_COMMON_ON       0
#define SDIO_7600_COMMON_ON       0
#define SDIO_7600_MAIN_CHIP_ON    0
#define SDIO_7600_AUX_CHIP_ON     0
#define SDIO_7800_COMMON_ON       0
#define SDIO_7800_MAIN_CHIP_ON    0
#define SDIO_7800_AUX_CHIP_ON     0
#define SDIO_8000_COMMON_ON       0
#define SDIO_9000_COMMON_ON       0
#define SDIO_9600_COMMON_ON       0
#if   ((SDIO_VERSION / 100)   == 10)
#undef  SDIO_1000_COMMON_ON
#define SDIO_1000_COMMON_ON       1
#endif
#if   ((SDIO_VERSION / 100)   == 40)
#undef  SDIO_4000_COMMON_ON
#define SDIO_4000_COMMON_ON       1
#endif
#if   ((SDIO_VERSION / 100)   == 68)
#undef  SDIO_6800_COMMON_ON
#define SDIO_6800_COMMON_ON       1
#endif
#if   ((SDIO_VERSION / 100)   == 69)
#undef  SDIO_6900_COMMON_ON
#define SDIO_6900_COMMON_ON       1
#endif
#if   ((SDIO_VERSION / 100)   == 76)
#undef  SDIO_7600_COMMON_ON
#define SDIO_7600_COMMON_ON       1
#endif
#if   ((SDIO_VERSION / 10)   == 760)
#undef  SDIO_7600_MAIN_CHIP_ON
#define SDIO_7600_MAIN_CHIP_ON    1
#endif
#if   ((SDIO_VERSION / 10)   == 761)
#undef  SDIO_7600_AUX_CHIP_ON
#define SDIO_7600_AUX_CHIP_ON     1
#endif
#if   ((SDIO_VERSION / 100)   == 78)
#undef  SDIO_7800_COMMON_ON
#define SDIO_7800_COMMON_ON       1
#endif
#if   ((SDIO_VERSION / 10)   == 780)
#undef  SDIO_7800_MAIN_CHIP_ON
#define SDIO_7800_MAIN_CHIP_ON    1
#endif
#if   ((SDIO_VERSION / 10)   == 781)
#undef  SDIO_7800_AUX_CHIP_ON
#define SDIO_7800_AUX_CHIP_ON     1
#endif
#if   ((SDIO_VERSION / 100)   == 80)
#undef  SDIO_8000_COMMON_ON
#define SDIO_8000_COMMON_ON       1
#endif
#if   ((SDIO_VERSION / 100)   == 90)
#undef  SDIO_9000_COMMON_ON
#define SDIO_9000_COMMON_ON       1
#endif
#if   ((SDIO_VERSION / 100)   == 96)
#undef  SDIO_9600_COMMON_ON
#define SDIO_9600_COMMON_ON       1
#endif

/* ******************************************************************** */
/*                       Function Switch Definition                     */
/* ******************************************************************** */
#define SDIO_SD_FUNCTION_ON       0
#define SDIO_CPU_9S12_ON          0
#define SDIO_CPU_POWERPC_ON       0
#define SDIO_CPU_STM32F1_ON       0
#define SDIO_CPU_STM32F103_ON     0
#define SDIO_CPU_STM32F105_ON     0
#if    (SDIO_1000_COMMON_ON    == 1)
#undef  SDIO_CPU_9S12_ON
#define SDIO_CPU_9S12_ON          1
#endif
#if    (SDIO_4000_COMMON_ON    == 1)
#undef  SDIO_CPU_9S12_ON
#define SDIO_CPU_9S12_ON          1
#endif
#if    (SDIO_6800_COMMON_ON    == 1)
#undef  SDIO_CPU_9S12_ON
#define SDIO_CPU_9S12_ON          1
#endif
#if    (SDIO_6900_COMMON_ON    == 1)
#undef  SDIO_CPU_POWERPC_ON
#define SDIO_CPU_POWERPC_ON       1
#endif
#if    (SDIO_7600_COMMON_ON    == 1)
#undef  SDIO_CPU_STM32F1_ON
#define SDIO_CPU_STM32F1_ON       1
#endif
#if    (SDIO_7600_MAIN_CHIP_ON == 1)
#undef  SDIO_CPU_STM32F105_ON
#define SDIO_CPU_STM32F105_ON     1
#endif
#if    (SDIO_7600_AUX_CHIP_ON  == 1)
#undef  SDIO_CPU_STM32F103_ON
#define SDIO_CPU_STM32F103_ON     1
#endif
#if    (SDIO_7800_COMMON_ON    == 1)
#undef  SDIO_CPU_STM32F1_ON
#define SDIO_CPU_STM32F1_ON       1
#endif
#if    (SDIO_7800_MAIN_CHIP_ON == 1)
#undef  SDIO_CPU_STM32F105_ON
#define SDIO_CPU_STM32F105_ON     1
#endif
#if    (SDIO_7800_AUX_CHIP_ON  == 1)
#undef  SDIO_CPU_STM32F103_ON
#define SDIO_CPU_STM32F103_ON     1
#endif
#if    (SDIO_8000_COMMON_ON    == 1)
#undef  SDIO_CPU_POWERPC_ON
#define SDIO_CPU_POWERPC_ON       1
#endif
#if    (SDIO_9000_COMMON_ON    == 1)
#undef  SDIO_CPU_POWERPC_ON
#define SDIO_CPU_POWERPC_ON       1
#endif
#if    (SDIO_9600_COMMON_ON    == 1)
#undef  SDIO_CPU_POWERPC_ON
#define SDIO_CPU_POWERPC_ON       1
#endif

/* ******************************************************************** */
/*                          Variable Definition                         */
/* ******************************************************************** */
SDIO_EXT INT16U usSDIOTimer;
SDIO_EXT INT16U usSDIOStatus;

/* ******************************************************************** */
/*                          Function Definition                         */
/* ******************************************************************** */
#if (SDIO_SD_FUNCTION_ON == 1)

SDIO_EXT void   SDIOInit(void);
SDIO_EXT void   SDIOStart(void);
SDIO_EXT void   SDIOTaskLoop(void);

#endif
/* ******************************************************************** */
/*                      End of Function Definition                      */
/* ******************************************************************** */
#endif
/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
