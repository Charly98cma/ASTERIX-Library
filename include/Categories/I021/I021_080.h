/**
 * @file I021_080.h
 * @brief Definition of I021/080, and related functions and values
 */

#ifndef I021_080_H
#define I021_080_H

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
 * @typedef I021_080
 * @brief Category 021 / Item 080 - Target Address
 * 
 * Target ICAO (24 bits) Address.
 */
typedef struct I021_080 {

    union {
        /// @brief Raw octet as received (recommended for portable access)
        uint8_t raw[3];
        
        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
        
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Target ICAO Address (24 bits)
            uint8_t TGTADDR[3];
        };
    };
} I021_080;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Returns the Target ICAO Address value
 *
 * Returns the 24-bit value of the Target ICAO Address.
 *
 * @param item Pointer to I021_080 structure.
 * @return uint32_t 24-bit target address.
 */
ASTERIX_API uint32_t get_I021_080_TGTADDR(const I021_080 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Target ICAO Address value into I021/080.
 *
 * Stores the 24-bit value into the raw array.
 *
 * @param item Pointer to I021_080 structure.
 * @param addr 24-bit target address.
 */
ASTERIX_API void set_I021_080_TGTADDR(I021_080 * item, uint32_t addr);

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

/** @brief Encode item I021/080 (Target Address) into a raw ASTERIX message.
 *
 * @param item_in Pointer to the input I021/080 structure.
 * @param msg_out Pointer to the output ASTERIX message buffer.
 * @param out_index Current index in the output message buffer.
 * 
 * @return Updated index in the output message buffer after encoding.
 */
ASTERIX_API uint16_t encode_I021_080(void * item_in,
                                     unsigned char * msg_out,
                                     uint16_t out_index);

/** @brief Decode item I021/080 (Target Address) from a raw ASTERIX message.
 *
 * @param item_out Pointer to the output I021/080 structure to populate.
 * @param msg_in Pointer to the input ASTERIX message buffer.
 * @param in_index Current index in the input message buffer.
 * 
 * @return Updated index in the input message buffer after decoding.
 */
ASTERIX_API uint16_t decode_I021_080(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of I021/080 (Target ICAO Address).
 * 
 * Prints both 3 hexadecimal that compose the ICAO Address of the target aircraft.
 * 
 * @param item Pointer to I021_080 structure.
 */
ASTERIX_API void print_I021_080(const I021_080 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_080_H */