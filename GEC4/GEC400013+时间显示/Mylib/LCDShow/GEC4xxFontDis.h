
#ifndef __GEC4XXFONTDIS_H
#define __GEC4XXFONTDIS_H



#define LNGMAX                   12
#define MainPageSUBMENU_NUM      3    //���˵��ĸ���
#define SysMsg_num               1    //GEC4xx������Ϣҳ������
#define SysLanguage_num		       2	  //GEC4xx������Ϣҳ������, 
#define CurveDotCtr	             8	  //Ĭ��8���� 16������
#define CurveMainPgCtr	         3	  //���˵�5��//�Զ��崫�������߸���
#define sParmSetnum_ForMainPage  74   //�����������������Ӳ˵�����
#define sAdjParmPageCon          18   //GEC400�ز�������ҳ������
#define sCurveParmPageCon        64   //GEC400�Զ���������������
#define sCMDParmPageCon          2   //GEC400Զ��������������
#define sHidParmPageCon          4   //GEC400�����ز���ҳ������
#define sHidParmPageCon1         12   //GEC400�����ز�������
#define GECx_DisCon              29
 

typedef unsigned char  uchar;
typedef unsigned int   uint;

typedef struct
  {
    uchar line[16][40];
  }const typPG;
typedef const typPG *typPGPointer;

const typedef enum   //����ʹ�õ�ö������
{
  lPubLabel1=1,
	lPubLabel2=2,
}lPubMenuLabel;

const typedef enum   //�����������˵�ö������
{
  lMainNum_ParmSet=1, //1 ��������������
  lMainNum_Message,   //2 ��������Ϣ
  lMainNum_Language,  //3 ����ѡ��
 
}lMainPageHeadnum;


typedef struct
{
  uchar line1[GECx_DisCon];
  uchar line2[GECx_DisCon];
  uchar line3[GECx_DisCon];
  uchar line4[GECx_DisCon];
  uchar line5[GECx_DisCon];
  uchar line6[GECx_DisCon];
  
} const typPGLib;
typedef const typPGLib  *typPGPointLib;

typedef struct
{
  lPubMenuLabel ParmSetHeadnum;
  uchar Mode;                         //�������ͣ�255Ϊ�ַ���
  const uchar NameStrCN[GECx_DisCon]; //�����ַ���ָ��(����)
  const uchar NameStrEN[GECx_DisCon]; //�����ַ���ָ��(Ӣ��)
  uchar ScaleStr[10];                 //��λ�ַ���
  const uchar *ParamStrCN;            //�����ַ�����ʾָ��,������Χ
  const uchar *ParamStrEN;
  uint MinValue;             //��Сֵ
  uint MaxValue;             //���ֵ
  uint DefaultValue;         //Ĭ��ֵ
  uint ValueOffset;          //����ƫ��
}const ParamStruct;
typedef const ParamStruct *ParamPtr;

typedef struct
{
  uchar   const  *ptNameStrCN;   //�����ַ���ָ��(����)
  uchar   const  *ptNameStrEN;   //�����ַ���ָ��(Ӣ��)
  lPubMenuLabel  lMenuHeadnum;
  uchar          MaxItem;        //�����Ŀ��
  ParamPtr       SubItems[sParmSetnum_ForMainPage];  //�Ӳ˵�����ָ��
}const SubMenu;
typedef const SubMenu *SubMenuPtr;

typedef struct
{
  uchar        MENUNUM;                      //�Ӳ˵���
  SubMenuPtr   SubPtr[MainPageSUBMENU_NUM];  //�Ӳ˵�ָ��
}const MainMenu;


typedef struct                  
{
  uchar Disable;
  const uchar *Pagept[LNGMAX];
}const Page;
typedef const Page *PagePtr;

typedef struct
{
  uchar   PageNums;
  PagePtr Pages[10];
}const MainPage;

//�����������������������ܶ���
const typedef struct
{
  uchar Line_CN[23];
  uchar Line_EN[23];
} SpPGLib;
const typedef struct                  
{
  uchar Disable;
  const uchar *Pagept[40];
}SpPage;
typedef SpPage *SpPtr;
const typedef struct
{
  uchar PageNums;
  SpPtr Pages[32];
}SpManyPage;


//�Զ��崫��������

typedef struct
{
  const uchar *cpParamStrCN;    //�����ַ�����ʾָ��,������Χ
  const uchar *cpParamStrEN;
  const uchar *cpParamScope;    //��Χ 
}const  CurveHeadStruct;
typedef const CurveHeadStruct *cpCurveHeadStruct;

typedef struct
{
  lPubMenuLabel ParmSetHeadnum;
  uint  CurveMin;             //��Сֵ
  uint  CurveMax;             //���ֵ
  uint  CurveDefault;         //Ĭ��ֵ
  uint  CurveOffset;          //����ƫ��
}const  CurveStruct;
typedef const CurveStruct *CurveParamPtr;

const typedef struct
{
  cpCurveHeadStruct CurveHeadStr;
  CurveParamPtr     CurvePages[CurveDotCtr*2];
}cpCurveMsubPg;
typedef const cpCurveMsubPg *cpCurveMsubPgstr;

const typedef struct
{
  uchar PageNums;
  cpCurveMsubPgstr cpCurveMainPg[CurveMainPgCtr];
}cpCurveMainPg;

//------------------- �������� -----------------------
extern const MainPage   PageShow;   //1������    2���Ŵ�����+����    4������+��ѹ  5���Ŵ�����+����+��ѹ
extern const MainPage   PageShowSpd;//0���Ÿ��� 3���Ŵ�����+��ѹ
extern const MainMenu   MAINMENU;
extern const MainPage   SysMsgPageShow;
extern const SpManyPage SpManyShow;
extern const SpManyPage SpHidSubPgShow;
extern const typPG      AlarmStrings_CN[];
extern const typPG      AlarmStrings_EN[];
extern const SubMenu    SUBMENU_AdjustPARM;
extern const SubMenu    HIDMENU_PARM;
extern const SpManyPage SpAdjSubPgShow;
extern const cpCurveMainPg MainCurvePage[];


#endif

/***********************Then End ***************************/
