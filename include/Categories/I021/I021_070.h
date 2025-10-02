/**
 * @file I021_070.h
 * @brief Definition of item 070 of CAT 021, and related functions and values
 */

#ifndef I021_070_H
#define I021_070_H

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
 * @typedef I021_070
 * @brief Category 021 / Item 070 - Mode 3/A Code in Octal Representation
 */
typedef struct I021_070 {
    union {
    
        /// @brief Raw bytes as received (recommended for portable access)
        uint8_t raw[2];

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
            /// @brief Spare bits-16/13 set to 0
            uint8_t spare       :4;
            /// @brief Bit 4 of A octal number
            uint8_t A4          :1;
            /// @brief Bit 2 of A octal number
            uint8_t A2          :1;
            /// @brief Bit 1 of A octal number
            uint8_t A1          :1;
            /// @brief Bit 4 of B octal number
            uint8_t B4          :1;

            /// @brief Bit 2 of B octal number
            uint8_t B2          :1;
            /// @brief Bit 1 of B octal number
            uint8_t B1          :1;
            /// @brief Bit 4 of C octal number
            uint8_t C4          :1;
            /// @brief Bit 2 of C octal number
            uint8_t C2          :1;
            /// @brief Bit 1 of C octal number
            uint8_t C1          :1;
            /// @brief Bit 4 of D octal number
            uint8_t D4          :1;
            /// @brief Bit 2 of D octal number
            uint8_t D2          :1;
            /// @brief Bit 1 of D octal number
            uint8_t D1          :1;
        };
    };
} I021_070;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the Mode 3/A Code in cctal representation.
 * 
 * Portable access to the bit-fields, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint16_t Mode 3/A Code in Octal Representation
 */
ASTERIX_API uint16_t get_I021_070_code(const I021_070 * item);

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Mode 3/A Code in octal representation into the raw field.
 * 
 * If the provided code is out of range (greater than 7777 octal), it will be
 * set to 0000.
 * 
 * @param item Pointer to I021_070 structure.
 * @param code Mode 3/A code in octal (0000 to 7777)
 */
ASTERIX_API void set_I021_070_code(I021_070 * item, uint16_t code);

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
ASTERIX_API uint16_t encode_I021_070(void * item_in,
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
ASTERIX_API uint16_t decode_I021_070(void * item_out,
                                     const unsigned char * msg_in,
                                     uint16_t in_index);

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

/**
 * @brief Print the contents of CAT 021 / Item 070.
 *
 * This function prints both the raw octests and Mode 3/A code in octal
 * representation.
 * It is useful for debugging and inspection.
 *
 * @param item Pointer to a I021_070 structure.
 */
ASTERIX_API void print_I021_070(const I021_070 * item);

#ifdef __cplusplus
}
#endif

#endif /* I021_070_H */