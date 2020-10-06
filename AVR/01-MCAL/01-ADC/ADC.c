#include "ADC_Lib.h"

/*Initialization of ADC */
void ADC_Init(const ADC_ConfigType *Config)
{
	ADCSRA_REG |=(1<<ADEN) ;/*Enabling ADC*/
	ADCSRA_REG = (ADCSRA_REG & 0xF8) | (Config->clock);/*Setting ADC_prescaler by putting its value at first 3bits*/
	ADMUX_REG = (ADMUX_REG & 0x3F) | ((Config->Refrence)<<6);/*setting ADC Refrence port*/
	#ifndef ADC_INTERRUPT
	ADCSRA_REG |=(1<<ADSC);/*Start ADC conversion*/
	ADCSRA_REG |=(1<<ADIE);/*Enabling ADC interrupt*/
    #endif
}
/*Getting ADC channel value*/
#ifndef ADC_INTERRUPT
uint16 ADC_Read(uint8 channel)
{
	channel &=0x07;/*Making sure we get just first 4 bits*/
	ADMUX_REG = (ADMUX_REG & 0xE0) | (channel);/*specify the channel*/
	
	ADCSRA_REG |=(1<<ADSC);/*Start ADC conversion*/
	while(BIT_IS_CLEAR(ADCSRA_REG , ADIF));/*Wait until conversion is complete*/
	ADCSRA_REG |=(1<<ADIF);/*clearing ADIF flag by Putting 1*/
	/*clearing the flag to be able to read another conversion*/
	return ADC_REG ;/*Returning ADC 10-bit Value*/
}
#endif
