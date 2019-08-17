#ifndef __SWJ_H
#define __SWJ_H		
#include "sys.h"
#include "usart.h"
//#define RECEIVE_BUF_SIZE 100
typedef struct HMI
{
	int ACC_X;
	int ACC_Y;
	int ACC_Z;
	int GYRO_X;
	int GYRO_Y;
	int GYRO_Z;
	int MAG_X;
	int MAG_Y;
	int MAG_Z;
}HMI_data;
extern HMI_data ina219;
//void ANO_DT_Send_Status(float angle_rol, float angle_pit, float angle_yaw, s32 alt, u8 fly_model, u8 armed);
void Send_RCData(HMI_data data);
void Uart1_Put_Buf(unsigned char *DataToSend , u8 data_num);
#endif
