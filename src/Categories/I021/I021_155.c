/**
 * @file I021_155.c
 * @brief Implementation of the Category 21 Item 155 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_155.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_155_RE(const I021_155 * item) {
    return GET_BITS(item->raw, 16, MASK_01_BITS);
}

double get_I021_155_BVR(const I021_155 * item) {
    return GET_BITS(item->raw, 1, MASK_15_BITS) * I021_155_LSB_BVR;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_155_RE(I021_155 * item, const uint8_t re) {
    SET_BITS(&(item->raw), re, MASK_01_BITS, 16);
}

void set_I021_155_BVR(I021_155 * item, const double bvr) {
    uint16_t bvr_raw = 0;

    if (bvr > 0)
        bvr_raw = (uint16_t) ((bvr / I021_155_LSB_BVR) + 0.5);

    SET_BITS(&(item->raw), bvr_raw, MASK_15_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_155(const I021_155 * item) {
    printf("Category 021 Item 155 - Barometric Vertical Rate\n");
    printf("  RE = %d\n", get_I021_155_RE(item));
    printf("  BVR (feet/minute) = %f\n", get_I021_155_BVR(item));
}