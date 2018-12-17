#ifndef  _CAN_H
#define  _CAN_H
#include "TYPCortex.h"

extern INT16U usCANTimerBuf;    //CANÍ¨ÐÅ³¬Ê±¼ì²â	
	
		void CAN_Config(void);
		void CAN_SetMsg(void);
		
		void CAN1_IRQHandler_it(void) ;
		extern void CAN_J1939Public_Init(void);


#endif

//-------------------------------------------------
