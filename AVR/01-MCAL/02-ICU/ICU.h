#ifndef ICU__H_
#define ICU__H_

#include "Timer_REG.h"
#include "DIO_INIT.h"
#include <avr/interrupt.h>
#define NULL 0 
typedef enum Clock
{
	NO_CLOCK,F_CPU_1,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_CLOCK;
typedef enum edge
{
	FALLING,RISING
}ICU_EDGE_TYPE;

typedef struct
{
	ICU_CLOCK clock;
	ICU_EDGE_TYPE edge;
}ICU_CONFIG;

void ICU_CLEAR_TIMER();
void ICU_Deinit();
uint16 ICU_Get_ICU_VALUE();
void ICU_Edge_select(const ICU_EDGE_TYPE select_edge);
void ICU_init(const ICU_CONFIG * CONFIG);
void Icu_setCallBack(void(*a_ptr)(void));

#endif /*ICU__H_*/