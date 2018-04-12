#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "stm32f10x.h"

//����ܽ�
#define KEY_UP     GPIO_Pin_0 //PA0 
#define KEY_DOWN   GPIO_Pin_3 //PE3
#define KEY_LEFT   GPIO_Pin_2 //PE2
#define KEY_RIGHT  GPIO_Pin_4 //PE4
//��ȡ״̬
#define KEY_State_Up    GPIO_ReadInputDataBit(GPIOA,KEY_UP)
#define KEY_State_Down  GPIO_ReadInputDataBit(GPIOE,KEY_DOWN)
#define KEY_State_Left  GPIO_ReadInputDataBit(GPIOE,KEY_LEFT)
#define KEY_State_Right GPIO_ReadInputDataBit(GPIOE,KEY_RIGHT)



void ButtonInit(void );  //��ʼ��
void key_pros(void); //����������

#endif
