/**
 * @file I021_152.h
 * @brief Definition of I021/152, and related functions and values
 */

#ifndef I021_152_H
#define I021_152_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_152_LSB_MH         (360.0/P2_16)  /// LSB = 360/2^16 degrees

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_152
 * @brief Category 021 / Item 152 - Magnetic Heading
 * 
 * Magnetic Heading (Element of Air Vector).
 * 
 * @note True North Heading is defined in the Reserved Expansion Field
 *       in the subfield TNH.
 */
typedef struct I021_152 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /**
             * @brief Magnetic Heading (Element of Air Vector)
             * 
             * LSB = 360/2^16 degrees
             */
            uint16_t MH;
        };
    };
} I021_152;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Magnetic Heading in degrees from I021/152 
 * 
 * @param item Pointer to I021_152 structure
 * 
 * @return double magnetic heading in degrees (see LSB)
 */
ASTERIX_API double get_I021_152_MH(const I021_152 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Magnetic Heading value in degrees (see LSB) into
 *        I021/152
 * 
 * @param item Pointer to I021_152 structure
 * @param tas New magnetic heading in degrees
 */
ASTERIX_API void set_I021_152_MH(I021_152 * item, double tas);

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
ASTERIX_API uint16_t encode_I021_152(void * item_in,
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
ASTERIX_API uint16_t decode_I021_152(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Magnetic Heading value of the I021/152
 * 
 * @param item Pointer to I021_152 structure
 */
ASTERIX_API void print_I021_152(const I021_152 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_152_H */