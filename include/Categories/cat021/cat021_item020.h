/**
 * @file cat021_item020.h
 * @brief Definition of item 020 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM020_H
#define CAT021_ITEM020_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"

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
            uint8_t ECAT;
        };
    };
} cat021_item020;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Emitter Category (ECAT) from CAT 021 Item 020.
 * 
 * Portable access to the ECAT bits, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item020 structure.
 * @return uint8_t Value of ECAT (0: not active, 1: active)
 */
ASTERIX_API uint8_t get_cat021_item020_ECAT(const cat021_item020 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Emitter Category (ECAT) value into CAT 021 Item 020
 * 
 * @param item Pointer to cat021_item020 structure.
 * @param sic_value Value of ECAT
 */
ASTERIX_API void set_cat021_item020_ECAT(cat021_item020 * item, uint8_t value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 020.
 *
 * This function prints the values of the main byte.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a cat021_item020 structure.
 */
ASTERIX_API void print_cat021_item020(const cat021_item020 *item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM020_H */