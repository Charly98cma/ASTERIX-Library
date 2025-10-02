/**
 * @file I021_230.c
 * @brief Implementation of the Category 21 Item 230 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_230.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_230_RA(const I021_230 * item) {
    return ((item->raw[0] << 8) | item->raw[1]) * I021_230_LSB_RA;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_230_RA(I021_230 * item, double ra_deg) {
    int16_t ra_raw = 0;

    if (ra_deg > 0)
        ra_raw = (int16_t) ((ra_deg / I021_230_LSB_RA) + 0.5);

    item->raw[0] = ra_raw >> 8;
    item->raw[1] = ra_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_230(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_230 * item = (I021_230 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_230(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_230 * item = (I021_230 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_230(const I021_230 * item) {
    printf("Category 021 Item 230 - Roll Angle\n");
    printf("  ROLL ANGLE = %f\n", get_I021_230_RA(item));
}
