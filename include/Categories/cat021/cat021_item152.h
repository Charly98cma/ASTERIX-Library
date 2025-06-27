/**
 * @file cat021_item152.h
 * @brief Definition of CAT 021 Item 152, and related functions and values
 */

#ifndef CAT021_ITEM152_H
#define CAT021_ITEM152_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define LSB_CAT021_ITEM152_TAS  (double) (360/P2_16)  /// LSB = 360/2^16 degrees

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item152
 * @brief Category 021 Item 152 - Magnetic Heading
 * 
 * Magnetic Heading (Element of Air Vector).
 * 
 * @note True North Heading is defined in the Reserved Expansion Field
 *       in the subfield TNH.
 */
typedef struct cat021_item152 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint16_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Range Exceeded Indicator
             * 
             * = 0: value within defined range | = 1: value exceeds defines range
             */
            uint16_t RE;
            /**
             * @brief Magnetic Heading
             * 
             * LSB = 1 knot
             */
            uint16_t TAS;
        };
    };
} cat021_item152;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Magnetic Heading in degrees from Cat 021 Item 152 
 * 
 * @param item Pointer to cat021_item152 structure
 * 
 * @return double magnetic heading in degrees (see LSB)
 */
ASTERIX_API double get_cat021_item152_MH(const cat021_item152 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Magnetic Heading value in degrees (see LSB) into
 *        Cat 021 Item 152
 * 
 * @param item Pointer to cat021_item152 structure
 * @param tas New magnetic heading in degrees
 */
ASTERIX_API void set_cat021_item152_MH(cat021_item152 * item, double tas);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Magnetic Heading value of the Cat 021 Item 152
 * 
 * @param item Pointer to cat021_item152 structure
 */
ASTERIX_API void print_cat021_item152(const cat021_item152 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM152_H */