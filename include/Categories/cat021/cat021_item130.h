/**
 * @file cat021_item130.h
 * @brief Definition of CAT 021 Item 130, and related functions and values
 */

#ifndef CAT021_ITEM130_H
#define CAT021_ITEM130_H

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

#define LSB_CAT021_ITEM130_LAT      (double) (180/P2_23)    /// LSB = 1/2^23 deg
#define LSB_CAT021_ITEM130_LON      (double) (180/P2_23)    /// LSB = 1/2^23 deg

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item130
 * @brief Category 021 Item 130 - Position in WGS-84 Co-ordinates
 * 
 * Position in WGS-84 Co-ordinates
 */
typedef struct cat021_item130 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[6];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** @brief Latitude in WGS-84 in two's complement (LSB = 180/2^23 deg.)
             * 
             * Range = -90 <= latitude <= 90 deg.
             */
            uint8_t LAT[3];
            /** @brief Longitude in WGS-84 in two's complement (LSB = 180/2^23 deg.)
             * 
             * Range -180 <= longitude < 180 deg.
             */
            uint8_t LON[3];
        };
    };
} cat021_item130;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the target Latitude in WGS-84 coordinates from Cat 021 Item 130 
 * 
 * @param item Pointer to cat021_item130 structure
 * @return double Latitude value in degrees (see LSB)
 */
ASTERIX_API double get_cat021_item130_LAT(const cat021_item130 * item);

 /**
 * @brief Get the target Longitude in WGS-84 coordinates from Cat 021 Item 130 
 * 
 * @param item Pointer to cat021_item130 structure
 * @return double Longitude value in degrees (see LSB)
 */
ASTERIX_API double get_cat021_item130_LON(const cat021_item130 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new Latitude in WGS-84 coordinates into Cat 021 Item 130
 * 
 * @param item Pointer to cat021_item130 structure
 * @param lan New latitude value in degrees's (see LSB)
 */
ASTERIX_API void set_cat021_item130_LAT(cat021_item130 * item, double lat);

/**
 * @brief Set the new Longitude in WGS-84 coordinates into Cat 021 Item 130 
 * 
 * @param item Pointer to cat021_item130 structure
 * @param lan New longitude value in degrees's (see LSB)
 */
ASTERIX_API void set_cat021_item130_LON(cat021_item130 * item, double lon);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT021 Item 130
 * 
 * @param item Pointer to cat021_item130 structure.
 */
ASTERIX_API void print_cat021_item130(const cat021_item130 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM130_H */