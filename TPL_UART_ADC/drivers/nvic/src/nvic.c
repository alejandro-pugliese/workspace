/****************************************************************************************************//**
*
* @file		nvic.c
* @brief
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
*** INCLUDES
********************************************************************************************************/
#include "LPC17xx.h"
/********************************************************************************************************
*** PRIVATE DEFINES
********************************************************************************************************/

/********************************************************************************************************
*** PRIVATE MACROS
********************************************************************************************************/

/********************************************************************************************************
*** PRIVATE DATA TYPES
********************************************************************************************************/

/********************************************************************************************************
*** PRIVATE TABLES
********************************************************************************************************/

/********************************************************************************************************
*** PUBLIC GLOBAL VARIABLES
********************************************************************************************************/


/********************************************************************************************************
*** PRIVATE GLOBAL VARIABLES
********************************************************************************************************/


/********************************************************************************************************
*** PRIVATE FUNCTION PROTOTYPES
********************************************************************************************************/

/********************************************************************************************************
*** CONFIGURATION ERRORS
********************************************************************************************************/

/*-----------------------------------------------------------------------------------------------------*/

/********************************************************************************************************
*** MODULE FUNCTIONS
********************************************************************************************************/
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
	NVIC->IP[(uint32_t)(IRQn)] = ((priority << 3) & 0xff);
}

void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	NVIC->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* enable interrupt */
}
/********************************************************************************************************
*** INTERNAL MODULE FUNCTIONS
********************************************************************************************************/

/*-----------------------------------------------------------------------------------------------------*/


