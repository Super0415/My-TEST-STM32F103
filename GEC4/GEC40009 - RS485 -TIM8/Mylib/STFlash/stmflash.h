#ifndef __STMFLASH_H__
#define __STMFLASH_H__

//////////////////////////////////////////////////////////////////////////////////////////////////////

//�û������Լ�����Ҫ����

#define STM32_FLASH_SIZE 512 	  //��ѡSTM32��FLASH������С(��λΪK)
#define STM32_FLASH_WREN 0        //ʹ��FLASHд��(0��������;1��ʹ��)
//////////////////////////////////////////////////////////////////////////////////////////////////////
#define FLASH_SAVE_ADDR    0X0807F000 				//����FLASH �����ַ(����Ϊż��) 0X1000 4K
//FLASH��ʼ��ַ
#define STM32_FLASH_BASE   0x08000000 	//STM32 FLASH����ʼ��ַ
//FLASH������ֵ

typedef  unsigned  char      uint8;
typedef  unsigned  short int uint16;
typedef  unsigned  long      uint32;

void FLASH_PowerOnInitFlash(void);
void FLASH_SaveParm(void);

void FLASH_PowerOnReadParm(void); //�ϵ��ȡ����
void FLASH_SaveAllModifParm(void);//�������Բ���
void FLASH_SavepParm(void);
void FLASH_SavesAdjParm(void);	
void FLASH_SavecCurveParm(void);
void FLASH_SaveOtherParm(void);



#endif

















