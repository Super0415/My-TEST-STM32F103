#include "USART485.h"

void USART485_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; //声明一个结构体变量，用来初始化GPIO	
	USART_InitTypeDef USART_InitStructure;  //串口配置结构体
    //中断优先级结构体
	NVIC_InitTypeDef NVIC_InitStructure;	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOG,ENABLE);     //管脚时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);      //串口功能 管脚复用
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);      //串口时钟              RCC_APB1Periph_USART2
  //RCC_APB1  和后面参数一致                                                         //RCC_APB1 -APB1总线
	                                                                                             //USART2 串口2
	
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;  //USART2-485  -  TX  输出
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	 //设置复用推挽输出模式               //发送管脚 配置复用推挽输出
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* 初始化GPIO */

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3; //USART2-485  -  RX  输入
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //浮空模式                      //接收管脚 配置浮空模式
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* 初始化GPIO */
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3; //USART2-485  -  控制端口  CS-485   --- 半双工
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //推挽输出模式
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //设置传输速率
	GPIO_Init(GPIOG,&GPIO_InitStructure); 	   /* 初始化GPIO */
	GPIO_ResetBits(GPIOG,GPIO_Pin_3);                                               //将控制端口清零，此时确保485处于接收状态
	

	USART_InitStructure.USART_BaudRate = 9600;      //波特率设置为9600	//波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;        //数据长8位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;             //1位停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;                    //奇偶失能 无校验
	USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;    //硬件流控制失能  
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;     //开启发送和接受模式
	USART_Init(USART2, &USART_InitStructure);          /* 初始化USART1 */
	
	USART_Cmd(USART2, ENABLE);         //串口1使能
	USART_ClearFlag(USART2,USART_FLAG_TC);          //为避免中断二义性，先清空中断标志     USART_FLAG_TC发送完成标志位	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);     //打开串口1的中断，   使能或者失能指定的USART中断         USART_IT_RXNE接收中断

	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //分组	
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;   //中断函数入口              
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;           //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //使能
    NVIC_Init(&NVIC_InitStructure);	

	

}





