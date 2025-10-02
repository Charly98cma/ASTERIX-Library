/**
 * @file I021_140.h
 * @brief Definition of I021/140, and related functions and values
 */

#ifndef I021_140_H
#define I021_140_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I021_140_LSB_GH                   (6.25)         /// LSB = 6.25 ft

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I021_140
 * @brief Category 021 / Item 140 - Geometric Height
 * 
 * Minimum height from a plane tangent to the earth’s ellipsoid, defined by
 * WGS-84, in two's complement form.
 */
typedef struct I021_140 {
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
             * @brief Geometric Height (LSB = 6.25 ft)
             * 
             * -1500 ft <= Geometric Height <= 150000 ft
             */
            uint16_t GH;
        };
    };
} I021_140;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Geometric Height (GH) from I021/140 
 * 
 * @param item Pointer to I021_140 structure
 * 
 * @return double Geometric Height in feets
 */
ASTERIX_API double get_I021_140_GH(const I021_140 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the given Geometric Height (GH) real value (see LSB) into
 *        I021/140
 * 
 * @param item Pointer to I021_140 structure
 * @param gh_ft New GH value in feets (LSB = 6.25 ft)
 */
ASTERIX_API void set_I021_140_GH(I021_140 * item, double gh_ft);

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
ASTERIX_API uint16_t encode_I021_140(void * item_in,
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
ASTERIX_API uint16_t decode_I021_140(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the Geometric Height of the I021/140
 * 
 * @param item Pointer to I021_140 structure
 */
ASTERIX_API void print_I021_140(const I021_140 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_140_H */