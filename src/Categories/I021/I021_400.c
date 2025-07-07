/**
 * @file I021_400.c
 * @brief Implementation of the Category 21 Item 400 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_400.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_400_RID(const I021_400 * item) {
    return GET_BITS(item->raw, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_400_RID(I021_400 * item, const uint8_t rid) {
    SET_BITS(&(item->raw), rid, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_400(const I021_400 * item) {
    printf("Category 021 Item 400 - Receiver ID\n");
    printf("  RID = %d\n", get_I021_400_RID(item));
}