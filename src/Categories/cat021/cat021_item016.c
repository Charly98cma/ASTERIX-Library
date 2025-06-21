/**
 * @file cat021_item016.c
 * @brief Implementation of the Category 21 Item 016 functions
 */

#include "cat021_item016.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item016_RP_raw(const cat021_item016 * item)
{
    return GET_BITS((item)->raw, 1, MASK_08_BITS);
}

double get_cat021_item016_RP_seconds(const cat021_item016 * item)
{
    return get_cat021_item016_RP(item) * LSB_CAT021_ITEM016_RP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item016_RP_raw(cat021_item016 * item, uint8_t raw_value)
{
    SET_BITS(&((item)->raw), raw_value, MASK_08_BITS, 1);
}

void set_cat021_item016_RP_seconds(cat021_item016 * item, double seconds)
{
    uint8_t raw_value = 0;

    // Change raw value to seconds rounding to nearest unit
    if (seconds > 0)
        raw_value = (uint8_t) (uint8_t) (seconds / LSB_CAT021_ITEM016_RP) + 0.5;

    SET_BITS(&((item)->raw), raw_value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item016(const cat021_item016 *item)
{
    printf("Category 021 / Item 016 - Service Management\n");
    printf("  RP (raw): 0x%02X\n", get_cat021_item016_RP(item));
    printf("  RP (seconds): %f\n\n", get_cat021_item016_RP_seconds(item));
}