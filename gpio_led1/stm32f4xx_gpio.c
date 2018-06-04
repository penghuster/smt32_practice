
#include "stm32f4xx_gpio.h"



/**
  *���� GPIOX ����λ�ߵ�ƽ
  *
  */
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	//��ΪBSRR�Ĵ���bit λΪ0ʱû��Ӱ�죬�ʿ���ֱ�Ӹ�ֵ��
  GPIOx->BSRRL = GPIO_Pin;
}

/**
  *���� GPIOX����Ϊ�͵�ƽ
  */
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{

  GPIOx->BSRRH = GPIO_Pin;
}


/**
  *��ʼ�� GPIOX �ļĴ���
  */
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
	  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;
	
	/*-- GPIO Mode Configuration --*/
	//�����ʼ�� GPIOX �ĵڼ������ţ��ӵ� 0 ����ʼ�������ҵ��� GPIO_InitStruct->GPIO_Pin �ǵڼ�������
  for (pinpos = 0x00; pinpos < 16; pinpos++)
  {
		
		pos = ((uint32_t)0x01) << pinpos;
   
		//
    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

		/*currentpin == pos����˵���� pinpos ��������Ҫ���õ�����*/
    if (currentpin == pos)
		{		
			//���� pinpos �����ŵ����ģʽ��Ϊ0
			GPIOx->MODER  &= ~(3 << (2 *pinpos));
		
			//���� pinpos �����ŵ����ģʽ��ʼ��
			GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << (2 *pinpos));


			GPIOx->PUPDR &= ~(3 << ((2 *pinpos)));
			GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->GPIO_PuPd) << (2 *pinpos));		
		
			//����ģʽ�Ĵ���Ϊ���ģʽ���������ٶ����������
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
