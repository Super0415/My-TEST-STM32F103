#include "TYPCortex.h"


extern void CAN_J1939Public_Init(void);
extern void CAN_PublicHookRx(CanRxMsg *pMsg);
extern void CANProcessPublicRxMsg (void);


/*******************************************************************************
 * �ļ���  ��can.c
 * Ӳ�����ӣ�PA11-CAN-RX  |	PA12-CAN-TX   
 * ����    ������
**********************************************************************************/
CanTxMsg CANTxMessage;			        //���ͻ�����
CanRxMsg CANRxMessage;				      //���ջ�����
u32  CAN_ID=0x123;

#define CAN_EXTSTD_ENABLE	  0       //1:ʹ����չ֡���� 0:��ͨ֡

/*******************************************************************************
 * ��������CAN_GPIO_Config
 * ����  ��CAN��GPIO ����,PA11�������룬PA12�������
 * ����  ����
 * ���  : ��
 * ����  ���ڲ�����
**********************************************************************************/
void CAN_GPIO_Config(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); //����ʱ������
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;            //Configure CAN pin: RX PA11						
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;	        //��������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;            //Configure CAN pin: TX PA12			
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		    //�����������
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;    
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*******************************************************************************
 * ��������CAN_NVIC_Config
 * ����  ��CAN��NVIC ����,��1���ȼ��飬0��0���ȼ�
 * ����  ����
 * ���  : ��
 * ����  ���ڲ�����
