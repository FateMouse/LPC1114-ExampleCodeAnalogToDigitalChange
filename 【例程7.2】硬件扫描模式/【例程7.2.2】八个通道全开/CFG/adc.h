#ifndef __NXP_ADC_H
#define __NXP_ADC_H

#define  Vref   3300

extern void ADC_Init(void);	   // ��ʼ��ADC��
extern uint32_t ADC_Read(uint8_t Channel);   // ��ȡ��ѹֵ

#endif



