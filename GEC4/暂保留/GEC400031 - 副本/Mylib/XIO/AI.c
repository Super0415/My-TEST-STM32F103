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
 * ��������ADC1_GPIO_Config
 * ����  ��ʹ��ADC1��DMA1��ʱ�ӣ���ʼ��PC.00 PC.01 PC.02 PC.03 PA.01 PA.02
 * ����  : ��
 * ���  ����
 * ����  ���ڲ�����
 **********************************************************/
static void ADC1_GPIO_Config(void)
{
//	GPIO_InitTypeDef GPIO_InitStructure;
	
	DMA_InitTypeDef DMA_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;	
	
	/* Enable DMA clock */
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);	
	
	/*����ADCʱ�ӣ�ΪPCLK2��2��Ƶ����24/2=12mHz*/
  #if(SYS_FreqSYSCLK==72)
	  RCC_ADCCLKConfig(RCC_PCLK2_Div6);
  #elif(SYS_FreqSYSCLK==24)
	  RCC_ADCCLKConfig(RCC_PCLK2_Div2);
  #endif		
	
	/* Enable ADC1 and GPIOC clock */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOC, ENABLE);
	
	/* Configure PC.00 PC.01 PC.02 PC.03  as analog input */
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
//	GPIO_Init(GPIOC, &GPIO_InitStructure);				
	
	/* Configure PA.01  as analog input */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* Configure PB.01  as analog input */
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);		

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
    
//}


///* ��������ADC1_Mode_Config
// * ����  ������ADC1�Ĺ���ģʽΪMDAģʽ
// * ����  : ��
// * ���  ����
// * ����  ���ڲ�����
// */

//static void ADC1_Mode_Config(void)
//{
//	DMA_InitTypeDef DMA_InitStructure;
//	ADC_InitTypeDef ADC_InitStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
	
	//RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

//@@@@@
   ADC_DeInit(ADC1);   //����ADC1�Ĵ���Ϊȱʡֵ
//@@@@@@@

	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;	//����ADCģʽ
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;//ENABLEɨ��ģʽ���ڶ�ͨ���ɼ�//DISABLE����(��ͨ��)ģʽ
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;	//��������ת��ģʽ������ͣ�ؽ���ADCת��
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;//ADC_ExternalTrigConv_None;	//��ʹ���ⲿ����ת�� //ADC_ExternalTrigConv_T1_CC1
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right; 	//�ɼ������Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = AI_CON;	 	//Ҫת����ͨ����Ŀ1
	ADC_Init(ADC1, &ADC_InitStructure);
	
		//����ָ��ADC�Ĺ�����ͨ����     �������ǵ�ת��˳��Ͳ���ʱ��  ADC_SampleTime_28Cycles5  ADC_SampleTime_55Cycles5
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 1, ADC_SampleTime_28Cycles5); //����Ua   //PA5
	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 2, ADC_SampleTime_28Cycles5); //����Ub   //PA6
	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 3, ADC_SampleTime_28Cycles5); //����Uc   //PA7
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 4, ADC_SampleTime_28Cycles5); //�Զ���3   //PC0
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 5, ADC_SampleTime_28Cycles5); //�Զ���4   //PC1
	ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 6, ADC_SampleTime_28Cycles5); //�¶�      //PC2
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 7, ADC_SampleTime_28Cycles5); //��ѹ      //PC3
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8,  8, ADC_SampleTime_28Cycles5); //D+            PB0
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9,  9, ADC_SampleTime_28Cycles5); //��ص�ѹ      PB1
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 10, ADC_SampleTime_28Cycles5); //IA   PA1
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 11, ADC_SampleTime_28Cycles5); //IB   PA2
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 12, ADC_SampleTime_28Cycles5); //IC   PA3
	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 13, ADC_SampleTime_28Cycles5); //1.65v�е��ѹ	  PA4
