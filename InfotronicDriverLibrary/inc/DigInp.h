/*******************************************************************************************************************************//**
 *
 * @file		DigInp.h
 * @brief		Modulo para el manejo de Entradas Digitales
 * @date		20/06/2018
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef DIGINP_H_
#define DIGINP_H_

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include <stdint.h>
#include <stdbool.h>

/***********************************************************************************************************************************
 *** DEFINES
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** MACROS
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** TIPO DE DATOS PUBLICOS
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** VARIABLES GLOBALES (extern)
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES
 **********************************************************************************************************************************/

/*******************************************************************************************************************************//**
 * @fn			void DigInp_Init(void)
 * @brief		Inicializa el modulo de Entradas Digitales.
 * @param[in]	void
 * @return		void
 **********************************************************************************************************************************/
void DigInp_Init(void);

/*******************************************************************************************************************************//**
 * @fn			bool DigInp_GetInputState(uint8_t diNum)
 * @brief		Retorna el estado de la entrada digital pasada como parametro.
 * @param[in]	diNum:	Número de entrada digital.
 * @return		true si la entrada esta activa, false en caso contrario.
 **********************************************************************************************************************************/
bool DigInp_GetInputState(uint8_t diNum);

/*******************************************************************************************************************************//**
 * @fn			void DigInp_Update(void)
 * @brief		Debe ser llamada periodicamente cada 5 milisegundos.
 * @param		void
 * @return		void
 **********************************************************************************************************************************/
void DigInp_Update(void);

/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* DIGINP_H_ */


