/**
 * @file aux_funcs.h
 * @brief Auxiliar functions and macros
 */

#ifndef AUX_FUNCS_H
#define AUX_FUNCS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Macro to check if the value is in the defines range
 * 
 * @param min Minimum value of the range
 * @param val Value to check
 * @param max Maximum value of the range.
 * 
 * @return True if the given value is in the range, False otherwhise
 */
#define IS_IN_RANGE(min, val, max) ((min <= val) && (val <= max))

/**
 * @brief Macro to check if the value is out of the defines range
 * 
 * @param val Value to check
 * @param min Minimum value of the range
 * @param max Maximum value of the range.
 * 
 * @return True if the given value is out of the range, False otherwhise
 */
#define IS_OUT_OF_RANGE(val, min, max) ((val < min) || (val > max))

#ifdef __cplusplus
}
#endif

#endif // AUX_FUNCS_H