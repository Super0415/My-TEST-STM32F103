#include "PWM.h"
#include "Systick.h"
#include "public.h"

//*********************************************************
//          PWM ��ʼ��
//*********************************************************
#if(Hardware==0)
void PWM_Init(void)
{
    //��ʱ�����ýṹ��
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO	
	TIM_OCInitTypeDef TIM_OCInitStructure;   //PWM ���ܽṹ�����
	
	//�򿪶�ʱ��3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);      //��ʱ��TIM3Ϊ��ͨʱ�ӣ�������APB1��
                         //��ʱ��	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);     //�ܽ�ʱ��     
	
    //�����ʱ���ж�	,��ֹ��ʼ��ʱ���жϱ�����
//    TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //���ʱ���ж�	     PWM�в�ʹ���ж�
//��ʱ�����ó�ʼ��
                                                      //ʹ��ϵͳʱ��72MHz
//    TIM_TimBaseInitStructure.TIM_Period = 2000;     //��ʱ����2000 = 72000000/36000      
//    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //Ԥ��Ƶ 36000
    
  TIM_TimBaseInitStructure.TIM_Period = 900;  //��ʱ����   72000000/1     1.   900��Ϊ����ARR  Ƶ��Ϊ 72000000/900=80K	
  TIM_TimBaseInitStructure.TIM_Prescaler = 0; //������Ԥ��Ƶ��
	TIM_TimBaseInitStructure.TIM_ClockDivision = 0;                  //��ʹ��ʱ���и�
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, & TIM_TimBaseInitStructure);                //ʹ�ö�ʱ��3
	
	//ӳ�� ��Tim3_2��ӳ�䵽PC7��LED�ƣ�   //@@@@@@@@@@ZC PE4
	GPIO_PinRemapConfig(GPIO_FullRemap_TIM3, ENABLE);
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;   //PWM ���ʹ�� ���ҹ̼���汾
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;       //���õ͵�ƽLED�������øߵ�ƽ��LED��
	TIM_OC2Init(TIM3, & TIM_OCInitStructure);             //TIM_OC2��Ϊ��ʱ��3�ĵڶ�ͨ��
//TIM_OC2ʹ��
    TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);   //ʹ�ܻ���ʧ��TIMx��CCR2�ϵ�Ԥװ�ؼĴ���
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

//	GPIO_SetBits(GPIOC,GPIO_Pin_7);	
	
//��ʱ��ʹ��	
	TIM_Cmd(TIM3, ENABLE);
//��ʱ���ж�ʹ��	
//	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );	             //  PWM�в�ʹ���ж�

}	

void PWM_LED(void)
{
	static u8 Directe = 1;
	static u32 SetNum = 0;
	delay_ms(10);
    if(Directe == 1)	
	{
	    SetNum++;
		if(SetNum > 200)
		{
		    Directe = 0;
		}
	}
	else
	{
	    SetNum--;
		if(SetNum == 0)
		{
		    Directe = 1;
		}
	}
    TIM_SetCompare2(TIM3, SetNum);		
}

#elif(Hardware == 4800) // GEC4800��·�� �ƹ� PE4  ������ͨ�˿ڱ�д

void PWM_Init(void)  
{
    //��ʱ�����ýṹ��
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO	
	NVIC_InitTypeDef NVIC_InitStructure;
	
	//�򿪶�ʱ��3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);      //��ʱ��TIM3Ϊ��ͨʱ�ӣ�������APB1��
  //��ʱ��	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);     //�ܽ�ʱ��
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //���ʱ���ж�	
                                                      //ʹ��ϵͳʱ��72MHz
//  TIM_TimBaseInitStructure.TIM_Period = 2000;     //��ʱ����2000 = 72000000/36000      
//  TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //Ԥ��Ƶ 36000	
	TIM_TimBaseInitStructure.TIM_Period = 719;  //��ʱ����  72M/(719+1)=100K  
	TIM_TimBaseInitStructure.TIM_Prescaler = 0; 
	TIM_TimBaseInitStructure.TIM_ClockDivision = 0;                  //��ʹ��ʱ���и�
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, & TIM_TimBaseInitStructure);                //ʹ�ö�ʱ��3
	//��ʱ��ʹ��	
	TIM_Cmd(TIM3, ENABLE);
	//��ʱ���ж�ʹ��	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //����
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;   //�жϺ������   TIM3_IRQn    //��TIM3
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //��Ӧ���ȼ�
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
	
	

//��ʱ���ж�ʹ��	
//	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );	             //  PWM�в�ʹ���ж�

}	




void PWM_LED(void)
{
	static u8 Directe = 1;
	static u32 SetNum = 0;
	delay_ms(10);
    if(Directe == 1)	
	{
	    SetNum++;
		if(SetNum > 200)
		{
		    Directe = 0;
		}
	}
	else
	{
	    SetNum--;
		if(SetNum == 0)
		{
		    Directe = 1;
		}
	}
    TIM_SetCompare2(TIM3, SetNum);		
}

#endif





