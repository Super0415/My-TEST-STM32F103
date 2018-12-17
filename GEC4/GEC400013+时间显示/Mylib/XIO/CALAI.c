//#include "ALL_Includes.h"
#include <math.h>
#include "TYPCortex.h"

#define BUF_LEN     16

#define CHN_BATT     5
#define CHN_CHARGE   4
#define CHN_AI1      0  
#define CHN_AI2      1  
#define CHN_AI3      2
#define CHN_AI4      3

#define _M_PI      3.14159265358979323846   /* pi         */

volatile M_INT8U ADSEQ=0;
volatile M_INT8U FFTNUM=0;
volatile M_INT8U FFTNUM2=0;

unsigned short int LED_GENSET;
unsigned short int LED_GCB;
unsigned short int LED_MAINS;
unsigned short int LED_MCB;

M_INT32U OilPressO3AI;  //ŷ3������AD����
M_INT16U OilPressO3Real;
M_INT16U OilPressO3[BUF_LEN];
float ADJST_O3=502.8; //ŷ3ѹ������У��

M_INT8U INPUT_TEMP[INPUT_NUM];
M_INT8U OUTPUT_TEMP[OUTPUT_NUM];

M_INT16U DataArrGENA[32];   //�ɼ�32��A�෢���ѹADֵ
M_INT16U DataArrGENB[32];   //�ɼ�32��B�෢���ѹADֵ
M_INT16U DataArrGENC[32];   //�ɼ�32��C�෢���ѹADֵ
M_INT16U DataArrIA[32];     //�ɼ�32��A�෢�����ADֵ
M_INT16U DataArrIB[32];     //�ɼ�32��A�෢�����ADֵ
M_INT16U DataArrIC[32];     //�ɼ�32��A�෢�����ADֵ
M_INT16U DataArrMAINA[32];  //�ɼ�32��A���е��ѹADֵ
M_INT16U DataArrMAINB[32];  //�ɼ�32��A���е��ѹADֵ
M_INT16U DataArrMAINC[32];  //�ɼ�32��A���е��ѹADֵ

M_INT32U DataArrAI[AI_NUM]; //���˵����������ģ�����ɼ������
M_INT32S AI_ADVALUE[AI_NUM];
M_INT32S AI_OHM[AI_NUM];
M_INT32U SensorBreakLineV[AI_NUM];
float ADJUST[AI_NUM]={ 1,1,1,1,1,1,1,1,1,1,};

float GENPT=1.0;
float MAINPT=1.0;

M_FP32 modulusV1=103420;//����
M_FP32 modulusV2=57600;//�е�
M_FP32 modulusIA=718000;
M_FP32 modulusIB=708600;
M_FP32 modulusIC=700000;


M_INT16U angle_buf1;
M_INT16U angle_buf2;
M_INT16U angle_buf3;
      
M_INT16S KWALL100=0;
M_INT32S KWA100 = 0;
M_INT32S KWB100 = 0;
M_INT32S KWC100 = 0;
M_INT32S KVARA100 = 0;
M_INT32S KVARB100 = 0;
M_INT32S KVARC100 = 0;
M_INT32S KVAA100=0;
M_INT32S KVAB100=0;
M_INT32S KVAC100=0;

M_INT32S PhaseR[9];
M_INT32S PhaseI[9];

M_FP32 CT;
M_INT16U FUELBUFF[BUF_LEN];           //Һλ
M_INT16U UA1BUFF[BUF_LEN];            //���� A���ѹ
M_INT16U UB1BUFF[BUF_LEN];            //���� B���ѹ
M_INT16U UC1BUFF[BUF_LEN];            //���� C���ѹ
M_INT16U UA2BUFF[BUF_LEN];            //�е� A���ѹ
M_INT16U UB2BUFF[BUF_LEN];            //�е� B���ѹ
M_INT16U UC2BUFF[BUF_LEN];            //�е� C���ѹ

M_INT16U UAB1BUFF[BUF_LEN];           //���� AB���ѹ
M_INT16U UBC1BUFF[BUF_LEN];           //���� BC���ѹ
M_INT16U UCA1BUFF[BUF_LEN];           //���� CA���ѹ

M_INT16U UAB2BUFF[BUF_LEN];           //�е� AB���ѹ
M_INT16U UBC2BUFF[BUF_LEN];           //�е� BC���ѹ
M_INT16U UCA2BUFF[BUF_LEN];           //�е� CA���ѹ
M_INT32S IABUFF[BUF_LEN];             //���� A�����
M_INT32S IBBUFF[BUF_LEN];             //���� B�����
M_INT32S ICBUFF[BUF_LEN];             //���� C�����

M_INT16U AI0BUFF[BUF_LEN];
M_INT16U AI1BUFF[BUF_LEN];
M_INT16U AI2BUFF[BUF_LEN];
M_INT16U AI3BUFF[BUF_LEN];
M_INT16U AI4BUFF[BUF_LEN];
M_INT16U AI5BUFF[BUF_LEN];
M_INT16U AI6BUFF[BUF_LEN];
M_INT16U AI7BUFF[BUF_LEN];

M_INT16U AIBUFF[AI_NUM][BUF_LEN];     //ģ����������
M_INT16U BATTBUFF[BUF_LEN];
M_INT16U CHARGEBUFF[BUF_LEN];

M_INT32S    r_powa_buf[BUF_LEN];//real power gen a phase buf       ��Чֵ
M_INT32S    r_powb_buf[BUF_LEN];//real power gen b phase buf
M_INT32S    r_powc_buf[BUF_LEN];//real power gen c phase buf
M_INT32S    i_powa_buf[BUF_LEN];//image power gen a phase buf      ���ֵ
M_INT32S    i_powb_buf[BUF_LEN];//image power gen b phase buf
M_INT32S    i_powc_buf[BUF_LEN];//image power gen c phase buf

M_INT16S OIL_CURVE_CUSTOM[8][2];
M_INT16S TEMP_CURVE_CUSTOM[8][2];
M_INT16S LEVEL_CURVE_CUSTOM[8][2];
M_INT16S OilTempLevel_CUSTOM_BUF[16][2];


M_INT16S PowerVoltageReal;
M_INT16S ChargerVoltageReal;
M_INT16U GEN_PA,GEN_PB,GEN_PC;
M_INT16U MAIN_PA,MAIN_PB,MAIN_PC;

const long cos_tab[] =
{
    10000,    9808,    9239,    8315,
    7071,     5556,    3827,     1951,
    0,        -1951,   -3827,  -5556,
    -7071,   -8315,  -9239,  -9808,
    -10000,  -9808,  -9239,  -8315,
    -7071,   -5556,  -3827,   -1951,
    0,       1951,    3827,    5556,
    7071,    8315,    9239,    9808,
};
const long sin_tab[] =
{
    0,         1951,      3827,    5556,
    7071,    8315,    9239,    9808,
    10000,    9808,    9239,    8315,
    7071,     5556,    3827,     1951,
    0,        -1951,    -3827,  -5556,
    -7071,  -8315,  -9239,  -9808,
    -10000,  -9808, -9239,  -8315,
    -7071,  -5556,  -3827,   -1951,
};

//��ѹ:
#define  SensorCurveCon 16  //ѡ�񴫸������ߵ��� 

const M_INT16S OIL_CURVE_VDO_10bar[SensorCurveCon][2] =      
 {
   {0, 0},    {16, 0},    {32, 179},   {48, 241},   {64, 338},   {96, 503},    {128, 703},   {176, 1034},
   {300,1034},{600,1034}, {1000,1034}, {2000,1034}, {5000,1034}, {8000, 1034}, {10000,1034}, {12000,1034} 
 };
const M_INT16S OIL_CURVE_SGH_10bar[SensorCurveCon][2] =      
 {
  {0,  0},
  {25, 0},    {35, 0},    {59, 200},    {98, 400},   {134, 600},   {192, 1000},  {200, 1000}, {240, 1000},
  {600,1000}, {1000,1000}, {2000,1000}, {5000,1000}, {8000, 1000}, {10000,1000}, {12000,1000}
 };

const M_INT16S OIL_CURVE_SGD_10bar[SensorCurveCon][2] =      
 {
  {0, 0},    
  {15, 0},   {24, 0},     {48, 200},   {88, 400},   {119, 600},   {149, 800},   {177,1000},  {200, 1000},
  {600,1000},{1000,1000}, {2000,1000}, {5000,1000}, {8000, 1000}, {10000,1000}, {12000,1000}
 };
                                                           
const M_INT16S OIL_CURVE_Curtis_10bar[SensorCurveCon][2] =   
 {
  {0, 0},    {10, 0},   {49, 200},  {88, 400},  {119, 600}, {149, 800},  {178, 1000}, {240, 1000},
  {300,1034},{600,1034},{1000,1034},{2000,1034},{5000,1034},{8000, 1034},{10000,1034},{12000,1034}
 };
