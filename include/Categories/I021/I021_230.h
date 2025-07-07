/**
 * @file I021_230.h
 * @brief Definition of I021/230, and related functions and values
 */

#ifndef I021_230_H
#define I021_230_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_230_LSB_RA           (0.01)      /// LSB = 0.01 degrees

#define I021_230_MIN_RA           (-180.0)    /// Min. Roll Angle = -180.0
#define I021_230_MAX_RA           ( 180.0)    /// Min. Roll Angle =  180.0

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_230
 * @brief Category 021 Item 230 - Roll Angle
 * 
 * The roll angle, in two's complement form, of an aircraft executing a turn.
 * 
 * @note 1. Negative Value indicates “Left Wing Down”.
 * @note 2. Resolution provided by the technology "1090 MHz Extended
 *          Squitter" is 1 degree.
 */
typedef struct I021_230 {
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
} I021_230;


/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Roll Angle value in degrees from I021/230
 * 
 * @param item pointer to I021_230 structure
 * 
 * @return double Roll Angle in degrees (LSB = 0.01 degrees)
 */
ASTERIX_API double get_I021_230_RA(const I021_230 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Sets the given value (ra) as the new Roll Angle into I021/230
 * 
 * @param item pointer to I021_230 structure
 * @param ra new Roll Angle value (LSB = 0.01 degrees) (-180 <= ra <= 180)
 */
ASTERIX_API void set_I021_230_RA(I021_230 * item, const double ra);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Roll Angle data from I021/230
 * 
 * @param item pointer to I021_230 structure
 */
ASTERIX_API void print_I021_230(const I021_230 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_230_H */