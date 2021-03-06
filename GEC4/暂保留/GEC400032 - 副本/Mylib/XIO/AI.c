#include "TYPCortex.h"

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ZC
INT16U *pXIOAdcDmaBuf;
INT16U usXIOAdcDmaBuf0[XIO_ADC_DMA_BUF_SIZ];
INT16U usXIOAdcDmaBuf1[XIO_ADC_DMA_BUF_SIZ];

INT16S ssXIOAdcChDat0[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat1[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat2[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat3[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat4[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat5[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat6[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat7[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat8[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat9[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat10[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat11[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat12[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat13[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat14[XIO_ADC_SMPL_SIZ];
INT16S ssXIOAdcChDat15[XIO_ADC_SMPL_SIZ];

#if (AI_ENABLE==1)
#define ADC1_DR_Address    ((u32)0x40012400+0x4c)

__IO uint16_t ADC_ConvertedValue[AI_CON];

/**********************************************************
 * 函数名：ADC1_GPIO_Config
 * 描述  ：使能ADC1和DMA1的时钟，初始化PC.00 PC.01 PC.02 PC.03 PA.01 PA.02
 * 输入  : 无
 * 输出  ：无
 * 调用  ：内部调用
 **********************************************************/	
#define   SYS_FreqSYSCLK     72  //系统使用的频率 
static void ADC1_GPIO_Config(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;	
	
	/* Enable DMA clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);	
	
	/*配置ADC时钟，为PCLK2的2分频，即24/2=12mHz*/
  #if(SYS_FreqSYSCLK==72)
	  RCC_ADCCLKConfig(RCC_PCLK2_Div6);
  #elif(SYS_FreqSYSCLK==24)
	  RCC_ADCCLKConfig(RCC_PCLK2_Div2);
  #endif			

    XIOConfigGPIO(GPIOA, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
		
    XIOConfigGPIO(GPIOA, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT2, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT3, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT4, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT5, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT6, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT7, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT2, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT3, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
		
    XIOConfigGPIO(GPIOC, XIO_PT_BT4, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT5, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
   
   ADC_DeInit(ADC1);   //设置ADC1寄存器为缺省值

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//独立ADC模式
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;//ENABLE扫描模式用于多通道采集//DISABLE单次(单通道)模式
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;	//开启连续转换模式，即不停地进行ADC转换
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;//ADC_ExternalTrigConv_None;	//不使用外部触发转换 //ADC_ExternalTrigConv_T1_CC1
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; 	//采集数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = AI_CON;	 	//要转换的通道数目1
	ADC_Init(ADC1, &ADC_InitStructure);
	
		//设置指定ADC的规则组通道，     设置它们的转化顺序和采样时间  ADC_SampleTime_28Cycles5  ADC_SampleTime_55Cycles5
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_28Cycles5); //发电Ua   //PA5
	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 2, ADC_SampleTime_28Cycles5); //发电Ub   //PA6
	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 3, ADC_SampleTime_28Cycles5); //发电Uc   //PA7
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 4, ADC_SampleTime_28Cycles5); //自定义3   //PC0
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 5, ADC_SampleTime_28Cycles5); //自定义4   //PC1
	ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 6, ADC_SampleTime_28Cycles5); //温度      //PC2
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 7, ADC_SampleTime_28Cycles5); //油压      //PC3
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8,  8, ADC_SampleTime_28Cycles5); //D+            PB0
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9,  9, ADC_SampleTime_28Cycles5); //电池电压      PB1
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 10, ADC_SampleTime_28Cycles5); //IA   PA1
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 11, ADC_SampleTime_28Cycles5); //IB   PA2
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 12, ADC_SampleTime_28Cycles5); //IC   PA3
	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 13, ADC_SampleTime_28Cycles5); //1.65v中点电压	  PA4


	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 14, ADC_SampleTime_28Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_14,15, ADC_SampleTime_28Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_15,16, ADC_SampleTime_28Cycles5);	

	
	ADC_DMACmd(ADC1,ENABLE);//将ADC与DMA链接在一起
	
	ADC_Cmd(ADC1,ENABLE);	/* Enable ADC1 */

  ADC_ResetCalibration(ADC1);  //重置指定的ADC的校准寄存器
	while(ADC_GetResetCalibrationStatus(ADC1));  /*等待校准寄存器复位完成 */
	ADC_StartCalibration(ADC1);	/* ADC校准 */
	while(ADC_GetCalibrationStatus(ADC1));/* 等待校准完成*/
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//使能或者失能指定的ADC的软件转换启动功能 
	

	/* DMA channel1 configuration */
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_PeripheralBaseAddr =(u32)&ADC1->DR;// ADC1_DR_Address;	 //ADC地址
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&pXIOAdcDmaBuf;//ADC_ConvertedValue;//内存地址  //修改内存地址
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;    //外设作为数据来源
	DMA_InitStructure.DMA_BufferSize = AI_CON;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//外设地址固定
	DMA_InitStructure.DMA_MemoryInc =DMA_MemoryInc_Enable; //内存地址递增  //DMA_MemoryInc_Disable;  //内存地址固定

	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	//外设数据宽度16  
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//存储数据宽度16
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;		//循环缓存传输
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;//DMA通道x拥有高优先级
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;  //DMA通道x没有设置为内存到内存传输
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);  //ADC1在DMA1通道1内
	/* Enable DMA channel1 */
	DMA_Cmd(DMA1_Channel1, ENABLE);  //使能DMA1	

	
//配置DMA中断	
	DMA_ITConfig(DMA1_Channel1,DMA_IT_TC,ENABLE);		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure); 	
	
    if (pXIOAdcDmaBuf   == &usXIOAdcDmaBuf0[0])
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf1[0];
    }   else
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf0[0];
    }	
	
}

