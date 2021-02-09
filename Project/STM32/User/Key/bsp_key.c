/**
  ******************************************************************************
  * @file    bsp_key.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   ����Ӧ��bsp��ɨ��ģʽ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-MINI STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 
  
#include "./key/bsp_key.h"  

/**
  * @brief  ���ð����õ���I/O��
  * @param  ��
  * @retval ��
  */
void Key_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	/*���������˿ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(KEY1_GPIO_CLK|KEY2_GPIO_CLK|KEY3_GPIO_CLK|KEY4_GPIO_CLK,ENABLE);
	
	//ѡ�񰴼�������
	GPIO_InitStructure.GPIO_Pin = KEY1_GPIO_PIN; 
	// ���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitStructure);
	
	//ѡ�񰴼�������
	GPIO_InitStructure.GPIO_Pin = KEY2_GPIO_PIN; 
	//���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = KEY3_GPIO_PIN; 
	//���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY3_GPIO_PORT, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = KEY4_GPIO_PIN; 
	//���ð���������Ϊ��������
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
	//ʹ�ýṹ���ʼ������
	GPIO_Init(KEY4_GPIO_PORT, &GPIO_InitStructure);	
}

 /*
 * ��������Key_Scan
 * ����  ������Ƿ��а�������
 * ����  ��GPIOx��x ������ A��B��C��D���� E
 *		     GPIO_Pin������ȡ�Ķ˿�λ 	
 * ���  ��KEY_OFF(û���°���)��KEY_ON�����°�����
 */
uint8_t Key_Scan(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin)
{			
	/*����Ƿ��а������� */
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON )  
	{	 
		/*�ȴ������ͷ� */
		while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin) == KEY_ON);   
		return 	KEY_ON;	 
	}
	else
		return KEY_OFF;
}
extern uint8_t screenMode;
extern uint8_t HUM_ALARM;
extern uint8_t TEMP_ALARM;
uint8_t AlarmSelect = 0;
uint8_t OLED_Light = 1;
void KeyFunction(void)
{
	static 	uint8_t wifiMode = 0;
	static uint8_t LedEnable = 0;
	switch(screenMode)
	{
		case 0:
		{
			if(!AlarmSelect)
			{
				OLED_ShowStr(110, 3,(unsigned char *)"<-",2);
			}
			else
			{
				OLED_ShowStr(110, 5,(unsigned char *)"<-",2);
			}
			if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
			{
				OLED_CLS();
				AlarmSelect = !AlarmSelect;
			}
			if (Key_Scan(KEY2_GPIO_PORT, KEY2_GPIO_PIN) == KEY_ON)
			{
				OLED_CLS();			 //����
				screenMode++;
			}
			if (Key_Scan(KEY3_GPIO_PORT, KEY3_GPIO_PIN) == KEY_ON)
			{
				OLED_CLS();
				if(!AlarmSelect)
				{
					HUM_ALARM-=5;
					if(HUM_ALARM<5)	HUM_ALARM = 90;
				}
				else
				{
					TEMP_ALARM--;
					if(TEMP_ALARM<10)	TEMP_ALARM = 40;
				}
				FLASH_Unlock();
				FLASH_ClearFlag(FLASH_FLAG_BSY|FLASH_FLAG_EOP|FLASH_FLAG_PGERR|FLASH_FLAG_WRPRTERR);//�����־λ
				//����
				FLASH_ErasePage(0x08000000+2*1024*20);
				
				//д������
				FLASH_ProgramWord(0x08000000+2*1024*20,HUM_ALARM);
				FLASH_ProgramWord(0x08000000+2*1024*20+10,TEMP_ALARM);
				FLASH_Lock();
			}
			if (Key_Scan(KEY4_GPIO_PORT, KEY4_GPIO_PIN) == KEY_ON)
			{
				OLED_CLS();
				if(!AlarmSelect)
				{
					HUM_ALARM+=5;
					if(HUM_ALARM>90)	HUM_ALARM = 5;
				}
				else
				{
					TEMP_ALARM++;
					if(TEMP_ALARM>40)	TEMP_ALARM = 10;
				}
				FLASH_Unlock();
				FLASH_ClearFlag(FLASH_FLAG_BSY|FLASH_FLAG_EOP|FLASH_FLAG_PGERR|FLASH_FLAG_WRPRTERR);//�����־λ
				//����
				FLASH_ErasePage(0x08000000+2*1024*20);
				
				//д������
				FLASH_ProgramWord(0x08000000+2*1024*20,HUM_ALARM);
				FLASH_ProgramWord(0x08000000+2*1024*20+10,TEMP_ALARM);
				FLASH_Lock();
			}
		};break;
		case 1:
		{
			if (Key_Scan(KEY1_GPIO_PORT, KEY1_GPIO_PIN) == KEY_ON)
			{
				wifiMode++;
				switch(wifiMode)
				{
					case 1:mcu_set_wifi_mode(SMART_CONFIG);LED1_ON;break;
					case 2:mcu_set_wifi_mode(AP_CONFIG);LED2_ON;LED1_OFF;break;
					default:wifiMode = 0;;LED2_OFF;break;
				}
			}
			if (Key_Scan(KEY2_GPIO_PORT, KEY2_GPIO_PIN) == KEY_ON)
			{
				OLED_CLS();			 //����
				screenMode++;
			}
			if (Key_Scan(KEY3_GPIO_PORT, KEY3_GPIO_PIN) == KEY_ON)
			{
				OLED_Light = !OLED_Light;
				if(OLED_Light)
					OLED_ON();
				else
					OLED_OFF();
			}
			if (Key_Scan(KEY4_GPIO_PORT, KEY4_GPIO_PIN) == KEY_ON)
			{
				LedEnable = !LedEnable;
				if(LedEnable)
				{
					TIM_ITConfig(BASIC_TIM,TIM_IT_Update,ENABLE);
				}
				else
				{
					TIM_ITConfig(BASIC_TIM,TIM_IT_Update,DISABLE);
					LED_R_OFF;LED_G_OFF;LED_B_OFF;
				}
			}
		}break;
		default:screenMode = 0;break;
	}
}
/*********************************************END OF FILE**********************/
