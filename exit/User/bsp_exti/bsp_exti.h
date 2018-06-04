#ifndef BSP_EXTI_H
#define BSP_EXTI_H

#include "stm32f4xx.h"

#define KEY1_INT_GPIO_PORT   GPIOA
#define KEY1_INT_GPIO_CLK    RCC_AHB1Periph_GPIOA
#define KEY1_INT_GPIO_PIN   GPIO_Pin_0
#define KEY1_INT_EXTI_PORTRESOURCE       EXTI_PortSourceGPIOA
#define KEY1_INT_EXTI_PINRESOURCE        EXTI_PinSource0
#define KEY1_INT_EXTI_IRQ               EXTI0_IRQn

#define KEY1_IRQHandler         EXTI0_IRQHandler

#define KEY2_INT_GPIO_PORT   GPIOC
#define KEY2_INT_GPIO_CLK    RCC_AHB1Periph_GPIOC
#define KEY2_INT_GPIO_PIN   GPIO_Pin_13
#define KEY2_INT_EXTI_PORTRESOURCE       EXTI_PortSourceGPIOC
#define KEY2_INT_EXTI_PINRESOURCE        EXTI_PinSource13
#define KEY2_INT_EXTI_IRQ               EXTI15_10_IRQn

#define KEY2_IRQHandler         EXTI15_10_IRQHandler


void EXTI_Key_Config(void);

#endif

