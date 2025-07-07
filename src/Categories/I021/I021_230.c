/**
 * @file I021_230.c
 * @brief Implementation of the Category 21 Item 230 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_230.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_230_RA(const I021_230 * item) {
    int16_t ra_raw = (int16_t) (
        (GET_BITS(item->raw[0], 1, MASK_08_BITS) << 8) |
        (GET_BITS(item->raw[1], 1, MASK_08_BITS)     ));
    return (ra_raw * I021_230_LSB_RA);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_230_RA(I021_230 * item, const double ra) {
    int16_t ra_raw = 0;

    if (ra > 0)
        ra_raw = (int16_t) ((ra / I021_230_LSB_RA) + 0.5);

    SET_BITS(&(item->raw[0]), (ra_raw >> 8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[1]), (ra_raw     ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_230(const I021_230 * item) {
    printf("Category 021 Item 230 - Roll Angle\n");
    printf("  ROLL ANGLE = %f\n", get_I021_230_RA(item));
}
