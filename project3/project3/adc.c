 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: reading analog signal
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/
#include "adc.h"
#include "avr/io.h"
#include "common_macros.h"
 /******************************************************************************
 * int function
 * this function initiate the adc
 * by setting refernce volt and prescaler
 *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX=(ADMUX&0x3f)|((Config_Ptr->ref_volt)<<6);
	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADCSRA,ADIE);
	ADCSRA=(ADCSRA&0x8f)|(Config_Ptr->prescaler);
}
/******************************************************************************
* ADC_readChannel function
* this function convert analog signal to digital
*
*******************************************************************************/
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX=(ADMUX&0xe0)|channel_num;
	SET_BIT(ADCSRA, ADSC)/* start conversion*/;
	while(BIT_IS_CLEAR(ADCSRA,ADIF));/*polling until flag is set two one*/
	SET_BIT(ADCSRA,ADIF);/*clear flag*/
	return ADC;
}