#endif

/*
 * 函数名：ADC1_Init
 * 描述  ：无
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 */
 int TESTZCADC[20];
void ADC1_Init(void)
{
	//ADC1_GPIO_Config();
	XIOInitADC1();
	XIOInitDma1Ch1Adc();
	
	XIOInitTim1();  //复位Tim1

	TESTZCADC[0]++;

}

//#if(AI_ENABLE == 0)	
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ZC
/* ******************************************************************** */
/*                              XIOInitADC1()                           */
/* ******************************************************************** */
/* ******************************************************************** */
/*                           XIOConfigGPIO()                            */
/* ******************************************************************** */
void XIOConfigGPIO (GPIO_TypeDef *pPt, INT08U ucBit, INT32U uiMod, INT16U usSet)
{   if (pPt == GPIOA)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    }   else if (pPt == GPIOB)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
    }   else if (pPt == GPIOC)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    }   else if (pPt == GPIOD)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
    }   else if (pPt == GPIOE)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;
    }
   #ifdef RCC_APB2ENR_IOPFEN
    else if (pPt == GPIOF)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPFEN;
    }
   #endif
   #ifdef RCC_APB2ENR_IOPGEN
    else if (pPt == GPIOG)
    {   RCC->APB2ENR |= RCC_APB2ENR_IOPGEN;
    }
   #endif
    else
    {   return;
    }
    if (usSet    ==  0)
    {   pPt->BRR  = (INT32U)0x01 << ucBit;
    }   else
    {   pPt->BSRR = (INT32U)0x01 << ucBit;
    }
    uiMod        &= (INT32U)0x0F;
    ucBit        *=  4;
    if (ucBit    <=  31)
    {   pPt->CRL &= ~((INT32U)0x0F << ucBit);
        pPt->CRL |=  uiMod << ucBit;
    }   else if (ucBit <= 63)
    {   ucBit    -=  32;
        pPt->CRH &= ~((INT32U)0x0F << ucBit);
        pPt->CRH |=  uiMod << ucBit;
    }
}

