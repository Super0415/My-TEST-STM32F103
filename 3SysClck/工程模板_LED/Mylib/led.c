#include "public.h"
#include "ALLApp.h"
void LEDInit(void )
{
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO

//	SystemInit();	//时钟初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* 初始化GPIO */

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
	GPIO_ResetBits(GPIOC,LED_SHOW1);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW1);
	GPIO_ResetBits(GPIOC,LED_SHOW2);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW2);
	GPIO_ResetBits(GPIOC,LED_SHOW3);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW3);
	GPIO_ResetBits(GPIOC,LED_SHOW4);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW4);
	GPIO_ResetBits(GPIOC,LED_SHOW5);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW5);
	GPIO_ResetBits(GPIOC,LED_SHOW6);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW6);
	GPIO_ResetBits(GPIOC,LED_SHOW7);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW7);
	GPIO_ResetBits(GPIOC,LED_SHOW8);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW8);
	GPIO_ResetBits(GPIOC,LED_SHOW9);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW9);
	GPIO_ResetBits(GPIOC,LED_SHOW0);	
	delay(6000000);//延时约为1s	
	GPIO_SetBits(GPIOC,LED_SHOW0);

}

void led_run_Systick(u32 timenum)
{
	int i = 0;
	for(i = 0;i < 8;i++)
	{
        //GPIO_Write(GPIOC,(u16)(0x01<<i));
		GPIO_Write(GPIOC,(u16)(0x01<<i)^0xFF);
		// 注意：2s延时不是delay_ms(2000);  M3中Systick为24位定时器即最大值为2^24 = 16777216 < 9000*2000  
		delay_ms(timenum); //1s延时  1000     		
    }
}





