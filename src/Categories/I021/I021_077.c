/**
 * @file I021_077.c
 * @brief Implementation of the Category 21 Item 077 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_077.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_I021_077_TART_raw(const I021_077 * item) {
    return ((((uint32_t) item->raw[0]) << 16) |
            (((uint32_t) item->raw[1]) <<  8) |
            (((uint32_t) item->raw[2])      ));
}

double get_I021_077_TART(const I021_077 * item) {
    return get_I021_077_TART_raw(item) * I021_077_LSB_TART;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_077_TART_raw(I021_077 * item, uint32_t tart_raw) {
    /* TODO: Check value is in valid range */
    item->raw[0] = (tart_raw >> 16);
    item->raw[1] = (tart_raw >>  8);
    item->raw[2] =tart_raw;
}

void set_I021_077_TART(I021_077 * item, double tart_seconds) {
    uint32_t tart_raw = 0;

    /* TODO: Check value is in valid range */

    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (tart_seconds > 0)
        tart_raw = (uint32_t) ((tart_seconds / I021_077_LSB_TART) + 0.5);

    set_I021_077_TART_raw(item, tart_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_077(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_077 * item = (I021_077 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    return out_index;
}

uint16_t decode_I021_077(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_077 * item = (I021_077 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_077(const I021_077 * item) {
    printf("Category 021 Item 077 - Time of ASTERIX Report Transmission\n");
    printf("  TART (raw) = 0x%03X\n", get_I021_077_TART_raw(item));
    printf("  TART (seconds) = %f\n\n", get_I021_077_TART(item));
}