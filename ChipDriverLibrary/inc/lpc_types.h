/*******************************************************************************************************************************//**
 *
 * @file		lpc_types.h
 * @brief		Common types used in LPC functions.
 * @note		Copyright(C) NXP Semiconductors, 2012
 * 				All rights reserved.
 * @par         Software that is described herein is for illustrative purposes only which provides customers with programming
 * 				information regarding the LPC products.  This software is supplied "AS IS" without any warranties of any kind,
 * 				and NXP Semiconductors and its licensor disclaim any and all warranties, express or implied, including all implied
 * 				warranties of merchantability, fitness for a particular purpose and non-infringement of intellectual property rights.
 * 				NXP Semiconductors assumes no responsibility or liability for the use of the software, conveys no license or rights
 * 				under any patent, copyright, mask work right, or any other intellectual property rights in or to any products.
 * 				NXP Semiconductors reserves the right to make changes in the software without notification. NXP Semiconductors also
 * 				makes no representation or warranty that such application will be suitable for the specified use without further
 * 				testing or modification.
 *
 * @par			Permission to use, copy, modify, and distribute this software and its documentation is hereby granted, under
 * 				NXP Semiconductors' and its licensor's relevant copyrights in the software, without fee, provided that it is used in
 * 				conjunction with NXP Semiconductors microcontrollers.  This copyright, permission, and disclaimer notice must appear
 * 				in all copies of this code.
 *
 * @note		Se adapta el formato al utilizado en Informatica II
 *
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef __LPC_TYPES_H_
#define __LPC_TYPES_H_

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include <stdint.h>
#include <stdbool.h>


/***********************************************************************************************************************************
 *** DEFINES
 **********************************************************************************************************************************/
/* NULL pointer */
#ifndef NULL
#define NULL ((void *) 0)
#endif

/* Static data/function define */
#define STATIC static

/* External data/function define */
#define EXTERN extern

/* Inline define */
#ifdef __CC_ARM
#define INLINE  __inline
#else
#define INLINE inline
#endif


/***********************************************************************************************************************************
 *** MACROS
 **********************************************************************************************************************************/
/* _BIT(n) sets the bit at position "n"
 * _BIT(n) is intended to be used in "OR" and "AND" expressions:
 * e.g., "(_BIT(3) | _BIT(7))".
 */
#undef _BIT
/* Set bit macro */
#define _BIT(n) (1 << (n))

/* _SBF(f,v) sets the bit field starting at position "f" to value "v".
 * _SBF(f,v) is intended to be used in "OR" and "AND" expressions:
 * e.g., "((_SBF(5,7) | _SBF(12,0xF)) & 0xFFFF)"
 */
#undef _SBF
/* Set bit field macro */
#define _SBF(f, v) ((v) << (f))

/* _BITMASK constructs a symbol with 'field_width' least significant
 * bits set.
 * e.g., _BITMASK(5) constructs '0x1F', _BITMASK(16) == 0xFFFF
 * The symbol is intended to be used to limit the bit field width
 * thusly:
 * <a_register> = (any_expression) & _BITMASK(x), where 0 < x <= 32.
 * If "any_expression" results in a value that is larger than can be
 * contained in 'x' bits, the bits above 'x - 1' are masked off.  When
 * used with the _SBF example above, the example would be written:
 * a_reg = ((_SBF(5,7) | _SBF(12,0xF)) & _BITMASK(16))
 * This ensures that the value written to a_reg is no wider than
 * 16 bits, and makes the code easier to read and understand.
 */
#undef _BITMASK
/* Bitmask creation macro */
#define _BITMASK(field_width) ( _BIT(field_width) - 1)

/* Number of elements in an array */
#define NELEMENTS(array)  (sizeof(array) / sizeof(array[0]))

#if !defined(MAX)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif
#if !defined(MIN)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif


/***********************************************************************************************************************************
 *** TIPO DE DATOS PUBLICOS
 **********************************************************************************************************************************/
/**
 * @brief Boolean Type definition
 */
typedef enum {FALSE = 0, TRUE = !FALSE} Bool;

/**
 * @brief Flag Status and Interrupt Flag Status type definition
 */
typedef enum {RESET = 0, SET = !RESET} FlagStatus, IntStatus, SetState;
#define PARAM_SETSTATE(State) ((State == RESET) || (State == SET))

/**
 * @brief Functional State Definition
 */
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define PARAM_FUNCTIONALSTATE(State) ((State == DISABLE) || (State == ENABLE))

/**
 * @ Status type definition
 */
typedef enum {ERROR = 0, SUCCESS = !ERROR} Status;


/**
 * Read/Write transfer type mode (Block or non-block)
 */
typedef enum {
	NONE_BLOCKING = 0,		/**< None Blocking type */
	BLOCKING,				/**< Blocking type */
} TRANSFER_BLOCK_T;


/***********************************************************************************************************************************
 *** FIN DEL MODULO
 **********************************************************************************************************************************/

#endif /* __LPC_TYPES_H_ */

