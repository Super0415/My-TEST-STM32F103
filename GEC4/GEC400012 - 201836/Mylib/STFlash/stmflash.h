#ifndef __STMFLASH_H__
#define __STMFLASH_H__

//////////////////////////////////////////////////////////////////////////////////////////////////////

//用户根据自己的需要设置

#define STM32_FLASH_SIZE 512 	  //所选STM32的FLASH容量大小(单位为K)
#define STM32_FLASH_WREN 0        //使能FLASH写入(0，不是能;1，使能)
//////////////////////////////////////////////////////////////////////////////////////////////////////
#define FLASH_SAVE_ADDR    0X0807F000 				//设置FLASH 保存地址(必须为偶数) 0X1000 4K
//FLASH起始地址
#define STM32_FLASH_BASE   0x08000000 	//STM32 FLASH的起始地址
//FLASH解锁键值

typedef  unsigned  char      uint8;
typedef  unsigned  short int uint16;
typedef  unsigned  long      uint32;

void FLASH_PowerOnInitFlash(void);
void FLASH_SaveParm(void);

void FLASH_PowerOnReadParm(void); //上电读取参数
void FLASH_SaveAllModifParm(void);//保存所以参数
void FLASH_SavepParm(void);
void FLASH_SavesAdjParm(void);	
void FLASH_SavecCurveParm(void);
void FLASH_SaveOtherParm(void);



#endif

















