#include "beep.h"
void BEEP_Init()	  //�˿ڳ�ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;

	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	GPIO_InitStructure.GPIO_Pin=BZ;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure); 	
}
void sound1()  //�Ȼ�������
{
	u32 i=5000;
	while(i--)
	{
		GPIO_SetBits(GPIOB,BZ);
		delay(i);
		GPIO_ResetBits(GPIOB,BZ);
		delay(i--);
	}	
}
void sound2()  //�綯������
{
	u32 i=1000;
	while(i--)
	{
		GPIO_SetBits(GPIOB,BZ);
		delay(i);
		GPIO_ResetBits(GPIOB,BZ);
		delay(i--);
	}	
}

