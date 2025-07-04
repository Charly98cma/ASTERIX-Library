/**
 * @file cat021_item072.c
 * @brief Implementation of the Category 21 Item 072 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item072.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_cat021_item072_TAV_raw(const cat021_item072 * item)
{
    return (uint32_t) (((uint32_t)item->raw[0] << 16) |
                       ((uint32_t)item->raw[1] <<  8) |
                       ((uint32_t)item->raw[2]      ));
}

double get_cat021_item072_TAV_seconds(const cat021_item072 * item)
{
    return (double) get_cat021_item072_TAV_raw(item) * CAT021_ITEM072_LSB_TAV;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item072_TAV_raw(cat021_item072 * item, const uint32_t raw_value)
{
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[0]), (raw_value >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[1]), (raw_value >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[2]), (raw_value      ), MASK_08_BITS, 1);
}

void set_cat021_item072_TAV_seconds(cat021_item072 * item, const double seconds)
{
    uint32_t raw_value = 0;

    // TODO: Check value is in valid range

    // Turn to raw format and round to nearest unit if bigger than 0
    if (seconds <= 0)
        raw_value = (uint32_t) ((seconds / CAT021_ITEM072_LSB_TAV) + 0.5);

    set_cat021_item072_TAV_raw(item, raw_value);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item072(const cat021_item072 * item)
{
    printf("Category 021 Item 072 - Time of Applicability for Velocity\n");
    printf("  TAV (raw) = 0x%03X\n", get_cat021_item072_TAV_raw(item));
    printf("  TAV (seconds) = %f\n\n", get_cat021_item072_TAV_seconds(item));
}
