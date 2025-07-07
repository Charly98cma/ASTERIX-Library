/**
 * @file I021_152.c
 * @brief Implementation of the Category 21 Item 152 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_152.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_152_MH(const I021_152 * item) {
    return GET_BITS(item->raw, 1, MASK_16_BITS) * I021_152_LSB_TAS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_152_MH(I021_152 * item, const double mh) {
    uint16_t mh_raw = 0;

    if (mh > 0)
        mh_raw = (uint16_t) ((mh / I021_152_LSB_TAS) + 0.5);

    SET_BITS(&(item->raw), mh_raw, MASK_16_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_152(const I021_152 * item) {
    printf("Category 021 Item 152 - Magnetic Heading\n");
    printf("  MH (degrees) = %f\n", get_I021_152_MH(item));
}