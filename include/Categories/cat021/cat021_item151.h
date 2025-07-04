/**
 * @file cat021_item151.h
 * @brief Definition of CAT 021 Item 151, and related functions and values
 */

#ifndef CAT021_ITEM151_H
#define CAT021_ITEM151_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM151_LSB_TAS          (1.0)                   /// LSB = 1 knot

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item151
 * @brief Category 021 Item 151 - True Air Speed
 * 
 * True Air Speed.
 * 
 * @note The RE-Bit, if set, indicates that the value to be transmitted
 *       is beyond the range defined for this specific data item and the
 *       applied technology. In this case the True Air Speed contains the
 *       maximum value that can be downloaded from the aircraft avionics and
 *       the RE-bit indicates that the actual value is greater than the value
 *       contained in the field.
 */
typedef struct cat021_item151 {
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
             * @brief True Air Speed
             * 
             * LSB = 1 knot
             */
            uint16_t TAS    :15;
        };
    };
} cat021_item151;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Range Exceeded Indicator (RE) from Cat 021 Item 151
 * 
 * @param item Pointer to cat021_item151 structure
 * 
 * @return uint8_t Range Exceeded Indicator value (0: in range,
 *                                                 1: exceeds range)
 */
ASTERIX_API uint8_t get_cat021_item151_RE(const cat021_item151 * item);

/**
 * @brief Get the True Air Speed (TAS) from Cat 021 Item 151 
 * 
 * @param item Pointer to cat021_item151 structure
 * 
 * @return uint16_t True Air Speed value in knots (LSB = 1 knot)
 */
ASTERIX_API uint16_t get_cat021_item151_TAS(const cat021_item151 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Range Exceeded Indicator (RE) value into
 *        Cat 021 Item 151
 * 
 * @param item Pointer to cat021_item151 structure
 * @param re New RE indicator (0: within range, 1: exceeds range)
 */
ASTERIX_API void set_cat021_item151_RE(cat021_item151 * item, const uint8_t re);

/**
 * @brief Set the given True Air Speed (TAS) value (LSB = 1 knot) into
 *        Cat 021 Item 151
 * 
 * @param item Pointer to cat021_item151 structure
 * @param tas New True Air Speed in knots
 */
ASTERIX_API void set_cat021_item151_TAS(cat021_item151 * item, const uint16_t tas);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the True Air Speed data of the Cat 021 Item 151
 * 
 * @param item Pointer to cat021_item151 structure
 */
ASTERIX_API void print_cat021_item151(const cat021_item151 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM151_H */