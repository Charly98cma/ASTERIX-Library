/**
 * @file I021_075.c
 * @brief Implementation of the Category 21 Item 075 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_075.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_I021_075_TMRV_raw(const I021_075 * item) {
    return ((((uint32_t)item->raw[0]) << 16) |
            (((uint32_t)item->raw[1]) <<  8) |
            (((uint32_t)item->raw[2])      ));
}

double get_I021_075_TMRV(const I021_075 * item) {
    return get_I021_075_TMRV_raw(item) * I021_075_LSB_TMRV;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_075_TMRV_raw(I021_075 * item, uint32_t tmrv_raw) {
    item->raw[0] = tmrv_raw >> 16;
    item->raw[1] = tmrv_raw >>  8;
    item->raw[2] = tmrv_raw;
}

void set_I021_075_TMRV(I021_075 * item, double tmrv_seconds) {
    uint32_t tmrv_raw = 0;

    /* TODO: Check value is in valid range */

    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (tmrv_seconds > 0)
        tmrv_raw = (uint32_t) ((tmrv_seconds / I021_075_LSB_TMRV) + 0.5);

    set_I021_075_TMRV_raw(item, tmrv_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_075(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_075 * item = (I021_075 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    return out_index;
}

uint16_t decode_I021_075(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_075 * item = (I021_075 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_075(const I021_075 * item) {
    printf("Category 021 Item 075 - Time of Message Reception for Velocity\n");
    printf("  TMRV (raw) = 0x%03X\n", get_I021_075_TMRV_raw(item));
    printf("  TMRV (seconds) = %f\n\n", get_I021_075_TMRV(item));
}