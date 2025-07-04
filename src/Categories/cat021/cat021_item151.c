/**
 * @file cat021_item151.c
 * @brief Implementation of the Category 21 Item 151 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item151.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item151_RE(const cat021_item151 * item)
{
    return GET_BITS(item->raw, 16, MASK_01_BITS);
}

uint16_t get_cat021_item151_TAS(const cat021_item151 * item)
{
    return GET_BITS(item->raw, 1, MASK_15_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item151_RE(cat021_item151 * item, const uint8_t re)
{
    SET_BITS(&(item->raw), re, MASK_01_BITS, 16);
}

void set_cat021_item151_TAS(cat021_item151 * item, const uint16_t tas)
{
    SET_BITS(&(item->raw), tas, MASK_15_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item151(const cat021_item151 * item)
{
    printf("Category 021 Item 151 - True Air Speed\n");
    printf("  RE = %d\n", get_cat021_item151_RE(item));
    printf("  TAS = %d\n", get_cat021_item151_TAS(item));
}