#ifndef __J1939_H
#define __J1939_H


 #include "CAN_PUBLIC.H"

/* ******************************************************************** */
/*                          Public Definition                           */
/* ******************************************************************** */
   #define CAN_GEC4010_COMMON_ON   1
   #define CAN_GEC5010_COMMON_ON   0
   
   

/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
	typedef struct
	{   INT08U     ucEnable;
		INT08U     ucState;
		INT16U     usTime;
		INT16U     usPeriod;
		INT32U     uiID;
	}   CAN_PGN_TCB;
	typedef struct
	{   INT16U     usCode;
		INT16U     usWhich;
		INT16U     usValue;
	}   CAN_CCP10_STR;


/* ******************************************************************** */
/*                         GEC4010 Application                          */
/* ******************************************************************** */
#if    (CAN_GEC4010_COMMON_ON   == 1)
	
		#define CAN_MY_ADDRESS         23
		#define CAN_SLAVE_ADDRESS       1
		#define CAN_CPU_9S12_ON         1
		#define CAN_CPU_POWERPC_ON      0
		#define CAN_ENGINE_CONTROL_ON   0
		#define CAN_ENGINE_EFI_ON       0
		#define CAN_CCP_CCP10_ON        1
		#define CAN_IGNORE_SPEED_ERROR  1
		#define CAN_IGNORE_RACK_ERROR   0
		#define CAN_PRESS_RELATIVE_ON   1
		#define CAN_RX_PGN_MATCH_ON     0
		#define CAN_TX_DM1_DM2_SPN_ON   0
		#define CAN_RX_PGN_MAX          20
		#define CAN_TX_PGN_MAX          2
		#define CAN_RX_PGN_EEC1         0
		#define CAN_RX_PGN_EEC2         1
		#define CAN_RX_PGN_EEC3         2
		#define CAN_RX_PGN_AMCON        3
		#define CAN_RX_PGN_VEHSPD       4
		#define CAN_RX_PGN_CNFPBAM      5
		#define CAN_RX_PGN_CNFPACK      6
		#define CAN_RX_PGN_ENGTEMP      7
		#define CAN_RX_PGN_LFE          8
		#define CAN_RX_PGN_EFL          9
		#define CAN_RX_PGN_LFC          10
		#define CAN_RX_PGN_DM1SINGLE    11
		#define CAN_RX_PGN_DM2SINGLE    12
		#define CAN_RX_PGN_DM4SINGLE    13
		#define CAN_RX_PGN_DM11ACK      14
		#define CAN_RX_PGN_INCON        15
		#define CAN_RX_PGN_VEHPOW       16
		#define CAN_RX_PGN_ENGHOUR      17
		#define CAN_RX_PGN_CRPRESS      18
		#define CAN_RX_PGN_CCP10PAR     19
		//#define CAN_TX_PGN_PGNRQ        0
		//#define CAN_TX_PGN_CCP10REQ     1 
		//#define CAN_RX_PGN_MATCH_ON     1

#endif

