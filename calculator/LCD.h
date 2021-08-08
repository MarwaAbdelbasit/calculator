/*
 * LCD.h
 *
 * Created: 17/10/2019 08:53:16 م
 *  Author: new
 */ 


#ifndef LCD_H_
#define LCD_H_

//#include "LCD_config.h"

/*
#if defined four_bits_mode
 #define EN 0
 #define RS 1
 #define RW 2
 #define FOUR_BITS 0x28
*/



void LCD_init(void);
void send_falling_edge(void);
void LCD_send_cmd(char cmd);
void LCD_send_char(char data);
void LCD_send_string(char *data);
void LCD_clear_screen(void);
void LCD_move_cursor(char row, char column);

#endif /* LCD_H_ */