const M_INT16S OIL_CURVE_Datcon_10bar[SensorCurveCon][2] =   
 {
  {0, 1034}, {38, 1034},{62, 758}, {101, 483},{127, 345}, {160, 207},  {206, 69},   {207, 0},
  {300,0},   {600,0},   {1000,0},  {2000,0},  {5000,0},   {8000, 0},   {10000,0},   {12000,0}
 }; 
const M_INT16S OIL_CURVE_VOLVO_EC_10bar[SensorCurveCon][2] = 
 {
  {0,  0},   
  {12, 0},   {58, 200}, {93, 400}, {124, 600},{152, 800}, {184, 1000}, {250, 1000}, {251, 0},
  {600,0},   {1000,0},  {2000,0},  {5000,0},  {8000, 0},  {10000,0},   {12000,0}
 };
 
const M_INT16S OIL_CURVE_SGX_10bar[SensorCurveCon][2] =      
 {
  {0,  0},  
  {15, 0},   {30, 100},  {50, 200},   {86, 400},   {100, 500},   {132, 700},   {168, 1000}, {200, 1000},
  {600,1000},{1000,1000},{2000,1000}, {5000,1000}, {8000, 1000}, {10000,1000}, {12000,1000}
 };


//ˮ��:
const M_INT16S TEMP_CURVE_VDO_163C[SensorCurveCon][2] =      
   {
      {0, 163},   
      {0, 163},  {32, 110}, {64, 85},  {96, 73},  {128, 64},  {192, 53},  {256, 44},  {480, 35},
      {600,35},  {1000,35}, {2000,35}, {5000,35}, {8000, 35}, {10000,35}, {12000,35} 
   };

const M_INT16S TEMP_CURVE_SGH_140C[SensorCurveCon][2] =
   {
     {0,  140}, 
     {19, 140}, {32, 120}, {56, 100}, {77, 90},  {106, 80},  {217, 60},  {327, 50},  {508, 40},
     {600,40},  {1000,40}, {2000,40}, {5000,40}, {8000, 40}, {10000,40}, {12000,40} 
   };
   
const M_INT16S TEMP_CURVE_SGD_180C[SensorCurveCon][2] =      
   {
     {0, 180},  
     {0, 180},  {17, 130}, {28, 110}, {36, 100}, {64, 80},  {128, 60}, {288, 40},  {732, 20},
     {800,20},  {1000,20}, {2000,20}, {5000,20}, {8000, 20},{10000,20},{12000,20} 
   };
   
const M_INT16S TEMP_CURVE_Curtis_140C[SensorCurveCon][2] =   
   {
    {0, 140}, 
    {0, 140},  {47, 120}, {77, 100}, {133, 80}, {246, 60},  {480, 35},  {480, 35},  {480, 35},
    {600,35},  {1000,35}, {2000,35}, {5000,35}, {8000, 35}, {10000,35}, {12000,35} 
   };

const M_INT16S TEMP_CURVE_Datcon_140C[SensorCurveCon][2] =   
   {
    {0, 140},  {25, 140}, 
    {55, 140}, {76, 120}, {106, 100},{197, 80},  {426, 60},  {952, 40}, {952, 40},  {952, 40},
    {1000,40}, {2000,40}, {5000,40}, {8000, 40}, {10000,40}, {12000,40}
   };
   
const M_INT16S TEMP_CURVE_VOLVO_EC_120C[SensorCurveCon][2] = 
   {
    {0,  120},
    {13, 120}, {18, 110}, {23, 100}, {32, 90},  {41, 80},   {61, 70},   {102, 60},  {220, 40},
    {600,40},  {1000,40}, {2000,40}, {5000,40}, {8000, 40}, {10000,40}, {12000,40}
   };
   
const M_INT16S TEMP_CURVE_SGX_140C[SensorCurveCon][2] =      
   {
    {0, 140},  
    {0, 140},  {21, 110}, {28, 100}, {39, 90},  {56, 80},   {116, 60},  {258, 40},  {300, 20},
    {500,20},  {1000,20}, {2000,20}, {5000,20}, {8000, 20}, {10000,20}, {12000,20}
   };

const M_INT16S TEMP_CURVE_PT100[SensorCurveCon][2] =         
   {
    {0,   0},
    {100, 0},  {112, 30}, {120, 50}, {127, 70}, {135, 90}, {139, 100},  {147, 120}, {151, 130},
    {155,140}, {158,150}, {162,160}, {166,170}, {170,180}, {10000,180}, {12000,180}
   };

const M_INT16S TEMP_CURVE_O3[SensorCurveCon][2] =         
   {
    {  0,120},
    {115,120},  {146,110}, {188,100}, {245, 90}, {333, 80}, {435,  70},  {596,  60}, {834, 50},
    {1175, 40}, {1707,30}, {2500,20}, {3792,10}, {5896, 0}, {10000, 0}, {12000,  0}
   }; //ŷ3������  


//Һλ:

const M_INT16S FUEL_CURVE_SGH[SensorCurveCon][2] = 
  {
   {0, 0},   {20, 10},   {40, 20},   {80, 40},   {100, 50},  {120, 60},   {160, 80},   {200, 100},
   {400,100},{500,100},  {1000,100}, {2000,100}, {5000,100}, {8000, 100}, {10000,100}, {12000,100}
  };
  
const M_INT16S FUEL_CURVE_SGD[SensorCurveCon][2] = 
  {
   {0, 0},   {20, 10},   {40, 20},   {80, 40},   {100, 50},  {120, 60},   {160, 80},   {200, 100},
   {400,100},{500,100},  {1000,100}, {2000,100}, {5000,100}, {8000, 100}, {10000,100}, {12000,100}
  };
const M_INT16S FUEL_CURVE_YW[SensorCurveCon][2] = 					//~YW-ES-8-2S(MS)Һλ������			8Ӣ��-0-180ŷ		��ͼƬ�ͺŲ�ͬ		������ֵ/Һλ�߶Ȱٷֱȣ�
	{
   {0, 100},  {18, 90},   {36, 80},   {72, 60},   {90, 50},  {108, 40},   {144, 20},   {180, 0},
   {400,0},		{500,0},  	{1000,0}, 	{2000,0}, 	{5000,0}, 	{8000, 0}, 	{10000,0}, 		{12000,0}
		 
  };  

