/*
 * logic.h
 *
 *  Created on: 2017-5-2
 *      Author: Administrator
 */

#ifndef LOGIC_H_
#define LOGIC_H_

#include <SI_EFM8BB1_Register_Enums.h>

typedef enum
{
	DEV_NORMAL = 0,
	DEV_STUDY  = 1,
	DEV_CLEAR  = 2,
	DEV_TEST   = 0xff,
}DevMode;


void devInit(void);
void delEvent(void);
void setDevMode(DevMode);
void delEspKey(void);




void delay_us(unsigned int);
void delay_1ms();
void delay_ms(unsigned int);



extern uint16_t timerout_cnt;
extern DevMode dev_mode;
extern uint8_t  gSelectChl;


extern uint8_t chl0_act_period;
extern volatile uint8_t clkIntCnt;


#endif /* LOGIC_H_ */
