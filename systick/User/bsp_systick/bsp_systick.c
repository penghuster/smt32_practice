#include "bsp_systick.h"

u32 timing_delay = 0;

void SysTick_Init()
{
    //SystemFrequency/1000 1ms
    //SystemFrequency/100000 10us
    //SystemFrequency/1000000 1us
    u32 SystemCoreClock = 180e6;
    if(SysTick_Config(SystemCoreClock / 100000))
    {
        while(1);
    }
}


void delay_us(__IO u32 time)
{
    timing_delay = time;
    while(timing_delay != 0);
}



