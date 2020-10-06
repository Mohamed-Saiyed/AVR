#ifndef LCD_H_
#define LCD_H_

#include <util/delay.h>
#include <stdlib.h>

#include "DIO_INIT.h"

#define DATA_BITS_MODE 8

#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif



#define LCD_DPORT              PORTB
#define LCD_Control_PORT       PORTA
#define Enable     0
#define ReadWrite  1
#define RS         2

#define TWO_LINE_LCD_Eight_BIT_MODE    0x38
#define CURSOR_OFF                     0x0C
#define CLEAR_SCREEN                   0x01
#define CURSOR_ON                      0x0E
#define SET_CURSOR_LOCATION            0x80
#define FOUR_BITS_DATA_MODE            0x02
#define TWO_LINE_LCD_Four_BIT_MODE     0x28

void LCD_init(void);
void Send_A_Command(unsigned char command);
void Send_A_Character(unsigned char character);
void Send_A_String(char *string);
void Send_A_String_WithLocation(uint8 x ,uint8 y , char *string);
void Gotoloction(uint8 x ,uint8 y);
void Send_An_Int_WithLocation(uint8 x ,uint8 y , int DisplyNum , char NumOfDigits);
void DIO_Vid_Set_PORT_MASKING(uint8 PortNumber , uint8 Mask , uint8 data);

#endif /*LCD_H_*/