
#include "stm32f4xx_gpio.h"



/**
  *设置 GPIOX 引脚位高电平
  *
  */
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	//因为BSRR寄存器bit 位为0时没有影响，故可以直接赋值。
  GPIOx->BSRRL = GPIO_Pin;
}

/**
  *设置 GPIOX引脚为低电平
  */
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{

  GPIOx->BSRRH = GPIO_Pin;
}


/**
  *初始化 GPIOX 的寄存器
  */
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
	  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;
	
	/*-- GPIO Mode Configuration --*/
	//计算初始化 GPIOX 的第几个引脚，从第 0 个开始遍历，找到与 GPIO_InitStruct->GPIO_Pin 是第几个引脚
  for (pinpos = 0x00; pinpos < 16; pinpos++)
  {
		
		pos = ((uint32_t)0x01) << pinpos;
   
		//
    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

		/*currentpin == pos，则说明第 pinpos 个引脚是要配置的引脚*/
    if (currentpin == pos)
		{		
			//将第 pinpos 个引脚的输出模式置为0
			GPIOx->MODER  &= ~(3 << (2 *pinpos));
		
			//将第 pinpos 个引脚的输出模式初始化
			GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << (2 *pinpos));


			GPIOx->PUPDR &= ~(3 << ((2 *pinpos)));
			GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->GPIO_PuPd) << (2 *pinpos));		
		
			//若是模式寄存器为输出模式，则设置速度与输出类型
			if ((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF))
			{
				GPIOx->OSPEEDR &= ~(3 << (2 *pinpos));
				GPIOx->OSPEEDR |= ((uint32_t)(GPIO_InitStruct->GPIO_Speed) << (2 *pinpos));

				GPIOx->OTYPER  &= ~(1 << (pinpos)) ;
				GPIOx->OTYPER |= (uint16_t)(((uint16_t)GPIO_InitStruct->GPIO_OType) << (pinpos));
			}
		}
	}
}
