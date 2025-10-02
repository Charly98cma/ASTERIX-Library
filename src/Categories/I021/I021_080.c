/**
 * @file I021_080.c
 * @brief Implementation of the Category 21 Item 080 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_080.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_I021_080_TGTADDR(const I021_080 * item) {
    return ((((uint32_t) item->raw[0]) << 16) |
            (((uint32_t) item->raw[1]) <<  8) |
            (((uint32_t) item->raw[2])      ));
}
/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_080_TGTADDR(I021_080 * item, uint32_t addr) {
    item->raw[0] = (addr >> 16);
    item->raw[1] = (addr >>  8);
    item->raw[2] =addr;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_080(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_080 * item = (I021_080 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    return out_index;
}

uint16_t decode_I021_080(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_080 * item = (I021_080 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_080(const I021_080 * item) {
    printf("Category 021 Item 080 - Target ICAO Address (24 bits)\n");
    printf("  ICAO Addr = 0x%03X\n", get_I021_080_TGTADDR(item));
}