#ifndef RCC_BSP_H
#define RCC_BSP_H


#include "stm32f4xx.h"
void HSE_SetSysClock(uint32_t m, uint32_t n, uint32_t p, uint32_t q);
void HSI_SetSysClock(uint32_t m, uint32_t n, uint32_t p, uint32_t q);
void MCO1_GPIO_Config(void);
void MCO2_GPIO_Config(void);


#endif
