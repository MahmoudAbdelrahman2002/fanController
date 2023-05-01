#include "motor.h"
#include "gpio.h"
#include "timer0_pwm.h"
 /******************************************************************************
 *
 * Module: Dc_motor
 *
 * File Name: motor.c
 *
 * Description: control dc_motor by timer0
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/

/*
 * it's a function that initiate the dc moter
 * and his pins
 * */
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(PORTD_ID,MOTOR_PIN1 , PIN_OUTPUT);
	GPIO_setupPinDirection(PORTD_ID,MOTOR_PIN2, PIN_OUTPUT);
	GPIO_writePin(PORTD_ID,MOTOR_PIN1 ,LOGIC_LOW);
	GPIO_writePin(PORTD_ID,MOTOR_PIN2,LOGIC_LOW);
}

/*
 * it's a function that control the direction
 * and speed of motor using pwm signal
 * */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PWM_Timer0_Start(speed);
	if(state==CW)
	{
		GPIO_writePin(PORTD_ID,MOTOR_PIN1 ,LOGIC_LOW);
		GPIO_writePin(PORTD_ID,MOTOR_PIN2,LOGIC_HIGH);
	}
	else if (state==A_CW)
	{
		GPIO_writePin(PORTD_ID,MOTOR_PIN1 ,LOGIC_HIGH);
				GPIO_writePin(PORTD_ID,MOTOR_PIN2,LOGIC_LOW);
	}
	else
	{
		GPIO_writePin(PORTD_ID,MOTOR_PIN1 ,LOGIC_LOW);
			GPIO_writePin(PORTD_ID,MOTOR_PIN2,LOGIC_LOW);
	}


}
