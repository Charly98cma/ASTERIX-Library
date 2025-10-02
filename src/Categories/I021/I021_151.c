/**
 * @file I021_151.c
 * @brief Implementation of the Category 21 Item 151 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_151.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_151_RE(const I021_151 * item) {
    return (item->raw[0] >> 7) & MASK_01_BITS;
}

uint16_t get_I021_151_TAS(const I021_151 * item) {
    return ((item->raw[0] & MASK_07_BITS) << 8) | item->raw[1];
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_151_RE(I021_151 * item, uint8_t re) {
    item->raw[0] |= (re & MASK_01_BITS) << 7;
}

void set_I021_151_TAS(I021_151 * item, uint16_t tas_kts) {
    item->raw[0] |= (tas_kts >> 8) & MASK_07_BITS;
    item->raw[1] = tas_kts;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_151(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_151 * item = (I021_151 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_151(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_151 * item = (I021_151 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_151(const I021_151 * item) {
    printf("Category 021 Item 151 - True Air Speed\n");
    printf("  RE = %d\n", get_I021_151_RE(item));
    printf("  TAS = %d\n", get_I021_151_TAS(item));
}