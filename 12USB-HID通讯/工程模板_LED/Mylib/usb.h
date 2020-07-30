#ifndef _USB_H_
#define _USB_H_

#include "stm32f10x.h"
#include "usb_istr.h"
#include "usb_lib.h"
#include "hw_config.h"
#include "string.h"
#include "stdio.h"

extern u8 Receive_Buffer[Max_Buffer_Length];
extern u8 Transi_Buffer[Max_Buffer_Length];
extern u8 USB_SendFlg;
extern u8 USB_ReceiveFlg;
extern vu8 MsgCmd;
extern u16 RX_DataLen;

void Init_usb(void);
void USB_SendString(char *str);
void testShow1(u8 system, u8 *data,u8 len);
void testShow(u8 system, char *buff,u8 *data,u8 len,char *buffend);
void USB_FirstSendString(char *str);
void Test_USB_ReceiveString(void);
void TEST_usbloop(void);

#endif

