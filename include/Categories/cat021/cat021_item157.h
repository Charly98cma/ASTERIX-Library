/**
 * @file cat021_item157.h
 * @brief Definition of CAT 021 Item 157, and related functions and values
 */

#ifndef CAT021_ITEM157_H
#define CAT021_ITEM157_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM157_LSB_GVR                (6.25)  /// LSB = 6.25 feet/minute

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item157
 * @brief Category 021 Item 157 - Geometric Vertical Rate
 * 
 * Geometric Vertical Rate, in two's complement form, with reference to WGS-84
 * 
 * @note The RE-Bit, if set, indicates that the value to be transmitted is 
 *       beyond the range defined for this specific data item and the 
 *       applied technology. In this case the Geometric Vertical Rate 
 *       contains the maximum value that can be downloaded from the 
 *       aircraft avionics and the RE-bit indicates that the actual value is 
 *       greater than the value contained in the field. 
 */
typedef struct cat021_item157 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

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
             * @brief Geometric Vertical Rate
             * 
             * LSB = 6.25 feet/minute
             */
            uint16_t GVR    :15;
        };
    };
} cat021_item157;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Range Exceeded Indicator (RE) from Cat 021 Item 157
 * 
 * @param item Pointer to cat021_item157 structure
 * 
 * @return uint8_t Range Exceeded Indicator value (0: in range,
 *                                                 1: exceeds range)
 */
ASTERIX_API uint8_t get_cat021_item157_RE(const cat021_item157 * item);

/**
 * @brief Get the Geometric Vertical Rate (GVR) from Cat 021 Item 157 
 * 
 * @param item Pointer to cat021_item157 structure
 * 
 * @return double GVR value in feets/minute (see LSB)
 */
ASTERIX_API double get_cat021_item157_GVR(const cat021_item157 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Range Exceeded Indicator (RE) value into
 *        Cat 021 Item 157
 * 
 * @param item Pointer to cat021_item157 structure
 * @param re New RE indicator (0: within range, 1: exceeds range)
 */
ASTERIX_API void set_cat021_item157_RE(cat021_item157 * item, const uint8_t re);

/**
 * @brief Set the given Geometric Vertical Rate (GVR) value (see LSB) into
 *        Cat 021 Item 157
 * 
 * @param item Pointer to cat021_item157 structure
 * @param GVR New GVR in feets/minute (see LSB)
 */
ASTERIX_API void set_cat021_item157_GVR(cat021_item157 * item, const double GVR);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Geometric Vertical Rate data of the Cat 021 Item 157
 * 
 * @param item Pointer to cat021_item157 structure
 */
ASTERIX_API void print_cat021_item157(const cat021_item157 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM157_H */