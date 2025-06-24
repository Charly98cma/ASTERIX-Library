/**
 * @file cat021_item145.c
 * @brief Implementation of the Category 21 Item 145 functions
 */

#include "Categories/cat021/cat021_item145.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

ASTERIX_API double get_cat021_item145_FL_raw(const cat021_item145 * item)
{
    return GET_BITS((item)->raw, 1, MASK_16_BITS);
}

ASTERIX_API double get_cat021_item145_FL_feet(const cat021_item145 * item)
{
    return (double) (get_cat021_item145_FL_raw(item) * LSB_CAT021_ITEM145);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

ASTERIX_API void set_cat021_item145_FL_raw(cat021_item145 * item,
                                           uint16_t fl_raw)
{
    // TODO: Check value is within limits
    SET_BITS(&((item)->raw), (fl_raw >> 8), MASK_08_BITS, 9);
    SET_BITS(&((item)->raw), (fl_raw     ), MASK_08_BITS, 1);
}

ASTERIX_API void set_cat021_item145_FL_feet(cat021_item145 * item,
                                            uint16_t fl)
{
    uint16_t fl_raw = 0;

    // TODO: Check value is within limits
    // Make the conversion only if value requiers it
    if (fl > 0)
        fl_raw = (uint16_t) ((fl / LSB_CAT021_ITEM145) + 0.5);
    
    set_cat021_item145_fl_raw(item, fl_raw);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

ASTERIX_API void print_cat021_item145(const cat021_item145 * item)
{
    printf("Category 021 / Item 145 - Flight Level\n");
    printf("  FL (steps of 1/4 FL's) = %d\n", get_cat021_item145_FL_raw(item));
    printf("  FL = %d\n", get_cat021_item145_FL_feet(item));
}