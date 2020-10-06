/*
 * CFile1.c
 *
 * Created: 5/9/2020 12:00:01 AM
 *  Author: Mohamed-Sayed
 */ 
#include "I2C.h"
void I2C_Init(uint8 TWBR_Value , const I2C_ConfigType *Config)
{
	
	TWSR_REG = (TWSR_REG & 0xFC) | (Config->clock); /*Setting I2C clock Prescaler*/
	TWBR_REG = TWBR_Value;
	TWAR_REG = Config->Slave_address ;/*Setting your slave address */
	TWCR_REG =(1<<TWEN);/*Enabling I2C*/
}
void I2C_Start()
{
	TWCR_REG = (1<<TWEN) |(1<<TWINT) | (1<<TWSTA);
	/**Enable I2C
	*Clearing Interrupt flag
	*Sending a start bit to be master*/
	while(!(TWCR_REG &(1<<TWINT)));/*wait until action is completed*/
}
void I2C_Stop()
{
	TWCR_REG = (1<<TWEN) |(1<<TWINT) | (1<<TWSTO);
	/**Enable I2C
	*Clearing Interrupt flag
	*Sending a stop bit to end  being a  master*/
}
void I2C_Write(uint8 data)
{
	TWDR_REG = data;/*Writing a byte in data register*/
	TWCR_REG = (1<<TWEN) |(1<<TWINT);
	/**Enable I2C
	*Clearing Interrupt flag*/
	
	while(!(TWCR_REG &(1<<TWINT)));/*wait until data is written*/
}
uint8 I2C_Read_With_ACK()
{
	TWCR_REG = (1<<TWEN) |(1<<TWINT) |(1<<TWEA);
	/**Enable I2C
	*Clearing Interrupt flag
	*Enable responding with an ACK*/
	while(!(TWCR_REG &(1<<TWINT)));/*wait until data is received*/
	return TWDR_REG;
}

uint8 I2C_Read_With_NACK()
{
	TWCR_REG = (1<<TWEN) |(1<<TWINT);
	/**Enable I2C
	*Clearing Interrupt flag
	*Enable responding with an NACK 'NACK means no need for other master's data'*/
	while(!(TWCR_REG &(1<<TWINT)));/*wait until data is received*/
	return TWDR_REG;
}
uint8 Check_Status()
{
	uint8 Status;
	Status = TWSR_REG & 0xF8;/*Masking for last 6 status register*/
	return Status;/*return statues of the action*/
}
