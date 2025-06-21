/**
 * @file item010.c
 * @brief Implementation of the Item 010 functions
 */

#include "item010.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_item010_SAC(const item010 * item)
{
    return GET_BITS((item)->raw, 9, MASK_08_BITS);
}

uint8_t get_item010_SIC(const item010 * item)
{
    return GET_BITS((item)->raw, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_item010_SAC(item010 * item, uint8_t sac_value)
{
    SET_BITS(&(item->raw), sac_value, MASK_08_BITS, 9);
}

void set_item010_SIC(item010 * item, uint8_t sic_value)
{
    SET_BITS(&(item->raw), sic_value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item010(const item010 *item)
{
    printf("Item 010 - Data Source Identification\n");
    printf("  SAC = 0x%02X\n", get_item010_SAC(item));
    printf("  SIC = 0x%02X\n", get_item010_SIC(item));
}