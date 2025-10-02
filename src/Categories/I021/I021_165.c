/**
 * @file I021_165.c
 * @brief Implementation of the Category 21 Item 165 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_165.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_165_TAR(const I021_165 * item) {
    int16_t tar_raw = ((item->raw[0] & MASK_02_BITS) << 8) | item->raw[1];
    return tar_raw * I021_165_LSB_TAR;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_165_TAR(I021_165 * item, double tar_degpsec) {
    int16_t tar_raw = 0;

    /* TODO: Check TAR value in valid range */
    if (tar_degpsec > 0)
        tar_raw = (int16_t) ((tar_degpsec / I021_165_LSB_TAR) + 0.5);

    item->raw[0] = (tar_raw >> 8) & MASK_02_BITS;
    item->raw[1] = tar_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_165(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_165 * item = (I021_165 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_165(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_165 * item = (I021_165 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_165(const I021_165 * item) {
    printf("Category 021 Item 155 - Track Angle Rate\n");
    printf("  TAR = %f\n", get_I021_165_TAR(item));
}