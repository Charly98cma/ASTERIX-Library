/**
 * @file cat021_item016.h
 * @brief Definition of item 016 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM016_H
#define CAT021_ITEM016_H

#include <stdint.h>
#include "visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define LSB_CAT021_ITEM016_RP       (double) (1/P2_1)       /// LSB = 0.5

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item016
 * @brief Category 021 / Item 016 - Service Management
 * 
 * Identification of services offered by a ground station
 * (identified by a SIC code)
 */
typedef struct cat021_item016 {
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
             * @brief Report Period (direct access)
             * 
             * Range: 0 … 127.5 seconds (value of 127.5 indicates 127.5 or more)
             * 
             * LSB = 0.5 s
             */
            uint8_t RP      :8;
        };
    };
} cat021_item016;

/*******************************************************************************
 * Function Headers
 ******************************************************************************/

ASTERIX_API uint8_t get_cat021_item016_RP(const cat021_item016 * item);

ASTERIX_API void print_cat021_item016(const cat021_item016 *item);

ASTERIX_API double get_cat021_item016_RP_seconds(const cat021_item016 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM016_H */