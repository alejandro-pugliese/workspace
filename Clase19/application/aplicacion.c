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
#include "uart.h"

int main(void)
{
	volatile char datorx = 0;
	BoardInit();

	printf("Clase Practica Ejemplo UART super simple InfoII R2051\n");

	while (1)
	{
		datorx = UART_PopRx();
		if('\0'!=datorx)
		{
			UART_RxClean();
			printf("Rx: %c \n",datorx);
		}
	}
	return 0;
}

void HandlerSystick500ms()
{
	static uint8_t abc = 0x30;
	UART_PushTx(abc);
	abc++;
	if(abc==0x65){
		abc=0x30;
	}
}
