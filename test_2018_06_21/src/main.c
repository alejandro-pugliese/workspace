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
#include "Keyboard.h"
#include "Heartbeat.h"

// TODO: insert other definitions and declarations here


void App(void)
{
	int8_t key;

	key = Keyboard_GetKey();

	if(key!= NO_KEY)
	{
		Lcd_putchar('a');
	}
}

int main(void) {
	SystemInit();

	Scheduler_Init(1);

    Keyboard_Init(STANDARD_KEYBOARD);
    Heartbeat_Init();
    Lcd_Init();


    //AGREGAR TAREAS AL SCHEDULER
    Scheduler_AddTask(&Keyboard_Update, 5);
    Scheduler_AddTask(&Lcd_Update, 10);
    Scheduler_AddTask(&App,1);
    Scheduler_AddTask(&Heartbeat_Update, 1000);

    //
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
