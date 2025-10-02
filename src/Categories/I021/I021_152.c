/**
 * @file I021_152.c
 * @brief Implementation of the Category 21 Item 152 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_152.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_152_MH(const I021_152 * item) {
    uint8_t mh_raw = ((item->raw[0]) << 8) | item->raw[1];
    return mh_raw * I021_152_LSB_MH;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_152_MH(I021_152 * item, double mh) {
    uint16_t mh_raw = 0;

    if (mh > 0)
        mh_raw = (uint16_t) ((mh / I021_152_LSB_MH) + 0.5);

   item->raw[0] = mh_raw >> 8;
   item->raw[1] = mh_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_152(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_152 * item = (I021_152 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_152(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_152 * item = (I021_152 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_152(const I021_152 * item) {
    printf("Category 021 Item 152 - Magnetic Heading\n");
    printf("  MH (degrees) = %f\n", get_I021_152_MH(item));
}