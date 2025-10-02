/**
 * @file I021_210.c
 * @brief Implementation of the Category 21 Item 210 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_210.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_210_VNS(const I021_210 * item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_210_VN(const I021_210 * item) {
    return (item->raw >> 3) & MASK_03_BITS;
}

uint8_t get_I021_210_LTT(const I021_210 * item) {
    return item->raw & MASK_03_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_210_VNS(I021_210 * item, uint8_t vns) {
    item->raw |= (vns & MASK_01_BITS) << 6;
}

void set_I021_210_VN(I021_210 * item, uint8_t vn) {
    item->raw |= (vn & MASK_03_BITS) << 3;
}

void set_I021_210_LTT(I021_210 * item, uint8_t ltt) {
    item->raw |= ltt & MASK_03_BITS;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_210(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_210 * item = (I021_210 *) item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_210(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_210 * item = (I021_210 *) item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_210(const I021_210 * item) {
    printf("Category 021 Item 200 - MOPS Version\n");
    printf("  VNS = %d\n", get_I021_210_VNS(item));
    printf("  VN = %d\n", get_I021_210_VN(item));
    printf("  LTT = %d\n", get_I021_210_LTT(item));
}