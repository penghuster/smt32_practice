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

void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
		/* ��������main����֮ǰ�������ļ���statup_stm32f429xx.s�Ѿ�����
		* SystemInit()������ϵͳʱ�ӳ�ʼ����180MHZ
		* SystemInit()��system_stm32f4xx.c�ж���
		* ����û����޸�ϵͳʱ�ӣ������б�д�����޸�
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

