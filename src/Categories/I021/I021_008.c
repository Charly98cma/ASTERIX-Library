/**
 * @file I021_008.c
 * @brief Implementation of the Category 21 Item 008 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_008.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_008_RA(const I021_008 * item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_008_TC(const I021_008 * item) {
    return (item->raw >> 5) & MASK_02_BITS;
}

uint8_t get_I021_008_TS(const I021_008 * item) {
    return (item->raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_008_ARV(const I021_008 * item) {
    return (item->raw >> 3) & MASK_01_BITS;
}

uint8_t get_I021_008_CDTI(const I021_008 * item) {
    return (item->raw >> 2) & MASK_01_BITS;
}

uint8_t get_I021_008_NTCAS(const I021_008 * item) {
    return (item->raw >> 1) & MASK_01_BITS;
}

uint8_t get_I021_008_SA(const I021_008 * item) {
    return item->raw & MASK_01_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_008_RA(I021_008 * item, uint8_t ra) {
    /* TODO: Check value is in valid range */
    item->raw |= (ra & MASK_01_BITS) << 7;
}

void set_I021_008_TC(I021_008 * item, uint8_t tc) {
    /* TODO: Check value is in valid range */
    item->raw |= (tc & MASK_02_BITS) << 5;
}

void set_I021_008_TS(I021_008 * item, uint8_t ts) {
    /* TODO: Check value is in valid range */
    item->raw |= (ts & MASK_01_BITS) << 4;
}

void set_I021_008_ARV(I021_008 * item, uint8_t arv) {
    /* TODO: Check value is in valid range */
    item->raw |= (arv & MASK_01_BITS) << 3;
}

void set_I021_008_CDTI(I021_008 * item, uint8_t cdti) {
    /* TODO: Check value is in valid range */
    item->raw |= (cdti & MASK_01_BITS) << 2;
}

void set_I021_008_NTCAS(I021_008 * item, uint8_t ntcas) {
    /* TODO: Check value is in valid range */
    item->raw |= (ntcas & MASK_01_BITS) << 1;
}

void set_I021_008_SA(I021_008 * item, uint8_t sa) {
    /* TODO: Check value is in valid range */
    item->raw |= sa & MASK_01_BITS;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_008(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_008 * item = (I021_008 *) item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_008(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_008 * item = (I021_008 *) item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_008(const I021_008 *item) {
    printf("Category 021 Item 008 - Aircraft Operational Status\n");
    printf("  RA: %d\n", get_I021_008_RA(item));
    printf("  TC: %d\n", get_I021_008_TC(item));
    printf("  TS: %d\n", get_I021_008_TS(item));
    printf("  ARV: %d\n", get_I021_008_ARV(item));
    printf("  CDTI: %d\n", get_I021_008_CDTI(item));
    printf("  NTCAS: %d\n", get_I021_008_NTCAS(item));
    printf("  SA: %d\n\n", get_I021_008_SA(item));
}
