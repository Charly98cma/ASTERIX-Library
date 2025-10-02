/**
 * @file I021_070.c
 * @brief Implementation of the Category 21 Item 070 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_070.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint16_t get_I021_070_code(const I021_070 * item) {
    return ((item->raw[0] & 0x0F) << 8) | (item->raw[1] & 0xFF);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_070_code(I021_070 * item, uint16_t code) {
    // Invalid code, set to zero
    if (code > 07777) code = 0;
    item->raw[0] = (code >> 8) & 0x0F;
    item->raw[1] = code & 0xFF;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_070(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_070 * item = (I021_070 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_070(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_070 * item = (I021_070 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_070(const I021_070 * item) {
    printf("Category 021 Item 070 - Mode 3/A\n");
    printf("  Raw bits: 0x%02X%02X\n", item->raw[0], item->raw[1]);
    printf("  Code: %04o\n\n", get_I021_070_code(item));
}
