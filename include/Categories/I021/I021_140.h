/**
 * @file I021_140.h
 * @brief Definition of I021/140, and related functions and values
 */

#ifndef I021_140_H
#define I021_140_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_140_LSB_GH                   (6.25)         /// LSB = 6.25 ft

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_140
 * @brief Category 021 Item 140 - Geometric Height
 * 
 * Minimum height from a plane tangent to the earth’s ellipsoid, defined by
 * WGS-84, in two's complement form.
 */
typedef struct I021_140 {
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
             * @brief Geometric Height (LSB = 6.25 ft)
             * 
             * -1500 ft <= Geometric Height <= 150000 ft
             */
            uint16_t GH;
        };
    };
} I021_140;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Geometric Height (GH) from I021/140 
 * 
 * @param item Pointer to I021_140 structure
 * 
 * @return double Geometric Height in steps of 6.26 feets (see LSB)
 */
ASTERIX_API uint16_t get_I021_140_GH_raw(const I021_140 * item);

/**
 * @brief Get the Geometric Height (GH) from I021/140 
 * 
 * @param item Pointer to I021_140 structure
 * 
 * @return double Geometric Height in feets
 */
ASTERIX_API double get_I021_140_GH_feet(const I021_140 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Geometric Height (GH) raw value (no LSB) into
 *        I021/140 
 * 
 * @param item Pointer to I021_140 structure
 * @param value New GH raw value in steps of 6.25 feets (see LSB)
 */
ASTERIX_API void set_I021_140_GH_raw(I021_140 * item, const uint16_t gh_raw);

/**
 * @brief Set the given Geometric Height (GH) real value (see LSB) into
 *        I021/140
 * 
 * @param item Pointer to I021_140 structure
 * @param value New GH value in feets (LSB = 6.25 ft)
 */
ASTERIX_API void set_I021_140_GH_feet(I021_140 * item, const double gh);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Geometric Height of the I021/140
 * 
 * @param item Pointer to I021_140 structure
 */
ASTERIX_API void print_I021_140(const I021_140 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_140_H */