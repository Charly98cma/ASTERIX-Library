/**
 * @file cat021_item230.h
 * @brief Definition of CAT 021 Item 230, and related functions and values
 */

#ifndef CAT021_ITEM230_H
#define CAT021_ITEM230_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM230_LSB_RA           (0.01)      /// LSB = 0.01 degrees

#define CAT021_ITEM230_MIN_RA           (-180.0)    /// Min. Roll Angle = -180.0
#define CAT021_ITEM230_MAX_RA           ( 180.0)    /// Min. Roll Angle =  180.0

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item230
 * @brief Category 021 Item 230 - Roll Angle
 * 
 * The roll angle, in two's complement form, of an aircraft executing a turn.
 * 
 * @note 1. Negative Value indicates “Left Wing Down”.
 * @note 2. Resolution provided by the technology "1090 MHz Extended
 *          Squitter" is 1 degree.
 */
typedef struct cat021_item230 {
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
             * @brief Roll Angle
             * 
             * Range: -180 <= RA <= 180
             * 
             * LSB = 0.01 degree
             */
            uint16_t RA;
        };
    };
} cat021_item230;


/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Roll Angle value in degrees from Cat 021 Item 230
 * 
 * @param item pointer to cat021_item230 structure
 * 
 * @return double Roll Angle in degrees (LSB = 0.01 degrees)
 */
ASTERIX_API double get_cat021_item230_RA(const cat021_item230 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Sets the given value (ra) as the new Roll Angle into Cat 021 Item 230
 * 
 * @param item pointer to cat021_item230 structure
 * @param ra new Roll Angle value (LSB = 0.01 degrees) (-180 <= ra <= 180)
 */
ASTERIX_API void set_cat021_item230_RA(cat021_item230 * item, const double ra);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Roll Angle data from Cat 021 Item 230
 * 
 * @param item pointer to cat021_item230 structure
 */
ASTERIX_API void print_cat021_item230(const cat021_item230 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM230_H */