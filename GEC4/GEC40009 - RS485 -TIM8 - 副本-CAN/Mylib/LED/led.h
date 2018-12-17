#ifndef __led_H
#define __led_H 

#include "stm32f10x_conf.h"

#define LED_GPIO_CLK     (RCC_APB2Periph_GPIOA  | RCC_APB2Periph_GPIOB  | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOE)

#define LED_PORT_STOP    GPIOE
#define LED_PIN_STOP     GPIO_Pin_5
#define LED_PORT_MAN     GPIOE
#define LED_PIN_MAN      GPIO_Pin_4
#define LED_PORT_AUTO    GPIOC
#define LED_PIN_AUTO     GPIO_Pin_12
#define LED_PORT_MCB     GPIOB
#define LED_PIN_MCB      GPIO_Pin_11
#define LED_PORT_ALARM   GPIOE
#define LED_PIN_ALARM    GPIO_Pin_4
#define LED_PORT_GCB     GPIOA
#define LED_PIN_GCB      GPIO_Pin_15


void LED_Init(void);

void LED_STOP_ON(void);
void LED_STOP_OFF(void);
void LED_STOP_Flick(void);

void LED_MAN_ON(void);
void LED_MAN_OFF(void);
void LED_MAN_Flick(void);

void LED_AUTO_ON(void);
void LED_AUTO_OFF(void);
void LED_AUTO_Flick(void);

void LED_ALARM_ON(void);
void LED_ALARM_OFF(void);
void LED_ALARM_Flick(void);

void LED_MCB_ON(void);
void LED_MCB_OFF(void);
void LED_MCB_Flick(void);

void LED_GCB_ON(void);
void LED_GCB_OFF(void);
void LED_GCB_Flick(void);

void LED_ALL_OFF(void);
void LED_ALL_Flick(void);

#endif



