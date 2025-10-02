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
 * @brief Get the Time of ASTERIX Report Transmission in seconds (floating-point)
 *        from I021/077.
 *
 * @param item Pointer to I021_077 structure.
 * @return double TART time in seconds (see LSB).
 */
ASTERIX_API double get_I021_077_TART(const I021_077 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of ASTERIX Report Transmission in seconds into I021/077.
 *
 * @param item Pointer to I021_077 structure.
 * @param tart_seconds TART time in seconds (see LSB)
 */
ASTERIX_API void set_I021_077_TART(I021_077 * item, double tart_seconds);

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
ASTERIX_API uint16_t encode_I021_077(void * item_in,
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
ASTERIX_API uint16_t decode_I021_077(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

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