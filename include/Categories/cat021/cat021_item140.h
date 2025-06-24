/**
 * @file cat021_item140.h
 * @brief Definition of CAT 021 Item 140, and related functions and values
 */

#ifndef CAT021_ITEM140_H
#define CAT021_ITEM140_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Macros
 ******************************************************************************/

#define LSB_CAT021_ITEM140          (double) (6.25)         /// LSB = 6.25 ft

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item140
 * @brief Category 021 Item 140 - Geometric Height
 * 
 * Minimum height from a plane tangent to the earth’s ellipsoid, defined by
 * WGS-84, in two's complement form.
 */
typedef struct cat021_item140 {
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
} cat021_item140;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Geometric Height (GH) from Cat 021 Item 140 
 * 
 * @param item Pointer to cat021_item140 structure
 * 
 * @return double Geometric Height in steps of 6.26 feets (see LSB)
 */
ASTERIX_API double get_cat021_item140_GH_raw(const cat021_item140 * item);

/**
 * @brief Get the Geometric Height (GH) from Cat 021 Item 140 
 * 
 * @param item Pointer to cat021_item140 structure
 * 
 * @return double Geometric Height in feets
 */
ASTERIX_API double get_cat021_item140_GH_feet(const cat021_item140 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Geometric Height (GH) raw value (no LSB) into
 *        Cat 021 Item 140 
 * 
 * @param item Pointer to cat021_item140 structure
 * @param value New GH raw value in steps of 6.25 feets (see LSB)
 */
ASTERIX_API void set_cat021_item140_GH_raw(cat021_item140 * item,
                                           uint16_t gh_raw);

/**
 * @brief Set the given Geometric Height (GH) real value (see LSB) into
 *        Cat 021 Item 140
 * 
 * @param item Pointer to cat021_item140 structure
 * @param value New GH value in feets (LSB = 6.25 ft)
 */
ASTERIX_API void set_cat021_item140_GH_feet(cat021_item140 * item,
                                            double gh);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Geometric Height of the Cat 021 Item 140
 * 
 * @param item Pointer to cat021_item140 structure
 */
ASTERIX_API void print_cat021_item140(const cat021_item140 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM140_H */