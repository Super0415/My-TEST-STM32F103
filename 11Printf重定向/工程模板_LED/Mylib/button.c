#include "ALLApp.h"

void ButtonInit(void )
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO

//	SystemInit();	//ʱ�ӳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOA,ENABLE);

	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=KEY_LEFT|KEY_DOWN|KEY_RIGHT;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;	 //��������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //���ô�������
	GPIO_Init(GPIOE,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
	
	GPIO_InitStructure.GPIO_Pin=KEY_UP;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;	 //��������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz; //���ô�������
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */	
	
	GPIO_ResetBits(GPIOA,KEY_UP); //KEY_UP��ʼ�����0
	
}


/*******************************************************************************
* �� �� �� : key_pros
* �������� : �������������жϰ������¿��ƶ�Ӧ��LED��
* �� �� : ��
* �� �� : ��
* ˵ �� : �˴��������������ʱ��������׼ȷ�����Բ����жϷ�ʽ����
*******************************************************************************/
/*
#define KEY_UP     GPIO_Pin_0 //PA0 
#define KEY_DOWN   GPIO_Pin_3 //PE3
#define KEY_LEFT   GPIO_Pin_2 //PE2
#define KEY_RIGHT  GPIO_Pin_4 //PE4
*/

void key_pros()	  //����������
{
	if(KEY_State_Up==1)	  //�жϰ���k_up�Ƿ���
	{
		delay_ms(10); //��������
		if(KEY_State_Up==1)	 //�ٴ��жϰ���k_up�Ƿ���
		{
		//	GPIO_Write(GPIOC,(u16)0xfe);	

            GPIO_WriteBit(GPIOC,GPIO_Pin_0,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_0)))); 
			                                        //���ݵƹܽţ���ȡ�ϴε����ֵ����ȡ��
			//���ݵƹܽţ������ϴε����ֵ��ȡ��ֵ	
		}
		while(KEY_State_Up); //�ȴ������ɿ�
	}
	if(KEY_State_Down==0)
	{
		delay_ms(10);
		if(KEY_State_Down==0)
		{
		//	GPIO_Write(GPIOC,(u16)(0xfd));	
            GPIO_WriteBit(GPIOC,GPIO_Pin_1,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_1)))); 	
		}
		while(!KEY_State_Down);
	}
	if(KEY_State_Left==0)
	{
		delay_ms(10);
		if(KEY_State_Left==0)
		{
		//	GPIO_Write(GPIOC,(u16)(0xfb));	
            GPIO_WriteBit(GPIOC,GPIO_Pin_2,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_2)))); 			
		}
		while(!KEY_State_Left);
	}
	if(KEY_State_Right==0)
	{
		delay_ms(10);
		if(KEY_State_Right==0)
		{
		//	GPIO_Write(GPIOC,(u16)(0xf7));	
            GPIO_WriteBit(GPIOC,GPIO_Pin_3,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3)))); 			
		}
		while(!KEY_State_Right);
	}	
}





