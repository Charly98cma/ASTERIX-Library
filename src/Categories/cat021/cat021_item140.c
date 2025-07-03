/**
 * @file cat021_item140.c
 * @brief Implementation of the Category 21 Item 140 functions
 */

#include "Categories/cat021/cat021_item140.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint16_t get_cat021_item140_GH_raw(const cat021_item140 * item)
{
    return GET_BITS((item)->raw, 1, MASK_16_BITS);
}

double get_cat021_item140_GH_feet(const cat021_item140 * item)
{
    return (double) (get_cat021_item140_GH_raw(item) * LSB_CAT021_ITEM140);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item140_GH_raw(cat021_item140 * item,
                                           uint16_t gh_raw)
{
    // TODO: Check value is within limits
    SET_BITS(&((item)->raw), (gh_raw >> 8), MASK_08_BITS, 9);
    SET_BITS(&((item)->raw), (gh_raw     ), MASK_08_BITS, 1);
}

void set_cat021_item140_GH_feet(cat021_item140 * item, double gh)
{
    uint16_t gh_raw = 0;

    // TODO: Check value is within limits
    // Make the conversion only if value requiers it
    if (gh > 0)
        gh_raw = (uint16_t) ((gh / LSB_CAT021_ITEM140) + 0.5);
    
    set_cat021_item140_GH_raw(item, gh_raw);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item140(const cat021_item140 * item)
{
    printf("Category 021 Item 140 - Geometric Height\n");
    printf("  GH (raw) = 0x%02X\n", get_cat021_item140_GH_raw(item));
    printf("  GH (feets) = %f\n", get_cat021_item140_GH_feet(item));
}