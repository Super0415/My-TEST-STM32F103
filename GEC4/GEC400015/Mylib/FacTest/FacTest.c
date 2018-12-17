//#include "ALL_Includes.h"//包含所需的头文件
//#include "..\GUIinc\GUI.h"
//#include "..\uCGUIDemo\GUIDEMO.h"
#include "TYPCortex.h"

unsigned  int HardTestModeEn=1; //硬件测试模式:0 ; 正常运行模式:1 


typedef void HardTestFun(void);

M_INT08U   HardTLCDRelay ;
M_INT16U   HardTLedFick; 
M_INT16U   HardTLCDRun; 
M_INT08U   HardTFunC=1;
M_INT08U   HardTHis=0;
M_INT08U   HardTRelayCtl=0;
M_INT16U   HARDTotalDelCtr=0;
void HardTestNopNone(){}
	
const M_INT16U HardTestAjdData[]=
{
  240,240, 240,  //A/B/C 相市电电压校准
  240,240, 240,  //A/B/C 相发电电压校准
  400,400, 400,  //A/B/C 相电流校准
  1001,//水缸温校准
  1001,//机油压力
  1001,//燃油位
  270,//电池电压
  270,//D+电压
};
/* ******************************************************************** */
/*                       HARDLCDDispRest ()                             */
/* ******************************************************************** */
void HARDDel()
{ int hArdDel;
  hArdDel=600000;
	do
	{hArdDel--;
	 if(GPIO_ReadInputDataBit(KEY_PORT_SET,KEY_PIN_SET) == (uint8_t)KEY_ON)F_ENTER_STOP_LCD=1;  
	}while((hArdDel>0)&&(F_ENTER_STOP_LCD==0));
}
void HARDLCDDispRest(void)
{ 
	HardTHis=0;
  GUI_Clear();LED_ALARM_Flick();
	HARDDel();
	GUI_SetBkColor(GUI_YELLOW);
	GUI_Clear();LED_ALARM_Flick();
	HARDDel();
	GUI_SetBkColor(GUI_GREEN);
	GUI_Clear();LED_ALARM_Flick();
	HARDDel();
	GUI_SetBkColor(GUI_RED);
	GUI_Clear();LED_ALARM_Flick();
	HARDDel();
	GUI_SetBkColor(GUI_WHITE);
	GUI_Clear();LED_ALARM_Flick();
	HARDDel();
	GUI_SetBkColor(GUI_BLACK);
	RELAY_ALL_ON();//关闭所有继电器
}

/* ******************************************************************** */
/*                         FacDisMData ()                               */
/* ******************************************************************** */
short facx[8],facy[8];
void FacDisMData(void)
{ float LCD_DisNum;
	GUI_SetColor(GUI_RED);
  GUI_GotoXY( 48, 75);  GUI_DispDecSpace(VOLTAGEA1,3);
	GUI_GotoXY(136, 75);  GUI_DispDecSpace(VOLTAGEB1,3);
	GUI_GotoXY(220, 75);  GUI_DispDecSpace(VOLTAGEC1,3);	   //发电L-N
	GUI_GotoXY( 38,100);  GUI_DispDecSpace(CURRENTA/10,4);
	GUI_GotoXY(126,100);  GUI_DispDecSpace(CURRENTB/10,4); 
	GUI_GotoXY(210,100);  GUI_DispDecSpace(CURRENTC/10,4);  //电流 
	
	if(VALUER0==-32768)                 {GUI_GotoXY( 42,125);GUI_DispString("++++");}        //电阻
	if((VALUER0<9999)&&(VALUER0>0))     {GUI_GotoXY( 42,125);GUI_DispDecSpace(VALUER0/10,4);}
	if(VALUER1==-32768)                 {GUI_GotoXY(130,125);GUI_DispString("++++");}        //电阻
	if((VALUER1<9999)&&(VALUER1>0))     {GUI_GotoXY(130,125);GUI_DispDecSpace(VALUER1/10,4);}//电阻
	LCD_DisNum=(float)GEN_FREQ/(float)10.0;
	GUI_GotoXY(220,125);  GUI_DispFloat(LCD_DisNum,4);	            //发电频率
	if(VALUER2==-32768)                 {GUI_GotoXY( 42,150);GUI_DispString("++++");} 
	if((VALUER2<9999)&&(VALUER2>0))     {GUI_GotoXY( 42,150);GUI_DispDecSpace(VALUER2/10,4);}//电阻
	if(VALUER3==-32768)                 {GUI_GotoXY(130,150);GUI_DispString("++++");} 
	if((VALUER3<9999)&&(VALUER3>0))     {GUI_GotoXY(130,150);GUI_DispDecSpace(VALUER3/10,4);}//电阻
	GUI_GotoXY(220,150);  GUI_DispDecSpace(DES_DISPSPEED,4);	    //转速
	LCD_DisNum=(float)PowerVoltage/(float)10.0;
	GUI_GotoXY( 45,175);  GUI_DispFloat(LCD_DisNum,4);	     //电池电压
	LCD_DisNum=(float)ChargerVoltage/(float)10.0;		  
	GUI_GotoXY(136,175);  GUI_DispFloat(LCD_DisNum,4);	     //充电机电压
	
}

