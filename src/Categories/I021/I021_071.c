/**
 * @file I021_071.c
 * @brief Implementation of the Category 21 Item 071 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_071.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_I021_071_TAP_raw(const I021_071 * item) {
    return ((((uint32_t)item->raw[0]) << 16) |
            (((uint32_t)item->raw[1]) <<  8) |
            (((uint32_t)item->raw[2])      ));
}

double get_I021_071_TAP(const I021_071 * item) {
    return get_I021_071_TAP_raw(item) * I021_071_LSB_TAP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_071_TAP_raw(I021_071 * item, uint32_t tap_raw) {
    item->raw[0] = tap_raw >> 16;
    item->raw[1] = tap_raw >>  8;
    item->raw[2] = tap_raw & MASK_08_BITS;
}

void set_I021_071_TAP_seconds(I021_071 * item, double tap_seconds) {
    uint32_t tap_raw = 0;

    /* TODO: Check value is in valid range */

    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (tap_seconds > 0)
        tap_raw = (uint32_t) ((tap_seconds / I021_071_LSB_TAP) + 0.5);

    set_I021_071_TAP_raw(item, tap_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_071(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_071 * item = (I021_071 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    return out_index;
}

uint16_t decode_I021_071(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_071 * item = (I021_071 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_071(const I021_071 * item) {
    printf("Category 021 Item 071 - Time of Applicability for Position\n");
    printf("  TAP (raw) = 0x%X\n", get_I021_071_TAP_raw(item));
    printf("  TAP (seconds) = %f\n\n", get_I021_071_TAP(item));
}
