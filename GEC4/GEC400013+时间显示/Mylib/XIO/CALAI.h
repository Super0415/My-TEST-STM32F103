#ifndef __CALAI_H
#define __CALAI_H
//#include"DB.h"
#include "TYPCortex.h"

#define INPUT_NUM   20
#define OUTPUT_NUM  20
#define AI_NUM      10

extern M_INT8U INPUT_TEMP[INPUT_NUM];
extern M_INT8U OUTPUT_TEMP[OUTPUT_NUM];

extern unsigned short int LED_GENSET;
extern unsigned short int LED_GCB;
extern unsigned short int LED_MAINS;
extern unsigned short int LED_MCB;


#define DI_NOTUSED                INPUT_TEMP[0]//δʹ��
#define DI_TEMPHIGH               INPUT_TEMP[1]//�¶ȸ�ͣ��
#define DI_OPLOW                  INPUT_TEMP[2]//��ѹ��ͣ��
#define DI_EXTERN_WRN             INPUT_TEMP[3]//�ⲿ���뱨��
#define DI_EXTERN_STOP            INPUT_TEMP[4]//�ⲿ����ͣ��
#define DI_ENCOOLING              INPUT_TEMP[5]//�������ɢ��ͣ��
#define DI_GCB                    INPUT_TEMP[6]//�����բ����
#define DI_MCB                    INPUT_TEMP[7]//�е��բ����
#define DI_TEMPHIGH_NOSTOP        INPUT_TEMP[8]//�¶ȸ߽�ֹͣ��
#define DI_OPLOW_NOSTOP           INPUT_TEMP[9]//��ѹ�Ͳ�ͣ��
#define DI_RMTSTART               INPUT_TEMP[10]//Զ������
#define DI_LOWFUEL_WRN            INPUT_TEMP[11]//����λ����
#define DI_LOWLIQUID_WRN          INPUT_TEMP[12]//ˮλ�ͱ���
#define DI_LOWFUEL_STOP           INPUT_TEMP[13]//����λͣ��  
#define DI_LOWLIQUID_STOP         INPUT_TEMP[14]//��ˮλͣ��
#define DI_INHIBIT_AUTOSTART      INPUT_TEMP[15]//��ֹ������
#define DI_F_STOP_EM              INPUT_TEMP[16]//����ͣ������
#define DI_F_EDITOR_CONT          INPUT_TEMP[17]//�˵���̿���0-������1-�޷����Ĳ˵���


#define DO_NOTUSED                OUTPUT_TEMP[0]//��ʹ��
#define DO_COMMALARM              OUTPUT_TEMP[1]//��������
#define DO_STOPOUTPUT             OUTPUT_TEMP[2]//�õ�ͣ�����
#define DO_IDLE                   OUTPUT_TEMP[3]//���ٿ���(�պϵ���)
#define DO_PREHEAT                OUTPUT_TEMP[4]//Ԥ�ȿ���
#define DO_GCB                    OUTPUT_TEMP[5]//GCB��բ
#define DO_MCB                    OUTPUT_TEMP[6]//�е��բ
#define DO_OFFCB                  OUTPUT_TEMP[7]//��բ
#define DO_RAISE_SPEED            OUTPUT_TEMP[8]//���ٿ���
#define DO_REDUCE_SPEED           OUTPUT_TEMP[9]//���ٿ���
#define DO_DES_RUNNING            OUTPUT_TEMP[10]//��������
#define DO_FUELPUMP               OUTPUT_TEMP[11]//ȼ�ͱÿ���
#define DO_HIGHSPEEDWARM          OUTPUT_TEMP[12]//���ٿ���(ů�����)
#define DO_AUTOMODE               OUTPUT_TEMP[13]//�Զ�ģʽ
#define DO_COMMALARM_STOP         OUTPUT_TEMP[14]//ͣ���������
#define F_OUTPUT_FUEL             OUTPUT_TEMP[15]//ȼ�����
#define DO_IDLE_Close             OUTPUT_TEMP[16]//���ٿ���(�Ͽ�����)


void CAL_GEN_MAINVOL(void);
void XIOAiCheck(void);
void XIO_CALAI_LOOP(void);



#endif

/*************************/
