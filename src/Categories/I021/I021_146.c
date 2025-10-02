/**
 * @file I021_146.c
 * @brief Implementation of the Category 21 Item 146 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_146.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_146_SAS(const I021_146 * item) {
    return (item->raw[0] >> 7) & MASK_01_BITS;
}

uint8_t get_I021_146_SRC(const I021_146 * item) {
    return (item->raw[0] >> 5) & MASK_02_BITS;
}

int32_t get_I021_146_ALT(const I021_146 * item) {
    int32_t alt_raw = (((item->raw[0] & MASK_05_BITS) << 8) | (item->raw[1]));
    return alt_raw * I021_146_LSB_ALT;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_146_SAS(I021_146 * item, uint8_t sas) {
    item->raw[0] |= (sas & MASK_01_BITS) << 7;
}

void set_I021_146_SRC(I021_146 * item, uint8_t src) {
    item->raw[0] |= (src & MASK_02_BITS) << 5;
}

void set_I021_146_ALT(I021_146 * item, const int32_t alt) {
    int16_t alt_raw = 0;

    /* TODO: Check value is within valid range */
    if (alt > 0)
        alt_raw = (int16_t) ((alt / I021_146_LSB_ALT) + 0.5);

    item->raw[0] |= (alt_raw >> 8) & MASK_05_BITS;
    item->raw[1] = alt_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_146(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_146 * item = (I021_146 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_146(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_146 * item = (I021_146 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_146(const I021_146 * item) {
    printf("Category 021 Item 146 - Selected Altitude\n");
    printf("  SAS = %d\n", get_I021_146_SAS(item));
    printf("  SRC = %d\n", get_I021_146_SRC(item));
    printf("  ALT = %d\n", get_I021_146_ALT(item));
}
