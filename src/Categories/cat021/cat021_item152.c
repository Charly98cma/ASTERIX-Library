/**
 * @file cat021_item152.c
 * @brief Implementation of the Category 21 Item 152 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item152.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_cat021_item152_MH(const cat021_item152 * item)
{
    return GET_BITS(item->raw, 1, MASK_16_BITS) * CAT021_ITEM152_LSB_TAS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item152_MH(cat021_item152 * item, const double mh)
{
    uint16_t mh_raw = 0;

    if (mh > 0)
        mh_raw = (uint16_t) ((mh / CAT021_ITEM152_LSB_TAS) + 0.5);

    SET_BITS(&(item->raw), mh_raw, MASK_16_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item152(const cat021_item152 * item)
{
    printf("Category 021 Item 152 - Magnetic Heading\n");
    printf("  MH (degrees) = %f\n", get_cat021_item152_MH(item));
}