//#include "ALL_Includes.h"
#include "TYPCortex.h"

#define  pParmPAGE_ADDR   (0x08000000 + 500 * 1024)//读出设置参数和语言
#define  sAdjPAGE_ADDR    (0x08000000 + 502 * 1024)//读出校验参数
#define  cCurvePAGE_ADDR  (0x08000000 + 504 * 1024)//读出自定义曲线参数
#define  fOtherPAGE_ADDR  (0x08000000 + 506 * 1024)//读出其他信息

typedef  unsigned  char      uint8;
typedef  unsigned  short int uint16;
typedef  unsigned  long      uint32;

#if STM32_FLASH_WREN	//如果使能了写 

void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);   		//从指定地址开始读出指定长度的数据
//要写入到STM32 FLASH的字符串数组
//#define SIZE sizeof(TEXT_Buffer)/2	 			  	//数组长度

//读取指定地址的半字(16位数据)
//faddr:读地址(此地址必须为2的倍数!!)
//返回值:对应数据.
u16 STMFLASH_ReadHalfWord(u32 faddr)
{
	return *(vu16*)faddr; 
}

//不检查的写入
//WriteAddr:起始地址
//pBuffer:数据指针
//NumToWrite:半字(16位)数  

void STMFLASH_Write_NoCheck(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)   
{ 			 		 
	u16 i;
	for(i=0;i<NumToWrite;i++)
	{
		FLASH_ProgramHalfWord(WriteAddr,pBuffer[i]);
	    WriteAddr+=2;//地址增加2.
	}  
} 
//从指定地址开始写入指定长度的数据
//WriteAddr:起始地址(此地址必须为2的倍数!!)
//pBuffer:数据指针
//NumToWrite:半字(16位)数(就是要写入的16位数据的个数.)
#if STM32_FLASH_SIZE<256
#define STM_SECTOR_SIZE 1024 //字节
#else 
#define STM_SECTOR_SIZE	2048
#endif		 
u16 STMFLASH_BUF[STM_SECTOR_SIZE/2];//最多是2K字节
void STMFLASH_Write(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)	
{
	u32 secpos;	   //扇区地址
	u16 secoff;	   //扇区内偏移地址(16位字计算)
	u16 secremain; //扇区内剩余地址(16位字计算)	   
 	u16 i;    
	u32 offaddr;   //去掉0X08000000后的地址
	if(WriteAddr<STM32_FLASH_BASE||(WriteAddr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))return;//非法地址
	FLASH_Unlock();						//解锁
	offaddr=WriteAddr-STM32_FLASH_BASE;		//实际偏移地址.
	secpos=offaddr/STM_SECTOR_SIZE;			//扇区地址  0~127 for STM32F103RBT6
	secoff=(offaddr%STM_SECTOR_SIZE)/2;		//在扇区内的偏移(2个字节为基本单位.)
	secremain=STM_SECTOR_SIZE/2-secoff;		//扇区剩余空间大小   
	if(NumToWrite<=secremain)secremain=NumToWrite;//不大于该扇区范围
	while(1) 
	{	
		STMFLASH_Read(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//读出整个扇区的内容
		for(i=0;i<secremain;i++)//校验数据
		{
			if(STMFLASH_BUF[secoff+i]!=0XFFFF)break;//需要擦除  	  
		}
		if(i<secremain)//需要擦除
		{
			FLASH_ErasePage(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE);//擦除这个扇区
			for(i=0;i<secremain;i++)//复制
			{
				STMFLASH_BUF[i+secoff]=pBuffer[i];	  
			}
			STMFLASH_Write_NoCheck(secpos*STM_SECTOR_SIZE+STM32_FLASH_BASE,STMFLASH_BUF,STM_SECTOR_SIZE/2);//写入整个扇区  
		}else STMFLASH_Write_NoCheck(WriteAddr,pBuffer,secremain);//写已经擦除了的,直接写入扇区剩余区间. 				   
		if(NumToWrite==secremain)break;//写入结束了
		else//写入未结束
		{
			secpos++;				//扇区地址增1
			secoff=0;				//偏移位置为0 	 
		   	pBuffer+=secremain;  	//指针偏移
			WriteAddr+=secremain;	//写地址偏移	   
		   	NumToWrite-=secremain;	//字节(16位)数递减
			if(NumToWrite>(STM_SECTOR_SIZE/2))secremain=STM_SECTOR_SIZE/2;//下一个扇区还是写不完
			else secremain=NumToWrite;//下一个扇区可以写完了
		}	 
	};	
	FLASH_Lock();//上锁
}


//从指定地址开始读出指定长度的数据
//ReadAddr:起始地址
//pBuffer:数据指针
//NumToWrite:半字(16位)数
void STMFLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead)   	
{
	u16 i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=STMFLASH_ReadHalfWord(ReadAddr);//读取2个字节.
		ReadAddr+=2;//偏移2个字节.	
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//WriteAddr:起始地址
//WriteData:要写入的数据
void Test_Write(u32 WriteAddr,u16 WriteData)   	
{
	STMFLASH_Write(WriteAddr,&WriteData,1);//写入一个字 
}

#endif



/***************************************************************************************************
* 函数名称: MemReadByte()
* 函数功能: 从存储器中读出num字节数据
* 入口参数: *dat:读出数据的保存地址
*                        num        :读出的字节数
* 出口参数: 0：操作失败；1：操作成功
* 使用说明: 无
* 创建日期: 2010年12月15日
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
* 函数名称: MemWriteByte()
* 函数功能: 向存储器中写入num字节数据
* 入口参数: *dat:待写入数据
*                        num        :写入的字节数
* 出口参数: 0：操作失败；1：操作成功
* 使用说明: 无
* 创建日期: 2010年12月15日
***************************************************************************************************/
uint8 MemWriteByte(uint16 *data,uint16 num,uint32 MemeryAddr)                                
{
        FLASH_Status temp_stat;
        uint32 temp_addr = MemeryAddr;
                
        FLASH_Unlock();                                                                                                        // Flash解锁，允许操作相关的寄存器
        temp_stat = FLASH_ErasePage(MemeryAddr);                                                        // 擦出制定的页
        
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
//  上电初始化数组
**************************************************/
void FLASH_PowerOnInitFlash(void)
{ u16 i;
  for(i=0;i<FLASH_FLASH_ArrayCon;i++)FLASHDATABASE[i].ByteInt=0; 
}
/*************************************************
//	FLASH_PowerOnRdSAVEDATATORAM()
//  上电从falsh中读取保存参数到测量内存
**************************************************/
void FLASH_PowerOnRdSAVEDATATORAM(void)
{  u16 i=0;
	 for(i=0;i<GensRunMSaveCon;i++)
	 {if(FLASHDATABASE[GensRunMSaveCtr+i].Sbyte<0)
	  {FLASHDATABASE[GensRunMSaveCtr+i].Sbyte=0;
	  }
	 }
	
   EPROM_STARTNUM= MSAVE_EPROMSTARTNUM; 	  //读出上次保存起动次数
   RUNNINGHOUR   = MSAVE_RUNNINGHOUR  ; 	  //读出上次保存运行累时
   RUNNINGMINUTE = MSAVE_RUNNINGMINUTE; 	  //读出上次保存运行累分 
   RUNNINGSEC    = MSAVE_RUNNINGSEC   ; 	  //读出上次保存运行秒 
   KWHH          = MSAVE_KWHH         ; 	  //读出上次保存千瓦时高位
   KWHL          = MSAVE_KWHL         ;	    //读出上次保存千瓦时低位
}  

/*************************************************
//	FLASH_PowerOnReadParm()
//  上电读取保存参数
**************************************************/
void FLASH_PowerOnReadParm(void)
{ uint16 i=0;
	MemReadByte((uint16*)(FLASHDATABASE+0),              (sParmSetnum_ForMainPage+1)*2,   pParmPAGE_ADDR );//读出设置参数和语言
	MemReadByte((uint16*)(FLASHDATABASE+sPa_VOLT_MAINS_A),sAdjParmPageCon*2,              sAdjPAGE_ADDR  );//读出校验参数
	MemReadByte((uint16*)(FLASHDATABASE+sPc_TEMP_R1),    (CurveDotCtr*2*CurveMainPgCtr)*2,cCurvePAGE_ADDR);//读出自定义参数
	MemReadByte((uint16*)(FLASHDATABASE+GensRunMSaveCtr), GensRunMSaveCon*2,              fOtherPAGE_ADDR);//读出其他信息
	
  DB_JudgeParm();
  FLASH_PowerOnRdSAVEDATATORAM();     //上电从falsh中读取保存的发动机运行参数到测量内存
  
  for(i=0;i<FLASH_FLASH_ArrayCon;i++)//初始化没有设置到的数据为0
  {if(FLASHDATABASE[i].Sbyte==-1)FLASHDATABASE[i].Sbyte=0;
  } 
}


/* ******************************************************************** */
/*             void FLASH_SavepParm()                        */
//                                  
/* ******************************************************************** */
void FLASH_SavepParm(void)
{
	MemWriteByte((uint16*)(FLASHDATABASE+0),(sParmSetnum_ForMainPage+1)*2,pParmPAGE_ADDR );//保存设置参数和语言
	TransValue();  //更新逻辑用延时
}
/* ******************************************************************** */
/*             void FLASH_SavesAdjParm()                        */
//                                  
/* ******************************************************************** */
void FLASH_SavesAdjParm(void)
{
	MemWriteByte((uint16*)(FLASHDATABASE+sPa_VOLT_MAINS_A),sAdjParmPageCon*2,sAdjPAGE_ADDR  );//保存校验参数
}
/* ******************************************************************** */
/*             void FLASH_SavecCurveParm()                        */
//                                  
/* ******************************************************************** */
void FLASH_SavecCurveParm(void)
{
	MemWriteByte((uint16*)(FLASHDATABASE+sPc_TEMP_R1),(CurveDotCtr*2*CurveMainPgCtr)*2,cCurvePAGE_ADDR);//保存自定义曲线参数
}
	/* ******************************************************************** */
/*             void FLASH_SaveOtherParm()                        */
//                                  
/* ******************************************************************** */;
void FLASH_SaveOtherParm(void)
{
	MemWriteByte((uint16*)(FLASHDATABASE+GensRunMSaveCtr), GensRunMSaveCon*2,fOtherPAGE_ADDR);//保存其他信息
}

/*************************************************
//	FLASH_SaveAllModifParm()
//   保存参数
**************************************************/
void FLASH_SaveAllModifParm(void)
{
 FLASH_SavepParm();
 FLASH_SavesAdjParm();	
 FLASH_SavecCurveParm();
 FLASH_SaveOtherParm();
}


/****************The End *********************/







