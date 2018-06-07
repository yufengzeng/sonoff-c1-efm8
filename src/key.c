
#include "key.h"
#include "logic.h"
#include "wireless_led.h"



uint16_t sKeyCnt;
uint8_t gValue;


SI_SBIT (IO_KEY_CH0, SFR_P0, 7);

uint8_t GetKey(void)
{
	uint8_t gTemp = 0;
	uint8_t toESPKey0Flag = 1;

    if(!IO_KEY_CH0)
    {
       toESPKey0Flag = 0; 
       gTemp |= 0x01;
    }
 
    if(dev_mode == DEV_NORMAL)
    {
        if(chl0_act_period)
        {
            chl0_act_period --;
            toESPKey0Flag = 0;
        }
    }
    else
    {
        chl0_act_period = 0;
    }
   
    
    if(toESPKey0Flag)
    {
        IO_WIFI_KEY0 = 1;
    }
    else
    {
        IO_WIFI_KEY0 = 0;
    }

	if(gTemp)
	{
		gValue = gTemp;
		sKeyCnt++;

		if(sKeyCnt >=350)   //3s 300
		{
		    gTemp =gTemp|L_KEY_MASK;
		    if(sKeyCnt ==350)
		    {
		    	return (gTemp);
		    }
        }
        if(sKeyCnt >=550)  //5s 500
		{
		    gTemp =gTemp|LL_KEY_MASK;
		    if(sKeyCnt ==550)
		    {
				return (gTemp);
			}
		    sKeyCnt = 555;
        }
	}
	else 
	{
	    if((sKeyCnt <300)&&(sKeyCnt >=4))
	    {
	        sKeyCnt = 0;
	        return (gValue);
	    }
	    else
	    {
	        sKeyCnt = 0;
	    }
	}
	return N_KEY;
}





void Key_Action(void)
{
	uint8_t gTemp;
	gTemp = GetKey();
	if(gTemp == N_KEY) {;}		
	else if(gTemp == S_KEY_CH0)  
	{
        ;
	}	
	else if(gTemp == L_KEY_CH0)   
	{
        gSelectChl = 0;
        setDevMode(DEV_STUDY);
        buzzerTimes(1);
	}	
		
	else if(gTemp == LL_KEY_CH0)   
	{
        gSelectChl = 0;
        buzzerTimes(2);
        setDevMode(DEV_CLEAR);
	}	
}

