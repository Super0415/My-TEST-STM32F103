// #include "includes.h"
// #include "ALL_Includes.h"
// #include "fsmc_sram.h"
#include "TYPCortex.h"
/*******************************************************************************
* Function Name  : RCC_Configuration
* Description    : Configures the different system clocks.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/

#define TP_CS()  GPIO_ResetBits(GPIOB,GPIO_Pin_7)
#define TP_DCS() GPIO_SetBits(GPIOB,GPIO_Pin_7)
extern void LCD_Init1(void);
void tp_Config(void) ;
void RCC_Configuration(void)
{  
   SystemInit();
}

////关闭调试接口，作GPIO使用
//void UnableJTAG(void)
//{
//   RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;                     // enable clock for Alternate Function
//   AFIO->MAPR &= ~(7UL<<24); // clear used bit
//   AFIO->MAPR |= (4UL<<24); // set used bits
//}

/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : Configures the different GPIO ports.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_CtlBKLingtON(void)
{
 GPIO_SetBits(GPIOB, GPIO_Pin_13);			//LIGHT
}

void GPIO_CtlBKLingtOFF(void)
{
 GPIO_ResetBits(GPIOB, GPIO_Pin_13);		//LIGHT
}

void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC |
                         RCC_APB2Periph_GPIOD | RCC_APB2Periph_GPIOE , ENABLE); 	

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;	 //LCD 背光控制	   
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 ; 	 //LCD-RST
  GPIO_Init(GPIOE, &GPIO_InitStructure);  	
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_4 | GPIO_Pin_5 |
                                GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_14 | 
                                GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  /* Set PE.07(D4), PE.08(D5), PE.09(D6), PE.10(D7), PE.11(D8), PE.12(D9), PE.13(D10),
     PE.14(D11), PE.15(D12) as alternate function push pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | 
                                GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | 
                                GPIO_Pin_15;
  GPIO_Init(GPIOE, &GPIO_InitStructure); 

  /* NE1 configuration */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; 
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  
  /* RS */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 ; 
  GPIO_Init(GPIOD, &GPIO_InitStructure); 
  
  GPIO_SetBits(GPIOD, GPIO_Pin_7);			//CS=1 
  GPIO_SetBits(GPIOD, GPIO_Pin_14| GPIO_Pin_15 |GPIO_Pin_0 | GPIO_Pin_1);  	 
  GPIO_SetBits(GPIOE, GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10);   
  //GPIO_ResetBits(GPIOE, GPIO_Pin_0);
  GPIO_ResetBits(GPIOE, GPIO_Pin_1);	    //RESET=0
  GPIO_SetBits(GPIOD, GPIO_Pin_4);		    //RD=1
  GPIO_SetBits(GPIOD, GPIO_Pin_5);			//WR=1	  

  GPIO_CtlBKLingtON();
//GPIO_CtlBKLingtOFF(); 

}

/*******************************************************************************
* Function Name  : NVIC_Configuration
* Description    : Configures Vector Table base location.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void NVIC_Configuration(void)
{
//  NVIC_InitTypeDef NVIC_InitStructure;

#if defined (VECT_TAB_RAM)
  /* Set the Vector Table base location at 0x20000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0); 
#elif defined(VECT_TAB_FLASH_IAP)
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x2000);
#else  /* VECT_TAB_FLASH  */
  /* Set the Vector Table base location at 0x08000000 */ 
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);   
#endif 

  /* Configure the NVIC Preemption Priority Bits */  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  
}
void BSP_HarldInit(void)
{
  LED_Init();
  RELAY_Init();
  KEY_Init();
  AUX_SWIN_Init();
	CAN_Config();
//	RS485_USART1_INIT();  //@@@
//  ADC1_Init();  //@@@
  //TIM2_PITTIMER_Cfig();  //@@@不需要定时器2来作为传感器采集
//  TIM3_Cap_Init(0xFFFF,3-1);	//以(72/2+1)Mhz的频率计数             //@@@@@@@@@@@@ZC  fir
  TIM4_TIMER_Config();  
//  TIM8_Cap_Init(0x0743,0x0000);     // 0.0008s   800-1,36-1	    //@@@@@@@@@@@@ZC  fir
}

