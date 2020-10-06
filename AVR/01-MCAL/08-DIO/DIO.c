#include "DIO_INIT.h"

void DIO_Vid_Set_PIN_DIRICTION(uint8 PinNumber , uint8 PortNumber , uint8 Diriction)
{
	switch(PortNumber)
	{
		case PORTA :
			if(Diriction == OUTPUT)
			{
			     SET_BIT(DDRA_REG , PinNumber) ;
			} 
			else if(Diriction == INPUT)
			{
				CLEAR_BIT(DDRA_REG , PinNumber);
			}
		
		break;
		case PORTB :
			if(Diriction == OUTPUT)
			{
				SET_BIT(DDRB_REG , PinNumber) ;
			}
			else if(Diriction == INPUT)
			{
				CLEAR_BIT(DDRB_REG , PinNumber);
			}
		break;
		case PORTC :
			if(Diriction == OUTPUT)
			{
				SET_BIT(DDRC_REG , PinNumber) ;
			}
			else if(Diriction == INPUT)
			{
				CLEAR_BIT(DDRC_REG , PinNumber);
			}
		break;
		case PORTD :
			if(Diriction == OUTPUT)
			{
				SET_BIT(DDRD_REG , PinNumber) ;
			}
			else if(Diriction == INPUT)
			{
				CLEAR_BIT(DDRD_REG , PinNumber);
			}
		break;
	}
}
void DIO_Vid_Set_PIN_VALUE(uint8 PinNumber , uint8 PortNumber , uint8 Value)
{
	switch(PortNumber)
	{
		case PORTA :
		if(Value == HIGH)
		{
			SET_BIT(PORTA_REG , PinNumber) ;
		}
		else if(Value == LOW)
		{
			CLEAR_BIT(PORTA_REG , PinNumber);
		}
		break;
		case PORTB :
		if(Value == HIGH)
		{
			SET_BIT(PORTB_REG , PinNumber) ;
		}
		else if(Value == LOW)
		{
			CLEAR_BIT(PORTB_REG , PinNumber);
		}
		break;
		case PORTC :
		if(Value == HIGH)
		{
			SET_BIT(PORTC_REG , PinNumber) ;
		}
		else if(Value == LOW)
		{
			CLEAR_BIT(PORTC_REG , PinNumber);
		}
		break;
		case PORTD :
		if(Value == HIGH)
		{
			SET_BIT(PORTD_REG , PinNumber) ;
		}
		else if(Value == LOW)
		{
			CLEAR_BIT(PORTD_REG , PinNumber);
		}
		break;
	}
}

void DIO_Vid_Set_PORT_DIRICTION(uint8 PortNumber , uint8 Diriction)
{
	switch(PortNumber)
	{
		case PORTA :
		    DDRA_REG |= Diriction;
		break;
		case PORTB :
			DDRC_REG |= Diriction;
		break;
		case PORTC :
			DDRC_REG |= Diriction;
		break;
		case PORTD :
			DDRD_REG |= Diriction;
		break;
	}
}

void DIO_Vid_Set_PORT_VALUE(uint8 PortNumber , uint8 Value)
{
	switch(PortNumber)
	{
		case PORTA :
			PORTA_REG |= Value;
		break;
		case PORTB :
			PORTB_REG |= Value;
		break;
		case PORTC :
			PORTC_REG |= Value;
		break;
		case PORTD :
	       PORTD_REG |= Value;
		break;
	}
}

uint8 DIO_U8Get_Pin_Value(uint8 PinNumber , uint8 PortNumber)
{
	switch(PortNumber)
	{
		case PORTA:
		         if (BIT_IS_CLEAR(PINA_REG , PinNumber))
		         {
					 return 0 ;
		         } 
		         else if (BIT_IS_SET(PINA_REG , PinNumber))
		         {
					 return 1 ;
		         }
		break;
		case PORTB:
				if (BIT_IS_CLEAR(PINB_REG , PinNumber))
				{
					return 0 ;
				}
				else if (BIT_IS_SET(PINB_REG , PinNumber))
				{
					return 1 ;
				}
		break;
		case PORTC:
				if (BIT_IS_CLEAR(PINC_REG , PinNumber))
				{
					return 0 ;
				}
				else if (BIT_IS_SET(PINC_REG , PinNumber))
				{
					return 1 ;
				}
		break;
		case PORTD:
				if (BIT_IS_CLEAR(PIND_REG , PinNumber))
				{
					return 0 ;
				}
				else if (BIT_IS_SET(PIND_REG , PinNumber))
				{
					return 1 ;
				}
		break;
	}
}

void DIO_Vid_Set_PORT_MASKING(uint8 PortNumber , uint8 Mask , uint8 data)
{
	switch(PortNumber)
	{
		case PORTA :
		PORTA_REG  = (PORTA_REG & Mask)  | (data);
		break;
		case PORTB :
		PORTB_REG = (PORTB_REG & Mask)  | (data);
		break;
		case PORTC :
		PORTC_REG = (PORTC_REG & Mask)  | (data);
		break;
		case PORTD :
		PORTD_REG = (PORTD_REG & Mask)  | (data);
		break;
	}
}







