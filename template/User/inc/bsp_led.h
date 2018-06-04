#ifndef __LED_H
#define	__LED_H

#include "stm32f4xx.h"


//red
#define LED1_PIN GPIO_Pin_10
#define LED1_GPIO_PORT   GPIOH
#define LED1_GPIO_CLK    RCC_AHB1Periph_GPIOH

//green
#define LED2_PIN GPIO_Pin_11
#define LED2_GPIO_PORT   GPIOH
#define LED2_GPIO_CLK    RCC_AHB1Periph_GPIOH

//blue
#define LED3_PIN GPIO_Pin_12
#define LED3_GPIO_PORT   GPIOH
#define LED3_GPIO_CLK    RCC_AHB1Periph_GPIOH


//Ö¸Ê¾µÆ
#define LED4_PIN GPIO_Pin_11
#define LED4_GPIO_PORT   GPIOD
#define LED4_GPIO_CLK    RCC_AHB1Periph_GPIOD



#define ON  0
#define OFF 1

/* ???,??????????? */
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_PIN)

#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_PIN)

#define digitalHi(p, i)		{p->BSRRL = i;}
#define digitalLo(p, i)   {p->BSRRH = i;}
#define digitalToggle(p, i)   {p->ODR ^=i;}


#define LED1_TOGGLE		digitalToggle(LED1_GPIO_PORT,LED1_PIN)
#define LED1_OFF			digitalHi(LED1_GPIO_PORT,LED1_PIN)
#define LED1_ON				digitalLo(LED1_GPIO_PORT,LED1_PIN)

#define LED2_TOGGLE		digitalToggle(LED2_GPIO_PORT,LED2_PIN)
#define LED2_OFF			digitalHi(LED2_GPIO_PORT,LED2_PIN)
#define LED2_ON				digitalLo(LED2_GPIO_PORT,LED2_PIN)

#define LED3_TOGGLE		digitalToggle(LED3_GPIO_PORT,LED3_PIN)
#define LED3_OFF			digitalHi(LED3_GPIO_PORT,LED3_PIN)
#define LED3_ON				digitalLo(LED3_GPIO_PORT,LED3_PIN)

#define LED_RED  \
					LED1_ON;\
					LED2_OFF;\
					LED3_OFF

#define LED_GREEN		\
					LED1_OFF;\
					LED2_ON;\
					LED3_OFF
					
#define LED_BLUE	\
					LED1_OFF;\
					LED2_OFF;\
					LED3_ON
					
#define LED_YELLOW	\
					LED1_ON;\
					LED2_ON;\
					LED3_OFF
					
#define LED_PURPLE	\
					LED1_ON;\
					LED2_OFF;\
					LED3_ON
					
#define LED_CYAN \
					LED1_OFF;\
					LED2_ON;\
					LED3_ON
					
#define LED_WHITE	\
					LED1_ON;\
					LED2_ON;\
					LED3_ON
					
#define LED_RGBOFF	\
					LED1_OFF;\
					LED2_OFF;\
					LED3_OFF	
					
void LED_GPIO_Config(void);


#endif /* __LED_H */
