/**
 * @file I034_110.h
 * @brief Definition of I034/110, and related functions and values
 */

#ifndef I034_110_H
#define I034_110_H

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

/*******************************************************************************
 * Structures and Types
 ******************************************************************************/

/**
 * @typedef I034_110
 * @brief Category 034 / Item 110 - Data Filter
 *
 * Data Filter, which allows suppression of individual data types
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
            /// @brief Data Filter Type
            int8_t TYP;
        };
    };
} I034_110;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Data Filter Type (TYP) from I034/110
 *
 * @param item Pointer to an I034_110 structure (must not be NULL).
 * 
 * @return Data Filter Type value.
 */
ASTERIX_API uint8_t get_I034_110_TYP(const I034_110 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set a new Data Filter Type (TYP) into I034/110
 *
 * @param item Pointer to an I034_110 structure to modify (must not be NULL).
 * @param typ New Data Filter Type value.
 */
ASTERIX_API void set_I034_110_TYP(I034_110 *item, uint8_t typ);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I034/110 into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_110 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_110(void *item_in,
                                        unsigned char *msg_out,
                                        uint16_t out_index);

/** @brief Decode item I034/110 from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_110 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_110(void *item_out,
                                        const unsigned char *msg_in,
                                        uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of item 034/110.
 *
 * @param item Pointer to a I034_110 structure.
 */
ASTERIX_API void print_I034_110(const I034_110 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_110_H */