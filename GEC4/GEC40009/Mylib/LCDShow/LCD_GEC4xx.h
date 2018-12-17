#ifndef __LCD_GEC4XX_H
#define	__LCD_GEC4XX_H

#define LCDIOStatPgCtr 5  //I/O状态所在的页面
#define LCDAlarmListPg 6  //报警列表所在的页面
                                             
/* ******************************************************************** */
/*                          LCD IO Port Definition                      */
/* ******************************************************************** */
#define MASK_BTN_GENS      0xff7f //0b01111111 11111111
#define MASK_BTN_MAINS     0xffbf //0b10111111 11111111
#define MASK_BTN_MANUAL    0xfbff //0b11111111 11111011
#define MASK_BTN_ALARM     0x7fff //0b11111111 01111111
#define MASK_BTN_START     0xfffe //0b11111110 11111111
#define MASK_BTN_AUTO      0xdfff //0b11111111 11011111
#define MASK_BTN_RUN       0xefff //0b11111111 11101111
#define MASK_BTN_STOP      0xfeff //0B11111111 11111110
#define MASK_BTN_PGTURN    0xefff //0B11111111 11101111 
#define MASK_BTN_MeueE     0xffdf //0b11011111 11111111    //7100 ok按键
#define MASK_BTN_PAGEDW    0xbfff //0B11111111 10111111
#define MASK_BTN_PAGEUP    0x7fff //0B11111111 01111111
#define MASK_BTN_HIGH_SET  0xfbf3 //0b11110011 11111011
#define MASK_BTN_HIGH_SET1 0xfbfb //0b11111011 11111011


void KeyCalRestFunAtLCD(void);
void LCD_GEC400_App(void);
extern void Boot_Intro(void);
extern void GUIDEMO_Automotive(void);
extern void GUIDEMO_AutomotiveSpd(void);
extern void GUI_DrawOpen(unsigned char Dtype);



#endif

