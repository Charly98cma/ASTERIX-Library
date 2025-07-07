/**
 * @file I021_020.c
 * @brief Implementation of the Category 21 Item 020 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_020.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_020_ECAT(const I021_020 * item) {
    return GET_BITS(item->raw, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_020_ECAT(I021_020 * item, const uint8_t value) {
    // TODO: Check value and return OK/FAIL
    SET_BITS(&(item->raw), value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_020(const I021_020 *item) {
    printf("Category 021 Item 020 - Emitter Category\n");
    printf("  ECAT: %d\n\n", get_I021_020_ECAT(item));  
}
