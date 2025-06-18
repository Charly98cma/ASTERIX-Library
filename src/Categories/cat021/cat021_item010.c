/**
 * @file cat021_item010.c
 * @brief Implementation of the Category 21 Item 010 functions
 */

#include "cat021_item010.h"
#include "constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item010_SAC(const cat021_item010 * item)
{
    return get_item010_SIC((item010 *) item);
}

uint8_t get_cat021_item010_SIC(const cat021_item010 * item)
{
    return get_item010_SIC((item010 *) item);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item010_SAC(cat021_item010 * item, uint8_t sac_value)
{
    set_item010_SAC((item010 *) item, sac_value);
}

void set_cat021_item010_SIC(cat021_item010 * item, uint8_t sic_value)
{
    set_item010_SIC((item010 *) item, sic_value);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item010(const cat021_item010 *item)
{
    printf("CAT021 / Item 010 - Data Source Identification\n");
    printf("  SAC: 0x%02X\n", get_item010_SAC(item));
    printf("  SIC: 0x%02X\n\n", get_item010_SIC(item));
}
