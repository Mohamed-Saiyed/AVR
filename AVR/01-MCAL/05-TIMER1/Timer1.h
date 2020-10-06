#ifndef Timer
#define Timer



#ifndef CTC

#define PWM    8
#define NORMAL 9
#define CTC    10

#endif /*CTC*/
#define COM1A    11
#define COM1B    12
#define COM_AB   13

#define  F_CPU 1000000UL
#include <avr/interrupt.h>

#include "Timer_REG.h"
#include "std_types.h"
#include "Commen_Macros.h"
#include "DIO_INIT.h"

typedef enum
{
	 NO_CLOCK ,F_CPU_CLOCK , F_CPU_8, F_CPU_64 ,F_CPU_256 , F_CPU_1024
}Timer1_Prescaler;

typedef enum
{
	NORMAL_OCA , Toggle_OCA , Clear_OCA_non_inverting , Set_OCA_inverting
}Timer1_COMA_Mode;

typedef enum
{
	NORMAL_OCB , Toggle_OCB , Clear_OCB_non_inverting , Set_OCB_inverting
}Timer1_COMB_Mode;

typedef struct
{
	Timer1_Prescaler clock;
	Timer1_COMA_Mode coma;
	Timer1_COMB_Mode comb;
}Timer1_ConfigType;


void Timer1_init(const Timer1_ConfigType * Config , uint8 com , uint8 Mode , uint32 CTC_Top , uint32 PWM_freq, uint32 CTC_freq , uint8 CLK_Generating , uint8 prescaler);


void Duty_cycle(uint8 com , float  COMA_duty_cycle , float  COMB_duty_cycle  );



TIMER1_OVF_Callback(void(*ptr_func)(void));

TIMER1_COMPA_Callback(void(*ptr_func)(void));

TIMER1_COMPB_Callback(void(*ptr_func)(void));

#endif