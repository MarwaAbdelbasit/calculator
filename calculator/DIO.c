/*
 * DIO.c
 *
 * Created: 08/09/2019 08:53:50 م
 *  Author: new
 */

#include <avr/io.h>
#include "macros.h"


//1-Function Description : Set the direction of the given pin in the given port (direction 0 = input : 1 = output)
void DIO_set_direction(char port, char pin, char val)
{
	switch(port)
	{
		case 'A':
		case 'a':
			if (val==1)
			{
				DDRA|=(1<<pin);
			}
			else
			{
				DDRA&=(~(1<<pin));
			}
		break;
		
		case 'B':
		case 'b':
			if (val==1)
			{
				DDRB|=(1<<pin);
			}
			else
			{
				DDRB&=(~(1<<pin));
			}
		break;
		
		case 'C':
		case 'c':
			if (val==1)
			{
				DDRC|=(1<<pin);
			}
			else
			{
				DDRC&=(~(1<<pin));
			}
		break;
		
		case 'D':
		case 'd':
			if (val==1)
			{
				DDRD|=(1<<pin);
			}
			else
			{
				DDRD&=(~(1<<pin));
			}
		break;
	}
} 


//2-Function Description : Set the value of the given pin in the given port (outputvalue 0 = low : 1 = high)
void DIO_write(char port, char pin, char val)
{
	switch(port)
	{
		case 'A':
		case 'a':
			if (val==1)
			{
				SET_BIT(PORTA, pin);
			}
			else
			{
				CLR_BIT(PORTA, pin);
			}
		break;
		
		case 'B':
		case 'b':
		if (val==1)
		{
			SET_BIT(PORTB, pin);
		}
		else
		{
			CLR_BIT(PORTB, pin);
		}
		break;	
		
		case 'C':
		case 'c':
		if (val==1)
		{
			SET_BIT(PORTC, pin);
		}
		else
		{
			CLR_BIT(PORTC, pin);
		}
		break;
		
		case 'D':
		case 'd':
		if (val==1)
		{
			SET_BIT(PORTD, pin);
		}
		else
		{
			CLR_BIT(PORTD, pin);
		}
		break;
	}
}


//3-Function Description : Returns 1 if the value of the given pin is high and zero if the value is low
char DIO_read(char port, char pin)
{
	char z=0;
	switch(port)
	{
		case 'A':
		case 'a':
			return z=READ_BIT(PINA, pin);
		break;
		
		case 'B':
		case 'b':
			return z=READ_BIT(PINB, pin);
		break;
		
		case 'C':
		case 'c':
			return z=READ_BIT(PINC, pin);
		break;
		
		case 'D':
		case 'd':
			return z=READ_BIT(PIND, pin);
		break;	
	}
	return z;
}


//4-Function Description : Reverse the value of the given pin in the given port.
void DIO_toggle(char port, char pin)
{
	switch (port)
	{
	case 'A':
	case 'a':
		TOG_BIT(PORTA, pin);
	break;
	
	case 'B':
	case 'b':
		TOG_BIT(PORTB, pin);
	break;
	
	case 'C':
	case 'c':
		TOG_BIT(PORTC, pin);
	break;
	
	case 'D':
	case 'd':
		TOG_BIT(PORTD, pin);
	break;
	}
}


//5-Function Description : set the direction of whole port .
void DIO_set_port_direction(char port, char direction)
{
	switch (port)
	{
		case 'A':
		case 'a':
			DDRA=direction;
		break;
		
		case 'B':
		case 'b':
			DDRB=direction;
		break;
		
		case 'C':
		case 'c':
			DDRC=direction;
		break;
		
		case 'D':
		case 'd':
			DDRD=direction;
		break;	
	}
}


//6-Function Description : Write the value to all port pins.
void DIO_write_port(char port, char val)
{
	switch (port)
	{
		case 'A':
		case 'a':
			PORTA=val;
		break;
		
		case 'B':
		case 'b':
			PORTB=val;
		break;
		
		case 'C':
		case 'c':
			PORTC=val;
		break;
		
		case 'D':
		case 'd':
			PORTD=val;
		break;	
	}
}


//7-Function Description : read the value of the port .
char DIO_read_port(char port)
{
	char z=0;
	switch(port)
	{
		case 'A':
		case 'a':
			return z=PINA;
		break;
		
		case 'B':
		case 'b':
			return z=PINB;
		break;
		
		case 'C':
		case 'c':
			return z=PINC;
		break;	
		
		case 'D':
		case 'd':
			return z=PIND;
		break;
	}
	return z;
}


//8_Connect and disconnect pull up resistor to the given pin at the given port 
void DIO_connect_pullup(char port, char pin, char connect_pullup)
{
	switch(port)
	{
		case 'A':
		case 'a':
			if (connect_pullup == 1)
			{
				SET_BIT(PORTA, pin);
			}
			else
			{
				CLR_BIT(PORTA, pin);
			}
		break;

		case 'B':
		case 'b':
			if (connect_pullup == 1)
			{
				SET_BIT(PORTB, pin);
			}
			else
			{
				CLR_BIT(PORTB, pin);
			}
		break;

		case 'C':
		case 'c':
			if (connect_pullup == 1)
			{
				SET_BIT(PORTC, pin);
			}
			else
			{
				CLR_BIT(PORTC, pin);
			}
		break;

		case 'D':
		case 'd':
			if (connect_pullup == 1)
			{
				SET_BIT(PORTD, pin);
			}
			else
			{
				CLR_BIT(PORTD, pin);
			}
		break;	
	}
}