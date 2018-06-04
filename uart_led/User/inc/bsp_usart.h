#ifndef BSP_USART_H
#define BSP_USART_H

#include "stm32f4xx.h"

#define USARTX USART1
#define USARTX_CLK     RCC_APB2Periph_USART1
#define USARTX_BANDRATE  115200

#define USARTX_RX_GPIO_PORT   GPIOA
#define USARTX_RX_GPIO_CLK    RCC_AHB1Periph_GPIOA
#define USARTX_RX_PIN		   GPIO_Pin_10 
#define USARTX_RX_AF          GPIO_AF_USART1
#define USARTX_RX_SOURCE      GPIO_PinSource10

#define USARTX_TX_GPIO_PORT   GPIOA
#define USARTX_TX_GPIO_CLK    RCC_AHB1Periph_GPIOA
#define USARTX_TX_PIN		   GPIO_Pin_9 
#define USARTX_TX_AF          GPIO_AF_USART1
#define USARTX_TX_SOURCE      GPIO_PinSource9

#define USARTX_IRQHandler     USART1_IRQHandler
#define USARTX_IRQn           USART1_IRQn

void USART_sendString(USART_TypeDef *pUSARTx, char *str);
//void Debug_USART_config(void);
void USARTX_config(void);



#endif 
