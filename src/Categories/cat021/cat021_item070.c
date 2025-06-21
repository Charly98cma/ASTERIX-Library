/**
 * @file cat021_item070.c
 * @brief Implementation of the Category 21 Item 070 functions
 */

#include "cat021_item070.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item070_A4(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 12, MASK_01_BITS); 
}

uint8_t get_cat021_item070_A2(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 11, MASK_01_BITS); 
}

uint8_t get_cat021_item070_A1(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 10, MASK_01_BITS); 
}

uint8_t get_cat021_item070_B4(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 9, MASK_01_BITS); 
}

uint8_t get_cat021_item070_B2(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 8, MASK_01_BITS); 
}

uint8_t get_cat021_item070_B1(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 7, MASK_01_BITS); 
}

uint8_t get_cat021_item070_C4(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 6, MASK_01_BITS); 
}

uint8_t get_cat021_item070_C2(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 5, MASK_01_BITS); 
}

uint8_t get_cat021_item070_C1(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 4, MASK_01_BITS); 
}

uint8_t get_cat021_item070_D4(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 3, MASK_01_BITS); 
}

uint8_t get_cat021_item070_D2(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 2, MASK_01_BITS); 
}

uint8_t get_cat021_item070_D1(const cat021_item070 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS); 
}

uint16_t get_cat021_item070_code(const cat021_item070 * item)
{
    uint8_t A, B, C, D;

    // A OCTAL FORMAT = A4 0 A2 A1 
    A = (get_cat021_item070_A4(item) << 2) |
        (get_cat021_item070_A2(item) << 1) |
        (get_cat021_item070_A1(item));
    // B OCTAL FORMAT = B4 0 B2 B1 
    B = (get_cat021_item070_B4(item) << 2) |
        (get_cat021_item070_B2(item) << 1) |
        (get_cat021_item070_B1(item));
    // C OCTAL FORMAT = C4 0 C2 C1 
    C = (get_cat021_item070_C4(item) << 2) |
        (get_cat021_item070_C2(item) << 1) |
        (get_cat021_item070_C1(item));
    // D OCTAL FORMAT = D4 0 D2 D1 
    D = (get_cat021_item070_D4(item) << 2) |
        (get_cat021_item070_D2(item) << 1) |
        (get_cat021_item070_D1(item));

    return (A << 9) | (B << 6) | (C << 3) | D;    
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

uint16_t set_cat021_item070_code(cat021_item070 * item, uint16_t code)
{
    uint8_t A, B, C, D;

    // TODO: Check code is in valid range
    //if (!IN_RANGE(0, code, 07777)) return OP_FAIL;

    // Extract each octal number individually
    // Number in binary => A4 A2 A1 B4 B2 B1 C4 C2 C1 D4 D2 D1
    A = GET_BITS(code, 10, MASK_03_BITS); // A4 A2 A1
    B = GET_BITS(code,  7, MASK_03_BITS); // B4 B2 B1
    C = GET_BITS(code,  4, MASK_03_BITS); // C4 C2 C1
    D = GET_BITS(code,  1, MASK_03_BITS); // D4 D2 D1

    // Clear field
    (item)->raw = 0;

    // Insert each octal number in its position
    SET_BITS(&((item)->raw), A, MASK_03_BITS, 10); // A4 A2 A1
    SET_BITS(&((item)->raw), B, MASK_03_BITS,  7); // B4 B2 B1
    SET_BITS(&((item)->raw), C, MASK_03_BITS,  4); // C4 C2 C1
    SET_BITS(&((item)->raw), D, MASK_03_BITS,  1); // D4 D2 D1

    // Returns a copy of the setted value for safety checks
    return (item)->raw;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item070(cat021_item070 * item)
{
    printf("Category 021 / Item 070 - Mode 3/A Code in Octal Representation\n");
    printf("  Raw bits: 0x%04X\n", item->raw);
    printf("  Code: %04o\n\n", get_cat021_item070_code(item));
}
