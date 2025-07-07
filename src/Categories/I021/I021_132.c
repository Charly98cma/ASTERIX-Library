/**
 * @file I021_132.c
 * @brief Implementation of the Category 21 Item 132 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_132.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_132_MAM(const I021_132 * item) {
    return GET_BITS(item->raw, 1, MASK_08_BITS) * I021_132_LSB_MAM;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_132_MAM(I021_132 * item, const uint8_t value) {
    SET_BITS(&(item->raw), (int8_t) (value * I021_132_LSB_MAM), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_132(const I021_132 * item) {
    printf("Category 021 Item 132 - Message Amplitude\n");
    printf("  MAM (dBm's) = %d\n", get_I021_132_MAM(item));
}