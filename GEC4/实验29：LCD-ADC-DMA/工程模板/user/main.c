/*******************************************************************************
*                 
*                 		       普中科技
--------------------------------------------------------------------------------
* 实 验 名		 : LCD-ADC-DMA实验
* 实验说明       : 通过将程序下载进去后点击复位，配置端口PA1内的ADC，将电位器变化值转换为
					电压值，通过配置DMA，将ADC和DMA连在一起，使其自动进行转换搬运。主函数
					直接调用即可。LED指示灯闪烁效果，
					按下复位开关重新运行,其他子函数注释
					可以参考之前的函数注释
* 连接方式       : 	
* 注    意		 : 	所用函数在头文件.c文件内
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
	dma_init();	  //DMA初始化 
	TFT_Init();	 //TFT彩屏初始化
	LED_Init();	  //端口初始化
	printf_init();	//printf初始化
	TFT_ClearScreen(BLACK);	   //清屏
	GUI_Show12ASCII(10,10,"This is a ADC1-DMA1 Check!",YELLOW,BLACK);
	GUI_Show12ASCII(10,27,"PA1 is AD Input!",YELLOW,BLACK);
	GUI_Show12ASCII(10,100,"The AD Volage is:",YELLOW,BLACK);
	while(1)
	{
		value=0;
		for(i=0;i<10;i++)//读取10次的AD数值取其平均数较为准确	
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