void CAL_GEN_MAINVOL(void)
{
  if(ADSEQ == 0)
    {
      if(FFTNUM < 32)
        {
//            DataArrGENA[FFTNUM] = ADC_ConvertedValue[3]-ADC_ConvertedValue[15];     //@@@@@@@@@ZC��д
//            DataArrGENB[FFTNUM] = ADC_ConvertedValue[4]-ADC_ConvertedValue[15];
//            DataArrGENC[FFTNUM] = ADC_ConvertedValue[5]-ADC_ConvertedValue[15];      //�����ѹ
//          
//            DataArrIA[FFTNUM] = ADC_ConvertedValue[12]-ADC_ConvertedValue[15];
//            DataArrIB[FFTNUM] = ADC_ConvertedValue[13]-ADC_ConvertedValue[15];
//            DataArrIC[FFTNUM] = ADC_ConvertedValue[14]-ADC_ConvertedValue[15];	      //����
//           
//  			    DataArrAI[CHN_BATT]    += ADC_ConvertedValue[11]; //��ص�ѹ
//            DataArrAI[CHN_CHARGE]  += ADC_ConvertedValue[10]; //������ѹ D+
//					
//			      DataArrAI[CHN_AI4]     += ADC_ConvertedValue[6];  //�Զ�������
//            DataArrAI[CHN_AI3]     += ADC_ConvertedValue[7];  //Һλ  �Զ�������
//            DataArrAI[CHN_AI2]     += ADC_ConvertedValue[8];  //ˮ�¶�
//            DataArrAI[CHN_AI1]     += ADC_ConvertedValue[9];  //����ѹ��
//					  OilPressO3AI           += ADC_ConvertedValue[9];  //����ѹ��ŷ3                 
        }
    }
    if(ADSEQ == 1)//�е�
    {if(FFTNUM2 < 32)
     {
//			 DataArrMAINA[FFTNUM2] = ADC_ConvertedValue[0];
//      DataArrMAINB[FFTNUM2] = ADC_ConvertedValue[1];
//      DataArrMAINC[FFTNUM2] = ADC_ConvertedValue[2]; //�е��ѹ
     }
    }
    if(ADSEQ == 0 && FFTNUM < 32) FFTNUM++;
    if(ADSEQ == 1 && FFTNUM2 < 32)FFTNUM2++;
    
    if(FFTNUM >= 32 && FFTNUM2 >= 32)TIM_ITConfig(TIM2,TIM_IT_Update,DISABLE);//�ض�ʱ���ж�
}
/************************************************************************/
//������AD��غ���
//�����ѹ���ߵ�������Чֵ
//����1��int *TmpArr ����������ʼ��ַ
//����2��uint modulus ģֵ����������������ϵ��
//����3��char lx_ch ͨ����
//����ֵ����ѹ���ߵ�������Чֵ
/************************************************************************/
static M_ulong XIOAiCalUi (M_INT16U *TmpArr , float modulus, char lx_ch)
{  
    
    int i;
    long lng_cos = 0;
    long lng_sin = 0;
    float anlog_cos, anlog_sin;
    float buf1;
    float buf2; 
    float bufsum; 
    float sum;   //?????????????     
    unsigned long sumcheck = 0;
    anlog_cos = 0;
    anlog_sin = 0;
    sum = 0;
    lng_cos=0;
    lng_sin=0;
    for (i = 0; i < 32; i++) // COS value
    {
        lng_cos  += (long)*(TmpArr+i) * (long) cos_tab[i]; //???
        lng_sin  += (long)*(TmpArr+i) * (long) sin_tab[i]; //???

        if (TmpArr[i] >= 2048)
        {
            sumcheck += (M_ulong) TmpArr[i] - 2048;
        }
        else
        {
            sumcheck += 2048 - (M_ulong) TmpArr[i];
        }
    }

    
    anlog_cos = (float) lng_cos  / (float) modulus;
    anlog_sin = (float) lng_sin  / (float) modulus;
    
    if(lx_ch>=6 && lx_ch<=8)
    {
        PhaseR[lx_ch] = anlog_cos * CT;
        PhaseI[lx_ch] = anlog_sin * CT;  
    }
    else
    {      
        PhaseR[lx_ch] = anlog_cos;
        PhaseI[lx_ch] = anlog_sin;
    }
    
    buf1 = anlog_cos * anlog_cos;
    buf2 = anlog_sin * anlog_sin;
    bufsum=buf1+buf2;
    
    if(lx_ch<6 && bufsum<90000)
    {
        PhaseR[lx_ch]=0;
        PhaseI[lx_ch]=0;        
        return 0;
    }
    
    if(lx_ch>=6 && bufsum<200)
    {
        PhaseR[lx_ch]=0;
        PhaseI[lx_ch]=0;        
        return 0;
    }    
    sum = sqrtf (buf1+buf2);  //@@@@@@@@@@@@@@@@@@zc   __
    
    if(lx_ch>=6 && lx_ch<=8)
    {
        return (unsigned long) (sum* CT);
    }
    else
    {      
        return (unsigned long) (sum);
    }
}

//************************************************************************************
//�������ƣ�  XIOAiPushdataUint()
//����������  ���Ͷ��г���
//���������  uint *pdata ���Ͷ��е��׵�ַ
//���������
//************************************************************************************
static void XIOAiPushdataUint (M_INT16U *pdata)
{
    M_INT8S i;

    for (i = 0; i < (BUF_LEN - 1); i++)
    {
        *pdata = * (pdata + 1);
        pdata++;
    }
}

//************************************************************************************
//�������ƣ�  XIOAiAverageUint()
//����������  ȥ�����������Сֵ����ƽ��ֵ
//���������  uint *pdata ������׵�ַ   INT8S len Ҫ��ƽ������ĳ���
//���������  average
//************************************************************************************
static M_INT16U XIOAiAverageUint (M_INT16U *pdata, M_INT8S len)
{
    M_INT16U  low_buf;
    M_INT16U  hi_buf;
    M_ulong sum_buf;
    M_INT8S cnt_buf;
    M_INT16U  average_buf;
    M_INT16U  *p_buf;
    p_buf = pdata;
    low_buf = *p_buf;
    hi_buf  = *p_buf;

    for (cnt_buf = 0; cnt_buf < (len - 1); cnt_buf++) //find maxim and min number
    {
        p_buf++;

        if (low_buf > *p_buf)
        {
            low_buf = *p_buf;
        }

        if (hi_buf < *p_buf)
        {
            hi_buf = *p_buf;
        }
    }

    sum_buf = 0;
    p_buf = pdata;    //notice????

    for (cnt_buf = 0; cnt_buf < len; cnt_buf++) //sum
    {
        sum_buf += *p_buf++;
    }

    average_buf = ( (sum_buf - low_buf - hi_buf) / (len - 2) );
    return average_buf;
}
//************************************************************************************
//�������ƣ�  ai_pushdata_ulong()
//����������  �����ζ��г���
//���������  long *pdata �����ζ����׵�ַ
//���������
//************************************************************************************
static void XIOAiPushdataLong (long *pdata)

{
    M_INT8S i;

    for (i = 0; i < (BUF_LEN - 1); i++)
    {
        *pdata = * (pdata + 1);
        pdata++;
    }
}
//************************************************************************************
//�������ƣ�  ai_average_ulong()
//����������  ȥ�������������Сֵ����ƽ��ֵ
//���������  uint *pdata ������׵�ַ  INT8S len Ҫ��ƽ������ĳ���
//���������  ƽ�����
//************************************************************************************
static long XIOAiAverageLong (long *pdata, M_INT8S len)
{
    long  low_buf;
    long  hi_buf;
    long long  sum_buf;
    M_INT8S cnt_buf;
    long  average_buf;
    long  *p_buf;
    p_buf = pdata;
    low_buf = *p_buf;
    hi_buf = *p_buf;

    for (cnt_buf = 0; cnt_buf < (len - 1); cnt_buf++) //find maxim and min number
    {
        p_buf++;

        if (low_buf > *p_buf)
        {
            low_buf = *p_buf;
        }

        if (hi_buf < *p_buf)
        {
            hi_buf = *p_buf;
        }

        //pdata++;
    }

    sum_buf = 0;
    p_buf = pdata;    //notice????

    for (cnt_buf = 0; cnt_buf < len; cnt_buf++) //sum
    {
        sum_buf += *p_buf++;
    }

    average_buf = ( (sum_buf - low_buf - hi_buf) / (len - 2) );
    return average_buf;
}
//************************************************************************************
//�������ƣ�  XIOAiUiProcess()
//����������  �����ѹ���ߵ���ͨ����ģ�������˲�
//���������  uint *pdata  �˲����е�ַ int
//            *parrdata�������ݵ�ַ 
//            INT8S lx_ch ͨ���� 
//            uint modulus ��������ϵ��
//���������  �����˲������Чֵ
//************************************************************************************
M_INT16U XIOAiUiProcess (M_INT16U *pdata, M_INT16U *parrdata, M_INT08S lx_ch, float modulus)
{
    XIOAiPushdataUint (pdata);                               //��������-������һλ
    pdata = (pdata + (BUF_LEN - 1) );                       //��ָ���Ƶ����һλ
    *pdata = XIOAiCalUi (parrdata, modulus, lx_ch);          //�Ѽ�������ĵ�ѹ����ֵ�������һλ
    pdata = (pdata - (BUF_LEN - 1) );                       //��ָ���Ƶ���һλ
    return ( (XIOAiAverageUint (pdata, BUF_LEN) + 5) / 10);  //���������С��-��������-���ƽ��ֵ����
}

M_INT16U XIOAiIProcess (long *pdata, M_INT16U *parrdata, M_INT08S lx_ch, float modulus)
{
    XIOAiPushdataLong (pdata);                               //��������-������һλ
    pdata = (pdata + (BUF_LEN - 1) );                       //��ָ���Ƶ����һλ
    *pdata = XIOAiCalUi (parrdata, modulus, lx_ch);          //�Ѽ�������ĵ�ѹ����ֵ�������һλ
    pdata = (pdata - (BUF_LEN - 1) );                       //��ָ���Ƶ���һλ
    return ( (XIOAiAverageLong (pdata, BUF_LEN) + 5) / 10);  //���������С��-��������-���ƽ��ֵ����
}

//************************************************************************************
//�������ƣ�  XIOAiAdProcess()
//����������  ���������������ģ�������˲�
//���������  uint *pdata  �˲����е�ַ int
//            *parrdata�������ݵ�ַ 
//���������  �����˲������Чֵ
//************************************************************************************
M_INT16U XIOAiAdProcess (M_INT16U *pdata, M_INT16U data)
{
    XIOAiPushdataUint (pdata);                 //��������-������һλ
    pdata = (pdata + (BUF_LEN - 1) );         //��ָ���Ƶ����һλ
    *pdata = data;                            //�Ѽ��������ADֵ�������һλ
    pdata = (pdata - (BUF_LEN - 1) );         //��ָ���Ƶ���һλ
    return XIOAiAverageUint (pdata, BUF_LEN);  //���������С��-��������-���ƽ��ֵ����
}

