#include "bsp_led.h"   

 /**
  * @brief  ?????LED?IO
  * @param  ?
  * @retval ?
  */
void LED_GPIO_Config(void)
{		
		/*????GPIO_InitTypeDef??????*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*??LED???GPIO????*/
		RCC_AHB1PeriphClockCmd ( LED1_GPIO_CLK|
	                           LED2_GPIO_CLK|
	                           LED3_GPIO_CLK, ENABLE); 

		/*??????GPIO??*/															   
		GPIO_InitStructure.GPIO_Pin = LED1_PIN;	

		/*???????????*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;   
    
    /*??????????????*/
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    
    /*?????????*/
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

		/*???????2MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz; 

		/*?????,???????GPIO_InitStructure???GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
    
    /*??????GPIO??*/															   
		GPIO_InitStructure.GPIO_Pin = LED2_PIN;	
    GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);	
    
    /*??????GPIO??*/															   
		GPIO_InitStructure.GPIO_Pin = LED3_PIN;	
    GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);	
		
		/*??RGB?*/
		LED_RGBOFF;		
		
}

