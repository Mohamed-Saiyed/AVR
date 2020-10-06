#ifndef UART_H
#define UART_H

#include "Commen_Macros.h"
#include "UART_REG.h"
#include "std_types.h"
#include <avr/interrupt.h>
void UART_init(uint32 BaudRate);
unsigned char UART_RECEIVE();
void UART_TRANSMIT(char data);
void UART_SEND_STRING(char *str);
void UART_SEND_CONST_STRING(const char *data);
void UART_Set_Callback(void(*a_ptr)(void));


#endif /*UART_H*/