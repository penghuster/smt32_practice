#include "bsp_usart.h"
#include <stdio.h>


static void NVIC_config()
{
	NVIC_InitTypeDef init;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	init.NVIC_IRQChannel = USART1_IRQn;
	init.NVIC_IRQChannelCmd = ENABLE;
	init.NVIC_IRQChannelPreemptionPriority = 1;
	init.NVIC_IRQChannelSubPriority = 1;

	NVIC_Init(&init);
}


void USARTX_config()
{
	GPIO_InitTypeDef gpio_init;
	USART_InitTypeDef usart_init;

	RCC_AHB1PeriphClockCmd(USARTX_RX_GPIO_CLK | USARTX_TX_GPIO_CLK, ENABLE);
	RCC_APB2PeriphClockCmd(USARTX_CLK, ENABLE );
	
	GPIO_PinAFConfig(USARTX_RX_GPIO_PORT, USARTX_RX_SOURCE, USARTX_RX_AF);
	GPIO_PinAFConfig(USARTX_TX_GPIO_PORT, USARTX_TX_SOURCE, USARTX_TX_AF);

	gpio_init.GPIO_Mode = GPIO_Mode_AF;
	gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
	gpio_init.GPIO_Speed = GPIO_Speed_50MHz;

	gpio_init.GPIO_Pin = USARTX_RX_PIN;
	GPIO_Init(USARTX_RX_GPIO_PORT, &gpio_init);

	gpio_init.GPIO_Pin = USARTX_TX_PIN;
	GPIO_Init(USARTX_TX_GPIO_PORT, &gpio_init);

	usart_init.USART_BaudRate = USARTX_BANDRATE;
	usart_init.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	usart_init.USART_Parity = USART_Parity_No;
	usart_init.USART_StopBits = USART_StopBits_1;
	usart_init.USART_WordLength = USART_WordLength_8b;
	usart_init.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

	USART_Init(USARTX, &usart_init);

	//NVIC_config();

	//USART_ITConfig(DEBUG_USART, USART_IT_RXNE, ENABLE);
	USART_Cmd(USARTX, ENABLE);
}

/*
void USART_sendByte(USART_TypeDef *pUSARTx, uint8_t ch)
{
	USART_SendData(pUSARTx, ch);
	//等待发送数据为空
	while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}


void USART_sendString(USART_TypeDef *pUSARTx, char *str)
{
	uint32_t k = 0;
	do{
		USART_sendByte(pUSARTx, *(str + k));
		k++;
	}while(*(str + k) != '\0');

	while(USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);
}
*/
/*

void DEBUG_USART_IRQHandler()
{
	uint8_t ucTemp;
	
	if(USART_GetITStatus(DEBUG_USART, USART_IT_RXNE) != RESET){
		ucTemp = USART_ReceiveData(DEBUG_USART);
		USART_SendData(DEBUG_USART, ucTemp);
	}
}
*/

///重定向c库函数printf到串口，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
		/* 发送一个字节数据到串口 */
		USART_SendData(USARTX, (uint8_t) ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(USARTX, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

///重定向c库函数scanf到串口，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
		/* 等待串口输入数据 */
		while (USART_GetFlagStatus(USARTX, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USARTX);
}


