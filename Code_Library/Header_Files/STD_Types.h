/**
 * @file    STD_Types.h
 * @author  Muhammad Al-Morshidi (linkedin.com/in/almorshidi0 | muhammad.almorshidi@gmail.com)
 * @brief   New standard types for portability purposes
 * @version 0.1
 * @date    2023-11-10
 * 
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/***** Macro Definitions *****/
/* NULL Macro definition for pointer verification. */
#define NULL ((void *)0)

/***** Special Types *****/
/* New standard types for portability purposes. */

typedef unsigned    char    u8;
typedef unsigned    short   u16;
typedef unsigned    long    u32;
typedef signed      char    s8;
typedef signed      short   s16;
typedef signed      long    s32;
typedef             float   f32;
typedef             double  f64;

/**
 * @brief std_return_t:
 *          Ending status of the function:
 *          - OK      : The function ended successfully.
 *          - NOT_OK  : An error happened during the execution of the function. 
 * 
 */
typedef enum
{
    NOT_OK = 0,
    OK
} std_return_t;

#endif /* STD_TYPES_H_ */