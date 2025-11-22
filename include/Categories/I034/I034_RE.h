/**
 * @file I034_RE.h
 * @brief Definition of I034/RE, and related functions and values
 */

#ifndef I034_RE_H
#define I034_RE_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /* Spare bits set to 0 */
            uint8_t spare;
        };
    };
} I034_RE;

/*******************************************************************************
 * Getters
 ******************************************************************************/


/*******************************************************************************
 * Setters
 ******************************************************************************/


/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/


/*******************************************************************************
 * Other Functions
 ******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* I034_RE_H */