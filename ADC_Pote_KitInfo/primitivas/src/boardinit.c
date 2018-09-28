/*
 * boardinit.c
 *
 *  Created on: Aug 16, 2017
 *      Author: agustin
 */
#include "system_LPC17xx.h"
#include "gpio.h"
#include "Systick.h"
#include "adc.h"

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
	ADC_Init();
}
