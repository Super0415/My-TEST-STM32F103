#include "stm32f10x.h"
#include "ALLApp.h"

#define choose_LED    1    //1-��Ч   ɾ����Ч
//#define choose_Beel   1    //1-��Ч   ɾ����Ч
#define choose_Systick   1
int main(void)
{
#ifdef 	choose_LED
  LEDInit();
#endif

#ifdef  choose_Beel
  BeelInit();
#endif
#ifdef  choose_Systick	
	RCC_HSE_Configuration();   //ע�����������Զ������ò�ͬ��������ʱЧ����ͬ    //ע�ʹ���ʱ������Ĭ�����ü�72MHz/8=9MHz    
#endif	
  while(1)
  {
#ifdef 	choose_LED	  
   //   led_display(); //led��ʾ 
#endif	  
	  
#ifdef  choose_Beel	  
	  //Beel_display();   //ѡ�����
      Beel_display1(1);   //switch���
#endif

#ifdef  choose_Systick		  
	  led_run_Systick(1000);//LED��ʱsystick����--1s	  
#endif	  
	  
  }


//  return 0;
}



