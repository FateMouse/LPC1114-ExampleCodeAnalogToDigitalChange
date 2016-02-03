/************************************************************************************** 
*   日期    ：2013年11月6日 (版权所有，翻版必究) 
*   目标    ：ARM Cortex-M0 LPC1114 
*   编译环境：KEIL 4.60
*   外部晶振：10Mhz(主频50M)
*   功能    ：学会使用硬件扫描模式八个通道全开测量ADC值
*   作者    ：Ration
*   官方网址：http://www.rationmcu.com
*   淘宝店  ：http://ration.taobao.com
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




