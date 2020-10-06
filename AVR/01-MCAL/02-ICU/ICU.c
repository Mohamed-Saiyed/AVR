#include "ICU.h"

static volatile void (*g_callBackPtr)(void);


ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
void Icu_setCallBack(void(*a_ptr)(void))
{
	/* Save the address of the Call back function in a global variable */
	g_callBackPtr = a_ptr;
}

void ICU_init(const ICU_CONFIG * CONFIG)
{
	DDRD_REG &=~(1<<PD6);/*setting ICP1 as input pin*/
	TCCR1A_REG |=(1<<FOC1A) | (1<<FOC1B);/*non PWM mode*/
	/*ICU is working in Timer normal mode*/
	TCCR1B_REG =(TCCR1B_REG & 0xF8) | (CONFIG ->clock);/*configuration of timer prescaler*/
	TCCR1B_REG = (TCCR1B_REG & 0xBF) | ((CONFIG->edge) << 6);/*configuration of ICU edge (Falling or Rising)*/
	TCNT1_REG = 0 ; /**/
	ICR1_REG = 0 ;/**/
	TIMSK_REG |=(1<<TICIE1);/*Enable timer 1 Over flow interrupt*/
}
void ICU_Edge_select(const ICU_EDGE_TYPE select_edge)
{
	TCCR1B_REG = (TCCR1B_REG & 0xBF) | ((select_edge) << 6);
}

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_Get_ICU_VALUE()
{
	return ICR1_REG;
}

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_CLEAR_TIMER()
{
	TCNT1_REG = 0 ;
}
/*Deinit ICU prephrial*/


void ICU_Deinit()
{
	/* Clear All Timer1 Registers */
	TCCR1B_REG = 0x00;
    TCNT1_REG = 0 ; 
	ICR1_REG = 0;
	
	/* Disable the Input Capture interrupt */
	TIMSK_REG &=~(1<<TICIE1);
}
