#include "smg.h"
u8 smgduan[16]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
             0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};//0~F
u8 miao,fen;
void smg_init()
{
	GPIO_InitTypeDef GPIO_InitStructure; 

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF|RCC_APB2Periph_GPIOC,ENABLE);

	GPIO_InitStructure.GPIO_Pin=tub1|tub2|tub3|tub4;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=smg_duan;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
}
void smg_display()	 //�������ʾ����
{
	u8 i;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
			case 0: GPIO_Write(GPIOC,(u16)(smgduan[i]));
					GPIO_ResetBits(GPIOF,tub1);
					GPIO_SetBits(GPIOF,tub2);
					GPIO_SetBits(GPIOF,tub3);
					GPIO_SetBits(GPIOF,tub4);	//��λѡ
					break;
			case 1: GPIO_Write(GPIOC,(u16)(smgduan[i]));
					GPIO_ResetBits(GPIOF,tub2);
					GPIO_SetBits(GPIOF,tub1);
					GPIO_SetBits(GPIOF,tub3);
					GPIO_SetBits(GPIOF,tub4);
					break;
			case 2: GPIO_Write(GPIOC,(u16)(smgduan[i]));
					GPIO_ResetBits(GPIOF,tub3);
					GPIO_SetBits(GPIOF,tub2);
					GPIO_SetBits(GPIOF,tub1);
					GPIO_SetBits(GPIOF,tub4);
					break;
			case 3: GPIO_Write(GPIOC,(u16)(smgduan[i]));
					GPIO_ResetBits(GPIOF,tub4);
					GPIO_SetBits(GPIOF,tub2);
					GPIO_SetBits(GPIOF,tub3);
					GPIO_SetBits(GPIOF,tub1);
					break;
		}
		delay_ms(1);
	}		
}
void time_smg_run()	  //��ʱ�������������ʾ
{
	u8 i;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
			case 0: GPIO_Write(GPIOC,(u16)(smgduan[miao%10]));
					GPIO_ResetBits(GPIOF,tub1);
					GPIO_SetBits(GPIOF,tub2);
					GPIO_SetBits(GPIOF,tub3);
					GPIO_SetBits(GPIOF,tub4);
					break;
			case 1: GPIO_Write(GPIOC,(u16)(smgduan[miao/10]));
					GPIO_ResetBits(GPIOF,tub2);
					GPIO_SetBits(GPIOF,tub1);
					GPIO_SetBits(GPIOF,tub3);
					GPIO_SetBits(GPIOF,tub4);
					break;
			case 2: GPIO_Write(GPIOC,(u16)(smgduan[fen%10]));
					GPIO_ResetBits(GPIOF,tub3);
					GPIO_SetBits(GPIOF,tub2);
					GPIO_SetBits(GPIOF,tub1);
					GPIO_SetBits(GPIOF,tub4);
					break;
			case 3: GPIO_Write(GPIOC,(u16)(smgduan[fen/10]));
					GPIO_ResetBits(GPIOF,tub4);
					GPIO_SetBits(GPIOF,tub2);
					GPIO_SetBits(GPIOF,tub3);
					GPIO_SetBits(GPIOF,tub1);
					break;
		}
		delay_ms(1);
	}					
}

