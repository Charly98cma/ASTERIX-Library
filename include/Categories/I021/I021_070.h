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
 * 
 * Code format => A4 0 A2 A1 | B4 0 B2 B1 | C4 0 C2 C1 | D4 0 D2 D1
 */
typedef struct I021_070 {
    union {
    
        /// @brief Raw bytes as received (recommended for portable access)
        uint16_t raw;

        /**
         * @note Bit-field layout is compiler and endianness dependent.
         * Use raw field and provided macros for portable access.
         */
 
        /// @brief Bit-field access (might be non-portable, use with caution)
        struct {
        
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
} I021_070;

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the A4 octal number (A4) from I021/070.
 * 
 * Portable access to the A4 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of A4
 */
uint8_t get_I021_070_A4(const I021_070 * item);

/**
 * @brief Get the A2 octal number (A2) from I021/070.
 * 
 * Portable access to the A2 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of A2
 */
uint8_t get_I021_070_A2(const I021_070 * item);

/**
 * @brief Get the A1 octal number (A1) from I021/070.
 * 
 * Portable access to the A1 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of A1
 */
uint8_t get_I021_070_A1(const I021_070 * item);

/**
 * @brief Get the B4 octal number (B4) from I021/070.
 * 
 * Portable access to the B4 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of B4
 */
uint8_t get_I021_070_B4(const I021_070 * item);

/**
 * @brief Get the B2 octal number (B2) from I021/070.
 * 
 * Portable access to the B2 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of B2
 */
uint8_t get_I021_070_B2(const I021_070 * item);

/**
 * @brief Get the B1 octal number (B1) from I021/070.
 * 
 * Portable access to the B1 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of B1
 */
uint8_t get_I021_070_B1(const I021_070 * item);

/**
 * @brief Get the C4 octal number (C4) from I021/070.
 * 
 * Portable access to the C4 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of C4
 */
uint8_t get_I021_070_C4(const I021_070 * item);

/**
 * @brief Get the C2 octal number (C2) from I021/070.
 * 
 * Portable access to the C2 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of C2
 */
uint8_t get_I021_070_C2(const I021_070 * item);

/**
 * @brief Get the C1 octal number (C1) from I021/070.
 * 
 * Portable access to the C1 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of C1
 */
uint8_t get_I021_070_C1(const I021_070 * item);

/**
 * @brief Get the D4 octal number (D4) from I021/070.
 * 
 * Portable access to the D4 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of D4
 */
uint8_t get_I021_070_D4(const I021_070 * item);

/**
 * @brief Get the D2 octal number (D2) from I021/070.
 * 
 * Portable access to the D2 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of D2
 */
uint8_t get_I021_070_D2(const I021_070 * item);

/**
 * @brief Get the D1 octal number (D1) from I021/070.
 * 
 * Portable access to the D1 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to I021_070 structure.
 * @return uint8_t Value of D1
 */
uint8_t get_I021_070_D1(const I021_070 * item);


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
 * Each digit is 0-7 (octal) and occupies bits: X4 0 X2 X1
 * 
 * @param item Pointer to I021_070 structure.
 * @param code Mode 3/A code in octal (0000 to 7777)
 * 
 * @return uint16_t value set as the M3/A code
 */
ASTERIX_API uint16_t set_I021_070_code(I021_070 * item, const uint16_t code);

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