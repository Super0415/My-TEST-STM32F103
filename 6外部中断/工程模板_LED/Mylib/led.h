#ifndef _LED_H_
#define _LED_H_
#include "stm32f10x.h"

#define LED_SHOW1   GPIO_Pin_1|GPIO_Pin_2
#define LED_SHOW2   GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_6|GPIO_Pin_4|GPIO_Pin_3
#define LED_SHOW3   GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_6
#define LED_SHOW4   GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_6
#define LED_SHOW5   GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_6
#define LED_SHOW6   GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7
#define LED_SHOW7   GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2
#define LED_SHOW8   GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7
#define LED_SHOW9   GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_5|GPIO_Pin_6
#define LED_SHOW0   GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_7

void delay(u32 i);
void LEDInit(void );
void led_display(void);
void led_run_Systick(u32 timenum);//LEDÑÝÊ¾systick

#endif

