#include "stm32f10x.h"
#include "ALLApp.h"

//#define choose_LED    1    //1-有效   删除无效
//#define choose_Beel   1   
//#define choose_Systick   1
//#define choose_Button   1
#define choose_NVIC   1
int main(void)
{
#ifdef 	choose_LED
  LEDInit();
#endif

#ifdef  choose_Beel
  BeelInit();
#endif
#ifdef  choose_Systick	
	RCC_HSE_Configuration();    //注意试验现象，自定义配置不同，产生延时效果不同    //注释此行时，采用默认配置及72MHz/8=9MHz  
#endif	
#ifdef  choose_Button		
	ButtonInit();
#endif	
#ifdef  choose_NVIC	
    exti_NVIC_Init();		//按键外部中断初始化
	LEDInit();    //需要LED显示现象
#endif		
  while(1)
  {
#ifdef 	choose_LED	  
      led_display(); //led显示 
#endif	  
	  
#ifdef  choose_Beel	  
	  //Beel_display();   //选择编译
      Beel_display1(1);   //switch语句
#endif

#ifdef  choose_Systick		  
	  led_run_Systick(1000);//LED延时systick功能--1s	  
#endif	
#ifdef  choose_Button		
	key_pros();
#endif	
	  
	  
  }


//  return 0;
}



