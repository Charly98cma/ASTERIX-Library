/**
 * @file I021_148.c
 * @brief Implementation of the Category 21 Item 148 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_148.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_148_MV(const I021_148 * item) {
    return GET_BITS(item->raw, 16, MASK_01_BITS);
}

uint8_t get_I021_148_AH(const I021_148 * item) {
    return GET_BITS(item->raw, 15, MASK_02_BITS);
}

uint8_t get_I021_148_AM(const I021_148 * item) {
    return GET_BITS(item->raw, 14, MASK_01_BITS);
}

int32_t get_I021_148_ALT(const I021_148 * item) {
    return (int32_t) (GET_BITS(item->raw, 1, MASK_13_BITS) * I021_148_LSB_ALT);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_148_MV(I021_148 * item, const uint8_t sas) {
    SET_BITS(&(item->raw), sas, MASK_01_BITS, 16);
}

void set_I021_148_AH(I021_148 * item, const uint8_t src) {
    SET_BITS(&(item->raw), src, MASK_01_BITS, 15);
}

void set_I021_148_AM(I021_148 * item, const uint8_t src) {
    SET_BITS(&(item->raw), src, MASK_01_BITS, 14);
}

void set_I021_148_ALT(I021_148 * item, const int32_t alt) {
    int16_t alt_raw = 0;

    // TODO: Check value is within valid range
    if (alt > 0)
        alt_raw = (int16_t) ((alt / I021_148_LSB_ALT) + 0.5);

    SET_BITS(&(item->raw), alt_raw, MASK_13_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_148(const I021_148 * item) {
    printf("Category 021 Item 148 - Final State Selected Altitude\n");
    printf("  MV = %d\n", get_I021_148_MV(item));
    printf("  AH = %d\n", get_I021_148_AH(item));
    printf("  AM = %d\n", get_I021_148_AM(item));
    printf("  ALT = %d\n", get_I021_148_ALT(item));
}
