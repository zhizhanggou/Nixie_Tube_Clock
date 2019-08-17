#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "oled.h" 
#include "delay.h"
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
								    
//按键初始化函数
void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能PORTA,PORTE时钟

//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;//KEY0-KEY2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOE2,3,4

}
u8 KEY_Scan(u8 mode)
{	 
	u8 temp=0;
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按
	ROW_OUT();
	delay_us(10);
	PBout(8)=0;PBout(9)=0;PBout(10)=0;PBout(11)=0;PBout(12)=1;PBout(13)=1;PBout(14)=1;
	COL_IN();
	if(key_up&&(PBin(8)==1||PBin(9)==1||PBin(10)==1||PBin(11)==1))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		OLED_Clear();
		if(PBin(8)==1)temp=1;
		else if(PBin(9)==1)temp=4;
		else if(PBin(10)==1)temp=7;
		else if(PBin(11)==1)temp=10;
		
		COL_OUT();
		delay_us(10);
		PBout(8)=1;PBout(9)=1;PBout(10)=1;PBout(11)=1;PBout(12)=0;PBout(13)=0;PBout(14)=0;
		ROW_IN();
		if(PBin(12)==1)
			return temp;
		else if(PBin(13)==1)
			return temp+=1;
		else if(PBin(14)==1)
			return temp+=2;
		
	}
	else if(PBin(8)==0&&PBin(9)==0&&PBin(10)==0&&PBin(11)==0)
		key_up=1; 	    
 	return 0;// 无按键按下
}
