/**
 * @file I021_157.c
 * @brief Implementation of the Category 21 Item 157 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_157.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_157_RE(const I021_157 * item) {
    return item->raw[0] & MASK_01_BITS;
}

double get_I021_157_GVR(const I021_157 * item) {
    int16_t gvr_raw = ((item->raw[0] & MASK_07_BITS) << 8) | item->raw[1];
    return  (gvr_raw * I021_157_LSB_GVR);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_157_RE(I021_157 * item, uint8_t re) {
   item->raw[0] |= (re & MASK_01_BITS) << 7;
}

void set_I021_157_GVR(I021_157 * item, double gvr_ftpmin) {
    int16_t gvr_raw = 0;

    if (gvr_ftpmin > 0)
        gvr_raw = (int16_t) ((gvr_ftpmin / I021_157_LSB_GVR) + 0.5);

    item->raw[0] |= (gvr_raw >> 8) & MASK_07_BITS;
    item->raw[1] = gvr_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_157(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_157 * item = (I021_157 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_157(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_157 * item = (I021_157 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_157(const I021_157 * item) {
    printf("Category 021 Item 157 - Geometric Vertical Rate\n");
    printf("  RE = %d\n", get_I021_157_RE(item));
    printf("  GVR (feet/minute) = %f\n", get_I021_157_GVR(item));
}