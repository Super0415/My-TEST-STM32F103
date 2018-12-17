//#include "ALL_Includes.h"
#include "TYPCortex.h"

#define  pParmPAGE_ADDR   (0x08000000 + 500 * 1024)//�������ò���������
#define  sAdjPAGE_ADDR    (0x08000000 + 502 * 1024)//����У�����
#define  cCurvePAGE_ADDR  (0x08000000 + 504 * 1024)//�����Զ������߲���
#define  fOtherPAGE_ADDR  (0x08000000 + 506 * 1024)//����������Ϣ

typedef  unsigned  char      uint8;
typedef  unsigned  short int uint16;
typedef  unsigned  long      uint32;

#if STM32_FLASH_WREN	//���ʹ����д 

void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//��ָ����ַ��ʼ����ָ�����ȵ�����
//Ҫд�뵽STM32 FLASH���ַ�������
//#define SIZE sizeof(TEXT_Buffer)/2	 			  	//���鳤��

//��ȡָ����ַ�İ���(16λ����)
//faddr:����ַ(�˵�ַ����Ϊ2�ı���!!)
//����ֵ:��Ӧ����.
u16 STMFLASH_ReadHalfWord(u32 faddr)
{
	return *(vu16*)faddr; 
}

//������д��
//WriteAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��  

