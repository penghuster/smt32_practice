
//片上外设基址
#define PERIPH_BASE  ((unsigned int)0x40000000)
	
//AHB1总线基址
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000)

//GPIOH 基地址
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00)

/*
//GPIOH 寄存器地址，强制转换成指针
#define GPIOH_MODER    *(unsigned int *)(GPIOH_BASE + 0x00)
#define GPIOH_OTYPER   *(unsigned int *)(GPIOH_BASE + 0x04)
#define GPIOH_OSPEEDR *(unsigned int *)(GPIOH_BASE + 0x08)
#define GPIOH_PUPDR    *(unsigned int *)(GPIOH_BASE + 0x0C)
#define GPIOH_IDR      *(unsigned int *)(GPIOH_BASE + 0x10)
#define GPIOH_ODR			 *(unsigned int*)(GPIOH_BASE+0x14)
#define GPIOH_BSRR					*(unsigned int*)(GPIOH_BASE+0x18)
#define GPIOH_LCKR					*(unsigned int*)(GPIOH_BASE+0x1C)
#define GPIOH_AFRL					*(unsigned int*)(GPIOH_BASE+0x20)
#define GPIOH_AFRH					*(unsigned int*)(GPIOH_BASE+0x24)
*/
//RCC外设基址
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)

//RCC的AHB1时钟使能寄存器地址，强制转换成指针
//#define RCC_AHB1ENR				*(unsigned int*)(RCC_BASE+0x30)

#define __IO    volatile  	 
typedef unsigned int  uint32_t;
typedef unsigned short  uint16_t;

//GPIOX 寄存器列表
typedef struct 
{
	__IO uint32_t MODER;  //模式寄存器 
	__IO uint32_t OTYPER; //输出类型寄存器
	__IO uint32_t OSPEEDR; //输出速度寄存器
	__IO uint32_t PUPDR; //上拉下拉寄存器
	__IO uint32_t IDR; //输入数据寄存器
	__IO uint32_t ODR; //输出数据寄存器
	__IO uint16_t BSRRL; //置位/复位寄存器低 16 位 部分
	__IO uint16_t BSRRH; //置位/复位寄存器高 16 位部分
	__IO uint32_t LCKR;  //配置锁定寄存器
	__IO uint32_t AFR[2];  //复用功能配置寄存器
} GPIO_TypeDef;

typedef struct 
{
	__IO uint32_t CR; //时钟控制寄存器
	__IO uint32_t PLLCFGR; //PLL配置寄存器
	__IO uint32_t CFGR; //时钟配置寄存器
	__IO uint32_t CIR; //时钟中断寄存器
	__IO uint32_t AHB1RSTR; //AHB1 外设复位寄存器
	__IO uint32_t AHB2RSTR; //AHB2 外设复位寄存器
	__IO uint32_t AHB3RSTR; //AHB3 外设复位寄存器
	__IO uint32_t RESERVED0; //保留
	__IO uint32_t APB1RSTR; //APB1 外设复位寄存器
	__IO uint32_t APB2RSTR; //APB2 外设复位寄存器
	__IO uint32_t RESERVED1[2];
	__IO	uint32_t AHB1ENR;       /*!< RCC AHB1 外设时钟寄存器: 0x30 */
	__IO	uint32_t AHB2ENR;       /*!< RCC AHB2 外设时钟寄存器: 0x34 */
	__IO	uint32_t AHB3ENR;       /*!< RCC AHB3 外设时钟寄存器: 0x38 */
}RCC_TypeDef;


#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)


#define RCC                 ((RCC_TypeDef *) RCC_BASE)
