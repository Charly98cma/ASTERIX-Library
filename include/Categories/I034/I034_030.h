/**
 * @file I034_030.h
 * @brief Definition of I034/030, and related functions and values
 */

#ifndef I034_030_H
#define I034_030_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I034_030_LSB_TOD    (0.0078125)   /// LSB = 1/2^7 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I034_030
 * @brief Category 034 / Item 030 - Time of Day (TOD)
 *
 * Absolute time stamping expressed as UTC time.
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[3];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Time of Day (TOD) (LSB = 1/128 seconds)
            uint8_t TOD[3];
        };
    };
} I034_030;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Retrieve the Time of Day (TOD) from I034/030.
 *
 * @param item Pointer to an I034_030 structure (must not be NULL).
 * @return Time of Day (UTC) in seconds (LSB = 1/2^7 seconds).
 */
ASTERIX_API float get_I034_030_TOD(const I034_030 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Time of Day (TOD) of I034/030.
 *
 * @param item Pointer to an I034_030 structure to modify (must not be NULL).
 * @param tod_seconds New Time of Day (UTC) in seconds (LSB = 1/2^7 seconds).
 */
ASTERIX_API void set_I034_030_TOD(I034_030 *item, float tod_seconds);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/030 (Time of Day) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_030 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_030(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item I034/030 (Time of Day) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_030 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_030(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/** @brief Print the contents of item 034/030.
 *
 * @param item Pointer to the I034_030 structure.
 */
ASTERIX_API void print_I034_030(const I034_030 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_030_H */