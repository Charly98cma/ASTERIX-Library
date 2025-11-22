/**
 * @file I034_090.h
 * @brief Definition of I034/090, and related functions and values
 */

#ifndef I034_090_H
#define I034_090_H

#include <stdint.h>
#include "Common/visibility.h"
#include "Common/constants.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/

#define I034_090_LSB_RANGEERR   (0.0078125)     /// @brief LSB = 1/128 NM
#define I034_090_LSB_AZERR      (360.0/P2_14)   /// @brief LSB = 360/2^14 degrees     

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I034_090
 * @brief Category 034 / Item 090 - Collimation Error
 *
 * Averaged difference in range and in azimuth for the primary target position
 * with respect to the SSR target position as calculated by the radar station
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
            /// @brief Range Error (LSB = 1/2^7 NM)
            int8_t RANGE_ERR;
            /// @brief Azimuth Error (LSB = 360/2^14 degrees)
            int8_t AZ_ERR;
        };
    };
} I034_090;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/** @brief Get the Range Error (RANGEERR) from I034/090.
 *
 * The returned value is in NM; convert using I034_090_LSB_RANGEERR if needed.
 *
 * @param item Pointer to an I034_090 structure (must not be NULL).
 * @return Range error in nautical miles as a float.
 */
ASTERIX_API float get_I034_090_RANGEERR(const I034_090 *item);

/** @brief Get the Azimuth Error (AZERR) from I034/090.
 *
 * The returned value is in degrees; convert using I034_090_LSB_AZERR if needed.
 *
 * @param item Pointer to an I034_090 structure (must not be NULL).
 * @return Azimuth error in degrees as a float.
 */
ASTERIX_API float get_I034_090_AZERR(const I034_090 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/** @brief Set a new Range Error (RANGEERR) into I034/090.
 *
 * @param item Pointer to an I034_090 structure to modify (must not be NULL).
 * @param range_error Range error in nautical miles (use LSB conversion externally).
 */
ASTERIX_API void set_I034_090_RANGEERR(I034_090 *item, float range_error);

/** @brief Set a new Azimuth Error (AZERR) into I034/090.
 *
 * @param item Pointer to an I034_090 structure to modify (must not be NULL).
 * @param az_error Azimuth error in degrees (use LSB conversion externally).
 */
ASTERIX_API void set_I034_090_AZERR(I034_090 *item, float az_error);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/090 (Collimation Error) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_090 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_090(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item I034/090 (Collimation Error) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_090 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_090(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of item 034/090.
 *
 * @param item Pointer to a I034_090 structure.
 */
ASTERIX_API void print_I034_090(const I034_090 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_090_H */