#include "beel.h"
#include "public.h"

#define choose_Beel  0

void BeelInit(void )
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO

//	SystemInit();	//ʱ�ӳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOB,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
	
    GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO������ߵ�ƽ
}


#if (choose_Beel == 1)
void Beel_display(void) 
{
	u32 i=6000;
	while(i--) //����һ��ʱ���PWM����ʹ����������
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO������ߵ�ƽ
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO������͵�ƽ
		delay(i--);
	}
}
#elif (choose_Beel == 2)
void Beel_display(void)   //��ʱ������
{
	u32 i=900000;

	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO������ߵ�ƽ
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO������͵�ƽ
		delay(i);
	}
}
#elif (choose_Beel == 3)
void Beel_display(void)   //��ʱ������
{
	u32 i=9000000;

	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO������ߵ�ƽ
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO������͵�ƽ
		delay(i);
	}
}
#endif


void Beel_display1(unsigned point)
{
	switch(point)
	{
		case 1:
			Beel_display11();
		    break;
		case 2:
			Beel_display12();
		    break;
		case 3:
			Beel_display13();
		    break;

		default:
	        break;
			
	
	
	}
}

void Beel_display11(void)
{
	u32 i=6000;
	while(i--) //����һ��ʱ���PWM����ʹ����������
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO������ߵ�ƽ
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO������͵�ƽ
		delay(i--);
	}
}

void Beel_display12(void)
{
	u32 i=900000;

	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO������ߵ�ƽ
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO������͵�ƽ
		delay(i);
	}
}

void Beel_display13(void)
{
	u32 i=9000000;

	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO������ߵ�ƽ
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO������͵�ƽ
		delay(i);
	}
}






