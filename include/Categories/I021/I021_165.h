/**
 * @file I021_165.h
 * @brief Definition of I021/165, and related functions and values
 */

#ifndef I021_165_H
#define I021_165_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_165_MAX_VALUE_TAR        16       /// Max. TAR = 16 deg./sec.

#define I021_165_LSB_TAR              (1.0/32.0)  /// LSB = 1/32 deg./sec.

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_165
 * @brief Category 021 Item 165 - Track angle Rate
 * 
 * Rate of Turn, in two's complement form
 * 
 * @note 1. A positive value represents a right turn, whereas a negative value
 *          represents a left turn.
 * @note 2. “Maximum value” means Maximum value or above.
 * @note 3. This item will not be transmitted for the technology
 *          “1090 MHz Extended Squitter”.
 */
typedef struct I021_165 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-16/11 set to 0
            uint16_t spare      :6;
            /**
             * @brief Track Angle Rate
             * 
             * LSB = 1/32 deg./sec.
             * 
             * Maximum value = 16 deg./sec.
             */
            uint16_t TAR        :10;
        };
    };
} I021_165;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Track Angle Rate (TAR) from I021/165
 * 
 * @param item pointer to I021_165 structure
 * 
 * @return double Track Angle Rate in degrees/second
 */
ASTERIX_API double get_I021_165_TAR(const I021_165 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Track Angle Rate (TAR) into I021/165
 * 
 * @param item pointer to I021_165 structure
 * @param tar new Track Angle Rate in degrees/second (LSB = 1/32 deg/sec.
 *                                                    Max value = 16 deg/sec)
 */
ASTERIX_API void set_I021_165_TAR(I021_165 * item, const double tar);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Track Angle Rate of the I021/165
 * 
 * @param item pointer to I021_165 structure
 */
ASTERIX_API void print_I021_165(const I021_165 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_165_H */