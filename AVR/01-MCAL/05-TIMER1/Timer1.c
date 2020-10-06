/*
 * CFile1.c
 *
 * Created: 5/9/2020 4:22:37 AM
 *  Author: Mohamed-Sayed
 */ 
#include "Timer1.h"


static volatile void(*TIMER1_OVF_Call_back_ptr)(void);

static volatile void(*TIMER1_COMPB_Call_back_ptr)(void);
static volatile void(*TIMER1_COMPA_Call_back_ptr)(void);

void Timer1_init(const Timer1_ConfigType * Config , uint8 com , uint8 Mode , uint32 CTC_Top , uint32 PWM_freq, uint32 CTC_freq , uint8 CLK_Generating , uint8 prescaler)
{
	TCCR1B_REG = (TCCR1B_REG & 0xF8) | (Config->clock);
	if (com == COM1A)
	{
		TCCR1A_REG = (TCCR1A_REG & 0x3F) | ((Config->coma) << 6);
	} 
	else if(com == COM1B)
	{
		TCCR1A_REG = (TCCR1A_REG & 0xCF) | ((Config->comb) << 4);
	}
	else if(com == COM_AB)
	{
		TCCR1A_REG = (TCCR1A_REG & 0x3F) | ((Config->coma) << 6);
		TCCR1A_REG = (TCCR1A_REG & 0xCF) | ((Config->comb) << 4);
	}
	if(Mode == PWM)
	{

		DDRD_REG |=(1<<PD5);
		DDRD_REG |=(1<<PD4);
		TCCR1A_REG |=(1<<WGM11);
		TCCR1B_REG |=(1<<WGM12) |(1<<WGM13);
		int TOP = 	(F_CPU/(PWM_freq*prescaler )- 1);
		ICR1_REG = TOP ;
	}
	else if(Mode == NORMAL)
	{
		TCCR1A_REG &=~(1<<WGM11)  | (1<<WGM10);
		TCCR1B_REG &=~(1<<WGM12)  | (1<<WGM13);
		TCCR1A_REG |=(1<<FOC1A) | (1<<FOC1B);
		TCNT1_REG = 0;
		TIMSK_REG  |=(1<<TOIE1);
		sei();
	}
	else if(Mode == CTC)
	{
		
		TCCR1A_REG |=(1<<FOC1A) | (1<<FOC1B);
		TCCR1B_REG |=(1<<WGM12);
		if (CLK_Generating == 1)
		{
			uint32 Math = 2 * (prescaler) * CTC_freq ;
			uint16 OCA_TOP = (F_CPU / Math) - 1;
				if (com == COM1A)
				{
					DDRD_REG |=(1<<PD5);
				}
				else if (com == COM1B)
				{
					DDRD_REG |=(1<<PD4);
					
				}
				else if (com == COM_AB)
				{
					DDRD_REG |=(1<<PD4);
					DDRD_REG |=(1<<PD5);
				}
				TCNT1_REG = 0 ;
				OCR1A_REG = OCA_TOP;
		}
		if (CLK_Generating == 0)
		{
			if (com == COM1A)
			{
				TIMSK_REG  |=(1<<OCIE1A);
			}
			else if(com == COM1B)
			{
				TIMSK_REG  |=(1<<OCIE1B);
			}
			else if(com == COM_AB)
			{
				TIMSK_REG  |=(1<<OCIE1A);
				TIMSK_REG  |=(1<<OCIE1B);
			}
			TCNT1_REG = 0 ;
			OCR1A_REG = CTC_Top;
			sei();
		}
		
		
		
	}
	
		
}


void Duty_cycle(uint8 com , float  COMA_duty_cycle , float  COMB_duty_cycle  )
{
	if (com == COM1A)
	{
		OCR1A_REG = ICR1_REG * COMA_duty_cycle;
	}
	else if (com == COM1B)
	{
		(OCR1B_REG = ICR1_REG * COMB_duty_cycle);
	}
	else if (com == COM_AB)
	{
		OCR1A_REG = ICR1_REG * COMA_duty_cycle;
		(OCR1B_REG = ICR1_REG * COMB_duty_cycle);
	}

}

uint16 Timer1_Get_Value(void)
{
	return TCNT1_REG;
}

void Timer1_Stop()
{
	TCCR1A_REG = 0x00;
	TCCR1B_REG = 0x00;
}


void TIMER1_OVF_Callback(void(*ptr_func)(void))
{
	TIMER1_OVF_Call_back_ptr = ptr_func ;
}

void TIMER1_COMPA_Callback(void(*ptr_func)(void))
{
	TIMER1_COMPA_Call_back_ptr = ptr_func ;
}
void TIMER1_COMPB_Callback(void(*ptr_func)(void))
{
  TIMER1_COMPB_Call_back_ptr = ptr_func ;	
}

ISR(TIMER1_OVF_vect)
{
	(*TIMER1_OVF_Call_back_ptr)();
}


ISR(TIMER1_COMPA_vect)
{
	(*TIMER1_COMPA_Call_back_ptr)();
}


ISR(TIMER1_COMPB_vect)
{
	(*TIMER1_COMPB_Call_back_ptr)();
}
