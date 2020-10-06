/*
 * IncFile1.h
 *
 * Created: 5/9/2020 8:25:03 PM
 *  Author: Mohamed-Sayed
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_


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
	NO_CLOCK ,F_CPU_CLOCK , F_CPU_8, F_CPU_64 ,F_CPU_256 , F_CPU_1024
}Timer0_Prescaler;

typedef enum
{
	NORMAL_OC0 , Toggle_OC0 , Clear_OC0_non_inverting , Set_OC0_inverting
}Timer0_COM_Mode;

typedef struct
{
	Timer0_Prescaler clock;
	Timer0_COM_Mode com;
}Timer0_ConfigType;


void Timer0_init(const Timer0_ConfigType * Config , uint8 Mode,uint8 Top , uint8 CLK_Genration , uint32 CTC_freq , uint8 prescaler);
TIMER0_OVF_Callback(void(*ptr1_func)(void));

TIMER0_COMP_Callback(void(*ptr_func)(void));

uint8 Time01_Get_Value(void);
void Timer0_Stop();

#endif /* TIMER0_H_ */