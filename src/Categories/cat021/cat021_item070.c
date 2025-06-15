/**
 * @file cat021_item070.c
 * @brief Implementation of the Category 21 Item 070 functions
 */

#include "cat021_item070.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/**
 * @brief Get the A4 octal number (A4) from CAT 021 Item 070.
 * 
 * Portable access to the A4 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of A4
 */
uint8_t get_cat021_item070_A4(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 12, MASK_01_BITS); 
}

/**
 * @brief Get the A2 octal number (A2) from CAT 021 Item 070.
 * 
 * Portable access to the A2 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of A2
 */
uint8_t get_cat021_item070_A2(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 11, MASK_01_BITS); 
}

/**
 * @brief Get the A1 octal number (A1) from CAT 021 Item 070.
 * 
 * Portable access to the A1 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of A1
 */
uint8_t get_cat021_item070_A1(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 10, MASK_01_BITS); 
}

/**
 * @brief Get the B4 octal number (B4) from CAT 021 Item 070.
 * 
 * Portable access to the B4 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of B4
 */
uint8_t get_cat021_item070_B4(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 9, MASK_01_BITS); 
}

/**
 * @brief Get the B2 octal number (B2) from CAT 021 Item 070.
 * 
 * Portable access to the B2 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of B2
 */
uint8_t get_cat021_item070_B2(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 8, MASK_01_BITS); 
}

/**
 * @brief Get the B1 octal number (B1) from CAT 021 Item 070.
 * 
 * Portable access to the B1 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of B1
 */
uint8_t get_cat021_item070_B1(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 7, MASK_01_BITS); 
}

/**
 * @brief Get the C4 octal number (C4) from CAT 021 Item 070.
 * 
 * Portable access to the C4 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of C4
 */
uint8_t get_cat021_item070_C4(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 6, MASK_01_BITS); 
}

/**
 * @brief Get the C2 octal number (C2) from CAT 021 Item 070.
 * 
 * Portable access to the C2 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of C2
 */
uint8_t get_cat021_item070_C2(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 5, MASK_01_BITS); 
}

/**
 * @brief Get the C1 octal number (C1) from CAT 021 Item 070.
 * 
 * Portable access to the C1 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of C1
 */
uint8_t get_cat021_item070_C1(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 4, MASK_01_BITS); 
}

/**
 * @brief Get the D4 octal number (D4) from CAT 021 Item 070.
 * 
 * Portable access to the D4 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of D4
 */
uint8_t get_cat021_item070_D4(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 3, MASK_01_BITS); 
}

/**
 * @brief Get the D2 octal number (D2) from CAT 021 Item 070.
 * 
 * Portable access to the D2 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of D2
 */
uint8_t get_cat021_item070_D2(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 2, MASK_01_BITS); 
}

/**
 * @brief Get the D1 octal number (D1) from CAT 021 Item 070.
 * 
 * Portable access to the D1 bit, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint8_t Value of D1
 */
uint8_t get_cat021_item070_D1(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS); 
}

/**
 * @brief Get the Mode 3/A Code in cctal representation.
 * 
 * Portable access to the bit-fields, independent of compiler and endianness.
 * 
 * @param item Pointer to cat021_item070 structure.
 * @return uint16_t Mode 3/A Code in Octal Representation
 */
uint16_t get_cat021_item070_code(cat021_item070 * item)
{
    uint8_t A, B, C, D;

    // A OCTAL FORMAT = A4 0 A2 A1 
    A = (get_cat021_item070_A4(item) << 3 ) |
        (get_cat021_item070_A2(item) << 1 ) |
        (get_cat021_item070_A1(item));
    // B OCTAL FORMAT = B4 0 B2 B1 
    B = (get_cat021_item070_B4(item) << 3 ) |
        (get_cat021_item070_B2(item) << 1 ) |
        (get_cat021_item070_B1(item));
    // C OCTAL FORMAT = C4 0 C2 C1 
    C = (get_cat021_item070_C4(item) << 3 ) |
        (get_cat021_item070_C2(item) << 1 ) |
        (get_cat021_item070_C1(item));
    // D OCTAL FORMAT = D4 0 D2 D1 
    D = (get_cat021_item070_D4(item) << 3 ) |
        (get_cat021_item070_D2(item) << 1 ) |
        (get_cat021_item070_D1(item));

    return (A << 9) | (B << 6) | (C << 3) | D;    
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/**
 * @brief Set the Mode 3/A Code in octal representation into the raw field.
 * 
 * Each digit is 0-7 (octal) and occupies bits: X4 0 X2 X1
 * 
 * @param item Pointer to cat021_item070 structure.
 * @param code Mode 3/A code in octal (0000 to 7777)
 * @return uint16_t Final raw value
 */
uint16_t set_cat021_item070_code(cat021_item070 * item, uint16_t code)
{
    uint8_t A, B, C, D;

    // Extract each octal number individually
    A = GET_BITS(code, 10, MASK_03_BITS); // A4 0 A2 A1
    B = GET_BITS(code,  7, MASK_03_BITS); // B4 0 B2 B1
    C = GET_BITS(code,  4, MASK_03_BITS); // C4 0 C2 C1
    D = GET_BITS(code,  1, MASK_03_BITS); // D4 0 D2 D1

    // Clear field
    item->raw = 0;

    // Insert each octal number in its position
    SET_BITS(&(item->raw), (A >> 3), MASK_01_BITS, 12); // A4
    SET_BITS(&(item->raw), (A >> 1), MASK_01_BITS, 11); // A2
    SET_BITS(&(item->raw), (A >> 0), MASK_01_BITS, 10); // A1

    SET_BITS(&(item->raw), (B >> 3), MASK_01_BITS,  9); // B4
    SET_BITS(&(item->raw), (B >> 1), MASK_01_BITS,  8); // B2
    SET_BITS(&(item->raw), (B >> 0), MASK_01_BITS,  7); // B1

    SET_BITS(&(item->raw), (C >> 3), MASK_01_BITS,  6); // C4
    SET_BITS(&(item->raw), (C >> 1), MASK_01_BITS,  5); // C2
    SET_BITS(&(item->raw), (C >> 0), MASK_01_BITS,  4); // C1

    SET_BITS(&(item->raw), (D >> 3), MASK_01_BITS,  3); // D4
    SET_BITS(&(item->raw), (D >> 1), MASK_01_BITS,  2); // D2
    SET_BITS(&(item->raw), (D >> 0), MASK_01_BITS,  1); // D1

    // Returns a copy of the setted value for safety checks
    return item->raw;
}

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
 * @param item Pointer to a cat021_item070 structure.
 */
void print_cat021_item070(cat021_item070 * item)
{
    printf("Category 021 / Item 070 - Mode 3/A Code in Octal Representation\n");
    printf("  Raw bits: 0x%04X\n", item->raw);
    printf("  Code: %04o\n\n", get_cat021_item070_code(item));
}