//************************************************************************************
//�������ƣ�  XIOAiRpowProcess()
//����������  ������Ч����
//���������  long *pdata �˲����е�ַ
//            INT8S chn_v��ѹͨ��
//            INT8S chn_c����ͨ��
//���������  �����˲�����й�����
//************************************************************************************
static long XIOAiRpowProcess (long *pdata, M_INT08S chn_v, M_INT08S chn_c)
{
    XIOAiPushdataLong (pdata);                                                    //��������-������һλ
    pdata = (pdata + (BUF_LEN - 1) );                                            //��ָ���Ƶ����һλ
    *pdata = (PhaseR[chn_v] * PhaseR[chn_c] + PhaseI[chn_v] * PhaseI[chn_c])/1000;      //�Ѽ�������й���Чֵ�������һλ
    pdata = (pdata - (BUF_LEN - 1) );                                            //��ָ���Ƶ���һλ
    return ( (XIOAiAverageLong (pdata, BUF_LEN) )/10);                        //���������С��-��С1000��-���ƽ��ֵ����
}
//************************************************************************************
//�������ƣ�  XIOAiRpowProcess()
//����������  �����޹�����
//���������  long *pdata �˲����е�ַ?
//            INT8S chn_v��ѹͨ��
//            INT8S chn_c����ͨ��
//���������  �����˲�����޹�����
//************************************************************************************
static long XIOAiIpowProcess (long *pdata, M_INT08S chn_v, M_INT08S chn_c)
{
    XIOAiPushdataLong (pdata);                                                        //��������-������һλ
    pdata = (pdata + (BUF_LEN - 1) );                                                //��ָ���Ƶ����һλ
    *pdata = (PhaseR[chn_v] * PhaseI[chn_c]-PhaseI[chn_v] * PhaseR[chn_c])/1000;  //�Ѽ�������޹���Чֵ�������һλ
    pdata = (pdata - (BUF_LEN - 1) );                                                //��ָ���Ƶ���һλ
    return ( (XIOAiAverageLong (pdata, BUF_LEN) ) / 10);                            //���������С��-��С1000��-���ƽ��ֵ����
}
//************************************************************************************
//�������ƣ�  XIOAiPfCal()
//����������  ���㹦������
//���������  long data1 ��Ч��������
//            ulong data2���ڹ�������
//���������  ��������
//************************************************************************************
static M_INT16S XIOAiPfCal (long data1, M_INT32U data2)
{
    M_INT32U buf;
    M_INT16S  buf1;

    if (data1 == data2)
    {
        return 100;
    }

    if (data1 < 0)
    {
        buf = -data1;
    }
    else
    {
        buf = data1;
    }

    buf1 = buf * 100 / data2;

    if (data1 < 0)
    {
        buf1 = -buf1;
    }
    if(buf1>100)
    {
        buf1=100;
    }
    

    return buf1;
}

//************************************************************************************
//�������ƣ�  XIOAiPhseCal()
//����������  calculate phase sequence  //��������
//���������
//���������
//************************************************************************************
static M_INT16U XIOAiPhseCal (M_INT08S lx_cnt)
{
    float buf;
    buf = sqrtf (PhaseI[lx_cnt] * PhaseI[lx_cnt] + PhaseR[lx_cnt] * PhaseR[lx_cnt]);
    buf = acosf (PhaseR[lx_cnt] / buf);

    if (PhaseI[lx_cnt] >= 0)
    {
        buf = buf / _M_PI * 180;
    }
    else
    {
        buf = 360 - buf / _M_PI * 180;
    }

    return buf;
}
//************************************************************************************
//�������ƣ�  XIOAiPhseCal1()
//����������  calculate phase sequence   //��������
//���������
//���������
//************************************************************************************
static M_INT16U XIOAiPhseCal1 (M_INT16U angle1, M_INT16U angle2)
{
    if (angle2 >= angle1)
    {
        return (angle2 - angle1);
    }
    else
    {
        return (360 + angle2 - angle1);
    }
}





