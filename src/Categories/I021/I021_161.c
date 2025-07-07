/**
 * @file I021_161.c
 * @brief Implementation of the Category 21 Item 161 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_161.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint16_t get_I021_161_TRKNUM(const I021_161 * item) {
    uint16_t track_number = (int16_t) (
        (GET_BITS(item->raw[0], 1, MASK_04_BITS) << 8) |
        (GET_BITS(item->raw[1], 1, MASK_08_BITS)     ));

    return track_number;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_161_TRKNUM(I021_161 * item, const uint16_t track_number) {
    // TODO: Check TRKNUM value in valid range
    SET_BITS(&(item->raw[0]), (track_number >> 8), MASK_04_BITS, 1);
    SET_BITS(&(item->raw[1]), (track_number     ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_161(const I021_161 * item) {
    printf("Category 021 Item 161 - Track Number\n");
    printf("  TRACK NUMBER = %d\n", get_I021_161_TRKNUM(item));
}