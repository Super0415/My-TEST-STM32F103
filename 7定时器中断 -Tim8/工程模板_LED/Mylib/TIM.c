#include "TIM.h"

//??????
void Tim_Init(void)
{

    //????????
	NVIC_InitTypeDef NVIC_InitStructure;
	//????????
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	//?????3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    //TIM3?????,???APB1?

//???????	,????????????
TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //??????	
	
//????????
   //??1?	
                                                      //??????72MHz
    TIM_TimBaseInitStructure.TIM_Period = 2000;     //????2000 = 72000000/36000      
    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //??? 36000

   //??0.5?	
                                                      //??????72MHz
//    TIM_TimBaseInitStructure.TIM_Period = 1000;     //????2000 = 72000000/36000     ???2000??1?,????1000,???0.5?  
//    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //??? 36000	
	
	TIM_TimBaseInitStructure.TIM_ClockDivision =  TIM_CKD_DIV1;                  //???????
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //??????
	TIM_TimeBaseInit(TIM3, & TIM_TimBaseInitStructure);                //?????3
//?????	
	TIM_Cmd(TIM3, ENABLE);
//???????	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );
	
//*******************************************?????*******************************************************************************************	
//??:??????????,????,??�|�??????	

//??NVIC??	                                                                           
	/* Configure the Priority Grouping with 1 bit */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //??
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;   //??????   TIM3_IRQn    //?TIM3
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //?????
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //?????
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		
//*******************************************?????*******************************************************************************************


}

//��ʱ����ʼ��
void Tim3_Init(void)
{

    //�ж����ȼ��ṹ��
	NVIC_InitTypeDef NVIC_InitStructure;
	//��ʱ�����ýṹ��
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	//�򿪶�ʱ��3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    //TIM3Ϊ��ͨʱ�ӣ�������APB1��

//�����ʱ���ж�	,��ֹ��ʼ��ʱ���жϱ�����
TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //���ʱ���ж�	
	
//��ʱ�����ó�ʼ��
   //��ʱ1��	
                                                      //ʹ��ϵͳʱ��72MHz
    TIM_TimBaseInitStructure.TIM_Period = 2000;     //��ʱ����2000 = 72000000/36000      
    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //Ԥ��Ƶ 36000

   //��ʱ0.5��	
                                                      //ʹ��ϵͳʱ��72MHz
//    TIM_TimBaseInitStructure.TIM_Period = 1000;     //��ʱ����2000 = 72000000/36000     ������2000��Ϊ1�룬��װֵΪ1000�����ʱ0.5��  
//    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //Ԥ��Ƶ 36000	
	
	TIM_TimBaseInitStructure.TIM_ClockDivision =  TIM_CKD_DIV1;                  //��ʹ��ʱ���и�
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, & TIM_TimBaseInitStructure);                //ʹ�ö�ʱ��3
//��ʱ��ʹ��	
	TIM_Cmd(TIM3, ENABLE);
//��ʱ���ж�ʹ��	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );
	
//*******************************************���ȼ�����*******************************************************************************************	
//ע��:���ȼ����ñ���һ��һ��������ã����ܡ�|�����ж������	

//����NVIC����	                                                                           
	/* Configure the Priority Grouping with 1 bit */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //����
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;   //�жϺ������   TIM3_IRQn    //��TIM3
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;           //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		
//*******************************************���ȼ�����*******************************************************************************************


}


//��ʱ����ʼ��
void Tim8_Init(void)
{

    //�ж����ȼ��ṹ��
	NVIC_InitTypeDef NVIC_InitStructure;
	//��ʱ�����ýṹ��
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	//�򿪶�ʱ��3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);    //TIM3Ϊ��ͨʱ�ӣ�������APB1��

//�����ʱ���ж�	,��ֹ��ʼ��ʱ���жϱ�����
TIM_ClearITPendingBit(TIM8,TIM_IT_Update);  //���ʱ���ж�	
	
//��ʱ�����ó�ʼ��
   //��ʱ1��	
                                                      //ʹ��ϵͳʱ��72MHz
    TIM_TimBaseInitStructure.TIM_Period = 2000;     //��ʱ����2000 = 72000000/36000      
    TIM_TimBaseInitStructure.TIM_Prescaler = 71999; //Ԥ��Ƶ 72000

   //��ʱ0.5��	
                                                      //ʹ��ϵͳʱ��72MHz
//    TIM_TimBaseInitStructure.TIM_Period = 1000;     //��ʱ����2000 = 72000000/36000     ������2000��Ϊ1�룬��װֵΪ1000�����ʱ0.5��  
//    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //Ԥ��Ƶ 36000	
	
	TIM_TimBaseInitStructure.TIM_ClockDivision = 0;                  //��ʹ��ʱ���и�
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM8, & TIM_TimBaseInitStructure);                //ʹ�ö�ʱ��3
//��ʱ��ʹ��	
	TIM_Cmd(TIM8, ENABLE);
//��ʱ���ж�ʹ��	
	TIM_ITConfig(TIM8, TIM_IT_Update, ENABLE );
	
//*******************************************���ȼ�����*******************************************************************************************	
//ע��:���ȼ����ñ���һ��һ��������ã����ܡ�|�����ж������	

//����NVIC����	                                                                           
	/* Configure the Priority Grouping with 1 bit */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //����
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_IRQn;   //�жϺ������   TIM3_IRQn    //��TIM3
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		
//*******************************************���ȼ�����*******************************************************************************************


}



