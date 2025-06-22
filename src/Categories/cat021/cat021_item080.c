/**
 * @file cat021_item080.c
 * @brief Implementation of the Category 21 Item 080 functions
 */

#include "Categories/cat021/cat021_item080.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_cat021_item080_TGTADDR(const cat021_item080 * item)
{
    return (((uint32_t) (item)->raw[0] << 16) |
            ((uint32_t) (item)->raw[1] <<  8) |
            ((uint32_t) (item)->raw[2]      ));
}
/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item080_TGTADDR(cat021_item080 * item, uint32_t addr)
{
    SET_BITS(&((item)->raw[0]), (addr >> 16), MASK_08_BITS, 1);
    SET_BITS(&((item)->raw[1]), (addr >>  8), MASK_08_BITS, 1);
    SET_BITS(&((item)->raw[2]), (addr      ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item080(const cat021_item080 * item)
{
    printf("Category 021 / Item 080 - Target ICAO Address (24 bits)\n");
    printf("  ICAO Addr = 0x%03X\n", get_cat021_item080_TGTADDR(item));
}