//IAR init
void XIOInitADC1 (void)
{   XIOConfigGPIO(GPIOA, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT2, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT3, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT4, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT5, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT6, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOA, XIO_PT_BT7, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOB, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT0, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT1, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT2, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT3, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT4, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    XIOConfigGPIO(GPIOC, XIO_PT_BT5, XIO_PT_GPI_ANALOG, XIO_PT_SET_0);
    RCC->APB2ENR |=  RCC_APB2ENR_ADC1EN;       /* 1: ADC1 clock enable  */
    ADC1->CR1    &= ~ADC_CR1_EOCIE             /* EOC Interrupt disable */
                 &  ~ADC_CR1_AWDIE             /* Analog Watchdog inter */
                 &  ~ADC_CR1_JEOCIE            /* Injected chan interru */
                 &  ~ADC_CR1_SCAN              /* Scan mode disable     */
                 &  ~ADC_CR1_AWDSGL            /* Disnable the watchdog */
                 &  ~ADC_CR1_JAUTO             /* Injected group conver */
                 &  ~ADC_CR1_DISCEN            /* Discontinuous mode    */
                 &  ~ADC_CR1_JDISCEN;          /* Discontinuous mode    */
    ADC1->CR2    &= ~ADC_CR2_ADON              /* A/D Converter OFF     */
                 &  ~ADC_CR2_CONT              /* Continuous Conversion */
                 &  ~ADC_CR2_CAL               /* A/D Calibration       */
                 &  ~ADC_CR2_DMA               /* DMA mode disable      */
                 &  ~ADC_CR2_ALIGN             /* Data Alignment right  */
                 &  ~ADC_CR2_EXTSEL            /* EXTSEL[2:0]=0: T1_CC1 */
                 &  ~ADC_CR2_EXTTRIG;          /* EXT triger Disabled   */
    ADC1->SMPR2   = (XIO_ADC1_SMPL_CYC << 0)   /* Chan 0  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 3)   /* Chan 1  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 6)   /* Chan 2  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 9)   /* Chan 3  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 12)  /* Chan 4  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 15)  /* Chan 5  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 18)  /* Chan 6  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 21)  /* Chan 7  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 24)  /* Chan 8  Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 27); /* Chan 9  Sample Cycles */
    ADC1->SMPR1   = (XIO_ADC1_SMPL_CYC << 0)   /* Chan 10 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 3)   /* Chan 11 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 6)   /* Chan 12 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 9)   /* Chan 13 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 12)  /* Chan 14 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 15)  /* Chan 15 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 18)  /* Chan 16 Sample Cycles */
                 |  (XIO_ADC1_SMPL_CYC << 21); /* Chan 17 Sample Cycles */
    ADC1->SQR3    = (XIO_ADC1_CH_1ST  << 0)    /* 1st  Chan in sequence */
                 |  (XIO_ADC1_CH_2ND  << 5)    /* 2nd  Chan in sequence */
                 |  (XIO_ADC1_CH_3RD  << 10)   /* 3rd  Chan in sequence */
                 |  (XIO_ADC1_CH_4TH  << 15)   /* 4th  Chan in sequence */
                 |  (XIO_ADC1_CH_5TH  << 20)   /* 5th  Chan in sequence */
                 |  (XIO_ADC1_CH_6TH  << 25);  /* 6th  Chan in sequence */
    ADC1->SQR2    = (XIO_ADC1_CH_7TH  << 0)    /* 7th  Chan in sequence */
                 |  (XIO_ADC1_CH_8TH  << 5)    /* 8th  Chan in sequence */
                 |  (XIO_ADC1_CH_9TH  << 10)   /* 9th  Chan in sequence */
                 |  (XIO_ADC1_CH_10TH << 15)   /* 10th Chan in sequence */
                 |  (XIO_ADC1_CH_11TH << 20)   /* 11th Chan in sequence */
                 |  (XIO_ADC1_CH_12TH << 25);  /* 12th Chan in sequence */
    ADC1->SQR1    = (XIO_ADC1_CH_13TH << 0)    /* 13th Chan in sequence */
                 |  (XIO_ADC1_CH_14TH << 5)    /* 14th Chan in sequence */
                 |  (XIO_ADC1_CH_15TH << 10)   /* 15th Chan in sequence */
                 |  (XIO_ADC1_CH_16TH << 15)   /* 16th Chan in sequence */
                 | ((XIO_NUM_OF_ADC1-1)<<20);  /* Chan Size in sequence */
    ADC1->CR1    |=  ADC_CR1_SCAN;             /* Scan mode enable      */    //??????
    ADC1->CR2    |=  ADC_CR2_EXTTRIG           /* EXT triger Enabled    */   //????????
                 |   ADC_CR2_DMA;              /* DMA mode Enable       */   //??DMA??-?????????
    ADC1->CR2    |=  ADC_CR2_ADON;             /* A/D Converter On      */  //??ADC?????  ????0->1????????ADC
    ADC1->CR2    |=  ADC_CR2_RSTCAL;           /* Reset Calibration     */  //????????
    while((ADC1->CR2 & ADC_CR2_RSTCAL) != 0);  /* Wait for Calib reset  */ //???????????,??????0.
    ADC1->CR2    |=  ADC_CR2_CAL;              /* A/D Calibration       */  //A/D??
    while((ADC1->CR2 & ADC_CR2_CAL) != 0);     /* Wait for Calibration  */ //A/D?????,??????0.
}
/* ******************************************************************** */
/*                          XIOInitDma1Ch1Adc()                         */
/* ******************************************************************** */
void XIOInitDma1Ch1Adc (void)
{TESTZCADC[2]++;
   RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA clock enable   */
    DMA1_Channel1->CCR  &= ~DMA_CCR1_MEM2MEM   /* 0: Mem2mem mode off   */
                        &  ~DMA_CCR1_PL        /* 0: Priority low       */
                        &  ~DMA_CCR1_PSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR1_MSIZE     /* 00: 8-bits            */
                        &  ~DMA_CCR1_PINC      /* 0: Peripheral inc off */
                        &  ~DMA_CCR1_CIRC      /* 0: Circular mode off  */
                        &  ~DMA_CCR1_DIR       /* 0: Read from periphe  */
                        &  ~DMA_CCR1_TEIE      /* 0: TE interrupt off   */
                        &  ~DMA_CCR1_HTIE      /* 0: HT interrupt off   */
                        &  ~DMA_CCR1_TCIE;     /* 0: TC interrupt off   */
    DMA1_Channel1->CCR  |=  DMA_CCR1_MINC      /* Memory increment mode */
                        |   DMA_CCR1_MSIZE_0   /* 01: Memory size 16bit */
                        |   DMA_CCR1_PSIZE_0   /* 01: Peripheral siz 16 */
                        |   DMA_CCR1_PL_1;     /* 01: Priority High     */
    DMA1->IFCR           =  DMA_ISR_GIF1       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF1      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF1      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF1;     /* 1: clear TE flag      */
    DMA1_Channel1->CNDTR =  XIO_ADC_DMA_BUF_SIZ;
    DMA1_Channel1->CPAR  = (INT32U)&(ADC1->DR);
    DMA1_Channel1->CMAR  = (INT32U)pXIOAdcDmaBuf;
    DMA1_Channel1->CCR  |=  DMA_CCR1_TCIE
                        |   DMA_CCR1_EN;
    if (pXIOAdcDmaBuf   == &usXIOAdcDmaBuf0[0])
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf1[0];
    }   else
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf0[0];
    }
}

