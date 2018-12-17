//#include "led.h"
//#include "ALL_Includes.h"
#include "TYPCortex.h"
/****************************************************
函数功能：LED初始化
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
 // RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, ENABLE);
    //GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
/*   	
    GPIO_InitStructure.GPIO_Pin = LED_PIN_GCB;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(LED_PORT_GCB, &GPIO_InitStructure);
*/	  
    GPIO_InitStructure.GPIO_Pin = LED_PIN_ALARM;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
    GPIO_Init(LED_PORT_ALARM, &GPIO_InitStructure);
   /* GPIO_InitStructure.GPIO_Pin = LED_PIN_MCB;
    GPIO_Init(LED_PORT_MCB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_PIN_AUTO;
    GPIO_Init(LED_PORT_AUTO, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_PIN_MAN;
    GPIO_Init(LED_PORT_MAN, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = LED_PIN_STOP;
    GPIO_Init(LED_PORT_STOP, &GPIO_InitStructure);
   */
	LED_ALL_OFF(); //Close all led
}

/****************************************************
函数功能：LED_STOP_ON开
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_STOP_ON(void)
{
	//GPIO_ResetBits(LED_PORT_STOP, LED_PIN_STOP);
}

/****************************************************
函数功能：LED_STOP_OFF关
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_STOP_OFF(void)
{
	//GPIO_SetBits(LED_PORT_STOP, LED_PIN_STOP);
}

/****************************************************
函数功能：LED_STOP_Flick闪烁
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_STOP_Flick(void)
{
  //GPIO_WriteBit(LED_PORT_STOP, LED_PIN_STOP, (BitAction)((1-GPIO_ReadOutputDataBit(LED_PORT_STOP, LED_PIN_STOP)))); 
}
	
/****************************************************
函数功能：LED_MAN_ON开
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_MAN_ON(void)
{
	//GPIO_ResetBits(LED_PORT_MAN, LED_PIN_MAN);
}

/****************************************************
函数功能：LED_MAN_OFF关
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_MAN_OFF(void)
{
	//GPIO_SetBits(LED_PORT_MAN, LED_PIN_MAN);
}

/****************************************************
函数功能：LED_MAN_Flick闪烁
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_MAN_Flick(void)
{
  //GPIO_WriteBit(LED_PORT_MAN, LED_PIN_MAN, (BitAction)((1-GPIO_ReadOutputDataBit(LED_PORT_MAN, LED_PIN_MAN)))); 
}

/****************************************************
函数功能：LED_AUTO_ON开
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_AUTO_ON(void)
{
	//GPIO_ResetBits(LED_PORT_AUTO, LED_PIN_AUTO);
}

/****************************************************
函数功能：LED_AUTO_OFF关
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_AUTO_OFF(void)
{
//	GPIO_SetBits(LED_PORT_AUTO, LED_PIN_AUTO);
}

/****************************************************
函数功能：LED_AUTO_Flick闪烁
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_AUTO_Flick(void)
{
  //GPIO_WriteBit(LED_PORT_AUTO, LED_PIN_AUTO, (BitAction)((1-GPIO_ReadOutputDataBit(LED_PORT_AUTO, LED_PIN_AUTO)))); 
}

/****************************************************
函数功能：LED_ALARM_ON开
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_ALARM_ON(void)
{
	GPIO_ResetBits(LED_PORT_ALARM, LED_PIN_ALARM);
}

/****************************************************
函数功能：LED_ALARM_OFF关
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_ALARM_OFF(void)
{
	GPIO_SetBits(LED_PORT_ALARM, LED_PIN_ALARM);
}

/****************************************************
函数功能：LED_ALARM_Flick闪烁
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_ALARM_Flick(void)
{
  GPIO_WriteBit(LED_PORT_ALARM, LED_PIN_ALARM, (BitAction)((1-GPIO_ReadOutputDataBit(LED_PORT_ALARM, LED_PIN_ALARM)))); 
}

/****************************************************
函数功能：LED_MCB_ON开
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_MCB_ON(void)
{
	//GPIO_ResetBits(LED_PORT_MCB, LED_PIN_MCB);
}

/****************************************************
函数功能：LED_MCB_OFF关
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_MCB_OFF(void)
{
	//GPIO_SetBits(LED_PORT_MCB, LED_PIN_MCB);
}

/****************************************************
函数功能：LED_MCB_Flick闪烁
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_MCB_Flick(void)
{
  //GPIO_WriteBit(LED_PORT_MCB, LED_PIN_MCB, (BitAction)((1-GPIO_ReadOutputDataBit(LED_PORT_MCB, LED_PIN_MCB)))); 
}

/****************************************************
函数功能：LED_GCB_ON开
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_GCB_ON(void)
{
//	GPIO_ResetBits(LED_PORT_GCB, LED_PIN_GCB);
}

/****************************************************
函数功能：LED_GCB_OFF关
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_GCB_OFF(void)
{
//	GPIO_SetBits(LED_PORT_GCB, LED_PIN_GCB);
}

/****************************************************
函数功能：LED_GCB_Flick闪烁
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_GCB_Flick(void)
{
//  GPIO_WriteBit(LED_PORT_GCB, LED_PIN_GCB, (BitAction)((1-GPIO_ReadOutputDataBit(LED_PORT_GCB, LED_PIN_GCB)))); 
}

/****************************************************
函数功能：LED_ALL_OFF
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_ALL_OFF(void)
{
    //LED_STOP_OFF();
	//LED_MAN_OFF();
	//LED_AUTO_OFF();
	LED_ALARM_OFF();
	//LED_MCB_OFF();
	//LED_GCB_OFF();
}

/****************************************************
函数功能：LED_ALL_Flick闪烁
输入参数：无
输出参数：无
备    注：调用此函数前，需要在LED.h修改宏定义LED引脚
****************************************************/
void LED_ALL_Flick(void)
{
    //LED_STOP_Flick();
	//LED_MAN_Flick();
	//LED_AUTO_Flick();
	LED_ALARM_Flick();
	//LED_MCB_Flick();
	//LED_GCB_Flick();
}

/*********************Then end *********************/
