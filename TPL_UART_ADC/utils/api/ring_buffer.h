/*
 * ring_buffer.h
 *
 *  Created on: Apr 3, 2016
 *      Author: agustin
 */

#ifndef API_RING_BUFFER_H_
#define API_RING_BUFFER_H_

#include "stdint.h"
/********************************************************************************************************
*** PUBLIC FUNCTION PROTOTYPES
********************************************************************************************************/

/*********************************************************************
 * @brief 		RingBuffer_Init
 * 				 	Initialize the ring buffer. There is only 1 ring
 * 				 	buffer available.
 *
 * @return 		None
 **********************************************************************/
int RingBuffer_Init();

/*********************************************************************
 * @brief 		RB_Push_Data
 * 				 	Stores one data into the ring buffer.
 * 				 	The buffer is 256 Bytes long.
 *
 * @param[in]	data: the byte to store.
 *
 * @return 		 1: Ok
 * 				-1: Buffer is full.
 *
 **********************************************************************/
int RingBuffer_PushData(uint8_t data);

/*********************************************************************
 * @brief 		RB_Pop_Data
 * 				 	Retrieves/get the information from store.
 *
 * @param[in]	data:   pointer to where the information will
 * 					be copied. Memmory allocation needs to be done
 * 					previously to the call to this function.
 *
 * @return 		 1: Ok
 * 				-1: Buffer is empty.
 *
 **********************************************************************/
int RingBuffer_PopData(uint8_t* data);


/*********************************************************************
 * @brief 		RB_Push_Data
 * 				 	Stores one data into the ring buffer.
 * 				 	The buffer is 256 Bytes long.
 *
 * @param[in]	data: the byte to store.
 *
 * @return 		 1: Ok
 * 				-1: Buffer is full.
 *
 **********************************************************************/
int PushTx(uint8_t data);

/*********************************************************************
 * @brief 		RB_Pop_Data
 * 				 	Retrieves/get the information from store.
 *
 *
 * @return
 * 				-1: Buffer is empty.
 * 			     x: Last buffer value
 *
 **********************************************************************/
int UART_PopTx(void);

#endif /* API_RING_BUFFER_H_ */
