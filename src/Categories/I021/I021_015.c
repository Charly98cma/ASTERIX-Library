/**
 * @file I021_015.c
 * @brief Implementation of the Category 21 Item 015 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_015.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_015_SI(const I021_015 * item) {
    return GET_BITS(item->raw, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_015_SI(I021_015 * item, const uint8_t value) {
    SET_BITS(&(item->raw), value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_015(const I021_015 *item) {
    printf("Category 021 Item 015 - Service Identification\n");
    printf("  SI: 0x%02X\n\n", get_I021_015_SI(item));
}
