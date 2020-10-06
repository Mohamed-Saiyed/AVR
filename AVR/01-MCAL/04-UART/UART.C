#include <math.h>
#define F_CPU 8000000UL	
#include <util/delay.h>/*include delay library for _delay_us*/

#include "UART.h"
#include <avr/interrupt.h>

static volatile void (*g_callBackPtr)(void);

void UART_init(uint32 BaudRate)
{
	sei();
	uint32 UBRR_VALUE = lrint((F_CPU/(16*BaudRate))-1);/*math EQU to set UBBR RIGSTER value*/
	UBRRL_REG =(uint8)UBRR_VALUE; /*writing first 8 bits of UBRR to UBRRL*/
	UBRRH_REG =(uint8)(UBRR_VALUE>>8);/*writing last 8 bits of UBRR to UBRRL*/
	SET_BIT(UCSRB_REG,RXEN);/*UART receive enable*/
	SET_BIT(UCSRB_REG,TXEN);/*UART TRANSMITING enable*/
	SET_BIT(UCSRB_REG,RXCIE);/*UART receive INT enable*/
	UCSRC_REG |=(3<<UCSZ0) | (1<<URSEL);/*UART is working in 8-bit mode*/
	/*URSEL bit must be set to one one writing in UCSRC register*/
	
}
unsigned char UART_RECEIVE()
{
	while(BIT_IS_CLEAR(UCSRA_REG , RXC ));/*wait till data is completely received*/
	return UDR_REG;/*returning data received*/
}
void UART_TRANSMIT(char data)
{
	
	while(BIT_IS_CLEAR(UCSRA_REG , UDRE));/*wait until the transmit buffer (UDR) is ready to receive new data*/
	UDR_REG = data;
	_delay_us(700);/*a delay just for higher MCU FREQU*/
}

void UART_SEND_STRING(char *str)
{
	int i =0;/*COUNTER FOR data CHAR ARRAY*/
	/*SENDING data STRING CHAR BY CAHR TILL REACHS THE END \0*/
	while(str[i]!=0)
	{
		UART_TRANSMIT(str[i]);
		i++;
		
	}
	
}

void UART_SEND_CONST_STRING(const char *data)
{
	while(*data > 0)
	{
		UART_TRANSMIT(*data++);
	}
}

void UART_Set_Callback(void(*a_ptr)(void))
{
	g_callBackPtr = a_ptr ;
}

ISR(USART_RXC_vect)
{
	(*g_callBackPtr)();
}	