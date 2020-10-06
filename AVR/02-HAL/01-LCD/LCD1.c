/*
 * LCD.c
 *
 * Created: 5/10/2020 5:08:07 AM
 *  Author: Mohamed-Sayed
 */ 

#include "LCD1.h"
static void Send_A_Pulse (void);
void LCD_init()
{
	DIO_Vid_Set_PIN_DIRICTION(Enable , LCD_Control_PORT , OUTPUT);
	DIO_Vid_Set_PIN_DIRICTION(ReadWrite , LCD_Control_PORT , OUTPUT);
	DIO_Vid_Set_PIN_DIRICTION(RS , LCD_Control_PORT , OUTPUT);
	#if (DATA_BITS_MODE == 4)
		#ifdef UPPER_PORT_PINS
		DIO_Vid_Set_PORT_DIRICTION(LCD_DPORT , 0xF0); /* Configure the highest 4 bits of the data port as output pins */
		#else
		DIO_Vid_Set_PORT_DIRICTION(LCD_DPORT , 0x0F); /* Configure the lowest 4 bits of the data port as output pins */
		#endif
	Send_A_Command(FOUR_BITS_DATA_MODE); 
	_delay_ms(20);
	Send_A_Command(TWO_LINE_LCD_Four_BIT_MODE); 
	_delay_ms(20);
	#elif (DATA_BITS_MODE == 8)
	DIO_Vid_Set_PORT_DIRICTION(LCD_DPORT , 0xFF);
	Send_A_Command(TWO_LINE_LCD_Eight_BIT_MODE); //8-bit mode
	_delay_ms(20);
	#endif
	
	_delay_us(50);
	Send_A_Command(CURSOR_ON);
	_delay_us(50);
	LCD_Clear_Screen();
}

static void Send_A_Pulse()
{
	DIO_Vid_Set_PIN_VALUE(Enable , LCD_Control_PORT , HIGH);
	asm volatile ("nop");
	asm volatile ("nop");
	DIO_Vid_Set_PIN_VALUE(Enable , LCD_Control_PORT , LOW);
}

void Send_A_Command(unsigned char command)
{
	
	DIO_Vid_Set_PIN_VALUE(ReadWrite , LCD_Control_PORT , LOW );
	DIO_Vid_Set_PIN_VALUE(RS , LCD_Control_PORT , LOW);
	_delay_ms(1);
	#if (DATA_BITS_MODE == 4)
		/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
		#ifdef UPPER_PORT_PINS
		DIO_Vid_Set_PORT_MASKING(LCD_DPORT , 0x0F , command & 0xF0);
		#else
		DIO_Vid_Set_PORT_MASKING(LCD_DPORT , 0xF0 , ((command & 0xF0) >> 4));
		#endif
		Send_A_Pulse();
	
		_delay_ms(1);
	
		#ifdef UPPER_PORT_PINS
		DIO_Vid_Set_PORT_MASKING(LCD_DPORT , 0x0F , ((command & 0x0F) << 4));
		#else
		DIO_Vid_Set_PORT_MASKING(LCD_DPORT , 0xF0 , (command & 0x0F));
		#endif
		Send_A_Pulse();	
	    _delay_ms(1);
	#elif (DATA_BITS_MODE == 8)
	_delay_ms(1);
	DIO_Vid_Set_PORT_VALUE(LCD_DPORT , command);
	Send_A_Pulse();	
	DIO_Vid_Set_PORT_VALUE(LCD_DPORT , 0x00);
	#endif

}

void Send_A_Character(unsigned char character)
{
	
	DIO_Vid_Set_PIN_VALUE(ReadWrite , LCD_Control_PORT , LOW );
	DIO_Vid_Set_PIN_VALUE(RS , LCD_Control_PORT , HIGH);
	_delay_ms(1);
	#if (DATA_BITS_MODE == 4)
		/* out the highest 4 bits of the required command to the data bus D4 --> D7 */
		#ifdef UPPER_PORT_PINS
		DIO_Vid_Set_PORT_MASKING(LCD_DPORT , 0x0F , character & 0xF0);
		#else
		DIO_Vid_Set_PORT_MASKING(LCD_DPORT , 0xF0 , ((character & 0xF0) >> 4));
		#endif
		Send_A_Pulse();
		
		_delay_ms(1);
		
		#ifdef UPPER_PORT_PINS
		DIO_Vid_Set_PORT_MASKING(LCD_DPORT , 0x0F , ((character & 0x0F) << 4));
		#else
		DIO_Vid_Set_PORT_MASKING(LCD_DPORT , 0xF0 , (character & 0x0F));
		#endif
		Send_A_Pulse();
		_delay_ms(1);
	#elif (DATA_BITS_MODE == 8)
	_delay_ms(1);
	DIO_Vid_Set_PORT_VALUE(LCD_DPORT , character);
	Send_A_Pulse();
	DIO_Vid_Set_PORT_VALUE(LCD_DPORT , 0x00);
	#endif
}
void Send_A_String(char * string)
{
	while(*string > 0)
	{
		Send_A_Character(*string++);
	}
	
}
void Send_A_String_WithLocation(uint8 x ,uint8 y , char *string)
{
	Gotoloction(x , y);
	Send_A_String(string);
}
int coloms [4]={0,64,20,84};
void Gotoloction(uint8 x ,uint8 y)
{
	Send_A_Command(SET_CURSOR_LOCATION + coloms[y-1] + (x-1));
}

void Send_An_Int_WithLocation(uint8 x ,uint8 y , int DisplyNum , char NumOfDigits)
{
	char CONVERTEDINT [NumOfDigits];
	itoa(DisplyNum , CONVERTEDINT , 10);

	for(uint8 i = 0; i < NumOfDigits ; i++) Send_A_String(" ");
	Send_A_String_WithLocation(x , y , CONVERTEDINT);
}
void LCD_Clear_Screen()
{
	Send_A_Command(CLEAR_SCREEN);
	_delay_ms(2);
}