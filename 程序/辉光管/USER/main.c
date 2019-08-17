#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "SWJ.h"
#include "led.h"
#include "timer.h"
#include "rtc.h" 	
#define SET_FINISH 1
#define SETTTING 2
#define WAIT_SET 0
/************************************************
 ALIENTEK战舰STM32开发板实验23
 IIC 实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

 				 	
	int value=0;
	u8 set_flag=0,set_count=0;
	int bai=0,shi=0,ge=0;
 int main(void)
 {	 
	delay_init();	    	 //延时函数初始化	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	Glow_tube_init();
	RTC_Init();
//	uart_init(115200);
//	TIM3_Int_Init(5000-1,36-1);
//	RTC_Set(2018,5,8,12,25,30); 
	while(1)
	{

	}
}
