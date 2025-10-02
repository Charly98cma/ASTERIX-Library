/**
 * @file I021_073.c
 * @brief Implementation of the Category 21 Item 073 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_073.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_I021_073_TMRP_raw(const I021_073 * item) {
    return ((((uint32_t)item->raw[0]) << 16) |
            (((uint32_t)item->raw[1]) <<  8) |
            (((uint32_t)item->raw[2])      ));
}

double get_I021_073_TMRP(const I021_073 * item) {
    return get_I021_073_TMRP_raw(item) * I021_073_LSB_TMRP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_073_TMRP_raw(I021_073 * item, uint32_t tmrp_raw) {
    item->raw[0] = tmrp_raw >> 16;
    item->raw[1] = tmrp_raw >>  8;
    item->raw[2] = tmrp_raw;
}

void set_I021_073_TMRP(I021_073 * item, double seconds) {
    uint32_t raw_value = 0;

    /* TODO: Check value is in valid range */

    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (seconds > 0)
        raw_value = (uint32_t) ((seconds / I021_073_LSB_TMRP) + 0.5);

    set_I021_073_TMRP_raw(item, raw_value);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_073(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_073 * item = (I021_073 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    return out_index;
}

uint16_t decode_I021_073(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_073 * item = (I021_073 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_073(const I021_073 * item) {
    printf("Category 021 Item 073 - Time of Message Reception for Position\n");
    printf("  TMRP (raw) = 0x%X\n", get_I021_073_TMRP_raw(item));
    printf("  TMRP (seconds) = %f\n\n", get_I021_073_TMRP(item));
}
