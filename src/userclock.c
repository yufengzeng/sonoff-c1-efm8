#include "logic.h"
#include "userclock.h"
//  全局变量


//-------------------------------------------------------------------------------------------------
uint8_t  clk_flag = 0;
static uint8_t  clk_cnt = 0;


//  软件配置
//-------------------------------------------------------------------------------------------------
#define SYS_CNT_50MS  5      // fClkIntCnt 1MS的计数次数  根据定时器变化

//-------------------------------------------------------------------------------------------------
//  函数名称: void getClock(void);
//  函数功能: 获取时钟标志
//  输入参数: FClk_1msInt     SYS_CNT_1MS
//  输出参数: fClkFlag0 fClkFlag1
//-------------------------------------------------------------------------------------------------

void getClock(void)
{
  uint8_t temp;
  clk_flag = 0;
  if(clkIntCnt >= SYS_CNT_50MS)
  {
    clkIntCnt -= SYS_CNT_50MS;
    temp = clk_cnt;
    clk_flag  = temp ^ (++clk_cnt);
  }
}

