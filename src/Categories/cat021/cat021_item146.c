/**
 * @file cat021_item146.c
 * @brief Implementation of the Category 21 Item 146 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item146.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item146_SAS(const cat021_item146 * item)
{
    return GET_BITS(item->raw, 16, MASK_01_BITS);
}

uint8_t get_cat021_item146_SRC(const cat021_item146 * item)
{
    return GET_BITS(item->raw, 14, MASK_02_BITS);
}

int32_t get_cat021_item146_ALT(const cat021_item146 * item)
{
    return (int32_t) (GET_BITS(item->raw, 1, MASK_13_BITS) * CAT021_ITEM146_LSB_ALT);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item146_SAS(cat021_item146 * item, const uint8_t sas)
{
    SET_BITS(&(item->raw), sas, MASK_01_BITS, 16);
}

void set_cat021_item146_SRC(cat021_item146 * item, const uint8_t src)
{
    SET_BITS(&(item->raw), src, MASK_02_BITS, 14);
}

void set_cat021_item146_ALT(cat021_item146 * item, const int32_t alt)
{
    uint16_t alt_raw = 0;

    // TODO: Check value is within valid range
    if (alt > 0)
        alt_raw = (uint16_t) ((alt / CAT021_ITEM146_LSB_ALT) + 0.5);

    SET_BITS(&(item->raw), alt_raw, MASK_13_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item146(const cat021_item146 * item)
{
    printf("Category 021 Item 146 - Selected Altitude\n");
    printf("  SAS = %d\n", get_cat021_item146_SAS(item));
    printf("  SRC = %d\n", get_cat021_item146_SRC(item));
    printf("  ALT = %d\n", get_cat021_item146_ALT(item));
}
