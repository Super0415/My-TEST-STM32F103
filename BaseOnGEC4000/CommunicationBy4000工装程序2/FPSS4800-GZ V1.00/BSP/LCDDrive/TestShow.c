/* ******************************************************************** */
/*                   Software for Elctronic Unit (V1.0)                 */
/*                       Source File TestShow.c                         */
/*                            By: Fengzc                                */
/*                             2018-05-17                               */
/* ******************************************************************** */
#include "TestShow.h"
#include "TYPCortex.h"




/*  选取的功能项
  0-0 485 第1个地址界面
	1-0 485 第2个地址界面
	2-0 485 第3个地址界面
	3-0 CAN 显示界面
*/
// 第1个元素为 界面种类  第2个元素为 种类下的分界面  第3个元素为 分界面下的数据序号
INT08U ForwardPage_Num[3];    //将要显示的界面  //按键中赋值
INT08U NowPage_Num[3];        //当前显示的界面  //显示中赋值
INT08U HistoryPage_Num[3];    //历史记录的界面  //按键中赋值
INT08U EditPageEnable;           //编辑当前界面使能
INT08U EditDATAEnable[2];        //编辑当前界面指定数据使能  //0-数据在此界面序号  1-是否编辑使能


INT08U DisSolidTips[SumSolidState+1] = {0};   //静态显示位置
INT08U DisdynamicTips[SumSolidWord+1] = {0}; //动态显示位置


const DisFontStruct DisFontStrings[SumSolidWord] = 
{
/*   0 */    {{"RS485 -- "},{"RS485-TEST"}},
/*   1 */    {{"报文:"},{"Message:"}},
/*   2 */    {{"CAN ----"},{"2222"}},
/*   3 */    {{"3333"},{"3333"}},

};

SolidStruct  SolidState[SumSolidState] = 
{
	          //显示使能----0级位置--------1级位置---- -Pic_X-Pic_Y--图片地址---TXT_X--TXT_Y----字体------------------文本位置-----------------------功能函数
/*000*/   {  FunENable,    RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    80,  70,   &GUI_FontHZ24,     0,        NULL,         NULL},
/*001*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    5,   30,   &GUI_FontHZ24,     1,        NULL,         NULL},
/*002*/   {  FunENable,    RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    80,  120,  &GUI_FontHZ24,     2,        NULL,         NULL},
/*003*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    5,   120,  &GUI_FontHZ24,     1,        NULL,         NULL},
/*004*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,  0,    0,       NULL,    60,  150,  &GUI_FontHZ24,     4,        NULL,         NULL},


/*005*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    0,     0,  &GUI_FontHZ24,     0,        NULL,         NULL},
/*006*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    30,    0,  &GUI_FontHZ24,     1,        NULL,         NULL},
/*007*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    60,    0,  &GUI_FontHZ24,     2,        NULL,         NULL},
/*008*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    90,    0,  &GUI_FontHZ24,     3,        NULL,         NULL},
/*009*/   {  FunDISable,   CANFunPage,     CANFun0     ,  0,    0,       NULL,    120,   0,  &GUI_FontHZ24,     4,        NULL,         NULL},
};



dynamicStruct dynamicData[SumdynamicData] = 
{
	          //显示使能-------0级位置--------1级位置------TXT_X--TXT_Y----字体--------数据特殊功能-----数据指针位置----------------功能函数
/*000*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        RS485Dis00Message,         NULL},  //485发送报文
/*000*/   {  FunENable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        RS485Dis01Message,         NULL},  //第一条报文
/*000*/   {  FunDISable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        CANDis00Message,         NULL},  //485发送报文
/*000*/   {  FunENable,   RS485AddPage0,  RS485Fun0   ,     0,   0,   &GUI_FontHZ24,       0,         NULL,        CANDis01Message,         NULL},  //第一条报文
};


//函数：TestShowTask
//接口：显示任务
//说明：
//备注：
void TestShowTask(void)
{
	  DBKeyCheck();
	
    ShowScreen();
}

