/**
 * @file cat021_item155.h
 * @brief Definition of CAT 021 Item 155, and related functions and values
 */

#ifndef CAT021_ITEM155_H
#define CAT021_ITEM155_H

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

#define LSB_CAT021_ITEM155_BVR      (double) (6.25)  /// LSB = 6.25 feet/minute

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item155
 * @brief Category 021 Item 155 - Barometric Vertical Rate
 * 
 * The RE-Bit, if set, indicates that the value to be transmitted is 
 * beyond the range defined for this specific data item and the 
 * applied technology. In this case the Barometric Vertical Rate 
 * contains the maximum value that can be downloaded from the 
 * aircraft avionics and the RE-bit indicates that the actual value is 
 * greater than the value contained in the field. 
 * 
 * Barometric Vertical Rate, in two's complement form
 */
typedef struct cat021_item155 {
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
} cat021_item155;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Range Exceeded Indicator (RE) from Cat 021 Item 155
 * 
 * @param item Pointer to cat021_item155 structure
 * 
 * @return uint8_t Range Exceeded Indicator value (0: in range,
 *                                                 1: exceeds range)
 */
ASTERIX_API uint8_t get_cat021_item155_RE(const cat021_item155 * item);

/**
 * @brief Get the Barometric Vertical Rate (BVR) from Cat 021 Item 155 
 * 
 * @param item Pointer to cat021_item155 structure
 * 
 * @return double BVR value in feets/minute (see LSB)
 */
ASTERIX_API double get_cat021_item155_BVR(const cat021_item155 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Range Exceeded Indicator (RE) value into
 *        Cat 021 Item 155
 * 
 * @param item Pointer to cat021_item155 structure
 * @param re New RE indicator (0: within range, 1: exceeds range)
 */
ASTERIX_API void set_cat021_item155_RE(cat021_item155 * item, uint8_t re);

/**
 * @brief Set the given Barometric Vertical Rate (BVR) value (see LSB) into
 *        Cat 021 Item 155
 * 
 * @param item Pointer to cat021_item155 structure
 * @param bvr New BVR in feets/minute (see LSB)
 */
ASTERIX_API void set_cat021_item155_BVR(cat021_item155 * item, double bvr);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Barometric Vertical Rate data of the Cat 021 Item 155
 * 
 * @param item Pointer to cat021_item155 structure
 */
ASTERIX_API void print_cat021_item155(const cat021_item155 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM155_H */