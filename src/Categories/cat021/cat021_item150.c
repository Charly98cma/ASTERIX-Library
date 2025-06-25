/**
 * @file cat021_item150.c
 * @brief Implementation of the Category 21 Item 150 functions
 */

#include "Categories/cat021/cat021_item150.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

ASTERIX_API uint8_t get_cat021_item150_IM(const cat021_item150 * item)
{
    return GET_BITS((item)->raw, 16, MASK_01_BITS);
}

ASTERIX_API double get_cat021_item150_AIRSPD(const cat021_item150 * item)
{
    double real_speed = 0;
    uint16_t raw_speed = GET_BITS((item)->raw, 1, MASK_15_BITS);

    if (get_cat021_item150_IM(item) == CAT021_ITEM150_IM_IAS)
        real_speed = raw_speed * LSB_CAT021_ITEM150_IAS;
    else
        real_speed = raw_speed * LSB_CAT021_ITEM150_MACH;

    return real_speed;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

ASTERIX_API void set_cat021_item150_IM(cat021_item150 * item, uint8_t im)
{
    SET_BITS(&((item)->raw), im, MASK_01_BITS, 16);
}

ASTERIX_API void set_cat021_item150_FL(cat021_item150 * item, double value)
{
    uint16_t raw_value = 0;

    if (get_cat021_item150_IM(item) == CAT021_ITEM150_IM_IAS)
        raw_value = value / LSB_CAT021_ITEM150_IAS;
    else
        raw_value = value / LSB_CAT021_ITEM150_MACH;

    SET_BITS(&((item)->raw), raw_value, MASK_15_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

ASTERIX_API void print_cat021_item150(const cat021_item150 * item)
{
    uint8_t im = get_cat021_item150_IM(item);

    printf("Category 021 / Item 150 - Air Speed\n");
    printf("  IM = %d\n", im);
    if (im == CAT021_ITEM150_IM_IAS)
        printf("  IAS = %f\n", get_cat021_item150_AIRSPD(item));
    else
        printf("  MACH = %f\n", get_cat021_item150_AIRSPD(item));
}