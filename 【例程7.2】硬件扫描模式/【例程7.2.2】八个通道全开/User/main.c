/************************************************************************************** 
*   ����    ��2013��11��6�� (��Ȩ���У�����ؾ�) 
*   Ŀ��    ��ARM Cortex-M0 LPC1114 
*   ���뻷����KEIL 4.60
*   �ⲿ����10Mhz(��Ƶ50M)
*   ����    ��ѧ��ʹ��Ӳ��ɨ��ģʽ�˸�ͨ��ȫ������ADCֵ
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
	uint8_t adc_value[16];
	uint16_t adc_temp;
	
	UART_init(9600);
	ADC_Init();
	
	while(1)
	{
		delay();
		adc_temp = ADC_Read(0);
		adc_value[0] = adc_temp>>8;
		adc_value[1] = adc_temp;
		
		adc_temp = ADC_Read(1);
		adc_value[2] = adc_temp>>8;
		adc_value[3] = adc_temp;
		
		adc_temp = ADC_Read(2);
		adc_value[4] = adc_temp>>8;
		adc_value[5] = adc_temp;
		
		adc_temp = ADC_Read(3);
		adc_value[6] = adc_temp>>8;
		adc_value[7] = adc_temp;
		
		adc_temp = ADC_Read(4);
		adc_value[8] = adc_temp>>8;
		adc_value[9] = adc_temp;
		
		adc_temp = ADC_Read(5);
		adc_value[10] = adc_temp>>8;
		adc_value[11] = adc_temp;
		
		adc_temp = ADC_Read(6);
		adc_value[12] = adc_temp>>8;
		adc_value[13] = adc_temp;
		
		adc_temp = ADC_Read(7);
		adc_value[14] = adc_temp>>8;
		adc_value[15] = adc_temp;
		UART_send(adc_value, 16);
	}
}




