/**
 * @file I021_170.c
 * @brief Implementation of the Category 21 Item 170 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aircraft_ident_char_encoding.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_170.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

void get_I021_170_TI(const I021_170 * item, unsigned char * code_out_str) {
    uint8_t code;
    
    /* Char 1
     * 48 47 46 45 44 43
     * 08 07 06 05 04 03
     */
    code = (item->raw[0] >> 2) & MASK_06_BITS;
    code_out_str[0] = encoding_to_char[code];
    /* Char 2
     * 42 41 40 39 38 37
     * 02 01 08 07 06 05
     */
    code = (item->raw[0] & MASK_02_BITS) << 4;
    code |= (item->raw[1] >> 4) & MASK_04_BITS;
    code_out_str[1] = encoding_to_char[code];
    /* Char 3
    * 36 35 34 33 32 31
    * 04 03 02 01 08 07
    */
    code = (item->raw[1] & MASK_04_BITS) << 2;
    code |= (item->raw[2] >> 6) & MASK_02_BITS;
    code_out_str[2] = encoding_to_char[code];
    /* Char 4
     * 30 29 28 27 26 25 
     * 06 05 04 03 02 01 
     */
    code = item->raw[2] & MASK_06_BITS;
    code_out_str[3] = encoding_to_char[code];
    /* Char 5
     * 24 23 22 21 20 19
     * 08 07 06 05 04 03
     */
    code = (item->raw[3] >> 2) & MASK_06_BITS;
    code_out_str[4] = encoding_to_char[code];
    /* Char 6
     * 18 17 16 15 14 13 
     * 02 01 08 07 06 05 
     */
    code = (item->raw[3] & MASK_02_BITS) << 4;
    code |= (item->raw[4] >> 4) & MASK_04_BITS;
    code_out_str[5] = encoding_to_char[code];
    /* Char 7
     * 12 11 10 09 08 07
     * 04 03 02 01 08 07
     */
    code = (item->raw[4] & MASK_04_BITS) << 2;
    code |= (item->raw[5] >> 6) & MASK_02_BITS;
    code_out_str[6] = encoding_to_char[code];
    /* Char 8
     * 06 05 04 03 02 01
     * 06 05 04 03 02 01
     */
    code = item->raw[5] & MASK_06_BITS;
    code_out_str[7] = encoding_to_char[code];
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_170_TI(I021_170 * item, const unsigned char * code_in_str) {
    uint8_t code;

    /* Char 1 */
    code = char_to_encoding[code_in_str[0]];
    item->raw[0] |= (code & MASK_06_BITS) << 2;

    /* Char 2 */
    code = char_to_encoding[code_in_str[1]];
    item->raw[0] |= (code >> 4) & MASK_02_BITS;
    item->raw[1] |= (code & MASK_04_BITS) << 4;

    /* Char 3 */
    code = char_to_encoding[code_in_str[2]];
    item->raw[1] |= (code >> 2) & MASK_04_BITS;
    item->raw[2] |= (code & MASK_02_BITS) << 6;
    
    /* Char 4 */
    code = char_to_encoding[code_in_str[3]];
    item->raw[2] |= code & MASK_06_BITS;

    /* Char 5 */
    code = char_to_encoding[code_in_str[4]];
    item->raw[3] |= (code & MASK_06_BITS) << 2;

    /* Char 6 */
    code = char_to_encoding[code_in_str[5]];
    item->raw[3] |= (code >> 4) & MASK_02_BITS;
    item->raw[4] |= (code & MASK_04_BITS) << 4;

    /* Char 6 */
    code = char_to_encoding[code_in_str[6]];
    item->raw[4] |= (code >> 2) & MASK_04_BITS;
    item->raw[5] |= (code & MASK_02_BITS) << 6;

    /* Char 6 */
    code = char_to_encoding[code_in_str[7]];
    item->raw[5] |= code & MASK_06_BITS;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_170(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_170 * item = (I021_170 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    msg_out[out_index++] = item->raw[3];
    msg_out[out_index++] = item->raw[4];
    msg_out[out_index++] = item->raw[5];
    return out_index;
}

uint16_t decode_I021_170(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_170 * item = (I021_170 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    item->raw[3] = msg_in[in_index++];
    item->raw[4] = msg_in[in_index++];
    item->raw[5] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_170(const I021_170 * item) {
    unsigned char str[8];
    get_I021_170_TI(item, str);
    
    printf("Category 021 Item 170 - Target Identification\n");
    printf("  Target Identification = %s\n", str);
}