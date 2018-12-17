//#include "ALL_Includes.h"//包含所需的头文件
#include "TYPCortex.h"

const typPG   AlarmStrings_CN[] =
{  

 {								                                                         
  "紧急停机报警             ","温度高报警停机           ", "低油压报警停机           ", "超速报警停机             ",  "欠速报警停机             ",     
	"速度信号丢失报警停机     ","发电过压报警停机         ", "发电欠压报警停机         ", "发电过流报警停机         ",  "起动失败报警停机         ",   
	"发电超频报警停机         ","发电欠频报警停机         ", "无发电报警停机           ", "低然油位报警停机         ",  "低冷却液位报警停机       ", 
	"  "
 },    //发动机报警  RAMDATABASE[47] 报警停机1
    
   
 {                                                                                                                  
  "温度高报警停机(IN)       ", "低油压报警停机 (IN)      ", "低燃油位报警停机 (IN)    ","低冷却液位报警停机(IN)   ",  "停机失败警告             ",        
	"输入口报警停机           ", "温度传感器断线停机       ", "压力传感器断线停机       ","bit8",                       "bit9",                  
	"bit10",                     "bit11",                     "bit12",                    "bit13",                      "bit14",                
	"bit15"
 },    //发动机报警 RAMDATABASE[48] 报警停机2
   
   
 {							                                                                                         
  "速度信号丢失警告         ", "发电过流警告             ", "bit2                     ", "然油位低警告             ",  "充电失败警告             ",      
	"电池欠压警告             ", "电池过压警告             ", "市电欠压警告             ", "市电过压警告             ",  "水位低警告               ",      
	"温度高警告               ", "油压低警告               ", "维护警告                 ", "输入口警告               ",  "温度传感器断线警告       ",           
	"压力传感器断线警告       " 
 },   //发电机报警 RAMDATABASE[49] 警告1 
   
 { 							                               
  "燃油位低警告  (IN)       ", "水位低警告    (IN)       ",  "滤清维护警告             ",  "bit3",   "bit4", 
	"bit5",                      "bit6",                       "bit7",                       "bit8",   "bit9",  
	"bit10",                     "bit11",                      "bit12",                      "bit13",  "bit14",       
	"bit15"   
 },   //发电机报警 RAMDATABASE[50] 警告2 
   
   
 { //发电机报警 RAMDATABASE[51]暂时没有用
  "bit0",    "bit1",   "bit2",  "bit3",  "bit4",          
	"bit5",    "bit6",   "bit7"   "bit8",  "bit9",   
	"bit10",   "bit11",  "bit12", "bit13", "bit14",   
	"bit15"
 },   //发电机报警 RAMDATABASE[51]暂时没有用

 {                                                                                                       
  "燃油输出延时         秒","开机预热延时         秒","正在起动             秒","机组等待带载",           "开机怠速延时         秒",
	"暖机延时             秒","安全运行延时         秒","开机延时             秒","停机延时             秒","",                    
	"",                       "",                       "开关转换延时         秒","停机散热延时         秒","停机怠速延时         秒",
	"等待停稳延时         秒"
 },     //通用状态位 RAMDATABASE[52]  通用状态1 
    
 {                                                                                                                     
  "停机失败状态             ",  "警告状态                 ", "报警停机状态             ",  "bit3",                     "bit4",               
	"bit5",                       "bit6",                      "bit7",                       "起动间隔延时         秒  ","市电正常鉴别         秒  ", 
	"市电异常鉴别         秒  ",  "得电停机延时         秒  ", "失电自起动延时       秒  ",  "得电自停机延时       秒  ","发电过流停机         秒  ", 
	""
	                                                                                                          
 },     //通用状态位 RAMDATABASE[53] 通用状态2  

 {                                                                                                                               
  "bit0",                       "bit1",                       "bit2",   	                 "机组正常运行             ","手动模式                 ",  
	"自动模式                 ",  "手动试机模式             ",  "停机模式                 ", "bit8",                     "bit9",              
	"bit10",                      "bit11",                      "bit12",                     "bit13",                    "bit14",             
	"bit15"  
 },  //通用状态位 RAMDATABASE[54]   通用状态2  
};

const typPG   AlarmStrings_EN[] =
{
 {	                                                                                                                
  "Emergency Stop alarm     ","High temp alarm          ","Lower OP stop alarm      ","Over speed alarm         ","Under speed alarm        ",      
	"Lost speed alarm         ","Gens over volt alarm     ","Gens under volt alarm    ","Gens over current stop   ","Failed to Start alarm    ",  
	"Gens over freq alarm     ","Gens under freq alarm    ","No gens freq alarm       ","Fuel level alarm         ","Coolant level alarm      ",
	"                         "                     
 },    //?????  RAMDATABASE[47] ????1
  
 {                                                 
  "High temp stop   (IN)    ","Lower OP stop   (IN)     ","Fuel level alarm  (IN)   ","Coolant level alarm IN   ","Failed to Stop warn      ", 
	"Input shutdown alarm     ","TempSensor open alarm    ","Oil sensor open alarm    ","bit8                     ","bit9                     ",                   
	"bit10                    ","bit11                    ","bit12                    ","bit13                    ","bit14                    ",                  
	"bit15                    "                
 },    //?????  RAMDATABASE[48] ????2
  
   
 {
  "Lost speed warn          ","Gens Over Current warn   ","bit2                     ","Fuel level low warn      ","Charge Alt Fail          ",   
	"Battery Low Voltage      ","Battery High Voltage     ","Mains under volt         ","Mains over volt warn     ","Coolant level warn       ",  
	"High temp warn           ","Lower OP warn            ","Maintenance Alarm        ","Input warn               ","Temp Sensor open warn    ",               
	"Oil sensor open warn     "
 },   //?????  RAMDATABASE[49]  ??1 
   
 {
  "Fuel level warn  (IN)    ","Coolant level warn  (IN) ","bit2                     ","bit3                     ","bit4                     ",                
	"bit5                     ","bit6                     ","bit7                     ","bit8                     ","bit9                     ",              
	"bit10                    ","bit11                    ","bit12                    ","bit13                    ","bit14                    ",             
	"bit15                    "                                                                                                
 },   //?????  RAMDATABASE[50]  ??2 
   
 {
  "bit0",    "bit1",   "bit2",              "bit3",              "bit4",                
	"bit5",    "bit6",   "bit7"               "bit8",              "bit9",              
	"bit10",   "bit11",  "bit12",             "bit13",             "bit14",             
	"bit15",               
 },   //?????  RAMDATABASE[51] ?????  

 {
  "Fuel outing          S   ","Preheat time         S   ","Cranking             S   ","Gens waiting load        ","Start idle           S   ",
	"Start warn up        S   ","Safe time            S   ","Start delay          S   ","Stop delay           S   ","                         ",                     
	"                         ","                         ","Switch time          S   ","Cooling time         S   ","Stop idle            S   ",
	"Wait stop            S   "
 },     //???  RAMDATABASE[52]  ????1  
    
 {                                                                                                                                                       
  "Failed to stop           ","Warning                  ","Gens Alarm               ","bit3                     ","bit4                     ",           
	"bit5                     ","bit6                     ","bit7                     ","Crank rest           S   ","Mains normal         S   ", 
	"Mains abnormal       S   ","ETS hold time        S   ","                         ","                         ","Gens OverCur         S   ", 
	"                         "                   
 },     //???  RAMDATABASE[53]   ????2    

 {                                                                                                                               
  "bit0                     ","bit1                     ","bit2                     ","Gens normal runing       ","Manual mode              ",     
	"Auto mode                ","Manual test mode         ","Stop mode                ","bit8                     ","bit9                     ",              
	"bit10                    ","bit11                    ","bit12                    ","bit13                    ","bit14                    ",             
	"bit15                    "  
 },  //通用状态位 RAMDATABASE[54]   通用状态2  

};

//自定义曲线结构
const CurveHeadStruct hCurveHead[]=
{ //                中文                         英文                     范围						 
 /*-00-*/ { {"自定义温度传感器曲线输入"},{"Custom temp  curve input "},{"范围:(0-6000)Ω|(0-200)℃  "}},
 /*-01-*/ { {"自定义压力传感器曲线输入"},{"Custom Press curve input "},{"范围:(0-6000)Ω|(0-1000)Kpa"}},
 /*-02-*/ { {"自定义液位传感器曲线输入"},{"Custom Level curve input "},{"范围:(0-6000)Ω|(0-200)%   "}},
};

CurveStruct  CurveRandVArray[]=
{ //****自定义温度**** SGX曲线
  //       数组中偏移                  范围 默认值
 /*-01-*/ {(lPubMenuLabel)sPc_TEMP_R1,0,6000,  0,0},
 /*-02-*/ {(lPubMenuLabel)sPc_TEMP_R2,0,6000, 21,0},
 /*-03-*/ {(lPubMenuLabel)sPc_TEMP_R3,0,6000, 28,0},
 /*-04-*/ {(lPubMenuLabel)sPc_TEMP_R4,0,6000, 39,0},
 /*-05-*/ {(lPubMenuLabel)sPc_TEMP_R5,0,6000, 56,0},
 /*-06-*/ {(lPubMenuLabel)sPc_TEMP_R6,0,6000,116,0},
 /*-07-*/ {(lPubMenuLabel)sPc_TEMP_R7,0,6000,258,0},
 /*-08-*/ {(lPubMenuLabel)sPc_TEMP_R8,0,6000,300,0},
 /*-09-*/ {(lPubMenuLabel)sPc_TEMP_V1,0, 200,140,0},
 /*-10-*/ {(lPubMenuLabel)sPc_TEMP_V2,0, 200,110,0},
 /*-11-*/ {(lPubMenuLabel)sPc_TEMP_V3,0, 200,100,0},
 /*-12-*/ {(lPubMenuLabel)sPc_TEMP_V4,0, 200, 90,0},
 /*-13-*/ {(lPubMenuLabel)sPc_TEMP_V5,0, 200, 80,0},
 /*-14-*/ {(lPubMenuLabel)sPc_TEMP_V6,0, 200, 60,0},
 /*-15-*/ {(lPubMenuLabel)sPc_TEMP_V7,0, 200, 40,0},
 /*-16-*/ {(lPubMenuLabel)sPc_TEMP_V8,0, 200, 20,0},
 //****自定义压力****SGX
 /*-17-*/ {(lPubMenuLabel)sPc_OP_R1,  0,6000, 15,0},
 /*-18-*/ {(lPubMenuLabel)sPc_OP_R2,  0,6000, 30,0},
 /*-19-*/ {(lPubMenuLabel)sPc_OP_R3,  0,6000, 50,0},
 /*-20-*/ {(lPubMenuLabel)sPc_OP_R4,  0,6000, 86,0},
 /*-21-*/ {(lPubMenuLabel)sPc_OP_R5,  0,6000,100,0},
 /*-22-*/ {(lPubMenuLabel)sPc_OP_R6,  0,6000,132,0},
 /*-23-*/ {(lPubMenuLabel)sPc_OP_R7,  0,6000,168,0},
 /*-24-*/ {(lPubMenuLabel)sPc_OP_R8,  0,6000,200,0},
 /*-25-*/ {(lPubMenuLabel)sPc_OP_V1,  0,1000,   0,0},
 /*-26-*/ {(lPubMenuLabel)sPc_OP_V2,  0,1000, 100,0},
 /*-27-*/ {(lPubMenuLabel)sPc_OP_V3,  0,1000, 200,0},
 /*-28-*/ {(lPubMenuLabel)sPc_OP_V4,  0,1000, 400,0},
 /*-29-*/ {(lPubMenuLabel)sPc_OP_V5,  0,1000, 500,0},
 /*-30-*/ {(lPubMenuLabel)sPc_OP_V6,  0,1000, 700,0},
 /*-31-*/ {(lPubMenuLabel)sPc_OP_V7,  0,1000,1000,0},
 /*-32-*/ {(lPubMenuLabel)sPc_OP_V8,  0,1000,1000,0},
 //****自定义液位****SGD
 /*-33-*/ {(lPubMenuLabel)sPc_LV_R1,  0,6000,  0,0},
 /*-34-*/ {(lPubMenuLabel)sPc_LV_R2,  0,6000, 20,0},
 /*-35-*/ {(lPubMenuLabel)sPc_LV_R3,  0,6000, 40,0},
 /*-36-*/ {(lPubMenuLabel)sPc_LV_R4,  0,6000, 80,0},
 /*-37-*/ {(lPubMenuLabel)sPc_LV_R5,  0,6000,100,0},
 /*-38-*/ {(lPubMenuLabel)sPc_LV_R6,  0,6000,120,0},
 /*-39-*/ {(lPubMenuLabel)sPc_LV_R7,  0,6000,160,0},
 /*-40-*/ {(lPubMenuLabel)sPc_LV_R8,  0,6000,200,0},
 /*-41-*/ {(lPubMenuLabel)sPc_LV_V1,  0, 200,  0,0},
 /*-42-*/ {(lPubMenuLabel)sPc_LV_V2,  0, 200, 10,0},
 /*-43-*/ {(lPubMenuLabel)sPc_LV_V3,  0, 200, 20,0},
 /*-44-*/ {(lPubMenuLabel)sPc_LV_V4,  0, 200, 40,0},
 /*-45-*/ {(lPubMenuLabel)sPc_LV_V5,  0, 200, 50,0},
 /*-46-*/ {(lPubMenuLabel)sPc_LV_V6,  0, 200, 60,0},
 /*-47-*/ {(lPubMenuLabel)sPc_LV_V7,  0, 200, 80,0},
 /*-48-*/ {(lPubMenuLabel)sPc_LV_V8,  0, 200,100,0},
 };

