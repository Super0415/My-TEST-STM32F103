#include "public.h"
#include "Systick.h"
//******************************************************************
//ʹ��Cortex-M3��systickʱ���µ�΢�뺯��
//******************************************************************
void delay_us(u32 i)
{
	u32 temp;
	SysTick->LOAD=9*i;		 //������װ��ֵ, 72MHZʱ
	SysTick->CTRL=0X01;		 //ʹ�ܣ����������޶����������ⲿʱ��Դ
	SysTick->VAL=0;		   	 //���������
	do
	{
		temp=SysTick->CTRL;		   //��ȡ��ǰ������ֵ
	}
	while((temp&0x01)&&(!(temp&(1<<16))));	 //�ȴ�ʱ�䵽��                            
	SysTick->CTRL=0;	//�رռ�����
	SysTick->VAL=0;		//��ռ�����
}
//******************************************************************
//ʹ��Cortex-M3��systickʱ���µĺ��뺯��
//M3��SystickΪ24λ��ʱ�������ֵΪ2^24 = 16777216
//******************************************************************
void delay_ms(u32 i)
{
	u32 temp;
	SysTick->LOAD=9000*i;	  //������װ��ֵ, 72MHZʱ
	SysTick->CTRL=0X01;		//ʹ�ܣ����������޶����������ⲿʱ��Դ
	SysTick->VAL=0;			//���������
	do
	{
		temp=SysTick->CTRL;	   //��ȡ��ǰ������ֵ
	}
	while((temp&0x01)&&(!(temp&(1<<16))));	//�ȴ�ʱ�䵽��
	SysTick->CTRL=0;	//�رռ�����
	SysTick->VAL=0;		//��ռ�����
}

//******************************************************************
//* �� �� ��: RCC_HSE_Configuration
//* ��������: �Զ���ϵͳʱ�ӣ�����ͨ���޸�PLLʱ��Դ�ͱ�Ƶϵ��ʵ��ʱ�ӵ���
//* ��    ��: ��
//* ��    ��: ��
//******************************************************************
void RCC_HSE_Configuration(void) //�Զ���ϵͳʱ�䣨�����޸�ʱ�ӣ�
{
	RCC_DeInit(); //������RCC�Ĵ�������Ϊȱʡֵ
	RCC_HSEConfig(RCC_HSE_ON);//�����ⲿ���پ���HSE��
	if(RCC_WaitForHSEStartUp()==SUCCESS) //�ȴ�HSE����
	{
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//����AHBʱ�ӣ�HCLK��
		RCC_PCLK1Config(RCC_HCLK_Div2);//���õ���AHBʱ�ӣ�PCLK1��
		RCC_PCLK2Config(RCC_HCLK_Div1);//���ø���AHBʱ�ӣ�PCLK2��
	    //RCC_PLLSource_HSE_Div2 ������2��Ƶ����72/8/2 = 4.5MHz  , RCC_PLLMul_9  Ԥ��ƵΪ9��   ��4.5MHz/9
	    //��ʱdelay_ms(1000); //2s��ʱ 
		//���������������������ʱΪdelay_ms(1000)Ϊ2s
		//RCC_PLLConfig(RCC_PLLSource_HSE_Div2,RCC_PLLMul_9);//����PLLʱ��Դ��PLL������ʱ�� = HSEʱ��Ƶ�ʣ�����Ƶϵ��
		//���������������������ʱΪdelay_ms(1000)Ϊ1s
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);//����PLLʱ��Դ��PLL������ʱ�� = HSEʱ��Ƶ�ʣ�����Ƶϵ��
		
		RCC_PLLCmd(ENABLE); //ʹ�ܻ���ʧ��PLL
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET);//���ָ����RCC��־λ�������,PLL����
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);//����ϵͳʱ�ӣ�SYSCLK��
		while(RCC_GetSYSCLKSource()!=0x08);//��������ϵͳʱ�ӵ�ʱ��Դ,0x08��PLL��Ϊϵͳʱ��
	}
}

