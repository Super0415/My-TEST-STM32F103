#ifndef __AI_H
#define __AI_H

#include "TYPCortex.h"

#define  AI_CON    16   //需要转换的模拟量通道数
extern __IO uint16_t ADC_ConvertedValue[AI_CON];

void ADC1_Init(void);

#endif
