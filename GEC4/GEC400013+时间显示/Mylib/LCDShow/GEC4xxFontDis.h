
#ifndef __GEC4XXFONTDIS_H
#define __GEC4XXFONTDIS_H



#define LNGMAX                   12
#define MainPageSUBMENU_NUM      3    //主菜单的个数
#define SysMsg_num               1    //GEC4xx控制信息页面数量
#define SysLanguage_num		       2	  //GEC4xx语言信息页面数量, 
#define CurveDotCtr	             8	  //默认8个点 16个数据
#define CurveMainPgCtr	         3	  //主菜单5个//自定义传感器曲线个数
#define sParmSetnum_ForMainPage  74   //控制器参数整定的子菜单个数
#define sAdjParmPageCon          18   //GEC400控参数整定页面数量
#define sCurveParmPageCon        64   //GEC400自定义曲线数据数量
#define sCMDParmPageCon          2   //GEC400远程命令数据数量
#define sHidParmPageCon          4   //GEC400控隐藏参数页面数量
#define sHidParmPageCon1         12   //GEC400控隐藏参数数量
#define GECx_DisCon              29
 

typedef unsigned char  uchar;
typedef unsigned int   uint;

typedef struct
  {
    uchar line[16][40];
  }const typPG;
typedef const typPG *typPGPointer;

const typedef enum   //公共使用的枚举类型
{
  lPubLabel1=1,
	lPubLabel2=2,
}lPubMenuLabel;

const typedef enum   //参数设置主菜单枚举类型
{
  lMainNum_ParmSet=1, //1 控制器参数整定
  lMainNum_Message,   //2 控制器信息
  lMainNum_Language,  //3 语言选择
 
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
  uchar Mode;                         //参数类型，255为字符串
  const uchar NameStrCN[GECx_DisCon]; //名称字符串指针(中文)
  const uchar NameStrEN[GECx_DisCon]; //名称字符串指针(英文)
  uchar ScaleStr[10];                 //单位字符串
  const uchar *ParamStrCN;            //参数字符串显示指针,参数范围
  const uchar *ParamStrEN;
  uint MinValue;             //最小值
  uint MaxValue;             //最大值
  uint DefaultValue;         //默认值
  uint ValueOffset;          //数据偏移
}const ParamStruct;
typedef const ParamStruct *ParamPtr;

typedef struct
{
  uchar   const  *ptNameStrCN;   //名称字符串指针(中文)
  uchar   const  *ptNameStrEN;   //名称字符串指针(英文)
  lPubMenuLabel  lMenuHeadnum;
  uchar          MaxItem;        //最大项目数
  ParamPtr       SubItems[sParmSetnum_ForMainPage];  //子菜单参数指针
}const SubMenu;
typedef const SubMenu *SubMenuPtr;

typedef struct
{
  uchar        MENUNUM;                      //子菜单数
  SubMenuPtr   SubPtr[MainPageSUBMENU_NUM];  //子菜单指针
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

//控制器参数设置中特殊项框架定义
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


//自定义传感器曲线

typedef struct
{
  const uchar *cpParamStrCN;    //参数字符串显示指针,参数范围
  const uchar *cpParamStrEN;
  const uchar *cpParamScope;    //范围 
}const  CurveHeadStruct;
typedef const CurveHeadStruct *cpCurveHeadStruct;

typedef struct
{
  lPubMenuLabel ParmSetHeadnum;
  uint  CurveMin;             //最小值
  uint  CurveMax;             //最大值
  uint  CurveDefault;         //默认值
  uint  CurveOffset;          //数据偏移
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

//------------------- 函数声明 -----------------------
extern const MainPage   PageShow;   //1：发电    2：磁传感器+发电    4：发电+油压  5：磁传感器+发电+油压
extern const MainPage   PageShowSpd;//0：磁感器 3：磁传感器+油压
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
