/**
 * @file cat021_item131.h
 * @brief Definition of CAT 021 Item 131, and related functions and values
 */

#ifndef CAT021_ITEM131_H
#define CAT021_ITEM131_H

#include <stdio.h>
#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif


/*******************************************************************************
 * Macros
 ******************************************************************************/

#define LSB_CAT021_ITEM131_LAT      (double) (180/P2_30)    /// LSB = 1/2^30 deg
#define LSB_CAT021_ITEM131_LON      (double) (180/P2_30)    /// LSB = 1/2^30 deg

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item131
 * @brief Category 021 Item 131 - High-Resolution Position in WGS-84 Co-ordinates
 * 
 *  High-Resolution Position in WGS-84 Co-ordinates
 */
typedef struct cat021_item131 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[8];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** @brief Latitude in WGS-84 in two's complement (LSB = 180/2^30 deg.)
             * 
             * Range = -90 <= latitude <= 90 deg.
             */
            uint8_t LAT[4];
            /** @brief Longitude in WGS-84 in two's complement (LSB = 180/2^30 deg.)
             * 
             * Range -180 <= longitude < 180 deg.
             */
            uint8_t LON[4];
        };
    };
} cat021_item131;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the target Latitude in WGS-84 coordinates from Cat 021 Item 131 
 * 
 * @param item Pointer to cat021_item131 structure
 * @return double High-resolution latitude value in degrees (see LSB)
 */
ASTERIX_API double get_cat021_item131_LAT(const cat021_item131 * item);

 /**
 * @brief Get the target Longitude in WGS-84 coordinates from Cat 021 Item 131 
 * 
 * @param item Pointer to cat021_item131 structure
 * @return double High-resolution longitude value in degrees (see LSB)
 */
ASTERIX_API double get_cat021_item131_LON(const cat021_item131 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new Latitude in High-Resolution Position in WGS-84
 *        coordinates into Cat 021 Item 130
 * 
 * @param item Pointer to cat021_item131 structure
 * @param lan New high-resolution latitude value in degrees's (see LSB)
 */
ASTERIX_API double set_cat021_item131_LAT(cat021_item131 * item, double lat);

/**
 * @brief Set the new Longitude in High-Resolution Position in WGS-84
 *        coordinates into Cat 021 Item 130 
 * 
 * @param item Pointer to cat021_item131 structure
 * @param lan New high-resolution longitude value in degrees's (see LSB)
 */
ASTERIX_API double set_cat021_item131_LON(cat021_item131 * item, double lon);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT021 Item 131
 * 
 * @param item Pointer to cat021_item131 structure.
 */
ASTERIX_API void print_cat021_item131(const cat021_item131 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM131_H */