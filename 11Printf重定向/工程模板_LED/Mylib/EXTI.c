#include "EXTI.h"

/*
#define KEY_UP     GPIO_Pin_0 //PA0 

#define KEY_DOWN   GPIO_Pin_3 //PE3
#define KEY_LEFT   GPIO_Pin_2 //PE2
#define KEY_RIGHT  GPIO_Pin_4 //PE4
*/


//ȡPE2�ж����
void exti_NVIC_Init(void)		//�����ⲿ�жϳ�ʼ��
{
	//�жϳ�ʼ���ṹ��
	EXTI_InitTypeDef EXTI_InitStructure;
    //�ж����ȼ��ṹ��
	NVIC_InitTypeDef NVIC_InitStructure;
//*******************************************���ŷ����ⲿ�ж�*********************************************************************************	
// 1.���ų�ʼ��
// 2.�������Ÿ��ù���
// 3.���ù���Ϊ�ⲿ�ж�
// ע��:ӳ���ϵ����һ��һ��������ã����ܡ�|�����ж������	
	
//����GPIO��ʼ��	
	ButtonInit();
//�����ܽŸ��ù��ܣ��޸Ĺܽ�ʱ��	  ��ʹ������IO��ʱ����Ҫ����ʹ���жϵȹ��ܣ����뿪�����ù���
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

//ѡ��GPIO�ܽ������ⲿ�ж���·	                                                             //&&&&ӳ���ϵ����һ��һ�������á�|�����ж������
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource2);  //ӳ�䵽�ⲿ�ж�2��3��4
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);  //ӳ�䵽�ⲿ�ж�2��3��4
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);  //ӳ�䵽�ⲿ�ж�2��3��4	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);  //ӳ�䵽�ⲿ�ж�0
//*******************************************���ŷ����ⲿ�ж�*********************************************************************************	
//*******************************************�ж�����*******************************************************************************************	
//	                                       �ж����ñȽ�����
//�¡�����	 �ж�����
	
    EXTI_InitStructure.EXTI_Line = EXTI_Line2|EXTI_Line3|EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);	
//��	�ж�����
    EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;	
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_InitStructure);
//*******************************************�ж�����*******************************************************************************************	
//*******************************************���ȼ�����*******************************************************************************************	
//ע��:���ȼ����ñ���һ��һ��������ã����ܡ�|�����ж������	

//����NVIC����	                                                                           
	/* Configure the Priority Grouping with 1 bit */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //����
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;   //�жϺ������               //EXTI2_IRQChannel  �汾��һ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	

	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;   //�жϺ������               //EXTI3_IRQChannel  �汾��һ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;   //�жϺ������               //EXTI4_IRQChannel  �汾��һ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;           //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;   //�жϺ������               //EXTI0_IRQChannel  �汾��һ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;           //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);		
//*******************************************���ȼ�����*******************************************************************************************	

}