void STMFLASH_Write_NoCheck(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)   
{ 			 		 
	u16 i;
	for(i=0;i<NumToWrite;i++)
	{
		FLASH_ProgramHalfWord(WriteAddr,pBuffer[i]);
	    WriteAddr+=2;//��ַ����2.
	}  
} 
//��ָ����ַ��ʼд��ָ�����ȵ�����
//WriteAddr:��ʼ��ַ(�˵�ַ����Ϊ2�ı���!!)
//pBuffer:����ָ��
//NumToWrite:����(16λ)��(����Ҫд���16λ���ݵĸ���.)
#if STM32_FLASH_SIZE<256
#define STM_SECTOR_SIZE 1024 //�ֽ�
#else 
#define STM_SECTOR_SIZE	2048
#endif		 
u16 STMFLASH_BUF[STM_SECTOR_SIZE/2];//�����2K�ֽ�
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)	
{
	u32 secpos;	   //������ַ
	u16 secoff;	   //������ƫ�Ƶ�ַ(16λ�ּ���)
	u16 secremain; //������ʣ���ַ(16λ�ּ���)	   
 	u16 i;    
	u32 offaddr;   //ȥ��0X08000000��ĵ�ַ
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))return;//�Ƿ���ַ
	FLASH_Unlock();						//����
	offaddr=WriteAddr-STM32_FLASH_BASE;		//ʵ��ƫ�Ƶ�ַ.
	secpos=offaddr/STM_SECTOR_SIZE;			//������ַ  0~127 for STM32F103RBT6
	secoff=(offaddr%STM_SECTOR_SIZE)/2;		//�������ڵ�ƫ��(2���ֽ�Ϊ������λ.)
	secremain=STM_SECTOR_SIZE/2-secoff;		//����ʣ��ռ��С   
	if(NumToWrite<=secremain)secremain=NumToWrite;//�����ڸ�������Χ
	while(1) 
	{	
		STMFLASH_Read(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//������������������
		for(i=0;i<secremain;i++)//У������
		{
			if(STMFLASH_BUF[secoff+i]!=0XFFFF)break;//��Ҫ����  	  
		}
		if(i<secremain)//��Ҫ����
		{
			FLASH_ErasePage(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE);//�����������
			for(i=0;i<secremain;i++)//����
			{
				STMFLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			STMFLASH_Write_NoCheck(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//д����������  
		}else STMFLASH_Write_NoCheck(WriteAddr,pBuffer,secremain);//д�Ѿ������˵�,ֱ��д������ʣ������. 				   
		if(NumToWrite==secremain)break;//д�������
		else//д��δ����
		{
			secpos++;				//������ַ��1
			secoff=0;				//ƫ��λ��Ϊ0 	 
		   	pBuffer+=secremain;  	//ָ��ƫ��
			WriteAddr+=secremain;	//д��ַƫ��	   
		   	NumToWrite-=secremain;	//�ֽ�(16λ)���ݼ�
			if(NumToWrite>(STM_SECTOR_SIZE/2))secremain=STM_SECTOR_SIZE/2;//��һ����������д����
			else secremain=NumToWrite;//��һ����������д����
		}	 
	};	
	FLASH_Lock();//����
}


//��ָ����ַ��ʼ����ָ�����ȵ�����
//ReadAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead)   	
{
	u16 i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadHalfWord(ReadAddr);//��ȡ2���ֽ�.
		ReadAddr+=2;//ƫ��2���ֽ�.	
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//WriteAddr:��ʼ��ַ
//WriteData:Ҫд�������
void Test_Write(u32 WriteAddr,u16 WriteData)   	
{
	STMFLASH_Write(WriteAddr,&WriteData,1);//д��һ���� 
}

#endif



/***************************************************************************************************
* ��������: MemReadByte()
* ��������: �Ӵ洢���ж���num�ֽ�����
* ��ڲ���: *dat:�������ݵı����ַ
*                        num        :�������ֽ���
* ���ڲ���: 0������ʧ�ܣ�1�������ɹ�
* ʹ��˵��: ��
* ��������: 2010��12��15��
***************************************************************************************************/
uint8 MemReadByte(uint16 *data,uint16 num,uint32 MemeryAddr)                                
{
        uint16 *temp_addr = (uint16 *)MemeryAddr;
        
        while(num --)
        {
                *data ++ = *temp_addr ++;
        }
                                                                                                        
        return 1;                                                                                                        
}
/***************************************************************************************************
* ��������: MemWriteByte()
* ��������: ��洢����д��num�ֽ�����
* ��ڲ���: *dat:��д������
*                        num        :д����ֽ���
* ���ڲ���: 0������ʧ�ܣ�1�������ɹ�
* ʹ��˵��: ��
* ��������: 2010��12��15��
***************************************************************************************************/
uint8 MemWriteByte(uint16 *data,uint16 num,uint32 MemeryAddr)                                
{
        FLASH_Status temp_stat;
        uint32 temp_addr = MemeryAddr;
                
        FLASH_Unlock();                                                                                                        // Flash���������������صļĴ���
        temp_stat = FLASH_ErasePage(MemeryAddr);                                                        // �����ƶ���ҳ
        
        if(temp_stat != FLASH_COMPLETE)
        {
                FLASH_Lock();
                return 0;
        }
        
        while(num --)
        {
                temp_stat = FLASH_ProgramHalfWord(temp_addr,*data);
                if(temp_stat != FLASH_COMPLETE)
                {
                        FLASH_Lock();
                        return 0;
                }
        
                temp_addr += 2;
                data++;
        }
        
        FLASH_Lock();        
        return 1;
}

void FLASH_SaveParm(void)
{
}

/*************************************************
//	FLASH_PowrOnInitFlash()
//  �ϵ��ʼ������
**************************************************/
void FLASH_PowerOnInitFlash(void)
{ u16 i;
  for(i=0;i<FLASH_FLASH_ArrayCon;i++)FLASHDATABASE[i].ByteInt=0; 
}
/*************************************************
//	FLASH_PowerOnRdSAVEDATATORAM()
//  �ϵ��falsh�ж�ȡ��������������ڴ�
**************************************************/
void FLASH_PowerOnRdSAVEDATATORAM(void)
{  u16 i=0;
	 for(i=0;i<GensRunMSaveCon;i++)
	 {if(FLASHDATABASE[GensRunMSaveCtr+i].Sbyte<0)
	  {FLASHDATABASE[GensRunMSaveCtr+i].Sbyte=0;
	  }
	 }
	
   EPROM_STARTNUM= MSAVE_EPROMSTARTNUM; 	  //�����ϴα����𶯴���
   RUNNINGHOUR   = MSAVE_RUNNINGHOUR  ; 	  //�����ϴα���������ʱ
   RUNNINGMINUTE = MSAVE_RUNNINGMINUTE; 	  //�����ϴα��������۷� 
   RUNNINGSEC    = MSAVE_RUNNINGSEC   ; 	  //�����ϴα��������� 
   KWHH          = MSAVE_KWHH         ; 	  //�����ϴα���ǧ��ʱ��λ
   KWHL          = MSAVE_KWHL         ;	    //�����ϴα���ǧ��ʱ��λ
}  

/*************************************************
//	FLASH_PowerOnReadParm()
//  �ϵ��ȡ�������
**************************************************/
void FLASH_PowerOnReadParm(void)
{ uint16 i=0;
	MemReadByte((uint16*)(FLASHDATABASE+0),              (sParmSetnum_ForMainPage+1)*2,   pParmPAGE_ADDR );//�������ò���������
	MemReadByte((uint16*)(FLASHDATABASE+sPa_VOLT_MAINS_A),sAdjParmPageCon*2,              sAdjPAGE_ADDR  );//����У�����
	MemReadByte((uint16*)(FLASHDATABASE+sPc_TEMP_R1),    (CurveDotCtr*2*CurveMainPgCtr)*2,cCurvePAGE_ADDR);//�����Զ������
	MemReadByte((uint16*)(FLASHDATABASE+GensRunMSaveCtr), GensRunMSaveCon*2,              fOtherPAGE_ADDR);//����������Ϣ
	
  DB_JudgeParm();
  FLASH_PowerOnRdSAVEDATATORAM();     //�ϵ��falsh�ж�ȡ����ķ��������в����������ڴ�
  
  for(i=0;i<FLASH_FLASH_ArrayCon;i++)//��ʼ��û�����õ�������Ϊ0
  {if(FLASHDATABASE[i].Sbyte==-1)FLASHDATABASE[i].Sbyte=0;
  } 
}


/* ******************************************************************** */
/*             void FLASH_SavepParm()                        */
//                                  
/* ******************************************************************** */
void FLASH_SavepParm(void)
{
	MemWriteByte((uint16*)(FLASHDATABASE+0),(sParmSetnum_ForMainPage+1)*2,pParmPAGE_ADDR );//�������ò���������
	TransValue();  //�����߼�����ʱ
}
/* ******************************************************************** */
/*             void FLASH_SavesAdjParm()                        */
//                                  
/* ******************************************************************** */
void FLASH_SavesAdjParm(void)
{
	MemWriteByte((uint16*)(FLASHDATABASE+sPa_VOLT_MAINS_A),sAdjParmPageCon*2,sAdjPAGE_ADDR  );//����У�����
}
/* ******************************************************************** */
/*             void FLASH_SavecCurveParm()                        */
//                                  
/* ******************************************************************** */
void FLASH_SavecCurveParm(void)
{
	MemWriteByte((uint16*)(FLASHDATABASE+sPc_TEMP_R1),(CurveDotCtr*2*CurveMainPgCtr)*2,cCurvePAGE_ADDR);//�����Զ������߲���
}
	/* ******************************************************************** */
/*             void FLASH_SaveOtherParm()                        */
//                                  
/* ******************************************************************** */;
void FLASH_SaveOtherParm(void)
{
	MemWriteByte((uint16*)(FLASHDATABASE+GensRunMSaveCtr), GensRunMSaveCon*2,fOtherPAGE_ADDR);//����������Ϣ
}

/*************************************************
//	FLASH_SaveAllModifParm()
//   �������
**************************************************/
void FLASH_SaveAllModifParm(void)
{
 FLASH_SavepParm();
 FLASH_SavesAdjParm();	
 FLASH_SavecCurveParm();
 FLASH_SaveOtherParm();
}


/****************The End *********************/







