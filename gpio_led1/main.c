//ʹ�üĴ����ķ�������LED��
#include "stm32f4xx.h" 


/**
  *  main ����
  */
int main(void)
{	
	//���� GPIOH����ʱ�ӣ�ʹ������ʱ��Ҫ�ȿ�������ʱ��
	RCC->AHB1ENR |= (1<<7);
	
	
	//LED �˿ڳ�ʼ��
	/*GPIOH MODER10����*/
	GPIOH->MODER  &= ~( 0x03<< (2*10));	
	/*PH10 MODER10 = 01b ���ģʽ*/
	GPIOH->MODER |= (1<<2*10);
	
	/*GPIOH OTYPER10��λ*/
	GPIOH->OTYPER &= ~(1<<1*10);
	/*PH10 OTYPER10 = 0b ����ģʽ*/
	GPIOH->OTYPER |= (0<<1*10);
	
	/*GPIOH OSPEEDR10 ���*/
	GPIOH->OSPEEDR &= ~(0x03<<2*10);
	/*PH10 OSPEEDR10 = 0b ����2MHz*/
	GPIOH->OSPEEDR |= (0<<2*10);
	
	/*GPIOH PUPDR10���*/
	GPIOH->PUPDR &= ~(0x03<<2*10);
	/*PH10 PUPDR10 = 01b ����ģʽ*/
	GPIOH->PUPDR |= (1<<2*10);
	
	/*PH10 BSRR�Ĵ�����BR10��1,ʹ��������͵�ƽ*/
	//GPIOH_BSRR |= (1<<16<<10);
	
	
	/*PH10 BSRR???? BS10?1,????????*/
	//GPIOH_BSRR |= (1<<10);
	
	GPIOH->ODR &= ~(0x01<<10);

	while(1);

}

// ????,?????????????
void SystemInit(void)
{	
}
