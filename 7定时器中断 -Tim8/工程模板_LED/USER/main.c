#include "stm32f10x.h"
#include "ALLApp.h"

#define choose_TIM
int main(void)
{

  Tim3_Init();	          //��ʱ���жϳ�ʼ��
	Tim8_Init();	          //��ʱ���жϳ�ʼ��
	LEDInit();    //��ҪLED��ʾ����	

  while(1)
  {
	  
  }


//  return 0;
}



