/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : usb_desc.c
* Author             : MCD Application Team
* Version            : V2.2.1
* Date               : 09/22/2008
* Description        : Descriptors for Custom HID Demo
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Extern variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//USB_CCID ������
/* USB Standard Device Descriptor �豸������ */
const u8 CustomHID_DeviceDescriptor[CUSTOMHID_SIZ_DEVICE_DESC] =
{
    0x12,                       /*bLength */				//�豸�������ֽ�����С
    USB_DEVICE_DESCRIPTOR_TYPE, /*bDescriptorType*/	//�豸���������ͱ��
    0x00,                       /*bcdUSB */					//USB�淶�汾�� (BCD��)
    0x02,
    0x00,                       /*bDeviceClass*/		//USB������豸�����
    0x00,                       /*bDeviceSubClass*/	//�豸�������
    0x00,                       /*bDeviceProtocol*/	//�豸Э�����
    0x40,                       /*bMaxPacketSize40*/	//������ݰ����� / byte
    0x83,                       /*idVendor (0x0483)*/  //����VID
    0x04,
    0x15,                       /*idProduct = 0x5750*/ //�Զ���PID
    0x04,
    0x00,                       /*bcdDevice rel. 2.00*/
    0x02,
    1,                          /*Index of string descriptor describing
                                              manufacturer */
    2,                          /*Index of string descriptor describing
                                             product*/
    3,                          /*Index of string descriptor describing the
                                             device serial number */
    0x01                        /*bNumConfigurations*/
}
; /* CustomHID_DeviceDescriptor */


/* USB Configuration Descriptor */
/*   All Descriptors (Configuration, Interface, Endpoint, Class, Vendor ����������*/
const u8 CustomHID_ConfigDescriptor[CUSTOMHID_SIZ_CONFIG_DESC] =
{
    0x09, /* bLength: Configuation Descriptor size */
    USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType: Configuration */
    CUSTOMHID_SIZ_CONFIG_DESC,
    /* wTotalLength: Bytes returned */
    0x00,
    0x01,         /* bNumInterfaces: 1 interface */
    0x01,         /* bConfigurationValue: Configuration value */
    0x00,         /* iConfiguration: Index of string descriptor describing
                                 the configuration*/
    0xC0,         /* bmAttributes: Bus powered */
    /*Bus powered: 7th bit, Self Powered: 6th bit, Remote wakeup: 5th bit, reserved: 4..0 bits */
    0x32,         /* MaxPower 100 mA: this current is used for detecting Vbus */
//    0x96,         /* MaxPower 300 mA: this current is used for detecting Vbus */
    /************** Descriptor of Custom HID interface ****************/
    /* 09 */
    0x09,         /* bLength: Interface Descriptor size */
    USB_INTERFACE_DESCRIPTOR_TYPE,/* bDescriptorType: Interface descriptor type */
    0x00,         /* bInterfaceNumber: Number of Interface */
    0x00,         /* bAlternateSetting: Alternate setting */
    0x02,         /* bNumEndpoints */
    0x03,         /* bInterfaceClass: HID */
    0x00,         /* bInterfaceSubClass : 1=BOOT, 0=no boot */
    0x00,         /* nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse */
    0,            /* iInterface: Index of string descriptor */
    /******************** Descriptor of Custom HID HID ********************/
    /* 18 */
    0x09,         /* bLength: HID Descriptor size */
    HID_DESCRIPTOR_TYPE, /* bDescriptorType: HID */
    0x10,         /* bcdHID: HID Class Spec release number */
    0x01,
    0x00,         /* bCountryCode: Hardware target country */
    0x01,         /* bNumDescriptors: Number of HID class descriptors to follow */
    0x22,         /* bDescriptorType */
    CUSTOMHID_SIZ_REPORT_DESC,/* wItemLength: Total length of Report descriptor */
    0x00,
    /******************** Descriptor of Custom HID endpoints ******************/
    /* 27 */
    0x07,          /* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE, /* bDescriptorType: */

    0x82,          /* bEndpointAddress: Endpoint Address (IN) */
    // bit 3...0 : the endpoint number
    // bit 6...4 : reserved
    // bit 7     : 0(OUT), 1(IN)
    0x03,          /* bmAttributes: Interrupt endpoint */
    0x40,//0x02,          /* wMaxPacketSize: 20 Bytes max */
    0x00,
    0x01,          /* bInterval: Polling Interval (21 ms) */
    /* 34 */

    0x07,	/* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE,	/* bDescriptorType: */
    /*	Endpoint descriptor type */
    0x01,	/* bEndpointAddress: */
    /*	Endpoint Address (OUT) */
    0x03,	/* bmAttributes: Interrupt endpoint */
    0x40,//0x02,	/* wMaxPacketSize: 20 Bytes max  */
    0x00,
    0x01,	/* bInterval: Polling Interval (32 ms) */
    /* 41 */
}; /* CustomHID_ConfigDescriptor */

