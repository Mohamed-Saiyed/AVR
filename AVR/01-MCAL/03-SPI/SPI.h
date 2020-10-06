#ifndef SPI_H_
#define SPI_H_


#include "DIO_INIT.h"/*importing DIO registers and functions and macros */
#include "SPI_REG.h" /*importing SPI registers*/

void SPI_MASTER_INIT();/*SETTING MASTER MCU SETTINGS*/
void SPI_SLAVE_INIT();/*SETTING SLAVE MCU SETTINGS*/

void SPI_SEND(uint8 data);

uint8 SPI_RECEIVE();

void SPI_SEND_STRING(char *data);

#endif /*SPI_H_*/
