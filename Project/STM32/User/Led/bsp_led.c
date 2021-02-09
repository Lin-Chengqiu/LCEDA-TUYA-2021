/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ledӦ�ú����ӿ�
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-MINI STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "./Led/bsp_led.h"   

 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;
	
//��ʱ�Ӻ���
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO,ENABLE);	//��GPIO��ʱ�ӣ��ȴ򿪸��ò����޸ĸ��ù���
GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//Ҫ�ȿ�ʱ�ӣ�����ӳ�䣻����ʾ�ر�jtag��ʹ��swd��  
//�����HAL�⣬ʹ�� __HAL_AFIO_REMAP_SWJ_NOJTAG();              //����JTAG
	
	
		/*����LED��ص�GPIO����ʱ��*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB, ENABLE);
	
			/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED1_GPIO_PIN;	

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED1_GPIO_PORT, &GPIO_InitStructure);	
		
		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED2_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED2_GPIO_PORT, &GPIO_InitStructure);
		
    		/*ѡ��Ҫ���Ƶ�GPIO����*/
		GPIO_InitStructure.GPIO_Pin = LED3_GPIO_PIN;

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(LED3_GPIO_PORT, &GPIO_InitStructure);

		GPIO_InitStructure.GPIO_Pin = LED_R_GPIO_PIN;
		GPIO_Init(LED_R_GPIO_PORT, &GPIO_InitStructure);
		GPIO_InitStructure.GPIO_Pin = LED_G_GPIO_PIN;
		GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStructure);		
		GPIO_InitStructure.GPIO_Pin = LED_B_GPIO_PIN;
		GPIO_Init(LED_B_GPIO_PORT, &GPIO_InitStructure);		
		/* �ر�����led��	*/
		GPIO_SetBits(LED1_GPIO_PORT, LED1_GPIO_PIN);
		
		/* �ر�����led��	*/
		GPIO_SetBits(LED2_GPIO_PORT, LED2_GPIO_PIN);	 
    
    		/* �ر�����led��	*/
		GPIO_SetBits(LED3_GPIO_PORT, LED3_GPIO_PIN);	 
		
			GPIO_SetBits(LED_R_GPIO_PORT, LED_R_GPIO_PIN);	 
			GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);	 
			GPIO_SetBits(LED_B_GPIO_PORT, LED_B_GPIO_PIN);	 
}

/**
  * @brief  ��ˮ�ƺ���
  *	@note   ÿ����һ�Σ��͸ı�һ��LED״̬
  * @param  ��
  * @retval ��
  */
void Flash_Led(void)
{
	static u8 count = 0;     //LED��־λ
	switch(++count)
	{
		case 1: LED_R_ON;LED_G_OFF;LED_B_OFF;break;//����LED1
		case 2: LED_R_OFF;LED_G_ON;LED_B_OFF;break;//����LED2s
		default :LED_R_OFF;LED_G_OFF;LED_B_ON;count = 0; break;
	}
}

/*********************************************END OF FILE**********************/
