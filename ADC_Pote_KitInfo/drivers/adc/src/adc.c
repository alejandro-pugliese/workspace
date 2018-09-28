#include "gpio.h"
#include "nvic.h"

#define	ADC_VAL(reg)	((reg>>04)&0x00000FFF)
#define	ADC_DONE(reg)	((reg>>31)&0x00000001)
#define	ADC_CHAN(reg)	((reg>>24)&0x00000007)
#define ADC_ENABLE_INTERRUPT(channel) (1<<channel)

void ADC_Init(){

	//1.- Activo la alimentacion del dispositivo desde el registro PCONP:
	LPC_SC->PCONP |= 1<<12;
	//2.- Selecciono el clock del ADC como 25MHz:
	LPC_SC->PCLKSEL0 &= ~(0x03<<24);
	//3.- Y el divisor como 1, para muestrear a 200kHz:
	LPC_ADC->ADCR &= 0x00000100;
	//Importante: la siguiente configuracion es para el CANAL 5.
	//4.- Configuro los pines del ADC0
	//ADC0.5 (pote) : P1[31]->PINSEL3: 30:31
	GPIO_SetPinFunc(PORT_1, PIN_31, THIRD_ALT_FUNC);
	//5.- NO ACTIVO LAS INTERRUPCIONES:
	LPC_ADC->ADINTEN &= 0xFFFFFE00;
	//6.- Selecciono que voy a tomar muestras del canal AD0.5:
	LPC_ADC->ADCR |= 0x00000020;
	//7.- Activo el ADC (PDN = 1):
	LPC_ADC->ADCR |= 1<<21;
	//8.- Selecciono que el ADC muestree solo, con BURST = 1 y START = 000:
	LPC_ADC->ADCR &= ~(0x0F<<24);
	LPC_ADC->ADCR |= 1<<16;
	//9.- Configuro las interrupciones
	LPC_ADC->ADINTEN |= ADC_ENABLE_INTERRUPT(5);
	//10.- Habilito las interrupciones
	NVIC_EnableIRQ(ADC_IRQn);
}

uint32_t ADC_Read ( void )
{
	static int resultado = 0;
	uint32_t registro;

	registro = LPC_ADC->ADDR5;

	if (ADC_DONE(registro))
		resultado = ADC_VAL(registro);

	return resultado;
}

uint32_t ConversionCuentasAVariable(int resultado)
{
	if(aux == (LPC_ADC->ADGDR <<32))
	{
		aux = LPC_ADC->ADGDR &= 0xFFF0;
		aux = (aux/3723)*1000;
	}
}


