/*
 * wireless_recv.h
 *
 *  Created on: 2017-4-24
 *      Author: Administrator
 */

#ifndef WIRELESS_RECV_H_
#define WIRELESS_RECV_H_

#include "stdint.h"
#include <SI_EFM8BB1_Register_Enums.h>

typedef struct
{
	uint16_t sync_time;
	uint16_t high_time;
	uint16_t low_time;
	uint32_t ir_data;
	uint8_t cnt;           /*correct frame num*/
	uint16_t timer_cnt;    /*up time*/

    uint8_t click_flag;
    uint8_t psis_click_flag;
}IrData;

extern IrData idata ir_data;

void saveCaptureValue(uint16_t capture_value);
void analyzeRfData(void);

#endif /* WIRELESS_RECV_H_ */
