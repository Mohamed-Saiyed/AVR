/*
 * IncFile1.h
 *
 * Created: 5/9/2020 12:00:11 AM
 *  Author: Mohamed-Sayed
 */ 


#ifndef I2C_REG_H_
#define I2C_REG_H_



#define TWBR_REG             (*(volatile uint8*)(0x20))
#define TWSR_REG             (*(volatile uint8*)(0x21))
#define TWAR_REG             (*(volatile uint8*)(0x22))
#define TWDR_REG             (*(volatile uint8*)(0x23))
#define TWCR_REG             (*(volatile uint8*)(0x56))

/*TWSR Bits*/
#define TWS7    7
#define TWS6    6
#define TWS5    5 
#define TWS4    4
#define TWS3    3
/*Bit 2 is Reserved*/
#define TWPS1   1
#define TWPS0   0


/*TWAR Bits*/
#define TWA6     7
#define TWA5     6
#define TWA4     5
#define TWA3     4
#define TWA2     3
#define TWA1     2
#define TWA0     1
#define TWGCE    0


/*TWCR Bits*/
#define TWINT     7
#define TWEA     6
#define TWSTA     5
#define TWSTO     4
#define TWWC     3
#define TWEN     2
/*Bit 1 is Reserved*/
#define TWIE    0

#endif /* I2C_REG_H_ */