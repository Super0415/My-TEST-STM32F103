#ifndef _LED_H_
#define _LED_H_
#include "stm32f10x.h"

void delay(u32 i);
void Init_LED(void );
void led_display(void);

/*
功能：取反LED1  // 绿光
*/
void ChangeLed1(void);
/*
功能：点亮LED1
*/
void TurnOnLed1(void);
/*
功能：熄灭LED1
*/
void TurnOffLed1(void);
/*
功能：取反LED2	// 蓝光
*/
void ChangeLed2(void);
/*
功能：点亮LED2
*/
void TurnOnLed2(void);
/*
功能：熄灭LED2
*/
void TurnOffLed2(void);

#endif

