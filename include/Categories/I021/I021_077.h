/**
 * @file I021_077.h
 * @brief Definition of I021/077, and related functions and values
 */

#ifndef I021_077_H
#define I021_077_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_077_LSB_TART       (1.0/128.0) /// @brief LSB = 1/128 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_077
 * @brief Category 021 / Item 077 -  Time of ASTERIX Report Transmission
 * 
 * Time of the transmission of the ASTERIX category 021 report in 
 * the form of elapsed time since last midnight, expressed as UTC.
 */
typedef struct I021_077 {
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
             * @brief  Time of ASTERIX Report Transmission (TART) (LSB = 1/128 sec)
             */
            uint8_t TART[3];
        };
    };
} I021_077;


/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get Time of ASTERIX Report Transmission raw value from I021/077.
 *
 * Combines the 3 raw bytes into a 24-bit unsigned integer.
 *
 * @param item Pointer to I021_077 structure.
 * @return uint32_t Time in units of 1/128 s (0 = midnight).
 */
ASTERIX_API uint32_t get_I021_077_TART_raw(const I021_077 * item);

/**
 * @brief Get the Time of ASTERIX Report Transmission in seconds (floating-point)
 *        from I021/077.
 *
 * Divides the raw 1/128-s units by 128.0 to return seconds since midnight.
 *
 * @param item Pointer to I021_077 structure.
 * @return double Time in seconds (>= 0).
 */
ASTERIX_API double get_I021_077_TART_seconds(const I021_077 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of ASTERIX Report Transmission raw value into I021/077.
 *
 * Stores the 24-bit value into the raw array.
 *
 * @param item Pointer to I021_077 structure.
 * @param raw_value Raw 24-bit time value to store (units of 1/128 s).
 */
ASTERIX_API void set_I021_077_TART_raw(I021_077 * item, const uint32_t raw_value);

/**
 * @brief Set the Time of ASTERIX Report Transmission in seconds into I021/077.
 *
 * Converts the seconds value into 1/128-s units and stores as raw data.
 *
 * @param item Pointer to I021_077 structure.
 * @param seconds Time in seconds (will be converted to 1/128-s units).
 */
ASTERIX_API void set_I021_077_TART_seconds(I021_077 * item, const double seconds);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/077 (Time of ASTERIX Report Transmission).
 * 
 * Prints both the raw value and the converted time in seconds.
 * 
 * @param item Pointer to I021_077_t structure.
 */
ASTERIX_API void print_I021_077(const I021_077 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_077_H */