//函数：DBKeyCheck
//接口：根据当前界面判断按键作用
//说明：
//备注：
void DBKeyCheck(void)
{
	  switch(ForwardPage_Num[0])
		{
			case RS485AddPage0:	
				switch(ForwardPage_Num[1])
				{
					case RS485Fun0:  RS485Fun0_KeyRule(); break;
//				  case RS485Fun1:  RS485Fun1_KeyRule(); break;
//					case RS485Fun2:  RS485Fun2_KeyRule(); break;
//					case RS485Fun3:  RS485Fun3_KeyRule(); break;
//					case RS485Fun4:  RS485Fun4_KeyRule(); break;
				}

		  break;
			case CANFunPage:
				switch(ForwardPage_Num[1])
				{
					case CANFun0:  CANFun0_KeyRule(); break;
//				  case CANFun1:  CANFun0_KeyRule(); break;
//					case CANFun2:  CANFun0_KeyRule(); break;
//					case CANFun3:  CANFun0_KeyRule(); break;
//					case CANFun4:  CANFun0_KeyRule(); break;
				}				
		  break;
      default:
			break;
		}
}
//函数：ShowScreen
//接口：根据当前界面判断显示内容
//说明：
//备注：
void ShowScreen(void)
{
	  switch(ForwardPage_Num[0])
		{
			case RS485AddPage0:
				switch(ForwardPage_Num[1])
				{
					case RS485Fun0:  RS485Fun0_Show(); break;
//				  case RS485Fun1:  RS485Fun1_Show(); break;
//					case RS485Fun2:  RS485Fun2_Show(); break;
//					case RS485Fun3:  RS485Fun3_Show(); break;
//					case RS485Fun4:  RS485Fun4_Show(); break;
				}

		  break;
			case CANFunPage:
				switch(ForwardPage_Num[1])
				{
					case CANFun0:  CANFun0_Show(); break;
//				  case CANFun1:  CANFun1_Show(); break;
//					case CANFun2:  CANFun2_Show(); break;
//					case CANFun3:  CANFun3_Show(); break;
//					case CANFun4:  CANFun4_Show(); break;
				}				
		  break;
      default:
			break;
		}  	

}
//函数：RS485Fun0_KeyRule
//接口：RS485Fun0界面按键规则
//说明：
//备注：
void RS485Fun0_KeyRule(void)
{
	  if(usDBmKeyMenuUp)
		{
			  if(EditPageEnable)
				{
				
				}
				else
				{
				
				}
		}	
		else if(usDBmKeyMenuDown)
		{
		
		
		}
		else if(usDBmKeyMenuEnter)
		{
			  if(EditPageEnable)
				{
				    EditPageEnable = 0;
				}
				else
				{
				    EditPageEnable = 1;
				}
		
		}
		else if(usDBmKeyMenuLeft)
		{
		
		}
		else if(usDBmKeyMenuRight)
		{
		
		}

}
//*************************************************************************************************  RS485-0
//函数：RS485Fun0_Show
//接口：RS485Fun1界面显示
//说明：
//备注：
void RS485Fun0_Show(void)
{
    if(ForwardPage_Num[0] != NowPage_Num[0])
    {
        NowPage_Num[0] = ForwardPage_Num[0];    //记录权限0界面值
    }
    if(ForwardPage_Num[1] != NowPage_Num[1])  //
    {
				NowPage_Num[1] = ForwardPage_Num[1];  // 记录权限分界面
				RS485Fun0_SolidShow(); 
    }
    
    RS485Fun0_dynamicShow();// 

}
//函数：RS485Fun0_SolidShow
//接口：RS485Fun1界面静态显示
//说明：
//备注：

