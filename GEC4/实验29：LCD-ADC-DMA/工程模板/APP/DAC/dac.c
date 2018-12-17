#include "stm32f10x.h"
void dac_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	DAC_InitTypeDef DAC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,ENABLE);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;//DAC_1
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;//ģ��������
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);//�����
	

	DAC_InitStructure.DAC_Trigger=DAC_Trigger_None;//��ʹ�ô�������
    DAC_InitStructure.DAC_WaveGeneration=DAC_WaveGeneration_None;//��ʹ�����ǲ�
   //���� ��ֵ����
    DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude=DAC_LFSRUnmask_Bit0;
   //�رջ���
    DAC_InitStructure.DAC_OutputBuffer=DAC_OutputBuffer_Disable;
    DAC_Init(DAC_Channel_1,&DAC_InitStructure);//��ʼ��DACͨ��1
    DAC_Cmd(DAC_Channel_1,ENABLE);//ʹ��DAC1
    DAC_SetChannel1Data(DAC_Align_12b_R,0);//12λ �Ҷ��� д0����
}

