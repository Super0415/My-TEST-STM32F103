#ifndef _BOSCH_KHCB_H
                               
#define _BOSCH_KHCB_H

 #include "CAN_PUBLIC.H"

extern  void  BOSCH_KHCBInit(void);           //BOSCH-KHCB�ƻ�����
extern  INT8U BOSCH_KHCBRxMsg(CAN_MSG *pMsg); //BOSCH-KHCB�ƻ�����
extern  void  BOSCH_KHCBSendCtrMsg(void);     //BOSCH-KHCB�ƻ�����



#endif

