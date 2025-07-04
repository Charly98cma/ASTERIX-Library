/**
 * @file cat021_item132.c
 * @brief Implementation of the Category 21 Item 132 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item132.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item132_MAM(const cat021_item132 * item)
{
    return GET_BITS(item->raw, 1, MASK_08_BITS) * CAT021_ITEM132_LSB_MAM;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item132_MAM(cat021_item132 * item, const uint8_t value)
{
    SET_BITS(&(item->raw), (int8_t) (value * CAT021_ITEM132_LSB_MAM), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item132(const cat021_item132 * item)
{
    printf("Category 021 Item 132 - Message Amplitude\n");
    printf("  MAM (dBm's) = %d\n", get_cat021_item132_MAM(item));
}