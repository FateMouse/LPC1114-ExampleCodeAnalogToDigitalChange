/************************************************************************************** 
*   ����    ��2013��11��6�� (��Ȩ���У�����ؾ�) 
*   Ŀ��    ��ARM Cortex-M0 LPC1114 
*   ���뻷����KEIL 4.60
*   �ⲿ����10Mhz(��Ƶ50M)
*   ����    ��ѧ��ʹ��Ӳ��ɨ��ģʽ��ȡADCֵ
*   ����    ��Ration
*   �ٷ���ַ��http://www.rationmcu.com
*   �Ա���  ��http://ration.taobao.com
**************************************************************************************/
#include "lpc11xx.h"
#include "uart.h"
#include "adc.h"

void delay(void)
{
	uint16_t i,j;
	for(j=0;j<5000;j++)
		for(i=0;i<500;i++);
}

int main()
{
	uint16_t adc_value;
	
	UART_init(9600);
	ADC_Init(7);
	
	while(1)
	{
		delay();
		adc_value = ADC_Read(7);
		UART_send_byte(adc_value>>8);
		UART_send_byte(adc_value);
	}
}




