#include "public.h"
#include "Systick.h"
//******************************************************************
//使用Cortex-M3中systick时钟下的微秒函数
//******************************************************************
void delay_us(u32 i)
{
	u32 temp;
	SysTick->LOAD=9*i;		 //设置重装数值, 72MHZ时
	SysTick->CTRL=0X01;		 //使能，减到零是无动作，采用外部时钟源
	SysTick->VAL=0;		   	 //清零计数器
	do
	{
		temp=SysTick->CTRL;		   //读取当前倒计数值
	}
	while((temp&0x01)&&(!(temp&(1<<16))));	 //等待时间到达                            
	SysTick->CTRL=0;	//关闭计数器
	SysTick->VAL=0;		//清空计数器
}
//******************************************************************
//使用Cortex-M3中systick时钟下的毫秒函数
//M3中Systick为24位定时器即最大值为2^24 = 16777216
//******************************************************************
void delay_ms(u32 i)
{
	u32 temp;
	SysTick->LOAD=9000*i;	  //设置重装数值, 72MHZ时
	SysTick->CTRL=0X01;		//使能，减到零是无动作，采用外部时钟源
	SysTick->VAL=0;			//清零计数器
	do
	{
		temp=SysTick->CTRL;	   //读取当前倒计数值
	}
	while((temp&0x01)&&(!(temp&(1<<16))));	//等待时间到达
	SysTick->CTRL=0;	//关闭计数器
	SysTick->VAL=0;		//清空计数器
}

//******************************************************************
//* 函 数 名: RCC_HSE_Configuration
//* 函数功能: 自定义系统时钟，可以通过修改PLL时钟源和倍频系数实现时钟调整
//* 输    入: 无
//* 输    出: 无
//******************************************************************
void RCC_HSE_Configuration(void) //自定义系统时间（可以修改时钟）
{
	RCC_DeInit(); //将外设RCC寄存器重设为缺省值
	RCC_HSEConfig(RCC_HSE_ON);//设置外部高速晶振（HSE）
	if(RCC_WaitForHSEStartUp()==SUCCESS) //等待HSE起振
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//设置AHB时钟（HCLK）
		RCC_PCLK1Config(RCC_HCLK_Div2);//设置低速AHB时钟（PCLK1）
		RCC_PCLK2Config(RCC_HCLK_Div1);//设置高速AHB时钟（PCLK2）
	    //RCC_PLLSource_HSE_Div2 进行了2分频，即72/8/2 = 4.5MHz  , RCC_PLLMul_9  预分频为9，   即4.5MHz/9
	    //此时delay_ms(1000); //2s延时 
		//试验现象表明，此设置延时为delay_ms(1000)为2s
		//RCC_PLLConfig(RCC_PLLSource_HSE_Div2,RCC_PLLMul_9);//设置PLL时钟源（PLL的输入时钟 = HSE时钟频率）及倍频系数
		//试验现象表明，此设置延时为delay_ms(1000)为1s
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);//设置PLL时钟源（PLL的输入时钟 = HSE时钟频率）及倍频系数
		
		RCC_PLLCmd(ENABLE); //使能或者失能PLL
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//检查指定的RCC标志位设置与否,PLL就绪
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//设置系统时钟（SYSCLK）
		while(RCC_GetSYSCLKSource()!=0x08);//返回用作系统时钟的时钟源,0x08：PLL作为系统时钟
	}
}

