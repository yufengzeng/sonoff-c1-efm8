/*
 * wireless_led.c
 *
 *  Created on: 2017-3-29
 *      Author: Administrator
 */
#include "wireless_led.h"

static uint8_t bibi_time = 0;

void buzzerTimes(uint8_t times)
{
    bibi_time = times;
}


void buzzerScan(void)
{
    static uint8_t buzzCnt = 0;
    if(bibi_time == 0)
    {
        return;
    }
    ++buzzCnt;
    if(buzzCnt== 1)
    {
        BUZZER = 1;
    }
    else if(buzzCnt== 40)
    {
    	BUZZER = 0;
    }
    else if(buzzCnt== 80)
    {
        buzzCnt = 0;
        bibi_time--;
    }
    
}





