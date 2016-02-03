/************************************************************************************** 
*   日期    ：2013年11月6日 (版权所有，翻版必究) 
*   目标    ：ARM Cortex-M0 LPC1114 
*   编译环境：KEIL 4.60
*   外部晶振：10Mhz(主频50M)
*   功能    ：学会使用START位启动ADC转换(中断)
*   作者    ：Ration
*   官方网址：http://www.rationmcu.com
*   淘宝店  ：http://ration.taobao.com
**************************************************************************************/
#include "lpc11xx.h"
#include "uart.h"
#include "adc.h"

uint8_t Channel;

void delay(void)
{
	uint16_t i,j;
	for(j=0;j<5000;j++)
		for(i=0;i<500;i++);
}

void ADC_IRQHandler(void)
{
	uint16_t adc_value;
	
	adc_value = (LPC_ADC->DR[Channel]>>6)&0x3FF;		
	adc_value = (adc_value*Vref)/1024; // 转换为真正的电压值
	UART_send_byte(adc_value>>8);
	UART_send_byte(adc_value);
}

int main()
{
	Channel = 7;
	UART_init(9600);
	ADC_Init(Channel);
	
	while(1)
	{
		delay();
		LPC_ADC->CR |= (1<<24); // 启动转换
	}
}

