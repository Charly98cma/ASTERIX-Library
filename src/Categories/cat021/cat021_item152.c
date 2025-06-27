/**
 * @file cat021_item152.c
 * @brief Implementation of the Category 21 Item 152 functions
 */

#include "Categories/cat021/cat021_item152.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_cat021_item152_MH(const cat021_item152 * item)
{
    return GET_BITS((item)->raw, 1, MASK_16_BITS) * LSB_CAT021_ITEM152_TAS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item152_MH(cat021_item152 * item, double mh)
{
    uint16_t mh_raw = 0;

    if (mh > 0)
        mh_raw = (uint16_t) ((mh / LSB_CAT021_ITEM152_TAS) + 0.5);

    SET_BITS(&((item)->raw), mh_raw, MASK_16_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item152(const cat021_item152 * item)
{
    printf("Category 021 / Item 152 - Magnetic Heading\n");
    printf("  MH (degrees) = %f\n", get_cat021_item152_MH(item));
}