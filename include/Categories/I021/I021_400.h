/**
 * @file I021_400.h
 * @brief Definition of I021/400, and related functions and values
 */

#ifndef I021_400_H
#define I021_400_H

#include <stdint.h>
#include "Common/visibility.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * Macros
 ******************************************************************************/


/*******************************************************************************
 * Structures and Types
 ******************************************************************************/


/**
 * @typedef I021_400
 * @brief Category 021 / Item 400 - Receiver ID
 * 
 * Designator of Ground Station in Distributed System
 */
typedef struct I021_400 {
    union {
        /// @brief Raw octets as received (recommended for portable access)
        uint8_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */

        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            uint8_t RID;
        };
    };
} I021_400;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Receiver ID (RID) value from I021/400
 * 
 * @param item pointer to I021_400 structure
 * 
 * @return value of the Received ID
 */
ASTERIX_API uint8_t get_I021_400_RID(const I021_400 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the new Receiver ID (RID) value into I021/400
 * 
 * @param item pointer to I021_400 structure
 * @param rid new RID value
 */
ASTERIX_API void set_I021_400_RID(I021_400 * item, uint8_t rid);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/400 (Received ID) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/400 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_400(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/400 (Received ID) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/400 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_400(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Prints the contents of I021/400 and its extension if present
 * 
 * @param item pointer to I021_400 structure
 */
ASTERIX_API void print_I021_400(const I021_400 * item);


#ifdef __cplusplus
}
#endif

#endif /* I021_400_H */