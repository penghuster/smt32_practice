#include "rcc_bsp.h"
/*
 * m: vco 输入时钟，分频因子， 取 2-63
 * n: vco 输出时钟， 倍频因子，取192-432
 * p: SYSCLK 时钟分频因子， 取值2， 4， 6， 8
 * q: OTG, FS SDIO RNG 时钟分频因子 取值 4-15
 * 函数使用举例， 使用 HSE 设置时钟：
 * SYSCLK = HCLK = 180M 
 * PCLK = HCLK/2 = 90M 
 * PCLK1 = HCLK/4 = 45
 * HSE 作为时钟来源，经过 PLL 倍频作为系统时钟，这是通常做法
 * 系统时钟超频到 216 
 */

void HSE_SetSysClock(uint32_t m, uint32_t n, uint32_t p, uint32_t q)
{
/*
 * 设置系统时钟的步骤：
 * 1. 开启 HSE/HSI 并等待 HSE/HSI 稳定
 * 2. 设置AHB APB1 APB2 的预分频因子
 * 3. 设置 PLL 的时钟来源，设置 VCO 输入时钟的分频因子 PLL_M, 设置 VCO 输出时钟倍频因子 PLL_N 
 *    设置 PLLCLK 时钟分频因子 PLL_P 设置 OTG_FS， SDIO RNG 时钟的分频因子 PLL_Q
 * 4. 开启 PLL，并等待 PLL稳定
 * 5. 把 PLLCLK 切换为系统 SYSCLK
 * 6. 读取时钟切换状态位，确保 PLLCLK 被选为系统时钟
 */
		__IO uint32_t HSEStartUpStatus = 0;
	
    RCC_HSEConfig(RCC_HSE_ON);

  
    HSEStartUpStatus = RCC_WaitForHSEStartUp();

    if(SUCCESS == HSEStartUpStatus){
        RCC-> APB1ENR |= RCC_APB1ENR_PWREN;
        PWR->CR |= PWR_CR_VOS;

        //设置系统时钟到 HCLK 的分频因子 
        RCC_HCLKConfig(RCC_SYSCLK_Div1);
        RCC_PCLK2Config(RCC_HCLK_Div2);
        RCC_PCLK1Config(RCC_HCLK_Div4); 

        RCC_PLLConfig(RCC_PLLSource_HSE, m, n, p, q);

        RCC_PLLCmd(ENABLE);

        while(RESET == RCC_GetFlagStatus(RCC_FLAG_PLLRDY)) {
            
        }
        PWR->CR |= PWR_CR_ODEN;
        while(0 == (PWR->CSR & PWR_CSR_ODRDY));

        PWR->CR |= PWR_CR_ODSWEN;
        while(0 == (PWR->CSR & PWR_CSR_ODSWRDY));

        //配置flash
        FLASH->ACR = FLASH_ACR_PRFTEN   
                     | FLASH_ACR_ICEN 
                     | FLASH_ACR_DCEN 
                     | FLASH_ACR_LATENCY_5WS;

        //当 PLL 稳定后将 PLL 切换为系统时钟
        RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
        while(0x08 !=  RCC_GetSYSCLKSource());
        
    }else {
        //HSE 配置出错
        while(1);
    }
    
    
}

// MCO1 PA8 GPIO 初始化
void MCO1_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
  // MCO1 GPIO 配置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
  GPIO_Init(GPIOA, &GPIO_InitStructure); 
}

// MCO2 PC9 GPIO 初始化
void MCO2_GPIO_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
  
  // MCO2 GPIO 配置
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  
  GPIO_Init(GPIOC, &GPIO_InitStructure);
}