void XIODma1Ch1IntHook (void)
{   DMA1_Channel1->CCR  &= ~DMA_CCR1_EN;       /* 1: Channel disabled   */
    DMA1_Channel1->CPAR  = (INT32U)(&(ADC1->DR));
    DMA1_Channel1->CMAR  = (INT32U)pXIOAdcDmaBuf;
    DMA1_Channel1->CNDTR =  XIO_ADC_DMA_BUF_SIZ;
    DMA1->IFCR           =  DMA_ISR_GIF1       /* 1: clear Global flag  */
                        |   DMA_ISR_TCIF1      /* 1: clear TC flag      */
                        |   DMA_ISR_HTIF1      /* 1: clear HT flag      */
                        |   DMA_ISR_TEIF1;     /* 1: clear TE flag      */
    DMA1_Channel1->CCR  |=  DMA_CCR1_EN;       /* 1: Channel enabled    */
    if (pXIOAdcDmaBuf   == &usXIOAdcDmaBuf0[0])
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf1[0];
    }   else
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf0[0];
    }
    (void)OSIntTaskResume(FW_TASK_PRIO_XIO);
}


void XIOGetAdcChanDat (INT16U *pDmaBuf)  
{   INT32U uiNumb, uiSize;
    INT16U *pData;
    pData  = pDmaBuf;
    uiNumb = 0;
    uiSize = XIO_ADC_SMPL_SIZ;
    while (uiSize--)
    {   ssXIOAdcChDat0[uiNumb]  = *pData++;
        ssXIOAdcChDat1[uiNumb]  = *pData++;
        ssXIOAdcChDat2[uiNumb]  = *pData++;
        ssXIOAdcChDat3[uiNumb]  = *pData++;
        ssXIOAdcChDat4[uiNumb]  = *pData++;
        ssXIOAdcChDat5[uiNumb]  = *pData++;
        ssXIOAdcChDat6[uiNumb]  = *pData++;
        ssXIOAdcChDat7[uiNumb]  = *pData++;
        ssXIOAdcChDat8[uiNumb]  = *pData++;
        ssXIOAdcChDat9[uiNumb]  = *pData++;
        ssXIOAdcChDat10[uiNumb] = *pData++;
        ssXIOAdcChDat11[uiNumb] = *pData++;
        ssXIOAdcChDat12[uiNumb] = *pData++;
        ssXIOAdcChDat13[uiNumb] = *pData++;
        ssXIOAdcChDat14[uiNumb] = *pData++;
        ssXIOAdcChDat15[uiNumb] = *pData++;
        uiNumb++;
    }
}

