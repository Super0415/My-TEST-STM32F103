/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File LCDCortex.c                        */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   LCD_GLOBALS
#include "TYPCortex.h"
void Delay_100ms(int Period) 
{
  int EndTime = usFW100msTimer+Period;
  int tRem; /* remaining Time */
  while (tRem = EndTime- usFW100msTimer, tRem>0);
}
/* ******************************************************************** */
/*                              LCDInit ()                              */
/* ******************************************************************** */
#if (LCD_LCD_FUNCTION_ON == 1)
void LCDInit (void)
{   usLCDTimer = 0;
    usLCDStatus = 0;
	  GUI_Init(); 
}
#endif

/* ******************************************************************** */
/*                              LCDStart ()                             */
/* ******************************************************************** */
#if (LCD_LCD_FUNCTION_ON == 1)
void LCDStart (void)
{
#if (Boot_animation == 1)
	Boot_Intro();
#endif	
}
#endif

/* ******************************************************************** */
/*                            LCDTaskLoop ()                            */
/* ******************************************************************** */
#if (LCD_LCD_FUNCTION_ON == 1)
char str[20] = "Hello World";
float FLOAT[10];
void LCDTaskLoop (void)
{
//  static int num=0;
//  if(usFW100msTimer/10%10==0) LCD_Str_O(200, 150, (u8 *)str,RED);
//  if(usFW100msTimer/10%10==3) LCD_Str_O(200, 150, (u8 *)str,GREEN);
//  if(usFW100msTimer/10%10==6) LCD_Str_O(200, 150, (u8 *)str,WHITE);

//	GUI_SetBkColor(GUI_BLUE);
//	GUI_SetColor(GUI_YELLOW);
//  if(num==0){GUI_Clear();num = 1;}
//	GUI_DrawBitmap(&bmclose,200,80); 
//	GUI_GotoXY(60, 70);GUI_DispDecSpace(usFW100msTimer/10/60,6);
//	GUI_GotoXY(130, 70);GUI_DispDecSpace(usFW100msTimer/10%60,2);
	LCD_GEC400_App();	
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
