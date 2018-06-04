#ifndef BSP_SYSTICK_H
#define BSP_SYSTICK_H

#include "stm32f4xx.h"

void SysTick_Init(void);
void delay_us(__IO u32 time);



#endif 

