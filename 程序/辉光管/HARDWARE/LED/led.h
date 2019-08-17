#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
typedef enum
{
   TUBE_1=1,TUBE_2,TUBE_3,TUBE_4,TUBE_5,TUBE_6
} TUBEn_e;

void Glow_tube_init(void);
void Choose_num(int show_num);
void Choose_tube(TUBEn_e tube_num);		 
void Glow_tube_Show_num(TUBEn_e tube_num,int show_num); //辉光管显示数字，tube_num为辉光管编号，show_num为要显示数字
#endif