/* ******************************************************************** */
/*                      SAE J1939 ID Definition                         */
/*                   GEC4010CAN J1939 ID Definition                     */
/* ******************************************************************** */
#if    (CAN_GEC4010_COMMON_ON   == 1)

		#define CAN_ID_J1939_EEC1      (INT32U)0x0CF00400
		#define CAN_ID_J1939_EEC2      (INT32U)0x0CF00300
		#define CAN_ID_J1939_EEC3      (INT32U)0x18FEDF00
		#define CAN_ID_J1939_AMCON     (INT32U)0x18FEF500
		#define CAN_ID_J1939_VEHSPD    (INT32U)0x18FEF100
		#define CAN_ID_J1939_CNFPBAM   (INT32U)0x18ECFF00
		#define CAN_ID_J1939_CNFPACK   (INT32U)0x18EBFF00
		#define CAN_ID_J1939_ENGTEMP   (INT32U)0x18FEEE00
		#define CAN_ID_J1939_LFE       (INT32U)0x18FEF200
		#define CAN_ID_J1939_EFL       (INT32U)0x18FEEF00
		#define CAN_ID_J1939_LFC       (INT32U)0x18FEE900
		#define CAN_ID_J1939_DM1SINGLE (INT32U)0x18FECA00
		#define CAN_ID_J1939_DM2SINGLE (INT32U)0x18FECB00
		#define CAN_ID_J1939_DM4SINGLE (INT32U)0x18FECD00
		#define CAN_ID_J1939_DM11ACK   (INT32U)0x18EBFF00
		#define CAN_ID_J1939_INCON     (INT32U)0x18FEF600
		#define CAN_ID_J1939_VEHPOW    (INT32U)0x18FEF700
		#define CAN_ID_J1939_ENGHOUR   (INT32U)0x18FEE500
		#define CAN_ID_J1939_CRPRESS   (INT32U)0x18FFF400

		#define CAN_ID_J1939_EBC1      (INT32U)0x18F0010B
		#define CAN_ID_J1939_EBC2      (INT32U)0x18FEBF0B
		#define CAN_ID_J1939_ETC1      (INT32U)0x0CF00203
		#define CAN_ID_J1939_RXCCVS    (INT32U)0x18FEF121
		#define CAN_ID_J1939_HRVD      (INT32U)0x18FEC1EE
		#define CAN_ID_J1939_PGNRQ     (INT32U)0x18EA0021
		#define CAN_ID_J1939_RXAMCON   (INT32U)0x01FEF521
		#define CAN_ID_J1939_TCO1      (INT32U)0x0CFE6CEE
		#define CAN_ID_J1939_TSC1AE    (INT32U)0x0C00000B
		#define CAN_ID_J1939_TSC1AR    (INT32U)0x0C000F0B
		#define CAN_ID_J1939_TSC1DE    (INT32U)0x0C000010
		#define CAN_ID_J1939_TSC1DR    (INT32U)0x0C000F10
		#define CAN_ID_J1939_TSC1PE    (INT32U)0x0C000024
		#define CAN_ID_J1939_TSC1TE    (INT32U)0x0C000003
		#define CAN_ID_J1939_TSC1TR    (INT32U)0x0C000F03
		#define CAN_ID_J1939_TSC1VE    (INT32U)0x0C000021
		#define CAN_ID_J1939_TSC1VR    (INT32U)0x0C000F21
		#define CAN_ID_J1939_DM13      (INT32U)0x18DFFF27
		#define CAN_ID_J1939_DEC1      (INT32U)0x0CFF0431
		#define CAN_ID_J1939_LOCK      (INT32U)0x18DC0027
		#define CAN_ID_J1939_CCP10REQ  (INT32U)0x0CF00E21
		#define CAN_ID_J1939_CCP10PAR  (INT32U)0x0CF00F00
		#define CAN_ID_J1939_SLAVEERR  (INT32U)0x18FECA01

#endif

