#include "stm32f10x.h"
#include "ALLApp.h"

#define choose_LED    1    //1-有效
#define choose_Beel   1    //1-有效

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
      led_display(); //led显示 
#endif	  
	  
#ifdef  choose_Beel	  
	  //Beel_display();   //选择编译
      Beel_display1(1);   //switch语句
#endif
  }


//  return 0;
}



