/**
 * @file I021_152.h
 * @brief Definition of I021/152, and related functions and values
 */

#ifndef I021_152_H
#define I021_152_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_152_LSB_TAS         (360.0/P2_16)  /// LSB = 360/2^16 degrees

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_152
 * @brief Category 021 Item 152 - Magnetic Heading
 * 
 * Magnetic Heading (Element of Air Vector).
 * 
 * @note True North Heading is defined in the Reserved Expansion Field
 *       in the subfield TNH.
 */
typedef struct I021_152 {
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
} I021_152;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Magnetic Heading in degrees from I021/152 
 * 
 * @param item Pointer to I021_152 structure
 * 
 * @return double magnetic heading in degrees (see LSB)
 */
ASTERIX_API double get_I021_152_MH(const I021_152 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Magnetic Heading value in degrees (see LSB) into
 *        I021/152
 * 
 * @param item Pointer to I021_152 structure
 * @param tas New magnetic heading in degrees
 */
ASTERIX_API void set_I021_152_MH(I021_152 * item, const double tas);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Magnetic Heading value of the I021/152
 * 
 * @param item Pointer to I021_152 structure
 */
ASTERIX_API void print_I021_152(const I021_152 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_152_H */