#include "led.h"
#include "Systick.h"

void delay(u32 i)	  
{
	while(i--);
}

void Init_LED(void )
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PB,PE端口时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1|GPIO_Pin_2;				 //LED0-->PB.5 端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOB.5
	TurnOffLed1();
	TurnOnLed2();
}

/*
功能：取反LED1  // 绿光
*/
void ChangeLed1(void)
{
  GPIO_WriteBit(GPIOA, GPIO_Pin_1, (BitAction)(1-GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)));
}
/*
功能：点亮LED1
*/
void TurnOnLed1(void)
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);						
}

/*
功能：熄灭LED1
*/
void TurnOffLed1(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);							
}
/*
功能：取反LED2	// 蓝光
*/
void ChangeLed2(void)
{
	GPIO_WriteBit(GPIOA, GPIO_Pin_2, (BitAction)(1-GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_2)));
}
/*
功能：点亮LED2
*/
void TurnOnLed2(void)
{	
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);						
}
/*
功能：熄灭LED2
*/
void TurnOffLed2(void)
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);				
}

void led_display(void)
{
		TurnOnLed1();
		TurnOnLed2();	
		delay_ms(500);//延时约为0.5s
		TurnOffLed1();
		TurnOffLed2();
		delay_ms(500);//延时约为0.5s	
}





