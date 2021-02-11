#include "./Timer/Timer.h"

void Timer4Init(void)		//1����@24.000MHz
{
	T4T3M |= 0x20;		//��ʱ��ʱ��1Tģʽ
	T4L = 0x40;		//���ö�ʱ��ֵ
	T4H = 0xA2;		//���ö�ʱ��ֵ
	T4T3M |= 0x80;		//��ʱ��4��ʼ��ʱ
	IE2 |= ET4;        //ʹ�ܶ�ʱ���ж�
	EA = 1;
}

void TM4_Isr() interrupt 20
{
	static unsigned int ms = 0;
	if(++ms == 1000)
	{
		ms = 0;
		Flash_Led();
	}
}