cpCurveMsubPg CurveMsubPg_01=	//自定义温度传感器
{
 &hCurveHead[0],
 {
  &CurveRandVArray[0], 
  &CurveRandVArray[1], 
  &CurveRandVArray[2], 
  &CurveRandVArray[3], 
  &CurveRandVArray[4], 
  &CurveRandVArray[5], 
  &CurveRandVArray[6], 
  &CurveRandVArray[7],
  &CurveRandVArray[8],
  &CurveRandVArray[9],
  &CurveRandVArray[10],
  &CurveRandVArray[11],
  &CurveRandVArray[12],
  &CurveRandVArray[13],
  &CurveRandVArray[14],
  &CurveRandVArray[15],  
 }
};

cpCurveMsubPg CurveMsubPg_02=	//自定义压力传感器
{
 &hCurveHead[1],
 {
  &CurveRandVArray[16], 
  &CurveRandVArray[17], 
  &CurveRandVArray[18], 
  &CurveRandVArray[19], 
  &CurveRandVArray[20], 
  &CurveRandVArray[21], 
  &CurveRandVArray[22], 
  &CurveRandVArray[23], 
  &CurveRandVArray[24],
  &CurveRandVArray[25],
  &CurveRandVArray[26],
  &CurveRandVArray[27],
  &CurveRandVArray[28],
  &CurveRandVArray[29],
  &CurveRandVArray[30],
  &CurveRandVArray[31],
 }
};

cpCurveMsubPg CurveMsubPg_03=	//自定义液位传感器
{
 &hCurveHead[2],
 {
  &CurveRandVArray[32], 
  &CurveRandVArray[33], 
  &CurveRandVArray[34], 
  &CurveRandVArray[35], 
  &CurveRandVArray[36], 
  &CurveRandVArray[37], 
  &CurveRandVArray[38], 
  &CurveRandVArray[39], 
  &CurveRandVArray[40],
  &CurveRandVArray[41],
  &CurveRandVArray[42],
  &CurveRandVArray[43],
  &CurveRandVArray[44],
  &CurveRandVArray[45],
  &CurveRandVArray[46],
  &CurveRandVArray[47],
 }
};

cpCurveMainPg MainCurvePage[]=
{
 CurveMainPgCtr,
 {
  &CurveMsubPg_01,&CurveMsubPg_02,&CurveMsubPg_03,
 }
};

 const SpPGLib   SpAdjPageSelib[] =
 {
   /*-00-*/ { {"00 GEC4010  "},{"00 GEC4010  "}},
   /*-01-*/ { {"01 GEC4020  "},{"01 GEC4020  "}},
   /*-02-*/ { {"00 否      "},{"00 No      "}},
   /*-03-*/	{ {"01 恢复    "},{"01 Yes     "}},
   
 };                                                                  
                                                                    
const SpPage SpAdjPage1=
 {
   1,     
   &SpAdjPageSelib[ 0].Line_EN[0],//&SpAdjPageSelib[ 1].Line_EN[0],
   
   &SpAdjPageSelib[ 0].Line_CN[0],//&SpAdjPageSelib[ 1].Line_CN[0],
 };

const SpPage SpAdjPage2=
 {
   2,     
   &SpAdjPageSelib[ 2].Line_EN[0],&SpAdjPageSelib[ 3].Line_EN[0], 
  
   &SpAdjPageSelib[ 2].Line_CN[0],&SpAdjPageSelib[ 3].Line_CN[0],
 };

const SpManyPage SpAdjSubPgShow=
 {
  2,         
  &SpAdjPage1,&SpAdjPage2,
 };

