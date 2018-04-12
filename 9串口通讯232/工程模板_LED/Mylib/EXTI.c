#include "EXTI.h"

/*
#define KEY_UP     GPIO_Pin_0 //PA0 

#define KEY_DOWN   GPIO_Pin_3 //PE3
#define KEY_LEFT   GPIO_Pin_2 //PE2
#define KEY_RIGHT  GPIO_Pin_4 //PE4
*/


//取PE2中断输出
void exti_NVIC_Init(void)		//按键外部中断初始化
{
	//中断初始化结构体
	EXTI_InitTypeDef EXTI_InitStructure;
    //中断优先级结构体
	NVIC_InitTypeDef NVIC_InitStructure;
//*******************************************引脚分配外部中断*********************************************************************************	
// 1.引脚初始化
// 2.开启引脚复用功能
// 3.复用功能为外部中断
// 注意:映射关系必须一对一，逐个设置，不能“|”进行多个配置	
	
//按键GPIO初始化	
	ButtonInit();
//开启管脚复用功能，修改管脚时钟	  ，使用正常IO口时，如要另外使用中断等功能，必须开启复用功能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

//选择GPIO管脚用作外部中断线路	                                                             //&&&&映射关系必须一对一，不能用“|”进行多个配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);  //映射到外部中断2、3、4
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);  //映射到外部中断2、3、4
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);  //映射到外部中断2、3、4	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);  //映射到外部中断0
//*******************************************引脚分配外部中断*********************************************************************************	
//*******************************************中断配置*******************************************************************************************	
//	                                       中断配置比较随意
//下、左、右	 中断配置
	
    EXTI_InitStructure.EXTI_Line = EXTI_Line2|EXTI_Line3|EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	
//上	中断配置
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
//*******************************************中断配置*******************************************************************************************	
//*******************************************优先级设置*******************************************************************************************	
//注意:优先级设置必须一对一，逐个设置，不能“|”进行多个配置	

//设置NVIC参数	                                                                           
	/* Configure the Priority Grouping with 1 bit */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //分组
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;   //中断函数入口               //EXTI2_IRQChannel  版本不一样
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;   //中断函数入口               //EXTI3_IRQChannel  版本不一样
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;   //中断函数入口               //EXTI4_IRQChannel  版本不一样
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;           //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;   //中断函数入口               //EXTI0_IRQChannel  版本不一样
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;           //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);		
//*******************************************优先级设置*******************************************************************************************	

}


