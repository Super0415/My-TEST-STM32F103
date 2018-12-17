//#include "ALL_Includes.h"
#include "TYPCortex.h"
/****************************************************
函数功能：RELAY初始化
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_Init(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
    
	  RCC_APB2PeriphClockCmd(RELAY_GPIO_CLK, ENABLE);
	  RCC_APB2PeriphClockCmd( RCC_APB2Periph_AFIO, ENABLE);
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC,ENABLE);
    //GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable, ENABLE);
	  GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE); 
   
    GPIO_InitStructure.GPIO_Pin = RELAY_AUX1_PIN | RELAY_AUX3_PIN | RELAY_AUX4_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(RELAY_PORT_AUX, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = RELAY_AUX5_PIN | RELAY_AUX6_PIN;
	  GPIO_Init(RELAY_PORT_AUX56, &GPIO_InitStructure);
	
	  GPIO_InitStructure.GPIO_Pin = RELAY_AUX2_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(RELAY_PORT_AUX, &GPIO_InitStructure);
		
	  GPIO_InitStructure.GPIO_Pin = RELAY_CRANK_PIN;
	  GPIO_Init(RELAY_PORT_CRANK, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = D_CHARGE_PIN;
	  GPIO_Init(D_PORT_CHARGE, &GPIO_InitStructure);
	
	  RELAY_ALL_ON();//关闭所有输出口
	
}


/****************************************************
函数功能：RELAY_AUX1_FlicK
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_AUX1_ON(void)
{
	GPIO_ResetBits(RELAY_PORT_AUX, RELAY_AUX1_PIN);
}

void RELAY_AUX1_OFF(void)
{
	GPIO_SetBits(RELAY_PORT_AUX, RELAY_AUX1_PIN);
}

void RELAY_AUX1_Flick(void)
{
  GPIO_WriteBit(RELAY_PORT_AUX, RELAY_AUX1_PIN, (BitAction)((1-GPIO_ReadOutputDataBit(RELAY_PORT_AUX, RELAY_AUX1_PIN)))); 
}

/****************************************************
函数功能：RELAY_AUX2_FlicK
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_AUX2_ON(void)
{
	GPIO_ResetBits(RELAY_PORT_AUX, RELAY_AUX2_PIN);
}

void RELAY_AUX2_OFF(void)
{
	GPIO_SetBits(RELAY_PORT_AUX, RELAY_AUX2_PIN);
}

void RELAY_AUX2_Flick(void)
{
  GPIO_WriteBit(RELAY_PORT_AUX, RELAY_AUX2_PIN, (BitAction)((1-GPIO_ReadOutputDataBit(RELAY_PORT_AUX, RELAY_AUX2_PIN)))); 
}

/****************************************************
函数功能：RELAY_AUX3_FlicK
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_AUX3_ON(void)
{
	GPIO_ResetBits(RELAY_PORT_AUX, RELAY_AUX3_PIN);
}

void RELAY_AUX3_OFF(void)
{
	GPIO_SetBits(RELAY_PORT_AUX, RELAY_AUX3_PIN);
}

void RELAY_AUX3_Flick(void)
{
  GPIO_WriteBit(RELAY_PORT_AUX, RELAY_AUX3_PIN, (BitAction)((1-GPIO_ReadOutputDataBit(RELAY_PORT_AUX, RELAY_AUX3_PIN)))); 
}

/****************************************************
函数功能：RELAY_AUX4_FlicK
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_AUX4_ON(void)
{
	GPIO_ResetBits(RELAY_PORT_AUX, RELAY_AUX4_PIN);
}

void RELAY_AUX4_OFF(void)
{
	GPIO_SetBits(RELAY_PORT_AUX, RELAY_AUX4_PIN);
}

void RELAY_AUX4_Flick(void)
{
  GPIO_WriteBit(RELAY_PORT_AUX, RELAY_AUX4_PIN, (BitAction)((1-GPIO_ReadOutputDataBit(RELAY_PORT_AUX, RELAY_AUX4_PIN)))); 
}

/****************************************************
函数功能：RELAY_AUX5_FlicK
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_AUX5_ON(void)
{
	GPIO_ResetBits(RELAY_PORT_AUX56, RELAY_AUX5_PIN);
}

void RELAY_AUX5_OFF(void)
{
	GPIO_SetBits(RELAY_PORT_AUX56, RELAY_AUX5_PIN);
}

void RELAY_AUX5_Flick(void)
{
  GPIO_WriteBit(RELAY_PORT_AUX56, RELAY_AUX5_PIN, (BitAction)((1-GPIO_ReadOutputDataBit(RELAY_PORT_AUX56, RELAY_AUX5_PIN)))); 
}


/****************************************************
函数功能：RELAY_AUX6_FlicK
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_AUX6_ON(void)
{
	GPIO_ResetBits(RELAY_PORT_AUX56, RELAY_AUX6_PIN);
}

void RELAY_AUX6_OFF(void)
{
	GPIO_SetBits(RELAY_PORT_AUX56, RELAY_AUX6_PIN);
}

void RELAY_AUX6_Flick(void)
{
  GPIO_WriteBit(RELAY_PORT_AUX56, RELAY_AUX6_PIN, (BitAction)((1-GPIO_ReadOutputDataBit(RELAY_PORT_AUX56, RELAY_AUX6_PIN)))); 
}


/****************************************************
函数功能：RELAY_DCHARGE_ON
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_DCHARGE_ON(void)
{
	GPIO_ResetBits(D_PORT_CHARGE, D_CHARGE_PIN);
}

void RELAY_DCHARGE_OFF(void)
{
	GPIO_SetBits(D_PORT_CHARGE, D_CHARGE_PIN);
}

void RELAY_DCHARGE_Flick(void)
{
  GPIO_WriteBit(D_PORT_CHARGE, D_CHARGE_PIN, (BitAction)((1-GPIO_ReadOutputDataBit(D_PORT_CHARGE, D_CHARGE_PIN)))); 
}

/****************************************************
函数功能：RELAY_CRANK_ON
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_CRANK_ON(void)
{
	GPIO_ResetBits(RELAY_PORT_CRANK, RELAY_CRANK_PIN);
}

void RELAY_CRANK_OFF(void)
{
	GPIO_SetBits(RELAY_PORT_CRANK, RELAY_CRANK_PIN);
}

void RELAY_CRANK_Flick(void)
{
  GPIO_WriteBit(RELAY_PORT_CRANK, RELAY_CRANK_PIN, (BitAction)((1-GPIO_ReadOutputDataBit(RELAY_PORT_CRANK, RELAY_CRANK_PIN)))); 
}

/****************************************************
函数功能：RELAY_ALL_ON
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_ALL_ON(void)
{ RELAY_AUX1_ON();
	RELAY_AUX2_ON();
	RELAY_AUX3_ON();
	RELAY_AUX4_ON();
	RELAY_AUX5_ON();
	RELAY_AUX6_ON();
	RELAY_DCHARGE_ON();
	RELAY_CRANK_ON();
}
/****************************************************
函数功能：RELAY_ALL_OFF
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_ALL_OFF(void)
{ RELAY_AUX1_OFF();
	RELAY_AUX2_OFF();
	RELAY_AUX3_OFF();
	RELAY_AUX4_OFF();
	RELAY_AUX5_OFF();
	RELAY_AUX6_OFF();
	RELAY_DCHARGE_OFF();
	RELAY_CRANK_OFF();
}
/****************************************************
函数功能：RELAY_ALL_Flick
输入参数：无
输出参数：无
备    注：调用此函数前，需要在RELAY.h修改宏定义LED引脚
****************************************************/
void RELAY_ALL_Flick(void)
{
  RELAY_AUX1_Flick();
	RELAY_AUX2_Flick();
	RELAY_AUX3_Flick();
	RELAY_AUX4_Flick();
	RELAY_AUX5_Flick();
	RELAY_AUX6_Flick();
	RELAY_DCHARGE_Flick();
	RELAY_CRANK_Flick();
}

/******************* END *****************/


