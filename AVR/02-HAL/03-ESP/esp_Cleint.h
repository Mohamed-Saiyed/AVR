#ifndef esp_Cleint_H_
#define esp_Cleint_H_


#include "UART.h"
#include "DIO_INIT.h"
#include "LCD1.h"
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>

extern char  rx_buffer[500];

void Get_data_Recieved(char *txt);
void WIFI_Config();
uint16 Get_data_Send_Size(char *txt);
void Send_Data(uint16_t data_Send_Value);


#endif