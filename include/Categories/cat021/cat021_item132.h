/**
 * @file cat021_item132.h
 * @brief Definition of CAT 021 Item 132, and related functions and values
 */

#ifndef CAT021_ITEM132_H
#define CAT021_ITEM132_H

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
 * @typedef cat021_item132
 * @brief Category 021 Item 132 - Message Amplitude
 * 
 * Amplitude, in dBm, of ADS-B messages received by the ground  station,
 * coded in two's complement.
 */
typedef struct cat021_item132 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Message Amplitude (LSB = 1 dBm)
            uint8_t MAM;
        };
    };
} cat021_item132;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Message Amplitude (MAM) from Cat 021 Item 131 
 * 
 * @param item Pointer to cat021_item132 structure
 * @return double Message Amplitude in dBm (LSB = 1 dBm)
 */
ASTERIX_API uint8_t get_cat021_item132_MAM(const cat021_item132 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Message Amplitude (MAM) new value into Cat 021 Item 131 
 * 
 * @param item Pointer to cat021_item132 structure
 * @param value New MAM value in dBm's (LSB = 1 dBm)
 */
ASTERIX_API uint8_t set_cat021_item132_MAM(cat021_item132 * item, uint8_t value);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT021 Item 132
 * 
 * @param item Pointer to cat021_item132 structure.
 */
ASTERIX_API void print_cat021_item132(const cat021_item132 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM132_H */