/**
 * @file I021_151.c
 * @brief Implementation of the Category 21 Item 151 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_151.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_151_RE(const I021_151 * item) {
    return GET_BITS(item->raw, 16, MASK_01_BITS);
}

uint16_t get_I021_151_TAS(const I021_151 * item) {
    return GET_BITS(item->raw, 1, MASK_15_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_151_RE(I021_151 * item, const uint8_t re) {
    SET_BITS(&(item->raw), re, MASK_01_BITS, 16);
}

void set_I021_151_TAS(I021_151 * item, const uint16_t tas) {
    SET_BITS(&(item->raw), tas, MASK_15_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_151(const I021_151 * item) {
    printf("Category 021 Item 151 - True Air Speed\n");
    printf("  RE = %d\n", get_I021_151_RE(item));
    printf("  TAS = %d\n", get_I021_151_TAS(item));
}