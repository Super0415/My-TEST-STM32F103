#include "stm32f10x.h"
#include "led.h"


int main(void)
{
  LEDInit();
  while(1)
  {
 		led_display(); //ledœ‘ æ 
  
  }


//  return 0;
}



