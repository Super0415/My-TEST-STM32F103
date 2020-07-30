/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : usb_endp.c
* Author             : MCD Application Team
* Version            : V2.2.1
* Date               : 09/22/2008
* Description        : Endpoint routines
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
//#include "platform_config.h"
#include "stm32f10x_lib.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "led.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u8 Receive_Buffer[Max_Buffer_Length];//���ջ���
u8 Transi_Buffer[Max_Buffer_Length];//���ͻ���
u8 USB_ReceiveFlg = FALSE;//������ɱ�־λ
u8 USB_SendFlg = TRUE;//������ɱ�־λ
u16 RX_DataLen;
vu8 MsgCmd;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : EP1_OUT_Callback.
* Description    : EP1 OUT Callback Routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

void EP1_OUT_Callback(void)//�˵�1 ���ջص�����
{
	  TurnOffLed1();
    USB_ReceiveFlg = TRUE;
		RX_DataLen = GetEPRxCount(ENDP1);					  //��ȡ�ӵ����ݵĳ���
    PMAToUserBufferCopy(Receive_Buffer, ENDP1_RXADDR,Max_Buffer_Length);
    MsgCmd = Receive_Buffer[Max_Buffer_Length-1];
    SetEPRxStatus(ENDP1, EP_RX_VALID);
}

void EP2_IN_Callback(void)//�˵�2 ���ͻص�����
{
    u8 ii;
    for (ii=0; ii<Max_Buffer_Length; ii++) Transi_Buffer[ii] = 0x00;//for LED test
		USB_SendFlg = TRUE;
		TurnOffLed1();
}

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/

