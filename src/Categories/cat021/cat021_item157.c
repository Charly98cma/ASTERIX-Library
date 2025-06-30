/**
 * @file cat021_item157.c
 * @brief Implementation of the Category 21 Item 157 functions
 */

#include <stdio.h>
#include "Categories/cat021/cat021_item157.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item157_RE(const cat021_item157 * item)
{
    return GET_BITS(item->raw[0], 8, MASK_01_BITS);
}

double get_cat021_item157_GVR(const cat021_item157 * item)
{
    int16_t raw_gvr = (int16_t) ((GET_BITS(item->raw[0], 1, MASK_07_BITS) << 8) |
                                 (GET_BITS(item->raw[1], 1, MASK_08_BITS)     ));

    return  (double) (raw_gvr * CAT021_ITEM157_LSB_GVR);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item157_RE(cat021_item157 * item, uint8_t re)
{
    SET_BITS(&(item->raw[0]), re, MASK_01_BITS, 8);
}

void set_cat021_item157_GVR(cat021_item157 * item, double gvr)
{
    int16_t gvr_raw = 0;

    if (gvr > 0)
        gvr_raw = (int16_t) ((gvr / CAT021_ITEM157_LSB_GVR) + 0.5);

    SET_BITS(&(item->raw[0]), (gvr_raw >> 8), MASK_07_BITS, 1);
    SET_BITS(&(item->raw[1]), (gvr_raw     ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item157(const cat021_item157 * item)
{
    printf("Category 021 / Item 157 - Geometric Vertical Rate\n");
    printf("  RE = %d\n", get_cat021_item157_RE(item));
    printf("  GVR (feet/minute) = %f\n", get_cat021_item157_GVR(item));
}