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
#include "bsp_key.h"
#include "bsp_led.h"

void Delay(__IO u32 nCount); 

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
    LED_GPIO_Config();
    key_gpio_config();

    while(1){
        if(key_scan(KEY1_GPIO_PORT, KEY1_PIN) == KEY_ON)
            LED1_TOGGLE;

        if(key_scan(KEY2_GPIO_PORT, KEY2_PIN) == KEY_OFF)
            LED2_TOGGLE;
    }

}

void Delay(__IO uint32_t nCount)	 //???????
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/

