//**************************************************公用文件夹********************************************************************
//简介：存放部分通用的函数，积累通用函数
//时间：2017/07/23

#include "public.h"

//******************************************************************
//while循环，占用CPU起到延时作用，不精确  
//如要产生1s延时，需要计算keil运行时间，而且不准确。
//在此芯片stm32f103中可采用sysTic定时器计时
//******************************************************************
void delay(u32 i)	 
{
	while(i--);
}


