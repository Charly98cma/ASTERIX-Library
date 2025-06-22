/**
 * @file cat021_item077.c
 * @brief Implementation of the Category 21 Item 077 functions
 */

#include "Categories/cat021/cat021_item077.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_cat021_item077_TART_raw(const cat021_item077 * item)
{
    return (uint32_t) (((uint32_t)item->raw[0] << 16) |
                       ((uint32_t)item->raw[1] <<  8) |
                       ((uint32_t)item->raw[2]      ));
}

double get_cat021_item077_TART_seconds(const cat021_item077 * item)
{
    return (double) (get_cat021_item077_TART_raw(item) * LSB_CAT021_ITEM077);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item077_TART_raw(cat021_item077 * item, uint32_t raw_value)
{
    SET_BITS(&(item->raw[0]), (raw_value >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[1]), (raw_value >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[2]), (raw_value      ), MASK_08_BITS, 1);
}

void set_cat021_item077_TART_seconds(cat021_item077 * item, double seconds)
{
    uint32_t raw_value = 0;

    // Turn to raw format and round to nearest unit if bigger than 0
    if (seconds > 0)
        raw_value = (uint32_t) ((seconds / LSB_CAT021_ITEM077) + 0.5);

    set_cat021_item077_TART_raw(item, raw_value);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item077(const cat021_item077 * item)
{
    printf("Category 021 / Item 077 - Time of ASTERIX Report Transmission\n");
    printf("  TART (raw) = 0x%03X\n", get_cat021_item077_TART_raw(item));
    printf("  TART (seconds) = %f\n\n", get_cat021_item077_TART_seconds(item));
}