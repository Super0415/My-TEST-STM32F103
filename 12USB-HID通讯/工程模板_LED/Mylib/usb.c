#include "usb.h"
#include "Systick.h"
#include "led.h"

extern u32 TEST[10];

void USB_LP_CAN1_RX0_IRQHandler(void)
{
  USB_Istr();
}

/*
功能：对USB初始化
*/
void Init_usb(void)
{
  Set_System();
	USB_Interrupts_Config();
	Set_USBClock();
  USB_Init();
}

/*
功能：USB发送处理
*/
void USB_SendString(char *str)
{
		u8 i=0;
		u8 div=0; 
		int len = 0;	
		len = strlen(str);
		while(*str)
    {			
			if (USB_SendFlg == TRUE)
			{				
				 TurnOnLed1();
				 Transi_Buffer[i++]=*(str++);
					if((i + div * 64) == len)			//最后一行为63个字符，对通讯稳定性有较大帮助
					{
							USB_SendFlg = FALSE;
							UserToPMABufferCopy(Transi_Buffer, ENDP2_TXADDR, Max_Buffer_Length);
							SetEPTxValid(ENDP2);
							break;
					}
					else if (i == Max_Buffer_Length)
					{
							USB_SendFlg = FALSE;
							UserToPMABufferCopy(Transi_Buffer, ENDP2_TXADDR, Max_Buffer_Length);
							SetEPTxValid(ENDP2);
							div++;
							i = 0;	
					}	
			}	
    }
}

void testShow1(u8 system, u8 *data,u8 len)
{
	char Databuff[50*5+500] = {'\0',};
	int i =0;
	char ASCII[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',};
	char bu[2];
	
	bu[0] = len/10+'0';
	bu[1] = len%10+'0';
	USB_FirstSendString(bu);
	USB_FirstSendString("\r\n");
	
	memset(Databuff,'\0',sizeof(Databuff));
	for( i=0; i<len; i++)
	{
		if(system == 16)
		{			
			Databuff[i*5+0] = '0';
			Databuff[i*5+1] = 'x';
			Databuff[i*5+2] = ASCII[data[i]/0x10];
			Databuff[i*5+3] = ASCII[data[i]%0x10];
		}
		else
		{
			Databuff[i*5+0] = ASCII[data[i]/100];
			Databuff[i*5+1] = ASCII[(data[i]%100)/10];
			Databuff[i*5+2] = ASCII[data[i]%10];
			Databuff[i*5+3] = ' ';
		}
		Databuff[i*5+4] = ' ';
	}
	
	Databuff[len*5] = '\0';
	
	USB_FirstSendString(Databuff);
}


void testShow(u8 system, char *buff,u8 *data,u8 len,char *buffend)
{
	char num_buff[4];
	char Databuff[100*4];
	int i =0;	
	memset(num_buff,'\0',sizeof(num_buff));
	memset(Databuff,'\0',sizeof(Databuff));
	
	strcat(Databuff,buff);	
	
		if(system == 16)
		{
			for( i=0; i<len; i++)
			{
				sprintf(num_buff,"%x ",data[i]);
				strcat(Databuff,num_buff);
			}			
		}
		else
		{
			for( i=0; i<len; i++)
			{
				sprintf(num_buff,"%d ",data[i]);
				strcat(Databuff,num_buff);
			}
			
		}
		
	strcat(Databuff,buffend);
	USB_FirstSendString(Databuff);
}

/*
功能：USB发送处理
*/
void USB_FirstSendString(char *str)
{
	//USB_SendFlg = TRUE;
	USB_SendString(str);
	delay_ms(5);
}

/*
功能：USB接收处理
*/

void Test_USB_ReceiveString(void)
{
		char buff[100] = {'\0'};
		int len = 0;
		if ( USB_ReceiveFlg == TRUE) //收到后上位机的数据后
		{
			USB_SendString("a0a1a2a3a4a5a6a7a8a9b0b1b2b3b4b5b6b7b8b9c0c1c2c3c4c5c6c7c8c9d0d1d2d3d4d5d6d7d8d9e0e1e2e3e4e5e6e7e8e9f0f1f2f3f4f5f6f7f8f9g0g1g2g3g4g5g6g7g8g9 \r\n");
//				USB_ReceiveFlg = FALSE;  
			
		}
}

/*
功能：USB测试循环
*/
void TEST_usbloop(void)
{
	Test_USB_ReceiveString();
}

