#include "PWM.h"
#include "Systick.h"
#include "public.h"

//*********************************************************
//          PWM 初始化
//*********************************************************
#if(Hardware==0)
void PWM_Init(void)
{
    //定时器配置结构体
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO	
	TIM_OCInitTypeDef TIM_OCInitStructure;   //PWM 功能结构体变量
	
	//打开定时器3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);      //定时器TIM3为普通时钟，挂载在APB1上
                         //打开时钟	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);     //管脚时钟     
	
    //先清空时钟中断	,防止初始化时此中断被触发
//    TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除时钟中断	     PWM中不使用中断
//定时器配置初始化
                                                      //使用系统时钟72MHz
//    TIM_TimBaseInitStructure.TIM_Period = 2000;     //定时计数2000 = 72000000/36000      
//    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //预分频 36000
    
  TIM_TimBaseInitStructure.TIM_Period = 900;  //定时计数   72000000/1     1.   900即为周期ARR  频率为 72000000/900=80K	
  TIM_TimBaseInitStructure.TIM_Prescaler = 0; //不进行预分频，
	TIM_TimBaseInitStructure.TIM_ClockDivision = 0;                  //不使用时钟切割
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //向上计数模式
	TIM_TimeBaseInit(TIM3, & TIM_TimBaseInitStructure);                //使用定时器3
	
	//映射 从Tim3_2口映射到PC7（LED灯）   //@@@@@@@@@@ZC PE4
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //PWM 输出使能 查找固件库版本
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;       //配置低电平LED亮，配置高电平，LED灭
	TIM_OC2Init(TIM3, & TIM_OCInitStructure);             //TIM_OC2即为定时器3的第二通道
//TIM_OC2使能
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);   //使能或者失能TIMx在CCR2上的预装载寄存器
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* 初始化GPIO */

//	GPIO_SetBits(GPIOC,GPIO_Pin_7);	
	
//定时器使能	
	TIM_Cmd(TIM3, ENABLE);
//定时器中断使能	
//	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );	             //  PWM中不使用中断

}	

void PWM_LED(void)
{
	static u8 Directe = 1;
	static u32 SetNum = 0;
	delay_ms(10);
    if(Directe == 1)	
	{
	    SetNum++;
		if(SetNum > 200)
		{
		    Directe = 0;
		}
	}
	else
	{
	    SetNum--;
		if(SetNum == 0)
		{
		    Directe = 1;
		}
	}
    TIM_SetCompare2(TIM3, SetNum);		
}

#elif(Hardware == 4800) // GEC4800电路板 灯光 PE4  按照普通端口编写

void PWM_Init(void)  
{
    //定时器配置结构体
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO	
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//打开定时器3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);      //定时器TIM3为普通时钟，挂载在APB1上
  //打开时钟	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);     //管脚时钟
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除时钟中断	
                                                      //使用系统时钟72MHz
//  TIM_TimBaseInitStructure.TIM_Period = 2000;     //定时计数2000 = 72000000/36000      
//  TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //预分频 36000	
	TIM_TimBaseInitStructure.TIM_Period = 719;  //定时计数  72M/(719+1)=100K  
	TIM_TimBaseInitStructure.TIM_Prescaler = 0; 
	TIM_TimBaseInitStructure.TIM_ClockDivision = 0;                  //不使用时钟切割
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //向上计数模式
	TIM_TimeBaseInit(TIM3, & TIM_TimBaseInitStructure);                //使用定时器3
	//定时器使能	
	TIM_Cmd(TIM3, ENABLE);
	//定时器中断使能	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //分组
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;   //中断函数入口   TIM3_IRQn    //对TIM3
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //响应优先级
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;  //选择你要设置的IO口
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //设置推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* 初始化GPIO */
	
	

//定时器中断使能	
//	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );	             //  PWM中不使用中断

}	




void PWM_LED(void)
{
	static u8 Directe = 1;
	static u32 SetNum = 0;
	delay_ms(10);
    if(Directe == 1)	
	{
	    SetNum++;
		if(SetNum > 200)
		{
		    Directe = 0;
		}
	}
	else
	{
	    SetNum--;
		if(SetNum == 0)
		{
		    Directe = 1;
		}
	}
    TIM_SetCompare2(TIM3, SetNum);		
}

#endif





