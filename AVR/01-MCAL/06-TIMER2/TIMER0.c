/*
 * CFile1.c
 *
 * Created: 5/9/2020 8:24:48 PM
 *  Author: Mohamed-Sayed
 */ 

#include "TIMER0.h"

static volatile void(*TIMER0_COMP_Call_back_ptr)(void);
static volatile void(*TIMER0_OVF_Call_back_ptr)(void);


void Timer0_init(const Timer0_ConfigType * Config , uint8 Mode,uint8 Top , uint8 CLK_Genration , uint32 CTC_freq , uint8 prescaler)
{
	TCCR0_REG = (TCCR0_REG & 0xF8) | (Config->clock);
	TCCR0_REG = (TCCR0_REG & 0xCF) | ((Config->com) << 4);
	if(Mode == PWM)
	{
		TCCR0_REG |=(1<<WGM00) | (1<<WGM01);
	}
	else if(Mode == NORMAL)
	{
		TCCR0_REG &=~(1<<WGM00) | (1<<WGM01);
		TCCR0_REG |=(1<<FOC0);
		TIMSK_REG  |=(1<<TOIE0);
		TCNT0_REG = 0 ;
		sei();
		
	}
	else if(Mode == CTC)
	{
		TCCR0_REG |=(1<<WGM01);
		TCCR0_REG |=(1<<FOC0);
		if (CLK_Genration == 0)
		{
			TIMSK_REG |=(1<<OCIE0);
			TCNT0_REG= 0 ;
			OCR0_REG = Top;
			sei();
		}
		else if (CLK_Genration == 1)
		{
			uint64 Math = 2 * (prescaler) * CTC_freq ;
			uint8 OC0_TOP = (F_CPU / Math) - 1;
			DDRB_REG |=(1<<PB3);
			TCNT1_REG = 0 ;
			OCR0_REG = OC0_TOP ;
			
			
		}
		
	}
}

uint8 Timer0_Get_Value(void)
{
	return TCNT0_REG;
}

void Timer0_Stop()
{
	TCCR0_REG = 0x00;
	
}
TIMER0_COMP_Callback(void(*ptr_func)(void))
{
	TIMER0_COMP_Call_back_ptr = ptr_func ;
}
TIMER0_OVF_Callback(void(*ptr1_func)(void))
{
	TIMER0_OVF_Call_back_ptr = ptr1_func ;
}

ISR(TIMER0_COMP_vect)
{
	(*TIMER0_COMP_Call_back_ptr)();
}


ISR(TIMER0_OVF_vect)
{
	(*TIMER0_OVF_Call_back_ptr)();
}