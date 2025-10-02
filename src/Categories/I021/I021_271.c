/**
 * @file I021_271.c
 * @brief Implementation of the Category 21 Item 271 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_271.h"


/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_271_POA(const I021_271 * item) {
    return (item->raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_271_CDTIS(const I021_271 * item) {
    return (item->raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_271_B2(const I021_271 * item) {
    return (item->raw >> 3) & MASK_01_BITS;
}

uint8_t get_I021_271_RAS(const I021_271 * item) {
    return (item->raw >> 2) & MASK_01_BITS;
}

uint8_t get_I021_271_IDENT(const I021_271 * item) {
    return (item->raw >> 1) & MASK_01_BITS;
}

uint8_t get_I021_271_FX(const I021_271 * item) {
    return item->raw & MASK_01_BITS;
}

uint8_t get_I021_271_EXT1_LW(const I021_271_EXT1 * item) {
    return (item->raw >> 4) & MASK_04_BITS;
}

uint8_t get_I021_271_EXT1_FX(const I021_271_EXT1 * item) {
    return item->raw & MASK_01_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_271_POA(I021_271 * item, uint8_t poa) {
    item->raw |= (poa & MASK_01_BITS) << 5;
}

void set_I021_271_CDTIS(I021_271 * item, uint8_t cdtis) {
    item->raw |= (cdtis & MASK_01_BITS) << 4;
}

void set_I021_271_B2(I021_271 * item, uint8_t b2) {
    item->raw |= (b2 & MASK_01_BITS) << 3;
}

void set_I021_271_RAS(I021_271 * item, uint8_t ras) {
    item->raw |= (ras & MASK_01_BITS) << 2;
}

void set_I021_271_IDENT(I021_271 * item, uint8_t ident) {
    item->raw |= (ident & MASK_01_BITS) << 1;
}

void set_I021_271_FX(I021_271 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

void set_I021_271_EXT1_LW(I021_271_EXT1 * item, uint8_t lw) {
    item->raw |= (lw & MASK_04_BITS) << 4;
}

void set_I021_271_EXT1_FX(I021_271_EXT1 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_271(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_271 * item = (I021_271 *) item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_271(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_271 * item = (I021_271 *) item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_271(const I021_271 * item) {
    printf("Category 021 Item 271 - Surface Capabilities and Characteristics\n");
    printf("  POA = %d\n", get_I021_271_POA(item));
    printf("  CDTIS = %d\n", get_I021_271_CDTIS(item));
    printf("  B2 = %d\n", get_I021_271_B2(item));
    printf("  RAS = %d\n", get_I021_271_RAS(item));
    printf("  IDENT = %d\n", get_I021_271_IDENT(item));
    printf("  FX = %d\n", get_I021_271_FX(item));

    if (get_I021_271_FX(item)) {
        printf("  EXT1_LW = %d\n", get_I021_271_EXT1_LW(&(item->ext1)));
        printf("  EXT1_FX = %d\n", get_I021_271_EXT1_FX(&(item->ext1)));
    }
}