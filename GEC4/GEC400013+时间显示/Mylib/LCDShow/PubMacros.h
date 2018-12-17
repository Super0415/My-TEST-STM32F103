#ifndef  _PUBMACROS_H
#define  _PUBMACROS_H
//GUI.h
/****************************************************
软件版本: Soft_VERSION=400  GEC400控制器

****************************************************/
#define Soft_VERSION      0x400

/*-----------------黑白屏驱动宏--------------------*///
#define   LCD_BK_M           0   //原来的黑白屏暂时不用

/***************系统频率使用********************////
#define   SYS_FreqSYSCLK     72  //系统使用的频率

/******常用颜色*****/
#define RED	  0XF800
#define GREEN 0X07E0
#define BLUE  0X001F  
#define BRED  0XF81F
#define GRED  0XFFE0
#define GBLUE 0X07FF
#define BLACK 0X0000
#define WHITE 0XFFFF

#if (Soft_VERSION==0x400)

  #define LCD_ClrScrColor  GBLUE          //清屏颜色
  #define LCD_DisBKColor   0xff3300       //显示背景颜色
  #define LCD_DisColor     GUI_WHITE      //当前字体颜色
  #define LCD_DisMDtColor  GUI_BLACK	  //显示测量数据颜色 
  #define LCD_DisParmSetCl GUI_WHITE	  //显示参数设置颜色 
  #define LCD_DisFont      GUI_FontHZ24   //当前显示字体
  #define LCD_AlarmColor   0XFFE0         //报警条背景颜色
  #define LCD_AlarmCharCol 0X0000         //报警条字体颜色
  #define LCD_MenuSelColor GUI_BROWN//GRED           //菜单选择条颜色

  #define LCDFirstLightOnCol  GUI_GREEN   //首界面指示灯亮颜色
  #define LCDFirstLightOffCol GUI_RED     //首界面指示灯灭颜色

  #define  Password0x0318     0x4399//0x813         
  #define  Password0x0636     0x0636//
  #define  Password0x1234     0x1234
	#define  Password0x4321     0x0001 //隐藏界面密码
	
  #define  LCD_GEC400EN       1   //GEC400控制器显示程序
	#define  LCD_GEC480EN       1   //GEC400控制器隐藏显示程序
	
  
#endif





#endif
/****************************The END *********************/
