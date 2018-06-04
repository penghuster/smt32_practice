#ifndef BSP_KEY_H
#define BSP_KEY_H

#include "stm32f4xx.h"

#define KEY1_PIN GPIO_Pin_0
#define KEY1_GPIO_PORT  GPIOA
#define KEY1_GPIO_CLK   RCC_AHB1Periph_GPIOA

#define KEY2_PIN  GPIO_Pin_13
#define KEY2_GPIO_PORT  GPIOC 
#define KEY2_GPIO_CLK   RCC_AHB1Periph_GPIOC

#define KEY_ON 1
#define KEY_OFF 0

void key_gpio_config(void);
uint8_t key_scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);


#endif

