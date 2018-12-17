/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

#include <stdio.h>

int main(void)
{
	int num = 0;
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);             //PB8   输出口1-继电器动作
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOE, &GPIO_InitStructure);             //PE4   灯
	
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_8);
		GPIO_SetBits(GPIOE,GPIO_Pin_4);
	    num = 30000000;
        while(--num);
	  GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		GPIO_ResetBits(GPIOE,GPIO_Pin_4);
	    num = 30000000;
        while(--num);
	
	}	
	
	;


 //   return 0;
}

