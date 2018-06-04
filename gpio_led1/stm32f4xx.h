
//Ƭ�������ַ
#define PERIPH_BASE  ((unsigned int)0x40000000)
	
//AHB1���߻�ַ
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000)

//GPIOH ����ַ
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00)

/*
//GPIOH �Ĵ�����ַ��ǿ��ת����ָ��
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
//RCC�����ַ
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)

//RCC��AHB1ʱ��ʹ�ܼĴ�����ַ��ǿ��ת����ָ��
//#define RCC_AHB1ENR				*(unsigned int*)(RCC_BASE+0x30)

#define __IO    volatile  	 
typedef unsigned int  uint32_t;
typedef unsigned short  uint16_t;

//GPIOX �Ĵ����б�
typedef struct 
{
	__IO uint32_t MODER;  //ģʽ�Ĵ��� 
	__IO uint32_t OTYPER; //������ͼĴ���
	__IO uint32_t OSPEEDR; //����ٶȼĴ���
	__IO uint32_t PUPDR; //���������Ĵ���
	__IO uint32_t IDR; //�������ݼĴ���
	__IO uint32_t ODR; //������ݼĴ���
	__IO uint16_t BSRRL; //��λ/��λ�Ĵ����� 16 λ ����
	__IO uint16_t BSRRH; //��λ/��λ�Ĵ����� 16 λ����
	__IO uint32_t LCKR;  //���������Ĵ���
	__IO uint32_t AFR[2];  //���ù������üĴ���
} GPIO_TypeDef;

typedef struct 
{
	__IO uint32_t CR; //ʱ�ӿ��ƼĴ���
	__IO uint32_t PLLCFGR; //PLL���üĴ���
	__IO uint32_t CFGR; //ʱ�����üĴ���
	__IO uint32_t CIR; //ʱ���жϼĴ���
	__IO uint32_t AHB1RSTR; //AHB1 ���踴λ�Ĵ���
	__IO uint32_t AHB2RSTR; //AHB2 ���踴λ�Ĵ���
	__IO uint32_t AHB3RSTR; //AHB3 ���踴λ�Ĵ���
	__IO uint32_t RESERVED0; //����
	__IO uint32_t APB1RSTR; //APB1 ���踴λ�Ĵ���
	__IO uint32_t APB2RSTR; //APB2 ���踴λ�Ĵ���
	__IO uint32_t RESERVED1[2];
	__IO	uint32_t AHB1ENR;       /*!< RCC AHB1 ����ʱ�ӼĴ���: 0x30 */
	__IO	uint32_t AHB2ENR;       /*!< RCC AHB2 ����ʱ�ӼĴ���: 0x34 */
	__IO	uint32_t AHB3ENR;       /*!< RCC AHB3 ����ʱ�ӼĴ���: 0x38 */
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
