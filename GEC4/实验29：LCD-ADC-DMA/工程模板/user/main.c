/*******************************************************************************
*                 
*                 		       ���пƼ�
--------------------------------------------------------------------------------
* ʵ �� ��		 : LCD-ADC-DMAʵ��
* ʵ��˵��       : ͨ�����������ؽ�ȥ������λ�����ö˿�PA1�ڵ�ADC������λ���仯ֵת��Ϊ
					��ѹֵ��ͨ������DMA����ADC��DMA����һ��ʹ���Զ�����ת�����ˡ�������
					ֱ�ӵ��ü��ɡ�LEDָʾ����˸Ч����
					���¸�λ������������,�����Ӻ���ע��
					���Բο�֮ǰ�ĺ���ע��
* ���ӷ�ʽ       : 	
* ע    ��		 : 	���ú�����ͷ�ļ�.c�ļ���
*******************************************************************************/



#include "public.h"
#include "dma.h"
#include "systick.h"
#include "gui.h"
#include "led.h"
#include "printf.h"


/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/
int main()			  
{	
	u16 value;
	u8 i,j,dat[6];
	float ad;
	dma_init();	  //DMA��ʼ�� 
	TFT_Init();	 //TFT������ʼ��
	LED_Init();	  //�˿ڳ�ʼ��
	printf_init();	//printf��ʼ��
	TFT_ClearScreen(BLACK);	   //����
	GUI_Show12ASCII(10,10,"This is a ADC1-DMA1 Check!",YELLOW,BLACK);
	GUI_Show12ASCII(10,27,"PA1 is AD Input!",YELLOW,BLACK);
	GUI_Show12ASCII(10,100,"The AD Volage is:",YELLOW,BLACK);
	while(1)
	{
		value=0;
		for(i=0;i<10;i++)//��ȡ10�ε�AD��ֵȡ��ƽ������Ϊ׼ȷ	
		{
			value=value+adc_data[0];		
		}
		delay_ms(500);
		value=value/10;
		ad=value*3.3/4095;
		value=(u16)(ad*100);
		dat[0]=value/100+0x30;
		dat[1]='.';
		dat[2]=value%100/10+0x30;
		dat[3]=value%100%10+0x30;
		dat[4]='V';
		dat[5]='\0';
		GUI_Show12ASCII(160,100,dat,YELLOW,BLACK);
		if(j>1)
		{
			j=0;
			GPIO_SetBits(GPIOC,GPIO_Pin_0);
		}
		else
		{
			j++;
			GPIO_ResetBits(GPIOC,GPIO_Pin_0);
		} 
								
	}			
}



