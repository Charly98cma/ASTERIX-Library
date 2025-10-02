/**
 * @file I021_200.c
 * @brief Implementation of the Category 21 Item 200 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_200.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_200_ICF(const I021_200 * item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_200_LNAV(const I021_200 * item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_200_ME(const I021_200 * item) {
    return (item->raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_200_PS(const I021_200 * item) {
    return (item->raw >> 2) & MASK_03_BITS;
}

uint8_t get_I021_200_SS(const I021_200 * item) {
    return item->raw & MASK_02_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_200_ICF(I021_200 * item, uint8_t icf) {
    /* TODO: Check valus is within range */
    item->raw |= (icf & MASK_01_BITS) <<  7;
}

void set_I021_200_LNAV(I021_200 * item, uint8_t lnav) {
    /* TODO: Check valus is within range */
    item->raw |= (lnav & MASK_01_BITS) <<  6;
}

void set_I021_200_ME(I021_200 * item, uint8_t me) {
    /* TODO: Check valus is within range */
    item->raw |= (me & MASK_01_BITS) <<  5;
}

void set_I021_200_PS(I021_200 * item, uint8_t ps) {
    /* TODO: Check valus is within range */
    item->raw |= (ps & MASK_03_BITS) <<  2;
}

void set_I021_200_SS(I021_200 * item, uint8_t ss) {
    /* TODO: Check valus is within range */
    item->raw |= ss & MASK_02_BITS;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_200(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_200 * item = (I021_200 *) item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_200(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_200 * item = (I021_200 *) item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_200(const I021_200 * item) {
    printf("Category 021 Item 200 - Target Status\n");
    printf("  ICF = %d\n", get_I021_200_ICF(item));    
    printf("  LNAV = %d\n", get_I021_200_LNAV(item));    
    printf("  ME = %d\n", get_I021_200_ME(item));    
    printf("  PS = %d\n", get_I021_200_PS(item));    
    printf("  SS = %d\n", get_I021_200_SS(item));
}
