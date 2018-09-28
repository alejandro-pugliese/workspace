/*******************************************************************************************************************************//**
 *
 * @file		Debug.h
 * @brief		Habilitación / Deshabilitación de chequeo de parámetros de la libreria
 * @date		22/05/2016
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef DEBUG_H_
#define DEBUG_H_

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include <stdint.h>


/***********************************************************************************************************************************
 *** MACROS
 **********************************************************************************************************************************/
/* La compilación para Debug genera la verificación de parametros. La compilación para Release no lo hace */
#if DEBUG
#define CHECK_PARAM(expr) ((expr) ? (void)0 : Debug_CheckFailed((uint8_t *)__FILE__, __LINE__))
#else
#define CHECK_PARAM(expr)
#endif


/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES
 **********************************************************************************************************************************/
void Debug_CheckFailed(uint8_t *file, uint32_t line);


/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* DEBUG_H_ */

