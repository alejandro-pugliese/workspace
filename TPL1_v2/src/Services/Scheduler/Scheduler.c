/*******************************************************************************************************************************//**
 *
 * @file		Scheduler.c
 * @brief		Módulo para el manejo de tareas periodicas. Esquema simplificado de un gestor de tareas.
 * @date		31/05/2016
 * @author		Daniel J. López Amado <dlopezamado@hotmail.com>
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "Scheduler.h"
#include "SysTick.h"

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
 **********************************************************************************************************************************/
typedef struct
{
	uint32_t period;
	uint32_t timeLeftToRun;
	TaskHandler_t taskHandler;
} Task_t;

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** VARIABLES GLOBLES PRIVADAS AL MODULO
 **********************************************************************************************************************************/
static Task_t Scheduler[MAX_TASKS];			/* Array de Tareas que maneja el Scheduler */
static uint32_t TaskIdx = 0;				/* Indice que indica las tareas que han sido agregadas */
static volatile uint32_t ProcessTheDispatcher = 0;	/* Indica que es tiempo de procesar el Dispatcher */
static uint32_t SchedulerPeriod = 0;		/* Periodo del Scheduler */

/***********************************************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 **********************************************************************************************************************************/
static inline void Scheduler_Update(void);

/*--------------------------------------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************************************
 *** IMPLEMENTACION DE FUNCIONES PUBLICAS
 **********************************************************************************************************************************/
/*******************************************************************************************************************************//**
 * @fn			void Scheduler_Init(uint32_t time_ms)
 * @brief		Inicializa el Scheduler.
 * @param[in]	time_ms:	Periodo de acutualizacion del Scheduler expresado en milisegundos.
 * @return		void
 **********************************************************************************************************************************/
void Scheduler_Init(uint32_t time_ms)
{
	SchedulerPeriod = time_ms;
}

/*******************************************************************************************************************************//**
 * @fn			uint32_t Scheduler_AddTask(TaskHandler_t taskHandler, uint32_t period)
 * @brief		Agrega una tarea.
 * @param[in]	taskHandler: Direccion de memoria de la tarea a ejecutar periodicamente. Debe ser del tipo: void Task(void)
 * @param[in]	period: 	 Periodo en el que se ejecuta la tarea (Expresado en veces del valor configurado en Scheduler_Init())
 * @return		Id de la tarea. Debe ser un numero de 0 a (MAX_TASKS-1). Si retorna MAX_TASKS la tarea no pudo ser agregada
 **********************************************************************************************************************************/
uint32_t Scheduler_AddTask(TaskHandler_t taskHandler, uint32_t period)
{
	uint32_t retVal = MAX_TASKS;

	if (TaskIdx < MAX_TASKS)
	{
		Scheduler[TaskIdx].taskHandler = taskHandler;
		Scheduler[TaskIdx].period = period;
		Scheduler[TaskIdx].timeLeftToRun = period;
		retVal =  TaskIdx;
		TaskIdx++;
	}

	return retVal;
}

/*******************************************************************************************************************************//**
 * @fn			void Scheduler_Start(void)
 * @brief		Comienza a funcionar el Scheduler. Debe ser invocada luego de agregar todas las tareas mediante Scheduler_AddTask()
 * @param	    void
 * @return		void
 **********************************************************************************************************************************/
void Scheduler_Start(void)
{
	SysTick_Init(SchedulerPeriod);
}

/*******************************************************************************************************************************//**
 * @fn			void Scheduler_Dispatcher(void)
 * @brief		Debe ser llamada en el lazo principal, con una frecuecia igual o mayor al periodo configurado en Scheduler_Init()
 * @param	    void
 * @return		void
 **********************************************************************************************************************************/
void Scheduler_Dispatcher(void)
{
	uint32_t taskId;
	bool checkAgaing;

	do
	{
		/* Verifica si es tiempo de procesar el Dispatcher */
		if (ProcessTheDispatcher > 0)
		{
			ProcessTheDispatcher--;
			checkAgaing = true;	/* Como el tiempo fue mayor a cero, luego de recorrer las tareas debe verificar nuevamente */

			/* A cada una de las tareas le decrementa en uno la variale "timeLeftToRun" y verifica si llego o no a cero.
			 * Si llego a cero ejecuta la tarea y recarga nuevamente el contador. Si no llego a cero, no hace nada */
			for (taskId = 0; taskId < TaskIdx; taskId++)
			{
				if (Scheduler[taskId].timeLeftToRun > 0)
				{
					if (--Scheduler[taskId].timeLeftToRun == 0)
					{
						(*Scheduler[taskId].taskHandler)();
						Scheduler[taskId].timeLeftToRun = Scheduler[taskId].period;
					}
				}
			}
		}
		else
		{
			checkAgaing = false;	/* Como el tiempo fue cero aun no es tiempo de procesar el Dispatcher */
		}

	} while (checkAgaing);
}

/***********************************************************************************************************************************
 *** IMPLEMNTACION DE FUNCIONES PRIVADAS AL MODULO
 **********************************************************************************************************************************/
/*******************************************************************************************************************************//**
 * @fn			static inline void Scheduler_Update(void)
 * @brief		Indica que es tiempo de procesar el Dispatcher
 * @param	    void
 * @return		void
 **********************************************************************************************************************************/
static inline void Scheduler_Update(void)
{
	ProcessTheDispatcher++;	/* Indica que es tiempo de Procesar el Dispatcher */
}

/*******************************************************************************************************************************//**
 * @fn			void SysTick_Handler(void)
 * @brief		Funcion de Interrupcion (SysTick).
 * @param	    void
 * @return		void
 **********************************************************************************************************************************/
void SysTick_Handler(void)
{
	Scheduler_Update();
}

/*--------------------------------------------------------------------------------------------------------------------------------*/


