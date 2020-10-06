#ifndef ADC_Lib
#define ADC_Lib

#include "Commen_Macros.h"
#include "std_types.h"
#include "ADC_REG.h"
#define  ADC_INTERRUPT
typedef enum
{
	F_CPU_CLOCK , F_CPU_2, F_CPU_4 , F_CPU_8, F_CPU_16 , F_CPU_32, F_CPU_64 ,F_CPU_128
}ADC_Prescaler;

typedef enum
{
	AREF , AVCC , Reserved , Internal_2_56V
}ADC_REF;

typedef struct 
{
	ADC_Prescaler clock;
	ADC_REF Refrence;
	
}ADC_ConfigType;

void ADC_Init();
#ifndef ADC_INTERRUPT
uint16 ADC_Read(uint8 channel);
#endif


#endif