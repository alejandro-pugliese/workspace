/*
 * adc.h
 *
 *  Created on: Sep 16, 2018
 *      Author: agustin
 */

#ifndef ADC_API_ADC_H_
#define ADC_API_ADC_H_

#include "stdint.h"

void ADC_Init(void);
uint32_t ADC_GetValue(void);

uint32_t ConversionCuentasAVariable(int resultado);

#endif /* ADC_API_ADC_H_ */
