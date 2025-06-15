/**
 * @file cat021_item070.h
 * @brief Definition of item 070 of CAT 021, and related functions and values
 */

#ifndef CAT021_ITEM070_H
#define CAT021_ITEM070_H

#include <stdint.h>
#include "visibility.h"

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
 * @typedef cat021_item070
 * @brief Category 021 / Item 070 - Mode 3/A Code in Octal Representation
 * 
 * Code format => A4 0 A2 A1 | B4 0 B2 B1 | C4 0 C2 C1 | D4 0 D2 D1
 */
typedef struct cat021_item070
{
    union
    {
        /// @brief Raw bytes as received (recommended for portable access)
        uint16_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct
        {
            /// @brief Spare bits-16/13 set to 0
            uint16_t spare      :4;
            /// @brief Bit 4 of A octal number
            uint16_t A4         :1;
            /// @brief Bit 2 of A octal number
            uint16_t A2         :1;
            /// @brief Bit 1 of A octal number
            uint16_t A1         :1;
            /// @brief Bit 4 of B octal number
            uint16_t B4         :1;
            /// @brief Bit 2 of B octal number
            uint16_t B2         :1;
            /// @brief Bit 1 of B octal number
            uint16_t B1         :1;
            /// @brief Bit 4 of C octal number
            uint16_t C4         :1;
            /// @brief Bit 2 of C octal number
            uint16_t C2         :1;
            /// @brief Bit 1 of C octal number
            uint16_t C1         :1;
            /// @brief Bit 4 of D octal number
            uint16_t D4         :1;
            /// @brief Bit 2 of D octal number
            uint16_t D2         :1;
            /// @brief Bit 1 of D octal number
            uint16_t D1         :1;
        };
    };
} cat021_item070;

/*******************************************************************************
 * Function headers
 ******************************************************************************/

uint8_t get_cat021_item070_A4(cat021_item070 * item);
uint8_t get_cat021_item070_A2(cat021_item070 * item);
uint8_t get_cat021_item070_A1(cat021_item070 * item);
uint8_t get_cat021_item070_B4(cat021_item070 * item);
uint8_t get_cat021_item070_B2(cat021_item070 * item);
uint8_t get_cat021_item070_B1(cat021_item070 * item);
uint8_t get_cat021_item070_C4(cat021_item070 * item);
uint8_t get_cat021_item070_C2(cat021_item070 * item);
uint8_t get_cat021_item070_C1(cat021_item070 * item);
uint8_t get_cat021_item070_D4(cat021_item070 * item);
uint8_t get_cat021_item070_D2(cat021_item070 * item);
uint8_t get_cat021_item070_D1(cat021_item070 * item);

ASTERIX_API uint16_t get_cat021_item070_code(cat021_item070 * item);

ASTERIX_API uint16_t set_cat021_item070_code(cat021_item070 * item,
                                             uint16_t code);

ASTERIX_API void print_cat021_item070(cat021_item070 * item);

#ifdef __cplusplus
}
#endif

#endif /* CAT021_ITEM070_H */