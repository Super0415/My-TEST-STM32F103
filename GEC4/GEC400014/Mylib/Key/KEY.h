#ifndef __KEY_H
#define __KEY_H
#include "DB.h"

#define KEY_ON    0
#define KEY_OFF   1

#define KEY_GPIO_CLK  (RCC_APB2Periph_GPIOE|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOB)

#define KEY_PORT_STOP    GPIOE
#define KEY_PIN_STOP     GPIO_Pin_6
#define KEY_PORT_MAN     GPIOE
#define KEY_PIN_MAN      GPIO_Pin_5
#define KEY_PORT_AUTO    GPIOD
#define KEY_PIN_AUTO     GPIO_Pin_3
#define KEY_PORT_START   GPIOC
#define KEY_PIN_START    GPIO_Pin_11
#define KEY_PORT_SET     GPIOC
#define KEY_PIN_SET      GPIO_Pin_10
#define KEY_PORT_UP      GPIOB
#define KEY_PIN_UP       GPIO_Pin_10
#define KEY_PORT_DOWN    GPIOB
#define KEY_PIN_DOWN     GPIO_Pin_5
#define KEY_PORT_ENTER   GPIOB
#define KEY_PIN_ENTER    GPIO_Pin_12

/* ******************************************************************** */
/*                      按键定义                     */
/* ******************************************************************** */


typedef union 
{
  M_INT16U BYTE; 
  struct {
    M_INT16U B_BTN_UP          :1;      
    M_INT16U B_BTN_DOWN        :1;      
    M_INT16U B_BTN_START       :1;
    M_INT16U B_BTN_STOP        :1;
    M_INT16U B_BTN_TEST        :1;
    M_INT16U B_BTN_MANUAL      :1;
    M_INT16U B_BTN_AUTO        :1;
    M_INT16U B_BTN_SETUP       :1;
    M_INT16U B_BTN_ENTER       :1;
    M_INT16U B_BTN_MAINCLOSE   :1;
    M_INT16U B_BTN_GENSCLOSE   :1;
    
   } Bits; 
}typBATTON_FLAG;

extern  typBATTON_FLAG BTN_FLAG,BTN_DOWN_FLAG;
//键标志
#define F_BTN_ALL               BTN_FLAG.BYTE
#define F_BTN_UP                BTN_FLAG.Bits.B_BTN_UP
#define F_BTN_DOWN              BTN_FLAG.Bits.B_BTN_DOWN
#define F_BTN_START             BTN_FLAG.Bits.B_BTN_START
#define F_BTN_STOP              BTN_FLAG.Bits.B_BTN_STOP
#define F_BTN_TEST              BTN_FLAG.Bits.B_BTN_TEST
#define F_BTN_MANUAL            BTN_FLAG.Bits.B_BTN_MANUAL
#define F_BTN_AUTO              BTN_FLAG.Bits.B_BTN_AUTO
#define F_BTN_SETUP             BTN_FLAG.Bits.B_BTN_SETUP
#define F_BTN_ENTER             BTN_FLAG.Bits.B_BTN_ENTER
#define F_BTN_MAINCLOSE         BTN_FLAG.Bits.B_BTN_MAINCLOSE
#define F_BTN_GENSCLOSE         BTN_FLAG.Bits.B_BTN_GENSCLOSE

//键按下标志
#define F_BTN_DOWN_ALL          BTN_DOWN_FLAG.BYTE
#define F_BTN_DOWN_UP           BTN_DOWN_FLAG.Bits.B_BTN_UP
#define F_BTN_DOWN_DOWN         BTN_DOWN_FLAG.Bits.B_BTN_DOWN
#define F_BTN_DOWN_START        BTN_DOWN_FLAG.Bits.B_BTN_START
#define F_BTN_DOWN_STOP         BTN_DOWN_FLAG.Bits.B_BTN_STOP
#define F_BTN_DOWN_TEST         BTN_DOWN_FLAG.Bits.B_BTN_TEST
#define F_BTN_DOWN_MANUAL       BTN_DOWN_FLAG.Bits.B_BTN_MANUAL
#define F_BTN_DOWN_AUTO         BTN_DOWN_FLAG.Bits.B_BTN_AUTO
#define F_BTN_DOWN_SETUP        BTN_DOWN_FLAG.Bits.B_BTN_SETUP
#define F_BTN_DOWN_ENTER        BTN_DOWN_FLAG.Bits.B_BTN_ENTER     
#define F_BTN_DOWN_MAINCLOSE    BTN_DOWN_FLAG.Bits.B_BTN_MAINCLOSE 
#define F_BTN_DOWN_GENSCLOSE    BTN_DOWN_FLAG.Bits.B_BTN_GENSCLOSE 

//键值								//   低8位 -- 高8位
#define BTN_VALUE_UP          0x01  //0B00000001 00000000     //向上键的值
#define BTN_VALUE_DOWN        0x02  //0B00000010 00000000     //向下键的值
#define BTN_VALUE_START       0x04  //0B00000100 00000000     //向启动键的值
#define BTN_VALUE_STOP        0x08  //0B00001000 00000000     //向停机键的值
#define BTN_VALUE_TEST        0x10  //0B00010000 00000000     //向试机键的值
#define BTN_VALUE_MANUAL      0x20  //0B00100000 00000000     //向手动键的值
#define BTN_VALUE_AUTO        0x40  //0B01000000 00000000     //向自动键的值
#define BTN_VALUE_SETUP       0x80  //0B10000000 00000000     //向设置键的值
#define BTN_VALUE_ENTER       0x100 //0B00000000 00000001     //确定键的值
#define BTN_VALUE_MAINCLOSE   0x200 //0B00000000 00000010     //市电合闸键的值
#define BTN_VALUE_GENSCLOSE   0x400 //0B00000000 00000100     //发电合闸键的值

#define DB_BTNDEF_ON   0       //扩展按键宏定义
//extern STRFLG16 KEY_VAL_STAT;  //按键输入状态   //淘汰

//#define K_STOP    KEY_VAL_STAT.BITS.BIT0
//#define K_MAN     KEY_VAL_STAT.BITS.BIT1
//#define K_AUTO    KEY_VAL_STAT.BITS.BIT2
//#define K_START   KEY_VAL_STAT.BITS.BIT3
//#define K_SET     KEY_VAL_STAT.BITS.BIT4
//#define K_UP      KEY_VAL_STAT.BITS.BIT5
//#define K_DOWN    KEY_VAL_STAT.BITS.BIT6
//#define K_ENTER   KEY_VAL_STAT.BITS.BIT7


void KEY_Init(void);
void XIOButProcess(void);

///--------------开关量输入定义------------------
#define SW_ON     0
#define SW_OFF    1


#define AUXSW_GPIO_CLK    RCC_APB2Periph_GPIOE
#define AUXSW_PORT_SW1    GPIOE
#define AUXSW1_PIN        GPIO_Pin_2
#define AUXSW_PORT_SW2    GPIOE
#define AUXSW2_PIN        GPIO_Pin_3

extern  STRFLG16 AUXSW_STAT;    //开关量输入状态
#define KEYSW_IN1  AUXSW_STAT.BITS.BIT0
#define KEYSW_IN2  AUXSW_STAT.BITS.BIT1


void AUX_SWIN_Init(void);
void AUX_SWINPUT_SCAN(void);


#endif

