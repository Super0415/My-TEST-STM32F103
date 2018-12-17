#include "TYPCortex.h"


extern void CAN_J1939Public_Init(void);
extern void CAN_PublicHookRx(CanRxMsg *pMsg);
extern void CANProcessPublicRxMsg (void);


/*******************************************************************************
 * 文件名  ：can.c
 * 硬件连接：PA11-CAN-RX  |	PA12-CAN-TX   
 * 作者    ：保留
**********************************************************************************/
CanTxMsg CANTxMessage;			        //发送缓冲区
CanRxMsg CANRxMessage;				      //接收缓冲区
u32  CAN_ID=0x123;

#define CAN_EXTSTD_ENABLE	  0       //1:使能扩展帧功能 0:普通帧

/*******************************************************************************
 * 函数名：CAN_GPIO_Config
 * 描述  ：CAN的GPIO 配置,PA11上拉输入，PA12推挽输出
 * 输入  ：无
 * 输出  : 无
 * 调用  ：内部调用
**********************************************************************************/
void CAN_GPIO_Config(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //外设时钟设置
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;            //Configure CAN pin: RX PA11						
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	        //上拉输入
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;            //Configure CAN pin: TX PA12			
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    //复用推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*******************************************************************************
 * 函数名：CAN_NVIC_Config
 * 描述  ：CAN的NVIC 配置,第1优先级组，0，0优先级
 * 输入  ：无
 * 输出  : 无
 * 调用  ：内部调用
**********************************************************************************/
void CAN_NVIC_Config(void)
{
   NVIC_InitTypeDef NVIC_InitStructure;
	 //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	 	                                
	 NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn; //中断设置 CAN1 RX0中断
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //抢占优先级0
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;			    //子优先级为0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
 * 函数名：CAN_Mode_Config
 * 描述  ：CAN的模式 配置
 * 输入  ：无
 * 输出  : 无
 * 调用  ：内部调用
**********************************************************************************/
#if CAN_EXTSTD_ENABLE
void CAN_Mode_Config(void)
{
    CAN_InitTypeDef  CAN_InitStructure;
	  CAN_DeInit(CAN1);
	  CAN_StructInit(&CAN_InitStructure);
	  CAN_InitStructure.CAN_TTCM=DISABLE;			   //MCR-TTCM  关闭时间触发通信模式使能
    CAN_InitStructure.CAN_ABOM=ENABLE;			   //MCR-ABOM  自动离线管理 
    CAN_InitStructure.CAN_AWUM=ENABLE;			   //MCR-AWUM  使用自动唤醒模式
    CAN_InitStructure.CAN_NART=DISABLE;			   //MCR-NART  禁止报文自动重传	  DISABLE-自动重传
    CAN_InitStructure.CAN_RFLM=DISABLE;			   //MCR-RFLM  接收FIFO 锁定模式  DISABLE-溢出时新报文会覆盖原有报文  
    CAN_InitStructure.CAN_TXFP=DISABLE;			   //MCR-TXFP  发送FIFO优先级 DISABLE-优先级取决于报文标示符 
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal; //正常工作模式???? CAN_Mode_LoopBack ????? CAN_Mode_Normal
    CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;		    //BTR-SJW 重新同步跳跃宽度 1个时间单元
    CAN_InitStructure.CAN_BS1=CAN_BS1_13tq;		    //BTR-TS1 时间段1 占用了13个时间单元
    CAN_InitStructure.CAN_BS2=CAN_BS2_2tq;		    //BTR-TS1 时间段2 占用了2个时间单元
    CAN_InitStructure.CAN_Prescaler =9;		        //BTR-BRP 波特率分频器定义了时间单元的时间长度 36/9/(1+13+2)=0.25Mbps
	                                                //36M/(1+12+3)/9= 250kbps
                                                  //36M/(1+5+2)/9 = 500kbps
                                                  //36M(1+2+1)/9 = 1M
	  CAN_Init(CAN1, &CAN_InitStructure);
	
}
#else
void CAN_Mode_Config(void)
{
    CAN_InitTypeDef  CAN_InitStructure;            //CAN单元设置
	  CAN_DeInit(CAN1);
	  CAN_StructInit(&CAN_InitStructure);
 	  CAN_InitStructure.CAN_TTCM=DISABLE;						 //非时间触发通信模式  
 	  CAN_InitStructure.CAN_ABOM=DISABLE;						 //软件自动离线管理	 
  	CAN_InitStructure.CAN_AWUM=DISABLE;						 //睡眠模式通过软件唤醒(清除CAN->MCR的SLEEP位)
  	CAN_InitStructure.CAN_NART=ENABLE;						 //禁止报文自动传送 
  	CAN_InitStructure.CAN_RFLM=DISABLE;						 //报文不锁定,新的覆盖旧的 
  	CAN_InitStructure.CAN_TXFP=DISABLE;						 //优先级由报文标识符决定 
  	CAN_InitStructure.CAN_Mode= CAN_Mode_Normal;	 //模式设置： mode:0,普通模式;1,回环模式; 
  	//设置波特率
  	CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;				 //重新同步跳跃宽度(Tsjw)为tsjw+1个时间单位  CAN_SJW_1tq	 CAN_SJW_2tq CAN_SJW_3tq CAN_SJW_4tq
  	CAN_InitStructure.CAN_BS1=CAN_BS1_13tq;        //Tbs1=tbs1+1个时间单位CAN_BS1_1tq ~CAN_BS1_16tq
  	CAN_InitStructure.CAN_BS2=CAN_BS2_2tq;         //Tbs2=tbs2+1个时间单位CAN_BS2_1tq ~	CAN_BS2_8tq
  	CAN_InitStructure.CAN_Prescaler=9;             //分频系数(Fdiv)为brp+1	
  	CAN_Init(CAN1, &CAN_InitStructure);            //初始化CAN1 
}
#endif
/*******************************************************************************
 * 函数名：CAN_Filter_Config
 * 描述  ：CAN的过滤器 配置
 * 输入  ：无
 * 输出  : 无
 * 调用  ：内部调用
**********************************************************************************/
#if CAN_EXTSTD_ENABLE
void CAN_Filter_Config(void)
{
    CAN_FilterInitTypeDef  CAN_FilterInitStructure;
	  CAN_FilterInitStructure.CAN_FilterNumber=0;						        //过滤器组0
    CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;	//工作在标识符屏蔽位模式
	  CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;//过滤器位宽为单个32位。
	//使能报文标示符过滤器按照标示符的内容进行比对过滤，扩展ID不是如下的就抛弃掉，是的话，会存入FIFO0
    CAN_FilterInitStructure.CAN_FilterIdHigh= (((u32)0x1314<<3)&0xFFFF0000)>>16;				        //要过滤的ID高位 
    CAN_FilterInitStructure.CAN_FilterIdLow= (((u32)0x1314<<3)|CAN_ID_EXT|CAN_RTR_DATA)&0xFFFF; //要过滤的ID低位 
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh= 0xFFFF;			                                  //过滤器高16位每位必须匹配
    CAN_FilterInitStructure.CAN_FilterMaskIdLow= 0xFFFF;			                                  //过滤器低16位每位必须匹配
	  CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FilterFIFO0 ;				                  //过滤器被关联到FIFO0
	  CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;			                                  //使能过滤器
	  CAN_FilterInit(&CAN_FilterInitStructure);
  	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);                                                    //CAN通信中断使能
    //CAN_ITConfig(CAN1,CAN_IT_FMP0 | CAN_IT_FF0 | CAN_IT_FOV0, ENABLE);  // fifo0中断
    //CAN_ITConfig(CAN1,CAN_IT_FMP1 | CAN_IT_FF1 | CAN_IT_FOV1, ENABLE);  // fifo1中断
    //CAN_ITConfig(CAN1,CAN_IT_TME, DISABLE);                //发送中断
    //CAN_ITConfig(CAN1,CAN_IT_EWG | CAN_IT_EPV | CAN_IT_BOF | CAN_IT_LEC | CAN_IT_ERR | CAN_IT_WKU | CAN_IT_SLK, ENABLE);  // ERR中断
    //memset(CAN_msg_num,0,MAX_MAIL_NUM); // CAN缓存初始化
}
#else
void CAN_Filter_Config(void)
{   CAN_FilterInitTypeDef  CAN_FilterInitStructure;
	  CAN_FilterInitStructure.CAN_FilterNumber=0;	                     //过滤器0
 	  CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask; 
  	CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;   //32位 
  	CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000;                 //32位ID
  	CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
  	CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000;             //32位MASK
  	CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
		//对标志帧的过滤
		//CAN_FilterInitStructure.CAN_FilterIdHigh= (((u32)CAN_ID<<21)&0xFFFF0000)>>16; 
		//CAN_FilterInitStructure.CAN_FilterIdLow=(((u32)CAN_ID<<21)|CAN_ID_STD|CAN_RTR_DATA)&0xFFFF; 
		//CAN_FilterInitStructure.CAN_FilterMaskIdHigh   = 0xFFFF; 
		//CAN_FilterInitStructure.CAN_FilterMaskIdLow    = 0xFFFF; 
  	CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FilterFIFO0;//过滤器0关联到FIFO0
 	  CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;              //激活过滤器0
  	CAN_FilterInit(&CAN_FilterInitStructure);                         //滤波器初始化
	  CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);                            //FIFO0消息挂号中断允许.		    
}
#endif
/*******************************************************************************
 * 函数名：CAN1_IRQHandler_it
 * 描述  ：CAN-RX IRQ
 * 输入  ：无
 * 输出  : 无
 * 调用  ：外部调用
**********************************************************************************/
#if CAN_EXTSTD_ENABLE
void CAN1_IRQHandler_it(void) //CAN-RX
{
  CAN_Receive(CAN1, CAN_FIFO0, &CANRxMessage);                  //从邮箱中读出报文
  if((CANRxMessage.ExtId==0x1314) && (CANRxMessage.IDE==CAN_ID_EXT)//比较ID和数据是否为0x1314及DCBA 
     && (CANRxMessage.DLC==2) && ((CANRxMessage.Data[1]|CANRxMessage.Data[0]<<8)==0xDCBA))
  {}// flag = 0; 					       //接收成功  
  else
  {} // flag = 0xff; 					   //接收失败
}
#else
void CAN1_IRQHandler_it(void) //CAN-RX
{CAN_Receive(CAN1, CAN_FIFO0, &CANRxMessage);                  //从邮箱中读出报文
 CAN_PublicHookRx(&CANRxMessage);
}
#endif


