/*
 * IncFile2.h
 *
 * Created: 5/9/2020 8:25:12 PM
 *  Author: Mohamed-Sayed
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#ifndef CTC


#define PWM    8
#define NORMAL 9
#define CTC    10


#endif /*CTC*/

#include <avr/interrupt.h>
#include "Timer_REG.h"
#include "std_types.h"
#include "Commen_Macros.h"
#include "DIO_INIT.h"
#define  F_CPU 1000000UL
typedef enum
{
	NO_CLOCK ,F_CPU_CLOCK , F_CPU_8, F_CPU_32 ,F_CPU_64 , F_CPU_128 , F_CPU_256 , F_CPU_1024
}Timer2_Prescaler;

typedef enum
{
	NORMAL_OC2 , Toggle_OC2 , Clear_OC2_non_inverting , Set_OC2_inverting
}Timer2_COM_Mode;

typedef struct
{
	Timer2_Prescaler clock;
	Timer2_COM_Mode com;
}Timer2_ConfigType;

uint8 Timer2_Get_Value(void);
void Timer2_Stop();

void Timer2_init(const Timer2_ConfigType * Config ,  uint8 Mode, uint8 Top , uint8 CLK_Genration , uint32 CTC_freq , uint8 prescaler);

TIMER2_OVF_Callback(void(*ptr_func)(void));
TIMER2_COMP_Callback(void(*ptr_func)(void));

#endif /* TIMER2_H_ */