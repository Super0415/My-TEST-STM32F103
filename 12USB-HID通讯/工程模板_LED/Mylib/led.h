#ifndef _LED_H_
#define _LED_H_
#include "stm32f10x.h"

void delay(u32 i);
void Init_LED(void );
void led_display(void);

/*
���ܣ�ȡ��LED1  // �̹�
*/
void ChangeLed1(void);
/*
���ܣ�����LED1
*/
void TurnOnLed1(void);
/*
���ܣ�Ϩ��LED1
*/
void TurnOffLed1(void);
/*
���ܣ�ȡ��LED2	// ����
*/
void ChangeLed2(void);
/*
���ܣ�����LED2
*/
void TurnOnLed2(void);
/*
���ܣ�Ϩ��LED2
*/
void TurnOffLed2(void);

#endif

