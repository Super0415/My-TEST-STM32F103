#ifndef _smg_H
#define _smg_H
#include "stm32f10x.h"
#include "systick.h"
#define tub1 GPIO_Pin_6	  //PF6~PF9
#define tub2 GPIO_Pin_7
#define tub3 GPIO_Pin_8
#define tub4 GPIO_Pin_9
#define smg_duan (GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7)//PC0~PC7 

void smg_init(void);//����ܳ�ʼ��
void smg_display(void);	 //�������ʾ����
void time_smg_run(void);	  //��ʱ�������������ʾ


extern u8 miao,fen;	//����ȫ�ֱ���
#endif
