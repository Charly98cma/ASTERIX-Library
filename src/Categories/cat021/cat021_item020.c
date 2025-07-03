/**
 * @file cat021_item020.c
 * @brief Implementation of the Category 21 Item 020 functions
 */

#include "Categories/cat021/cat021_item020.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item020_ECAT(const cat021_item020 * item)
{
    return GET_BITS((item)->raw, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item020_ECAT(cat021_item020 * item, uint8_t value)
{
    // TODO: Check value and return OK/FAIL
    SET_BITS(&(item->raw), value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item020(const cat021_item020 *item)
{
    printf("Category 021 Item 020 - Emitter Category\n");
    printf("  ECAT: %d\n\n", get_cat021_item020_ECAT(item));  
}
