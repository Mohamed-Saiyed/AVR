/*
 * CFile2.c
 *
 * Created: 5/9/2020 8:24:57 PM
 *  Author: Mohamed-Sayed
 */ 
#include "TIMER2.h"
static volatile void(*TIMER2_COMP_Call_back_ptr)(void);

static volatile void(*TIMER2_OVF_Call_back_ptr)(void);


void Timer2_init(const Timer2_ConfigType * Config ,  uint8 Mode, uint8 Top , uint8 CLK_Genration , uint32 CTC_freq , uint8 prescaler)
{
	TCCR2_REG = (TCCR2_REG & 0xF8) | (Config->clock);
	TCCR2_REG = (TCCR2_REG & 0xCF) | ((Config->com) << 4 );
	if(Mode == PWM)
	{
		TCCR2_REG |=(1<<WGM20) | (1<<WGM21);
	}
	else if(Mode == NORMAL)
	{
		TCCR2_REG &=~(1<<WGM20) | (1<<WGM21);
		TCCR2_REG |=(1<<FOC2);
		TIMSK_REG  |=(1<<TOIE2);
		TCNT2_REG = 0 ;
		sei();
	}
	else if(Mode == CTC)
	{
		TCCR2_REG |=(1<<WGM21);
		TCCR2_REG |=(1<<FOC2);
		if (CLK_Genration == 0)
		{
			TIMSK_REG |=(1<<OCIE2);
			TCNT2_REG= 0 ;
			OCR2_REG = Top;
			sei();
		}
		else if (CLK_Genration == 1)
		{
			uint64 Math = 2 * (prescaler) * CTC_freq ;
			uint8 OC2_TOP = (F_CPU / Math) - 1;
			DDRD_REG |=(1<<PD7);
			TCNT2_REG = 0 ;
			OCR2_REG = OC2_TOP ;
			
			
		}
	}
}

uint8 Timer2_Get_Value(void)
{
	return TCNT2_REG;
}

void Timer2_Stop()
{
	TCCR2_REG = 0x00;
}



TIMER2_OVF_Callback(void(*ptr_func)(void))
{
	TIMER2_OVF_Call_back_ptr = ptr_func ;
}

TIMER2_COMP_Callback(void(*ptr_func)(void))
{
	TIMER2_COMP_Call_back_ptr = ptr_func ;
}


ISR(TIMER2_COMP_vect)
{
	(*TIMER2_COMP_Call_back_ptr)();
}


ISR(TIMER2_OVF_vect)
{
	(*TIMER2_OVF_Call_back_ptr)();
}