/**
 * @file I034_020.h
 * @brief Definition of I034/020, and related functions and values
 */

#ifndef I034_020_H
#define I034_020_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I034_020_LSB_SECTORNUM      (1.40625)   /// LSB = 360.0/2^8 degrees

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/** @brief Category 034 / Item 020 - Sector Number
 * @typedef I034_020
 *
 * Eight most significant bits of the antenna azimuth defining a particular
 * azimuth sector
 */
typedef struct
{
    union
    {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Sector Number (LSB = 360/2^8 deg)
            uint8_t SECTORNUM;
        };
    };
} I034_020;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/** @brief Retrieve the Sector Number (SECTORNUM) from the I034/020 item.
 *
 * @param item Pointer to an I034_020 structure (must not be NULL).
 * 
 * @return Sector azimuth (LSB = 360/2^8 degrees).
 */
ASTERIX_API float get_I034_020_SECTORNUM(const I034_020 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/** @brief Set the Sector Number (SECTORNUM) into the I034/020 item.
 *
 * @param item Pointer to an I034_020 structure to modify (must not be NULL).
 * @param sector_az Sector azimuth value to store as sector number (LSB = 360/2^8 degrees).
 */
ASTERIX_API void set_I034_020_SECTORNUM(I034_020 *item, float sector_az);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/020 (Sector Number) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_020 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_020(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item I034/020 (Sector Number) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_020 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_020(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/** @brief Print the contents of item 034/020.
 *
 * @param item Pointer to a I034_020 structure.
 */
ASTERIX_API void print_I034_020(const I034_020 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_020_H */