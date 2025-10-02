/**
 * @file I021_072.c
 * @brief Implementation of the Category 21 Item 072 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_072.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_I021_072_TAV_raw(const I021_072 * item) {
    return ((((uint32_t)item->raw[0]) << 16) |
            (((uint32_t)item->raw[1]) <<  8) |
            (((uint32_t)item->raw[2])      ));
}

double get_I021_072_TAV(const I021_072 * item) {
    return get_I021_072_TAV_raw(item) * I021_072_LSB_TAV;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_072_TAV_raw(I021_072 * item, uint32_t tav_raw) {
    item->raw[0] = tav_raw >> 16;
    item->raw[1] = tav_raw >>  8;
    item->raw[2] = tav_raw;
}

void set_I021_072_TAV(I021_072 * item, double tav_seconds) {
    uint32_t tav_raw = 0;

    /* TODO: Check value is in valid range */

    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (tav_seconds > 0)
        tav_raw = (uint32_t) ((tav_seconds / I021_072_LSB_TAV) + 0.5);

    set_I021_072_TAV_raw(item, tav_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_072(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_072 * item = (I021_072 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    return out_index;
}

uint16_t decode_I021_072(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_072 * item = (I021_072 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_072(const I021_072 * item) {
    printf("Category 021 Item 072 - Time of Applicability for Velocity\n");
    printf("  TAV (raw) = 0x%X\n", get_I021_072_TAV_raw(item));
    printf("  TAV (seconds) = %f\n\n", get_I021_072_TAV(item));
}
