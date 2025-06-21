/**
 * @file cat021_item075.c
 * @brief Implementation of the Category 21 Item 075 functions
 */

#include "cat021_item075.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_cat021_item075_TMRV_raw(const cat021_item075 * item)
{
    return (uint32_t) (((uint32_t)item->raw[0] << 16) |
                       ((uint32_t)item->raw[1] <<  8) |
                       ((uint32_t)item->raw[2]      ));
}

double get_cat021_item075_TMRV_seconds(const cat021_item075 * item)
{
    return (double) (get_cat021_item075_TMRV_raw(item) * LSB_CAT021_ITEM075);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item075_TMRV_raw(cat021_item075 * item, uint32_t raw_value)
{
    // TODO: Check raw_values is in valid range
    SET_BITS(&(item->raw[0]), (raw_value >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[1]), (raw_value >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[2]), (raw_value      ), MASK_08_BITS, 1);
}

void set_cat021_item075_TMRV_seconds(cat021_item075 * item, double seconds)
{
    uint32_t raw_value = 0;

    // Turn to raw format and round to nearest unit if bigger than 0
    if (seconds > 0)
        raw_value = (uint32_t) ((seconds / LSB_CAT021_ITEM075) + 0.5);

    set_cat021_item075_TMRV_raw(item, raw_value);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item075(const cat021_item075 * item)
{
    printf("Category 021 / Item 075 - Time of Message Reception for Velocity\n");
    printf("  TMRV (raw) = 0x%03X\n", get_cat021_item075_TMRV_raw(item));
    printf("  TMRV (seconds) = %f\n\n", get_cat021_item075_TMRV_seconds(item));
}