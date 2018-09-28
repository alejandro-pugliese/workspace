/*
 * boardinit.c
 *
 *  Created on: Aug 16, 2017
 *      Author: agustin
 */
#include "system_LPC17xx.h"
#include "gpio.h"
#include "uart.h"
#include "Systick.h"
#include "adc.h"

#include "salidasdigitales_infotronic.h"
#include "tecladofijo_infotronic.h"

/***************************************************************************//**
 * @fn			BoardInit()
 * @brief		Configura todos los perifericos para trabajar con la placa.
 * 				Arranca el PLL del uC.
 *
 * @param[in]	None
 *
 * @return 		None
 ******************************************************************************/
void BoardInit(void)
{
	SystemInit();
	TIMER_Systick_Init();
	UART_Init();
	ADC_Init();

	SALIDASDIGITALES_INFOTRONIC_Inicializar();
	TECLADOFIJO_INFOTRONIC_Inicializar();
}
