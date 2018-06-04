//使用寄存器的方法点亮LED灯
#include "stm32f4xx.h" 


/**
  *  main 函数
  */
int main(void)
{	
	//开启 GPIOH　的时钟，使用外设时都要先开启它的时钟
	RCC->AHB1ENR |= (1<<7);
	
	
	//LED 端口初始化
	/*GPIOH MODER10清零*/
	GPIOH->MODER  &= ~( 0x03<< (2*10));	
	/*PH10 MODER10 = 01b 输出模式*/
	GPIOH->MODER |= (1<<2*10);
	
	/*GPIOH OTYPER10置位*/
	GPIOH->OTYPER &= ~(1<<1*10);
	/*PH10 OTYPER10 = 0b 推挽模式*/
	GPIOH->OTYPER |= (0<<1*10);
	
	/*GPIOH OSPEEDR10 清空*/
	GPIOH->OSPEEDR &= ~(0x03<<2*10);
	/*PH10 OSPEEDR10 = 0b 速率2MHz*/
	GPIOH->OSPEEDR |= (0<<2*10);
	
	/*GPIOH PUPDR10清空*/
	GPIOH->PUPDR &= ~(0x03<<2*10);
	/*PH10 PUPDR10 = 01b 上拉模式*/
	GPIOH->PUPDR |= (1<<2*10);
	
	/*PH10 BSRR寄存器的BR10置1,使引脚输出低电平*/
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
