/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "Systick.h"

#include "public.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


//#define KEY_UP     GPIO_Pin_0 //PA0 

//#define KEY_DOWN   GPIO_Pin_3 //PE3
//#define KEY_LEFT   GPIO_Pin_2 //PE2
//#define KEY_RIGHT  GPIO_Pin_4 //PE4

void EXTI0_IRQHandler(void)  //外部中断0入口函数
{
    if(EXTI_GetITStatus(EXTI_Line0)==SET)  //判断中断状态  检查指定的EXTI线路触发请求发生与否
	{
	
		EXTI_ClearITPendingBit(EXTI_Line0);  //清除EXTI线路挂起位
	    delay_ms(10);  //消抖处理
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)==Bit_SET)     //判断PA0 向上按键是否生效
		{
			//delay_ms(10);  //消抖处理  可添加，消抖精确
			GPIO_WriteBit(GPIOC,GPIO_Pin_0,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_0)))); 
//			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)==Bit_RESET)
//			{
//			    GPIO_SetBits(GPIOC,GPIO_Pin_0);    //熄灭LED0
//			}
//			else
//			{
//			    GPIO_ResetBits(GPIOC,GPIO_Pin_0);    //点亮LED0
//			}		
		}
		while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)==Bit_SET);    //等待按键松开

		
	}

}

void EXTI2_IRQHandler(void)  //外部中断2入口函数
{
    if(EXTI_GetITStatus(EXTI_Line2))  //判断中断状态  检查指定的EXTI线路触发请求发生与否
	{
	    EXTI_ClearITPendingBit(EXTI_Line2);  //清除EXTI线路挂起位
		delay_ms(10);  //消抖处理
		
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)==Bit_RESET)     //判断PE2 向上按键是否生效
		{
			GPIO_WriteBit(GPIOC,GPIO_Pin_2,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_2)))); 
//			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)==Bit_RESET)
//			{
//			    GPIO_SetBits(GPIOC,GPIO_Pin_2);    //熄灭LED2
//			}
//			else
//			{
//			    GPIO_ResetBits(GPIOC,GPIO_Pin_2);    //点亮LED2
//			}		
		}
        while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)==Bit_RESET);    //等待按键松开		
	}

}

void EXTI3_IRQHandler(void)  //外部中断3入口函数
{
    if(EXTI_GetITStatus(EXTI_Line3))  //判断中断状态  检查指定的EXTI线路触发请求发生与否
	{
	    EXTI_ClearITPendingBit(EXTI_Line3);  //清除EXTI线路挂起位
		delay_ms(10);  //消抖处理
		
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)==Bit_RESET)     //判断PE3 向上按键是否生效
		{
			GPIO_WriteBit(GPIOC,GPIO_Pin_3,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3))));  
//			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)==Bit_RESET)
//			{
//			    GPIO_SetBits(GPIOC,GPIO_Pin_3);    //熄灭LED0
//			}
//			else
//			{
//			    GPIO_ResetBits(GPIOC,GPIO_Pin_3);    //点亮LED0
//			}		
		}
        while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)==Bit_RESET);    //等待按键松开		
	}

}
void EXTI4_IRQHandler(void)  //外部中断4入口函数
{
    if(EXTI_GetITStatus(EXTI_Line4))  //判断中断状态  检查指定的EXTI线路触发请求发生与否
	{
	    EXTI_ClearITPendingBit(EXTI_Line4);  //清除EXTI线路挂起位
		delay_ms(10);  //消抖处理
		
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)==Bit_RESET)     //判断PE4 向上按键是否生效
		{
			GPIO_WriteBit(GPIOC,GPIO_Pin_4,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_4))));   
//			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)==Bit_RESET)
//			{
//			    GPIO_SetBits(GPIOC,GPIO_Pin_4);    //熄灭LED0
//			}
//			else
//			{
//			    GPIO_ResetBits(GPIOC,GPIO_Pin_4);    //点亮LED0
//			}		
		}	
        while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)==Bit_RESET);    //等待按键松开		
	}

}

void TIM3_IRQHandler(void)  //时钟3中断入口函数 //时钟配置时已经设置好1秒/0.5秒触发一次中断
{
	static u8 i = 0;
    TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除时钟中断	
    GPIO_Write(GPIOC,(u16)~(0x01<<i++));
	if(i == 8)i=0;
}

void USART1_IRQHandler(void)	//串口1中断函数
{
	static u8 k;
	USART_ClearFlag(USART1,USART_FLAG_TC);  //清除串口1中断标志位   USART_FLAG_TC发送完成标志位
	if(USART_GetITStatus(USART1,USART_IT_RXNE)!=Bit_RESET)//检查指定的USART中断发生与否   USART_IT_RXNE接收中断
	{
		k=USART_ReceiveData(USART1);
		k++;	
		USART_SendData(USART1,k);//通过外设USARTx发送单个数据
		while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==Bit_RESET);	//等待发送完成 USART_FLAG_TXE发送数据寄存器空标志位
	}
}

void USART2_IRQHandler(void)	//串口2中断函数
{
	static u8 k;
	static u8 n = 0;
	static u8 num = 0;
	USART_ClearFlag(USART2,USART_FLAG_TC);  //清除串口2中断标志位   USART_FLAG_TC传输完成标志位
	if(USART_GetITStatus(USART2,USART_IT_RXNE)!=Bit_RESET)//检查指定的USART中断发生与否   USART_IT_RXNE接收中断
	{
	//	USART_ClearFlag(USART2,USART_IT_RXNE);
		k=USART_ReceiveData(USART2);
		TESTZC[n++] = k;
	
		if(k ==0 )
		{
			GPIO_SetBits(GPIOG,GPIO_Pin_3);
			while(num < n)
			{
				USART_SendData(USART2,TESTZC[num++]);//通过外设USARTx发送单个数据
				while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)==Bit_RESET);	//等待发送完成 USART_FLAG_TXE发送数据寄存器空标志位
				delay_ms(1);
			}
			GPIO_ResetBits(GPIOG,GPIO_Pin_3);
		
		}
	}
}

//################################################################################################
//             下一段程序接收数据存在问题，我的办法是将接收和发送函数分开，以0x00为结束标识语,如上。
//################################################################################################
/*
void USART2_IRQHandler(void)	//串口2中断函数
{
	static u8 k;
	static u8 n = 0;
	USART_ClearFlag(USART2,USART_FLAG_TC);  //清除串口2中断标志位   USART_FLAG_TC传输完成标志位
	if(USART_GetITStatus(USART2,USART_IT_RXNE)!=Bit_RESET)//检查指定的USART中断发生与否   USART_IT_RXNE接收中断
	{
		USART_ClearFlag(USART2,USART_IT_RXNE);
		k=USART_ReceiveData(USART2);
		TESTZC[n] = k;
		n++;
		delay_ms(10);
		//接收到485数据后打开发送功能，	
		GPIO_SetBits(GPIOG,GPIO_Pin_3);
		USART_SendData(USART2,k);//通过外设USARTx发送单个数据
		while(USART_GetFlagStatus(USART2,USART_FLAG_TXE)==Bit_RESET);	//等待发送完成 USART_FLAG_TXE发送数据寄存器空标志位
		delay_ms(2);
		GPIO_ResetBits(GPIOG,GPIO_Pin_3);
		
	}
}
*/


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
