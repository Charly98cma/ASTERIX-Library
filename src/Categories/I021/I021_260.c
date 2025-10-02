/**
 * @file I021_260.c
 * @brief Implementation of the Category 21 Item 260 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_260.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_260_TYP(const I021_260 * item) {
    return (item->raw[0] >> 3) & MASK_05_BITS;
}

uint8_t get_I021_260_STYP(const I021_260 * item) {
    return item->raw[0] & MASK_03_BITS;
}

uint16_t get_I021_260_ARA(const I021_260 * item) {
    return (item->raw[1] << 6) | ((item->raw[2] >> 2) & MASK_06_BITS);
}

uint8_t get_I021_260_RAC(const I021_260 * item) {
    return (((item->raw[2] & MASK_02_BITS) << 2) |
            ((item->raw[3] >> 6) & MASK_02_BITS));
}

uint8_t get_I021_260_RAT(const I021_260 * item) {
    return (item->raw[3] >> 5) & MASK_01_BITS;
}

uint8_t get_I021_260_MTE(const I021_260 * item) {
    return (item->raw[3] >> 4) & MASK_01_BITS;
}

uint8_t get_I021_260_TTI(const I021_260 * item) {
    return (item->raw[3] >> 2) & MASK_02_BITS;
}

uint32_t get_I021_260_TID(const I021_260 * item) {
    return (((item->raw[3] & MASK_02_BITS) << 24) |
            (item->raw[4] << 16) |
            (item->raw[5] <<  8) |
            item->raw[6]);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_260_TYP(I021_260 * item, uint8_t typ) {
    item->raw[0] |= (typ & MASK_05_BITS) << 3;
}

void set_I021_260_STYP(I021_260 * item, uint8_t styp) {
    item->raw[0] |= styp & MASK_03_BITS;
}

void set_I021_260_ARA(I021_260 * item, uint16_t ara) {
    item->raw[0] |= ara >> 6;
    item->raw[0] |= (ara & MASK_06_BITS) << 2;
}

void set_I021_260_RAC(I021_260 * item, uint8_t rac) {
    item->raw[2] |= (rac >> 2) & MASK_02_BITS;
    item->raw[3] |= (rac & MASK_02_BITS) << 6;
}

void set_I021_260_RAT(I021_260 * item, uint8_t rat) {
    item->raw[3] |= (rat & MASK_01_BITS) << 5;
}

void set_I021_260_MTE(I021_260 * item, uint8_t mte) {
    item->raw[3] |= (mte & MASK_01_BITS) << 4;
}

void set_I021_260_TTI(I021_260 * item, uint8_t tti) {
    item->raw[3] |= (tti & MASK_02_BITS) << 2;
}

void set_I021_260_TID(I021_260 * item, uint32_t tid) {
    item->raw[3] |= (tid >> 24) & MASK_02_BITS;
    item->raw[4] = tid >> 16;
    item->raw[5] = tid >>  8;
    item->raw[6] = tid;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_260(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_260 * item = (I021_260 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    msg_out[out_index++] = item->raw[3];
    msg_out[out_index++] = item->raw[4];
    msg_out[out_index++] = item->raw[5];
    msg_out[out_index++] = item->raw[6];
    return out_index;
}

uint16_t decode_I021_260(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_260 * item = (I021_260 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    item->raw[3] = msg_in[in_index++];
    item->raw[4] = msg_in[in_index++];
    item->raw[5] = msg_in[in_index++];
    item->raw[6] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_260(const I021_260 * item) {
    printf("Category 021 Item 260 - ACAS Resolution Advisory Report\n");
    printf("  TYP = %d\n", get_I021_260_TYP(item));
    printf("  STYP = %d\n", get_I021_260_STYP(item));
    printf("  ARA = 0x%04X\n", get_I021_260_ARA(item));
    printf("  RAC = 0x%02X\n", get_I021_260_RAC(item));
    printf("  RAT = %d\n", get_I021_260_RAT(item));
    printf("  MTE = %d\n", get_I021_260_MTE(item));
    printf("  TTI = %d\n", get_I021_260_TTI(item));
    printf("  TID = 0x%08X\n", get_I021_260_TID(item));
}
