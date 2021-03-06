/*******************************************************************************************************************************//**
 *
 * @file		SysTick.h
 * @brief		Módulo para el manejo del Timer del Sistema (SysTick)
 * @date		22/05/2016
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef SYSTICK_H_
#define SYSTICK_H_

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/

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
 * @fn			void SysTick_Init(uint32_t time_ms)
 * @brief		Inicializa el Timer del Sistema (SysTick) para interrumpir periodicamente
 * @param[in]	time_ms:	Periodo de interrupción expresado en milisegundos.
 * @return		void
 **********************************************************************************************************************************/
void SysTick_Init(uint32_t time_ms);

/*******************************************************************************************************************************//**
 * @fn			void SysTick_Handler(void)
 * @brief		Funcion de Interrupción. Debe ser implementada por el usuario del módulo.
 * @param		void
 * @return		void
 **********************************************************************************************************************************/
void SysTick_Handler(void);

/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* SYSTICK_H_ */


