/*
 * DIO.h
 *
 * Created: 08/09/2019 09:49:22 م
 *  Author: new
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_set_direction(char port, char pin, char val);

void DIO_write(char port, char pin, char val);

char DIO_read(char port, char pin);

void DIO_toggle(char port, char pin);

void DIO_set_port_direction(char port, char direction);

void DIO_write_port(char port, char val);

char DIO_read_port(char port);

void DIO_connect_pullup(char port, char pin, char connect_pullup);


#endif /* DIO_H_ */