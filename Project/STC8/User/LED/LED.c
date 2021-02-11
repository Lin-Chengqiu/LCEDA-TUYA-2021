#include "./LED/LED.h"

void LED_init(void)
{
	/*
	P5.4����
	P5.5����
	*/	
	P5M1=(P5M1&0xCF)|0x00;  //����IO��ģʽ
	P5M0=(P5M0&0xCF)|0x30;  //����IO��ģʽ
	/*P4.0����*/
	P4M1=(P4M1&0xFE)|0x00;  //����IO��ģʽ
	P4M0=(P4M0&0xFE)|0x01;  //����IO��ģʽ
}

void Flash_Led(void)
{
	static unsigned char count = 0;     //LED��־λ
	switch(++count)
	{
		case 1: LED_R_ON;LED_G_OFF;LED_B_OFF;break;//����LED1
		case 2: LED_R_OFF;LED_G_ON;LED_B_OFF;break;//����LED2s
		default :LED_R_OFF;LED_G_OFF;LED_B_ON;count = 0; break;
	}
}