/**
 * @file cat021_item072.h
 * @brief Definition of item 072 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM072_H
#define CAT021_ITEM072_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define CAT021_ITEM072_LSB_TAV    (1.0/128.0)     /// @brief LSB = 1/128 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef cat021_item072
 * @brief Category 021 / Item 072 - Time of Applicability for Velocity
 * 
 * Time of applicability (measurement) of the reported velocity, in  
 * the form of elapsed time since last midnight, expressed as UTC.
 */
typedef struct cat021_item072 {
    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[3];
        
        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
        
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /** 
             * @brief Time of Applicability for Velocity (LSB = 1/128 sec)
             */
            uint8_t TAV[3];
        };
    };
} cat021_item072;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Time of Applicability for Velocity raw value from Cat 021 Item 072.
 *
 * Combines the 3 raw bytes into a 24-bit unsigned integer.
 *
 * @param item Pointer to cat021_item072 structure.
 * @return uint32_t Time in units of 1/128 s (0 = midnight).
 */
ASTERIX_API uint32_t get_cat021_item072_TAV_raw(const cat021_item072 * item);

/**
 * @brief Get the Time of Applicability for Velocity in seconds (floating-point)
 *        from Cat 021 Item 072.
 *
 * Divides the raw 1/128-s units by 128.0 to return seconds since midnight.
 *
 * @param item Pointer to cat021_item072 structure.
 * @return double Time in seconds (>= 0).
 */
ASTERIX_API double get_cat021_item072_TAV_seconds(const cat021_item072 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of Applicability for Velocity raw value into Cat 021 Item 072.
 *
 * Stores the 24-bit value into the raw array.
 *
 * @param item Pointer to cat021_item072 structure.
 * @param raw_value Raw 24-bit time value to store (units of 1/128 s).
 */
ASTERIX_API void set_cat021_item072_TAV_raw(cat021_item072 * item,
                                            const uint32_t raw_value);

/**
 * @brief Set the Time of Applicability for Velocity in seconds into Cat 021 Item 072.
 *
 * Converts the seconds value into 1/128-s units and stores as raw data.
 *
 * @param item Pointer to cat021_item072 structure.
 * @param seconds Time in seconds (will be converted to 1/128-s units).
 */
ASTERIX_API void set_cat021_item072_TAV_seconds(cat021_item072 * item,
                                                const double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT021 Item 072 (Time of Applicability Velocity).
 * 
 * Prints both the raw value and the converted time in seconds.
 * 
 * @param item Pointer to cat021_item072_t structure.
 */
ASTERIX_API void print_cat021_item072(const cat021_item072 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM072_H */