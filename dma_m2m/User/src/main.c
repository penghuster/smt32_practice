  
#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bap_usart_dma.h"



void Delay(__IO u32 nCount); 


uint8_t Buffercmp(const uint32_t *pBuffer, uint32_t *pBuffer1, uint16_t buf_len)
{
	while(buf_len--){
		if(*pBuffer != *pBuffer1)
			return 0;
		pBuffer++;
		pBuffer1++;
	}
	return 1;
}

int main(void)
{
	uint8_t transfer_status;
	u_int16_t i;

	LED_GPIO_Config();
	Debug_USART_Config();
	USART_DMA_Config();

	printf("\r\n USART1 DMA Tx test \r\n");

	for(i = 0; i < SENDBUFF_SIZE; i++){
		SendBuff[i] = 'A';
	}

	USART_DMACmd(DEBUG_USART, USART_DMAReq_Tx, ENABLE);

	while(1){
		LED1_TOGGLE;
		Delay(0xFFFFFF);
	}

/*
	LED_PURPLE;
	Delay(0xFFFFFF);

	DMA_Config();
	while(DMA_GetFlagStatus(DMA_STREAM, DMA_FLAG_TCIF) == DISABLE);

	transfer_status = Buffercmp(aSRC_Const_Buffer, aDST_Buffer, BUFFER_SIZE);

	if(0 == transfer_status){
		LED_RED;
	}	else {
		LED_BLUE;
	}
    while(1);
*/
}

void Delay(__IO uint32_t nCount)	 //???????
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/

