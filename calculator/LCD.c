/*
 * LCD.c
 *
 * Created: 17/10/2019 09:05:27 م
 *  Author: new
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"

#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38

void LCD_init(void)
{
	_delay_ms(200);
	DIO_set_port_direction('A', 1);
	DIO_set_direction('B', EN, 1);
	DIO_set_direction('B', RS, 1);
	DIO_set_direction('B', RW, 1);
	DIO_write('B', RW, 0);
	
	LCD_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	
	LCD_send_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	
	//LCD_send_cmd(CLR_SCREEN);
	//_delay_ms(1);
	
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	
	/*
	#elif defined four_bits_mode
	DIO_set_direction('A', 4, 1);
	DIO_set_direction('A', 5, 1);
	DIO_set_direction('A', 6, 1);
	DIO_set_direction('A', 7, 1);
	DIO_set_direction('B', EN, 1);
	DIO_set_direction('B', RS, 1);
	DIO_set_direction('B', RW, 1);
	DIO_write('B', RW, 0);
	
	LCD_send_cmd(RETURN_HOME);
	_delay_ms(10);
	
	LCD_send_cmd(FOUR_BITS);
	_delay_ms(1);
	
	LCD_send_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(1);
	
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	*/

}

void send_falling_edge(void)
{
	DIO_write('B', EN, 1);
	_delay_ms(2);
	DIO_write('B', EN, 0);
	_delay_ms(2);
}

void LCD_send_cmd(char cmd)
{
	DIO_write_port('A', cmd);
	DIO_write('B', RS, 0);
	send_falling_edge();
	
	/*
	#elif defined four_bits_mode
	//write_high_nibble('A', cmd>>4);
	DIO_write('B', RS, 0);
	send_falling_edge();
	//write_high_nibble('A', cmd);
	DIO_write('B', RS, 0);
	send_falling_edge();
	_delay_ms(1);
	#endif
	*/
}

void LCD_send_char(char data)
{
	DIO_write_port('A', data);
	DIO_write('B', RS, 1);
	send_falling_edge();
	
	/*
	#elif defined four_bits_mode
	//write_high_nibble('A', data>>4);
	DIO_write('B', RS, 1);
	send_falling_edge();
	//write_high_nibble('A', data);
	DIO_write('B', RS, 1);
	send_falling_edge();
	_delay_ms(1);
	#endif
	*/
}

void LCD_send_string(char *data)
{
	while ((*data)!='\0')
	{
		LCD_send_char(*data);
		data++;
	}
}

void LCD_clear_screen(void)
{
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_move_cursor(char row, char column)
{
	char data = 0;
	if(row>2 || row<1 || column>16 || column<1)
	{
		data = 0x80;
	}
	else if (row == 1)
	{
		data = 0x80 + column-1;
	}
	else if (row == 2)
	{
		data = 0xc0 + column-1;
	}
	LCD_send_cmd(data);
	_delay_ms(1);
}