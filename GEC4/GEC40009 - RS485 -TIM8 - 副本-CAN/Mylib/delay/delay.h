#ifndef __DELAY_H
#define __DELAY_H

//#include "ALL_Includes.h"
#include "TYPCortex.h"
#define TMR_NUM        60 


void TimingDelay_Decrement(void);



extern u32    TimerEnArr[TMR_NUM];
extern u32    TimerTrig[TMR_NUM];
extern u32    TimerValue[TMR_NUM];
extern u32    TimerSet[TMR_NUM];
extern u32    TimerMode[TMR_NUM];

extern unsigned long Timer_Mcon;

void TIM2_PITTIMER_Cfig(void);
void Delay_CHtim2Period(u16 CHPeriod);
void TIM4_TIMER_Config(void);
extern void TIM4_IRQHandler_it(void);

#endif

