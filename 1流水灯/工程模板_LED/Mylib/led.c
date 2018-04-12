#include "led.h"

void delay(u32 i)	  
{
	while(i--);
}

void LEDInit(void )
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO

//	SystemInit();	//ʱ�ӳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

	GPIO_SetBits(GPIOC,GPIO_Pin_All);
}


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
void led_display(void)
{
//	GPIO_SetBits(GPIOC,LED_SHOW1);
//	delay(6000000);//��ʱԼΪ1s
//	GPIO_ResetBits(GPIOC,LED_SHOW1);
//	delay(6000000);
	
	
GPIO_ResetBits(GPIOC,LED_SHOW1);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW1);
GPIO_ResetBits(GPIOC,LED_SHOW2);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW2);
GPIO_ResetBits(GPIOC,LED_SHOW3);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW3);
GPIO_ResetBits(GPIOC,LED_SHOW4);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW4);
GPIO_ResetBits(GPIOC,LED_SHOW5);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW5);
GPIO_ResetBits(GPIOC,LED_SHOW6);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW6);
GPIO_ResetBits(GPIOC,LED_SHOW7);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW7);
GPIO_ResetBits(GPIOC,LED_SHOW8);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW8);
GPIO_ResetBits(GPIOC,LED_SHOW9);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW9);
GPIO_ResetBits(GPIOC,LED_SHOW0);	
delay(6000000);//��ʱԼΪ1s	
GPIO_SetBits(GPIOC,LED_SHOW0);
	
	
	
}





