/*
 * wireless_led.h
 *
 *  Created on: 2017-3-29
 *      Author: Administrator
 */

#ifndef WIRELESS_LED_H_
#define WIRELESS_LED_H_

#include <SI_EFM8BB1_Register_Enums.h>




SI_SBIT (BUZZER, SFR_P1,0);


void buzzerScan(void);
void buzzerTimes(uint8_t);


 
#endif /* WIRELESS_LED_H_ */