const ParamStruct PARAMS_AdjustPASS[]=                                                                                                             
{                                                                                                                                                        //最小值//最大值//默认值//当前值在数组中的偏移量 
 /*-01-*/ {(lPubMenuLabel)sPa_VOLT_MAINS_A,  0x00, {"01 市电A相电压整定"}, {"01 Mains A volt adj"},   {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-02-*/ {(lPubMenuLabel)sPa_VOLT_MAINS_B,  0x00, {"02 市电B相电压整定"}, {"02 Mains B volt adj"},   {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-03-*/ {(lPubMenuLabel)sPa_VOLT_MAINS_C,  0x00, {"03 市电C相电压整定"}, {"03 Mains C volt adj"},   {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-04-*/ {(lPubMenuLabel)sPa_VOLT_GEN_A  ,  0x00, {"04 发电A相电压整定"}, {"04 Gens A volt adj"},    {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-05-*/ {(lPubMenuLabel)sPa_VOLT_GEN_B  ,  0x00, {"05 发电B相电压整定"}, {"05 Gens B volt adj"},    {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-06-*/ {(lPubMenuLabel)sPa_VOLT_GEN_C  ,  0x00, {"06 发电C相电压整定"}, {"06 Gens C volt adj"},    {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-07-*/ {(lPubMenuLabel)sPa_CURRENT_A   ,  0x00, {"07 A相电流整定"},     {"07 Current A adj"},      {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-08-*/ {(lPubMenuLabel)sPa_CURRENT_B   ,  0x00, {"08 B相电流整定"},     {"08 Current B adj"},      {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-09-*/ {(lPubMenuLabel)sPa_CURRENT_C   ,  0x00, {"09 C相电流整定"},     {"09 Current C adj"},      {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-10-*/ {(lPubMenuLabel)sPa_TEMP        ,  0x00, {"10 水/缸温度整定"},   {"10 Temperature adj"},    {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-11-*/ {(lPubMenuLabel)sPa_OP          ,  0x00, {"11 机油压力整定"},    {"11 Pressure adj"},       {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-12-*/ {(lPubMenuLabel)sPa_LEVEL       ,  0x00, {"12 燃油位整定"},      {"12 Level adj"},          {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-13-*/ {(lPubMenuLabel)sPa_CustomAnalog,  0x00, {"13 自定义整定"},      {"13 Custom adj"},         {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-14-*/ {(lPubMenuLabel)sPa_BATT        ,  0x01, {"14 电池电压整定"},    {"14 Battery volt adj"},   {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-15-*/ {(lPubMenuLabel)sPa_CHARGER     ,  0x01, {"15 充电机D+(WL)整定"},{"15 D+(WL) adj"},         {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-16-*/ {(lPubMenuLabel)sPa_COS         ,  0x00, {"16 发电功率因数整定"},{"16 Power factor adj"},   {""},{""},{""},{4000},{16000},{10000},{0},},
 /*-17-*/ {(lPubMenuLabel)sPa_MODEL       ,  0x08, {"17 控制器型号选择"},  {"17 Select module type"}, {"00"},{""},{""},{ 0},{   1}, {MODEL410},{0},},
 /*-18-*/ {(lPubMenuLabel)sPa_RestFactory ,  0x08, {"18 恢复出厂参数设置"},{"18 Restore factory Set"},{"01"},{""},{""},{ 0},{   1}, {   0}, {0},},


};  
const SubMenu SUBMENU_AdjustPARM=                                                                                  
{                                                                                                            
  "",
  "",   
  lPubLabel1,
  sAdjParmPageCon,                 //GEC400控参数整定页面数量
  {
    &PARAMS_AdjustPASS[0], &PARAMS_AdjustPASS[1], &PARAMS_AdjustPASS[2], &PARAMS_AdjustPASS[3], 
    &PARAMS_AdjustPASS[4], &PARAMS_AdjustPASS[5], &PARAMS_AdjustPASS[6], &PARAMS_AdjustPASS[7], 
    &PARAMS_AdjustPASS[8], &PARAMS_AdjustPASS[9], &PARAMS_AdjustPASS[10],&PARAMS_AdjustPASS[11],
    &PARAMS_AdjustPASS[12],&PARAMS_AdjustPASS[13],&PARAMS_AdjustPASS[14],&PARAMS_AdjustPASS[15],
    &PARAMS_AdjustPASS[16],&PARAMS_AdjustPASS[17],
  } 
};

const SpPGLib   SpPage_Sel_Pub[] =
  {
   
   /*-00-*/ {{"00 未使用            "}, {"00 Not used           "}, },
   /*-01-*/ {{"01 公共报警输出      "}, {"01 Common alarm       "}, },
   /*-02-*/ {{"02 得电停机控制      "}, {"02 Energised to stop  "}, },
   /*-03-*/ {{"03 怠速控制(闭合怠速)"}, {"03 Idle control(Close)"}, },
   /*-04-*/ {{"04 预热控制          "}, {"04 Preheat control    "}, },
   /*-05-*/ {{"05 发电合闸          "}, {"05 Close Gens         "}, },
   /*-06-*/ {{"06 保留              "}, {"06 Reserve            "}, },
   /*-07-*/ {{"07 分闸              "}, {"07 Open ATS           "}, },
   /*-08-*/ {{"08 升速控制          "}, {"08 Raise speed        "}, },
   /*-09-*/ {{"09 降速控制          "}, {"09 Drop speed         "}, },
   /*-10-*/ {{"10 机组运行输出      "}, {"10 Generator run      "}, },
   /*-11-*/ {{"11 燃油泵控制        "}, {"11 Fuel pump control  "}, },
   /*-12-*/ {{"12 高速控制          "}, {"12 High speed control "}, },
   /*-13-*/ {{"13 系统在自动模式    "}, {"13 In Auto mode       "}, },
   /*-14-*/ {{"14 停机报警输出      "}, {"14 Shutdown alarm     "}, },
   /*-15-*/ {{"15 燃油输出          "}, {"15 Fule Output        "}, },
   /*-16-*/ {{"16 怠速控制(断开怠速)"}, {"16 Idle control(Open) "}, },
   /*-17-*/ {{"17 保留              "}, {"17 Reserve            "}, },
   /*-18-*/ {{"00 未使用            "}, {"00 Not used           "}, },
   /*-19-*/ {{"01 温度高报警输入    "}, {"01 High temp input    "}, },
   /*-20-*/ {{"02 油压低报警输入    "}, {"02 Low pressure input "}, },
   /*-21-*/ {{"03 外部告警输入      "}, {"03 Warn input         "}, },
   /*-22-*/ {{"04 外部停机报警输入  "}, {"04 Shutdown input     "}, },
   /*-23-*/ {{"05 温度过高时散热停机"}, {"05 WTH STOP by cool   "}, },
   /*-24-*/ {{"06 发电合闸状态输入  "}, {"06 Gens closed input  "}, },
   /*-25-*/ {{"07 保留              "}, {"07 Reserve            "}, },
   /*-26-*/ {{"08 温度高停机禁止    "}, {"08 Inhibit WTH STOP   "}, },
   /*-27-*/ {{"09 油压低停机禁止    "}, {"09 Inhibit OPL STOP   "}, },
   /*-28-*/ {{"10 远端开机输入      "}, {"10 Remote strart      "}, },
   /*-29-*/ {{"11 燃油位低警告输入  "}, {"11 Fuel level warn    "}, },
   /*-30-*/ {{"12 冷却液位低警告输入"}, {"12 Coolant level warn "}, },
   /*-31-*/ {{"13 燃油位低停机输入  "}, {"13 Fuel level shutdown"}, },
   /*-32-*/ {{"14 冷却液位低停机输入"}, {"14 Coolant level shut "}, },
   /*-33-*/ {{"15 自动开机禁止      "}, {"15 Inhibit start Auto "}, },
   /*-34-*/ {{"00 闭合              "}, {"00 Close              "}, },
   /*-35-*/ {{"01 断开              "}, {"01 Open               "}, },
   /*-36-*/ {{"00 停机状态          "}, {"00 Stop mode          "}, },
   /*-37-*/ {{"01 手动状态          "}, {"01 Manual mode        "}, },
   /*-38-*/ {{"02 自动状态          "}, {"02 Auto mode          "}, },
   /*-39-*/ {{"00 磁传感器          "}, {"00 Speed              "}, },
   /*-40-*/ {{"01 发电              "}, {"01 Freq               "}, },
   /*-41-*/ {{"02 磁传感器+发电     "}, {"02 Speed + Freq       "}, },
   /*-42-*/ {{"03 磁传感器+油压     "}, {"03 Speed + OP         "}, },
   /*-43-*/ {{"04 发电+油压         "}, {"04 Freq + OP          "}, },
   /*-44-*/ {{"05 磁传感器+发电+油压"}, {"05 Speed + Freq + OP  "}, },
   /*-45-*/ {{"00 温度高停机        "}, {"00 WTH STOP           "}, },
   /*-46-*/ {{"01 温度高禁止停机    "}, {"01 Inhibit WTH STOP   "}, },
   /*-47-*/ {{"00 油压低停机        "}, {"00 OPL STOP           "}, },
   /*-48-*/ {{"01 油压低禁止停机    "}, {"01 Inhibit OPL STOP   "}, },
   /*-49-*/ {{"00 三相四线          "}, {"00 3 phase 4 wire     "}, },
   /*-50-*/ {{"01 二相三线          "}, {"01 2 phase 3 wire     "}, },
   /*-51-*/ {{"02 单相              "}, {"02 Single phase       "}, },
   /*-52-*/ {{"00 自定义温度传感器  "}, {"00 Temperature curve  "}, },
   /*-53-*/ {{"01 自定义压力传感器  "}, {"01 Oil pressure curve "}, },
   /*-54-*/ {{"02 自定义液位传感器  "}, {"02 Fuel level curve   "}, },
   /*-55-*/ {{"00 无                "}, {"00 Not used           "}, },
   /*-56-*/ {{"01 自定义电阻型      "}, {"01 Defined Curve      "}, },
   /*-57-*/ {{"02 VDO               "}, {"02 VDO                "}, },
   /*-58-*/ {{"03 SGH               "}, {"03 SGH                "}, },
   /*-59-*/ {{"04 SGD               "}, {"04 SGD                "}, },
   /*-60-*/ {{"05 CURTIS            "}, {"05 CURTIS             "}, },
   /*-61-*/ {{"06 DATCON            "}, {"06 DATCON             "}, },
   /*-62-*/ {{"07 VOLVO-EC          "}, {"07 VOLVO-EC           "}, },
   /*-63-*/ {{"08 SGX               "}, {"08 SGX                "}, },
   /*-64-*/ {{"09 PT100             "}, {"09 PT100              "}, },
   /*-65-*/ {{"02 VDO 10Bar         "}, {"02 VDO 10Bar          "}, },
   /*-66-*/ {{"06 DATCON 10Bar      "}, {"06 DATCON 10Bar       "}, },
   /*-67-*/ {{"02 SGH               "}, {"02 SGH                "}, },
   /*-68-*/ {{"03 SGD               "}, {"03 SGD                "}, },
   /*-69-*/ {{"04 YW-ES-8-2S(MS)    "}, {"04 YW-ES-8-2S(MS)     "}, },
   /*-70-*/ {{"05 保留              "}, {"05 Reserve            "}, },
   /*-71-*/ {{"06 未使用            "}, {"06 Not used           "}, },
   /*-72-*/ {{"07 未使用            "}, {"07 Not used           "}, },
   /*-73-*/ {{"02 VDO 10Bar         "}, {"02 VDO 10Bar          "}, },
   /*-74-*/ {{"06 DATCON 10Bar      "}, {"06 DATCON 10Bar       "}, },
   /*-75-*/ {{"09 保留              "}, {"09 Reserve            "}, },
   /*-76-*/ {{"00 开关量输入口4配置 "}, {"00 Digit input3 set   "}, },
   /*-77-*/ {{"00 开关量输入口3配置 "}, {"00 Digit input4 set   "}, },
   /*-78-*/ {{"01 压力传感器        "}, {"01 Pressure Sensor    "}, },
   /*-79-*/ {{"02 温度传感器        "}, {"02 Temperature Sensor "}, },
   /*-80-*/ {{"03 液位传感器        "}, {"03 Level Sensor       "}, },
   /*-81-*/ {{"00 指示              "}, {"00 Indication         "}, },
   /*-82-*/ {{"01 警告              "}, {"01 Warn               "}, },
   /*-83-*/ {{"02 停机              "}, {"02 Shutdown           "}, },
   /*-84-*/ {{"01 保留              "}, {"01 Reserve            "}, },
   /*-85-*/ {{"02 保留              "}, {"02 Reserve            "}, },
   /*-86-*/ {{"00 普通机组          "}, {"00 Conventional Engine"}, },//发动机类型 J1939
   /*-87-*/ {{"01 通用J1939机组     "}, {"01 General J1939      "}, },
   /*-88-*/ {{"02 BOSCH             "}, {"02 BOSCH              "}, },
   /*-89-*/ {{"03 保留              "}, {"03 Reserve            "}, },
   /*-90-*/ {{"04 保留              "}, {"04 Reserve            "}, },
   /*-91-*/ {{"05 保留              "}, {"05 Reserve            "}, },
   /*-92-*/ {{"10 欧Ⅲ              "}, {"10 ΩⅢ               "}, },
   /*-93-*/ {{"16 急停输入          "}, {"16 EM Input           "}, },
};                                                                  
                                                                    
const SpPage SpPage1=
 {
   18,     
   &SpPage_Sel_Pub[ 0].Line_EN[0],&SpPage_Sel_Pub[ 1].Line_EN[0],&SpPage_Sel_Pub[ 2].Line_EN[0],
   &SpPage_Sel_Pub[ 3].Line_EN[0],&SpPage_Sel_Pub[ 4].Line_EN[0],&SpPage_Sel_Pub[ 5].Line_EN[0],
   &SpPage_Sel_Pub[ 6].Line_EN[0],&SpPage_Sel_Pub[ 7].Line_EN[0],&SpPage_Sel_Pub[ 8].Line_EN[0],
   &SpPage_Sel_Pub[ 9].Line_EN[0],&SpPage_Sel_Pub[10].Line_EN[0],&SpPage_Sel_Pub[11].Line_EN[0],
   &SpPage_Sel_Pub[12].Line_EN[0],&SpPage_Sel_Pub[13].Line_EN[0],&SpPage_Sel_Pub[14].Line_EN[0],
   &SpPage_Sel_Pub[15].Line_EN[0],&SpPage_Sel_Pub[16].Line_EN[0],&SpPage_Sel_Pub[17].Line_EN[0],
   
   &SpPage_Sel_Pub[ 0].Line_CN[0],&SpPage_Sel_Pub[ 1].Line_CN[0],&SpPage_Sel_Pub[ 2].Line_CN[0],
   &SpPage_Sel_Pub[ 3].Line_CN[0],&SpPage_Sel_Pub[ 4].Line_CN[0],&SpPage_Sel_Pub[ 5].Line_CN[0],
   &SpPage_Sel_Pub[ 6].Line_CN[0],&SpPage_Sel_Pub[ 7].Line_CN[0],&SpPage_Sel_Pub[ 8].Line_CN[0],
   &SpPage_Sel_Pub[ 9].Line_CN[0],&SpPage_Sel_Pub[10].Line_CN[0],&SpPage_Sel_Pub[11].Line_CN[0],
   &SpPage_Sel_Pub[12].Line_CN[0],&SpPage_Sel_Pub[13].Line_CN[0],&SpPage_Sel_Pub[14].Line_CN[0],
   &SpPage_Sel_Pub[15].Line_CN[0],&SpPage_Sel_Pub[16].Line_CN[0],&SpPage_Sel_Pub[17].Line_CN[0],
 };
const SpPage SpPage5=
 {
   17,     
   &SpPage_Sel_Pub[18].Line_EN[0],&SpPage_Sel_Pub[19].Line_EN[0],&SpPage_Sel_Pub[20].Line_EN[0],
   &SpPage_Sel_Pub[21].Line_EN[0],&SpPage_Sel_Pub[22].Line_EN[0],&SpPage_Sel_Pub[23].Line_EN[0],
   &SpPage_Sel_Pub[24].Line_EN[0],&SpPage_Sel_Pub[25].Line_EN[0],&SpPage_Sel_Pub[26].Line_EN[0],
   &SpPage_Sel_Pub[27].Line_EN[0],&SpPage_Sel_Pub[28].Line_EN[0],&SpPage_Sel_Pub[29].Line_EN[0],
   &SpPage_Sel_Pub[30].Line_EN[0],&SpPage_Sel_Pub[31].Line_EN[0],&SpPage_Sel_Pub[32].Line_EN[0],
   &SpPage_Sel_Pub[33].Line_EN[0],&SpPage_Sel_Pub[93].Line_EN[0],
   
   &SpPage_Sel_Pub[18].Line_CN[0],&SpPage_Sel_Pub[19].Line_CN[0],&SpPage_Sel_Pub[20].Line_CN[0],
   &SpPage_Sel_Pub[21].Line_CN[0],&SpPage_Sel_Pub[22].Line_CN[0],&SpPage_Sel_Pub[23].Line_CN[0],
   &SpPage_Sel_Pub[24].Line_CN[0],&SpPage_Sel_Pub[25].Line_CN[0],&SpPage_Sel_Pub[26].Line_CN[0],
   &SpPage_Sel_Pub[27].Line_CN[0],&SpPage_Sel_Pub[28].Line_CN[0],&SpPage_Sel_Pub[29].Line_CN[0],
   &SpPage_Sel_Pub[30].Line_CN[0],&SpPage_Sel_Pub[31].Line_CN[0],&SpPage_Sel_Pub[32].Line_CN[0],
   &SpPage_Sel_Pub[33].Line_CN[0],&SpPage_Sel_Pub[93].Line_CN[0],
 };

const SpPage SpPage6=
 {
   2,     
   &SpPage_Sel_Pub[34].Line_EN[0],&SpPage_Sel_Pub[35].Line_EN[0],
   
   &SpPage_Sel_Pub[34].Line_CN[0],&SpPage_Sel_Pub[35].Line_CN[0],
 };

const SpPage SpPage15=
 {
   3,     
   &SpPage_Sel_Pub[36].Line_EN[0],&SpPage_Sel_Pub[37].Line_EN[0],&SpPage_Sel_Pub[38].Line_EN[0],
   
   &SpPage_Sel_Pub[36].Line_CN[0],&SpPage_Sel_Pub[37].Line_CN[0],&SpPage_Sel_Pub[38].Line_CN[0],
 };

const SpPage SpPage16=
 {
   6,     
   &SpPage_Sel_Pub[39].Line_EN[0],&SpPage_Sel_Pub[40].Line_EN[0],&SpPage_Sel_Pub[41].Line_EN[0],
   &SpPage_Sel_Pub[42].Line_EN[0],&SpPage_Sel_Pub[43].Line_EN[0],&SpPage_Sel_Pub[44].Line_EN[0],
   
   &SpPage_Sel_Pub[39].Line_CN[0],&SpPage_Sel_Pub[40].Line_CN[0],&SpPage_Sel_Pub[41].Line_CN[0],
   &SpPage_Sel_Pub[42].Line_CN[0],&SpPage_Sel_Pub[43].Line_CN[0],&SpPage_Sel_Pub[44].Line_CN[0],
 };
 
const SpPage SpPage17=
 {
   2,     
   &SpPage_Sel_Pub[45].Line_EN[0],&SpPage_Sel_Pub[46].Line_EN[0],
   
   &SpPage_Sel_Pub[45].Line_CN[0],&SpPage_Sel_Pub[46].Line_CN[0],
 };

const SpPage SpPage18=
 {
   2,     
   &SpPage_Sel_Pub[47].Line_EN[0],&SpPage_Sel_Pub[48].Line_EN[0],
   
   &SpPage_Sel_Pub[47].Line_CN[0],&SpPage_Sel_Pub[48].Line_CN[0],
 };
 
const SpPage SpPage19=
 {
   3,     
   &SpPage_Sel_Pub[49].Line_EN[0],&SpPage_Sel_Pub[50].Line_EN[0],&SpPage_Sel_Pub[51].Line_EN[0],
 
   &SpPage_Sel_Pub[49].Line_CN[0],&SpPage_Sel_Pub[50].Line_CN[0],&SpPage_Sel_Pub[51].Line_CN[0],
 };
const SpPage SpPage20=    
 {
   11,     
   &SpPage_Sel_Pub[55].Line_EN[0],&SpPage_Sel_Pub[56].Line_EN[0],&SpPage_Sel_Pub[57].Line_EN[0],
   &SpPage_Sel_Pub[58].Line_EN[0],&SpPage_Sel_Pub[59].Line_EN[0],&SpPage_Sel_Pub[60].Line_EN[0],
   &SpPage_Sel_Pub[61].Line_EN[0],&SpPage_Sel_Pub[62].Line_EN[0],&SpPage_Sel_Pub[63].Line_EN[0],
   &SpPage_Sel_Pub[64].Line_EN[0],&SpPage_Sel_Pub[92].Line_EN[0],
   
   &SpPage_Sel_Pub[55].Line_CN[0],&SpPage_Sel_Pub[56].Line_CN[0],&SpPage_Sel_Pub[57].Line_CN[0],
   &SpPage_Sel_Pub[58].Line_CN[0],&SpPage_Sel_Pub[59].Line_CN[0],&SpPage_Sel_Pub[60].Line_CN[0],
   &SpPage_Sel_Pub[61].Line_CN[0],&SpPage_Sel_Pub[62].Line_CN[0],&SpPage_Sel_Pub[63].Line_CN[0],
   &SpPage_Sel_Pub[64].Line_CN[0],&SpPage_Sel_Pub[92].Line_CN[0],
 };

const SpPage SpPage22=    
 {
   6,     
   &SpPage_Sel_Pub[55].Line_EN[0],&SpPage_Sel_Pub[56].Line_EN[0],&SpPage_Sel_Pub[67].Line_EN[0],
   &SpPage_Sel_Pub[68].Line_EN[0],&SpPage_Sel_Pub[69].Line_EN[0],&SpPage_Sel_Pub[70].Line_EN[0], 
   
   &SpPage_Sel_Pub[55].Line_CN[0],&SpPage_Sel_Pub[56].Line_CN[0],&SpPage_Sel_Pub[67].Line_CN[0],
   &SpPage_Sel_Pub[68].Line_CN[0],&SpPage_Sel_Pub[69].Line_CN[0],&SpPage_Sel_Pub[70].Line_CN[0],
 };

//?????? 
const SpPage SpPage23=
 {
   CurveMainPgCtr,     
   &SpPage_Sel_Pub[52].Line_EN[0],&SpPage_Sel_Pub[53].Line_EN[0],&SpPage_Sel_Pub[54].Line_EN[0],
   
   &SpPage_Sel_Pub[52].Line_CN[0],&SpPage_Sel_Pub[53].Line_CN[0],&SpPage_Sel_Pub[54].Line_CN[0],
 };
 

const SpPage SpPage24=    
 {
   11,     
   &SpPage_Sel_Pub[55].Line_EN[0],&SpPage_Sel_Pub[56].Line_EN[0],&SpPage_Sel_Pub[73].Line_EN[0],
   &SpPage_Sel_Pub[58].Line_EN[0],&SpPage_Sel_Pub[59].Line_EN[0],&SpPage_Sel_Pub[60].Line_EN[0],
   &SpPage_Sel_Pub[74].Line_EN[0],&SpPage_Sel_Pub[62].Line_EN[0],&SpPage_Sel_Pub[63].Line_EN[0],
   &SpPage_Sel_Pub[75].Line_EN[0],&SpPage_Sel_Pub[92].Line_EN[0],
   
   &SpPage_Sel_Pub[55].Line_CN[0],&SpPage_Sel_Pub[56].Line_CN[0],&SpPage_Sel_Pub[73].Line_CN[0],
   &SpPage_Sel_Pub[58].Line_CN[0],&SpPage_Sel_Pub[59].Line_CN[0],&SpPage_Sel_Pub[60].Line_CN[0],
   &SpPage_Sel_Pub[74].Line_CN[0],&SpPage_Sel_Pub[62].Line_CN[0],&SpPage_Sel_Pub[63].Line_CN[0],
   &SpPage_Sel_Pub[75].Line_CN[0],&SpPage_Sel_Pub[92].Line_CN[0],
 };


const SpPage SpPage25=    
 {
   4,     
   &SpPage_Sel_Pub[76].Line_EN[0],
	 //&SpPage_Sel_Pub[78].Line_EN[0],&SpPage_Sel_Pub[79].Line_EN[0],
	 &SpPage_Sel_Pub[84].Line_EN[0],&SpPage_Sel_Pub[85].Line_EN[0],
	 &SpPage_Sel_Pub[80].Line_EN[0],
	 
   
   &SpPage_Sel_Pub[76].Line_CN[0],
	 //&SpPage_Sel_Pub[78].Line_CN[0],&SpPage_Sel_Pub[79].Line_CN[0],
	 &SpPage_Sel_Pub[84].Line_CN[0],&SpPage_Sel_Pub[85].Line_CN[0],
	 &SpPage_Sel_Pub[80].Line_CN[0],
	
 };

const SpPage SpPage26=    
 {
   4,     
   &SpPage_Sel_Pub[77].Line_EN[0],&SpPage_Sel_Pub[78].Line_EN[0],&SpPage_Sel_Pub[79].Line_EN[0],
   &SpPage_Sel_Pub[80].Line_EN[0],
   
   &SpPage_Sel_Pub[77].Line_CN[0],&SpPage_Sel_Pub[78].Line_CN[0],&SpPage_Sel_Pub[79].Line_CN[0],
   &SpPage_Sel_Pub[80].Line_CN[0],
 };
const SpPage SpPage27=    
 {10,     
   &SpPage_Sel_Pub[55].Line_EN[0],&SpPage_Sel_Pub[56].Line_EN[0],&SpPage_Sel_Pub[57].Line_EN[0],
   &SpPage_Sel_Pub[58].Line_EN[0],&SpPage_Sel_Pub[59].Line_EN[0],&SpPage_Sel_Pub[60].Line_EN[0],
   &SpPage_Sel_Pub[61].Line_EN[0],&SpPage_Sel_Pub[62].Line_EN[0],&SpPage_Sel_Pub[63].Line_EN[0],
   &SpPage_Sel_Pub[64].Line_EN[0],
   
   &SpPage_Sel_Pub[55].Line_CN[0],&SpPage_Sel_Pub[56].Line_CN[0],&SpPage_Sel_Pub[57].Line_CN[0],
   &SpPage_Sel_Pub[58].Line_CN[0],&SpPage_Sel_Pub[59].Line_CN[0],&SpPage_Sel_Pub[60].Line_CN[0],
   &SpPage_Sel_Pub[61].Line_CN[0],&SpPage_Sel_Pub[62].Line_CN[0],&SpPage_Sel_Pub[63].Line_CN[0],
   &SpPage_Sel_Pub[64].Line_CN[0],
 };
 
//传感器开路动作选择
 const SpPage SpPage28=    
 {
   3,     
   &SpPage_Sel_Pub[81].Line_EN[0],&SpPage_Sel_Pub[82].Line_EN[0],&SpPage_Sel_Pub[83].Line_EN[0],
   
   &SpPage_Sel_Pub[81].Line_CN[0],&SpPage_Sel_Pub[82].Line_CN[0],&SpPage_Sel_Pub[83].Line_CN[0],
 };
 
 //发动机类型选择
 const SpPage SpPage29=    
 {
   6,     
   &SpPage_Sel_Pub[86].Line_EN[0],&SpPage_Sel_Pub[87].Line_EN[0],&SpPage_Sel_Pub[88].Line_EN[0],
	 &SpPage_Sel_Pub[89].Line_EN[0],&SpPage_Sel_Pub[90].Line_EN[0],&SpPage_Sel_Pub[91].Line_EN[0],
   
   &SpPage_Sel_Pub[86].Line_CN[0],&SpPage_Sel_Pub[87].Line_CN[0],&SpPage_Sel_Pub[88].Line_CN[0],
	 &SpPage_Sel_Pub[89].Line_CN[0],&SpPage_Sel_Pub[90].Line_CN[0],&SpPage_Sel_Pub[91].Line_CN[0],
	 
 };
 
const SpManyPage SpManyShow=
 {
  28,         
 //  1       2         3        4
  &SpPage1,&SpPage1,&SpPage1,&SpPage1,
 //  5       6         7        8        9       10
  &SpPage5,&SpPage6,&SpPage5,&SpPage6,&SpPage5,&SpPage6,
 //  11      12     13 AUX5  14 AUX6      15      16
  &SpPage5,&SpPage6,&SpPage1,&SpPage1,&SpPage15,&SpPage16,
 //   17       18        19       20温度    21压力 22复1口曲线 23自定义曲线
  &SpPage17,&SpPage18,&SpPage19,&SpPage20,&SpPage24,&SpPage22, &SpPage23,
 //24复1口功  25复2口功  26复2口曲线  27传感器断线动作  28发动机类型
   &SpPage25, &SpPage26,  &SpPage27,  &SpPage28,        &SpPage29,
 
 };

 const typPGLib   Page_Status_P1_CN[] =
 {                              	                              					   	
	{"发电机"                      , "L-N                        V", "L-L                        V", 
	 "Amp                        A", "            kW          kVar", "PF:           Hz         kVA", 
	},  														 
 };
  
 const typPGLib   Page_Status_P1_EN[] =
 {
  {"Generator                   ", "L-N                        V", "L-L                        V", 
	 "Amp                        A", "            kW          kVar", "PF:           Hz         kVA", 
	},						  
 };
    
 const typPGLib   Page_Status_P2_CN[] =
 {                                                                                                                   
  {												
	 "发电机"                    ,   "累计开机次数:               ", "累计运行:            :   :  ",  
	 "累计电能:                KWh", "                            ", "                            ", 
	}, 
 };
  
 const typPGLib   Page_Status_P2_EN[] =
 {                                                         
  {
	 "Generator",                    "Starts:                     ",  "RunHours:            :   :  ",  
	 "Energy:                  KWh", "                            ",  "                            ",
	},
 }; 
 const typPGLib   Page_Status_P3_CN[] =
 { 				      
  {"发动机"                    ,    "发动机转速:              RPM", "温度:          ℃         ￡",  
	 "机油压力:                kPa",  "            PSI          Bar", "电池        V 充电机       V", 
	},  
 };
  
 const typPGLib   Page_Status_P3_EN[] =
 {
  {"Engine",                        "Speed:                   RPM", "TEMP:          ℃         ￡",
	 "Oil pressure:            kPa",  "            PSI          Bar", "BAT         V  W/L         V",  
	},
 };
  
 const typPGLib   Page_Status_P4_CN[] =
 {                                                                				       
  {"发动机"                    ,   "燃油位                     %","                          ",
	 "                            ", "                            ","                          ",
	},  
 };
  
 const typPGLib   Page_Status_P4_EN[] =
 {
  {"Engine",                     "Fuel level                 %","                          ",
	 "                          ", "                            ","                          ",
	}, 
 };   
 const typPGLib   Page_Status_P5_CN[] =
 {                                                                				      
  {"I/O状态"                   , "IN:    1  2  3  4  5  6  EM", "                          ",
	 "OUT:   1  C  2  3  4  5  6 ", "                          ", "                          ",
	},  
 };
  
 const typPGLib   Page_Status_P5_EN[] =
 {
  {"I/O"                   ,      "IN:    1  2  3  4  5  6  EM", "                          ",
	 "OUT:   1  C  2  3  4  5  6 ", "                          ", "                          ",
	}, 
 };   


const Page PageP0=
 {
   1,     //GUI仪表盘使用
   &Page_Status_P1_EN[0].line1[0],

   &Page_Status_P1_CN[0].line1[0],
 };
 
const Page PageP1=
 {
   6,     //表示本显示页面有 X 个显示行
   &Page_Status_P1_EN[0].line1[0],&Page_Status_P1_EN[0].line2[0],
   &Page_Status_P1_EN[0].line3[0],&Page_Status_P1_EN[0].line4[0],
   &Page_Status_P1_EN[0].line5[0],&Page_Status_P1_EN[0].line6[0],
   
   &Page_Status_P1_CN[0].line1[0],&Page_Status_P1_CN[0].line2[0],
   &Page_Status_P1_CN[0].line3[0],&Page_Status_P1_CN[0].line4[0],
   &Page_Status_P1_CN[0].line5[0],&Page_Status_P1_CN[0].line6[0],
 };

 const Page PageP2=
 {
   6,     //表示本显示页面有 X 个显示行
   &Page_Status_P2_EN[0].line1[0],&Page_Status_P2_EN[0].line2[0],
   &Page_Status_P2_EN[0].line3[0],&Page_Status_P2_EN[0].line4[0],
   &Page_Status_P2_EN[0].line5[0],&Page_Status_P2_EN[0].line6[0],
   												
   &Page_Status_P2_CN[0].line1[0],&Page_Status_P2_CN[0].line2[0],
   &Page_Status_P2_CN[0].line3[0],&Page_Status_P2_CN[0].line4[0],
   &Page_Status_P2_CN[0].line5[0],&Page_Status_P2_CN[0].line6[0],
 };

 const Page PageP3=
 {
   6,     //表示本显示页面有 X 个显示行
   &Page_Status_P3_EN[0].line1[0],&Page_Status_P3_EN[0].line2[0],
   &Page_Status_P3_EN[0].line3[0],&Page_Status_P3_EN[0].line4[0],
   &Page_Status_P3_EN[0].line5[0],&Page_Status_P3_EN[0].line6[0],
   	
   &Page_Status_P3_CN[0].line1[0],&Page_Status_P3_CN[0].line2[0],
   &Page_Status_P3_CN[0].line3[0],&Page_Status_P3_CN[0].line4[0],
   &Page_Status_P3_CN[0].line5[0],&Page_Status_P3_CN[0].line6[0],
 };

const Page PageP4=
 {
   6,     //表示本显示页面有 X 个显示行
   &Page_Status_P4_EN[0].line1[0],&Page_Status_P4_EN[0].line2[0],
   &Page_Status_P4_EN[0].line3[0],&Page_Status_P4_EN[0].line4[0],
   &Page_Status_P4_EN[0].line5[0],&Page_Status_P4_EN[0].line6[0],
   	
   &Page_Status_P4_CN[0].line1[0],&Page_Status_P4_CN[0].line2[0],
   &Page_Status_P4_CN[0].line3[0],&Page_Status_P4_CN[0].line4[0],
   &Page_Status_P4_CN[0].line5[0],&Page_Status_P4_CN[0].line6[0],
 };

const Page PageP5=
 {
   6,     //表示本显示页面有 X 个显示行
   &Page_Status_P5_EN[0].line1[0],&Page_Status_P5_EN[0].line2[0],
   &Page_Status_P5_EN[0].line3[0],&Page_Status_P5_EN[0].line4[0],
   &Page_Status_P5_EN[0].line5[0],&Page_Status_P5_EN[0].line6[0],
   	
   &Page_Status_P5_CN[0].line1[0],&Page_Status_P5_CN[0].line2[0],
   &Page_Status_P5_CN[0].line3[0],&Page_Status_P5_CN[0].line4[0],
   &Page_Status_P5_CN[0].line5[0],&Page_Status_P5_CN[0].line6[0],
 };

 const Page PageAlarmList=
 {
   2,     //表示本显示页面有 X 个显示行
   "                          ","                          ",   	
  
   "                          ","                          ",
 };
 
const Page PageSpd0=
{
   4,
	 &Page_Status_P3_EN[0].line1[0],&Page_Status_P3_EN[0].line2[0],
   &Page_Status_P3_EN[0].line4[0],&Page_Status_P3_EN[0].line5[0],
   	
   &Page_Status_P3_CN[0].line1[0],&Page_Status_P3_CN[0].line2[0],
   &Page_Status_P3_CN[0].line4[0],&Page_Status_P3_CN[0].line5[0],
};
  
const Page PageSpd1=
{
   3, 
	 &Page_Status_P3_EN[0].line1[0],&Page_Status_P2_EN[0].line2[0],
   &Page_Status_P2_EN[0].line3[0],
	
   &Page_Status_P3_CN[0].line1[0],&Page_Status_P2_CN[0].line2[0],
   &Page_Status_P2_CN[0].line3[0],
};

//参数测量主页面显示
//1：发电    2：磁传感器+发电    4：发电+油压  5：磁传感器+发电+油压
 const MainPage PageShow=
 {
  7,         //表示有 X 个显示页面
  &PageP0,&PageP1,&PageP2,&PageP3,&PageP4,&PageP5,&PageAlarmList,
 };
//0：磁感器 3：磁传感器+油压
 const MainPage PageShowSpd=
 {
  5,         //表示有 X 个显示页面
  &PageP0,&PageSpd0,&PageSpd1,&PageP5,&PageAlarmList,
 }; 

 const typPGLib   Page_Status_PARM_CN[] =
 {
   {"1 控制器参数整定","2 控制器信息","3 语言选择/Language","  ","  "},
   {"4 F1","5 F2","6 F3","  ","  "}, 
 };
 const typPGLib   Page_Status_PARM_EN[] =
 {
   {"1 Set Parameters", "2 Information", "3 Set Language/语言","",""},
   {"4 F1","5 F2","5 F3","  ","  "},
 };

 const ParamStruct PARAMS_SysMsg[]=
 { 
    {lPubLabel1, 0,{""},             {" Input Password"}, {""},{""},{""},{0},{0},{0},{0}},
    {lPubLabel1, 1,{"02 系统时间"},  {" Change Password"},{""},{""},{""},{0},{0},{0},{0},},
 };

 const ParamStruct PARAMS_Language[]=
 { 
  {lPubLabel1, 0,{"请选择语言:"},  {"Select Language:"},{""},{""},{""},{0},{3600},{1000},{0}},
  {lPubLabel1, 0,{"1 English"},   {"1 English"},       {""},{""},{""},{0},{3600},{1000},{0}},
  {lPubLabel1, 1,{"2 简体中文"},   {"2 简体中文"},      {""},{""},{""},{0},{9999},{0},   {1}},
 };

  const typPGLib   Page_SysMege_P1_CN[] =
   {
      {"     控制器信息",      "软件版本:GEC4000 V1.14","硬件版本:GEC4000-1.1","发布日期:2018-03-26"," "}, 
   };
  const typPGLib   Page_SysMege_P1_EN[] =
   {
      {"    Information",     "Soft Ver:GEC4000 V1.14", "Hard Ver:GEC4000-1.1", "Issue: 2018-03-26"," "},
   };  
  const typPGLib   Page_SysMege_P2_CN[] =
   {
      {"IN:1 2 3 4 5 6 7 8 EM"," ",   "OUT: F C 1 2 3 4", " ", " "}, 
   };
  const typPGLib   Page_SysMege_P2_EN[] =
   {
      {"IN:1 2 3 4 5 6 7 8 EM"," ",   "OUT: F C 1 2 3 4", " ", " "},
   }; 
 const Page SysMsgPageShowP1=
 {
   4,      //表示本显示页面有 X 个显示行
   &Page_SysMege_P1_EN[0].line1[0],&Page_SysMege_P1_EN[0].line2[0],
   &Page_SysMege_P1_EN[0].line3[0],&Page_SysMege_P1_EN[0].line4[0],
   
   &Page_SysMege_P1_CN[0].line1[0],&Page_SysMege_P1_CN[0].line2[0],
   &Page_SysMege_P1_CN[0].line3[0],&Page_SysMege_P1_CN[0].line4[0],
 };
 const Page SysMsgPageShowP2=
 {
   4,      //表示本显示页面有 X 个显示行
   &Page_SysMege_P2_EN[0].line1[0],&Page_SysMege_P2_EN[0].line2[0],
   &Page_SysMege_P2_EN[0].line3[0],&Page_SysMege_P2_EN[0].line4[0],
   
   &Page_SysMege_P2_CN[0].line1[0],&Page_SysMege_P2_CN[0].line2[0],
   &Page_SysMege_P2_CN[0].line3[0],&Page_SysMege_P2_CN[0].line4[0],
 };
//GEC4xx控制信息页面显示
 const MainPage SysMsgPageShow=
 {
  SysMsg_num,         //表示有 X 个显示页面
  &SysMsgPageShowP1,&SysMsgPageShowP2,
  //&SysMsgPageShowP3,&SysMsgPageShowP4,
};


const unsigned char  Characters_Library_CN[][24]=
{
   /*-01-*/     {"范围: (0-3600) S"},     
   /*-02-*/     {"范围: (0-3600) S"},     
   /*-03-*/     {"范围: (30-360) V"},     
   /*-04-*/     {"范围: (30-360) V"},     
   /*-05-*/     {"范围: (0-99.9) S"},     
   /*-06-*/     {"范围: (0-3600) S"},     
   /*-07-*/     {"范围: (0-3600) S"},     
   /*-08-*/     {"范围: (1-10) 次"},     
   /*-09-*/     {"范围: (0-300) S"},      
   /*-10-*/     {"范围: (3-60) S"},       
   /*-11-*/     {"范围: (3-60) S"},       
   /*-12-*/     {"范围: (1-60) S"},       
   /*-13-*/     {"范围: (0-3600) S"},     
   /*-14-*/     {"范围: (0-3600) S"},     
   /*-15-*/     {"范围: (3-3600) S"},     
   /*-16-*/     {"范围: (0-3600) S"},     
   /*-17-*/     {"范围: (0-120) S"},      
   /*-18-*/     {"范围: (0-120) S"},      
   /*-19-*/     {"范围: (0-10.0) S"},     
   /*-20-*/     {"范围: (10-300) 齿"},    
   /*-21-*/     {"范围: (0-20.0) S"},     
   /*-22-*/     {"范围: (30-360) V"},     
   /*-23-*/     {"范围: (30-360) V"},     
   /*-24-*/     {"范围: (0-6000) RPM"},   
   /*-25-*/     {"范围: (0-6000) RPM"},   
   /*-26-*/     {"范围: (0-75.0) HZ"},      
   /*-27-*/     {"范围: (0-75.0) HZ"},      
   /*-28-*/     {"范围: (80-140) ℃"},    
   /*-29-*/     {"范围: (0-400) kPa"},    
   /*-30-*/     {"范围: (0-100) %"},      
   /*-31-*/     {"范围: (0-20.0) S"},     
   /*-32-*/     {"范围: (0-30.0) V"},       
   /*-33-*/     {"范围: (12.0-40.0) V"},  
   /*-34-*/     {"范围: (4.0-30.0) V"},   
   /*-35-*/     {"范围: (5-6000) /5"},    
   /*-36-*/     {"范围: (5-6000) A"},     
   /*-37-*/     {"范围: (50-130) %"},     
   /*-38-*/     {"范围: (0-3600) S"},     
   /*-39-*/     {"范围: (0-100) %"},      
   /*-40-*/     {"范围: (0-100) %"},      
   /*-41-*/     {"范围: (0-17)"},         
   /*-42-*/     {"范围: (0-17)"},         
   /*-43-*/     {"范围: (0-17)"},         
   /*-44-*/     {"范围: (0-17)"},         
   /*-45-*/     {"范围: (0-15)"},         
   /*-46-*/     {"范围: (0-1)"},          
   /*-47-*/     {"范围: (0-20.0) S"},       
   /*-48-*/     {"范围: (0-15)"},         
   /*-49-*/     {"范围: (0-1)"},          
   /*-50-*/     {"范围: (0-20.0) S"},       
   /*-51-*/     {"范围: (0-15)"},         
   /*-52-*/     {"范围: (0-1)"},          
   /*-53-*/     {"范围: (0-20.0) S"},       
   /*-54-*/     {"范围: (0-15)"},         
   /*-55-*/     {"范围: (0-1)"},          
   /*-56-*/     {"范围: (0-20.0) S"},       
   /*-57-*/     {"范围: (0-15)"},         
   /*-58-*/     {"范围: (0-1)"},          
   /*-59-*/     {"范围: (0-20.0) S"},       
   /*-60-*/     {"范围: (0-2)"},          
   /*-61-*/     {"范围: (1-254)"},        
   /*-62-*/     {"范围: (0-9999)"},       
   /*-63-*/     {"范围: (0-5)"},          
   /*-64-*/     {"范围: (0-3000) RPM"},   
   /*-65-*/     {"范围: (10.0-30.0) Hz"}, 
   /*-66-*/     {"范围: (0-400) Kpa"},    
   /*-67-*/     {"范围: (0-1)"},          
   /*-68-*/     {"范围: (0-1)"},          
   /*-69-*/     {"范围: (0-2)"},          
   /*-70-*/     {"范围: (0-9)"},          
   /*-71-*/     {"范围: (0-9)"},          
   /*-72-*/     {"范围: (0-5)"},          
   /*-73-*/     {"范围: (2-16)"},         
   /*-74-*/     {"范围: (0-2)"},    
   /*-75-*/     {"范围: (0-3)"},  
   /*-76-*/     {"范围: (0-9)"},  
	 /*-77-*/     {"范围: (0-2)"},
   /*-78-*/     {"范围: (0-5)"},//发动机类型选择  	 
	    
};
const unsigned char  Characters_Library_EN[][24]= 
{
  /*-01-*/          {"Range: (0-3600) S"},     
  /*-02-*/          {"Range: (0-3600) S"},     
  /*-03-*/          {"Range: (30-360) V"},     
  /*-04-*/          {"Range: (30-360) V"},     
  /*-05-*/          {"Range: (0-99.9) S"},     
  /*-06-*/          {"Range: (0-3600) S"},     
  /*-07-*/          {"Range: (0-3600) S"},     
  /*-08-*/          {"Range: (1-10) num"},    
  /*-09-*/          {"Range: (0-300) S"},      
  /*-10-*/          {"Range: (3-60) S"},       
  /*-11-*/          {"Range: (3-60) S"},       
  /*-12-*/          {"Range: (1-60) S"},       
  /*-13-*/          {"Range: (0-3600) S"},     
  /*-14-*/          {"Range: (0-3600) S"},     
  /*-15-*/          {"Range: (3-3600) S"},     
  /*-16-*/          {"Range: (0-3600) S"},     
  /*-17-*/          {"Range: (0-120) S"},      
  /*-18-*/          {"Range: (0-120) S"},      
  /*-19-*/          {"Range: (0-10.0) S"},     
  /*-20-*/          {"Range: (10-300)"},       
  /*-21-*/          {"Range: (0-20.0) S"},     
  /*-22-*/          {"Range: (30-360) V"},     
  /*-23-*/          {"Range: (30-360) V"},     
  /*-24-*/          {"Range: (0-6000) RPM"},   
  /*-25-*/          {"Range: (0-6000) RPM"},   
  /*-26-*/          {"Range: (0-75.0) HZ"},      
  /*-27-*/          {"Range: (0-75.0) HZ"},      
  /*-28-*/          {"Range: (80-140) ℃"},    
  /*-29-*/          {"Range: (0-400) kPa"},    
  /*-30-*/          {"Range: (0-100) %"},      
  /*-31-*/          {"Range: (0-20.0) S"},     
  /*-32-*/          {"Range: (0-30.0) V"},       
  /*-33-*/          {"Range: (12.0-40.0) V"},  
  /*-34-*/          {"Range: (4.0-30.0) V"},   
  /*-35-*/          {"Range: (5-6000) /5"},    
  /*-36-*/          {"Range: (5-6000) A"},     
  /*-37-*/          {"Range: (50-130) %"},     
  /*-38-*/          {"Range: (0-3600) S"},     
  /*-39-*/          {"Range: (0-100) %"},      
  /*-40-*/          {"Range: (0-100) %"},      
  /*-41-*/          {"Range: (0-17)"},         
  /*-42-*/          {"Range: (0-17)"},         
  /*-43-*/          {"Range: (0-17)"},         
  /*-44-*/          {"Range: (0-17)"},         
  /*-45-*/          {"Range: (0-15)"},         
  /*-46-*/          {"Range: (0-1)"},          
  /*-47-*/          {"Range: (0-20.0) S"},       
  /*-48-*/          {"Range: (0-15)"},         
  /*-49-*/          {"Range: (0-1)"},          
  /*-50-*/          {"Range: (0-20.0) S"},       
  /*-51-*/          {"Range: (0-15)"},         
  /*-52-*/          {"Range: (0-1)"},          
  /*-53-*/          {"Range: (0-20.0) S"},       
  /*-54-*/          {"Range: (0-15)"},         
  /*-55-*/          {"Range: (0-1)"},          
  /*-56-*/          {"Range: (0-20.0) S"},       
  /*-57-*/          {"Range: (0-15)"},         
  /*-58-*/          {"Range: (0-1)"},          
  /*-59-*/          {"Range: (0-20.0) S"},       
  /*-60-*/          {"Range: (0-2)"},          
  /*-61-*/          {"Range: (1-254)"},        
  /*-62-*/          {"Range: (0-9999)"},       
  /*-63-*/          {"Range: (0-5)"},          
  /*-64-*/          {"Range: (0-3000) RPM"},   
  /*-65-*/          {"Range: (10.0-30.0) Hz"}, 
  /*-66-*/          {"Range: (0-400) Kpa"},    
  /*-67-*/          {"Range: (0-1)"},          
  /*-68-*/          {"Range: (0-1)"},          
  /*-69-*/          {"Range: (0-2)"},          
  /*-70-*/          {"Range: (0-9)"},          
  /*-71-*/          {"Range: (0-9)"},          
  /*-72-*/          {"Range: (0-5)"},          
  /*-73-*/          {"Range: (2-16)"},                                                                                                       
  /*-74-*/          {"Range: (0-2)"}, 
  /*-75-*/          {"Range: (0-3)"}, 
  /*-76-*/          {"Range: (0-0)"}, 
  /*-77-*/          {"Range: (0-2)"},
  /*-78-*/          {"Range: (0-5)"},  //发动机类型选择     	
};


const ParamStruct PARAMS_PASS[]=                                                                                                             
{                                                                                                                                                           
 /*-01-*/ {(lPubMenuLabel)sPn_MAINS_NORMAL_DEL       , 0x00,  {"01 市电正常延时"},       {"01 Mains normal delay"},  {"  "},{&Characters_Library_CN[ 0][0]},{&Characters_Library_EN[ 0][0]},{ 0},{3600},{  10}, {0},},
 /*-02-*/ {(lPubMenuLabel)sPn_MAINS_OBNORMAL_DEL     , 0x00,  {"02 市电异常延时"},       {"02 Mains abnorm delay"},  {"  "},{&Characters_Library_CN[ 1][0]},{&Characters_Library_EN[ 1][0]},{ 0},{3600},{   5}, {0},},
 /*-03-*/ {(lPubMenuLabel)sPn_MAINS_VOLT_LOW         , 0x00,  {"03 市电欠压阈值"},       {"03 Mains under volt"},    {"  "},{&Characters_Library_CN[ 2][0]},{&Characters_Library_EN[ 2][0]},{30},{ 360},{ 184}, {0},},
 /*-04-*/ {(lPubMenuLabel)sPn_MAINS_VOLT_HIGH        , 0x00,  {"04 市电过压阈值"},       {"04 Mains over volt"},     {"  "},{&Characters_Library_CN[ 3][0]},{&Characters_Library_EN[ 3][0]},{30},{ 360},{ 276}, {0},},
 /*-05-*/ {(lPubMenuLabel)sPn_MAINS_TRANS_DEL        , 0x01,  {"05 开关转换延时"},       {"05 Transfer rest time"},  {"  "},{&Characters_Library_CN[ 4][0]},{&Characters_Library_EN[ 4][0]},{ 0},{ 999},{  10}, {0},},
 /*-06-*/ {(lPubMenuLabel)sPn_AMF_START_DEL          , 0x00,  {"06 开机延时"},           {"06 Start delay"},         {"  "},{&Characters_Library_CN[ 5][0]},{&Characters_Library_EN[ 5][0]},{ 0},{3600},{   1}, {0},},
 /*-07-*/ {(lPubMenuLabel)sPn_AMF_STOP_DEL           , 0x00,  {"07 停机延时"},           {"07 Stop delay"},          {"  "},{&Characters_Library_CN[ 6][0]},{&Characters_Library_EN[ 6][0]},{ 0},{3600},{   1}, {0},},
 /*-08-*/ {(lPubMenuLabel)sPn_DES_START_NUM          , 0x00,  {"08 起动次数"},           {"08 Number of Crank"},     {"  "},{&Characters_Library_CN[ 7][0]},{&Characters_Library_EN[ 7][0]},{ 1},{  10},{   3}, {0},},
 /*-09-*/ {(lPubMenuLabel)sPn_DES_PREHEAT_DEL        , 0x00,  {"09 预热时间"},           {"09 Preheat time"},        {"  "},{&Characters_Library_CN[ 8][0]},{&Characters_Library_EN[ 8][0]},{ 0},{ 300},{   0}, {0},},
 /*-10-*/ {(lPubMenuLabel)sPn_DES_CRANK_DEL          , 0x00,  {"10 起动时间"},           {"10 Cranking time"},       {"  "},{&Characters_Library_CN[ 9][0]},{&Characters_Library_EN[ 9][0]},{ 3},{  60},{   8}, {0},},
 /*-11-*/ {(lPubMenuLabel)sPn_DES_CRANKINT_DEL       , 0x00,  {"11 起动间歇时间"},       {"11 Crank rest time"},     {"  "},{&Characters_Library_CN[10][0]},{&Characters_Library_EN[10][0]},{ 3},{  60},{  10}, {0},},
 /*-12-*/ {(lPubMenuLabel)sPn_DES_SAFE_DEL           , 0x00,  {"12 安全运行时间"},       {"12 Safe time"},           {"  "},{&Characters_Library_CN[11][0]},{&Characters_Library_EN[11][0]},{ 1},{  60},{   5}, {0},},
 /*-13-*/ {(lPubMenuLabel)sPn_DES_STARTIDLE_DEL      , 0x00,  {"13 开机怠速时间"},       {"13 Start idle time"},     {"  "},{&Characters_Library_CN[12][0]},{&Characters_Library_EN[12][0]},{ 0},{3600},{   6}, {0},},
 /*-14-*/ {(lPubMenuLabel)sPn_DES_WARM_DEL           , 0x00,  {"14 暖机时间"},           {"14 Warming up time"},     {"  "},{&Characters_Library_CN[13][0]},{&Characters_Library_EN[13][0]},{ 0},{3600},{   8}, {0},},
 /*-15-*/ {(lPubMenuLabel)sPn_DES_COOLING_DEL        , 0x00,  {"15 散热时间"},           {"15 Cooling time"},        {"  "},{&Characters_Library_CN[14][0]},{&Characters_Library_EN[14][0]},{ 3},{3600},{   4}, {0},},
 /*-16-*/ {(lPubMenuLabel)sPn_DES_STOPIDLE_DEL       , 0x00,  {"16 停机怠速时间"},       {"16 Stop idle time"},      {"  "},{&Characters_Library_CN[15][0]},{&Characters_Library_EN[15][0]},{ 0},{3600},{   6}, {0},},
 /*-17-*/ {(lPubMenuLabel)sPn_DES_STOPOUTPUT_DEL     , 0x00,  {"17 得电停机时间"},       {"17 ETS solenoid hold"},   {"  "},{&Characters_Library_CN[16][0]},{&Characters_Library_EN[16][0]},{ 0},{ 120},{  10}, {0},},
 /*-18-*/ {(lPubMenuLabel)sPn_DES_STOPSUCC_DEL       , 0x00,  {"18 等待停稳延时"},       {"18 Fail to stop delay"},  {"  "},{&Characters_Library_CN[17][0]},{&Characters_Library_EN[17][0]},{ 0},{ 120},{   1}, {0},},
 /*-19-*/ {(lPubMenuLabel)sPn_GEN_MCBGCB_DEL         , 0x01,  {"19 开关合闸延时"},       {"19 ATS close time"},      {"  "},{&Characters_Library_CN[18][0]},{&Characters_Library_EN[18][0]},{ 0},{ 100},{  50}, {0},},
 /*-20-*/ {(lPubMenuLabel)sPn_DES_GEARTEETH          , 0x00,  {"20 飞轮齿数"},           {"20 Flywheel teeth"},      {"  "},{&Characters_Library_CN[19][0]},{&Characters_Library_EN[19][0]},{10},{ 300},{ 118}, {0},},
 /*-21-*/ {(lPubMenuLabel)sPn_GEN_OBNORMAL_DEL       , 0x01,  {"21 发电异常延时"},       {"21 GenVolt AbnormTime"},  {"  "},{&Characters_Library_CN[20][0]},{&Characters_Library_EN[20][0]},{ 0},{ 200},{ 100}, {0},},
 /*-22-*/ {(lPubMenuLabel)sPn_GEN_VOLTHIGH_STOP      , 0x00,  {"22 发电过压阈值 (停机)"},{"22 Gens over volt"},      {"  "},{&Characters_Library_CN[21][0]},{&Characters_Library_EN[21][0]},{30},{ 360},{ 264}, {0},},
 /*-23-*/ {(lPubMenuLabel)sPn_GEN_VOLTLOW_STOP       , 0x00,  {"23 发电欠压阈值 (停机)"},{"23 Gens under volt"},     {"  "},{&Characters_Library_CN[22][0]},{&Characters_Library_EN[22][0]},{30},{ 360},{ 196}, {0},},
 /*-24-*/ {(lPubMenuLabel)sPn_DES_LOWSPEED           , 0x00,  {"24 欠速阈值 (停机)"},    {"24 Under speed"},         {"  "},{&Characters_Library_CN[23][0]},{&Characters_Library_EN[23][0]},{ 0},{6000},{1200}, {0},},
 /*-25-*/ {(lPubMenuLabel)sPn_DES_HIGHSPEED          , 0x00,  {"25 超速阈值 (停机)"},    {"25 Over speed"},          {"  "},{&Characters_Library_CN[24][0]},{&Characters_Library_EN[24][0]},{ 0},{6000},{1710}, {0},},
 /*-26-*/ {(lPubMenuLabel)sPn_GEN_FREQLOW            , 0x01,  {"26 发电欠频阈值 (停机)"},{"26 Gens under freq"},     {"  "},{&Characters_Library_CN[25][0]},{&Characters_Library_EN[25][0]},{ 0},{ 750},{ 450}, {0},},
 /*-27-*/ {(lPubMenuLabel)sPn_GEN_FREQHIGH           , 0x01,  {"27 发电过频阈值 (停机)"},{"27 Gens over freq"},      {"  "},{&Characters_Library_CN[26][0]},{&Characters_Library_EN[26][0]},{ 0},{ 750},{ 570}, {0},},
 /*-28-*/ {(lPubMenuLabel)sPn_DES_HITEMP             , 0x00,  {"28 高水温阈值 (停机)"},  {"28 High temperature"},    {"  "},{&Characters_Library_CN[27][0]},{&Characters_Library_EN[27][0]},{80},{ 140},{  98}, {0},},
 /*-29-*/ {(lPubMenuLabel)sPn_DES_LOWOP              , 0x00,  {"29 低油压阈值 (停机)"},  {"29 Low oil pressure"},    {"  "},{&Characters_Library_CN[28][0]},{&Characters_Library_EN[28][0]},{ 0},{ 400},{ 103}, {0},},
 /*-30-*/ {(lPubMenuLabel)sPn_DES_LOWLEVEL           , 0x00,  {"30 燃油位阈值 (警告)"},  {"30 Low fuel level"},      {"  "},{&Characters_Library_CN[29][0]},{&Characters_Library_EN[29][0]},{ 0},{ 100},{  10}, {0},},
 /*-31-*/ {(lPubMenuLabel)sPn_DES_LOSTSPEED_DEL      , 0x01,  {"31 速度信号丢失延时"},   {"31 Lost speed delay"},    {"  "},{&Characters_Library_CN[30][0]},{&Characters_Library_EN[30][0]},{ 0},{ 200},{  50}, {0},},
 /*-32-*/ {(lPubMenuLabel)sPn_DES_CHARGEFAULT        , 0x01,  {"32 充电失败阈值 (警告)"},{"32 Charge fail volt"},    {"  "},{&Characters_Library_CN[31][0]},{&Characters_Library_EN[31][0]},{ 0},{ 300},{ 120}, {0},},
 /*-33-*/ {(lPubMenuLabel)sPn_DES_BATTHI             , 0x01,  {"33 电池过压阈值 (警告)"},{"33 Battery over volt"},   {"  "},{&Characters_Library_CN[32][0]},{&Characters_Library_EN[32][0]},{120},{400},{ 320}, {0},},
 /*-34-*/ {(lPubMenuLabel)sPn_DES_BATTLOW            , 0x01,  {"34 电池欠压阈值 (警告)"},{"34 Battery under volt"},  {"  "},{&Characters_Library_CN[33][0]},{&Characters_Library_EN[33][0]},{ 40},{300},{ 200}, {0},},
 /*-35-*/ {(lPubMenuLabel)sPn_GEN_CT                 , 0x00,  {"35 电流互感器变比"},     {"35 CT Rate"},             {"  "},{&Characters_Library_CN[34][0]},{&Characters_Library_EN[34][0]},{ 5},{6000},{ 500}, {0},},
 /*-36-*/ {(lPubMenuLabel)sPn_GEN_RATINGCURRENT      , 0x00,  {"36 满载电流"},           {"36 Full load current"},   {"  "},{&Characters_Library_CN[35][0]},{&Characters_Library_EN[35][0]},{ 5},{6000},{ 500}, {0},},
 /*-37-*/ {(lPubMenuLabel)sPn_GEN_OVERCURRENT        , 0x00,  {"37 过流百分比"},         {"37 Over current"},        {"  "},{&Characters_Library_CN[36][0]},{&Characters_Library_EN[36][0]},{50},{ 130},{ 120}, {0},},
 /*-38-*/ {(lPubMenuLabel)sPn_GEN_OVERCURRENT_DEL    , 0x00,  {"38 过流延时"},           {"38 Over current delay"},  {"  "},{&Characters_Library_CN[37][0]},{&Characters_Library_EN[37][0]},{ 0},{3600},{1296}, {0},},
 /*-39-*/ {(lPubMenuLabel)sPn_DES_FUELPUMP_ON        , 0x00,  {"39 燃油泵开阈值"},       {"39 Fuel pump on"},        {"  "},{&Characters_Library_CN[38][0]},{&Characters_Library_EN[38][0]},{ 0},{ 100},{  25}, {0},},
 /*-40-*/ {(lPubMenuLabel)sPn_DES_FUELPUMP_OFF       , 0x00,  {"40 燃油泵关阈值"},       {"40 Fuel pump off"},       {"  "},{&Characters_Library_CN[39][0]},{&Characters_Library_EN[39][0]},{ 0},{ 100},{  80}, {0},},
 /*-41-*/ {(lPubMenuLabel)sPn_COMMON_OUTPUTFUNC1     , 0x48,  {"41 可编程输出口1设置"},  {"41 Output 1 set"},        {"00"},{&Characters_Library_CN[40][0]},{&Characters_Library_EN[40][0]},{ 0},{  17},{  15}, {0},},
 /*-42-*/ {(lPubMenuLabel)sPn_COMMON_OUTPUTFUNC2     , 0x48,  {"42 可编程输出口2设置"},  {"42 Output 2 set"},        {"01"},{&Characters_Library_CN[41][0]},{&Characters_Library_EN[41][0]},{ 0},{  17},{   2}, {0},},
 /*-43-*/ {(lPubMenuLabel)sPn_COMMON_OUTPUTFUNC3     , 0x48,  {"43 可编程输出口3设置"},  {"43 Output 3 set"},        {"02"},{&Characters_Library_CN[42][0]},{&Characters_Library_EN[42][0]},{ 0},{  17},{   5}, {0},},
 /*-44-*/ {(lPubMenuLabel)sPn_COMMON_OUTPUTFUNC4     , 0x48,  {"44 可编程输出口4设置"},  {"44 Output 4 set"},        {"03"},{&Characters_Library_CN[43][0]},{&Characters_Library_EN[43][0]},{ 0},{  17},{   3}, {0},},
 /*-45-*/ {(lPubMenuLabel)sPn_COMMON_OUTPUTFUNC5     , 0x48,  {"44 可编程输出口5设置"},  {"44 Output 5 set"},        {"12"},{&Characters_Library_CN[43][0]},{&Characters_Library_EN[43][0]},{ 0},{  17},{   0}, {0},},
 /*-46-*/ {(lPubMenuLabel)sPn_COMMON_OUTPUTFUNC6     , 0x48,  {"44 可编程输出口6设置"},  {"44 Output 6 set"},        {"13"},{&Characters_Library_CN[43][0]},{&Characters_Library_EN[43][0]},{ 0},{  17},{   0}, {0},},
 /*-47-*/ {(lPubMenuLabel)sPn_COMMON_INPUTFUNC1      , 0x44,  {"45 可编程输入口1设置"},  {"45 Digit input 1 set"},   {"04"},{&Characters_Library_CN[44][0]},{&Characters_Library_EN[44][0]},{ 0},{  16},{   1}, {0},},
 /*-48-*/ {(lPubMenuLabel)sPn_COMMON_INPUTFUNC1_VALID, 0x08,  {"46 可编程输入口1有效"},  {"46 Digit input 1 act"},   {"05"},{&Characters_Library_CN[45][0]},{&Characters_Library_EN[45][0]},{ 0},{   1},{   0}, {0},},
 /*-49-*/ {(lPubMenuLabel)sPn_COMMON_INPUTFUNC1_DELAY, 0x01,  {"47 可编程输入口1延时"},  {"47 Digit input 1 delay"}, {"  "},{&Characters_Library_CN[46][0]},{&Characters_Library_EN[46][0]},{ 0},{ 200},{  20}, {0},},
 /*-50-*/ {(lPubMenuLabel)sPn_COMMON_INPUTFUNC2      , 0x44,  {"48 可编程输入口2设置"},  {"48 Digit input 2 set"},   {"06"},{&Characters_Library_CN[47][0]},{&Characters_Library_EN[47][0]},{ 0},{  16},{  10}, {0},},
 /*-51-*/ {(lPubMenuLabel)sPn_COMMON_INPUTFUNC2_VALID, 0x08,  {"49 可编程输入口2有效"},  {"49 Digit input 2 act"},   {"07"},{&Characters_Library_CN[48][0]},{&Characters_Library_EN[48][0]},{ 0},{   1},{   0}, {0},},
 /*-52-*/ {(lPubMenuLabel)sPn_COMMON_INPUTFUNC2_DELAY, 0x01,  {"50 可编程输入口2延时"},  {"50 Digit input 2 delay"}, {"  "},{&Characters_Library_CN[49][0]},{&Characters_Library_EN[49][0]},{ 0},{ 200},{  20}, {0},},
 /*-53-*/ {(lPubMenuLabel)sPn_COMMON_INPUTFUNC3      , 0x44,  {"51 可编程输入口3设置"},  {"51 Digit input 3 set"},   {"08"},{&Characters_Library_CN[50][0]},{&Characters_Library_EN[50][0]},{ 0},{  16},{   2}, {0},},
 /*-54-*/ {(lPubMenuLabel)sPn_COMMON_INPUTFUNC3_VALID, 0x08,  {"52 可编程输入口3有效"},  {"52 Digit input 3 act"},   {"09"},{&Characters_Library_CN[51][0]},{&Characters_Library_EN[51][0]},{ 0},{   1},{   0}, {0},},
 /*-55-*/ {(lPubMenuLabel)sPn_COMMON_INPUTFUNC3_DELAY, 0x01,  {"53 可编程输入口3延时"},  {"53 Digit input 3 delay"}, {"  "},{&Characters_Library_CN[52][0]},{&Characters_Library_EN[52][0]},{ 0},{ 200},{  20}, {0},},

/*-59-*/  {(lPubMenuLabel)sPn_DES_STARTINIT          , 0x0c,  {"60 开机状态选择"},       {"60 Module power on"},     {"14"},{&Characters_Library_CN[59][0]},{&Characters_Library_EN[59][0]},{ 0},{   2},{   0}, {0},},
/*-60-*/  {(lPubMenuLabel)sPn_COMMON_ADDR            , 0x00,  {"61 控制器地址"},         {"61 Module Address"},      {"  "},{&Characters_Library_CN[60][0]},{&Characters_Library_EN[60][0]},{ 1},{ 254},{   1}, {0},},
/*-61-*/  {(lPubMenuLabel)sPn_DES_PASSWORD           , 0x00,  {"62 口令设置"},           {"62 Passwords set"},       {"  "},{&Characters_Library_CN[61][0]},{&Characters_Library_EN[61][0]},{ 0},{9999},{4399}, {0},},
/*-62-*/  {(lPubMenuLabel)sPn_DES_STARTSUCC_CONDITION, 0x18,  {"63 起动成功条件"},       {"63 Crank disconnect"},    {"15"},{&Characters_Library_CN[62][0]},{&Characters_Library_EN[62][0]},{ 0},{   5},{   2}, {0},},
/*-63-*/  {(lPubMenuLabel)sPn_DES_STARTSUCC_SPEED    , 0x00,  {"64 起动成功转速"},       {"64 Speed disconnect"},    {"  "},{&Characters_Library_CN[63][0]},{&Characters_Library_EN[63][0]},{ 0},{3000},{ 400}, {0},},
/*-64-*/  {(lPubMenuLabel)sPn_DES_STARTSUCC_FREQ     , 0x01,  {"65 起动成功频率"},       {"65 Freq disconnect"},     {"  "},{&Characters_Library_CN[64][0]},{&Characters_Library_EN[64][0]},{100},{300},{ 140}, {0},},
/*-65-*/  {(lPubMenuLabel)sPn_DES_STARTSUCC_OP       , 0x00,  {"66 起动成功油压"},       {"66 OP disconnect"},       {"  "},{&Characters_Library_CN[65][0]},{&Characters_Library_EN[65][0]},{ 0},{ 400},{ 200}, {0},},
/*-66-*/  {(lPubMenuLabel)sPn_DES_TEMPHIGH_NOSTOP    , 0x08,  {"67 温度高禁止停机选择"}, {"67 Select Inhibit WTH"},  {"16"},{&Characters_Library_CN[66][0]},{&Characters_Library_EN[66][0]},{ 0},{   1},{   0}, {0},},
/*-67-*/  {(lPubMenuLabel)sPn_DES_OPLOW_NOSTOP       , 0x08,  {"68 油压低禁止停机选择"}, {"68 Select Inhibit OPL"},  {"17"},{&Characters_Library_CN[67][0]},{&Characters_Library_EN[67][0]},{ 0},{   1},{   0}, {0},},
/*-68-*/  {(lPubMenuLabel)sPn_GEN_VOLT_TYPE          , 0x0c,  {"69 电压输入选择"},       {"69 Select AC system"},    {"18"},{&Characters_Library_CN[68][0]},{&Characters_Library_EN[68][0]},{ 0},{   2},{   0}, {0},},
/*-69-*/  {(lPubMenuLabel)sPn_DES_TEMP_SENSOR        , 0x2c,  {"70 温度传感器选择"},     {"70 Select temp curve"},   {"19"},{&Characters_Library_CN[69][0]},{&Characters_Library_EN[69][0]},{ 0},{  10},{   2}, {0},},
/*-70-*/  {(lPubMenuLabel)sPn_DES_OP_SENSOR          , 0x2c,  {"71 压力传感器选择"},     {"71 Select press curve"},  {"20"},{&Characters_Library_CN[70][0]},{&Characters_Library_EN[70][0]},{ 0},{  10},{   2}, {0},},

/*-72-*/  {(lPubMenuLabel)sPn_DES_LV_SENSOR          , 0x18,  {"73 液位传感器选择"},     {"73 Select Level curve"},  {"21"},{&Characters_Library_CN[71][0]},{&Characters_Library_EN[71][0]},{ 0},{   5},{   3}, {0},},

/*-75-*/  {(lPubMenuLabel)sPn_GEN_POLENUM            , 0x00,  {"76 发电机极数"},         {"76 Generator Poles"},     {"  "},{&Characters_Library_CN[72][0]},{&Characters_Library_EN[72][0]},{ 2},{  16},{   4}, {0},},
/*-76-*/  {(lPubMenuLabel)sPn_BREAK_TEMP_SENSOR      , 0x0c,  {"77 温度传感器开路动作"}, {"77 Temp.S open action"},  {"26"},{&Characters_Library_CN[76][0]},{&Characters_Library_EN[76][0]},{ 0},{   2},{   1}, {0},},//温度传感器断线动作选择
/*-77-*/  {(lPubMenuLabel)sPn_BREAK_OP_SENSOR        , 0x0c,  {"78 压力传感器开路动作"}, {"78 Oil.S open action"},   {"26"},{&Characters_Library_CN[76][0]},{&Characters_Library_EN[76][0]},{ 0},{   2},{   1}, {0},},//压力传感器断线动作选择
/*-78-*/  {(lPubMenuLabel)sPn_BREAK_LV_SENSOR        , 0x0c,  {"79 液位传感器开路动作"}, {"79 Level.S open action"}, {"26"},{&Characters_Library_CN[76][0]},{&Characters_Library_EN[76][0]},{ 0},{   2},{   0}, {0},},//液位传感器断线动作选择
/*-80-*/  {(lPubMenuLabel)sPn_CUSTOM_SENSOR_TYPE     , 0x0c,  {"81 自定义曲线选择"},     {"81 Defined curve set"},   {"22"},{&Characters_Library_CN[73][0]},{&Characters_Library_EN[73][0]},{ 0},{   2},{   0}, {0},},
/*-81-*/  {(lPubMenuLabel)sPn_GENS_TYPE              , 0x18,  {"82 发动机类型选择"},     {"82 Engine Type"},         {"27"},{&Characters_Library_CN[77][0]},{&Characters_Library_EN[77][0]},{ 0},{   5},{   0}, {0},},//发动机类型选择
	
};                                                                                                                                                      												   
																																																		   

const SubMenu SUBMENU_PARM=                                                                             
{                                                                                                            
  &Page_Status_PARM_CN[0].line1[0],   //1 控制器参数整定   
  &Page_Status_PARM_EN[0].line1[0],
  (lPubMenuLabel)lMainNum_ParmSet,
  sParmSetnum_ForMainPage,            //GEC4xx控参数整定页面数量
  {
  /*-01-*/   &PARAMS_PASS[sPn_MAINS_NORMAL_DEL       ],//市电正常延时        
  /*-02-*/   &PARAMS_PASS[sPn_MAINS_OBNORMAL_DEL     ],//市电异常延时      
  /*-03-*/   &PARAMS_PASS[sPn_MAINS_VOLT_LOW         ],//市电欠压阈值          
  /*-04-*/   &PARAMS_PASS[sPn_MAINS_VOLT_HIGH        ],//市电过压阈值       
  /*-05-*/   &PARAMS_PASS[sPn_MAINS_TRANS_DEL        ],//开关转换延时         
  /*-06-*/   &PARAMS_PASS[sPn_AMF_START_DEL          ],//开机延时           
  /*-07-*/   &PARAMS_PASS[sPn_AMF_STOP_DEL           ],//停机延时            
  /*-08-*/   &PARAMS_PASS[sPn_DES_START_NUM          ],//起动次数 
  /*-09-*/   &PARAMS_PASS[sPn_DES_PREHEAT_DEL        ],//预热时间         
  /*-10-*/   &PARAMS_PASS[sPn_DES_CRANK_DEL          ],//起动时间          
  /*-11-*/   &PARAMS_PASS[sPn_DES_CRANKINT_DEL       ],//起动间隔时间      
  /*-12-*/   &PARAMS_PASS[sPn_DES_SAFE_DEL           ],//安全运行时间
  /*-13-*/   &PARAMS_PASS[sPn_DES_STARTIDLE_DEL      ],//开机怠速时间       
  /*-14-*/   &PARAMS_PASS[sPn_DES_WARM_DEL           ],//暖机时间            
  /*-15-*/   &PARAMS_PASS[sPn_DES_COOLING_DEL        ],//散热时间         
  /*-16-*/   &PARAMS_PASS[sPn_DES_STOPIDLE_DEL       ],//停机怠速时间
  /*-17-*/   &PARAMS_PASS[sPn_DES_STOPOUTPUT_DEL     ],//得电停机时间      
  /*-18-*/   &PARAMS_PASS[sPn_DES_STOPSUCC_DEL       ],//等待停稳延时        
  /*-19-*/   &PARAMS_PASS[sPn_GEN_MCBGCB_DEL         ],//开关合闸延时          
  /*-20-*/   &PARAMS_PASS[sPn_DES_GEARTEETH          ],//飞轮齿数     
  /*-21-*/   &PARAMS_PASS[sPn_GEN_OBNORMAL_DEL       ],//发电异常延时        
  /*-22-*/   &PARAMS_PASS[sPn_GEN_VOLTHIGH_STOP      ],//发电过压阈值停机       
  /*-23-*/   &PARAMS_PASS[sPn_GEN_VOLTLOW_STOP       ],//发电欠压阈值停机        
  /*-24-*/   &PARAMS_PASS[sPn_DES_LOWSPEED           ],//欠速阈值        
  /*-25-*/   &PARAMS_PASS[sPn_DES_HIGHSPEED          ],//超速阈值           
  /*-26-*/   &PARAMS_PASS[sPn_GEN_FREQLOW            ],//发电欠频阈值             
  /*-27-*/   &PARAMS_PASS[sPn_GEN_FREQHIGH           ],//发电过频阈值            
  /*-28-*/   &PARAMS_PASS[sPn_DES_HITEMP             ],//高水温阈值          
  /*-29-*/   &PARAMS_PASS[sPn_DES_LOWOP              ],//低油压阈值               
  /*-30-*/   &PARAMS_PASS[sPn_DES_LOWLEVEL           ],//燃油位阈值            
  /*-31-*/   &PARAMS_PASS[sPn_DES_LOSTSPEED_DEL      ],//速度信号丢失延时       
  /*-32-*/   &PARAMS_PASS[sPn_DES_CHARGEFAULT        ],//充电失败阈值
  /*-33-*/   &PARAMS_PASS[sPn_DES_BATTHI             ],//电池过压阈值              
  /*-34-*/   &PARAMS_PASS[sPn_DES_BATTLOW            ],//电池欠压阈值             
  /*-35-*/   &PARAMS_PASS[sPn_GEN_CT                 ],//电流互感器变比                  
  /*-36-*/   &PARAMS_PASS[sPn_GEN_RATINGCURRENT      ],//满载电流
  /*-37-*/   &PARAMS_PASS[sPn_GEN_OVERCURRENT        ],//过流百分比         
  /*-38-*/   &PARAMS_PASS[sPn_GEN_OVERCURRENT_DEL    ],//过流延时     
  /*-39-*/   &PARAMS_PASS[sPn_DES_FUELPUMP_ON        ],//燃油泵开阈值         
  /*-40-*/   &PARAMS_PASS[sPn_DES_FUELPUMP_OFF       ],//燃油泵关阈值
  /*-41-*/   &PARAMS_PASS[sPn_COMMON_OUTPUTFUNC1     ],//可编程输出1功能      
  /*-42-*/   &PARAMS_PASS[sPn_COMMON_OUTPUTFUNC2     ],//可编程输出2功能      
  /*-43-*/   &PARAMS_PASS[sPn_COMMON_OUTPUTFUNC3     ],//可编程输出3功能      
  /*-44-*/   &PARAMS_PASS[sPn_COMMON_OUTPUTFUNC4     ],//可编程输出4功能
 /*-45-*/	   &PARAMS_PASS[sPn_COMMON_OUTPUTFUNC5     ],//可编程输出5功能
 /*-46-*/	   &PARAMS_PASS[sPn_COMMON_OUTPUTFUNC6     ],//可编程输出6功能
 /*-47-*/    &PARAMS_PASS[sPn_COMMON_INPUTFUNC1      ],//可编程输入1功能       
 /*-48-*/    &PARAMS_PASS[sPn_COMMON_INPUTFUNC1_VALID],//可编程输入1有效 
 /*-49-*/    &PARAMS_PASS[sPn_COMMON_INPUTFUNC1_DELAY],//可编程输入1延时 
 /*-50-*/    &PARAMS_PASS[sPn_COMMON_INPUTFUNC2      ],//可编程输入2功能
 /*-51-*/    &PARAMS_PASS[sPn_COMMON_INPUTFUNC2_VALID],//可编程输入2有效 
 /*-52-*/    &PARAMS_PASS[sPn_COMMON_INPUTFUNC2_DELAY],//可编程输入2延时 
 /*-53-*/    &PARAMS_PASS[sPn_COMMON_INPUTFUNC3      ],//可编程输入3功能       
 /*-54-*/    &PARAMS_PASS[sPn_COMMON_INPUTFUNC3_VALID],//可编程输入3有效
 /*-55-*/    &PARAMS_PASS[sPn_COMMON_INPUTFUNC3_DELAY],//可编程输入3延时 
 /*-56-*/    &PARAMS_PASS[sPn_DES_STARTINIT          ],//开机状态选择        
 /*-57-*/    &PARAMS_PASS[sPn_COMMON_ADDR            ],//控制器地址选择      
 /*-58-*/    &PARAMS_PASS[sPn_DES_PASSWORD           ],//口令设置            
 /*-59-*/    &PARAMS_PASS[sPn_DES_STARTSUCC_CONDITION],//起动成功条件    
 /*-60-*/    &PARAMS_PASS[sPn_DES_STARTSUCC_SPEED    ],//起动成功转速            
 /*-61-*/    &PARAMS_PASS[sPn_DES_STARTSUCC_FREQ     ],//起动成功频率      
 /*-62-*/    &PARAMS_PASS[sPn_DES_STARTSUCC_OP       ],//起动成功油压        
 /*-63-*/    &PARAMS_PASS[sPn_DES_TEMPHIGH_NOSTOP    ],//温度高禁止停机     
 /*-64-*/    &PARAMS_PASS[sPn_DES_OPLOW_NOSTOP       ],//油压低禁止停机      
 /*-65-*/    &PARAMS_PASS[sPn_GEN_VOLT_TYPE          ],//电压输入类型选择    
 /*-66-*/    &PARAMS_PASS[sPn_DES_TEMP_SENSOR        ],//温度传感器选择      
 /*-67-*/    &PARAMS_PASS[sPn_DES_OP_SENSOR          ],//压力传感器选择  
 /*-68-*/    &PARAMS_PASS[sPn_DES_LV_SENSOR          ],//液位传感器选择           
 /*-69-*/    &PARAMS_PASS[sPn_GEN_POLENUM            ],//发电机极数   
 /*-70-*/    &PARAMS_PASS[sPn_BREAK_TEMP_SENSOR      ],//温度传感器断线动作选择
 /*-71-*/    &PARAMS_PASS[sPn_BREAK_OP_SENSOR        ],//压力传感器断线动作选择
 /*-72-*/    &PARAMS_PASS[sPn_BREAK_LV_SENSOR        ],//液位传感器断线动作选择 
 /*-73-*/    &PARAMS_PASS[sPn_CUSTOM_SENSOR_TYPE     ],//自定义曲线序号    
 /*-74-*/    &PARAMS_PASS[sPn_GENS_TYPE              ],//发动机类型选择
 } 
};

const SubMenu SUBMENU_SysMsg=
{
  &Page_Status_PARM_CN[0].line2[0], //2 控制信息  
  &Page_Status_PARM_EN[0].line2[0],
  (lPubMenuLabel)lMainNum_Message,
  SysMsg_num,   //GEC4xx控制信息页面数量
  {
    &PARAMS_SysMsg[0],//&PARAMS_SysMsg[1],
  } 
};

const SubMenu SUBMENU_Language=
{
  &Page_Status_PARM_CN[0].line3[0],  //3 语言选择/Language 
  &Page_Status_PARM_EN[0].line3[0],
  (lPubMenuLabel)lMainNum_Language,
  SysLanguage_num,    //GEC4xx语言信息页面数量, 
  {
    &PARAMS_Language[0],&PARAMS_Language[1],&PARAMS_Language[2],
  } 
};

const MainMenu MAINMENU=
{
  MainPageSUBMENU_NUM,  //参数设置主菜单中子菜单个数
  {
   &SUBMENU_PARM,       //1 控制器参数整定
   &SUBMENU_SysMsg,     //2 控制信息
   &SUBMENU_Language,   //3 语言选择/Language
  }
};

/*----------------------Then End ----------------------*/