//************************************************************************************
//�������ƣ�  XIOAiPsCal()
//����������  calculate apparentpower          //����[���]����
//���������    real power , image power
//���������    apparentpower
//************************************************************************************
static M_INT32U XIOAiPsCal (long buf1, long buf2)
{
    if (buf2 == 0)
    {
        return buf1;
    }
    else
    {
        return (sqrtf ((float)buf1 * (float)buf1 + (float)buf2 * (float)buf2) );

    }
}
//************************************************************************************
//�������ƣ�  XIOAiViProcess()
//����������  �������ѹ����ߵ�ѹ
//���������  �˲����е�ַ
//            ���ѹͨ����
//            ���ѹͨ����
//���������  ���ѹ֮����ߵ�ѹֵ
//************************************************************************************
static M_INT16U XIOAiViProcess (M_INT16U *pdata, M_INT08S lx_cnt1, M_INT08S lx_cnt2)
{
    float buf1;
    float buf2;
    uint tempdata;
    XIOAiPushdataUint (pdata);
    buf1 = PhaseR[lx_cnt1] - PhaseR[lx_cnt2];
    buf2 = PhaseI[lx_cnt1] - PhaseI[lx_cnt2];
    pdata = (pdata + (BUF_LEN - 1) );
    tempdata = sqrtf (buf1 * buf1 + buf2 * buf2);

    if (tempdata < 10)
    {
        return 0;
    }

    *pdata = tempdata;
    pdata = (pdata - (BUF_LEN - 1) );
    return ( (XIOAiAverageUint (pdata, BUF_LEN) + 5) / 10);
}
//************************************************************************************
//�������ƣ�  XIOAiProcess()
//����������  ģ��������
//���������  
//���������  
//************************************************************************************
void XIO_ClearLLDis()
{
   //���ߵ�ѹС��10v��ǿ����ʾΪ0
   if(VOLTAGEAB1 <=10)VOLTAGEAB1=0;
   if(VOLTAGEBC1 <=10)VOLTAGEBC1=0;
   if(VOLTAGECA1 <=10)VOLTAGECA1=0;
   if(VOLTAGEAB2 <=10)VOLTAGEAB2=0;
   if(VOLTAGEBC2 <=10)VOLTAGEBC2=0;
   if(VOLTAGECA2 <=10)VOLTAGECA2=0;
}
int TESTDATA[10];
void XIOAiProcess(void)
{	
    M_INT8U i;
	//���෢��-���ѹ    //@@@@@@@@@@ZC��̭
//    VOLTAGEA1 = XIOAiUiProcess (UA1BUFF, DataArrGENA, 0,(M_INT32U)modulusV1 * (M_INT32U)RECAL_VOLT_GEN_A/10000) * GENPT;        
//    VOLTAGEB1 = XIOAiUiProcess (UB1BUFF, DataArrGENB, 1,(M_INT32U)modulusV1 * (M_INT32U)RECAL_VOLT_GEN_B/10000) * GENPT;
//    VOLTAGEC1 = XIOAiUiProcess (UC1BUFF, DataArrGENC, 2,(M_INT32U)modulusV1 * (M_INT32U)RECAL_VOLT_GEN_C/10000) * GENPT;

//    //����-�ߵ�ѹ
//    VOLTAGEAB1 = XIOAiViProcess (UAB1BUFF, 0, 1) * GENPT;
//    VOLTAGEBC1 = XIOAiViProcess (UBC1BUFF, 1, 2) * GENPT;	
//    VOLTAGECA1 = XIOAiViProcess (UCA1BUFF, 0, 2) * GENPT;

    if(COMMON_MODEL==MODEL420)                             //�����е�-���ѹ
    {    
	   VOLTAGEA2 = XIOAiUiProcess (UA2BUFF, DataArrMAINA, 3,(M_INT32U)modulusV2 * (M_INT32U)RECAL_VOLT_MAINS_A/10000) * MAINPT;
     VOLTAGEB2 = XIOAiUiProcess (UB2BUFF, DataArrMAINB, 4,(M_INT32U)modulusV2 * (M_INT32U)RECAL_VOLT_MAINS_B/10000) * MAINPT;
     VOLTAGEC2 = XIOAiUiProcess (UC2BUFF, DataArrMAINC, 5,(M_INT32U)modulusV2 * (M_INT32U)RECAL_VOLT_MAINS_C/10000) * MAINPT;
     VOLTAGEAB2 = XIOAiViProcess (UAB2BUFF, 3, 4) * MAINPT;//�е�-�ߵ�ѹ
     VOLTAGEBC2 = XIOAiViProcess (UBC2BUFF, 4, 5) * MAINPT;
     VOLTAGECA2 = XIOAiViProcess (UCA2BUFF, 3, 5) * MAINPT;
    }
	 else
	  {VOLTAGEA2 =0;
     VOLTAGEB2 =0;
     VOLTAGEC2 =0;
     VOLTAGEAB2=0; 
     VOLTAGEBC2=0; 
     VOLTAGECA2=0;     
	  }

	  XIO_ClearLLDis();     //���ߵ�ѹС��10v��ǿ����ʾΪ0
    CT = (float)GEN_CT/5; //�������
	//���෢��-����
//	  CURRENTA = XIOAiIProcess (IABUFF, DataArrIA, 6, (float)modulusIA*(float)RECAL_CURRENT_A/(float)10000);
//    CURRENTB = XIOAiIProcess (IBBUFF, DataArrIB, 7, (float)modulusIB*(float)RECAL_CURRENT_B/(float)10000);
//    CURRENTC = XIOAiIProcess (ICBUFF, DataArrIC, 8, (float)modulusIC*(float)RECAL_CURRENT_C/(float)10000);
   
   //A���й�����
    KWA100 = XIOAiRpowProcess (r_powa_buf, 0, 6);
    //A���޹�����
    KVARA100 = XIOAiIpowProcess (i_powa_buf, 0, 6);
    KWA = KWA100 / 10;
    KVARA = KVARA100 / 10;
    
    //B���й�����
    KWB100 = XIOAiRpowProcess (r_powb_buf, 1, 7);
    //B���޹�����
    KVARB100 = XIOAiIpowProcess (i_powb_buf, 1, 7);
    KWB = KWB100 / 10;
    KVARB = KVARB100 / 10;
    
    //C���й�����
    KWC100 = XIOAiRpowProcess (r_powc_buf, 2, 8);
    //C���޹�����
    KVARC100 = XIOAiIpowProcess (i_powc_buf, 2, 8);
    KWC = KWC100 / 10;
    KVARC = KVARC100 / 10;
    
    //A�����ڹ���
    KVAA100 = XIOAiPsCal (KWA100, KVARA100);
    //B�����ڹ���
    KVAB100 = XIOAiPsCal (KWB100, KVARB100);
    //C�����ڹ���
    KVAC100 = XIOAiPsCal (KWC100, KVARC100);
    
    KVAA=KVAA100/10;
    KVAB=KVAB100/10;
    KVAC=KVAC100/10;
   
    //�ܹ�����
    KWALL100 = KWA100 + KWB100 + KWC100;
	if(GEN_VOLT_TYPE == 2) KWALL = KWC;  //<<<<<<<<<<<<<<<<<<<<<�������
	else KWALL = KWA + KWB + KWC;
    
    //���޹�����
    
    if(GEN_VOLT_TYPE == 2) KVARALL = KVARC;	//<<<<<<<<<<<<<<<<<<<
	else KVARALL = KVARA + KVARB + KVARC;	
    //�����ڹ���
    
    if(GEN_VOLT_TYPE == 2) KVAALL = KVAC;	//<<<<<<<<<<<<<<<<<
	else KVAALL = KVAA + KVAB + KVAC;
   
    //���๦������
    PFA = XIOAiPfCal (KWA100, KVAA100);
    PFB = XIOAiPfCal (KWB100, KVAB100);
    PFC = XIOAiPfCal (KWC100, KVAC100);
    
    //��������	
    if(GEN_VOLT_TYPE == 2) PhaseCOS = XIOAiPfCal (KWC100, KVAC100);  //
    else  PhaseCOS = XIOAiPfCal (KWA100 + KWB100 + KWC100, KVAA100 + KVAB100 + KVAC100);	
    
    
	  if(KWALL==KVAALL)KVARALL = 0;//����ʾ ���й��������ڻ��߹�������Ϊ1 �޹�����ǿ��Ϊ 0

      for(i=0;i<4;i++)
      {
        AI_ADVALUE[i]=XIOAiAdProcess(&AIBUFF[i][0],DataArrAI[i]/32)*ADJUST[i];
        if (AI_ADVALUE[i] > 4050)
        {
            AI_OHM[i] = -1;
        }
        else
        {              //ԭ����30000Ϊ����У��100ŷ���ϵĵ���ĳ�3000
            AI_OHM[i] = (3000* AI_ADVALUE[i]) /  (4095 - AI_ADVALUE[i]);
        } 
        DataArrAI[i]=0;  
      }

     if(AI_OHM[0]>0)	  //ѹ��
      {      
        VALUER0=SensorBreakLineV[0]=(M_INT32U)AI_OHM[0] * RECAL_OP/10000;
      }
     else
      {
        VALUER0=SensorBreakLineV[0]=-32768;
      }
     if(AI_OHM[1]>0)	 //�¶�
      {      
        VALUER1=SensorBreakLineV[1]=(M_INT32U)AI_OHM[1] * RECAL_TEMP/10000;
      }
     else
      {
        VALUER1=SensorBreakLineV[1]=-32768;                
      }
     if(AI_OHM[2]>0)	//���������1 Ĭ��Һλ
      {      
        VALUER2=SensorBreakLineV[2]=(M_INT32U)AI_OHM[2] * RECAL_LEVEL/10000;
      }
     else
      {
        VALUER2=SensorBreakLineV[2]=-32768;
      }        
 	  if(AI_OHM[3]>0)  //���������2 Ĭ�Ͽ���������3
      {      
        VALUER3=SensorBreakLineV[3]=(M_INT32U)AI_OHM[3]* RECAL_CustomAnalog/10000;
      }
     else
      {
        VALUER3=SensorBreakLineV[3]=-32768;
      } 
	   
    //���μ����ص�ѹ  
    AI_ADVALUE[CHN_BATT]=XIOAiAdProcess(&AIBUFF[CHN_BATT][0],DataArrAI[CHN_BATT]/32)*ADJUST[CHN_BATT];
    //���μ��������ѹ
    AI_ADVALUE[CHN_CHARGE]=XIOAiAdProcess(&AIBUFF[CHN_CHARGE][0],DataArrAI[CHN_CHARGE]/32)*ADJUST[CHN_CHARGE];

    DataArrAI[CHN_BATT]=0;
    DataArrAI[CHN_CHARGE]=0; 
    
    //���ռ����ص�ѹ 
    PowerVoltageReal =(M_INT16U) ((M_ulong)XIOAiAdProcess (BATTBUFF, AI_ADVALUE[CHN_BATT])*739/4096); 
    PowerVoltage=(M_INT32U)PowerVoltageReal*RECAL_BATT/10000;
    if(PowerVoltage>10)
     {
       PowerVoltage +=6;
     }
    
    //���ռ��������ѹ 
    ChargerVoltageReal=(M_INT16U) ((M_ulong)XIOAiAdProcess (CHARGEBUFF, (M_ulong)AI_ADVALUE[CHN_CHARGE])*739/4096);  
    ChargerVoltage=(M_INT32U)ChargerVoltageReal*RECAL_CHARGER/10000;
    if(ChargerVoltage>10)
      {
        ChargerVoltage+=6;
      }
}

/********************************************************
//
//��8������Զ����������ݰ��յ���ֵ��С�����˳������---ð������
//
********************************************************/
void XIOTransCustomCurvesort(M_INT16S *CustomAarry)
{
  M_INT08U i;
  M_INT08U j;
  M_INT08U t;	
  M_INT16S CustomBuf1;
  M_INT16S CustomBuf2;	
//  M_INT16S CUSTOM_BUF[8][2];	
	
  for(i = 0;i < 7;i++)   //ѭ������7��
  {
     t = 7-i;	  
    for(j = 0;j < t;j++)
    {
	  if(*(CustomAarry+j*2) > *(CustomAarry+j*2+2))
	  {
	      CustomBuf1 = *(CustomAarry+j*2+2);
		  CustomBuf2 = *(CustomAarry+j*2+2+1);
		  *(CustomAarry+j*2+2) = *(CustomAarry+j*2);
		  *(CustomAarry+j*2+2+1) = *(CustomAarry+j*2+1);
		  *(CustomAarry+j*2) = CustomBuf1;
		  *(CustomAarry+j*2+1) = CustomBuf2;
	  }
	}	  
  }
}
/********************************************************
//
//���Զ�������8����תΪ16��
//
********************************************************/
void XIOTransCustomCurve(M_INT16S *CustomAarry) 
{
  M_INT08U ii;
  M_INT16S CustomBuf;
  XIOTransCustomCurvesort(CustomAarry);   //ð������	
  OilTempLevel_CUSTOM_BUF[0][0]=0; OilTempLevel_CUSTOM_BUF[0][1]=*(CustomAarry+1);
  for(ii=0;ii<8;ii++) 
  {
    OilTempLevel_CUSTOM_BUF[ii+1][0]=*(CustomAarry+ii*2);
    OilTempLevel_CUSTOM_BUF[ii+1][1]=*(CustomAarry+ii*2+1);
  }
  CustomBuf=(11606-*(CustomAarry+14))/7;
  for(ii=0;ii<7;ii++)
  {
    OilTempLevel_CUSTOM_BUF[ii+9][0]=*(CustomAarry+14)+CustomBuf*(ii+1); 
    OilTempLevel_CUSTOM_BUF[ii+9][1]=*(CustomAarry+15); 
  }
}

