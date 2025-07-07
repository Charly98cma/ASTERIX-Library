/**
 * @file I021_165.c
 * @brief Implementation of the Category 21 Item 165 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_165.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_165_TAR(const I021_165 * item) {
    int16_t tar_raw = (int16_t) (
        (GET_BITS(item->raw[0], 1, MASK_02_BITS) << 8) |
        (GET_BITS(item->raw[1], 1, MASK_08_BITS))
    );

    return tar_raw * I021_165_LSB_TAR;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_165_TAR(I021_165 * item, const double tar) {
    int16_t tar_raw = 0;

    // TODO: Check TAR value in valid range
    if (tar > 0)
        tar_raw = (int16_t) ((tar / I021_165_LSB_TAR) + 0.5);

    SET_BITS(&(item->raw[0]), (tar_raw >> 8), MASK_02_BITS, 1);
    SET_BITS(&(item->raw[1]), (tar_raw     ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_165(const I021_165 * item) {
    printf("Category 021 Item 155 - Track Angle Rate\n");
    printf("  TAR = %f\n", get_I021_165_TAR(item));
}