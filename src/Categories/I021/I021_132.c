/**
 * @file I021_132.c
 * @brief Implementation of the Category 21 Item 132 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_132.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_132_MAM(const I021_132 * item) {
    return item->raw * I021_132_LSB_MAM;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_132_MAM(I021_132 * item, uint8_t mam_dBm) {
    item->raw = mam_dBm;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_132(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_132 * item = (I021_132 *) item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_132(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_132 * item = (I021_132 *) item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_132(const I021_132 * item) {
    printf("Category 021 Item 132 - Message Amplitude\n");
    printf("  MAM (dBm's) = %d\n", get_I021_132_MAM(item));
}