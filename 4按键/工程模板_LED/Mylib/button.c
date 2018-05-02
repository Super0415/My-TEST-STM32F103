#include "ALLApp.h"

void ButtonInit(void )
{
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO

//	SystemInit();	//时钟初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOA,ENABLE);

	/*  配置GPIO的模式和IO口 */
	GPIO_InitStructure.GPIO_Pin=KEY_LEFT|KEY_DOWN|KEY_RIGHT;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	 //设置上拉模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //设置传输速率
	GPIO_Init(GPIOE,&GPIO_InitStructure); 	   /* 初始化GPIO */
	
	GPIO_InitStructure.GPIO_Pin=KEY_UP;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;	 //设置下拉模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //设置传输速率
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* 初始化GPIO */	
	
	GPIO_ResetBits(GPIOA,KEY_UP); //KEY_UP初始化输出0
	
}


/*******************************************************************************
* 函 数 名 : key_pros
* 函数功能 : 按键处理函数，判断按键按下控制对应的LED灯
* 输 入 : 无
* 输 出 : 无
* 说 明 : 此处消抖处理采用延时处理，不够准确，可以采用中断方式处理
*******************************************************************************/
/*
#define KEY_UP     GPIO_Pin_0 //PA0 
#define KEY_DOWN   GPIO_Pin_3 //PE3
#define KEY_LEFT   GPIO_Pin_2 //PE2
#define KEY_RIGHT  GPIO_Pin_4 //PE4
*/

void key_pros()	  //按键处理函数
{
	if(KEY_State_Up==1)	  //判断按键k_up是否按下
	{
		delay_ms(10); //消抖处理
		if(KEY_State_Up==1)	 //再次判断按键k_up是否按下
		{
		//	GPIO_Write(GPIOC,(u16)0xfe);	

            GPIO_WriteBit(GPIOC,GPIO_Pin_0,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_0)))); 
			                                        //根据灯管脚，读取上次灯输出值，再取反
			//根据灯管脚，输入上次灯输出值的取反值	
		}
		while(KEY_State_Up); //等待按键松开
	}
	if(KEY_State_Down==0)
	{
		delay_ms(10);
		if(KEY_State_Down==0)
		{
		//	GPIO_Write(GPIOC,(u16)(0xfd));	
            GPIO_WriteBit(GPIOC,GPIO_Pin_1,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_1)))); 	
		}
		while(!KEY_State_Down);
	}
	if(KEY_State_Left==0)
	{
		delay_ms(10);
		if(KEY_State_Left==0)
		{
		//	GPIO_Write(GPIOC,(u16)(0xfb));	
            GPIO_WriteBit(GPIOC,GPIO_Pin_2,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_2)))); 			
		}
		while(!KEY_State_Left);
	}
	if(KEY_State_Right==0)
	{
		delay_ms(10);
		if(KEY_State_Right==0)
		{
		//	GPIO_Write(GPIOC,(u16)(0xf7));	
            GPIO_WriteBit(GPIOC,GPIO_Pin_3,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3)))); 			
		}
		while(!KEY_State_Right);
	}	
}