//--------------------------------------------------------------
//���㴫�������߲����ؽ��
//int CurveType ������
//float InputValue ģ��������ֵ
//int ADVALUE  ADת��ֵ
//char CurveMode��������
//--------------------------------------------------------------
M_INT32S XIOCalcOilPressCurve (int CurveType, float InputValue,int ADVALUE , char CurveMode)
{
    const int *CurveAddr;
    const int *NowAddr;
    char i = 0;
    float X1 = 0;
    float Y1 = 0;
    float X = 0;
    float Y = 0;
    float Err = 0;
    float OilPO3Value;
	
    switch(ADVALUE)
	  {
	    case 0:
				for(i=0;i<8;i++)
        {
          OIL_CURVE_CUSTOM[i][0]=FLASHDATABASE[sPc_OP_R1+i].Sbyte;
          OIL_CURVE_CUSTOM[i][1]=FLASHDATABASE[sPc_OP_V1+i].Sbyte;
        }
			break;
		  case 3:
			  for(i=0;i<8;i++)
        {
          OIL_CURVE_CUSTOM[i][0]=FLASHDATABASE[sPc_LV_R1+i].Sbyte;
          OIL_CURVE_CUSTOM[i][1]=FLASHDATABASE[sPc_LV_V1+i].Sbyte;
         }
		  break;
		  case 4: 
			  for(i=0;i<8;i++)
        {
          OIL_CURVE_CUSTOM[i][0]=FLASHDATABASE[sPc_REUSE_R1+i].Sbyte;
          OIL_CURVE_CUSTOM[i][1]=FLASHDATABASE[sPc_REUSE_V1+i].Sbyte;
         }
			break;
			
		  default:break;
	  }
		
    if (InputValue == -1)
    {
        return -32768;
    }
    
    InputValue=InputValue/10;
   
    if (CurveMode == 0)		  //��ѹ
    {
     switch (CurveType)
     {
        case 0:
            //δʹ��
            return -32768;
            //break;
        case 1:
            XIOTransCustomCurve(&OIL_CURVE_CUSTOM[0][0]);  //���Զ�������8����תΪ16��
            CurveAddr = &OilTempLevel_CUSTOM_BUF[0][0];    //�Զ�������
            break;
        case 2:
            
            CurveAddr = &OIL_CURVE_VDO_10bar[0][0];
            break;
        case 3:
            CurveAddr = &OIL_CURVE_SGH_10bar[0][0]; 
            
            break;
        case 4:
            CurveAddr = &OIL_CURVE_SGD_10bar[0][0];
            break;
        case 5:
            CurveAddr = &OIL_CURVE_Curtis_10bar[0][0];
            break;
        case 6:
            CurveAddr = &OIL_CURVE_Datcon_10bar[0][0];
            break;
        case 7:
            CurveAddr = &OIL_CURVE_VOLVO_EC_10bar[0][0];
            break;  
        case 8:
            CurveAddr = &OIL_CURVE_SGX_10bar[0][0];
            break; 
        case 9:return -32768;
//				    break;//����
        case 10:
          OilPressO3Real =(M_INT32S)((long)XIOAiAdProcess (OilPressO3, OilPressO3AI/32)*510/4096); 
          OilPressO3AI=0;
          if((OilPressO3Real>45)&&(OilPressO3Real<480)) 
          {
            OilPO3Value=(float)OilPressO3Real-0.1*ADJST_O3;
            if(OilPO3Value>=0)OilPO3Value=(OilPO3Value/(0.8*ADJST_O3)*10000+5)/10;
            else              OilPO3Value=0;
           return (M_INT32S)(OilPO3Value);
          } 
          else return -32768;  
         //break;
         default:return -32768; //break;   				
      }
    }
		
		if(InputValue<*CurveAddr || InputValue>*(CurveAddr+30))
    {
        return -32768;
    }
    
    for (i = 2; i < 32; i += 2)
    {
     if (InputValue <= * (CurveAddr + i) )
     {
       NowAddr = CurveAddr + i;
       X1 = * (NowAddr);
       Y1 = * (NowAddr + 1);
       X = * (NowAddr - 2);
       Y = * (NowAddr - 1);
       Err = InputValue - * (NowAddr - 2);
       return (Y1 - Y) / (X1 - X) * Err + * (NowAddr - 1);
      }
    }
    return -32768;
	}

//--------------------------------------------------------------
//���㴫�������߲����ؽ��
//int CurveType ������
//float InputValue ģ��������ֵ
//int ADVALUE  ADת��ֵ
//char CurveMode��������
//--------------------------------------------------------------
M_INT32S XIOCalcTempCurve (int CurveType, float InputValue,int ADVALUE , char CurveMode)
{
    const int *CurveAddr;
    const int *NowAddr;
    char i = 0;
    float X1 = 0;
    float Y1 = 0;
    float X = 0;
    float Y = 0;
    float Err = 0;
    
    switch(ADVALUE)
	  {
	    case 0:
				for(i=0;i<8;i++)
        {
          TEMP_CURVE_CUSTOM[i][0]=FLASHDATABASE[sPc_TEMP_R1+i].Sbyte;
          TEMP_CURVE_CUSTOM[i][1]=FLASHDATABASE[sPc_TEMP_V1+i].Sbyte;
        }
			break;
		  case 3:
			  for(i=0;i<8;i++)
        {
          TEMP_CURVE_CUSTOM[i][0]=FLASHDATABASE[sPc_LV_R1+i].Sbyte;
          TEMP_CURVE_CUSTOM[i][1]=FLASHDATABASE[sPc_LV_V1+i].Sbyte;
         }
		  break;
		  case 4: 
			  for(i=0;i<8;i++)
        {
          TEMP_CURVE_CUSTOM[i][0]=FLASHDATABASE[sPc_REUSE_R1+i].Sbyte;
          TEMP_CURVE_CUSTOM[i][1]=FLASHDATABASE[sPc_REUSE_V1+i].Sbyte;
         }
			break;
			
		  default:break;
	  }
		
    if (InputValue == -1)
    {
        return -32768;
    }
    
    InputValue=InputValue/10;
   
    if (CurveMode == 1)		  //ˮ��
    {
        switch (CurveType)
        {
        case 0:
            return -32768;
//            break;
//        break;
        
        case 1:
         //  CurveAddr=&TEMP_CURVE_CUSTOM[0][0];//�Զ�������
            XIOTransCustomCurve(&TEMP_CURVE_CUSTOM[0][0]);  //���Զ�������8����תΪ16��
            CurveAddr = &OilTempLevel_CUSTOM_BUF[0][0];    //�Զ�������
            break;                
        case 2:
            CurveAddr = &TEMP_CURVE_VDO_163C[0][0];
            break;
        case 3:
            CurveAddr = &TEMP_CURVE_SGH_140C[0][0];
            break;
        case 4:
            CurveAddr = &TEMP_CURVE_SGD_180C[0][0];
            break;
        case 5:
            CurveAddr = &TEMP_CURVE_Curtis_140C[0][0];
            break;
        case 6:
            CurveAddr = &TEMP_CURVE_Datcon_140C[0][0];
            break;
        case 7:
            CurveAddr = &TEMP_CURVE_VOLVO_EC_120C[0][0];
            break;
        case 8:
            CurveAddr = &TEMP_CURVE_SGX_140C[0][0];
            break;
        case 9:
            CurveAddr=&TEMP_CURVE_PT100[0][0];
            break;    
        case 10:
            CurveAddr=&TEMP_CURVE_O3[0][0];
            break;    
        default:return -32768;//break;    
            
        }
    }
		
		if(InputValue<*CurveAddr || InputValue>*(CurveAddr+30))
    {
        return -32768;
    }
    
    for (i = 2; i < 32; i += 2)
    {
     if (InputValue <= * (CurveAddr + i) )
     {
       NowAddr = CurveAddr + i;
       X1 = * (NowAddr);
       Y1 = * (NowAddr + 1);
       X = * (NowAddr - 2);
       Y = * (NowAddr - 1);
       Err = InputValue - * (NowAddr - 2);
       return (Y1 - Y) / (X1 - X) * Err + * (NowAddr - 1);
      }
    }
    return -32768;
	}
