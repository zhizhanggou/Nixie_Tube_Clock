#include "ina219.h"
#include "sys.h"
#include "myiic.h"
void ina219_init()
{
	ina219_WriteReg(SLAVE_ADDRESS,Configuration_Register,0x0667);
	ina219_WriteReg(SLAVE_ADDRESS,Calibration_Register,0x5477);
}
int ina219_read_voltage()
{
	int temp;
	temp=ina219_ReadReg(SLAVE_ADDRESS,Bus_voltage_Register);
}
int ina219_read_current()
{
	int temp;
	temp=ina219_ReadReg(SLAVE_ADDRESS,Current_Register);
}
int ina219_ReadReg(u8 addr,u8 reg)
{
	int temp;
	IIC_Start();
	IIC_Send_Byte(addr);	   //·¢ËÍÐ´ÃüÁî
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);	   //·¢ËÍ¶ÁÃüÁî
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte(addr|1);	   //·¢ËÍ¶ÁÃüÁî
	IIC_Wait_Ack();
	temp=IIC_Read_Byte(1);	     //·¢ËÍÓ¦´ð
	temp=temp<<8;
	temp+=IIC_Read_Byte(0);	   
	IIC_Stop();
	return temp;
}
u8 ina219_WriteReg(u8 addr,u8 reg ,u16 Value)
{
	u8 error;
	IIC_Start();
	IIC_Send_Byte(addr);	   //·¢ËÍÐ´ÃüÁî
	error=IIC_Wait_Ack();
	if(!error)
	{
		IIC_Send_Byte(reg);	   //·¢ËÍÐ´ÃüÁî
		error=IIC_Wait_Ack();
		IIC_Send_Byte( (Value & 0xff00)>>8 );	   //·¢ËÍÐ´ÃüÁî
		error=IIC_Wait_Ack();
		IIC_Send_Byte( Value & 0x00ff );	   //·¢ËÍÐ´ÃüÁî
		error=IIC_Wait_Ack();
	}
	IIC_Stop();
	return error;
}