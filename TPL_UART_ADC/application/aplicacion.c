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

#include "boardinit.h"
#include "ring_buffer.h"
#include "conversor_temperatura.h"

#include "procesar_trama.h"

int main(void)
{
	uint8_t datorx = 0;
	BoardInit();
	RingBuffer_Init();

	printf("TPL_UART_ADC InfoII R2051\n");

	while (1)
	{
		if( -1 != RingBuffer_PopData(&datorx))
		{
			printf("Rx: %c \n",datorx);
			Mde_Procesar_Trama(datorx);
		}
	}
	return 0;
}

void HandlerSystick500ms()
{

}