/********************************************************
//���㴫�������߲����ؽ��
//int CurveType ������
//float InputValue ģ��������ֵ
//int ADVALUE  ADת��ֵ
//char CurveMode��������
 ********************************************************/
M_INT32S XIOCalcLevelCurve (int CurveType, float InputValue,int ADVALUE , char CurveMode)
{
    const int *CurveAddr;
    const int *NowAddr;
    char i = 0;
    float X1 = 0;
    float Y1 = 0;
    float X = 0;
    float Y = 0;
    float Err = 0;
	  switch(ADVALUE)
	  {
	    case 0:
		  case 3:
			  for(i=0;i<8;i++)
        {
          LEVEL_CURVE_CUSTOM[i][0]=FLASHDATABASE[sPc_LV_R1+i].Sbyte;
          LEVEL_CURVE_CUSTOM[i][1]=FLASHDATABASE[sPc_LV_V1+i].Sbyte;
         }
		  break;
		  case 4: 
			  for(i=0;i<8;i++)
        {
          LEVEL_CURVE_CUSTOM[i][0]=FLASHDATABASE[sPc_REUSE_R1+i].Sbyte;
          LEVEL_CURVE_CUSTOM[i][1]=FLASHDATABASE[sPc_REUSE_V1+i].Sbyte;
         }
			break;
			
		  default:break;
	  }
	
    
    if (InputValue == -1)
    {
        return -32768;
    }
    
    InputValue=InputValue/10;
   
    if (CurveMode == 2)		 //Ȼ��λ
    {
      switch (CurveType)
      {
       case 0:
            return -32768;
            break;
        case 1:							
           // CurveAddr = &LEVEL_CURVE_CUSTOM[0][0];//�Զ�������
            XIOTransCustomCurve(&LEVEL_CURVE_CUSTOM[0][0]);  //���Զ�������8����תΪ16��
            CurveAddr = &OilTempLevel_CUSTOM_BUF[0][0];    //�Զ�������
            break;            
        case 2:
            CurveAddr = &FUEL_CURVE_SGH[0][0];
            break;
        case 3:
            CurveAddr = &FUEL_CURVE_SGD[0][0];
            break;  
        case 4:
            CurveAddr = &FUEL_CURVE_YW[0][0];
            break;		
        default:
            return -32768;    
      }
    }
    
    if(InputValue<*CurveAddr || InputValue>*(CurveAddr+30))
    {
        return -32768;
    }
    
    for (i = 2; i < 32; i += 2)
    {
        if (InputValue <= * (CurveAddr + i) )
        {
            NowAddr = CurveAddr + i;
            X1 = * (NowAddr);
            Y1 = * (NowAddr + 1);
            X = * (NowAddr - 2);
            Y = * (NowAddr - 1);
            Err = InputValue - * (NowAddr - 2);
            return (Y1 - Y) / (X1 - X) * Err + * (NowAddr - 1);
        }
    }
    return -32768;
}

/********************************************************
//���㴫�������߲����ؽ��
//int CurveType ������
//float InputValue ģ��������ֵ
//int ReuseType �������� 0--3
//char CustomType�Զ�������ѡ�� 
 ********************************************************/
M_INT32S XIOCalcREUSECurve(int CurveType, float InputValue,char CustomType,int ReuseType)
{ M_INT32S SensorVal=0;
	if(ReuseType==0)//���������빦��
	{
	   return -32768;
	}
	if((CustomType==3)&&(CurveType==1))//����������ΪҺλѡ����ʱ�˳�
	{
	   return -32768;
	}
	
	if(ReuseType==1)     //��ѹ����
	{
		SensorVal=XIOCalcOilPressCurve(CurveType,InputValue,CustomType,0);
	}
	else if(ReuseType==2)//ˮ�¼���
	{
		SensorVal=XIOCalcTempCurve(CurveType,InputValue,CustomType,1);
	}
	else if(ReuseType==3)//ȼ�ͼ���
	{ 
		SensorVal=XIOCalcLevelCurve(CurveType,InputValue,CustomType,2);
	}
	else
	{
		 return -32768;
	}
	return SensorVal;
}
//----------------------------------------------------------------
//����ģ�������룬�������Ӧֵ
//
//----------------------------------------------------------------
void XIOCalcSensor(void)
{
     if( GES_GENS_TYPE == 0 )  //�ǵ������
	 {
//		 OILPRESSURE   =  XIOCalcOilPressCurve(DES_OP_SENSOR,   SensorBreakLineV[0],0,0);    //��ѹ����    //@@@@@@
         WATERTEMP     =  XIOCalcTempCurve(DES_TEMP_SENSOR,     SensorBreakLineV[1],0,1);    //ˮ�¼���
	 }
	 FUEL          =  XIOCalcLevelCurve(DES_LV_SENSOR,      SensorBreakLineV[2],0,2);    //ȼ�ͼ���
   //FUEL          =  XIOCalcREUSECurve(REUSE_INPUT1_SENSOR,SensorBreakLineV[2],3,REUSE_INPUTFUNC1_TYPE);  //����1�¶�ѹ��Һλ ������Һλ    
   //REUSEOILTEMPL =  XIOCalcREUSECurve(REUSE_INPUT2_SENSOR,SensorBreakLineV[3],4,REUSE_INPUTFUNC2_TYPE);  //����2�¶�ѹ��Һλ       
}

//----------------------------------------------------------------
//               void XIOAiCheck(void)
//
//----------------------------------------------------------------
void XIOAiCheck(void)
{
  unsigned int time=625;
  if (FFTNUM >=32 && FFTNUM2 == 0)
  {
   ADSEQ = 1;           //�ɼ��е�
   if (BUS_FREQ > 200)  //200�ܲ�������СƵ��
    {
     time = (unsigned int)((((float)3125000 / (float)(BUS_FREQ))+5)/10);
	   Delay_CHtim2Period(time);
    }                                
    else
    {
     Delay_CHtim2Period(625);
    }
   }
   if(FFTNUM >= 32 && FFTNUM2 >= 32)
   {
     XIOAiProcess();
     XIOCalcSensor();
     FFTNUM = 0;
     FFTNUM2 = 0;
	   if (GEN_FREQ > 200) //200�ܲ�������СƵ��
     {
		  time = (unsigned int)((((float)3125000 / (float)(GEN_FREQ))+5)/10);
		  Delay_CHtim2Period(time);
     }
     else
     {
      Delay_CHtim2Period(625);
     }
     ADSEQ = 0;   //�ɼ����� 
	   TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
   }
}

//*********************************************************************
//�������ƣ�  void XIORelayProcess(void)
//����������  �������
//���������  
//���������
//*********************************************************************
void XIORelayProcess(void)
{ 
  if(!F_AUX_OUTPUT1) RELAY_AUX1_ON();
  else               RELAY_AUX1_OFF();
  
  if(!F_AUX_OUTPUT2) RELAY_AUX2_ON();
  else               RELAY_AUX2_OFF();
  
  if(!F_AUX_OUTPUT3) RELAY_AUX3_ON();
  else               RELAY_AUX3_OFF();
  
  if(!F_AUX_OUTPUT4) RELAY_AUX4_ON();
  else               RELAY_AUX4_OFF();
	
  if(!F_AUX_OUTPUT5) RELAY_AUX5_ON();
  else               RELAY_AUX5_OFF();
	
  if(!F_AUX_OUTPUT6) RELAY_AUX6_ON();
  else               RELAY_AUX6_OFF();
  
  if(!F_OUTPUT_CRANK)RELAY_CRANK_ON();
  else               RELAY_CRANK_OFF();
  
  if(!F_OUTPUT_DCHAR)RELAY_DCHARGE_ON();
  else               RELAY_DCHARGE_OFF();  //D+
}
//*********************************************************************
//�������ƣ�  void XIOInputProcess(void)
//����������  ����ڴ���
//���������  
//���������
//*********************************************************************
void XIOInputProcess(void)
{
  if(KEYSW_IN1) F_AUX_INPUT1 = 1;
  else          F_AUX_INPUT1 = 0;
  
  if(KEYSW_IN2) F_AUX_INPUT2 = 1;
  else          F_AUX_INPUT2 = 0;

  if((VALUER3<100)&&(VALUER3>0)){F_AUX_INPUT3 = 1;}
  else           {F_AUX_INPUT3 = 0;}
}

