
#include "bsp_usart_dma.h"

uint8_t SendBuff[SENDBUFF_SIZE];

void Debug_USART_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
		
	RCC_AHB1PeriphClockCmd( DEBUG_USART_RX_GPIO_CLK|DEBUG_USART_TX_GPIO_CLK, ENABLE);

	/* Enable UART clock */
	RCC_APB2PeriphClockCmd(DEBUG_USART_CLK, ENABLE);

	/* Connect PXx to USARTx_Tx*/
	GPIO_PinAFConfig(DEBUG_USART_RX_GPIO_PORT,DEBUG_USART_RX_SOURCE, DEBUG_USART_RX_AF);

	/* Connect PXx to USARTx_Rx*/
	GPIO_PinAFConfig(DEBUG_USART_TX_GPIO_PORT,DEBUG_USART_TX_SOURCE,DEBUG_USART_TX_AF);

	/* Configure USART Tx as alternate function  */
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;

	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_TX_PIN  ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_USART_TX_GPIO_PORT, &GPIO_InitStructure);

	/* Configure USART Rx as alternate function  */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin = DEBUG_USART_RX_PIN;
	GPIO_Init(DEBUG_USART_RX_GPIO_PORT, &GPIO_InitStructure);
			
	/* USART mode config */
	USART_InitStructure.USART_BaudRate = DEBUG_USART_BAUDRATE;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(DEBUG_USART, &USART_InitStructure); 
	USART_Cmd(DEBUG_USART, ENABLE);	
}


///重定向c库函数printf到USART1
int fputc(int ch, FILE *f)
{
		/* 发送一个字节数据到USART1 */
		USART_SendData(DEBUG_USART, (uint8_t) ch);
		
		/* 等待发送完毕 */
		while (USART_GetFlagStatus(DEBUG_USART, USART_FLAG_TXE) == RESET);		
	
		return (ch);
}

///重定向c库函数scanf到USART1
int fgetc(FILE *f)
{
		/* 等待串口1输入数据 */
		while (USART_GetFlagStatus(DEBUG_USART, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(DEBUG_USART);
}


void USART_DMA_Config()
{
	DMA_InitTypeDef init;
	//__IO uint32_t timeout = TIMEOUT_MAX;

	RCC_AHB1PeriphClockCmd(DEBUG_USART_DMA_CLK, ENABLE);

	//将数据流控制器恢复为复位值
	DMA_DeInit(DEBUG_USART_DMA_STREAM);

	while(DMA_GetCmdStatus(DEBUG_USART_DMA_STREAM) != DISABLE);

	init.DMA_Channel = DEBUG_USART_DMA_CHANNEL;
	init.DMA_PeripheralBaseAddr = (uint32_t)DEBUG_USART_DR_BASE;
	init.DMA_Memory0BaseAddr = (uint32_t)SendBuff;
	init.DMA_BufferSize = (uint32_t)SENDBUFF_SIZE;
	init.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	init.DMA_MemoryInc = DMA_MemoryInc_Enable;
	init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	init.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	init.DMA_Mode = DMA_Mode_Circular;
	init.DMA_DIR = DMA_DIR_MemoryToPeripheral;

	init.DMA_Priority = DMA_Priority_Medium;
	init.DMA_FIFOMode = DMA_FIFOMode_Disable;
	init.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;

	init.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	init.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

	DMA_Init(DEBUG_USART_DMA_STREAM, &init);

	//一次传输时，需要手动清除此标识
	//DMA_ClearFlag(DEBUG_USART_DMA_STREAM, DMA_FLAG_TCIF);
	DMA_Cmd(DEBUG_USART_DMA_STREAM, ENABLE);
/*
	timeout = TIMEOUT_MAX;
	while((DMA_GetCmdStatus(DEBUG_USART_DMA_STREAM) != ENABLE) && (timeout-- > 0));

	if(0 == timeout){
		LED_RED;
		Delay(0xFFFFFF);
		LED_RGBOFF;
		Delay(0xFFFFFF);
	}	
	
	*/
}



