//#include "ALL_Includes.h"
//#include <stdio.h>
#include "TYPCortex.h"

uint8_t RS485_RecBuff[8],RS485RecDataFinish=0;

void USART1_RXTX_CTLConfig(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	//GPIO_ResetBits(GPIOA,GPIO_Pin_8);	//进入接收模式
	RS485_USART1_TXRX_CON(Max485_R);
}
//-----------------------------------------------------
// 函数名：USART1_Config
// 描述  ：USART1 GPIO 配置,工作模式配置
// 输入  ：无
// 输出  : 无
// 调用  ：外部调用
// -----------------------------------------------------
void USART1_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	/* config USART1 clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	/* USART1 GPIO config */
	/* Configure USART1 Tx (PA.09) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);    
	/* Configure USART1 Rx (PA.10) as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* USART1 mode config */
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_ClearFlag(USART1, USART_FLAG_TC); /*???????,Transmission Complete flag */
	USART_Cmd(USART1, ENABLE);
}

//-----------------------------------------------------
// 函数名：NVIC_Configuration
// 描述 
// 输入  ：无
// 输出  : 无
// 调用  ：外部调用
// -----------------------------------------------------
void RS485_NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	/* Configure the NVIC Preemption Priority Bits */  
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 7;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}
//-----------------------------------------------------
// 函数名：RS485_USART1_INIT
// 描述 
// 输入  ：无
// 输出  : 无
// 调用  ：外部调用
// -----------------------------------------------------
void USART1_IRQHandler_RX(void)
{
 static u8 c=0;
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{ 	//USART_ReceiveData(USART2);
	    RS485_RecBuff[c]=USART1->DR;
	  	if(c++>=7){c=0;RS485RecDataFinish=2;}
	}
}

//-----------------------------------------------------
// 函数名：RS485_USART1_INIT
// 描述 
// 输入  ：无
// 输出  : 无
// 调用  ：外部调用
// -----------------------------------------------------
void RS485_USART1_INIT(void)
{
  //USART1_Config();
	//RS485_NVIC_Configuration();
	USART1_RXTX_CTLConfig();
	eMBInit(MB_RTU, 1, 0,9600, MB_PAR_NONE);
	eMBEnable();	
}

void RS485_SendDate(unsigned char SendDate)
{
  RS485_USART1_TXRX_CON(Max485_T);  //发送数据
	USART_ClearFlag(USART1, USART_FLAG_TC);
	USART_SendData(USART1, (unsigned char)SendDate);
	//while (!(USART1->SR & USART_FLAG_TXE));
	while (USART_GetFlagStatus(USART1,USART_FLAG_TC) !=SET);//轮询直到发送数据完毕
	RS485_USART1_TXRX_CON(Max485_R);  //接收数据
}

void RS485_SendString(unsigned char *SendBuf,unsigned char SendConuter)
{
  while(SendConuter) 
  {
    RS485_SendDate(*SendBuf); 
    SendConuter--;
    SendBuf++;
  }
} 
void RS485_Manage(void)
{/*
  if(RS485RecDataFinish==22)
	 { RS485RecDataFinish=0;RS485_USART1_TXRX_CON(Max485_R);
	 }
	if(RS485RecDataFinish==33)
	 { RS485RecDataFinish=0;RS485_USART1_TXRX_CON(Max485_T);  //发送数据
		 USART_SendData(USART1,0x66);
	 }
	 */
/*	if(RS485RecDataFinish==2)
	 { RS485RecDataFinish=0;
	   RS485_SendDate(0x55);
	 }
*/
 eMBPoll();		 
}
/************************END OF FILE************/



