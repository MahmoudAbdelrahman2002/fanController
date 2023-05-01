#include "adc.h"
#include "lcd.h"
#include "motor.h"
uint8 temp;
void main()
{
	ADC_ConfigType confg={INTERNAL,Prescaler_8};
	/* configration for adc*/
	ADC_init(&confg);
	/* initiate adc module*/
	LCD_init();
	/*initiate lcd*/
	LCD_clearScreen();
	/*clear screen*/
	DcMotor_Init();
	while(1)
	{

		LCD_moveCursor(0, 5);
		/*set the cursor to row 0 and column 5*/
		temp=LM35_getTemperature();
		/*reading temperature from the sensor*/
		if(temp<30)
		{

			LCD_displayString("FAN OFF");
			LCD_displayStringRowColumn(1,3,"temp =");
			LCD_intgerToString(temp);

		}
		else if((temp>=30)&&temp<60)
		{

			LCD_displayString("FAN ON");
			LCD_displayStringRowColumn(1,3,"temp =");
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 25);
		}
		else if((temp>=60)&&temp<90)
		{

			LCD_displayString("FAN ON");
			LCD_displayStringRowColumn(1,3,"temp =");
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 50);
		}
		else if((temp>=90)&&temp<120)
		{

			LCD_displayString("FAN ON");
			LCD_displayStringRowColumn(1,3,"temp =");
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 75);
		}
		else if((temp>=120)&&temp<150)
		{

			LCD_displayString("FAN ON");
			LCD_displayStringRowColumn(1,3,"temp =");
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 100);
		}
	}
}
