/**
 * @file I034_041.h
 * @brief Definition of I034/041, and related functions and values
 */

#ifndef I034_041_H
#define I034_041_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I034_041_LSB_ANTROTSPD (0.0078125) /// LSB = 1/128 seconds

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I034_041
 * @brief Category 034 / Item 041 - Antenna Rotation Speed
 *
 * Antenna rotation period as measured between two consecutive North crossings
 * or as averaged during a period of time.
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Antenna Rotation Speed (see ref. for valid values)
            uint16_t ANTROTSPD;
        };
    };
} I034_041;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/** @brief Retrieve the Antenna Rotation Speed (ANTROTSPD) from I034/041.
 *
 * @param item Pointer to an I034_041 structure (must not be NULL).
 * 
 * @return Antenna Rotation Speed in seconds (LSB = 1/2^7 seconds).
 */
ASTERIX_API float get_I034_041_ANTROTSPD(const I034_041 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/** @brief Set the Antenna Rotation Speed (ANTROTSPD) into I034/041.
 *
 * @param item Pointer to an I034_041 structure to modify (must not be NULL).
 * @param antrotspd_seconds New Antenna Rotation Speed in seconds to store.
 */
ASTERIX_API void set_I034_041_ANTROTSPD(I034_041 *item, float antrotspd_seconds);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/041 (Antenna Rotation Speed) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_041 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_041(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item I034/041 (Antenna Rotation Speed) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_041 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_041(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/** @brief Print the contents of item 034/041.
 *
 * @param item Pointer to a I034_041 structure.
 */
ASTERIX_API void print_I034_041(const I034_041 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_041_H */