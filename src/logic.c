/*
 * logic.c
 *
 *  Created on: 2017-5-2
 *      Author: Administrator
 */


#include "logic.h"
#include "key.h"
#include "wireless_recv.h"
#include "wireless_led.h"
#include "EFM8BB1_FlashPrimitives.h"
#include "EFM8BB1_FlashUtils.h"


#define STORE_NUM_MAX   14
#define SINGLE_LEN  5



#define START_ADDRESS          (0x1600+0x400)


SI_LOCATED_VARIABLE_NO_INIT(flash_write_array[512], uint8_t, SI_SEG_CODE, START_ADDRESS);


DevMode dev_mode = DEV_NORMAL;

uint16_t timerout_cnt = 0;


uint8_t  gSelectChl = 0;

uint8_t chl0_act_period = 0;

uint8_t xdata remote_value_lib[3][71]={0};


static void loadRemoteLib(void)
{
    FLASH_Read(&remote_value_lib[0][0], START_ADDRESS, sizeof(remote_value_lib));
    if(remote_value_lib[0][0] >=3*STORE_NUM_MAX)
    {
        remote_value_lib[0][0] = 0;
    }
    if(remote_value_lib[1][0] >=3*STORE_NUM_MAX)
    {
        remote_value_lib[1][0] = 0;
    }
    if(remote_value_lib[2][0] >=3*STORE_NUM_MAX)
    {
        remote_value_lib[2][0] = 0;
    }
    
    FLASH_PageErase(START_ADDRESS);  
    FLASH_Write(START_ADDRESS, &remote_value_lib[0][0], sizeof(remote_value_lib));
}

static uint8_t checkRemoteValue(IrData irFrm)
{   
    uint8_t hg,le,rtu;
    uint8_t dataH = (irFrm.ir_data>>16)&0x000000ff;
    uint8_t dataM = (irFrm.ir_data>>8)&0x000000ff;
    uint8_t dataL = irFrm.ir_data&0x000000ff;
    uint16_t high_time;

    rtu = 0;
    for(hg =0; hg<3;hg++)
    {
        for(le =0; le<14;le++)
        {
            if(le >= remote_value_lib[hg][0])
            {break;}
            if((remote_value_lib[hg][5*le+3] ==dataH)
            &&(remote_value_lib[hg][5*le+4] ==dataM)
            &&(remote_value_lib[hg][5*le+5] ==dataL)
            )
            {
               high_time = (remote_value_lib[hg][5*le+1]<<8)+ remote_value_lib[hg][5*le+2];
               if(irFrm.high_time < (high_time + high_time/5)
                 &&irFrm.high_time > (high_time - high_time/5)
                 )
                 {
                    rtu |=(1<<hg);
                    break;
                 }
            }
        } 
    }
    return rtu;
}


static void saveToRemoteLib(uint8_t chl,IrData irFrm)
{
    uint8_t value;
    if(chl>2) return;
    value = checkRemoteValue(irFrm);
    if((value&(1<<chl)) ==(1<<chl))
    {
    	chl = chl;
    }
    else
    {
        value = remote_value_lib[chl][0];
        if(value >= 28)     /* 2*STORE_NUM_MAX*/
        {
            value -= STORE_NUM_MAX;
        }
        remote_value_lib[chl][0] = value +1;
        value = value%STORE_NUM_MAX;
        remote_value_lib[chl][1+value*5] = (irFrm.high_time >>8);
        remote_value_lib[chl][2+value*5] = (irFrm.high_time &0xFF);
        remote_value_lib[chl][3+value*5] = ((irFrm.ir_data >>16)&0xFF);
        remote_value_lib[chl][4+value*5] = ((irFrm.ir_data >>8)&0xFF);
        remote_value_lib[chl][5+value*5] = ((irFrm.ir_data )&0xFF);        
        FLASH_PageErase(START_ADDRESS);  
        FLASH_Write(START_ADDRESS, &remote_value_lib[0][0], sizeof(remote_value_lib));
    }
   
}



#if 1
void delay_us(unsigned int k)
{
    while(k--)
    {
        _nop_();_nop_();_nop_();_nop_();
        _nop_();_nop_();_nop_();_nop_();
        _nop_();
    }
}
void delay_1ms()
{
    unsigned int j ;
    for(j=2450;j>0;j--);
}

void delay_ms(unsigned int i)
{
    for(;i>0;i--)delay_1ms();
}
#endif



void setDevMode(DevMode mode)
{
    dev_mode = mode;
    timerout_cnt = 0;
}



static void delNormalEvent(void)
{
    uint8_t value  = 0;
    if(ir_data.click_flag)
	{
	    ir_data.click_flag = false;
		ir_data.timer_cnt = 0;
        value = checkRemoteValue(ir_data);


        if((value&(0x01)) ==(0x01))
        {
        	buzzerTimes(1);
            chl0_act_period = 15;
        }
	}


}

static void delStudyEvent(void)
{
    if(ir_data.click_flag)
    {
    	ir_data.click_flag = false;
	    buzzerTimes(1);
		ir_data.timer_cnt = 0;
        saveToRemoteLib(gSelectChl,ir_data);
		dev_mode = DEV_NORMAL;
	}
	else if(timerout_cnt >= 500)
	{
		dev_mode = DEV_NORMAL;
	}

}

static void delClearEvent(void)
{
    uint8_t cnt;
	if(ir_data.click_flag)
	{
	    ir_data.click_flag = false;
		ir_data.timer_cnt = 0;
        remote_value_lib[gSelectChl][0] = 0;

        for(cnt = 0; cnt<71;cnt++)
        {
            remote_value_lib[gSelectChl][cnt] = 0;
        }
		dev_mode = DEV_NORMAL;
        FLASH_PageErase(START_ADDRESS);  
        FLASH_Write(START_ADDRESS, &remote_value_lib[0][0], sizeof(remote_value_lib));
        buzzerTimes(1);
 
	}
	else if(timerout_cnt >= 500) 
	{
		dev_mode = DEV_NORMAL;
	}
}




static void delTestEvent(void)
{
    uint8_t i,j;
    for(i = 0;i<3 ;i++)
    {
        for(j = 0;j<71 ;j++)
        {
            remote_value_lib[i][j] =i+j;
        }
    }	
    FLASH_PageErase(START_ADDRESS);
    FLASH_Write(START_ADDRESS, &remote_value_lib[0][0], sizeof(remote_value_lib));

    for(i = 0;i<3 ;i++)
    {
        for(j = 0;j<71 ;j++)
        {
            remote_value_lib[i][j] =3;
        }
    }
    FLASH_Read(&remote_value_lib[0][0], START_ADDRESS, sizeof(remote_value_lib));
}



void delEvent(void)
{
	switch(dev_mode)
	{
    	case DEV_NORMAL:
    		delNormalEvent();
    		break;
    	case DEV_STUDY:
    		delStudyEvent();
    		break;
        case DEV_CLEAR:
    		delClearEvent();
    		break;
        case DEV_TEST:
            delTestEvent();
            break;
    	default:
    		break;
	}
}


void devInit(void)
{
	BUZZER = 0;
	IO_WIFI_KEY0 = 1;
	loadRemoteLib();
}
