/**
 * @file I021_016.c
 * @brief Implementation of the Category 21 Item 016 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_016.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_016_RP_raw(const I021_016 * item) {
    return GET_BITS(item->raw, 1, MASK_08_BITS);
}

double get_I021_016_RP_seconds(const I021_016 * item) {
    return get_I021_016_RP_raw(item) * I021_016_LSB_RP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_016_RP_raw(I021_016 * item, const uint8_t raw_value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), raw_value, MASK_08_BITS, 1);
}

void set_I021_016_RP_seconds(I021_016 * item, const  double seconds) {
    uint8_t raw_value = 0;

    // TODO: Check value is in valid range

    // Change from seconds to raw value, rounding to nearest unit
    if (seconds > 0)
        raw_value = (uint8_t) (seconds / I021_016_LSB_RP + 0.5);

    SET_BITS(&(item->raw), raw_value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_016(const I021_016 *item) {
    printf("Category 021 Item 016 - Service Management\n");
    printf("  RP (raw): 0x%02X\n", get_I021_016_RP_raw(item));
    printf("  RP (seconds): %f\n\n", get_I021_016_RP_seconds(item));
}