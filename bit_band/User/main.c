  
#include "stm32f4xx.h"
#include "bsp_led.h"

#define BITBAND(addr, bitnum) ((addr & 0xF0000000) + 0x02000000 + \
    ((addr & 0x000FFFFF) << 5) + (bitnum <<2))


#define MEM_ADDR(addr)  *((volatile unsigned long *)(addr))
#define BIT_ADDR(addr, bitnum)  MEM_ADDR(BITBAND(addr, bitnum))

#define GPIOA_ODR_Addr (GPIOA_BASE + 0x14)
#define GPIOB_ODR_Addr (GPIOB_BASE + 0x14)
#define GPIOC_ODR_Addr (GPIOC_BASE + 0x14)
#define GPIOD_ODR_Addr (GPIOD_BASE + 0x14)
#define GPIOE_ODR_Addr (GPIOE_BASE + 0x14)
#define GPIOF_ODR_Addr (GPIOF_BASE + 0x14)
#define GPIOG_ODR_Addr (GPIOG_BASE + 0x14)
#define GPIOH_ODR_Addr (GPIOH_BASE + 0x14)
#define GPIOI_ODR_Addr (GPIOI_BASE + 0x14)
#define GPIOJ_ODR_Addr (GPIOJ_BASE + 0x14)
#define GPIOK_ODR_Addr (GPIOK_BASE + 0x14)

#define GPIOA_IDR_Addr (GPIOA_BASE + 0x10)
#define GPIOB_IDR_Addr (GPIOB_BASE + 0x10)
#define GPIOC_IDR_Addr (GPIOC_BASE + 0x10)
#define GPIOD_IDR_Addr (GPIOD_BASE + 0x10)
#define GPIOE_IDR_Addr (GPIOE_BASE + 0x10)
#define GPIOF_IDR_Addr (GPIOF_BASE + 0x10)
#define GPIOG_IDR_Addr (GPIOG_BASE + 0x10)
#define GPIOH_IDR_Addr (GPIOH_BASE + 0x10)
#define GPIOI_IDR_Addr (GPIOI_BASE + 0x10)
#define GPIOJ_IDR_Addr (GPIOJ_BASE + 0x10)
#define GPIOK_IDR_Addr (GPIOK_BASE + 0x10)


#define PAout(n)  BIT_ADDR(GPIOA_ODR_Addr, n)
#define PAin(n)   BIT_ADDR(GPIOA_IDR_Addr, n)

#define PBout(n)  BIT_ADDR(GPIOB_ODR_Addr, n)
#define PBin(n)   BIT_ADDR(GPIOB_IDR_Addr, n)

#define PCout(n)  BIT_ADDR(GPIOC_ODR_Addr, n)
#define PCin(n)   BIT_ADDR(GPIOC_IDR_Addr, n)

#define PDout(n)  BIT_ADDR(GPIOD_ODR_Addr, n)
#define PDin(n)   BIT_ADDR(GPIOD_IDR_Addr, n)

#define PEout(n)  BIT_ADDR(GPIOE_ODR_Addr, n)
#define PEin(n)   BIT_ADDR(GPIOE_IDR_Addr, n)

#define PFout(n)  BIT_ADDR(GPIOF_ODR_Addr, n)
#define PFin(n)   BIT_ADDR(GPIOF_IDR_Addr, n)

#define PGout(n)  BIT_ADDR(GPIOG_ODR_Addr, n)
#define PGin(n)   BIT_ADDR(GPIOG_IDR_Addr, n)

#define PHout(n)  BIT_ADDR(GPIOH_ODR_Addr, n)
#define PHin(n)   BIT_ADDR(GPIOH_IDR_Addr, n)


#define PIout(n)  BIT_ADDR(GPIOI_ODR_Addr, n)
#define PIin(n)   BIT_ADDR(GPIOI_IDR_Addr, n)


#define PJout(n)  BIT_ADDR(GPIOJ_ODR_Addr, n)
#define PJin(n)   BIT_ADDR(GPIOJ_IDR_Addr, n)

#define PKout(n)  BIT_ADDR(GPIOK_ODR_Addr, n)
#define PKin(n)   BIT_ADDR(GPIOK_IDR_Addr, n)
















void Delay(__IO u32 nCount); 

int main(void)
{
    LED_GPIO_Config();
    while(1){
        
        PHout(11) = 0;
        Delay(0xFFFFF);

        PHout(11) = 1;
        Delay(0xFFFFF);
    }

}

void Delay(__IO uint32_t nCount)	 //???????
{
	for(; nCount != 0; nCount--);
}

/*********************************************END OF FILE**********************/

