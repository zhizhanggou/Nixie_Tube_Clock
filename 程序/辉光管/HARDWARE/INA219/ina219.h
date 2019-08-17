#ifndef __ina219_H__
#define __ina219_H__

#include "sys.h"
#define SLAVE_ADDRESS 0x80
#define Configuration_Register 0x00
#define Shunt_voltage_Register 0x01
#define Bus_voltage_Register 0x02
#define Current_Register 0x04
#define Calibration_Register 0x05

int ina219_read_voltage(void);
int ina219_read_current(void);
u8 ina219_WriteReg(u8 addr,u8 reg ,u16 Value);
int ina219_ReadReg(u8 addr,u8 reg);
void ina219_init();
#endif