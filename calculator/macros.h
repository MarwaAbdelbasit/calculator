/*
 * macros.h
 *
 * Created: 08/09/2019 08:32:14 م
 *  Author: new
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define REGISTER_SIZE 8
#define SET_BIT(reg, bit)	reg|=(1<<bit)
#define CLR_BIT(reg, bit)	reg&=(~(1<<bit))
#define	TOG_BIT(reg, bit)	reg^=(1<<bit)
#define READ_BIT(reg, bit)	((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg, bit)	(reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg, bit)	!((reg&(1<<bit))>>bit)
#define ROR(reg, bit)	reg=(reg<<(REGISTER_SIZE-num))|(reg>>(num)))
#define ROL(reg, bit)	reg=(reg>>(REGISTER_SIZE-num))|(reg<<(num)))

#endif /* MACROS_H_ */