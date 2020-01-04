#include "TIM.h"

//??????
void Tim_Init(void)
{

    //????????
	NVIC_InitTypeDef NVIC_InitStructure;
	//????????
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	//?????3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    //TIM3?????,???APB1?

//???????	,????????????
TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //??????	
	
//????????
   //??1?	
                                                      //??????72MHz
    TIM_TimBaseInitStructure.TIM_Period = 2000;     //????2000 = 72000000/36000      
    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //??? 36000

   //??0.5?	
                                                      //??????72MHz
//    TIM_TimBaseInitStructure.TIM_Period = 1000;     //????2000 = 72000000/36000     ???2000??1?,????1000,???0.5?  
//    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //??? 36000	
	
	TIM_TimBaseInitStructure.TIM_ClockDivision =  TIM_CKD_DIV1;                  //???????
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //??????
	TIM_TimeBaseInit(TIM3, & TIM_TimBaseInitStructure);                //?????3
//?????	
	TIM_Cmd(TIM3, ENABLE);
//???????	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );
	
//*******************************************?????*******************************************************************************************	
//??:??????????,????,??ì|î??????	

//??NVIC??	                                                                           
	/* Configure the Priority Grouping with 1 bit */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //??
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;   //??????   TIM3_IRQn    //?TIM3
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //?????
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //?????
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		
//*******************************************?????*******************************************************************************************


}

//∂® ±∆˜≥ı ºªØ
void Tim3_Init(void)
{

    //÷–∂œ”≈œ»º∂Ω·ππÃÂ
	NVIC_InitTypeDef NVIC_InitStructure;
	//∂® ±∆˜≈‰÷√Ω·ππÃÂ
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	//¥Úø™∂® ±∆˜3
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);    //TIM3Œ™∆’Õ® ±÷”£¨π“‘ÿ‘⁄APB1…œ

//œ»«Âø’ ±÷”÷–∂œ	,∑¿÷π≥ı ºªØ ±¥À÷–∂œ±ª¥•∑¢
TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //«Â≥˝ ±÷”÷–∂œ	
	
//∂® ±∆˜≈‰÷√≥ı ºªØ
   //∂® ±1√Î	
                                                      // π”√œµÕ≥ ±÷”72MHz
    TIM_TimBaseInitStructure.TIM_Period = 2000;     //∂® ±º∆ ˝2000 = 72000000/36000      
    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //‘§∑÷∆µ 36000

   //∂® ±0.5√Î	
                                                      // π”√œµÕ≥ ±÷”72MHz
//    TIM_TimBaseInitStructure.TIM_Period = 1000;     //∂® ±º∆ ˝2000 = 72000000/36000     º∆ ˝µΩ2000≤≈Œ™1√Î£¨÷ÿ◊∞÷µŒ™1000£¨‘Ú∫ƒ ±0.5√Î  
//    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //‘§∑÷∆µ 36000	
	
	TIM_TimBaseInitStructure.TIM_ClockDivision =  TIM_CKD_DIV1;                  //≤ª π”√ ±÷”«–∏Ó
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //œÚ…œº∆ ˝ƒ£ Ω
	TIM_TimeBaseInit(TIM3, & TIM_TimBaseInitStructure);                // π”√∂® ±∆˜3
//∂® ±∆˜ πƒ‹	
	TIM_Cmd(TIM3, ENABLE);
//∂® ±∆˜÷–∂œ πƒ‹	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE );
	
//*******************************************”≈œ»º∂…Ë÷√*******************************************************************************************	
//◊¢“‚:”≈œ»º∂…Ë÷√±ÿ–Î“ª∂‘“ª£¨÷∏ˆ…Ë÷√£¨≤ªƒ‹°∞|°±Ω¯––∂‡∏ˆ≈‰÷√	

//…Ë÷√NVIC≤Œ ˝	                                                                           
	/* Configure the Priority Grouping with 1 bit */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //∑÷◊È
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;   //÷–∂œ∫Ø ˝»Îø⁄   TIM3_IRQn    //∂‘TIM3
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //«¿’º”≈œ»º∂
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;           //œÏ”¶”≈œ»º∂
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		
//*******************************************”≈œ»º∂…Ë÷√*******************************************************************************************


}


//∂® ±∆˜≥ı ºªØ
void Tim8_Init(void)
{

    //÷–∂œ”≈œ»º∂Ω·ππÃÂ
	NVIC_InitTypeDef NVIC_InitStructure;
	//∂® ±∆˜≈‰÷√Ω·ππÃÂ
	TIM_TimeBaseInitTypeDef TIM_TimBaseInitStructure;
	//¥Úø™∂® ±∆˜3
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);    //TIM3Œ™∆’Õ® ±÷”£¨π“‘ÿ‘⁄APB1…œ

//œ»«Âø’ ±÷”÷–∂œ	,∑¿÷π≥ı ºªØ ±¥À÷–∂œ±ª¥•∑¢
TIM_ClearITPendingBit(TIM8,TIM_IT_Update);  //«Â≥˝ ±÷”÷–∂œ	
	
//∂® ±∆˜≈‰÷√≥ı ºªØ
   //∂® ±1√Î	
                                                      // π”√œµÕ≥ ±÷”72MHz
    TIM_TimBaseInitStructure.TIM_Period = 2000;     //∂® ±º∆ ˝2000 = 72000000/36000      
    TIM_TimBaseInitStructure.TIM_Prescaler = 71999; //‘§∑÷∆µ 72000

   //∂® ±0.5√Î	
                                                      // π”√œµÕ≥ ±÷”72MHz
//    TIM_TimBaseInitStructure.TIM_Period = 1000;     //∂® ±º∆ ˝2000 = 72000000/36000     º∆ ˝µΩ2000≤≈Œ™1√Î£¨÷ÿ◊∞÷µŒ™1000£¨‘Ú∫ƒ ±0.5√Î  
//    TIM_TimBaseInitStructure.TIM_Prescaler = 35999; //‘§∑÷∆µ 36000	
	
	TIM_TimBaseInitStructure.TIM_ClockDivision = 0;                  //≤ª π”√ ±÷”«–∏Ó
	TIM_TimBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;   //œÚ…œº∆ ˝ƒ£ Ω
	TIM_TimeBaseInit(TIM8, & TIM_TimBaseInitStructure);                // π”√∂® ±∆˜3
//∂® ±∆˜ πƒ‹	
	TIM_Cmd(TIM8, ENABLE);
//∂® ±∆˜÷–∂œ πƒ‹	
	TIM_ITConfig(TIM8, TIM_IT_Update, ENABLE );
	
//*******************************************”≈œ»º∂…Ë÷√*******************************************************************************************	
//◊¢“‚:”≈œ»º∂…Ë÷√±ÿ–Î“ª∂‘“ª£¨÷∏ˆ…Ë÷√£¨≤ªƒ‹°∞|°±Ω¯––∂‡∏ˆ≈‰÷√	

//…Ë÷√NVIC≤Œ ˝	                                                                           
	/* Configure the Priority Grouping with 1 bit */
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //∑÷◊È
	/* Enable TIM3 global interrupt with Preemption Priority 0 and Sub
	Priority as 2 */
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_IRQn;   //÷–∂œ∫Ø ˝»Îø⁄   TIM3_IRQn    //∂‘TIM3
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //«¿’º”≈œ»º∂
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //œÏ”¶”≈œ»º∂
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
		
//*******************************************”≈œ»º∂…Ë÷√*******************************************************************************************


}



