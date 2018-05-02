#include "USART232.h"

void USART232_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO	
	USART_InitTypeDef USART_InitStructure;  //�������ýṹ��
    //�ж����ȼ��ṹ��
	NVIC_InitTypeDef NVIC_InitStructure;	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);     //�ܽ�ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);      //���ڹ��� �ܽŸ���   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);      //����ʱ��
	
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;  //USART1-232  -  TX  ���
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;	 //���ø����������ģʽ          //���͹ܽ� ���ø����������
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10; //USART1-232  -  RX  ����
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;	 //����ģʽ                 //���չܽ� ���ø���ģʽ
	GPIO_Init(GPIOA,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */

	USART_InitStructure.USART_BaudRate = 9600;      //����������Ϊ9600	//������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;        //���ݳ�8λ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;             //1λֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;                    //��żʧ�� ��У��
	USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;    //Ӳ��������ʧ��  
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;     //�������ͺͽ���ģʽ
	USART_Init(USART1, &USART_InitStructure);          /* ��ʼ��USART1 */
	
	USART_Cmd(USART1, ENABLE);         //����1ʹ��
	USART_ClearFlag(USART1,USART_FLAG_TC);          //Ϊ�����ж϶����ԣ�������жϱ�־     USART_FLAG_TC������ɱ�־λ	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);     //�򿪴���1���жϣ�   ʹ�ܻ���ʧ��ָ����USART�ж�         USART_IT_RXNE�����ж�

	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);                           //����	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;   //�жϺ������               //EXTI0_IRQChannel  �汾��һ��
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    //��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;           //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;             //ʹ��
    NVIC_Init(&NVIC_InitStructure);	

}

