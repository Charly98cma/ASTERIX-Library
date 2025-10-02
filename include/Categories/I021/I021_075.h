/**
 * @file I021_075.h
 * @brief Definition of I021/075, and related functions and values
 */

#ifndef I021_075_H
#define I021_075_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_075_LSB_TMRV       (1.0/128.0) /// @brief LSB = 1/128 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_075
 * @brief Category 021 / Item 075 - Time of Message Reception for Velocity
 * 
 * Time of reception of the latest velocity squitter in the Ground
 * Station, in the form of elapsed time since last midnight,
 * expressed as UTC.
 */
typedef struct I021_075 {
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
             * @brief Time of Message Reception for Velocity (LSB = 1/128 sec)
             */
            uint8_t TMRV[3];
        };
    };
} I021_075;


/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Time of Message Reception for Velocity in seconds (floating-point)
 *        from I021/075.
 *
 * Divides the raw 1/128-s units by 128.0 to return seconds since midnight.
 *
 * @param item Pointer to I021_075 structure.
 * @return double Time in seconds (>= 0).
 */
ASTERIX_API double get_I021_075_TMRV(const I021_075 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of Message Reception for Velocity in seconds into I021/075.
 *
 * Converts the seconds value into 1/128-s units and stores as raw data.
 *
 * @param item Pointer to I021_075 structure.
 * @param tmrv_seconds Time in seconds (will be converted to 1/128-s units).
 */
ASTERIX_API void set_I021_075_TMRV(I021_075 * item, double tmrv_seconds);

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
ASTERIX_API uint16_t encode_I021_075(void * item_in,
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
ASTERIX_API uint16_t decode_I021_075(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/075 (Time of Message Reception for Velocity).
 * 
 * Prints both the raw value and the converted time in seconds.
 * 
 * @param item Pointer to I021_075_t structure.
 */
ASTERIX_API void print_I021_075(const I021_075 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_075_H */