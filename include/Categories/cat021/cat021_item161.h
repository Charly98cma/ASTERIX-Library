/**
 * @file cat021_item161.h
 * @brief Definition of CAT 021 Item 161, and related functions and values
 */

#ifndef CAT021_ITEM161_H
#define CAT021_ITEM161_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM161_MIN_TRKNUM       (0)     /// @brief Min. track number = 0
#define CAT021_ITEM161_MAX_TRKNUM       (4095)  /// @brief Min. track number = 4095

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item161
 * @brief Category 021 Item 161 - Airborne Ground Vector
 * 
 * An integer value representing a unique reference to a track record within a
 * particular track file
 */
typedef struct cat021_item161 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-16/13 set to 0
            uint16_t spare      :4;
            /// @brief Track number (0 to 4095)
            uint16_t TRKNUM     :12;
        };
    };
} cat021_item161;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Track Number (TRKNUM) from Cat 021 Item 161
 * 
 * @param item pointer to cat021_item161 structure
 * 
 * @return uint16_t track number value
 */
ASTERIX_API uint16_t get_cat021_item161_TRKNUM(const cat021_item161 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Track Number (TRKNUM) into Cat 021 Item 161
 * 
 * @param item pointer to cat021_item161 structure
 * @param track_number New Track Number (0 to 4095)
 */
ASTERIX_API void set_cat021_item161_TRKNUM(cat021_item161 * item,
                                           const uint16_t track_number);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Track Number of the Cat 021 Item 161
 * 
 * @param item pointer to cat021_item161 structure
 */
ASTERIX_API void print_cat021_item161(const cat021_item161 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM161_H */