void RS485Fun0_SolidShow(void)
{
	  INT08U i = 0;
	  INT08U Temp = 0;
    GUI_SetBkColor(LCD_DisBKColor);
    GUI_SetColor(LCD_DisColor);
		RS485Fun0_DisCheckSolid(DisSolidTips,DisdynamicTips);  //记录此处界面的静态数据 以及 动态数据
    GUI_Clear();	

		for(i = 0;i < DisSolidTips[0];i++)
		{
			  Temp = DisSolidTips[i+1];
			  if(SolidState[Temp].FunF != NULL) SolidState[Temp].FunF(); 
				if(NULL != SolidState[Temp].GUIFont) 
				{
					GUI_SetFont(SolidState[Temp].GUIFont);  
				}
			  if(NULL != SolidState[Temp].Pic_Add) 
				{
						GUI_DrawBitmap(SolidState[Temp].Pic_Add,SolidState[Temp].Pic_X ,SolidState[Temp].Pic_Y);   //SolidState[Temp].TxTAdd
				}
		    if(SumSolidWord>SolidState[Temp].TxTAdd)	
				{
						GUI_DispStringAt(DisFontStrings[SolidState[Temp].TxTAdd].DisCNStrings, SolidState[Temp].TXT_X, SolidState[Temp].TXT_Y);
				}
				if(SolidState[Temp].FunB != NULL) SolidState[Temp].FunB(); 
		}
	
	
}
//函数：RS485Fun0_dynamicShow
//接口：RS485Fun1界面判断显示内容
//说明：
//备注：
void RS485Fun0_DisCheckSolid(INT08U *DisSolTips,INT08U *DisdynTips)
{
	  INT08U i = 0;
	  INT08U Count = 0;
	  for(i = 0;i<SumSolidState;i++)
		{
				if((SolidState[i].SHOWABLE == FunENable) && SolidState[i].Level0Pos == NowPage_Num[0] && SolidState[i].Level1Pos == NowPage_Num[1])
				{
					  Count++;
					  *(DisSolTips+Count) = i;
				}
		}
		*DisSolTips = Count;
		Count = 0;  //计数值清零
	  for(i = 0;i<SumdynamicData;i++)
		{
				if((dynamicData[i].SHOWABLE == FunENable) && dynamicData[i].Level0Pos == NowPage_Num[0] && dynamicData[i].Level1Pos == NowPage_Num[1])
				{
					  Count++;
					  *(DisdynTips+Count) = i;
				}
		}
		*DisdynTips = Count;		


}
//函数：RS485Fun0_dynamicShow
//接口：RS485Fun1界面动态显示
//说明：
//备注：
void RS485Fun0_dynamicShow(void)
{
	  INT08U i = 0;
	  INT08U Temp = 0;

		for(i = 1;i <= DisdynamicTips[0];i++)
		{
			  Temp = DisdynamicTips[i];
				if(NULL != dynamicData[Temp].GUIFont) 
					GUI_SetFont(dynamicData[Temp].GUIFont);
			  if(dynamicData[Temp].FunF != NULL) dynamicData[Temp].FunF(); 
  
		    if(NULL != dynamicData[Temp].DATAAdd)	
					GUI_DispStringAt(DisFontStrings[SolidState[Temp].TxTAdd].DisCNStrings, SolidState[Temp].TXT_X, SolidState[Temp].TXT_Y);
				if(dynamicData[Temp].FunB != NULL) dynamicData[Temp].FunB(); 
		}	
	
	
}
////*************************************************************************************************  RS485-1
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun1_KeyRule(void)
//{
//}
////函数：RS485Fun0_Show
////接口：RS485Fun1界面显示
////说明：
////备注：
//void RS485Fun1_Show(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun1_SolidShow(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun1_dynamicShow(void)
//{
//}
////*************************************************************************************************  RS485-2
////函数：RS485Fun2_KeyRule
////接口：RS485Fun2界面按键规则
////说明：
////备注：
//void RS485Fun2_KeyRule(void)
//{
//}
////函数：RS485Fun0_Show
////接口：RS485Fun1界面显示
////说明：
////备注：
//void RS485Fun2_Show(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun2_SolidShow(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun2_dynamicShow(void)
//{
//}
////*************************************************************************************************  RS485-3
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun3_KeyRule(void)
//{
//}
////函数：RS485Fun0_Show
////接口：RS485Fun1界面显示
////说明：
////备注：
//void RS485Fun3_Show(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun3_SolidShow(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun3_dynamicShow(void)
//{
//}
////*************************************************************************************************  RS485-4
////函数：CANFun4_KeyRule
////接口：CANFun0界面按键规则
////说明：
////备注：
//void RS485Fun4_KeyRule(void)
//{
//}
////函数：RS485Fun0_Show
////接口：RS485Fun1界面显示
////说明：
////备注：
//void RS485Fun4_Show(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun4_SolidShow(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void RS485Fun4_dynamicShow(void)
//{
//}


//函数：RS485Dis00Message
//接口：用于显示485发送报文数据
//说明：
//备注：
void RS485Dis00Message(void)
{
		INT08U MsgLong = usDBpRS485Sent0Leng;
	  INT16U X = 80;
	  INT16U Y = 30;
	  INT16U* DataAdd = usDBcRS485Sent0DataA0;
	  INT08U i = 0;
		
		for(i = 0;i<MsgLong;i++)
		{
			  GUI_DispHexAt(*(DataAdd+i),X+i*30,Y,2);
		}
}
//函数：RS485Dis01Message
//接口：用于显示485接受报文数据
//说明：
//备注：
void RS485Dis01Message(void)
{
		INT08U MsgLong = SF_UC_LOW(*usDBhRS485RXBuff);  //取第一个数-标志-的后8位
	  INT16U X = 170;
	  INT16U Y = 70;
	  INT16U* DataAdd = (usDBhRS485RXBuff+1);
	  INT08U i = 0;
		
	  if(usDBmRS485Msg0Norma0)
	  {
			  GUI_DispStringAt("  YES        ",X,Y);
  	}
		else
		{
		    GUI_DispStringAt("  NO         ",X,Y);
		
		}

}









