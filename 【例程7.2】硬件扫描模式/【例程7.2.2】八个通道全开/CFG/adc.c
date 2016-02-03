#include "lpc11xx.h"
#include "adc.h"


/*****************************************/
/* 函数名称：初始化ADC口                 */
/*****************************************/
void ADC_Init(void)
{
	LPC_SYSCON->PDRUNCFG &= ~(0x1<<4);        // ADC模块上电
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<13);     // 使能ADC时钟
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);     // 使能IOCON时钟

	LPC_IOCON->R_PIO0_11 &= ~0x07;              // 
	LPC_IOCON->R_PIO0_11 |= 0x02;               // 把P0.11引脚设置为AD0功能
	LPC_IOCON->R_PIO0_11 &= ~(3<<3) ;           // 去掉上拉和下拉电阻
	LPC_IOCON->R_PIO0_11 &= ~(1<<7) ;           // 模拟输入模式

	LPC_IOCON->R_PIO1_0 &= ~0x07;              // 
	LPC_IOCON->R_PIO1_0 |= 0x02;               // 把P1.0引脚设置为AD1功能
	LPC_IOCON->R_PIO1_0 &= ~(3<<3) ;           // 去掉上拉和下拉电阻
	LPC_IOCON->R_PIO1_0 &= ~(1<<7) ;           // 模拟输入模式

	LPC_IOCON->R_PIO1_1 &= ~0x07;              // 
	LPC_IOCON->R_PIO1_1 |= 0x02;               // 把P1.1引脚设置为AD2功能
	LPC_IOCON->R_PIO1_1 &= ~(3<<3) ;           // 去掉上拉和下拉电阻
	LPC_IOCON->R_PIO1_1 &= ~(1<<7) ;           // 模拟输入模式

	LPC_IOCON->R_PIO1_2 &= ~0x07;              // 
	LPC_IOCON->R_PIO1_2 |= 0x02;               // 把P1.2引脚设置为AD3功能
	LPC_IOCON->R_PIO1_2 &= ~(3<<3) ;           // 去掉上拉和下拉电阻
	LPC_IOCON->R_PIO1_2 &= ~(1<<7) ;           // 模拟输入模式

	LPC_IOCON->SWDIO_PIO1_3 &= ~0x07;              // 
	LPC_IOCON->SWDIO_PIO1_3 |= 0x02;               // 把P1.3引脚设置为AD4功能
	LPC_IOCON->SWDIO_PIO1_3 &= ~(3<<3) ;           // 去掉上拉和下拉电阻
	LPC_IOCON->SWDIO_PIO1_3 &= ~(1<<7) ;           // 模拟输入模式

	LPC_IOCON->PIO1_4 &= ~0x07;              // 
	LPC_IOCON->PIO1_4 |= 0x01;               // 把P1.4引脚设置为AD5功能
	LPC_IOCON->PIO1_4 &= ~(3<<3) ;           // 去掉上拉和下拉电阻
	LPC_IOCON->PIO1_4 &= ~(1<<7) ;           // 模拟输入模式

	LPC_IOCON->PIO1_10 &= ~0x07;              // 
	LPC_IOCON->PIO1_10 |= 0x01;               // 把P1.10引脚设置为AD6功能
	LPC_IOCON->PIO1_10 &= ~(3<<3) ;           // 去掉上拉和下拉电阻
	LPC_IOCON->PIO1_10 &= ~(1<<7) ;           // 模拟输入模式

	LPC_IOCON->PIO1_11 &= ~0x07;              // 
	LPC_IOCON->PIO1_11 |= 0x01;               // 把P1.11引脚设置为AD7功能
	LPC_IOCON->PIO1_11 &= ~(3<<3) ;           // 去掉上拉和下拉电阻
	LPC_IOCON->PIO1_11 &= ~(1<<7) ;           // 模拟输入模式

	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);    // 关闭IOCON时钟
	LPC_ADC->CR = (0xFF)|                /* bit7:bit0   开启全部通道*/
								(24<<8)|                     /* bit15:bit8  把采样时钟频率设置为2MHz 50/(24+1)*/
	              (1<<16);                    /* 硬件扫描模式 */
}

/********************************************/
/* 函数功能：读取电压值                     */
/* 出口参数：adc_value, 读到的电压值        */
/********************************************/
uint32_t ADC_Read(uint8_t Channel)
{
	uint32_t adc_value=0;

	adc_value = ((LPC_ADC->DR[Channel]>>6)&0x3FF);		
	adc_value = (adc_value*Vref)/1024; // 转换为真正的电压值

	return adc_value;	  // 返回结果
}


//////////////////////////////////////////////////////////



