 /******************************************************************************
 *
 * Module: timer0
 *
 * File Name: timer0_pwm.c
 *
 * Description: for pwm signal
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/


#include "timer0_pwm.h"
#include "avr/io.h"
#include "gpio.h"


void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCCR0=(1<<WGM01)|(1<<WGM00)|(1<<COM01)|(1<<CS01);
	OCR0=(uint8)((duty_cycle*255)/100);
	GPIO_setupPinDirection(PORTB_ID, PIN3_ID,PIN_OUTPUT);
}