const u8 CustomHID_ReportDescriptor[CUSTOMHID_SIZ_REPORT_DESC] =
{
//#ifdef 0
    0x05, 0x8c, /* USAGE_PAGE (ST Page) */
    0x09, 0x01, /* USAGE (Demo Kit) */
    0xa1, 0x01, /* COLLECTION (Application) */
    /* 6 */

// The Input report
    0x09,0x03, // USAGE ID - Vendor defined
    0x15,0x00, // LOGICAL_MINIMUM (0)
    0x26,0x00, 0xFF, // LOGICAL_MAXIMUM (255)
    0x75,0x08, // REPORT_SIZE (8)
    0x95,Max_Buffer_Length,// REPORT_COUNT (64)
    0x81,0x02, // INPUT (Data,Var,Abs)
//19
// The Output report
    0x09,0x04, // USAGE ID - Vendor defined
    0x15,0x00, // LOGICAL_MINIMUM (0)
    0x26,0x00,0xFF, // LOGICAL_MAXIMUM (255)
    0x75,0x08, // REPORT_SIZE (8)
    0x95,Max_Buffer_Length, // REPORT_COUNT (64)
    0x91,0x02, // OUTPUT (Data,Var,Abs)
//32
// The Feature report
    /*
    0x09, 0x05, // USAGE ID - Vendor defined
    0x15,0x00, // LOGICAL_MINIMUM (0)
    0x26,0x00,0xFF, // LOGICAL_MAXIMUM (255)
    0x75,0x08, // REPORT_SIZE (8)
    0x95,0x02, // REPORT_COUNT (2)
    0xB1,0x02,
    */
    /* 45 */
    0xc0 /* END_COLLECTION */
//#endif
}; /* CustomHID_ReportDescriptor */


/* USB String Descriptors (optional) */
const u8 CustomHID_StringLangID[CUSTOMHID_SIZ_STRING_LANGID] =
{
    CUSTOMHID_SIZ_STRING_LANGID,
    USB_STRING_DESCRIPTOR_TYPE,
    0x09,
    0x04
}
; /* LangID = 0x0409: U.S. English */

const uint8_t CustomHID_StringVendor[CUSTOMHID_SIZ_STRING_VENDOR] =
  {
    CUSTOMHID_SIZ_STRING_VENDOR, /* Size of Vendor string */
    USB_STRING_DESCRIPTOR_TYPE,  /* bDescriptorType*/
    /* Manufacturer: "STMicroelectronics" */
    'S', 0, 'T', 0, 'M', 0, 'i', 0, 'c', 0, 'r', 0, 'o', 0, 'e', 0,
    'l', 0, 'e', 0, 'c', 0, 't', 0, 'r', 0, 'o', 0, 'n', 0, 'i', 0,
    'c', 0, 's', 0
  };

	const uint8_t CustomHID_StringProduct[CUSTOMHID_SIZ_STRING_PRODUCT] =
  {
    CUSTOMHID_SIZ_STRING_PRODUCT,          /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'Y', 0, 'U', 0, 'N', 0, 'G', 0, 'K', 0, 'U', 0, ' ', 0,  
		'C', 0, 'u', 0, 's', 0, 't', 0, 'o', 0, 'm', 0,
		//'H', 0, 'I', 0,'D', 0
  };
uint8_t CustomHID_StringSerial[CUSTOMHID_SIZ_STRING_SERIAL] =
  {
    CUSTOMHID_SIZ_STRING_SERIAL,           /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    'S', 0, 'T', 0, 'M', 0,'3', 0,'2', 0
  };

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/

