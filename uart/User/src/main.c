/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ��1.5.1�汾�⽨�Ĺ���ģ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_debug_usart.h"

void Delay(__IO u32 nCount); 

int main(void)
{

	Debug_USART_config();
	USART_sendString(DEBUG_USART, "this is a usart echo.");
	while(1);
}

void Delay(__IO uint32_t nCount)	 //???????
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/

