/*
 ===============================================================================
 Name        : CP_Procesar_Trama.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
 ===============================================================================
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>
#include "stdint.h"

#include "boardinit.h"
#include "adc.h"

volatile uint32_t valorADC;

int main(void)
{
	BoardInit();
	printf("Clase Practica Ejemplo ADC InfoII R2054\n");

	while (1)
	{
		valorADC = ADC_Read();

	}
	return 0;
}

void HandlerSystick500ms()
{
	printf("Valor ADC: %d \n", valorADC);
}

void ADC_IRQHandler(){
	valorADC = ADC_Read();
}
