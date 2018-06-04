  
#include "stm32f4xx.h"
#include "bsp_led.h"

#define DMA_STREAM  DMA2_Stream0
#define DMA_CHANNEL DMA_Channel_0
#define DMA_STREAM_CLK RCC_AHB1Periph_DMA2
#define DMA_FLAG_TCIF DMA_FLAG_TCIF0

#define BUFFER_SIZE 32 
#define TIMEOUT_MAX 10000

const uint32_t aSRC_Const_Buffer[BUFFER_SIZE]= {
                                    0x01020304,0x05060708,0x090A0B0C,0x0D0E0F10,
                                    0x11121314,0x15161718,0x191A1B1C,0x1D1E1F20,
                                    0x21222324,0x25262728,0x292A2B2C,0x2D2E2F30,
                                    0x31323334,0x35363738,0x393A3B3C,0x3D3E3F40,
                                    0x41424344,0x45464748,0x494A4B4C,0x4D4E4F50,
                                    0x51525354,0x55565758,0x595A5B5C,0x5D5E5F60,
                                    0x61626364,0x65666768,0x696A6B6C,0x6D6E6F70,
                                    0x71727374,0x75767778,0x797A7B7C,0x7D7E7F80};

uint32_t aDST_Buffer[BUFFER_SIZE];

void Delay(__IO u32 nCount); 

static void DMA_Config(void)
{
	DMA_InitTypeDef init;
	__IO uint32_t timeout = TIMEOUT_MAX;

	RCC_AHB1PeriphClockCmd(DMA_STREAM_CLK, ENABLE);

	//将数据流控制器恢复为复位值
	DMA_DeInit(DMA_STREAM);

	while(DMA_GetCmdStatus(DMA_STREAM) != DISABLE);

	init.DMA_Channel = DMA_CHANNEL;
	init.DMA_PeripheralBaseAddr = (uint32_t)aSRC_Const_Buffer;
	init.DMA_Memory0BaseAddr = (uint32_t)aDST_Buffer;
	init.DMA_BufferSize = (uint32_t)BUFFER_SIZE;
	init.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	init.DMA_MemoryInc = DMA_MemoryInc_Enable;
	init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Word;
	init.DMA_MemoryDataSize = DMA_MemoryDataSize_Word;
	init.DMA_Mode = DMA_Mode_Normal;
	init.DMA_DIR = DMA_DIR_MemoryToMemory;

	init.DMA_Priority = DMA_Priority_High;
	init.DMA_FIFOMode = DMA_FIFOMode_Disable;
	init.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;

	init.DMA_MemoryBurst = DMA_MemoryBurst_Single;
	init.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;

	DMA_Init(DMA_STREAM, &init);

	DMA_ClearFlag(DMA_STREAM, DMA_FLAG_TCIF);
	DMA_Cmd(DMA_STREAM, ENABLE);

	timeout = TIMEOUT_MAX;
	while((DMA_GetCmdStatus(DMA_STREAM) != ENABLE) && (timeout-- > 0));

	if(0 == timeout){
		LED_RED;
		Delay(0xFFFFFF);
		LED_RGBOFF;
		Delay(0xFFFFFF);
	}
}

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

	LED_GPIO_Config();

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

}

void Delay(__IO uint32_t nCount)	 //???????
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/