/* ******************************************************************** */
/*                       HARDLCDDispIOs ()                              */
/* ******************************************************************** */
void HARDIosCh1(void)
{if(HardTHis==0)
 { HardTHis=1;
	GUI_SetBkColor(LCD_DisBKColor);
  GUI_SetColor(LCD_DisParmSetCl);
  GUI_SetFont(&LCD_DisFont);
  GUI_SetTextMode(GUI_TEXTMODE_NORMAL);
  GUI_Clear();   //清屏
	
	GUI_DispStringAt("K1:   K2:   K3:   K4:   ",2,  0);
	GUI_DispStringAt("K5:   K6:   K7:   K8:   ",2, 25);
	GUI_DispStringAt("In1:   In2:    OUT:     ",2, 50);
	GUI_DispStringAt("Ua:     Ub:     Uc:     ",2, 75);
	GUI_DispStringAt("Ia:     Ib:     Ic:     ",2,100);
	GUI_DispStringAt("OP:     TP:     Fr:     ",2,125);
	GUI_DispStringAt("C1:     C2:     Sp:     ",2,150);
	GUI_DispStringAt("Bt:     Ct:             ",2,175);
	GUI_DispStringAt("CAN:Err RS485:Err       ",2,200);
 }
}

void HARDIosChkey(void)
{
	if(K_STOP) {GUI_GotoXY(45,0);GUI_DispDecSpace(1,1);}
	else       {GUI_GotoXY(45,0);GUI_DispDecSpace(0,1);}
	
  if(K_MAN)  {GUI_GotoXY(115,0);GUI_DispDecSpace(1,1);}
	else       {GUI_GotoXY(115,0);GUI_DispDecSpace(0,1);}

	if(K_AUTO) {GUI_GotoXY(185,0);GUI_DispDecSpace(1,1);}
	else       {GUI_GotoXY(185,0);GUI_DispDecSpace(0,1);}

	if(K_START){GUI_GotoXY(255,0);GUI_DispDecSpace(1,1);}
	else       {GUI_GotoXY(255,0);GUI_DispDecSpace(0,1);}

	if(K_SET)  {GUI_GotoXY(45,25);GUI_DispDecSpace(1,1);}
	else       {GUI_GotoXY(45,25);GUI_DispDecSpace(0,1);}
	
	if(K_DOWN) {GUI_GotoXY(115,25);GUI_DispDecSpace(1,1);}
	else       {GUI_GotoXY(115,25);GUI_DispDecSpace(0,1);}
	
	if(K_ENTER){GUI_GotoXY(185,25);GUI_DispDecSpace(1,1);}
	else       {GUI_GotoXY(185,25);GUI_DispDecSpace(0,1);}
	
	if(K_UP)   {GUI_GotoXY(255,25);GUI_DispDecSpace(1,1);}
	else       {GUI_GotoXY(255,25);GUI_DispDecSpace(0,1);}
}

void HARDIosChIOinout(void)
{
  if(KEYSW_IN1){GUI_GotoXY(55,50);GUI_DispDecSpace(1,1);}
	else         {GUI_GotoXY(55,50);GUI_DispDecSpace(0,1);}
	
	if(KEYSW_IN2){GUI_GotoXY(140,50);GUI_DispDecSpace(1,1);}
	else         {GUI_GotoXY(140,50);GUI_DispDecSpace(0,1);}
	
	GUI_GotoXY(240,50);GUI_DispDecSpace(HardTRelayCtl,1);
	switch(HardTRelayCtl)
	{case 1:RELAY_AUX1_OFF();break;
	 case 2:RELAY_AUX2_OFF();break;
	 case 3:RELAY_AUX3_OFF();break;
	 case 4:RELAY_AUX4_OFF();break;
	 case 5:RELAY_AUX5_OFF();break;
	 case 6:RELAY_AUX6_OFF();break;
	 case 7:RELAY_DCHARGE_OFF();break;
   case 8:RELAY_CRANK_OFF();break;
	 default:RELAY_ALL_ON();break;
	}
	
}

void HARDLCDDispIOs(void)
{HARDIosCh1(); 
 HARDIosChkey();
 HARDIosChIOinout();
 FacDisMData();
}

HardTestFun *HardTestUserF[]=
{
  HARDLCDDispRest,
  HARDLCDDispIOs,
  HardTestNopNone,
  HardTestNopNone,
  HardTestNopNone,
  0
};
/* ******************************************************************** */
/*                       HardTestLoop ()                                */
/* ******************************************************************** */
void HardTestLoop(void)
{ 
  if(F_ENTER_STOP_LCD)
  { F_ENTER_STOP_LCD=0;
    if(HardTFunC>=2)HardTFunC=0; 
		HardTFunC++;
  } 
 (*HardTestUserF[HardTFunC-1])();
  if(HARDTotalDelCtr++>8)
	{ HARDTotalDelCtr=0;
		HardTRelayCtl++;
		if(HardTRelayCtl>9)
		{HardTRelayCtl=0;
		}
	}
}

/**************************************************/
