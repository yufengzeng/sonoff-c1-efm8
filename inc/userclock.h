#ifndef _USERCLOCK_H
#define _USERCLOCK_H

//  包含头文件
//-------------------------------------------------------------------------------------------------

//  变量声明
//-------------------------------------------------------------------------------------------------

extern uint8_t  clk_flag;

#define  FClk_50MS        (clk_flag&0x01)    
#define  FClk_100MS       (clk_flag&0x02)  
#define  FClk_200MS       (clk_flag&0x04)  
#define  FClk_400MS       (clk_flag&0x08)  
#define  FClk_800MS       (clk_flag&0x10)  
#define  FClk_1600MS      (clk_flag&0x20)  
#define  FClk_3200MS      (clk_flag&0x40)  
#define  FClk_6400MS      (clk_flag&0x80)  

//  函数声明
//-------------------------------------------------------------------------------------------------
void getClock(void);

#endif