//函数：CANDis00Message
//接口：用于CAN发送报文数据
//说明：
//备注：
void CANDis00Message(void)
{
		INT08U MsgLong = 8;
	  INT16U X = 80;
	  INT16U Y = 120;
	  INT16U* DataAdd = usDBcCANTTX0DataA0;
	  INT08U i = 0;
		
		for(i = 0;i<MsgLong;i++)
		{
			  GUI_DispHexAt(*(DataAdd+i),X+i*30,Y,2);
		}
}
//函数：CANDis01Message
//接口：用于CAN接收报文数据
//说明：
//备注：
void CANDis01Message(void)
{
		INT08U MsgLong = 8;
	  INT16U X = 170;
	  INT16U Y = 120;
	  INT16U* DataAdd = usDBhCANRXBuff;
	  INT08U i = 0;
	  if(usDBmCANMsg0Norma0)
	  {		
//				for(i = 0;i<MsgLong;i++)
//				{
//						GUI_DispHexAt(*(DataAdd+i),X+i*30,Y,2);
//				}
			  GUI_DispStringAt("  YES        ",X,Y);
		}
		else
		{
		    GUI_DispStringAt("  NO         ",X,Y);
		
		}		
}









//*************************************************************************************************  CAN-0
//函数：RS485Fun0_Show
//接口：RS485Fun1界面显示
//说明：
//备注�
void CANFun0_KeyRule(void)
{
}
//函数：RS485Fun0_Show
//接口：RS485Fun1界面显示
//说明：
//备注：
void CANFun0_Show(void)
{
}
//函数：RS485Fun1_KeyRule
//接口：RS485Fun1界面按键规则
//说明：
//备注：
void CANFun0_SolidShow(void)
{
}
//函数：RS485Fun1_KeyRule
//接口：RS485Fun1界面按键规则
//说明：
//备注：
void CANFun0_dynamicShow(void)
{
}
////*************************************************************************************************  CAN-1
////函数：CANFun0_KeyRule
////接口：CANFun0界面按键规则
////说明：
////备注：
//void CANFun1_KeyRule(void)
//{
//}
////函数：RS485Fun0_Show
////接口：RS485Fun1界面显示
////说明：
////备注：
//void CANFun1_Show(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void CANFun1_SolidShow(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void CANFun1_dynamicShow(void)
//{
//}
////*************************************************************************************************  CAN-2
////函数：CANFun0_KeyRule
////接口：CANFun0界面按键规则
////说明：
////备注：
//void CANFun2_KeyRule(void)
//{
//}
////函数：RS485Fun0_Show
////接口：RS485Fun1界面显示
////说明：
////备注：
//void CANFun2_Show(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void CANFun2_SolidShow(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void CANFun2_dynamicShow(void)
//{
//}
////*************************************************************************************************  CAN-3
////函数：CANFun0_KeyRule
////接口：CANFun0界面按键规则
////说明：
////备注：
//void CANFun3_KeyRule(void)
//{
//}
////函数：RS485Fun0_Show
////接口：RS485Fun1界面显示
////说明：
////备注：
//void CANFun3_Show(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void CANFun3_SolidShow(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void CANFun3_dynamicShow(void)
//{
//}
////*************************************************************************************************  CAN-4
////函数：CANFun0_KeyRule
////接口：CANFun0界面按键规则
////说明：
////备注：
//void CANFun4_KeyRule(void)
//{
//}
////函数：RS485Fun0_Show
////接口：RS485Fun1界面显示
////说明：
////备注：
//void CANFun4_Show(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void CANFun4_SolidShow(void)
//{
//}
////函数：RS485Fun1_KeyRule
////接口：RS485Fun1界面按键规则
////说明：
////备注：
//void CANFun4_dynamicShow(void)
//{
//}
//*************************************************************************************************  CAN-END


