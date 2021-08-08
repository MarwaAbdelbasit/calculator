/*
 * calculator.c
 *
 * Created: 24/10/2019 05:21:13 م
 *  Author: new
 */ 


#include <avr/io.h>
#include "keybad_driver.h"
#include "LCD.h"
#include "DIO.h"
#include "macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>


#define DEL_50   50
#define DEL_100 100

int main(void)
{
	LCD_init();
	keybad_init();
	
	char arr[6] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
	short result;
	char i = 0;
	
		for (int x = 0; x<6; x++)
		{
			do
			{
				arr[i] = keybad_check_press();
			} while (arr[i] == 0xff);
			LCD_send_char(arr[i]);
			i++;
			_delay_ms(DEL_50);
		}
		
		LCD_clear_screen();
		
		if (arr[6] == '=')
		{
			//LCD_send_char(arr[i]);
			
			
			if (arr[i-3] == '+')
			{
				arr[i-1] = arr[i-1] - 48;
				arr[i-2] = (arr[i-2]*10) -48;
				arr[i-4] = arr[i-4] - 48;
				arr[i-5] = (arr[i-5]*10) -48;
				
				result = (arr[i-1] + arr[i-4])+(arr[i-2] + arr[i-5]);
				
				LCD_send_string("result=");
				LCD_send_char(result + 48);
			}	
		}
}




