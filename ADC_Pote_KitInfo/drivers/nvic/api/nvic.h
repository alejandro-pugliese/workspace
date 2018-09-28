/********************************************************************************************************
*** MODULE
********************************************************************************************************/
#ifndef NVIC_API_NVIC_H_
#define NVIC_API_NVIC_H_


/********************************************************************************************************
*** INCLUDES
********************************************************************************************************/

/********************************************************************************************************
*** DEFINES
********************************************************************************************************/

/********************************************************************************************************
*** MACROS
********************************************************************************************************/

/********************************************************************************************************
*** DATA TYPES
********************************************************************************************************/

/********************************************************************************************************
*** PUBLIC GLOBAL VARIABLES
********************************************************************************************************/

/********************************************************************************************************
*** PUBLIC FUNCTION PROTOTYPES
********************************************************************************************************/
void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);


#endif /* NVIC_API_NVIC_H_ */