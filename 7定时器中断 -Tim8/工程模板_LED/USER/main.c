#include "stm32f10x.h"
#include "ALLApp.h"

#define choose_TIM
int main(void)
{

  Tim3_Init();	          //定时器中断初始化
	Tim8_Init();	          //定时器中断初始化
	LEDInit();    //需要LED显示现象	

  while(1)
  {
	  
  }


//  return 0;
}



