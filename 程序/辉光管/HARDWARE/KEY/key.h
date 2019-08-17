#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//按键驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PEin(4)   	//PE4
//#define KEY1 PEin(3)	//PE3 
//#define KEY2 PEin(2)	//PE2
//#define WK_UP PAin(0)	//PA0  WK_UP

//#define KEY0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)//读取按键0
//#define KEY1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)//读取按键1
//#define KEY2  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)//读取按键2 
//#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键3(WK_UP) 



#define ROW_IN()  {GPIOB->CRH&=0XF000FFFF;GPIOB->CRH|=(u32)8<<24;GPIOB->CRH|=(u32)8<<20;GPIOB->CRH|=(u32)8<<16;}
#define ROW_OUT() {GPIOB->CRH&=0XF000FFFF;GPIOB->CRH|=(u32)3<<24;GPIOB->CRH|=(u32)3<<20;GPIOB->CRH|=(u32)3<<16;}

#define COL_IN()  {GPIOB->CRH&=0XFFFF0000;GPIOB->CRH|=(u32)8<<12;GPIOB->CRH|=(u32)8<<8;GPIOB->CRH|=(u32)8<<4;GPIOB->CRH|=(u32)8;}
#define COL_OUT() {GPIOB->CRH&=0XFFFF0000;GPIOB->CRH|=(u32)3<<12;GPIOB->CRH|=(u32)3<<8;GPIOB->CRH|=(u32)3<<4;GPIOB->CRH|=(u32)3;}

#define KEY0_PRES 	8	//KEY0按下
#define KEY1_PRES	9	//KEY1按下
#define KEY2_PRES	10	//KEY2按下
#define WKUP_PRES   11	//KEY_UP按下(即WK_UP/KEY_UP)


void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);  	//按键扫描函数					    
#endif
