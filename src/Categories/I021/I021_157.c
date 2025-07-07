/**
 * @file I021_157.c
 * @brief Implementation of the Category 21 Item 157 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_157.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_157_RE(const I021_157 * item) {
    return GET_BITS(item->raw[0], 8, MASK_01_BITS);
}

double get_I021_157_GVR(const I021_157 * item) {
    int16_t raw_gvr = (int16_t) (
        (GET_BITS(item->raw[0], 1, MASK_07_BITS) << 8) |
        (GET_BITS(item->raw[1], 1, MASK_08_BITS)     ));

    return  (raw_gvr * I021_157_LSB_GVR);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_157_RE(I021_157 * item, const uint8_t re) {
    SET_BITS(&(item->raw[0]), re, MASK_01_BITS, 8);
}

void set_I021_157_GVR(I021_157 * item, const double gvr) {
    int16_t gvr_raw = 0;

    if (gvr > 0)
        gvr_raw = (int16_t) ((gvr / I021_157_LSB_GVR) + 0.5);

    SET_BITS(&(item->raw[0]), (gvr_raw >> 8), MASK_07_BITS, 1);
    SET_BITS(&(item->raw[1]), (gvr_raw     ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_157(const I021_157 * item) {
    printf("Category 021 Item 157 - Geometric Vertical Rate\n");
    printf("  RE = %d\n", get_I021_157_RE(item));
    printf("  GVR (feet/minute) = %f\n", get_I021_157_GVR(item));
}