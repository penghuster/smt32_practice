#include "bsp_exti.h"
#include "bsp_led.h"
static void NVIC_Configuration()
{
    NVIC_InitTypeDef init;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    init.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
    init.NVIC_IRQChannelCmd = ENABLE;
    init.NVIC_IRQChannelPreemptionPriority = 1;
    init.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&init);

    init.NVIC_IRQChannel = KEY2_INT_EXTI_IRQ;
    NVIC_Init(&init);
}

void EXTI_Key_Config()
{
    
    GPIO_InitTypeDef gpio_init;
    EXTI_InitTypeDef exti_init;

    RCC_AHB1PeriphClockCmd(KEY1_INT_GPIO_CLK | KEY2_INT_GPIO_CLK, ENABLE);

    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

    NVIC_Configuration();

    gpio_init.GPIO_Mode = GPIO_Mode_IN;
    gpio_init.GPIO_Pin = KEY1_INT_GPIO_PIN;
    gpio_init.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(KEY1_INT_GPIO_PORT, &gpio_init);

    gpio_init.GPIO_Pin = KEY2_INT_GPIO_PIN;
    GPIO_Init(KEY2_INT_GPIO_PORT, &gpio_init);

    SYSCFG_EXTILineConfig(KEY1_INT_EXTI_PORTRESOURCE, KEY1_INT_EXTI_PINRESOURCE);
    exti_init.EXTI_Line = EXTI_Line0;
    exti_init.EXTI_Mode = EXTI_Mode_Interrupt;
    exti_init.EXTI_LineCmd = ENABLE;
    exti_init.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_Init(&exti_init);

    SYSCFG_EXTILineConfig(KEY2_INT_EXTI_PORTRESOURCE, KEY2_INT_EXTI_PINRESOURCE);
    exti_init.EXTI_Line = EXTI_Line13;
    exti_init.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&exti_init);
    
    
}


void KEY1_IRQHandler()
{
    if(EXTI_GetITStatus(EXTI_Line0) !=  RESET)
    {
        LED1_TOGGLE;
        EXTI_ClearITPendingBit(EXTI_Line0);
    }
}


void KEY2_IRQHandler()
{
    if(EXTI_GetITStatus(EXTI_Line13) !=  RESET)
    {
        LED2_TOGGLE;
        EXTI_ClearITPendingBit(EXTI_Line13);
    }
}