/* ******************************************************************** */
/*                             XIOInitTim1()                            */
/* ******************************************************************** */
void XIOInitTim1 (void)
{   RCC->APB2ENR  |=  RCC_APB2ENR_TIM1EN;    /* 1: TIM1 clock enable    */
    RCC->APB2RSTR |=  RCC_APB2RSTR_TIM1RST;  /* 1: TIM1 clock reset     */
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST;  /* 0: TIM1 reset stop      */
    TIM1->CR1      =  0;                     /* TIM1 control register 1 */
    TIM1->CR2      =  0;                     /* TIM1 control register 2 */
    TIM1->SMCR     =  0;                     /* TIM1 slave mode control */
    TIM1->DIER     =  0;                     /* TIM1 DMA/Interrupt en   */
    TIM1->SR       =  0;                     /* TIM1 status register    */
    TIM1->EGR      =  0;                     /* TIM1 event generation   */
    TIM1->CCMR1    =  0;                     /* Capture/compare mode 1  */
    TIM1->CCMR2    =  0;                     /* Capture/compare mode 2  */
    TIM1->CCER     =  0;                     /* Capture/compare enable  */
    TIM1->CNT      =  0;                     /* TIM1 counter            */
    TIM1->PSC      =  71;                    /* Prescaler: 72(1us)      */
    TIM1->ARR      =  0xFFFF;                /* TIM1 auto-reload        */
    TIM1->RCR      =  0;                     /* TIM1 control register 1 */
    TIM1->CCR1     =  0;                     /* Capture/compare reg 1   */
    TIM1->CCR2     =  0;                     /* Capture/compare reg 2   */
    TIM1->CCR3     =  0;                     /* Capture/compare reg 3   */
    TIM1->CCR4     =  0;                     /* Capture/compare reg 4   */
    TIM1->BDTR     =  0;                     /* break and dead-time     */
    TIM1->DCR      =  0;                     /* DMA control register    */
    TIM1->DMAR     =  0;                     /* DMA address for full tr */
}