//*********************************************************************
//�������ƣ�  void XIOLedProcess(void)
//����������  LED��������
//���������  
//���������
//*********************************************************************
void XIOLedProcess(void)
{
  if(F_SHOW_LED_STOP)  LED_STOP_ON();
  else                 LED_STOP_OFF();
  
  if(F_SHOW_LED_MANUAL)LED_MAN_ON();
  else                 LED_MAN_OFF();
  
  if(F_SHOW_LED_AUTO)  LED_AUTO_ON();
  else                 LED_AUTO_OFF();
  
//  if(F_SHOW_LED_TEST) LED_TEST=0;
//  else LED_TEST=1;
 
	
  if(F_SHOW_LED_GENSET) LED_GENSET=1;
  else                  LED_GENSET=0;
     
  if(F_SHOW_LED_MAINS)  LED_MAINS=1;
  else                  LED_MAINS=0;
    
  if(F_SHOW_LED_GCB)    LED_GCB=1;
  else                  LED_GCB=0;
  
  if(F_SHOW_LED_MCB)    LED_MCB=1;
  else                  LED_MCB=0;    
  
  if(F_SHOW_LED_ALARM)  LED_ALARM_ON();
  else                  LED_ALARM_OFF();
    
 
  if(COMMON_MODEL==MODEL420)
  {
    //  PTS_PTS2=LED_MCB;
    //  PTT_PTT1=LED_GENSET;
    //  PTS_PTS6=LED_MAINS;
    //  PORTK_PK0=LED_GCB;
  }
  
  if(COMMON_MODEL==MODEL410)
  {
   /*
	if(LED_GENSET){ LED_MCB_ON(); }
	else          { LED_MCB_OFF();}

	if(LED_GCB)   { LED_GCB_ON(); }
	else          { LED_GCB_OFF();}
   */
  }

}
/* ******************************************************************** */
/*                              XIODIDO()                               */
/* ******************************************************************** */
void CALAI_AUX_RelayOUT_Ctl()
 {
    if(OUTPUT_TEMP[COMMON_OUTPUTFUNC1])    {F_AUX_OUTPUT1=1;}
    else                                   {F_AUX_OUTPUT1=0;}
    
    if(OUTPUT_TEMP[COMMON_OUTPUTFUNC2])    {F_AUX_OUTPUT2=1;}
    else                                   {F_AUX_OUTPUT2=0;}
    
    if(OUTPUT_TEMP[COMMON_OUTPUTFUNC3])    {F_AUX_OUTPUT3=1;}    
    else                                   {F_AUX_OUTPUT3=0;}
    
    if(OUTPUT_TEMP[COMMON_OUTPUTFUNC4])    {F_AUX_OUTPUT4=1;}
    else                                   {F_AUX_OUTPUT4=0;} 
	
    if(OUTPUT_TEMP[COMMON_OUTPUTFUNC5])    {F_AUX_OUTPUT5=1;}    
    else                                   {F_AUX_OUTPUT5=0;}
    
    if(OUTPUT_TEMP[COMMON_OUTPUTFUNC6])    {F_AUX_OUTPUT6=1;}
    else                                   {F_AUX_OUTPUT6=0;} 
		
 }
void CALAI_AUX_INPUT_CTL(void)
{
	if(COMMON_INPUTFUNC1_VALID==0) //????
    {
        if(F_AUX_INPUT1==1)
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC1_DELAY]=1;
        }
        else
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC1_DELAY]=0;
            //INPUT_TEMP[COMMON_INPUTFUNC1]=0;
            TimerTrig[TMR_COMMON_INPUTFUNC1_DELAY]=0;
        }
    }
    else
    {
        if(F_AUX_INPUT1==0)
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC1_DELAY]=1;
        }
        else
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC1_DELAY]=0;
            //INPUT_TEMP[COMMON_INPUTFUNC1]=0;
            TimerTrig[TMR_COMMON_INPUTFUNC1_DELAY]=0;
        }    
    }
    
    if(TimerTrig[TMR_COMMON_INPUTFUNC1_DELAY])
    {
         INPUT_TEMP[COMMON_INPUTFUNC1]|=1;    
    }
          
    if(COMMON_INPUTFUNC2_VALID==0)
    {
        if(F_AUX_INPUT2)
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC2_DELAY]=1;
        }
        else
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC2_DELAY]=0;
            //INPUT_TEMP[COMMON_INPUTFUNC2]=0;
            TimerTrig[TMR_COMMON_INPUTFUNC2_DELAY]=0; 
        }
    }
    else
    {
        if(F_AUX_INPUT2==0)
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC2_DELAY]=1;
        }
        else
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC2_DELAY]=0;
            //INPUT_TEMP[COMMON_INPUTFUNC2]=0;
            TimerTrig[TMR_COMMON_INPUTFUNC2_DELAY]=0; 
        }    
    }
    
    if(TimerTrig[TMR_COMMON_INPUTFUNC2_DELAY])
    {
         
         INPUT_TEMP[COMMON_INPUTFUNC2]|=1;    
    } 
    
    if(COMMON_INPUTFUNC3_VALID==0)
    {
        if(F_AUX_INPUT3)
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC3_DELAY]=1;
        }
        else
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC3_DELAY]=0;
            //INPUT_TEMP[COMMON_INPUTFUNC3]=0;
            TimerTrig[TMR_COMMON_INPUTFUNC3_DELAY]=0;
        }
    }
    else
    {
        if(F_AUX_INPUT3==0)
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC3_DELAY]=1;
        }
        else
        {
            TimerEnArr[TMR_COMMON_INPUTFUNC3_DELAY]=0;
            //INPUT_TEMP[COMMON_INPUTFUNC3]=0;
            TimerTrig[TMR_COMMON_INPUTFUNC3_DELAY]=0;
        }    
    }
    
    if(TimerTrig[TMR_COMMON_INPUTFUNC3_DELAY])
    {
          
         INPUT_TEMP[COMMON_INPUTFUNC3]|=1;    
    }           
   
}

void XIOCustomDIDO (void)
{
    M_INT08U idx;
    if((IDLECTL==1 && F_OUTPUT_FUEL) || F_OUTPUT_FUEL==0){DO_IDLE=0;}
    if(F_OUTPUT_FUEL && IDLECTL==0)                      {DO_IDLE=1;}
		
    if(IDLECTL==1 && F_OUTPUT_FUEL)                      {DO_IDLE_Close=1;}
    if((F_OUTPUT_FUEL && IDLECTL==0) || F_OUTPUT_FUEL==0){DO_IDLE_Close=0;}
		
    for(idx=0;idx<INPUT_NUM;idx++)
    {
        INPUT_TEMP[idx]=0;
    }
    if(NowMode==2)
    {
        DO_AUTOMODE=1;
    }
    else
    {
        DO_AUTOMODE=0;
    }
    if(F_STA_STOPALARM|F_STA_WARN)
    {
       DO_COMMALARM=1; 
    }
    else
    {
       DO_COMMALARM=0;
    }
                             
    if(FUEL<=DES_FUELPUMP_ON &&FUEL>=0)
    {
        TimerEnArr[TMR_FUELPUMP_ON]=1;  
    }
    else
    {
      TimerEnArr[TMR_FUELPUMP_ON]=0;  
    }
    if(TimerTrig[TMR_FUELPUMP_ON])
     {
       TimerTrig[TMR_FUELPUMP_ON]=0;
       DO_FUELPUMP=1; 
     }
    if(FUEL>=DES_FUELPUMP_OFF)
    {
      TimerEnArr[TMR_FUELPUMP_OFF]=1;   
    }
    else
    {
      TimerEnArr[TMR_FUELPUMP_OFF]=0;  
    }
    if(TimerTrig[TMR_FUELPUMP_OFF])
     {
       TimerTrig[TMR_FUELPUMP_OFF]=0;
       DO_FUELPUMP=0; 
     }
    if(FUEL==-32768) DO_FUELPUMP=0; 
    CALAI_AUX_RelayOUT_Ctl();
    CALAI_AUX_INPUT_CTL();   
   
    F_WARN_EXTERN=DI_EXTERN_WRN;
   
    F_WARN_WATER_LO=DI_LOWLIQUID_WRN;
    
    if(DI_EXTERN_STOP)
    {
        F_STOP_EXTERN=1;
    }
    F_DI_TEMPHI_STOP   =DI_TEMPHIGH && F_STOP_TEMP_HI;
    F_DI_OILP_STOP     =DI_OPLOW && F_STOP_OP_LO;
    F_DI_FUELLOW_WRN   =DI_LOWFUEL_WRN;
    F_DI_WATERLOW_WRN  =DI_LOWLIQUID_WRN;
    F_DI_FUELLOW_STOP  =DI_LOWFUEL_STOP;
    F_DI_WATERLOW_STOP =DI_LOWLIQUID_STOP;     
}

void XIO_CALAI_LOOP(void)
{
 if(HardTestModeEn)
 {
	XIOCustomDIDO();
	XIORelayProcess();
	XIOLedProcess();
	XIOInputProcess();
 }
}


/************The end ************/
