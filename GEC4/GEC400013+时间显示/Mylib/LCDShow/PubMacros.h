#ifndef  _PUBMACROS_H
#define  _PUBMACROS_H
//GUI.h
/****************************************************
����汾: Soft_VERSION=400  GEC400������

****************************************************/
#define Soft_VERSION      0x400

/*-----------------�ڰ���������--------------------*///
#define   LCD_BK_M           0   //ԭ���ĺڰ�����ʱ����

/***************ϵͳƵ��ʹ��********************////
#define   SYS_FreqSYSCLK     72  //ϵͳʹ�õ�Ƶ��

/******������ɫ*****/
#define RED	  0XF800
#define GREEN 0X07E0
#define BLUE  0X001F  
#define BRED  0XF81F
#define GRED  0XFFE0
#define GBLUE 0X07FF
#define BLACK 0X0000
#define WHITE 0XFFFF

#if (Soft_VERSION==0x400)

  #define LCD_ClrScrColor  GBLUE          //������ɫ
  #define LCD_DisBKColor   0xff3300       //��ʾ������ɫ
  #define LCD_DisColor     GUI_WHITE      //��ǰ������ɫ
  #define LCD_DisMDtColor  GUI_BLACK	  //��ʾ����������ɫ 
  #define LCD_DisParmSetCl GUI_WHITE	  //��ʾ����������ɫ 
  #define LCD_DisFont      GUI_FontHZ24   //��ǰ��ʾ����
  #define LCD_AlarmColor   0XFFE0         //������������ɫ
  #define LCD_AlarmCharCol 0X0000         //������������ɫ
  #define LCD_MenuSelColor GUI_BROWN//GRED           //�˵�ѡ������ɫ

  #define LCDFirstLightOnCol  GUI_GREEN   //�׽���ָʾ������ɫ
  #define LCDFirstLightOffCol GUI_RED     //�׽���ָʾ������ɫ

  #define  Password0x0318     0x4399//0x813         
  #define  Password0x0636     0x0636//
  #define  Password0x1234     0x1234
	#define  Password0x4321     0x0001 //���ؽ�������
	
  #define  LCD_GEC400EN       1   //GEC400��������ʾ����
	#define  LCD_GEC480EN       1   //GEC400������������ʾ����
	
  
#endif





#endif
/****************************The END *********************/
