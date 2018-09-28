/*****************************************************************************************************//**
*
* @file		salidasdigitales_infotronic.c
* @brief	Módulo para manejo de las 5 salidas digitales.
*
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
#include "gpio.h"
#include "My_Types.h"
#include "salidasdigitales_infotronic.h"

/********************************************************************************************************
*** PRIVATE DEFINES
********************************************************************************************************/
#define SALIDA_0_HW_PORT PORT_2
#define SALIDA_0_HW_PIN  PIN_0
#define SALIDA_1_HW_PORT PORT_0
#define SALIDA_1_HW_PIN PIN_23

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
*** PUBLIC FUNCTIONS
********************************************************************************************************/
/***************************************************************************//**
 * @fn			SALIDASDIGITALES_INFOTRONIC_Inicializar()
 * @brief		Inicializa los pines del teclado fijo 5x1.
 *
 * @param[in]	None
 *
 * @return 		void
 ******************************************************************************/
void SALIDASDIGITALES_INFOTRONIC_Inicializar()
{
	GPIO_InitPinAsGPIO(SALIDA_0_HW_PORT, SALIDA_0_HW_PIN, DIR_OUT, RES_NONE, NOT_OPEN_DRAIN);
	GPIO_InitPinAsGPIO(SALIDA_1_HW_PORT, SALIDA_1_HW_PIN, DIR_OUT, RES_NONE, NOT_OPEN_DRAIN);
}

/***************************************************************************//**
 * @fn			TECLADOFIJO_INFOTRONIC_LeerTecla()
 * @brief		Setea el estado de la salida.
 * 				Importante: Logica Positiva
 *
 * @param[in]	SALIDAS: salida a encender o apagar.
 *
 * @param[in]	DIGITAL_STATE: encendido o apagado.
 *
 * @return 		devuelve true si la tecla esta precionada
 ******************************************************************************/
void SALIDASDIGITALES_SetearEstado(SALIDAS salida, DIGITAL_STATE estado)
{

	switch(salida)
	{
		case SALIDA_0:
			GPIO_SETpINsTATE(SALIDA_0_HW_PORT, SALIDA_0_HW_PIN, ACTIVE_HIGH, estado);
			break;
		case SALIDA_1:
			GPIO_SETpINsTATE(SALIDA_1_HW_PORT, SALIDA_1_HW_PIN, ACTIVE_HIGH, estado);
			break;
		default:
			break;
	}

}

bool_t SALIDASDIGITALES_LeerEstado(SALIDAS salida)
{
	bool_t retval = FALSE;

	switch(tecla)
	{
		case SALIDA_0:
			retval = GPIO_GETpINsTATE(SALIDA_0_HW_PORT, SALIDA_0_HW_PIN, ACTIVE_LOW);
			break;
		case SALIDA_1:
			retval = GPIO_GETpINsTATE(SALIDA_1_HW_PORT, SALIDA_1_HW_PIN, ACTIVE_LOW);
			break;
		default:
			break;
	}

	return retval;
}
/********************************************************************************************************
*** PRIVATE FUNCTIONS
********************************************************************************************************/


/*-----------------------------------------------------------------------------------------------------*/
