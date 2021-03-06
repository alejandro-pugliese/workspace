/*
 * systick_private.h
 *
 *  Created on: 18/06/2014
 *      Author: Agustin
 */


/*********************************************************************************************************
*
* @file		systick_private.h
* @brief	Módulo para manejo de Temporizaciones.
* @version	1.00
* @date		XX/XX/XXXX
* @author	Agustin G. Gimeno (AGG)
*
*
*********************************************************************************************************
*** REVISION HISTORY
*
********************************************************************************************************/


/********************************************************************************************************
*** MODULE
********************************************************************************************************/
#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

/********************************************************************************************************
*** INCLUDES
********************************************************************************************************/
#include "My_Types.h"

/********************************************************************************************************
*** DEFINES
********************************************************************************************************/
#define CCLK		100000000	//!< Clock expresado en Hz

// Etiquetas que representan tiempos
#define _0msec		           	  (0)
#if (TMR_TICK <= 1)
#define _1msec		     (1/TMR_TICK)
#endif
#if (TMR_TICK <= 10)
#define _10msec		    (10/TMR_TICK)
#endif
#define _20msec		    (20/TMR_TICK)
#define _100msec	   (100/TMR_TICK)
#define _250msec	   (250/TMR_TICK)
#define _500msec	   (500/TMR_TICK)
#define _750msec	   (750/TMR_TICK)
#define _1sec		  (1000/TMR_TICK)
#define _2sec		  (2000/TMR_TICK)
#define _5sec		  (5000/TMR_TICK)
#define _10sec		 (10000/TMR_TICK)
#define _1min		 (60000/TMR_TICK)
#define _2min		(120000/TMR_TICK)
#define _3min		(180000/TMR_TICK)
#define _4min		(240000/TMR_TICK)
#define _5min		(300000/TMR_TICK)
#define _10min		(600000/TMR_TICK)
#define _1hour		(_1min * 60)
#define _24hour		(_1hour * 24)

/********************************************************************************************************
*** MACROS
********************************************************************************************************/


/********************************************************************************************************
*** DATA TYPES
********************************************************************************************************/


/********************************************************************************************************
*** PUBLIC GLOBAL VARIABLES
********************************************************************************************************/
extern volatile Bool Systick_Flag1mSec;
extern volatile Bool Systick_FlagTmrTick;


/********************************************************************************************************
*** INTERNAL MODULE FUNCTION PROTOTYPES
********************************************************************************************************/

/********************************************************************************************************
 * @fn
 * @brief
 *
 * @param[in]
 * @return
********************************************************************************************************/
void timer_Systick_Init(void);

/********************************************************************************************************
 * @fn
 * @brief
 *
 * @param[in]
 * @return
********************************************************************************************************/
void timer_Core(void);

/********************************************************************************************************
*** MODULE END
********************************************************************************************************/

#endif /* SYSTICK_PRIVATE_H_ */
