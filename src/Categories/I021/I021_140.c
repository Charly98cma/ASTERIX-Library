/**
 * @file I021_140.c
 * @brief Implementation of the Category 21 Item 140 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_140.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint16_t get_I021_140_GH_raw(const I021_140 * item) {
    return ((item->raw[0] << 8) | (item->raw[1]));
}

double get_I021_140_GH(const I021_140 * item) {
    return get_I021_140_GH_raw(item) * I021_140_LSB_GH;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_140_GH_raw(I021_140 * item, uint16_t gh_raw) {
    item->raw[0] = gh_raw >> 8;
    item->raw[1] =gh_raw;
}

void set_I021_140_GH(I021_140 * item, double gh_ft) {
    int16_t gh_raw = 0;

    /* TODO: Check value is within limits */

    /* Make the conversion only if value requiers it */
    if (gh_ft > 0)
        gh_raw = (int16_t) ((gh_ft / I021_140_LSB_GH) + 0.5);
    
    set_I021_140_GH_raw(item, gh_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_140(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_140 * item = (I021_140 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_140(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_140 * item = (I021_140 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_140(const I021_140 * item) {
    printf("Category 021 Item 140 - Geometric Height\n");
    printf("  GH (raw) = 0x%04X\n", get_I021_140_GH_raw(item));
    printf("  GH (feets) = %f\n", get_I021_140_GH(item));
}