/* ******************************************************************** */
/*                       XIOInitTim1AdcTriger()                         */
/* ******************************************************************** */
void XIOInitTim1AdcTriger (void)
{   TIM1->CCMR1   |=  TIM_CCMR1_OC1M_2       /* CH1: 110, PWM mode 1    */
                  |   TIM_CCMR1_OC1M_1;      /* (111: PWM mode 2)       */
    TIM1->ARR      =  XIO_ADC_SMPL_TIM_US-1; /* Pwm Period              */
    TIM1->CCR1     =  XIO_ADC_SMPL_TIM_US/2; /* Pwm Duty                */
    TIM1->CCER    |=  TIM_CCER_CC1E;         /* OC1 enable              */
    TIM1->EGR      =  TIM_EGR_UG;            /* UG: Update generation   */
    TIM1->BDTR    |=  TIM_BDTR_MOE;          /* TIM1 Outputs enabled    */
    TIM1->CR1     |=  TIM_CR1_CEN;           /* 1: Counter enabled      */
}


void XIOStart (void)
{   (void)XIOInitTim1AdcTriger();
    (void)FWIrqEnable(DMA1_Channel1_IRQn, 0);
   // (void)FWIrqEnable(TIM2_IRQn, 0);
}

INT16U aDBMeas[20];

INT16S SFGetAve16s (INT16S *pData, INT16U usSize)
{   INT32S siSum;
    INT16U usSiz;
    siSum = 0;
    usSiz = usSize / 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
        siSum += (INT32S)(*pData++);
    }
    usSiz = usSize % 8;
    while (usSiz--)
    {   siSum += (INT32S)(*pData++);
    }
    return (INT16S)(siSum / usSize);
}

void XIOTaskLoop(void)
{

	while(1)
	{
        (void)OSTaskSuspend(OS_PRIO_SELF);	
		
				(void)XIOGetAdcChanDat(pXIOAdcDmaBuf);
			
        aDBMeas[0]  = SFGetAve16s(ssXIOAdcChDat0, XIO_ADC_SMPL_SIZ);
        aDBMeas[1]  = SFGetAve16s(ssXIOAdcChDat1, XIO_ADC_SMPL_SIZ);
        aDBMeas[2]  = SFGetAve16s(ssXIOAdcChDat2, XIO_ADC_SMPL_SIZ);
        aDBMeas[3]  = SFGetAve16s(ssXIOAdcChDat3, XIO_ADC_SMPL_SIZ);
        aDBMeas[4]  = SFGetAve16s(ssXIOAdcChDat4, XIO_ADC_SMPL_SIZ);
        aDBMeas[5]  = SFGetAve16s(ssXIOAdcChDat5, XIO_ADC_SMPL_SIZ);
        aDBMeas[6]  = SFGetAve16s(ssXIOAdcChDat6, XIO_ADC_SMPL_SIZ);
        aDBMeas[7]  = SFGetAve16s(ssXIOAdcChDat7, XIO_ADC_SMPL_SIZ);
        aDBMeas[8]  = SFGetAve16s(ssXIOAdcChDat8, XIO_ADC_SMPL_SIZ);
        aDBMeas[9]  = SFGetAve16s(ssXIOAdcChDat9, XIO_ADC_SMPL_SIZ);
        aDBMeas[10] = SFGetAve16s(ssXIOAdcChDat10,XIO_ADC_SMPL_SIZ);
        aDBMeas[11] = SFGetAve16s(ssXIOAdcChDat11,XIO_ADC_SMPL_SIZ);   //????
        aDBMeas[12] = SFGetAve16s(ssXIOAdcChDat12,XIO_ADC_SMPL_SIZ);
        aDBMeas[13] = SFGetAve16s(ssXIOAdcChDat13,XIO_ADC_SMPL_SIZ);
        aDBMeas[14] = SFGetAve16s(ssXIOAdcChDat14,XIO_ADC_SMPL_SIZ);
        aDBMeas[15] = SFGetAve16s(ssXIOAdcChDat15,XIO_ADC_SMPL_SIZ);	
	}
}
/************************END OF FILE************/