/*******************************************************************************
 * 函数名：CAN_SetMsg
 * 描述  ：CAN通信报文内容设置
 * 输入  ：无
 * 输出  : 无
 * 调用  ：外部调用
**********************************************************************************/
#if CAN_EXTSTD_ENABLE
void CAN_SetMsg(void)
{	
	if(cand++>2500)
  {	cand=0;
		//TxMessage.StdId=0x00;						 
		CANTxMessage.ExtId=0x1314;				 //使用的扩展ID
		CANTxMessage.IDE=CAN_ID_EXT;			 //扩展模式
		CANTxMessage.RTR=CAN_RTR_DATA;		 //发送的是数据
		CANTxMessage.DLC=3;							 //数据长度为3字节
		CANTxMessage.Data[0]=0xAB;
		CANTxMessage.Data[1]=0xCD;
		if(a++>200)a=0;
		CANTxMessage.Data[2]=a;
		CAN_Transmit(CAN1, &CANTxMessage);//发送消息 “ABCD”
  }
}

#else

/*******************************************************************************
//can发送一组数据(固定格式:ID为0X12,标准帧,数据帧)	
//len:数据长度(最大为8)				     
//msg:数据指针,最大为8个字节.
//返回值:0,成功;其他,失败;
*******************************************************************************/
void CAN_SetMsg(void)
{	/*
  CANTxMessage.StdId=0x12;					    //标准标识符为0
  CANTxMessage.ExtId=0x12;				      //设置扩展标示符（29位）
  CANTxMessage.IDE=0;			              //使用扩展标识符
  CANTxMessage.RTR=0;		                //消息类型为数据帧，一帧8位
  CANTxMessage.DLC=8;							      //发送两帧信息
  for(i=0;i<8;i++)CANTxMessage.Data[i]=i+1;//第一帧信息          
  if(a++>200)a=0;CANTxMessage.Data[2]=a;
	CAN_Transmit(CAN1, &CANTxMessage);
 */	
  CANProcessPublicRxMsg (); 
}

#endif


/*******************************************************************************
 * 函数名：CAN_Config
 * 描述  ：完整配置CAN的功能
 * 输入  ：无
 * 输出  : 无
 * 调用  ：外部调用
**********************************************************************************/
void CAN_Config(void)
{
  CAN_GPIO_Config();
  CAN_NVIC_Config();
  CAN_Mode_Config();
  CAN_Filter_Config();
  CAN_J1939Public_Init();	
}


/**************************END OF FILE************************************/

