#include "SWJ.h"
#include "usart.h"	
#include "stm32f10x_dma.h"

u8 Uart1_dma_tx_buf[50];
u8 Uart1_dma_rx_buf[100];
u16 Uart1_DmaBufLen;
u16 UART1_ReceiveSize = 0;  
u8 TxBuffer[256];
#define BYTE0(dwTemp)       (*(char *)(&dwTemp))
#define BYTE1(dwTemp)       (*((char *)(&dwTemp) + 1))
#define BYTE2(dwTemp)       ( *( (char *)(&dwTemp) + 2) )
#define BYTE3(dwTemp)       ( *( (char *)(&dwTemp) + 3) )

u8 count=0;
uint8_t TxCounter1;
uint8_t TxLen=25; 
uint8_t *TXS;
u8 i;

HMI_data ina219;
void Uart1_Put_Buf(unsigned char *DataToSend , u8 data_num)
{
	for(i=0;i<data_num;i++)
		TxBuffer[count++] = *(DataToSend+i);
	if(!(USART1->CR1 & USART_CR1_TXEIE))
		USART_ITConfig(USART1, USART_IT_TXE, ENABLE); 
}


void Send_RCData(HMI_data data)
{
	u8 data_to_send[30];
	vs16 _temp;
	u8 _cnt=0;
	u8 sum = 0;
/***************************传感器数据****************************/
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0xAA;
	data_to_send[_cnt++]=0x02;
	data_to_send[_cnt++]=0;
	
	data_to_send[_cnt++]=BYTE1(data.ACC_X);
	data_to_send[_cnt++]=BYTE0(data.ACC_X);
	
	data_to_send[_cnt++]=BYTE1(data.ACC_Y);
	data_to_send[_cnt++]=BYTE0(data.ACC_Y);
	
	data_to_send[_cnt++]=BYTE1(data.ACC_Z);
	data_to_send[_cnt++]=BYTE0(data.ACC_Z);
	
	data_to_send[_cnt++]=BYTE1(data.GYRO_X);
	data_to_send[_cnt++]=BYTE0(data.GYRO_X);
	
	data_to_send[_cnt++]=BYTE1(data.GYRO_Y);
	data_to_send[_cnt++]=BYTE0(data.GYRO_Y);
	
	data_to_send[_cnt++]=BYTE1(data.GYRO_Z);
	data_to_send[_cnt++]=BYTE0(data.GYRO_Z);
	
	data_to_send[_cnt++]=BYTE1(data.MAG_X);
	data_to_send[_cnt++]=BYTE0(data.MAG_X);
	
	data_to_send[_cnt++]=BYTE1(data.MAG_Y);
	data_to_send[_cnt++]=BYTE0(data.MAG_Y);
	
	data_to_send[_cnt++]=BYTE1(data.MAG_Z);
	data_to_send[_cnt++]=BYTE0(data.MAG_Z);


	data_to_send[3] = _cnt-4;
	
	
	for( i=0;i<_cnt;i++)
		sum += data_to_send[i];
	data_to_send[_cnt++]=sum;
	

//		TXS=(uint8_t *)data_to_send;   //?TXS?????TxBuffer1
//    TxCounter1=0; 
//		USART_ITConfig(USART1, USART_IT_TXE,ENABLE);   //??TXE??,???????
//		while(TxCounter1!=TxLen);   //??????
	for(i=0;i<_cnt;i++)
	{
		USART_SendData(USART1,data_to_send[i]);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET){}  
	}

	
}

