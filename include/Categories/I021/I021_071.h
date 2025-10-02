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
 * @brief Get the Time of Applicability for Position in seconds (floating-point)
 *        from I021/071.
 *
 * Divides the raw 1/128-s units by 128.0 to return seconds since midnight.
 *
 * @param item Pointer to I021_071 structure.
 * @return double Time in seconds (>= 0).
 */
ASTERIX_API double get_I021_071_TAP(const I021_071 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of Applicability for Position in seconds into I021/071.
 *
 * Converts the seconds value into 1/128-s units and stores as raw data.
 *
 * @param item Pointer to I021_071 structure.
 * @param tap_seconds Time in seconds (will be converted to 1/128-s units).
 */
ASTERIX_API void set_I021_071_TAP(I021_071 * item, double tap_seconds);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/**
 * @brief
 * 
 * @param item_in
 * @param msg_out
 * @param out_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t encode_I021_071(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/**
 * @brief
 * 
 * @param item_in
 * @param msg_in
 * @param in_index
 * 
 * @return uint16_t
 */
ASTERIX_API uint16_t decode_I021_071(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

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