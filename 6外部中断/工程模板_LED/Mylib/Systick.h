#ifndef _SYSTICK_H_
#define _SYSTICK_H_
#include "stm32f10x.h"

void delay_us(u32 i);//微秒
void delay_ms(u32 i);//毫秒
void RCC_HSE_Configuration(void); //自定义系统时间（可以修改时钟）


#endif
