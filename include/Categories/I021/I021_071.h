/**
 * @file I021_071.h
 * @brief Definition of item 071 of CAT 021, and related functions and values
 */

#ifndef I021_071_H
#define I021_071_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_071_LSB_TAP             (1.0/128.0)     /// LSB = 128 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_071
 * @brief Category 021 / Item 071 -  Time of Applicability for Position
 * 
 * Time of applicability of the reported position, in the form of
 * elapsed time since last midnight, expressed as UTC.
 */
typedef struct I021_071 {
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
             * @brief Time of Applicability for Position (LSB = 1/128 sec)
             */
            uint8_t TAP[3];
        };
    };
} I021_071;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Time of Applicability for Position raw value from I021/071.
 *
 * Combines the 3 raw bytes into a 24-bit unsigned integer.
 *
 * @param item Pointer to I021_071 structure.
 * @return uint32_t Time in units of 1/128 s (0 = midnight).
 */
ASTERIX_API uint32_t get_I021_071_TAP_raw(const I021_071 * item);

/**
 * @brief Get the Time of Applicability for Position in seconds (floating-point)
 *        from I021/071.
 *
 * Divides the raw 1/128-s units by 128.0 to return seconds since midnight.
 *
 * @param item Pointer to I021_071 structure.
 * @return double Time in seconds (>= 0).
 */
ASTERIX_API double get_I021_071_TAP_seconds(const I021_071 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of Applicability for Position raw value into I021/071.
 *
 * Stores the 24-bit value into the raw array.
 *
 * @param item Pointer to I021_071 structure.
 * @param raw_value Raw 24-bit time value to store (units of 1/128 s).
 */
ASTERIX_API void set_I021_071_TAP_raw(I021_071 * item, const uint32_t raw_value);

/**
 * @brief Set the Time of Applicability for Position in seconds into I021/071.
 *
 * Converts the seconds value into 1/128-s units and stores as raw data.
 *
 * @param item Pointer to I021_071 structure.
 * @param seconds Time in seconds (will be converted to 1/128-s units).
 */
ASTERIX_API void set_I021_071_TAP_seconds(I021_071 * item, const double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021_071 (Time of Applicability Position).
 * 
 * Prints both the raw value and the converted time in seconds.
 * 
 * @param item Pointer to I021_071 structure.
 */
ASTERIX_API void print_I021_071(const I021_071 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_071_H */