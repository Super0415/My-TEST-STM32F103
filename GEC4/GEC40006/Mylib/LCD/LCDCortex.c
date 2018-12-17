/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File LCDCortex.c                        */
/*                            By: Wu Xuekui                             */
/*                             2017-11-02                               */
/* ******************************************************************** */

#define   LCD_GLOBALS
#include "TYPCortex.h"
#include "lcd.h"
#include "GUI.h"

void Delay1us1(uint32_t us)
{
    int n = 24*us;
    for(; n != 0; n--);
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
}
#endif

/* ******************************************************************** */
/*                            LCDTaskLoop ()                            */
/* ******************************************************************** */
#if (LCD_LCD_FUNCTION_ON == 1)
char str[20] = "Hello World";
void LCDTaskLoop (void)
{
  if(usFW100msTimer/10%10==0) LCD_Str_O(200, 150, (u8 *)str,RED);
  if(usFW100msTimer/10%10==3) LCD_Str_O(200, 150, (u8 *)str,GREEN);
  if(usFW100msTimer/10%10==6) LCD_Str_O(200, 150, (u8 *)str,WHITE);
	
	GUI_SetBkColor(GUI_BLUE);
	GUI_SetColor(GUI_YELLOW);
	GUI_SetFont(GUI_ASCII_FONT);
	GUI_DispStringAt("ucGUI Success again", 60, 10);
	
	Delay1us1(10000);	
	
	GUI_Clear();

	Delay1us1(10000);
	
	GUI_SetColor(GUI_RED);
	GUI_DispStringAt("ucGUI Success again", 60, 40);

	Delay1us1(10000);
	
	
	
}
#endif

/* ******************************************************************** */
/*                                The End                               */
/* ******************************************************************** */
