/**
 * @file I021_145.c
 * @brief Implementation of the Category 21 Item 145 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_145.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

int16_t get_I021_145_FL_raw(const I021_145 * item) {
    return ((item->raw[0] << 8) | (item->raw[1]));
}

int16_t get_I021_145_FL_feet(const I021_145 * item) {
    return get_I021_145_FL_raw(item) * I021_145_LSB_FL;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_145_FL_raw(I021_145 * item, const int16_t fl_raw) {
    item->raw[0] = fl_raw >> 8;
    item->raw[1] = fl_raw;
}

void set_I021_145_FL_feet(I021_145 * item, const int16_t fl) {
    int16_t fl_raw = 0;

    /* TODO: Check value is within limits */

    /* Make the conversion only if value requiers it */
    if (fl > 0)
        fl_raw = (fl / I021_145_LSB_FL) + 0.5;

    set_I021_145_FL_raw(item, fl_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_145(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_145 * item = (I021_145 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_145(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_145 * item = (I021_145 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_145(const I021_145 * item) {
    printf("Category 021 Item 145 - Flight Level\n");
    printf("  FL (steps of 1/4 FL's) = 0x%04X\n", get_I021_145_FL_raw(item));
    printf("  FL = %d\n", get_I021_145_FL_feet(item));
}