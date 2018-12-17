#include "rtc.h"
u8 timebz;
void rtc_init()
{
   	NVIC_InitTypeDef NVIC_InitStructure; 

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);//�򿪵�Դʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);//�򿪴洢��ʱ��

	PWR_BackupAccessCmd(ENABLE);//ʹ�ܻ���ʧ��RTC�ͺ󱸼Ĵ�������
	BKP_DeInit();//������BKP��ȫ���Ĵ�������Ϊȱʡֵ
	RCC_LSEConfig(RCC_LSE_ON);//�����ⲿ���پ���LSE��
	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY)==RESET);//���ָ����RCC��־λ�������
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);//����RTCʱ�ӣ�RTCCLK��
	RCC_RTCCLKCmd(ENABLE);//ʹ�ܻ���ʧ��RTCʱ��
	RTC_WaitForSynchro(); //�ȴ�RTC�Ĵ���ͬ��
	RTC_WaitForLastTask();//�ȴ����һ�ζ�RTC�Ĵ�����д�������
	RTC_ITConfig(RTC_IT_SEC,ENABLE);//ʹ�ܻ���ʧ��ָ����RTC�ж�
	RTC_WaitForLastTask();//�ȴ����һ�ζ�RTC�Ĵ�����д�������
	RTC_SetPrescaler(32767);//����Ԥ��Ƶ ʹ���ⲿ����Ϊ32.768K��Ҫ��1s�ж���Ԥ��Ƶ������Ϊ32767��ϵͳ���ڴ����ֻ����ϼ�1
	RTC_WaitForLastTask();//�ȴ����һ�ζ�RTC�Ĵ�����д�������
	

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 
	NVIC_InitStructure.NVIC_IRQChannel = RTC_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
	
		
}

void clockinit_RTC()
{
	if(BKP_ReadBackupRegister(BKP_DR1)!=0XA5A5)//��ָ���ĺ󱸼Ĵ����ж�������
	{
		//��һ������  ��ʼ������
		//RTC��ʼ��
		rtc_init();
		RTC_WaitForLastTask();//�ȴ����һ�ζ�RTC�Ĵ�����д�������
		RTC_SetCounter(0x9f92);//����RTC��������ֵ 11:20��50
		RTC_WaitForLastTask();
		BKP_WriteBackupRegister(BKP_DR1,0xA5A5);
	}
	else
	{	
		RTC_WaitForSynchro();//�ȴ�RTC�Ĵ���ͬ��	
		RTC_WaitForLastTask();//�ȴ�дRTC�Ĵ������		
	    RTC_ITConfig(RTC_IT_SEC,ENABLE);//ʹ��RTC���ж�    
		RTC_WaitForLastTask();//�ȴ�дRTC�Ĵ������	
	}
	RCC_ClearFlag();//�����λ��־��		
}



