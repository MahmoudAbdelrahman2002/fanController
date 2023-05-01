 /******************************************************************************
 *
 * Module: Dc_motor
 *
 * File Name: motor.h
 *
 * Description: control dc_motor by timer0
 *
 * Author: Mahmoud Abdelrahman
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
typedef enum
{
	CW,A_CW,STOP
}DcMotor_State;
#define MOTOR_PIN1 PIN6_ID
#define MOTOR_PIN2 PIN7_ID
 void DcMotor_Rotate(DcMotor_State state,uint8 speed);

void DcMotor_Init(void);


#endif /* MOTOR_H_ */
