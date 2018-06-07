/*
 * wireless_led.c
 *
 *  Created on: 2017-3-29
 *      Author: Administrator
 */
#include "wireless_led.h"
#include "userclock.h"


static uint8_t bibi_time = 0;

void buzzerTimes(uint8_t times)
{
    bibi_time = times;
}


void buzzerScan(void)
{
    static uint8_t buzzCnt = 0;

    if(!FClk_50MS)
    {
        return;
    }
    if(bibi_time == 0)
    {
        return;
    }
    ++buzzCnt;
    if(buzzCnt== 1)
    {
        BUZZER = 1;
    }
    else if(buzzCnt== 8)
    {
    	BUZZER = 0;
    }
    else if(buzzCnt== 16)
    {
        buzzCnt = 0;
        bibi_time--;
    }
    
}





