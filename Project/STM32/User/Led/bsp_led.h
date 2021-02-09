#ifndef __LED_H
#define	__LED_H


#include "stm32f10x.h"


/* ����LED���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED���� */
#define LED1_GPIO_PORT    	GPIOA		              /* GPIO�˿� */
#define LED1_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define LED1_GPIO_PIN				GPIO_Pin_1			        

#define LED2_GPIO_PORT    	GPIOA			              /* GPIO�˿� */
#define LED2_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define LED2_GPIO_PIN				GPIO_Pin_2			        

#define LED3_GPIO_PORT    	GPIOA			              /* GPIO�˿� */
#define LED3_GPIO_CLK 	    RCC_APB2Periph_GPIOA		/* GPIO�˿�ʱ�� */
#define LED3_GPIO_PIN				GPIO_Pin_3			 

#define LED_R_GPIO_PORT    	GPIOB		              /* GPIO�˿� */
#define LED_R_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED_R_GPIO_PIN			GPIO_Pin_3			        

#define LED_G_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define LED_G_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED_G_GPIO_PIN			GPIO_Pin_4			        

#define LED_B_GPIO_PORT    	GPIOB			              /* GPIO�˿� */
#define LED_B_GPIO_CLK 	    RCC_APB2Periph_GPIOB		/* GPIO�˿�ʱ�� */
#define LED_B_GPIO_PIN			GPIO_Pin_5		
/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* ʹ�ñ�׼�Ĺ̼������IO*/
#define LED1(a)	if (a)	\
					GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2(a)	if (a)	\
					GPIO_SetBits(LED2_GPIO_PORT,LED2_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED2_GPIO_PORT,LED2_GPIO_PIN)
          
#define LED3(a)	if (a)	\
					GPIO_SetBits(LED3_GPIO_PORT,LED3_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED3_GPIO_PORT,LED3_GPIO_PIN)

#define LED_R(a)	if (a)	\
					GPIO_SetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_R_GPIO_PORT,LED_R_GPIO_PIN)

#define LED_G(a)	if (a)	\
					GPIO_SetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_G_GPIO_PORT,LED_G_GPIO_PIN)
          
#define LED_B(a)	if (a)	\
					GPIO_SetBits(LED_B_GPIO_PORT,LED_B_GPIO_PIN);\
					else		\
					GPIO_ResetBits(LED_B_GPIO_PORT,LED_B_GPIO_PIN)


/* ֱ�Ӳ����Ĵ����ķ�������IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //���Ϊ�ߵ�ƽ		
#define digitalLo(p,i)		 {p->BRR=i;}	 //����͵�ƽ
#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬


/* �������IO�ĺ� */
#define LED1_TOGGLE		 digitalToggle(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		   digitalHi(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			   digitalLo(LED1_GPIO_PORT,LED1_GPIO_PIN)

#define LED2_TOGGLE		 digitalToggle(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_OFF		   digitalHi(LED2_GPIO_PORT,LED2_GPIO_PIN)
#define LED2_ON			   digitalLo(LED2_GPIO_PORT,LED2_GPIO_PIN)

#define LED3_TOGGLE		 digitalToggle(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_OFF		   digitalHi(LED3_GPIO_PORT,LED3_GPIO_PIN)
#define LED3_ON			   digitalLo(LED3_GPIO_PORT,LED3_GPIO_PIN)

#define LED_R_TOGGLE		 digitalToggle(LED_R_GPIO_PORT,LED_R_GPIO_PIN)
#define LED_R_OFF		   digitalHi(LED_R_GPIO_PORT,LED_R_GPIO_PIN)
#define LED_R_ON			   digitalLo(LED_R_GPIO_PORT,LED_R_GPIO_PIN)

#define LED_G_TOGGLE		 digitalToggle(LED_G_GPIO_PORT,LED_G_GPIO_PIN)
#define LED_G_OFF		   digitalHi(LED_G_GPIO_PORT,LED_G_GPIO_PIN)
#define LED_G_ON			   digitalLo(LED_G_GPIO_PORT,LED_G_GPIO_PIN)

#define LED_B_TOGGLE		 digitalToggle(LED_B_GPIO_PORT,LED_B_GPIO_PIN)
#define LED_B_OFF		   digitalHi(LED_B_GPIO_PORT,LED_B_GPIO_PIN)
#define LED_B_ON			   digitalLo(LED_B_GPIO_PORT,LED_B_GPIO_PIN)


void LED_GPIO_Config(void);
void Flash_Led(void);

#endif /* __LED_H */
