/**
 * @file I021_155.h
 * @brief Definition of I021/155, and related functions and values
 */

#ifndef I021_155_H
#define I021_155_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_155_LSB_BVR                (6.25)  /// LSB = 6.25 feet/minute

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_155
 * @brief Category 021 Item 155 - Barometric Vertical Rate
 * 
 * Barometric Vertical Rate, in two's complement form
 * 
 * @note The RE-Bit, if set, indicates that the value to be transmitted is 
 *       beyond the range defined for this specific data item and the 
 *       applied technology. In this case the Barometric Vertical Rate 
 *       contains the maximum value that can be downloaded from the 
 *       aircraft avionics and the RE-bit indicates that the actual value is 
 *       greater than the value contained in the field. 
 */
typedef struct I021_155 {
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
            uint16_t RE     :1;
            /**
             * @brief Barometric Vertical Rate
             * 
             * LSB = 6.25 feet/minute
             */
            uint16_t BVR    :15;
        };
    };
} I021_155;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Range Exceeded Indicator (RE) from I021/155
 * 
 * @param item Pointer to I021_155 structure
 * 
 * @return uint8_t Range Exceeded Indicator value (0: in range,
 *                                                 1: exceeds range)
 */
ASTERIX_API uint8_t get_I021_155_RE(const I021_155 * item);

/**
 * @brief Get the Barometric Vertical Rate (BVR) from I021/155 
 * 
 * @param item Pointer to I021_155 structure
 * 
 * @return double BVR value in feets/minute (see LSB)
 */
ASTERIX_API double get_I021_155_BVR(const I021_155 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Range Exceeded Indicator (RE) value into
 *        I021/155
 * 
 * @param item Pointer to I021_155 structure
 * @param re New RE indicator (0: within range, 1: exceeds range)
 */
ASTERIX_API void set_I021_155_RE(I021_155 * item, const uint8_t re);

/**
 * @brief Set the given Barometric Vertical Rate (BVR) value (see LSB) into
 *        I021/155
 * 
 * @param item Pointer to I021_155 structure
 * @param bvr New BVR in feets/minute (see LSB)
 */
ASTERIX_API void set_I021_155_BVR(I021_155 * item, const double bvr);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Barometric Vertical Rate data of the I021/155
 * 
 * @param item Pointer to I021_155 structure
 */
ASTERIX_API void print_I021_155(const I021_155 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_155_H */