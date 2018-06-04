/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   ��1.5.1�汾�⽨�Ĺ���ģ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:����  STM32 F429 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include <stdio.h>

void Delay(__IO u32 nCount); 
static void Show_Message(void);


int main(void)
{
	 char ch;
	LED_GPIO_Config();

 	USARTX_config();
	//USART_sendString(DEBUG_USART, "this is a usart echo.");
	//while(1);
	  /* 打印指令输入提示信息 */
	  Show_Message();
	  while(1)
		{	
	    /* 获取字符指令 */
	    ch=getchar();
	    printf("recieve char: %c\n",ch);
	    
	    /* 根据字符指令控制RGB彩灯颜色 */
	    switch(ch)
	    {
	      case '1':
	        LED_RED;
	      break;
	      case '2':
	        LED_GREEN;
	      break;
	      case '3':
	        LED_BLUE;
	      break;
	      case '4':
	        LED_YELLOW;
	      break;
	      case '5':
	        LED_PURPLE;
	      break;
	      case '6':
	        LED_CYAN;
	      break;
	      case '7':
	        LED_WHITE;
	      break;
	      case '8':
	        LED_RGBOFF;
	      break;
	      default:
	        /* 如果不是指定指令字符，打印提示信息 */
	        Show_Message();
	        break;      
	    }   
		}	
}

void Delay(__IO uint32_t nCount)	 //???????
{
	for(; nCount != 0; nCount--);
}


static void Show_Message(void)
{
  printf("\r\n  this is a experiment that usart controls the RGB\n");
  printf("the band rate of usart1 %d 8-N-1 \n", USARTX_BANDRATE);
  printf("the rgb control command: \n");
  printf("   cmd   ------ color \n");
  printf("     1    ------    red \n");
  printf("     2    ------    green \n");
  printf("     3    ------    blue \n");
  printf("     4    ------    yellow \n");
  printf("     5    ------    pure \n");
  printf("     6    ------    qing \n");
  printf("     7    ------    white \n");
  printf("     8    ------    turnoff \n"); 
}


/*********************************************END OF FILE**********************/