**********************************************************************************/
void CAN_NVIC_Config(void)
{
   NVIC_InitTypeDef NVIC_InitStructure;
	 //NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	 	                                
	 NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn; //�ж����� CAN1 RX0�ж�
   NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0
   NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;			    //�����ȼ�Ϊ0
   NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
 * ��������CAN_Mode_Config
 * ����  ��CAN��ģʽ ����
 * ����  ����
 * ���  : ��
 * ����  ���ڲ�����
**********************************************************************************/
#if CAN_EXTSTD_ENABLE
void CAN_Mode_Config(void)
{
    CAN_InitTypeDef  CAN_InitStructure;
	  CAN_DeInit(CAN1);
	  CAN_StructInit(&CAN_InitStructure);
	  CAN_InitStructure.CAN_TTCM=DISABLE;			   //MCR-TTCM  �ر�ʱ�䴥��ͨ��ģʽʹ��
    CAN_InitStructure.CAN_ABOM=ENABLE;			   //MCR-ABOM  �Զ����߹��� 
    CAN_InitStructure.CAN_AWUM=ENABLE;			   //MCR-AWUM  ʹ���Զ�����ģʽ
    CAN_InitStructure.CAN_NART=DISABLE;			   //MCR-NART  ��ֹ�����Զ��ش�	  DISABLE-�Զ��ش�
    CAN_InitStructure.CAN_RFLM=DISABLE;			   //MCR-RFLM  ����FIFO ����ģʽ  DISABLE-���ʱ�±��ĻḲ��ԭ�б���  
    CAN_InitStructure.CAN_TXFP=DISABLE;			   //MCR-TXFP  ����FIFO���ȼ� DISABLE-���ȼ�ȡ���ڱ��ı�ʾ�� 
    CAN_InitStructure.CAN_Mode = CAN_Mode_Normal; //��������ģʽ???? CAN_Mode_LoopBack ????? CAN_Mode_Normal
    CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;		    //BTR-SJW ����ͬ����Ծ��� 1��ʱ�䵥Ԫ
    CAN_InitStructure.CAN_BS1=CAN_BS1_13tq;		    //BTR-TS1 ʱ���1 ռ����13��ʱ�䵥Ԫ
    CAN_InitStructure.CAN_BS2=CAN_BS2_2tq;		    //BTR-TS1 ʱ���2 ռ����2��ʱ�䵥Ԫ
    CAN_InitStructure.CAN_Prescaler =9;		        //BTR-BRP �����ʷ�Ƶ��������ʱ�䵥Ԫ��ʱ�䳤�� 36/9/(1+13+2)=0.25Mbps
	                                                //36M/(1+12+3)/9= 250kbps
                                                  //36M/(1+5+2)/9 = 500kbps
                                                  //36M(1+2+1)/9 = 1M
	  CAN_Init(CAN1, &CAN_InitStructure);
	
}
#else
void CAN_Mode_Config(void)
{
    CAN_InitTypeDef  CAN_InitStructure;            //CAN��Ԫ����
	  CAN_DeInit(CAN1);
	  CAN_StructInit(&CAN_InitStructure);
 	  CAN_InitStructure.CAN_TTCM=DISABLE;						 //��ʱ�䴥��ͨ��ģʽ  
 	  CAN_InitStructure.CAN_ABOM=DISABLE;						 //����Զ����߹���	 
  	CAN_InitStructure.CAN_AWUM=DISABLE;						 //˯��ģʽͨ���������(���CAN->MCR��SLEEPλ)
  	CAN_InitStructure.CAN_NART=ENABLE;						 //��ֹ�����Զ����� 
  	CAN_InitStructure.CAN_RFLM=DISABLE;						 //���Ĳ�����,�µĸ��Ǿɵ� 
  	CAN_InitStructure.CAN_TXFP=DISABLE;						 //���ȼ��ɱ��ı�ʶ������ 
  	CAN_InitStructure.CAN_Mode= CAN_Mode_Normal;	 //ģʽ���ã� mode:0,��ͨģʽ;1,�ػ�ģʽ; 
  	//���ò�����
  	CAN_InitStructure.CAN_SJW=CAN_SJW_1tq;				 //����ͬ����Ծ���(Tsjw)Ϊtsjw+1��ʱ�䵥λ  CAN_SJW_1tq	 CAN_SJW_2tq CAN_SJW_3tq CAN_SJW_4tq
  	CAN_InitStructure.CAN_BS1=CAN_BS1_13tq;        //Tbs1=tbs1+1��ʱ�䵥λCAN_BS1_1tq ~CAN_BS1_16tq
  	CAN_InitStructure.CAN_BS2=CAN_BS2_2tq;         //Tbs2=tbs2+1��ʱ�䵥λCAN_BS2_1tq ~	CAN_BS2_8tq
  	CAN_InitStructure.CAN_Prescaler=9;             //��Ƶϵ��(Fdiv)Ϊbrp+1	
  	CAN_Init(CAN1, &CAN_InitStructure);            //��ʼ��CAN1 
}
#endif
/*******************************************************************************
 * ��������CAN_Filter_Config
 * ����  ��CAN�Ĺ����� ����
 * ����  ����
 * ���  : ��
 * ����  ���ڲ�����
**********************************************************************************/
#if CAN_EXTSTD_ENABLE
void CAN_Filter_Config(void)
{
    CAN_FilterInitTypeDef  CAN_FilterInitStructure;
	  CAN_FilterInitStructure.CAN_FilterNumber=0;						        //��������0
    CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask;	//�����ڱ�ʶ������λģʽ
	  CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;//������λ��Ϊ����32λ��
	//ʹ�ܱ��ı�ʾ�����������ձ�ʾ�������ݽ��бȶԹ��ˣ���չID�������µľ����������ǵĻ��������FIFO0
    CAN_FilterInitStructure.CAN_FilterIdHigh= (((u32)0x1314<<3)&0xFFFF0000)>>16;				        //Ҫ���˵�ID��λ 
    CAN_FilterInitStructure.CAN_FilterIdLow= (((u32)0x1314<<3)|CAN_ID_EXT|CAN_RTR_DATA)&0xFFFF; //Ҫ���˵�ID��λ 
    CAN_FilterInitStructure.CAN_FilterMaskIdHigh= 0xFFFF;			                                  //��������16λÿλ����ƥ��
    CAN_FilterInitStructure.CAN_FilterMaskIdLow= 0xFFFF;			                                  //��������16λÿλ����ƥ��
	  CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FilterFIFO0 ;				                  //��������������FIFO0
	  CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;			                                  //ʹ�ܹ�����
	  CAN_FilterInit(&CAN_FilterInitStructure);
  	CAN_ITConfig(CAN1, CAN_IT_FMP0, ENABLE);                                                    //CANͨ���ж�ʹ��
    //CAN_ITConfig(CAN1,CAN_IT_FMP0 | CAN_IT_FF0 | CAN_IT_FOV0, ENABLE);  // fifo0�ж�
    //CAN_ITConfig(CAN1,CAN_IT_FMP1 | CAN_IT_FF1 | CAN_IT_FOV1, ENABLE);  // fifo1�ж�
    //CAN_ITConfig(CAN1,CAN_IT_TME, DISABLE);                //�����ж�
    //CAN_ITConfig(CAN1,CAN_IT_EWG | CAN_IT_EPV | CAN_IT_BOF | CAN_IT_LEC | CAN_IT_ERR | CAN_IT_WKU | CAN_IT_SLK, ENABLE);  // ERR�ж�
    //memset(CAN_msg_num,0,MAX_MAIL_NUM); // CAN�����ʼ��
}
#else
void CAN_Filter_Config(void)
{   CAN_FilterInitTypeDef  CAN_FilterInitStructure;
	  CAN_FilterInitStructure.CAN_FilterNumber=0;	                     //������0
 	  CAN_FilterInitStructure.CAN_FilterMode=CAN_FilterMode_IdMask; 
  	CAN_FilterInitStructure.CAN_FilterScale=CAN_FilterScale_32bit;   //32λ 
  	CAN_FilterInitStructure.CAN_FilterIdHigh=0x0000;                 //32λID
  	CAN_FilterInitStructure.CAN_FilterIdLow=0x0000;
  	CAN_FilterInitStructure.CAN_FilterMaskIdHigh=0x0000;             //32λMASK
  	CAN_FilterInitStructure.CAN_FilterMaskIdLow=0x0000;
		//�Ա�־֡�Ĺ���
		//CAN_FilterInitStructure.CAN_FilterIdHigh= (((u32)CAN_ID<<21)&0xFFFF0000)>>16; 
		//CAN_FilterInitStructure.CAN_FilterIdLow=(((u32)CAN_ID<<21)|CAN_ID_STD|CAN_RTR_DATA)&0xFFFF; 
		//CAN_FilterInitStructure.CAN_FilterMaskIdHigh   = 0xFFFF; 
		//CAN_FilterInitStructure.CAN_FilterMaskIdLow    = 0xFFFF; 
  	CAN_FilterInitStructure.CAN_FilterFIFOAssignment=CAN_FilterFIFO0;//������0������FIFO0
 	  CAN_FilterInitStructure.CAN_FilterActivation=ENABLE;              //���������0
  	CAN_FilterInit(&CAN_FilterInitStructure);                         //�˲�����ʼ��
	  CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);                            //FIFO0��Ϣ�Һ��ж�����.		    
}
#endif
/*******************************************************************************
 * ��������CAN1_IRQHandler_it
 * ����  ��CAN-RX IRQ
 * ����  ����
 * ���  : ��
 * ����  ���ⲿ����
**********************************************************************************/
#if CAN_EXTSTD_ENABLE
void CAN1_IRQHandler_it(void) //CAN-RX
{
  CAN_Receive(CAN1, CAN_FIFO0, &CANRxMessage);                  //�������ж�������
  if((CANRxMessage.ExtId==0x1314) && (CANRxMessage.IDE==CAN_ID_EXT)//�Ƚ�ID�������Ƿ�Ϊ0x1314��DCBA 
     && (CANRxMessage.DLC==2) && ((CANRxMessage.Data[1]|CANRxMessage.Data[0]<<8)==0xDCBA))
  {}// flag = 0; 					       //���ճɹ�  
  else
  {} // flag = 0xff; 					   //����ʧ��
}
#else
void CAN1_IRQHandler_it(void) //CAN-RX
{CAN_Receive(CAN1, CAN_FIFO0, &CANRxMessage);                  //�������ж�������
 CAN_PublicHookRx(&CANRxMessage);
}
#endif