//@@@
/*
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 14, ADC_SampleTime_28Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_14,15, ADC_SampleTime_28Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_15,16, ADC_SampleTime_28Cycles5);	
*/
	
	ADC_DMACmd(ADC1,ENABLE);//��ADC��DMA������һ��
	
	ADC_Cmd(ADC1,ENABLE);	/* Enable ADC1 */

  ADC_ResetCalibration(ADC1);  //����ָ����ADC��У׼�Ĵ���
	while(ADC_GetResetCalibrationStatus(ADC1));  /*�ȴ�У׼�Ĵ�����λ��� */
	ADC_StartCalibration(ADC1);	/* ADCУ׼ */
	while(ADC_GetCalibrationStatus(ADC1));/* �ȴ�У׼���*/
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);//ʹ�ܻ���ʧ��ָ����ADC�����ת���������� 
	

	/* DMA channel1 configuration */
	DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_PeripheralBaseAddr =(u32)&ADC1->DR;// ADC1_DR_Address;	 //ADC��ַ
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)&ADC_ConvertedValue;//�ڴ��ַ
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize = AI_CON;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//�����ַ�̶�
	DMA_InitStructure.DMA_MemoryInc =DMA_MemoryInc_Enable; //�ڴ��ַ����  //DMA_MemoryInc_Disable;  //�ڴ��ַ�̶�

	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	//�������ݿ��16  
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;//�洢���ݿ��16
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;		//ѭ�����洫��
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;//DMAͨ��xӵ�и����ȼ�
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;  //DMAͨ��xû������Ϊ�ڴ浽�ڴ洫��
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);  //ADC1��DMA1ͨ��1��
	/* Enable DMA channel1 */
	DMA_Cmd(DMA1_Channel1, ENABLE);  //ʹ��DMA1	

	/*����ADC1��ͨ��11Ϊ55.	5���������ڣ�����Ϊ1 */
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 1, ADC_SampleTime_55Cycles5);//�е�Ua
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_7,  2, ADC_SampleTime_55Cycles5);//�е�Ub
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 3, ADC_SampleTime_55Cycles5);//�е�Uc

//	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 4, ADC_SampleTime_55Cycles5); //����Ua
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 5, ADC_SampleTime_55Cycles5); //����Ub
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 6, ADC_SampleTime_55Cycles5); //����Uc
//	
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 7, ADC_SampleTime_55Cycles5); //�Զ���3
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 8, ADC_SampleTime_55Cycles5); //�Զ���4
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 9, ADC_SampleTime_55Cycles5); //�¶�
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_13,10, ADC_SampleTime_55Cycles5); //��ѹ
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 11, ADC_SampleTime_55Cycles5); //D+
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_9, 12, ADC_SampleTime_55Cycles5); //��ص�ѹ
//	
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 13, ADC_SampleTime_55Cycles5); //IA
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 14, ADC_SampleTime_55Cycles5); //IB
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 15, ADC_SampleTime_55Cycles5); //IC
//	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 16, ADC_SampleTime_55Cycles5); //1.65v�е��ѹ

	
//����DMA�ж�	
	DMA_ITConfig(DMA1_Channel1,DMA_IT_TC,ENABLE);		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel1_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure); 	
}

#endif

/*
 * ��������ADC1_Init
 * ����  ����
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 */
 int TESTZCADC[20];
