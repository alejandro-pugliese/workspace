/*
 * ring_buffer.c
 *
 *  Created on: Sep 27, 2018
 *      Author: alejandro
 */

#include "ring_buffer.h"

static uint8_t buffer[256];
int in_counter=0;
int out_counter=0;
int qty_counter=0;

RingBuffer_Init()
{
	for(i=0;i<255;i++)
	{
		buffer[i]=0;
	}
}

PushTx(uint8_t data)
{
	if(qty_counter<256)
	{
		buffer[in_counter]=data;
		in_counter++;
		qty_counter++;
		if(in_counter>=256)
		{
			in_counter=0;
		}

	}

}

UART_PopTx()
{
	uint8_t aux;
	if(qty_counter<=0)
	{
		qty_counter=0;
		return -1;
	}
	else
	{
		aux=buffer[out_counter];
		if(out_counter==255)
		{
			out_counter=0;
			qty_counter--;
		}
		else
		{
			out_counter++;
			qty_counter--;
		}
		//out_counter++;
		//qty_counter--;
		/*if(out_counter>=256)
		{
			out_counter=0;
		}*/
		return (int)aux;

	}

}