void BSP_Init(void)
{
  /* System Clocks Configuration */
  //RCC_Configuration();   
//  GPIO_Configuration(); //@@@
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_FSMC, ENABLE);  //@@@
//  FSMC_LCD_Init();  //@@@ZC
//  LCD_Init1();      //@@@ZC
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);  
  BSP_HarldInit();  //硬件初始化

}
//------------------------------------------------------------------
// PVD电源电压低监测
//------------------------------------------------------------------
void PVDEXTI_Configuration(void)
{	
  NVIC_InitTypeDef NVIC_InitStructure;
  EXTI_InitTypeDef EXTI_InitStructure; 
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);//电源管理部分时钟开启 
  EXTI_InitStructure.EXTI_Line = EXTI_Line16;// PVD连接到中断线16上 
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//使用中断模式 
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;//电压上升或下降越过设定阀值时都产生中断。
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;// 使能中断线
  EXTI_Init(&EXTI_InitStructure);// 初始

	/* enabling EXTI interrupt */
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  NVIC_InitStructure.NVIC_IRQChannel=PVD_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
/*-----------------------------------------------------------------------
函数名称：void PVD_SoftReSetINIT(void)
功能描述：电压低监测 
输入参数：
输出参数：Mcu电压低于2.5v 做软件复位
----------------------------------------------------------------------- */
void PVD_SoftReSetINIT(void)
{
 PVDEXTI_Configuration();
 PWR_PVDLevelConfig(PWR_PVDLevel_2V5);
 PWR_PVDCmd(ENABLE);
}

uint32  BSP_CPU_ClkFreq (void)
{
    RCC_ClocksTypeDef  rcc_clocks;
    RCC_GetClocksFreq(&rcc_clocks);
    return ((uint32)rcc_clocks.HCLK_Frequency);
}

INT32U  OS_CPU_SysTickClkFreq (void)
{
    INT32U  freq;
    freq = BSP_CPU_ClkFreq();
    return (freq);
}

void  OS_CPU_SysTickInit(void)
{
    RCC_ClocksTypeDef  rcc_clocks;
    INT32U         cnts;
    RCC_GetClocksFreq(&rcc_clocks);
    cnts = (INT32U)rcc_clocks.HCLK_Frequency/OS_TICKS_PER_SEC;
	  SysTick_Config(cnts);
}


void tp_Config(void) 
{ 
  GPIO_InitTypeDef  GPIO_InitStructure; 
  SPI_InitTypeDef   SPI_InitStructure; 
  //SPI1 Periph clock enable 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE); 

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Configure PB.12 as Output push-pull, used as Flash Chip select */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;           //SPI1 CS1 
  GPIO_Init(GPIOC, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;           //SPI1 CS4 
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;           //SPI1 NSS 
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  GPIO_SetBits(GPIOC, GPIO_Pin_4);			//SPI CS1
  GPIO_SetBits(GPIOB, GPIO_Pin_12);			//SPI CS4
  GPIO_SetBits(GPIOA, GPIO_Pin_4);			//SPI NSS

  // SPI3 Config  
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master; 
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b; 
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low; 
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; 
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;   //SPI_NSS_Hard
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64; 
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB; 
  SPI_InitStructure.SPI_CRCPolynomial = 7; 
  SPI_Init(SPI1,&SPI_InitStructure); 

  // SPI1 enable  
  SPI_Cmd(SPI1,ENABLE);  
}


unsigned char SPI_WriteByte(unsigned char data) 
{ 
 unsigned char Data = 0; 

   //Wait until the transmit buffer is empty 
  while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE)==RESET); 
  // Send the byte  
  SPI_I2S_SendData(SPI1,data); 

   //Wait until a data is received 
  while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)==RESET); 
  // Get the received data 
  Data = SPI_I2S_ReceiveData(SPI1); 

  // Return the shifted data 
  return Data; 
}  


void SpiDelay(unsigned int DelayCnt)
{
 unsigned int i;
 for(i=0;i<DelayCnt;i++);
}

u16 TPReadX(void)
{ 
  u16 X=0;
  TP_CS();
  SpiDelay(10);
  SPI_WriteByte(0xD0);
  SpiDelay(10);
  X=SPI_WriteByte(0x00);
  X<<=8;
  X+=SPI_WriteByte(0x00);
  SpiDelay(10);
  TP_DCS();
  X = X>>3; 
  return (X);
}

u16 TPReadY(void)
{
   u16 Y=0;
   TP_CS();
   SpiDelay(10);
   SPI_WriteByte(0x90);
   SpiDelay(10);
   Y=SPI_WriteByte(0x00);
   Y<<=8;
   Y+=SPI_WriteByte(0x00);
   SpiDelay(10);
   TP_DCS(); 
   Y = Y>>3;
   return (4096-Y);
}


#ifdef  DEBUG
/*******************************************************************************
* Function Name  : assert_failed
* Description    : Reports the name of the source file and the source line number
*                  where the assert_param error has occurred.
* Input          : - file: pointer to the source file name
*                  - line: assert_param error line source number
* Output         : None
* Return         : None
*******************************************************************************/
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/

