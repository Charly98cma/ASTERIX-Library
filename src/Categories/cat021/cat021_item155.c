/**
 * @file cat021_item155.c
 * @brief Implementation of the Category 21 Item 155 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item155.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item155_RE(const cat021_item155 * item)
{
    return GET_BITS(item->raw, 16, MASK_01_BITS);
}

double get_cat021_item155_BVR(const cat021_item155 * item)
{
    return GET_BITS(item->raw, 1, MASK_15_BITS) * CAT021_ITEM155_LSB_BVR;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item155_RE(cat021_item155 * item, const uint8_t re)
{
    SET_BITS(&(item->raw), re, MASK_01_BITS, 16);
}

void set_cat021_item155_BVR(cat021_item155 * item, const double bvr)
{
    uint16_t bvr_raw = 0;

    if (bvr > 0)
        bvr_raw = (uint16_t) ((bvr / CAT021_ITEM155_LSB_BVR) + 0.5);

    SET_BITS(&(item->raw), bvr_raw, MASK_15_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item155(const cat021_item155 * item)
{
    printf("Category 021 Item 155 - Barometric Vertical Rate\n");
    printf("  RE = %d\n", get_cat021_item155_RE(item));
    printf("  BVR (feet/minute) = %f\n", get_cat021_item155_BVR(item));
}