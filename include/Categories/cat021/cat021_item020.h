/**
 * @file cat021_item020.h
 * @brief Definition of item 020 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM020_H
#define CAT021_ITEM020_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item020
 * @brief Category 021 / Item 020 - Emitter Category
 * 
 * Characteristics of the originating ADS-B unit
 */
typedef struct cat021_item020 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** 
             * @brief Emitter Category
             * 
             * Refer to category codes for detailed meaning.
             */
            uint8_t ECAT        :8;
        };
    };
} cat021_item020;

/*******************************************************************************
 * Function Headers
 ******************************************************************************/

ASTERIX_API uint8_t get_cat021_item020_ECAT(const cat021_item020 * item);

ASTERIX_API void print_cat021_item020(const cat021_item020 *item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM020_H */