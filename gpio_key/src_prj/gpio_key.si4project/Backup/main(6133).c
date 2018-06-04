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

void Delay(__IO u32 nCount); 

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
		/* 程序来到main函数之前，启动文件：statup_stm32f429xx.s已经调用
		* SystemInit()函数把系统时钟初始化成180MHZ
		* SystemInit()在system_stm32f4xx.c中定义
		* 如果用户想修改系统时钟，可自行编写程序修改
		*/
		  /* add your code here ^_^. */
	/* LED ????? */
	LED_GPIO_Config();

	/* ??LED? */
	while (1)
	{
		LED1( ON );			 // ? 
		Delay(0xFFFFFF);
		LED1( OFF );		  // ?

		LED2( ON );			// ? 
		Delay(0xFFFFFF);
		LED2( OFF );		  // ?

		LED3( ON );			 // ? 
		Delay(0xFFFFFF);
		LED3( OFF );		  // ?	

		/*???? ??????? ??*/
		LED_RED;
		Delay(0xFFFFFF);
		
		LED_GREEN;
		Delay(0xFFFFFF);
		
		LED_BLUE;
		Delay(0xFFFFFF);
		
		LED_YELLOW;
		Delay(0xFFFFFF);
		
		LED_PURPLE;
		Delay(0xFFFFFF);
				
		LED_CYAN;
		Delay(0xFFFFFF);
		
		LED_WHITE;
		Delay(0xFFFFFF);
		
		LED_RGBOFF;
		Delay(0xFFFFFF);
	}
  	 // while(1);

}

void Delay(__IO uint32_t nCount)	 //???????
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/

