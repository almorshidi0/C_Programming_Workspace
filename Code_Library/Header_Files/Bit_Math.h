/**
 * @file    Bit_Math.h
 * @author  Muhammad Al-Morshidi (linkedin.com/in/almorshidi0 | muhammad.almorshidi@gmail.com)
 * @brief   Frequently used bit manipulation functions
 * @version 0.1
 * @date    2023-11-10
 * 
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/***** Macro Function Definitions *****/
/* Frequently used bit manipulation functions. */

#define SET_BIT(VAR, BIT_NUM)	   (VAR) |=  (1 << (BIT_NUM))
#define CLR_BIT(VAR, BIT_NUM)	   (VAR) &= ~(1 << (BIT_NUM))
#define GET_BIT(VAR, BIT_NUM)	   (((VAR) >> (BIT_NUM)) & 0x01)
#define TOG_BIT(VAR, BIT_NUM)	   (VAR) ^=  (1 << (BIT_NUM))
#define ROTATE_RIGHT(VAR, SIZE)    ((VAR) = ((VAR) >> 1) | ((VAR) << ((SIZE) - 1)))
#define ROTATE_LEFT(VAR, SIZE)	   ((VAR) = ((VAR) << 1) | ((VAR) >> ((SIZE) - 1)))
#define CLEAR_HIGH_NIBBLE(VAR)     ((VAR) &= (0x0F))
#define CLEAR_LOW_NIBBLE(VAR)      ((VAR) &= (0xF0))

#endif /* BIT_MATH_H_ */