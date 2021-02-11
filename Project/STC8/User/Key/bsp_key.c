#include "./key/bsp_key.h"  


void Key_init(void)
{
	P3M1=(P3M1&0x3F)|0xC0;  //����IO��ģʽ
	P3M0=(P3M0&0x3F)|0xC0;  //����IO��ģʽ
	/*
	P3.0ά�ֲ���
	P3.1ά�ֲ���
	P3.2ά�ֲ���
	P3.3ά�ֲ���
	P3.4ά�ֲ���
	P3.5ά�ֲ���
	P3.6��©
	P3.7��©
	*/
}

void KeyScan(void)
{
	static uint8_t OLED_Light = 1;
	static uint8_t LedEnable = 0;
	if (KEY1 == KEY_ON)
	{
		LedEnable = !LedEnable;
		if(LedEnable)
		{
			IE2 |= ET4;
		}
		else
		{
			IE2 &= ~ET4;
			LED_R_OFF;LED_G_OFF;LED_B_OFF;
		}
	}while(KEY1 == KEY_ON);
	if (KEY2 == KEY_ON)
	{
		OLED_Light = !OLED_Light;
		if(OLED_Light)
			OLED_ON();
		else
			OLED_OFF();
	}while(KEY2 == KEY_ON);
}
/*********************************************END OF FILE**********************/
