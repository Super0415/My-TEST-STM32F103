#include "stm32f10x.h"
#include "led.h"
#include "Systick.h"
#include "usb.h"

// stm32f10x_lib  

int main(void)
{
	RCC_HSE_Configuration();   //注释此行时，采用默认配置及72MHz/8=9MHz  
  Init_LED();
	Init_usb();
	

	
	
  while(1)
  {
// 		led_display(); //led显示 
		TEST_usbloop();
  }


//  return 0;
}