/* ******************************************************************** */
/*                           5010 Application                           */
/* ******************************************************************** */
#if    (CAN_GEC5010_COMMON_ON   == 1)
		#define CAN_IGNORE_SPEED_ERROR  1
		#define CAN_IGNORE_RACK_ERROR   0
		#define CAN_PRESS_RELATIVE_ON   1
		#define CAN_RX_PGN_MATCH_ON     0
		#define CAN_TX_DM1_DM2_SPN_ON   0
		#define CAN_RX_PGN_MAX          16
		#define CAN_TX_PGN_MAX          20
		#define CAN_RX_PGN_EBC1         0
		#define CAN_RX_PGN_EBC2         1
		#define CAN_RX_PGN_ETC1         2
		#define CAN_RX_PGN_RXCCVS       3
		#define CAN_RX_PGN_HRVD         4
		#define CAN_RX_PGN_PGNRQ        5
		#define CAN_RX_PGN_RXAMCON      6
		#define CAN_RX_PGN_TCO1         7
		#define CAN_RX_PGN_TSC1AE       8
		#define CAN_RX_PGN_TSC1DE       9
		#define CAN_RX_PGN_TSC1PE       10
		#define CAN_RX_PGN_TSC1TE       11
		#define CAN_RX_PGN_TSC1VE       12
		#define CAN_RX_PGN_DM13         13
		#define CAN_RX_PGN_DEC1         14
		#define CAN_RX_PGN_CCP10REQ     15
		#define CAN_TX_PGN_EEC1         0
		#define CAN_TX_PGN_EEC2         1
		#define CAN_TX_PGN_EEC3         2
		#define CAN_TX_PGN_AMCON        3
		#define CAN_TX_PGN_VEHSPD       4
		#define CAN_TX_PGN_CNFPBAM      5
		#define CAN_TX_PGN_CNFPACK      6
		#define CAN_TX_PGN_ENGTEMP      7
		#define CAN_TX_PGN_LFE          8
		#define CAN_TX_PGN_EFL          9
		#define CAN_TX_PGN_LFC          10
		#define CAN_TX_PGN_DM1SINGLE    11
		#define CAN_TX_PGN_DM2SINGLE    12
		#define CAN_TX_PGN_DM4SINGLE    13
		#define CAN_TX_PGN_DM11ACK      14
		#define CAN_TX_PGN_INCON        15
		#define CAN_TX_PGN_VEHPOW       16
		#define CAN_TX_PGN_ENGHOUR      17
		#define CAN_TX_PGN_CRPRESS      18
		#define CAN_TX_PGN_CCP10PAR     19
#endif



/* ******************************************************************** */
/*                            Basic Definition                          */
/* ******************************************************************** */
#define CAN_TRUE                1
#define CAN_FALSE               0
#define CAN_ENABLE              1
#define CAN_DISABLE             0
#define CAN_BASIC_TIME          5
#define CAN_NO_ERR              0
#define CAN_ERR_INVALID         1
#define CAN_ERR_TIMEOUT         2
#define CAN_CODE_FREE           0
#define CAN_CODE_CYCLIC         1
#define CAN_CODE_IMMED          2
#define CAN_STS_NORMAL          0
#define CAN_STS_RESET           1
#define CAN_STS_WARNING         2
#define CAN_STS_BUS_OFF         4
#define CAN_STS_SLEEPING        8
#define CAN_STS_OVERRUN         16
#define CAN_STS_TX_OK           32
#define CAN_STS_RX_OK           64

#define CAN_UC_LOW(w)          (INT08U)(w)
#define CAN_UC_HIGH(w)         (INT08U)((w)>>8)
#define CAN_US_CREAT(l,h)      (INT16U)(l)+((INT16U)(h)<<8)
#define CAN_CPU_TO_ID32(x)     (((x>>1)&(INT32U)0x0003FFFF)|((x>>3)&(INT32U)0x1FFC0000))
#define CAN_ID32_TO_CPU(x)     (((x&(INT32U)0x0003FFFF)<<1)|((x&(INT32U)0x1FFC0000)<<3)|(INT32U)0x00180000)
#define CAN_CPU_TO_PGN16(x)    (INT16U)(((x>>9)&(INT32U)0x000003FF)|((x>>11)&(INT32U)0x0000FC00))
#define CAN_ID32_TO_PGN16(x)   (INT16U)(x>>8)
#define CAN_CPU_TO_PGN32(x)    (x&(INT32U)0x07E7FE00)


/* ******************************************************************** */
/*                           Type Definition                            */
/* ******************************************************************** */
extern INT16U usCANTimer;
extern INT16U usCANStatus;
extern CAN_PGN_TCB sCANRxPgnTbl[CAN_RX_PGN_MAX];
extern CAN_PGN_TCB sCANTxPgnTbl[CAN_TX_PGN_MAX];
extern CAN_CCP10_STR sCANRxCcpPar;


extern void GeneralJ1939Init(void);
extern INT8U GeneralJ1939RxMsg(CAN_MSG *pMsg);
extern INT08U GeneralJ1939TxMsg (CAN_MSG *pMsg);


#endif


