/**
 * @file I021_145.c
 * @brief Implementation of the Category 21 Item 145 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_145.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint16_t get_I021_145_FL_raw(const I021_145 * item) {
    return GET_BITS(item->raw, 1, MASK_16_BITS);
}

int16_t get_I021_145_FL_feet(const I021_145 * item) {
    return (int16_t) (get_I021_145_FL_raw(item) * I021_145_LSB_FL);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_145_FL_raw(I021_145 * item, const uint16_t fl_raw) {
    // TODO: Check value is within limits
    SET_BITS(&(item->raw), (fl_raw >> 8), MASK_08_BITS, 9);
    SET_BITS(&(item->raw), (fl_raw     ), MASK_08_BITS, 1);
}

void set_I021_145_FL_feet(I021_145 * item, const int16_t fl) {
    uint16_t fl_raw = 0;

    // TODO: Check value is within limits
    // Make the conversion only if value requiers it
    if (fl > 0)
        fl_raw = (uint16_t) ((fl / I021_145_LSB_FL) + 0.5);
    
    set_I021_145_FL_raw(item, fl_raw);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_145(const I021_145 * item) {
    printf("Category 021 Item 145 - Flight Level\n");
    printf("  FL (steps of 1/4 FL's) = %d\n", get_I021_145_FL_raw(item));
    printf("  FL = %d\n", get_I021_145_FL_feet(item));
}