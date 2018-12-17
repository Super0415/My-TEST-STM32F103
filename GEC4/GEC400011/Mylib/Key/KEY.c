//#include "ALL_Includes.h"
#include "TYPCortex.h"
STRFLG16 AUXSW_STAT;    //开关量输入状态
//STRFLG16 KEY_VAL_STAT;  //按键输入状态  //淘汰
typBATTON_FLAG BTN_FLAG,BTN_DOWN_FLAG;//按键输入状态临时变量
M_INT16U BTN_VALUE;					  //按键值

/****************************************************
函数功能：key初始化
输入参数：无
输出参数：无
备    注：调用此函数前，需要在KEY.h修改宏定义LED引脚
****************************************************/
void KEY_Init(void)
{
	  GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = KEY_PIN_STOP;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;
    GPIO_Init(KEY_PORT_STOP, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = KEY_PIN_MAN;
	  GPIO_Init(KEY_PORT_MAN, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = KEY_PIN_AUTO;
	  GPIO_Init(KEY_PORT_AUTO, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = KEY_PIN_START;
	  GPIO_Init(KEY_PORT_START, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = KEY_PIN_SET;
	  GPIO_Init(KEY_PORT_SET, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = KEY_PIN_UP;
	  GPIO_Init(KEY_PORT_UP, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = KEY_PIN_DOWN;
	  GPIO_Init(KEY_PORT_DOWN, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = KEY_PIN_ENTER;
	  GPIO_Init(KEY_PORT_ENTER, &GPIO_InitStructure);	
	
}

/****************************************************
函数功能：CheckKeyStatue	按键状态检测
输入参数：无
输出参数：无
备    注：调用此函数前，需要在KEY.h修改宏定义引脚
****************************************************/
//void CheckKeyStatue(void)    //淘汰
//{
//	if(GPIO_ReadInputDataBit(KEY_PORT_STOP,KEY_PIN_STOP) == (uint8_t)KEY_ON)  {K_STOP= 1;}
//	else{K_STOP= 0;}
//	
//	if(GPIO_ReadInputDataBit(KEY_PORT_MAN,KEY_PIN_MAN) == (uint8_t)KEY_ON)    {K_MAN= 1;}
//	else{K_MAN= 0;}
//	
//	if(GPIO_ReadInputDataBit(KEY_PORT_AUTO,KEY_PIN_AUTO) == (uint8_t)KEY_ON)  {K_AUTO= 1;}
//	else{K_AUTO= 0;}
//	
//	if(GPIO_ReadInputDataBit(KEY_PORT_START,KEY_PIN_START) == (uint8_t)KEY_ON){K_START= 1;}
//	else{K_START= 0;}
//	
//	if(GPIO_ReadInputDataBit(KEY_PORT_SET,KEY_PIN_SET) == (uint8_t)KEY_ON)    {K_SET= 1;}
//	else{K_SET= 0;}
//	
//	if(GPIO_ReadInputDataBit(KEY_PORT_UP,KEY_PIN_UP) == (uint8_t)KEY_ON)      {K_UP= 1;}
//	else{K_UP= 0;}
//	
//	if(GPIO_ReadInputDataBit(KEY_PORT_DOWN,KEY_PIN_DOWN) == (uint8_t)KEY_ON)  {K_DOWN= 1;}
//	else{K_DOWN= 0;}

//	if(GPIO_ReadInputDataBit(KEY_PORT_ENTER,KEY_PIN_ENTER) == (uint8_t)KEY_ON){K_ENTER= 1;}
//	else{K_ENTER= 0;}
//}

//*********************************************************************
//函数名称：  XIOBtnDete()
//功能描述：  检测按键   并返回键值
//输入参数：  
//输出参数：
//********************************************************************* 
 M_INT16U XIOBtnDete(void)
  {
//    CheckKeyStatue();  //淘汰
    if(K_UP)F_BTN_DOWN_UP=1;
    if((!K_UP) && F_BTN_DOWN_UP)
      {
        F_BTN_UP=1;
        F_BTN_DOWN_UP=0;
      }
    
    if(K_DOWN)F_BTN_DOWN_DOWN=1;
    if((!K_DOWN) && F_BTN_DOWN_DOWN)
      {
        F_BTN_DOWN=1;
        F_BTN_DOWN_DOWN=0;
      }
      
    //if(!BTN_STOP)LCDTestBKandLight++; //按下停止键3s测试液晶屏和灯
    
    if(K_START)F_BTN_DOWN_START=1;
    if((!K_START) && F_BTN_DOWN_START)
      {
        F_BTN_START=1;
        F_BTN_DOWN_START=0;
      }
      
    if(K_STOP)F_BTN_DOWN_STOP=1;
    if((!K_STOP) && F_BTN_DOWN_STOP)
      {
        F_BTN_STOP=1;
        F_BTN_DOWN_STOP=0;
      }
  /*  
    if(BTN_TEST)F_BTN_DOWN_TEST=1;
    if((!BTN_TEST) && F_BTN_DOWN_TEST)
      {
        F_BTN_TEST=1;
        F_BTN_DOWN_TEST=0;
      }
    */  
    if(K_MAN)  F_BTN_DOWN_MANUAL=1;
    if((!K_MAN)&& F_BTN_DOWN_MANUAL)
      {
        F_BTN_MANUAL=1;
        F_BTN_DOWN_MANUAL=0;
      }
    
    if(K_AUTO) F_BTN_DOWN_AUTO=1;
    if((!K_AUTO) && F_BTN_DOWN_AUTO)
      {
        F_BTN_AUTO=1;
        F_BTN_DOWN_AUTO=0;
      }
      
     if(K_SET)   F_BTN_DOWN_SETUP=1;
     if((!K_SET) && F_BTN_DOWN_SETUP)
      {
        F_BTN_SETUP=1;
        F_BTN_DOWN_SETUP=0;
      }
   
     if(K_ENTER)F_BTN_DOWN_ENTER=1;
     if((!K_ENTER) && F_BTN_DOWN_ENTER)
      {
        F_BTN_ENTER=1;
        F_BTN_DOWN_ENTER=0;
      }

  #if(DB_BTNDEF_ON==1) 
     if(BTN_MAINCLOSE)F_BTN_DOWN_MAINCLOSE=1;
     if((!BTN_MAINCLOSE) && F_BTN_DOWN_MAINCLOSE)
      {
        F_BTN_MAINCLOSE=1;
        F_BTN_DOWN_MAINCLOSE=0;
      } 
     if(BTN_GENSCLOSE)F_BTN_DOWN_GENSCLOSE=1;
     if((!BTN_GENSCLOSE) && F_BTN_DOWN_GENSCLOSE)
      {
        F_BTN_GENSCLOSE=1;
        F_BTN_DOWN_GENSCLOSE=0;
      }   
  #endif
      
    if(!F_BTN_DOWN_ALL)
      {
        BTN_VALUE=F_BTN_ALL;
        F_BTN_ALL=0;  
      }
    return  BTN_VALUE;

  }

//*********************************************************************
//函数名称：  XIOBtnProcessUp()
//功能描述：  向上翻页按键处理
//输入参数：  
//输出参数：
//********************************************************************* 
 void XIOBtnProcessUp(void)
  {
    F_ENTER_UP=1; 
  }

//*********************************************************************
//函数名称：  XIOBtnProcessDown()
//功能描述：  向下翻页按键处理
//输入参数：  
//输出参数：
//********************************************************************* 
 void XIOBtnProcessDown(void)
  {
    F_ENTER_DOWN=1; 
  }
  
//*********************************************************************
//函数名称：  XIOBtnProcessStart()
//功能描述：  启动按键处理
//输入参数：  
//输出参数：
//********************************************************************* 
 void XIOBtnProcessStart(void)
  {
    F_ENTER_START=1;
 
  }
  
//*********************************************************************
//函数名称：  XIOBtnProcessStop()
//功能描述：  停机按键处理
//输入参数：  
//输出参数：
//********************************************************************* 
 void XIOBtnProcessStop(void)
 {
    F_ENTER_STOP_LCD=1;   //LCD菜单退出用
    //KeyCalRestFunAtLCD(); //故障复位功能
	  RESETFLAG=1;
 }
  
//*********************************************************************
//函数名称：  XIOBtnProcessTest()
//功能描述：  测试按键处理
//输入参数：  
//输出参数：
//********************************************************************* 
 void XIOBtnProcessTest(void)
  {    
    F_ENTER_TEST=1;
  }
 
//*********************************************************************
//函数名称：  XIOBtnProcessManual()
//功能描述：  手动按键处理
//输入参数：  
//输出参数：
//********************************************************************* 
 void XIOBtnProcessManual(void)
  {
    F_ENTER_MANUAL=1;
  }
  
//*********************************************************************
//函数名称：  XIOBtnProcessAuto()
//功能描述：  自动按键处理
//输入参数：  
//输出参数：
//********************************************************************* 
 void XIOBtnProcessAuto(void)
  {
    F_ENTER_AUTO=1;
  }


//*********************************************************************
//函数名称：  XIOBtnProcessSetup()
//功能描述：  设置按键处理
//输入参数：  
//输出参数：
//********************************************************************* 
 void XIOBtnProcessSetup(void)
  {
    F_ENTER_SETUP=1;
  }

//*********************************************************************
//函数名称：  XIOButProcess()
//功能描述：  设置按键处理
//输入参数：  
//输出参数：
//*********************************************************************  
 
void XIOButProcess(void)
 {
    M_INT16U key_value_current=0;
    key_value_current=XIOBtnDete();
    BTN_VALUE=0; 
   /* if(key_value_current>0)
    {
        LCDLitBackLight();
    }*/
    switch(key_value_current)
      {
        case BTN_VALUE_UP:
             XIOBtnProcessUp();
        break;
        case BTN_VALUE_DOWN:
             XIOBtnProcessDown();
        break;
        case BTN_VALUE_START:
             //XIOBtnProcessStart();
		     XIOBtnProcessStop();
        break;
        case BTN_VALUE_STOP:
			       F_ENTER_STOP_CAL=1; //逻辑停机用 
        break;
        case BTN_VALUE_TEST:
             XIOBtnProcessTest();
        break;
        case BTN_VALUE_MANUAL:
             XIOBtnProcessManual();
        break;
        case BTN_VALUE_AUTO:
             XIOBtnProcessAuto();
        break;
        case BTN_VALUE_SETUP:
             //XIOBtnProcessSetup(); 
			       F_ENTER_START=1;
        break;
		    case BTN_VALUE_ENTER:     
		         F_ENTER_ENTER    =1;
	    break;

       #if(DB_BTNDEF_ON==1)      
        
        case BTN_VALUE_MAINCLOSE: F_ENTER_MAINCLOSE=1;break; 
        case BTN_VALUE_GENSCLOSE: F_ENTER_GENSCLOSE=1;break; 
       #endif    
        default:break;
      }
    
  }

/****************************************************
函数功能：开关量输入初始化
输入参数：无
输出参数：无
备    注：调用此函数前，需要在修改宏定义引脚
****************************************************/
void AUX_SWIN_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(AUXSW_GPIO_CLK, ENABLE);
    GPIO_InitStructure.GPIO_Pin = AUXSW1_PIN | AUXSW2_PIN ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU ;//GPIO_Mode_IN_FLOATING
    GPIO_Init(AUXSW_PORT_SW1, &GPIO_InitStructure);
}
/****************************************************
函数功能：开关量输入状态扫描
输入参数：无
输出参数：无
****************************************************/
void AUX_SWINPUT_SCAN(void)
{
  if(GPIO_ReadInputDataBit(AUXSW_PORT_SW1,AUXSW1_PIN) == (uint8_t)SW_ON) 
	{KEYSW_IN1=1;
	}else{KEYSW_IN1=0;}

  if(GPIO_ReadInputDataBit(AUXSW_PORT_SW2,AUXSW2_PIN) == (uint8_t)SW_ON) 
	{KEYSW_IN2=1;
	}else{KEYSW_IN2=0;}
	
}



/********************************The end **************************/
