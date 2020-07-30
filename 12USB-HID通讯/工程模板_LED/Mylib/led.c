#include "led.h"
#include "Systick.h"

void delay(u32 i)	  
{
	while(i--);
}

void Init_LED(void )
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //ʹ��PB,PE�˿�ʱ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2;				 //LED0-->PB.5 �˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOB.5
	TurnOffLed1();
	TurnOnLed2();
}

/*
���ܣ�ȡ��LED1  // �̹�
*/
void ChangeLed1(void)
{
  GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction)(1-GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)));
}
/*
���ܣ�����LED1
*/
void TurnOnLed1(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);						
}

/*
���ܣ�Ϩ��LED1
*/
void TurnOffLed1(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);							
}
/*
���ܣ�ȡ��LED2	// ����
*/
void ChangeLed2(void)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_2, (BitAction)(1-GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)));
}
/*
���ܣ�����LED2
*/
void TurnOnLed2(void)
{	
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);						
}
/*
���ܣ�Ϩ��LED2
*/
void TurnOffLed2(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);				
}

void led_display(void)
{
		TurnOnLed1();
		TurnOnLed2();	
		delay_ms(500);//��ʱԼΪ0.5s
		TurnOffLed1();
		TurnOffLed2();
		delay_ms(500);//��ʱԼΪ0.5s	
}





