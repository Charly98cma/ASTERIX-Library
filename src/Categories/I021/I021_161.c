/**
 * @file I021_161.c
 * @brief Implementation of the Category 21 Item 161 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_161.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint16_t get_I021_161_TRKNUM(const I021_161 * item) {
    return ((item->raw[0] & MASK_04_BITS) << 8) | item->raw[1];
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_161_TRKNUM(I021_161 * item, uint16_t track_number) {
    /* TODO: Check TRKNUM value in valid range */
    item->raw[0] = (track_number >> 8) & MASK_04_BITS;
    item->raw[1] = track_number;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_161(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_161 * item = (I021_161 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_161(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_161 * item = (I021_161 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_161(const I021_161 * item) {
    printf("Category 021 Item 161 - Track Number\n");
    printf("  TRACK NUMBER = %d\n", get_I021_161_TRKNUM(item));
}