/**
 * @file I021_155.c
 * @brief Implementation of the Category 21 Item 155 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_155.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_155_RE(const I021_155 * item) {
    return (item->raw[0] >> 7) & MASK_01_BITS;
}

double get_I021_155_BVR(const I021_155 * item) {
    int16_t bvr_raw = ((item->raw[0] & MASK_07_BITS) << 8) | item->raw[1];
    return bvr_raw * I021_155_LSB_BVR;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_155_RE(I021_155 * item, uint8_t re) {
    item->raw[0] |= (re & MASK_01_BITS) >> 7;
}

void set_I021_155_BVR(I021_155 * item, double bvr_ftpmin) {
    int16_t bvr_raw = 0;

    if (bvr_ftpmin > 0)
        bvr_raw = (int16_t) ((bvr_ftpmin / I021_155_LSB_BVR) + 0.5);

    item->raw[0] |= (bvr_raw >> 8) & MASK_07_BITS;
    item->raw[1] |= bvr_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_155(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_155 * item = (I021_155 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_155(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_155 * item = (I021_155 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_155(const I021_155 * item) {
    printf("Category 021 Item 155 - Barometric Vertical Rate\n");
    printf("  RE = %d\n", get_I021_155_RE(item));
    printf("  BVR (feet/minute) = %f\n", get_I021_155_BVR(item));
}