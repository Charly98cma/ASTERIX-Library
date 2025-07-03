/**
 * @file cat021_item015.c
 * @brief Implementation of the Category 21 Item 015 functions
 */

#include "Categories/cat021/cat021_item015.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item015_SI(const cat021_item015 * item)
{
    return GET_BITS((item)->raw, 1, MASK_08_BITS);
}


/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item015_SI(cat021_item015 * item, uint8_t value)
{
    SET_BITS(&((item)->raw), value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item015(const cat021_item015 *item)
{
    printf("Category 021 Item 015 - Service Identification\n");
    printf("  SI: 0x%02X\n\n", get_cat021_item015_SI(item));
}
