/*
===============================================================================
 Name        : test_2018_06_21.c
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


// TODO: insert other include files here
#include "Lcd.h"
#include "Scheduler.h"
#include "DigInp.h"
#include "DigOut.h"
#include "Keyboard.h"
#include "defines.h"
#include "Heartbeat.h"


// TODO: insert other definitions and declarations here
static int tick[MAX_SENS];

void App(void)
{
	int8_t key;

	key = Keyboard_GetKey();

	if(key!= NO_KEY)
	{
		Lcd_putchar('a');
	}


}


//Sensores_Init()

//Sensores_GetEstado()

// Sensores_Update()
void MaqEstSensores()
{
	int nro_sensor;



	for(nro_sensor=0;nro_sensor<MAX_SENS;nro_sensor++)
	{
		if(DigInp_GetInputState(nro_sensor)==TRUE)
			{
				if(tick > 0)
				{//--tick[nro_sensor];
					if(--tick[nro_sensor]==0)
					{
						DigOut_SetState(nro_sensor, !0);
					}
				}
			}
			else
			{
				tick[nro_sensor] = 100;
				DigOut_SetState(nro_sensor, 0);
			}

	}

}


int main(void) {
	int nro_sensor;
	unsigned int Rpm;



	//INITS
	SystemInit();
	DigInp_Init();
	DigOut_Init();
	Scheduler_Init(1);
    Keyboard_Init(STANDARD_KEYBOARD);
    Heartbeat_Init();
    Lcd_Init();



    //AGREGAR TAREAS AL SCHEDULER
    Scheduler_AddTask(&MaqEstSensores, 10);
    Scheduler_AddTask(&DigInp_Update, 5);

//    Scheduler_AddTask(&Lcd_Update, 10);
//    Scheduler_AddTask(&App,1);
    Scheduler_AddTask(&Heartbeat_Update, 1000);

    //Last_State Iniciali

    //Rpm = RPM_Get();
    //

    for(nro_sensor=0;nro_sensor<MAX_SENS;nro_sensor++)
    {
    	tick[nro_sensor]=100;
    }
    Scheduler_Start();

	// TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
    	Scheduler_Dispatcher();
        i++ ;
    }
    return 0 ;
}
