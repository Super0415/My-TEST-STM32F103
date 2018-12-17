#ifndef _BOSCH_KHCB_H
                               
#define _BOSCH_KHCB_H

 #include "CAN_PUBLIC.H"

extern  void  BOSCH_KHCBInit(void);           //BOSCH-KHCB科华船舶
extern  INT8U BOSCH_KHCBRxMsg(CAN_MSG *pMsg); //BOSCH-KHCB科华船舶
extern  void  BOSCH_KHCBSendCtrMsg(void);     //BOSCH-KHCB科华船舶



#endif

