#include "TYPCortex.h"


u32    TimerEnArr[TMR_NUM];
u32    TimerTrig[TMR_NUM];
u32    TimerValue[TMR_NUM];
u32    TimerSet[TMR_NUM];
u32    TimerMode[TMR_NUM];

void Timer_FlickDelLogicUse()
{
    static unsigned short int FLG_200MS;
    static unsigned short int FLG_300MS;
    static unsigned short int FLG_500MS;
  /*  static unsigned short int FLG_1S;   
    static unsigned short int FLG_30S;  
    static unsigned short int FLG_1MIN; 
    static unsigned short int FLG_30MIN;
    static unsigned short int FLG_1HOUR;
	*/
    FLG_200MS++;
    FLG_300MS++;
    FLG_500MS++;
  /*  FLG_1S++;   
    FLG_30S++;  
    FLG_1MIN++; 
    FLG_30MIN++;
    FLG_1HOUR++;
   */
    if(TIME_STAMP_100MS==1)
    {
        TIME_STAMP_100MS=0;
    }
    else
    {
        TIME_STAMP_100MS=1;
    }
    
    if(FLG_200MS>=2)    
    {
        if(TIME_STAMP_200MS==1)
        {
            TIME_STAMP_200MS=0;
        }
        else
        {
            TIME_STAMP_200MS=1;
        }
        FLG_200MS=0;
    }
    
    if(FLG_300MS>=3)    
    {
        if(TIME_STAMP_300MS==1)
        {
            TIME_STAMP_300MS=0;
        }
        else
        {
            TIME_STAMP_300MS=1;
        }
        FLG_300MS=0;
    }

    if(FLG_500MS>=5)    
    {
        if(TIME_STAMP_500MS==1)
        {
            TIME_STAMP_500MS=0;
        }
        else
        {
            TIME_STAMP_500MS=1;
        }
        FLG_500MS=0; 
    }
  /*  
    if(FLG_1S>=10)    
    {
        if(TIME_STAMP_1S==1)
        {
            TIME_STAMP_1S=0;
        }
        else
        {
            TIME_STAMP_1S=1;
        }
        FLG_1S=0;
    }  
  
    if(FLG_30S>=300)    
    {
        if(TIME_STAMP_30S==1)
        {
            TIME_STAMP_30S=0;
        }
        else
        {
            TIME_STAMP_30S=1;
        }
        FLG_30S=0;
    } 
     
    if(FLG_1MIN>=600)    
    {
        if(TIME_STAMP_1MIN==1)
        {
            TIME_STAMP_1MIN=0;
        }
        else
        {
            TIME_STAMP_1MIN=1;
        }
        FLG_1MIN=0;
    }    
  
    if(FLG_30MIN>=18000)    
    {
        if(TIME_STAMP_30MIN==1)
        {
            TIME_STAMP_30MIN=0;
        }
        else
        {
            TIME_STAMP_30MIN=1;
        }
        FLG_30MIN=0;
    }  
    
    if(FLG_1HOUR>=36000)    
    {
        if(TIME_STAMP_1HOUR==1)
        {
            TIME_STAMP_1HOUR=0;
        }
        else
        {
            TIME_STAMP_1HOUR=1;
        }
        FLG_1HOUR=0;
    }
	*/
}

/*
 * ��������TimingDelay_Decrement
 * ����  ����ȡ���ĳ���
 * ����  ����
 * ���  ����
 * ����  ���� SysTick �жϺ��� SysTick_Handler()����
*/ 

void TimingDelay_Decrement_a(void)
{
	u8 i;
	
	for (i = 0; i < TMR_NUM; i++)   
    {
        if(TimerEnArr[i] == 1)
        {
            if(TimerValue[i]<TimerSet[i])TimerValue[i]++;

            if (TimerValue[i] >= TimerSet[i])
            {
                if (TimerMode[i] <= 1)
                {
                    TimerValue[i] = 0;
                    TimerEnArr[i] = TimerMode[i];
                }
                else
                {
                    TimerEnArr[i] = 0;
                }
               TimerTrig[i] = 1;
            }
        }
        else
        {
            if(TimerMode[i]!=2)
            {          
                TimerValue[i] = 0;
            }
        }
    }
}

