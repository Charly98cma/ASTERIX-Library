/**
 * @file cat021_item165.c
 * @brief Implementation of the Category 21 Item 165 functions
 */

#include <stdio.h>
#include "Categories/cat021/cat021_item165.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_cat021_item165_TAR(const cat021_item165 * item)
{
    int16_t tar_raw = (int16_t) (
        (GET_BITS(item->raw[0], 1, MASK_02_BITS) << 8) |
        (GET_BITS(item->raw[1], 1, MASK_08_BITS))
    );

    return tar_raw * CAT021_ITEM165_LSB_TAR;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item165_TAR(cat021_item165 * item, double tar)
{
    int16_t tar_raw = 0;

    // TODO: Check TAR value in valid range
    if (tar > 0)
        tar_raw = (int16_t) ((tar / CAT021_ITEM165_LSB_TAR) + 0.5);

    SET_BITS(&(item->raw[0]), (tar_raw >> 8), MASK_02_BITS, 1);
    SET_BITS(&(item->raw[1]), (tar_raw     ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item165(const cat021_item165 * item)
{
    printf("Category 021 / Item 155 - Track Angle Rate\n");
    printf("  TAR = %f\n", get_cat021_item165_TAR(item));
}