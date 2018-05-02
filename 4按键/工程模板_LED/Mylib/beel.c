#include "beel.h"
#include "public.h"

#define choose_Beel  0

void BeelInit(void )
{
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO

//	SystemInit();	//时钟初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOB,&GPIO_InitStructure); 	   /* 初始化GPIO */
	
    GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO口输出高电平
}


#if (choose_Beel == 1)
void Beel_display(void) 
{
	u32 i=6000;
	while(i--) //产生一段时间的PWM波，使蜂鸣器发声
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO口输出高电平
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO口输出低电平
		delay(i--);
	}
}
#elif (choose_Beel == 2)
void Beel_display(void)   //定时器闹钟
{
	u32 i=900000;

	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO口输出高电平
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO口输出低电平
		delay(i);
	}
}
#elif (choose_Beel == 3)
void Beel_display(void)   //定时器闹钟
{
	u32 i=9000000;

	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO口输出高电平
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO口输出低电平
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
	while(i--) //产生一段时间的PWM波，使蜂鸣器发声
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO口输出高电平
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO口输出低电平
		delay(i--);
	}
}

void Beel_display12(void)
{
	u32 i=900000;

	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO口输出高电平
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO口输出低电平
		delay(i);
	}
}

void Beel_display13(void)
{
	u32 i=9000000;

	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5); //IO口输出高电平
		delay(i);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5); //IO口输出低电平
		delay(i);
	}
}






