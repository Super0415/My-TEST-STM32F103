#include "TIM.h"

//定时器初始化
void Tim_Init(void)
{

    //中断优先级结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	//定时器配置结构体
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	//打开定时器3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    //TIM3为普通时钟，挂载在APB1上

//先清空时钟中断	,防止初始化时此中断被触发
TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除时钟中断	
	
//定时器配置初始化
   //定时1秒	
                                                      //使用系统时钟72MHz
    TIM_TimBaseInitStructure.TIM_Period = 2000;     //定时计数2000 = 72000000/36000      
    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //预分频 36000

   //定时0.5秒	
                                                      //使用系统时钟72MHz
//    TIM_TimBaseInitStructure.TIM_Period = 1000;     //定时计数2000 = 72000000/36000     计数到2000才为1秒，重装值为1000，则耗时0.5秒  
//    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //预分频 36000	
	
	TIM_TimBaseInitStructure.TIM_ClockDivision = 0;                  //不使用时钟切割
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //向上计数模式
	TIM_TimeBaseInit(TIM3, & TIM_TimBaseInitStructure);                //使用定时器3
//定时器使能	
	TIM_Cmd(TIM3, ENABLE);
//定时器中断使能	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );
	
//*******************************************优先级设置*******************************************************************************************	
//注意:优先级设置必须一对一，逐个设置，不能“|”进行多个配置	

//设置NVIC参数	                                                                           
	/* Configure the Priority Grouping with 1 bit */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //分组
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;   //中断函数入口   TIM3_IRQn    //对TIM3
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		
//*******************************************优先级设置*******************************************************************************************


}



