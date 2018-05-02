#include "stm32f10x.h"
#include "ALLApp.h"

//#define choose_LED    1    //1-��Ч   ɾ����Ч
//#define choose_Beel   1   
//#define choose_Systick   1
//#define choose_Button   1
//#define choose_NVIC   1
//#define choose_TIM   1
//#define choose_PWM   1
#define choose_USART232  1

int main(void)
{
#ifdef 	choose_LED
  LEDInit();
#endif

#ifdef  choose_Beel
  BeelInit();
#endif
#ifdef  choose_Systick	
	LEDInit();
	RCC_HSE_Configuration();    //ע�����������Զ������ò�ͬ��������ʱЧ����ͬ    //ע�ʹ���ʱ������Ĭ�����ü�72MHz/8=9MHz  
#endif	
#ifdef  choose_Button		
	ButtonInit();
#endif	
#ifdef  choose_NVIC	
    exti_NVIC_Init();		//�����ⲿ�жϳ�ʼ��
	LEDInit();    //��ҪLED��ʾ����
#endif	
#ifdef  choose_TIM	
    Tim_Init();	          //��ʱ���жϳ�ʼ��
	LEDInit();    //��ҪLED��ʾ����	
#endif	
#ifdef  choose_PWM	
    PWM_Init();//PWM��ʼ��
#endif	
#ifdef  choose_USART232
    USART232_Init();
#endif
  while(1)
  {
#ifdef 	choose_LED	  
      led_display(); //led��ʾ 
#endif	  
	  
#ifdef  choose_Beel	  
	  //Beel_display();   //ѡ�����
      Beel_display1(1);   //switch���
#endif

#ifdef  choose_Systick		  
	  led_run_Systick(1000);//LED��ʱsystick����--1s	  
#endif	
#ifdef  choose_Button		
	key_pros();
#endif	
#ifdef  choose_PWM		  
	PWM_LED();
#endif		  
	  
  }


//  return 0;
}



