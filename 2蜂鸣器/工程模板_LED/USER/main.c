#include "stm32f10x.h"
#include "ALLApp.h"

#define choose_LED    1    //1-��Ч
#define choose_Beel   1    //1-��Ч

int main(void)
{
#ifdef 	choose_LED
  LEDInit();
#endif

#ifdef  choose_Beel
  BeelInit();
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
  }


//  return 0;
}



