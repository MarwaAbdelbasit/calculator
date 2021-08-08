/*
 * keybad_driver.c
 *
 * Created: 23/10/2019 07:58:27 م
 *  Author: new
 */ 

#include "keybad_driver.h"
#include "DIO.h"

void keybad_init(void) 
{
	DIO_set_direction('D', 0, 1);
	DIO_set_direction('D', 1, 1);
	DIO_set_direction('D', 2, 1);
	DIO_set_direction('D', 3, 1);
	DIO_set_direction('D', 4, 0);
	DIO_set_direction('D', 5, 0);
	DIO_set_direction('D', 6, 0);
	DIO_set_direction('D', 7, 0);
	DIO_connect_pullup('D', 4, 1);
	DIO_connect_pullup('D', 5, 1);
	DIO_connect_pullup('D', 6, 1);
	DIO_connect_pullup('D', 7, 1);
}

char keybad_check_press(void)
{
	char arr[4][4] = {{'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, {'A', '0', '=', '+'}};
	char row, col, x;
	char returnval = 0xff;
	
	for (row = 0; row<4; row++)
	{
		DIO_write('D', 0, 1);
		DIO_write('D', 1, 1);
		DIO_write('D', 2, 1);
		DIO_write('D', 3, 1);
		DIO_write('D', row, 0);
		
		for (col = 0; col<4; col++)
		{
			x = DIO_read('D', (col+4));
			if (x==0)
			{
				returnval = arr[row][col];
				break;
			}
		}
		if (x==0)
		{
			break;
		}
	}
	return returnval;
}













