/**
 * @file cat021_item170.c
 * @brief Implementation of the Category 21 Item 170 functions
 */

#include <stdio.h>
#include <string.h>
#include "Categories/cat021/cat021_item170.h"
#include "Common/constants.h"
#include "Aux_Funcs/char_encoding.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

void get_cat021_item170_TI(const cat021_item170 * item, unsigned char * str)
{
    uint8_t code;
    
    /* Char 1
     * 48 47 46 45 44 43
     * 08 07 06 05 04 03
     */
    code = GET_BITS(item->raw[0], 3, MASK_06_BITS);
    str[0] = encoding_to_char[code];
    /* Char 2
     * 42 41 40 39 38 37
     * 02 01 08 07 06 05
     */
    code  = GET_BITS(item->raw[0], 1, MASK_02_BITS) << 4;
    code |= GET_BITS(item->raw[1], 5, MASK_04_BITS);
    str[1] = encoding_to_char[code];
    /* Char 3
    * 36 35 34 33 32 31
    * 04 03 02 01 08 07
    */
    code  = GET_BITS(item->raw[1], 1, MASK_04_BITS) << 2;
    code |= GET_BITS(item->raw[2], 7, MASK_02_BITS);
    str[2] = encoding_to_char[code];
    /* Char 4
     * 30 29 28 27 26 25 
     * 06 05 04 03 02 01 
     */
    code  = GET_BITS(item->raw[2], 1, MASK_06_BITS);
    str[3] = encoding_to_char[code];
    /* Char 5
     * 24 23 22 21 20 19
     * 08 07 06 05 04 03
     */
    code  = GET_BITS(item->raw[3], 3, MASK_06_BITS);
    str[4] = encoding_to_char[code];
    /* Char 6
     * 18 17 16 15 14 13 
     * 02 01 08 07 06 05 
     */
    code  = GET_BITS(item->raw[3], 1, MASK_02_BITS) << 4;
    code |= GET_BITS(item->raw[4], 5, MASK_04_BITS);
    str[5] = encoding_to_char[code];
    /* Char 7
     * 12 11 10 09 08 07
     * 04 03 02 01 08 07
     */
    code  = GET_BITS(item->raw[4], 1, MASK_04_BITS) << 2;
    code |= GET_BITS(item->raw[5], 7, MASK_02_BITS);
    str[6] = encoding_to_char[code];
    /* Char 8
     * 06 05 04 03 02 01
     * 06 05 04 03 02 01
     */
    code  = GET_BITS(item->raw[5], 1, MASK_06_BITS);
    str[7] = encoding_to_char[code];
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item170_TI(cat021_item170 * item, const unsigned char * str)
{
    uint8_t code;

    // Char 1
    code = char_to_encoding[str[0]];
    SET_BITS(&(item->raw[0]), code     , MASK_06_BITS, 3);

    // Char 2
    code = char_to_encoding[str[1]];
    SET_BITS(&(item->raw[0]), code >> 4, MASK_02_BITS, 1);
    SET_BITS(&(item->raw[1]), code     , MASK_04_BITS, 5);

    // Char 3
    code = char_to_encoding[str[2]];
    SET_BITS(&(item->raw[1]), code >> 2, MASK_04_BITS, 1);
    SET_BITS(&(item->raw[2]), code     , MASK_02_BITS, 7);
    
    // Char 4
    code = char_to_encoding[str[3]];
    SET_BITS(&(item->raw[2]), code     , MASK_06_BITS, 1);

    // Char 5
    code = char_to_encoding[str[4]];
    SET_BITS(&(item->raw[3]), code     , MASK_06_BITS, 3);

    // Char 6
    code = char_to_encoding[str[5]];
    SET_BITS(&(item->raw[3]), code >> 4, MASK_02_BITS, 1);
    SET_BITS(&(item->raw[4]), code     , MASK_04_BITS, 5);

    // Char 6
    code = char_to_encoding[str[6]];
    SET_BITS(&(item->raw[4]), code >> 2, MASK_04_BITS, 1);
    SET_BITS(&(item->raw[5]), code     , MASK_02_BITS, 7);

    // Char 6
    code = char_to_encoding[str[7]];
    SET_BITS(&(item->raw[5]), code     , MASK_06_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item170(const cat021_item170 * item)
{
    unsigned char str[8];
    get_cat021_item170_TI(item, str);
    
    printf("Category 021 / Item 170 - Target Identification\n");
    printf("  Target Identification = %s\n", str);
}