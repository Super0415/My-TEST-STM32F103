#ifndef __RS485LIN_H
#define __RS485LIN_H

typedef enum {Max485_R = 0,Max485_T = !Max485_R} Max485Status;


#define RS485_USART1_TXRX_CON(CON){\
          if(CON==1)GPIO_SetBits(GPIOA,   GPIO_Pin_8);\
	        else      GPIO_ResetBits(GPIOA, GPIO_Pin_8);\
        }

				
void RS485_USART1_INIT(void);
void RS485_Manage(void);
				

#endif
