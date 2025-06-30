/**
 * @file cat021_item210.c
 * @brief Implementation of the Category 21 Item 210 functions
 */

#include <stdio.h>
#include "Categories/cat021/cat021_item210.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item210_VNS(const cat021_item210 * item)
{
    return GET_BITS((item)->raw, 7, MASK_01_BITS);
}

uint8_t get_cat021_item210_VN(const cat021_item210 * item)
{
    return GET_BITS((item)->raw, 4, MASK_03_BITS);
}

uint8_t get_cat021_item210_LTT(const cat021_item210 * item)
{
    return GET_BITS((item)->raw, 1, MASK_03_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item210_VNS(cat021_item210 * item, uint8_t vns)
{
    SET_BITS(&((item)->raw), vns, MASK_01_BITS, 7);
}

void set_cat021_item210_VN(cat021_item210 * item, uint8_t vn)
{
    SET_BITS(&((item)->raw), vn, MASK_03_BITS, 4);
}

void set_cat021_item210_LTT(cat021_item210 * item, uint8_t ltt)
{
    SET_BITS(&((item)->raw), ltt, MASK_03_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item210(const cat021_item210 * item)
{
    printf("Category 021 / Item 200 - MOPS Version\n");
    printf("  VNS = %d\n", get_cat021_item210_VNS(item));
    printf("  VN = %d\n", get_cat021_item210_VN(item));
    printf("  LTT = %d\n", get_cat021_item210_LTT(item));
}