/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   用1.5.1版本库建的工程模板
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "bsp_led.h"
#include "rcc_bsp.h"

void Delay(__IO u32 nCount); 

int main(void)
{
    HSE_SetSysClock(25, 180, 2, 7);
	LED_GPIO_Config();
    MCO1_GPIO_Config();
    MCO2_GPIO_Config();

    RCC_MCO1Config(RCC_MCO1Source_PLLCLK,  RCC_MCO1Div_2);
    RCC_MCO2Config(RCC_MCO2Source_SYSCLK,  RCC_MCO1Div_2);

	while (1)
	{
		LED1( ON );			 // ? 
		Delay(0xFFFFFF);
		LED1( OFF );		  // ?

		LED2( ON );			// ? 
		Delay(0xFFFFFF);
		LED2( OFF );		  // ?

	}
  	 // while(1);

}

void Delay(__IO uint32_t nCount)	 //???????
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/

