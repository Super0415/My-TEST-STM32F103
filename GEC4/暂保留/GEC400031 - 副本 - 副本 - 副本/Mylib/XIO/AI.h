#ifndef __AI_H
#define __AI_H

#include "TYPCortex.h"

#define  AI_CON    16   //需要转换的模拟量通道数
extern __IO uint16_t ADC_ConvertedValue[AI_CON];


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ZC
#define XIO_ADC_SMPL_SIZ         64
#define XIO_NUM_OF_ADC1         (INT32U)16
#define XIO_ADC_SMPL_SIZ         64
#define XIO_ADC_SMPL_PRD_US      20000
#define XIO_ADC_SMPL_TIM_US     (XIO_ADC_SMPL_PRD_US / XIO_ADC_SMPL_SIZ)
#define XIO_ADC_DMA_BUF_SIZ     (XIO_NUM_OF_ADC1 * XIO_ADC_SMPL_SIZ)

#define  XIO_EXT extern

/* **************** ADC1 (All External Inputs) Definitions ************ */
#define XIO_NUM_OF_ADC1         (INT32U)16
#define XIO_ADC1_SMPL_CYC       (INT32U)3      /* 28.5 Cycles           */
#define XIO_ADC_IN_MAIN_VA      (INT32U)10     /* Pin15, PC0, ADC1-Ch10 */
#define XIO_ADC_IN_MAIN_VB      (INT32U)11     /* Pin16, PC1, ADC1-Ch11 */
#define XIO_ADC_IN_MAIN_VC      (INT32U)12     /* Pin17, PC2, ADC1-Ch12 */
#define XIO_ADC_IN_GENS_VA      (INT32U)13     /* Pin18, PC3, ADC1-Ch13 */
#define XIO_ADC_IN_GENS_VB      (INT32U)4      /* Pin29, PA4, ADC1-Ch4  */
#define XIO_ADC_IN_GENS_VC      (INT32U)5      /* Pin30, PA5, ADC1-Ch5  */
#define XIO_ADC_IN_GENS_IA      (INT32U)6      /* Pin31, PA6, ADC1-Ch6  */
#define XIO_ADC_IN_GENS_IB      (INT32U)7      /* Pin32, PA7, ADC1-Ch7  */
#define XIO_ADC_IN_GENS_IC      (INT32U)14     /* Pin33, PC4, ADC1-Ch14 */
#define XIO_ADC_IN_TEMP_9       (INT32U)0      /* Pin23, PA0, ADC1-Ch0  */
#define XIO_ADC_IN_TEMP_10      (INT32U)1      /* Pin24, PA1, ADC1-Ch1  */
#define XIO_ADC_IN_TEMP_11      (INT32U)2      /* Pin25, PA2, ADC1-Ch2  */
#define XIO_ADC_IN_TEMP_12      (INT32U)3      /* Pin26, PA3, ADC1-Ch3  */
#define XIO_ADC_IN_TEMP_13      (INT32U)8      /* Pin35, PB0, ADC1-Ch8  */
#define XIO_ADC_IN_TEMP_14      (INT32U)9      /* Pin36, PB1, ADC1-Ch9  */
#define XIO_ADC_IN_TEMP_15      (INT32U)15     /* Pin34, PC5, ADC1-Ch15 */
#define XIO_ADC1_CH_1ST          XIO_ADC_IN_MAIN_VA
#define XIO_ADC1_CH_2ND          XIO_ADC_IN_GENS_VA
#define XIO_ADC1_CH_3RD          XIO_ADC_IN_GENS_IA
#define XIO_ADC1_CH_4TH          XIO_ADC_IN_MAIN_VB
#define XIO_ADC1_CH_5TH          XIO_ADC_IN_GENS_VB
#define XIO_ADC1_CH_6TH          XIO_ADC_IN_GENS_IB
#define XIO_ADC1_CH_7TH          XIO_ADC_IN_MAIN_VC
#define XIO_ADC1_CH_8TH          XIO_ADC_IN_GENS_VC
#define XIO_ADC1_CH_9TH          XIO_ADC_IN_GENS_IC
#define XIO_ADC1_CH_10TH         XIO_ADC_IN_TEMP_9
#define XIO_ADC1_CH_11TH         XIO_ADC_IN_TEMP_10
#define XIO_ADC1_CH_12TH         XIO_ADC_IN_TEMP_11
#define XIO_ADC1_CH_13TH         XIO_ADC_IN_TEMP_12
#define XIO_ADC1_CH_14TH         XIO_ADC_IN_TEMP_13
#define XIO_ADC1_CH_15TH         XIO_ADC_IN_TEMP_14
#define XIO_ADC1_CH_16TH         XIO_ADC_IN_TEMP_15
#define XIO_ADC_NO_MAIN_VA      (INT32U)0
#define XIO_ADC_NO_GENS_VA      (INT32U)1
#define XIO_ADC_NO_GENS_IA      (INT32U)2
#define XIO_ADC_NO_MAIN_VB      (INT32U)3
#define XIO_ADC_NO_GENS_VB      (INT32U)4
#define XIO_ADC_NO_GENS_IB      (INT32U)5
#define XIO_ADC_NO_MAIN_VC      (INT32U)6
#define XIO_ADC_NO_GENS_VC      (INT32U)7
#define XIO_ADC_NO_GENS_IC      (INT32U)8
#define XIO_ADC_NO_TEMP_9       (INT32U)9
#define XIO_ADC_NO_TEMP_10      (INT32U)10
#define XIO_ADC_NO_TEMP_11      (INT32U)11
#define XIO_ADC_NO_TEMP_12      (INT32U)12
#define XIO_ADC_NO_TEMP_13      (INT32U)13
#define XIO_ADC_NO_TEMP_14      (INT32U)14
#define XIO_ADC_NO_TEMP_15      (INT32U)15
/* *************************** GPIO Config **************************** */
#define XIO_PT_MOD_IN           (INT32U)(0x00)
#define XIO_PT_MOD_10M          (INT32U)(0x01)
#define XIO_PT_MOD_02M          (INT32U)(0x02)
#define XIO_PT_MOD_50M          (INT32U)(0x03)
#define XIO_PT_IN_ANALOG        (INT32U)(0x00 << 2)
#define XIO_PT_IN_FLOAT         (INT32U)(0x01 << 2)
#define XIO_PT_IN_PULL          (INT32U)(0x02 << 2)
#define XIO_PT_OUT_PP           (INT32U)(0x00 << 2)
#define XIO_PT_OUT_OD           (INT32U)(0x01 << 2)
#define XIO_PT_ALT_PP           (INT32U)(0x02 << 2)
#define XIO_PT_ALT_OD           (INT32U)(0x03 << 2)
#define XIO_PT_GPI_ANALOG       (XIO_PT_MOD_IN + XIO_PT_IN_ANALOG)
#define XIO_PT_GPI_FLOAT        (XIO_PT_MOD_IN + XIO_PT_IN_FLOAT)
#define XIO_PT_GPI_PULL         (XIO_PT_MOD_IN + XIO_PT_IN_PULL)
#define XIO_PT_GPO_PP_10M       (XIO_PT_OUT_PP + XIO_PT_MOD_10M)
#define XIO_PT_GPO_OD_10M       (XIO_PT_OUT_OD + XIO_PT_MOD_10M)
#define XIO_PT_ALT_PP_10M       (XIO_PT_ALT_PP + XIO_PT_MOD_10M)
#define XIO_PT_ALT_OD_10M       (XIO_PT_ALT_OD + XIO_PT_MOD_10M)
#define XIO_PT_GPO_PP_02M       (XIO_PT_OUT_PP + XIO_PT_MOD_02M)
#define XIO_PT_GPO_OD_02M       (XIO_PT_OUT_OD + XIO_PT_MOD_02M)
#define XIO_PT_ALT_PP_02M       (XIO_PT_ALT_PP + XIO_PT_MOD_02M)
#define XIO_PT_ALT_OD_02M       (XIO_PT_ALT_OD + XIO_PT_MOD_02M)
#define XIO_PT_GPO_PP_50M       (XIO_PT_OUT_PP + XIO_PT_MOD_50M)
#define XIO_PT_GPO_OD_50M       (XIO_PT_OUT_OD + XIO_PT_MOD_50M)
#define XIO_PT_ALT_PP_50M       (XIO_PT_ALT_PP + XIO_PT_MOD_50M)
#define XIO_PT_ALT_OD_50M       (XIO_PT_ALT_OD + XIO_PT_MOD_50M)
#define XIO_PT_SET_0            (INT16U)0
#define XIO_PT_SET_1            (INT16U)1
#define XIO_PT_BT0              (INT08U)0
#define XIO_PT_BT1              (INT08U)1
#define XIO_PT_BT2              (INT08U)2
#define XIO_PT_BT3              (INT08U)3
#define XIO_PT_BT4              (INT08U)4
#define XIO_PT_BT5              (INT08U)5
#define XIO_PT_BT6              (INT08U)6
#define XIO_PT_BT7              (INT08U)7
#define XIO_PT_BT8              (INT08U)8
#define XIO_PT_BT9              (INT08U)9
#define XIO_PT_BT10             (INT08U)10
#define XIO_PT_BT11             (INT08U)11
#define XIO_PT_BT12             (INT08U)12
#define XIO_PT_BT13             (INT08U)13
#define XIO_PT_BT14             (INT08U)14
#define XIO_PT_BT15             (INT08U)15

XIO_EXT INT16U *pXIOAdcDmaBuf;
XIO_EXT INT16U usXIOAdcDmaBuf0[XIO_ADC_DMA_BUF_SIZ];
XIO_EXT INT16U usXIOAdcDmaBuf1[XIO_ADC_DMA_BUF_SIZ];

XIO_EXT INT16S ssXIOAdcChDat0[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat1[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat2[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat3[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat4[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat5[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat6[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat7[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat8[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat9[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat10[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat11[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat12[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat13[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat14[XIO_ADC_SMPL_SIZ];
XIO_EXT INT16S ssXIOAdcChDat15[XIO_ADC_SMPL_SIZ];

void XIODma1Ch1IntHook (void);
void XIOInitDma1Ch1Adc (void);
void ADC1_Init(void);
void XIOInitADC1 (void);
void XIOGetAdcChanDat (INT16U *pDmaBuf);
void XIOConfigGPIO (GPIO_TypeDef *pPt, INT08U ucBit, INT32U uiMod, INT16U usSet);
void XIOInitTim1 (void);
void XIOInitTim1AdcTriger (void);
void XIOStart (void);

#endif
