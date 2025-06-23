/**
 * @file cat021_item132.c
 * @brief Implementation of the Category 21 Item 132 functions
 */

#include "Categories/cat021/cat021_item132.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

ASTERIX_API uint8_t get_cat021_item132_MAM(const cat021_item132 * item)
{
    return GET_BITS((item)->raw, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

ASTERIX_API uint8_t set_cat021_item132_MAM(cat021_item132 * item, uint8_t value)
{
    SET_BITS(&((item)->raw), value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

ASTERIX_API void print_cat021_item132(const cat021_item132 * item)
{
    printf("Category 021 / Item 132 - Message Amplitude\n");
    printf("  MAM (dBm's) = %d\n", get_cat021_item132_MAM(item));
}