#ifndef I2C_H_
#define I2C_H_ 

#include "Commen_Macros.h"
#include "std_types.h"
#include "I2C_REG.h"


typedef enum
{
	FCPU_CLOCK ,  FCPU_4 ,  FCPU_16 ,  FCPU_64
}I2C_Prescaler;


typedef struct
{
	I2C_Prescaler clock;
	uint8 Slave_address;
	
}I2C_ConfigType;

/* I2C Status Bits in the TWSR Register */
#define I2C_START            0x08 // start has been sent
#define I2C_REPEAT_START     0x10 // repeated start
#define I2C_MT_SLA_W_ACK     0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define I2C_MT_SLA_R_ACK     0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define I2C_MT_DATA_ACK      0x28 // Master transmit data and ACK has been received from Slave.
#define I2C_MR_DATA_ACK      0x50 // Master received data and send ACK to slave
#define I2C_MR_DATA_NACK     0x58 // Master received data but doesn't send ACK to slave

void I2C_Init(uint8 TWBR_Value , const I2C_ConfigType *Config);

void I2C_Start();

void I2C_Stop();

void I2C_Write(uint8 data);

uint8 I2C_Read_With_ACK();

uint8 I2C_Read_With_NACK();

uint8 Check_Status();

#endif  /*I2C_H_*/