/*******************************************************************************
 * ��������CAN_SetMsg
 * ����  ��CANͨ�ű�����������
 * ����  ����
 * ���  : ��
 * ����  ���ⲿ����
**********************************************************************************/
#if CAN_EXTSTD_ENABLE
void CAN_SetMsg(void)
{	
	if(cand++>2500)
  {	cand=0;
		//TxMessage.StdId=0x00;						 
		CANTxMessage.ExtId=0x1314;				 //ʹ�õ���չID
		CANTxMessage.IDE=CAN_ID_EXT;			 //��չģʽ
		CANTxMessage.RTR=CAN_RTR_DATA;		 //���͵�������
		CANTxMessage.DLC=3;							 //���ݳ���Ϊ3�ֽ�
		CANTxMessage.Data[0]=0xAB;
		CANTxMessage.Data[1]=0xCD;
		if(a++>200)a=0;
		CANTxMessage.Data[2]=a;
		CAN_Transmit(CAN1, &CANTxMessage);//������Ϣ ��ABCD��
  }
}

#else

/*******************************************************************************
//can����һ������(�̶���ʽ:IDΪ0X12,��׼֡,����֡)	
//len:���ݳ���(���Ϊ8)				     
//msg:����ָ��,���Ϊ8���ֽ�.
//����ֵ:0,�ɹ�;����,ʧ��;
*******************************************************************************/
void CAN_SetMsg(void)
{	/*
  CANTxMessage.StdId=0x12;					    //��׼��ʶ��Ϊ0
  CANTxMessage.ExtId=0x12;				      //������չ��ʾ����29λ��
  CANTxMessage.IDE=0;			              //ʹ����չ��ʶ��
  CANTxMessage.RTR=0;		                //��Ϣ����Ϊ����֡��һ֡8λ
  CANTxMessage.DLC=8;							      //������֡��Ϣ
  for(i=0;i<8;i++)CANTxMessage.Data[i]=i+1;//��һ֡��Ϣ          
  if(a++>200)a=0;CANTxMessage.Data[2]=a;
	CAN_Transmit(CAN1, &CANTxMessage);
 */	
  CANProcessPublicRxMsg (); 
}

#endif


/*******************************************************************************
 * ��������CAN_Config
 * ����  ����������CAN�Ĺ���
 * ����  ����
 * ���  : ��
 * ����  ���ⲿ����
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

