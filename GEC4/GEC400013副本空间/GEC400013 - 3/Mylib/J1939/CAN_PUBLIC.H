#ifndef __CAN_PUBLIC_H

#define __CAN_PUBLIC_H  


#define CAN_RX_BUF_SIZE   12
#define DB_DISP_PAR_NUM   20

/*********************************************************************
    变量结构体定义
**********************************************************************/
				typedef unsigned char  BOOL;
				typedef unsigned char  BOOLEAN;
				typedef unsigned char  INT8U;
				typedef signed   char  INT8S;
				typedef unsigned char  INT08U;
				typedef signed   char  INT08S;
				typedef unsigned short INT16U;
				typedef signed   short INT16S;
				typedef unsigned int   INT32U;
				typedef signed   int   INT32S;

				typedef struct
				{   INT32U          uiID;
						INT32U          uiDat0;
						INT32U          uiDat1;
				}   CAN_DATA32_STR;
				typedef struct
				{   INT16U          usID1;
						INT16U          usID0;
						INT16U          usDat0;
						INT16U          usDat1;
						INT16U          usDat2;
						INT16U          usDat3;
				}   CAN_DATA16_STR;
				typedef struct
				{   INT08U          ucID3;
						INT08U          ucID2;
						INT08U          ucID1;
						INT08U          ucID0;
						INT08U          ucDat0;
						INT08U          ucDat1;
						INT08U          ucDat2;
						INT08U          ucDat3;
						INT08U          ucDat4;
						INT08U          ucDat5;
						INT08U          ucDat6;
						INT08U          ucDat7;
				}   CAN_DATA08_STR;
				typedef union
				{   CAN_DATA32_STR  DAT32;
						CAN_DATA16_STR  DAT16;
						CAN_DATA08_STR  DAT08;
				}   CAN_MSG;

				typedef struct 
				{
					 INT8U  ENABLE;
					 INT16S *VALUE;
				}CAN_DATATBL;

				typedef struct db_par_tcb
				{  // const INT08U *pName;
					 // const INT08U *pCName;
					 // const INT08U *pBName;
						const INT08U *pUnit;
						INT16S        ssValue;
					//  INT16S        ssMin;
					//  INT16S        ssMax;
					//  INT08U        ucPos;
						INT08U        ucErr;
				}   DB_PAR_TCB;

				typedef struct 
				{
					 INT8U  POINT;
					 CAN_MSG CAN_DATATBL[CAN_RX_BUF_SIZE];
				}CAN_DATARXBUF;


/*********************************************************************
      采集到数据放入数组序号定义
**********************************************************************/
#define DB_NO_ENG_SPEED         0  //电喷机转速
#define DB_NO_VEH_SPEED         1
#define DB_NO_ENG_LOAD          2
#define DB_NO_ENG_HOUR          3
#define DB_NO_COOL_TEMP         4 //水温
#define DB_NO_AIR_TEMP          5
#define DB_NO_OIL_TEMP          6
#define DB_NO_FUEL_TEMP         7
#define DB_NO_AIR_PRES          8
#define DB_NO_OIL_PRES          9   //油压
#define DB_NO_FUEL_PRES         10
#define DB_NO_RAIL_PRES         11
#define DB_NO_FUEL_ECONOMY      12
#define DB_NO_FUEL_RATE         13
#define DB_NO_PEDAL_POSI        14
#define DB_NO_GEAR_POSI         15
#define DB_NO_SYS_VOLT          16
#define DB_NO_ENG_CONFIG        17
#define DB_NO_ACT_FAULT         18
#define DB_NO_STO_FAULT         19



/*********************************************************************
    函数声明定义
**********************************************************************/
extern INT16U usDBmErrCAN;
extern INT16U usDBmCanState;
extern CAN_DATARXBUF CANRXBUF;
//extern CAN_MSG sFWCanIntrRxMsg;
extern DB_PAR_TCB aDBDisplay[DB_DISP_PAR_NUM];

extern INT16U CANGetStatus(void);
extern void   CANSetStatus(INT16U usSet);
extern void   CANClearStatus(INT16U usClear);
extern INT08U CANCheckTime(INT16U usOld, INT16U usNow, INT16U usPer);
extern void CANBusTimeOutErrCheck(void);



#endif
