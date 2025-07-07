/**
 * @file I021_073.c
 * @brief Implementation of the Category 21 Item 073 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_073.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_I021_073_TMRP_raw(const I021_073 * item) {
    return (((uint32_t)item->raw[0] << 16) |
            ((uint32_t)item->raw[1] <<  8) |
            ((uint32_t)item->raw[2]      ));
}

double get_I021_073_TMRP_seconds(const I021_073 * item) {
    return (get_I021_073_TMRP_raw(item) * I021_073_LSB_TMRP);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_073_TMRP_raw(I021_073 * item, const uint32_t raw_value) {
    // TODO: Check raw_value is in valid range
    SET_BITS(&(item->raw[0]), (raw_value >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[1]), (raw_value >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[2]), (raw_value      ), MASK_08_BITS, 1);
}

void set_I021_073_TMRP_seconds(I021_073 * item, const double seconds) {
    uint32_t raw_value = 0;

    // TODO: Check value is in valid range

    // Turn to raw format and round to nearest unit if bigger than 0
    if (seconds > 0)
        raw_value = (uint32_t) ((seconds / I021_073_LSB_TMRP) + 0.5);

    set_I021_073_TMRP_raw(item, raw_value);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_073(const I021_073 * item) {
    printf("Category 021 Item 073 - Time of Message Reception for Position\n");
    printf("  TMRP (raw) = 0x%03X\n", get_I021_073_TMRP_raw(item));
    printf("  TMRP (seconds) = %f\n\n", get_I021_073_TMRP_seconds(item));
}
