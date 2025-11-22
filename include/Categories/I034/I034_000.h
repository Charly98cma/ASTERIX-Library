/**
 * @file I034_000.h
 * @brief Definition of I034/000, and related functions and values
 */

#ifndef I034_000_H
#define I034_000_H

#include <stdint.h>
#include "Common/visibility.h"

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
 * @typedef I034_000
 * @brief Category 034 / Item 000 - Message Type
 *
 * This Data Item allows for a more convenient handling of the messages at
 * the receiver side by further defining the type of transaction.
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
            /// @brief Message Type (see ref. for valid values)
            uint8_t MSGTYPE;
        };
    };
}I034_000;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Retrieve the Message Type (MSGTYPE) from the I034/000 item.
 *
 * @param item Pointer to a I034_000 structure (must not be NULL).
 * 
 * @return Message Type. See specification for the meaning/valid range of values.
 */
ASTERIX_API uint8_t get_I034_000_MSGTYPE(const I034_000 *item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Message Type (MSGTYPE) in the I034/000 item.
 *
 * @param item Pointer to the I034_000 structure to modify (must not be NULL).
 * @param msg_type New MSGTYPE value to store.
 */
ASTERIX_API void set_I034_000_MSGTYPE(I034_000 *item, uint8_t msg_type);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item 034/000 (Message Type) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I034_000 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 *
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I034_000(void *item_in,
                                     unsigned char *msg_out,
                                     uint16_t out_index);

/** @brief Decode item 034/000 (Message Type) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I034_000 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 *
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I034_000(void *item_out,
                                     const unsigned char *msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of item 034/000.
 *
 * @param item Pointer to a I034_000 structure.
 */
ASTERIX_API void print_I034_000(const I034_000 *item);

#ifdef __cplusplus
}
#endif

#endif /* I034_000_H */