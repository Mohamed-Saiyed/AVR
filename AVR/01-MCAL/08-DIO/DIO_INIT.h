#ifndef DIO_INIT_H
#define DIO_INIT_H

#define OUTPUT 1
#define INPUT  0

#define HIGH 1
#define LOW  0

#define PORTA 0
#define PORTB 1 
#define PORTC 3
#define PORTD 4

#include "Commen_Macros.h"
#include "DIO_REG.h"
#include "std_types.h"

void DIO_Vid_Set_PIN_DIRICTION(uint8 PinNumber , uint8 PortNumber , uint8 Diriction);
void DIO_Vid_Set_PIN_VALUE(uint8 PinNumber , uint8 PortNumber , uint8 Value);

void DIO_Vid_Set_PORT_DIRICTION(uint8 PortNumber , uint8 Diriction);
void DIO_Vid_Set_PORT_VALUE(uint8 PortNumber , uint8 Value);



uint8 DIO_U8Get_Pin_Value(uint8 PinNumber , uint8 PortNumber);
	




#endif