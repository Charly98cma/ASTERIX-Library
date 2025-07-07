/**
 * @file I021_140.c
 * @brief Implementation of the Category 21 Item 140 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_140.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint16_t get_I021_140_GH_raw(const I021_140 * item) {
    return GET_BITS(item->raw, 1, MASK_16_BITS);
}

double get_I021_140_GH_feet(const I021_140 * item) {
    return (get_I021_140_GH_raw(item) * I021_140_LSB_GH);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_140_GH_raw(I021_140 * item, const uint16_t gh_raw) {
    // TODO: Check value is within limits
    SET_BITS(&(item->raw), (gh_raw >> 8), MASK_08_BITS, 9);
    SET_BITS(&(item->raw), (gh_raw     ), MASK_08_BITS, 1);
}

void set_I021_140_GH_feet(I021_140 * item, const double gh) {
    uint16_t gh_raw = 0;

    // TODO: Check value is within limits
    // Make the conversion only if value requiers it
    if (gh > 0)
        gh_raw = (uint16_t) ((gh / I021_140_LSB_GH) + 0.5);
    
    set_I021_140_GH_raw(item, gh_raw);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_140(const I021_140 * item) {
    printf("Category 021 Item 140 - Geometric Height\n");
    printf("  GH (raw) = 0x%02X\n", get_I021_140_GH_raw(item));
    printf("  GH (feets) = %f\n", get_I021_140_GH_feet(item));
}