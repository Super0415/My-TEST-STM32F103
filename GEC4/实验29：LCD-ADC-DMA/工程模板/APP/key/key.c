#include "key.h"
void key_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;

	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOE,ENABLE);

	GPIO_InitStructure.GPIO_Pin=K_UP;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//��������  //����ѡ�񸡿������������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=K_DOWN|K_LEFT|K_RIGHT;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	//��������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
				
	GPIO_ResetBits(GPIOA,K_UP);	//��K_UP��ʼ�����0
}
