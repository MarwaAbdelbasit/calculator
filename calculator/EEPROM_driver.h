/*
 * EEPROM_driver.h
 *
 * Created: 03/10/2019 04:48:38 م
 *  Author: new
 */ 


#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_

void EEPROM_write(unsigned short address, unsigned char data);

unsigned char EEPROM_read(const unsigned short address);


#endif /* EEPROM_DRIVER_H_ */