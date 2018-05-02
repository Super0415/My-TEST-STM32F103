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

void EXTI0_IRQHandler(void)  //�ⲿ�ж�0��ں���
{
    if(EXTI_GetITStatus(EXTI_Line0)==SET)  //�ж��ж�״̬  ���ָ����EXTI��·�������������
	{
		TESTZC[0]++;
		EXTI_ClearITPendingBit(EXTI_Line0);  //���EXTI��·����λ
	    delay_ms(10);  //��������
		if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)==Bit_SET)     //�ж�PA0 ���ϰ����Ƿ���Ч
		{
			//delay_ms(10);  //��������  ����ӣ�������ȷ
			GPIO_WriteBit(GPIOC,GPIO_Pin_0,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_0)))); 
//			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)==Bit_RESET)
//			{
//			    GPIO_SetBits(GPIOC,GPIO_Pin_0);    //Ϩ��LED0
//			}
//			else
//			{
//			    GPIO_ResetBits(GPIOC,GPIO_Pin_0);    //����LED0
//			}		
		}
		while(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)==Bit_SET);    //�ȴ������ɿ�

		
	}

}

void EXTI2_IRQHandler(void)  //�ⲿ�ж�2��ں���
{
    if(EXTI_GetITStatus(EXTI_Line2))  //�ж��ж�״̬  ���ָ����EXTI��·�������������
	{
		TESTZC[1]++;
	    EXTI_ClearITPendingBit(EXTI_Line2);  //���EXTI��·����λ
		delay_ms(10);  //��������
		
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)==Bit_RESET)     //�ж�PE2 ���ϰ����Ƿ���Ч
		{
			GPIO_WriteBit(GPIOC,GPIO_Pin_2,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_2)))); 
//			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)==Bit_RESET)
//			{
//			    GPIO_SetBits(GPIOC,GPIO_Pin_2);    //Ϩ��LED2
//			}
//			else
//			{
//			    GPIO_ResetBits(GPIOC,GPIO_Pin_2);    //����LED2
//			}		
		}
        while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2)==Bit_RESET);    //�ȴ������ɿ�		
	}

}

void EXTI3_IRQHandler(void)  //�ⲿ�ж�3��ں���
{
    if(EXTI_GetITStatus(EXTI_Line3))  //�ж��ж�״̬  ���ָ����EXTI��·�������������
	{
		TESTZC[2]++;
	    EXTI_ClearITPendingBit(EXTI_Line3);  //���EXTI��·����λ
		delay_ms(10);  //��������
		
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)==Bit_RESET)     //�ж�PE3 ���ϰ����Ƿ���Ч
		{
			GPIO_WriteBit(GPIOC,GPIO_Pin_3,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3))));  
//			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)==Bit_RESET)
//			{
//			    GPIO_SetBits(GPIOC,GPIO_Pin_3);    //Ϩ��LED0
//			}
//			else
//			{
//			    GPIO_ResetBits(GPIOC,GPIO_Pin_3);    //����LED0
//			}		
		}
        while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3)==Bit_RESET);    //�ȴ������ɿ�		
	}

}
void EXTI4_IRQHandler(void)  //�ⲿ�ж�4��ں���
{
    if(EXTI_GetITStatus(EXTI_Line4))  //�ж��ж�״̬  ���ָ����EXTI��·�������������
	{
		TESTZC[3]++;
	    EXTI_ClearITPendingBit(EXTI_Line4);  //���EXTI��·����λ
		delay_ms(10);  //��������
		
		if(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)==Bit_RESET)     //�ж�PE4 ���ϰ����Ƿ���Ч
		{
			GPIO_WriteBit(GPIOC,GPIO_Pin_4,(BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_4))));   
//			if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)==Bit_RESET)
//			{
//			    GPIO_SetBits(GPIOC,GPIO_Pin_4);    //Ϩ��LED0
//			}
//			else
//			{
//			    GPIO_ResetBits(GPIOC,GPIO_Pin_4);    //����LED0
//			}		
		}	
        while(GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4)==Bit_RESET);    //�ȴ������ɿ�		
	}

}

void TIM3_IRQHandler(void)  //ʱ��3�ж���ں��� //ʱ������ʱ�Ѿ����ú�1��/0.5�봥��һ���ж�
{
	static u8 i = 0;
    TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //���ʱ���ж�	
    GPIO_Write(GPIOC,(u16)~(0x01<<i++));
	if(i == 8)i=0;
}




/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
