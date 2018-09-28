/*
 * procesar_trama.c
 *
 *  Created on: Sep 16, 2018
 *      Author: agustin
 */
#include "stdint.h"
#include "adc.h"
#include "salidasdigitales_infotronic.h"


void Mde_Procesar_Trama(uint8_t datorx){
	//Implementar el procesamiento de trama.

	volatile uint8_t aux;
	volatile uint32_t tmp_cmd;


	if(datorx == '$') //testeo  que $ primer caracter
	{
		aux=1;
		return;
	}


	if(aux ==1 )
	{
		switch(datorx)
		{
			case 'A':
						aux=2;
						tmp_cmd=datorx;
						break;
			case 'B':
						aux=2;
						tmp_cmd=datorx;
						break;
			case 'C':
						aux=2;
						tmp_cmd=datorx;
						break;
			default:
						aux=0;
						break;

		}
	}

	if (aux==2)
	{
		if(datorx == '#')
		{
			switch(tmp_cmd)
			{
					case 'A':
								EnviarEstadoEntradas();
								break;
					case 'B':
								EnviarEstadoADC();
								break;
					case 'C':
								InversorEstado();
								break;
			}

		}
		else
		{
				aux=0;
				return;
		}
	}

}

void EnviarEstadoEntradas(){
	//Armar la trama de respuesta para el Estado de Entradas y enviarlo
	uint8_t array[2];

	PushTx('$');

	PushTx('A');

	if(TECLADOFIJO_INFOTRONIC_LeerTecla(SW3)==1)
	{
		PushTx('1');
	}
	else
	{
		PushTx('0');
	}
	if(TECLADOFIJO_INFOTRONIC_LeerTecla(SW10)==1)
	{
		PushTx('1');
	}
	else
	{
		PushTx('0');
	}

	PushTx('#');
}

void EnviarEstadoADC(){
	//Armar la trama de Estado de ADC y enviarlo.

	PushTx('$');
	PushTx('B');
	PushTx((uint8_t)(ConversionCuentasAVariable()&(0xFF))); //bits 0-7
	PushTx((uint8_t)((ConversionCuentasAVariable()&(0xFF00))>>8)); //bits 8-15
	PushTx('#');

}


void InversorEstado(void)
{
	if(SALIDASDIGITALES_LeerEstado(SALIDA_0))
	{
		SALIDASDIGITALES_SetearEstado(SALIDA_0,OFF);
	}
	else
	{
		SALIDASDIGITALES_SetearEstado(SALIDA_0,ON);
	}

}