void TimingDelay_Decrement(void)
{
  if(Timer_Mcon>=50)   //100MS����һ��
  {
   Timer_Mcon=0;
   TimingDelay_Decrement_a();
   Timer_FlickDelLogicUse();
  }
}



/*
 * ��������TIM2_NVIC_Configuration
 * ����  ��TIM2�ж����ȼ�����
 * ����  ����
 * ���  ����	
 */
void TIM2_NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    
   													
    NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;	  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;	  //3
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

void Delay_CHtim2Period(u16 CHPeriod)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;     
	  TIM_TimeBaseStructure.TIM_Period=CHPeriod-1;		 					  /* �Զ���װ�ؼĴ������ڵ�ֵ(����ֵ) */
  /* �ۼ� TIM_Period��Ƶ�ʺ����һ�����»����ж� */
    TIM_TimeBaseStructure.TIM_Prescaler= (SYS_FreqSYSCLK - 1);/* ʱ��Ԥ��Ƶ�� 72M/72 */
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		/* ������Ƶ */
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; /* ���ϼ���ģʽ */
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

}

/*TIM_Period--625   TIM_Prescaler--71 -->�ж�����Ϊ0.2ms--50hz*/
void TIM2_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2 , ENABLE);
    TIM_DeInit(TIM2);
    TIM_TimeBaseStructure.TIM_Period=625-1;		 								  
    TIM_TimeBaseStructure.TIM_Prescaler= (SYS_FreqSYSCLK - 1);				    
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	//  Delay_CHtim2Period(625);
    TIM_ClearFlag(TIM2, TIM_FLAG_Update);							    		/* �������жϱ�־ */
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
    TIM_Cmd(TIM2, ENABLE);																		/* ����ʱ�� */
    
}

void TIM2_PITTIMER_Cfig(void)
{
	TIM2_NVIC_Configuration();
	TIM2_Configuration();
}


	
/**
  * @brief  This function handles TIM2 interrupt request.
  * @param  None
  * @retval : None
  */
void TIM2_IRQHandler_it(void)
{
	if ( TIM_GetITStatus(TIM2 , TIM_IT_Update) != RESET ) 
	{	
		TIM_ClearITPendingBit(TIM2 , TIM_FLAG_Update);    
		CAL_GEN_MAINVOL();
	}		 	
}

/*
 * ��������TIM4_NVIC_Configuration
 * ����  ��TIM4�ж����ȼ�����
 * ����  ����
 * ���  ����	
 */
void TIM4_NVIC_Configuration(void)
{
    NVIC_InitTypeDef NVIC_InitStructure; 
    
//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);  													
    NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;	  
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;	//4  5
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
}

/*TIM_Period--2000   TIM_Prescaler--71 -->�ж�����Ϊ2ms*/
void TIM4_Configuration(void)
{
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4 , ENABLE);
    TIM_DeInit(TIM4);
    TIM_TimeBaseStructure.TIM_Period=2000-1;		 								  
    TIM_TimeBaseStructure.TIM_Prescaler= (SYS_FreqSYSCLK - 1);				    
    TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 		
    TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; 
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
    TIM_ClearFlag(TIM4, TIM_FLAG_Update);							    		/* �������жϱ�־ */
    TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);
    TIM_Cmd(TIM4, ENABLE);																		/* ����ʱ�� */
    
}
/**
  * @brief  This function handles TIM4 interrupt request.
  * @param  None
  * @retval : None
  */
void TIM4_IRQHandler_it(void)
{
	if ( TIM_GetITStatus(TIM4 , TIM_IT_Update) != RESET ) 
	{	
		TIM_ClearITPendingBit(TIM4 , TIM_FLAG_Update);    
	  Timer_Mcon++;         //ʱ�����������
	  TimingDelay_Decrement();  //ʱ�����
	}		 	
}
//----------------------------------------------------
//	   TIM4_TIMER_Config(void)
//��ͨ��ʱ������ͨ��ʱ
//----------------------------------------------------
void TIM4_TIMER_Config(void)
{
	TIM4_NVIC_Configuration();
	TIM4_Configuration();
}

