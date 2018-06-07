/*
 * wireless_recv.c
 *
 *  Created on: 2017-4-24
 *      Author: Administrator
 */

#include "wireless_recv.h"
#include "logic.h"



SI_SBIT (RF_PIN, SFR_P0, 0);

typedef struct
{
	uint8_t end_flag;
	uint8_t sync_flag;
	uint16_t sync_time;
	uint16_t rf_data[48];
}RecvData;
static RecvData idata recv_data = {0};



/*start  action  Tsyn-h Tsyn-l  Tlow-h Tlow-l Thigh-h Thigh-l  data1 data2 data3  end*/
//static uint8_t xdata send_data[13] = {0x00};

IrData idata ir_data = {0};


void saveCaptureValue(uint16_t capture_value)
{
	static uint8_t cnt = 0;
	if(!recv_data.sync_flag)
	{
		if(capture_value >= 200 && RF_PIN == 1)
		{
			recv_data.sync_time = capture_value;
			recv_data.sync_flag = true;
		}
	}
	else
	{
		if(recv_data.sync_time > (capture_value * 4))
		{
			recv_data.rf_data[cnt] = capture_value;
			cnt++;
		}
		else
		{
			recv_data.sync_flag = false;
			cnt = 0;
		}
		if(cnt >= 48)
		{
			cnt = 0;
			recv_data.end_flag = true;
			recv_data.sync_flag = false;
		}
	}
}



typedef enum 
{
    STATUS_NO_CLICK             = 0,
    STATUS_FIRST_CLICK          = 1,
    STATUS_PERSIS_CLICK         = 2,    
    STATUS_ERROR                = 0xff,
} rfState;




void analyzeRfData(void)
{
	uint8_t i = 0;
	uint32_t temp = 0;
	uint16_t unit_time = 0;
	uint16_t temp_time = 0;
	uint16_t threshold_time = 0;
	uint16_t sync_threshold = 0;
	uint16_t short_time = 0;
	uint16_t long_time = 0;
    static uint8_t rf_state = STATUS_NO_CLICK;
   
    static uint16_t same_rfvalue_period = 0; 
    static uint32_t last_period   = 0;  
    
    if(recv_data.end_flag == true)
	{
	    recv_data.end_flag = false;
		if(ir_data.cnt == 0)
		{
			ir_data.high_time = recv_data.rf_data[0];
			ir_data.low_time = recv_data.rf_data[1];
			ir_data.sync_time = recv_data.sync_time;
		}
		unit_time = ir_data.high_time + ir_data.low_time;
		threshold_time = unit_time / 4;   //5 
		sync_threshold = ir_data.sync_time / 4;   //5
		for(i = 0; i < 48; i = i + 2)
		{
			temp_time = recv_data.rf_data[i] + recv_data.rf_data[i + 1];
			if((temp_time > unit_time + threshold_time)
				|| (temp_time < unit_time - threshold_time))
			{
				if(++ir_data.timer_cnt>0xff00)
                {
                    ir_data.timer_cnt = 0xff03;
                }
				return;
			}
			if(recv_data.rf_data[i] > recv_data.rf_data[i + 1])
			{
				temp = (temp << 1) | 0x01;
				short_time += recv_data.rf_data[i + 1];
				long_time += recv_data.rf_data[i];
			}
			else if(recv_data.rf_data[i] < recv_data.rf_data[i + 1])
			{
				temp = temp << 1;
				long_time += recv_data.rf_data[i + 1];
				short_time += recv_data.rf_data[i];
			}
			else
			{
				if(++ir_data.timer_cnt>0xff00)
                {
                    ir_data.timer_cnt = 0xff03;
                }
				return;
			}
		}



		if(rf_state == STATUS_NO_CLICK)
		{
		    ir_data.click_flag =true;
            ir_data.psis_click_flag =false;
            ir_data.sync_time = recv_data.sync_time;
            ir_data.ir_data = temp;
            ir_data.cnt = 1;
            ir_data.timer_cnt = 0;
            ir_data.low_time = (uint16_t)((short_time / 24) + 0.5);
            ir_data.high_time = (uint16_t)((long_time / 24) + 0.5);
            rf_state = STATUS_FIRST_CLICK;
		}
        else if(rf_state == STATUS_FIRST_CLICK)
		{
		    if(same_rfvalue_period*2 < 2*last_period/100)
            {   
                if((ir_data.sync_time < threshold_time + recv_data.sync_time			
                    && ir_data.sync_time > recv_data.sync_time - threshold_time         
                    && temp == ir_data.ir_data))
                    {
                        ir_data.cnt++;
                        rf_state = STATUS_PERSIS_CLICK;
                    }
                else
				{
					ir_data.sync_time = recv_data.sync_time;
					ir_data.ir_data = temp;
					ir_data.cnt = 1;
					ir_data.timer_cnt = 0;
					ir_data.low_time = (uint16_t)((short_time / 24) + 0.5);
					ir_data.high_time = (uint16_t)((long_time / 24) + 0.5);
				}


            }      
		}
		else if(rf_state == STATUS_PERSIS_CLICK)
		{
		    ir_data.click_flag =false;
            ir_data.psis_click_flag =false;
		    if(same_rfvalue_period*2 < 2*last_period/100)
            {   
                if((ir_data.sync_time < threshold_time + recv_data.sync_time			
                    && ir_data.sync_time > recv_data.sync_time - threshold_time         
                    && temp == ir_data.ir_data))
                    {
                        if(++ir_data.cnt>=10)
                        {
                            if(ir_data.cnt==10)
                            {
                                ir_data.psis_click_flag =true;
                            }
                            else
                            {
                                ir_data.cnt = 15;
                            }
                        }
                    }
            }
            ir_data.sync_time = recv_data.sync_time;
            ir_data.ir_data = temp;
            //ir_data.cnt = 1;
            ir_data.timer_cnt = 0;
            ir_data.low_time = (uint16_t)((short_time / 24) + 0.5);
            ir_data.high_time = (uint16_t)((long_time / 24) + 0.5);

		}
        same_rfvalue_period = 0;
        last_period = (short_time + long_time)<<2;
	}
	else
	{
        if(++same_rfvalue_period > 150)    
        {       
            same_rfvalue_period = 152; 
            rf_state = STATUS_NO_CLICK;
            ir_data.cnt = 0;
            ir_data.ir_data = 0;
            ir_data.sync_time = 0;
        }
        if(++ir_data.timer_cnt>0xff00)
        {
            ir_data.timer_cnt = 0xff03;
        }
	}
    
}