void ADC1_Init(void)
{
#if(AI_ENABLE == 1)	
	ADC1_GPIO_Config();
	XIOInitTim1();
	XIOInitTim1AdcTriger();	
	
#endif	
	TESTZCADC[0]++;
#if(AI_ENABLE == 0)	
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@ZC
	pXIOAdcDmaBuf   = &usXIOAdcDmaBuf0[0];    //DMA??ADC????
    (void)XIOInitADC1();        //ADC1???
    (void)XIOInitDma1Ch1Adc();
	XIOInitTim1();
	XIOInitTim1AdcTriger();
#endif
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
    ADC1->CR1    &= ~ADC_CR1_EOCIE             /* EOC Interrupt disable */  //����ж�
                 &  ~ADC_CR1_AWDIE             /* Analog Watchdog inter */
                 &  ~ADC_CR1_JEOCIE            /* Injected chan interru */
                 &  ~ADC_CR1_SCAN              /* Scan mode disable     */
                 &  ~ADC_CR1_AWDSGL            /* Disnable the watchdog */
                 &  ~ADC_CR1_JAUTO             /* Injected group conver */
                 &  ~ADC_CR1_DISCEN            /* Discontinuous mode    */
                 &  ~ADC_CR1_JDISCEN;          /* Discontinuous mode    */   //��λ����ж�
    ADC1->CR2    &= ~ADC_CR2_ADON              /* A/D Converter OFF     */  //�ر�ADC����ϵ�ģʽ
                 &  ~ADC_CR2_CONT              /* Continuous Conversion */
                 &  ~ADC_CR2_CAL               /* A/D Calibration       */
                 &  ~ADC_CR2_DMA               /* DMA mode disable      */
                 &  ~ADC_CR2_ALIGN             /* Data Alignment right  */
                 &  ~ADC_CR2_EXTSEL            /* EXTSEL[2:0]=0: T1_CC1 */
                 &  ~ADC_CR2_EXTTRIG;          /* EXT triger Disabled   */  //��λ���״̬
    ADC1->SMPR2   = (XIO_ADC1_SMPL_CYC << 0)   /* Chan 0  Sample Cycles */   //��������ͨ��ɨ������
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
    ADC1->SQR3    = (XIO_ADC1_CH_1ST  << 0)    /* 1st  Chan in sequence */  //���������е�һ��ת��
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
                 | ((XIO_NUM_OF_ADC1-1)<<20);  /* Chan Size in sequence */   //����ͨ������
    ADC1->CR1    |=  ADC_CR1_SCAN;             /* Scan mode enable      */   //����ɨ��ģʽ
    ADC1->CR2    |=  ADC_CR2_EXTTRIG           /* EXT triger Enabled    */   //ʹ���ⲿ�¼�����--<<<<<<
                 |   ADC_CR2_DMA;              /* DMA mode Enable       */   //ʹ��DMAģʽ
    ADC1->CR2    |=  ADC_CR2_ADON;             /* A/D Converter On      */   //����ADC������ת��
    ADC1->CR2    |=  ADC_CR2_RSTCAL;           /* Reset Calibration     */   //��λУ׼
    while((ADC1->CR2 & ADC_CR2_RSTCAL) != 0);  /* Wait for Calib reset  */
    ADC1->CR2    |=  ADC_CR2_CAL;              /* A/D Calibration       */   //ADУ׼
    while((ADC1->CR2 & ADC_CR2_CAL) != 0);     /* Wait for Calibration  */
		TESTZCADC[1]++;
}
/* ******************************************************************** */
/*                          XIOInitDma1Ch1Adc()                         */
/* ******************************************************************** */
void XIOInitDma1Ch1Adc (void)
{TESTZCADC[2]++;
	RCC->AHBENR         |=  RCC_AHBENR_DMA1EN; /* 1: DMA clock enable   */
    DMA1_Channel1->CCR  &= ~DMA_CCR1_MEM2MEM   /* 0: Mem2mem mode off   */  //���üĴ�����λ  --�Ǵ洢�����洢��ģʽ
                        &  ~DMA_CCR1_PL        /* 0: Priority low       */  //ͨ�����ȼ���
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
    DMA1_Channel1->CMAR  = (INT32U)pXIOAdcDmaBuf;    //��ȡ�ڴ��ַ
    DMA1_Channel1->CCR  |=  DMA_CCR1_TCIE            //������ɲ����ж�
                        |   DMA_CCR1_EN;
    if (pXIOAdcDmaBuf   == &usXIOAdcDmaBuf0[0])
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf1[0];
    }   else
    {   pXIOAdcDmaBuf    = &usXIOAdcDmaBuf0[0];
    }
		TESTZCADC[3]++;
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
    (void)OSIntTaskResume(FW_TASK_PRIO_XIO);  //��������
		TESTZCADC[4]++;
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
//        ssXIOAdcChDat13[uiNumb] = *pData++;
//        ssXIOAdcChDat14[uiNumb] = *pData++;
//        ssXIOAdcChDat15[uiNumb] = *pData++;
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
{   TIM1->CCMR1   |=  TIM_CCMR1_OC1M_2       /* CH1: 110, PWM mode 1    */  //110-PWM mode 1
                  |   TIM_CCMR1_OC1M_1;      /* (111: PWM mode 2)       */
    TIM1->ARR      =  XIO_ADC_SMPL_TIM_US-1; /* Pwm Period              */
    TIM1->CCR1     =  XIO_ADC_SMPL_TIM_US/2; /* Pwm Duty                */
    TIM1->CCER    |=  TIM_CCER_CC1E;         /* OC1 enable              */
    TIM1->EGR      =  TIM_EGR_UG;            /* UG: Update generation   */  //���³�ʼ��������������һ�������¼�
    TIM1->BDTR    |=  TIM_BDTR_MOE;          /* TIM1 Outputs enabled    */
    TIM1->CR1     |=  TIM_CR1_CEN;            /* 1: Counter enabled      */  //ʹ�ܼ�����
}



//#endif

/************************END OF FILE************/




