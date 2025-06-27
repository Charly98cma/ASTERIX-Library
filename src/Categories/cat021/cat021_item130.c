/**
 * @file cat021_item130.c
 * @brief Implementation of the Category 21 Item 130 functions
 */

#include "Categories/cat021/cat021_item130.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_cat021_item130_LAT(const cat021_item130 * item)
{
    uint32_t lat_raw = 
        (((uint32_t) GET_BITS((item)->raw[0], 1, MASK_08_BITS) << 16) |
         ((uint32_t) GET_BITS((item)->raw[1], 1, MASK_08_BITS) <<  8) |
         ((uint32_t) GET_BITS((item)->raw[2], 1, MASK_08_BITS)      ));
    return (double) (lat_raw * LSB_CAT021_ITEM130_LAT);
}

double get_cat021_item130_LON(const cat021_item130 * item)
{
    uint32_t lon_raw = 
        (((uint32_t) GET_BITS((item)->raw[3], 1, MASK_08_BITS) << 16) |
         ((uint32_t) GET_BITS((item)->raw[4], 1, MASK_08_BITS) <<  8) |
         ((uint32_t) GET_BITS((item)->raw[5], 1, MASK_08_BITS)      ));
    return (double) (lon_raw * LSB_CAT021_ITEM130_LON);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item130_LAT(cat021_item130 * item, double lat)
{
    uint32_t lat_raw;

    // TODO: Check valus is within range

    // Change from degrees to raw value, rounding to nearest unit
    if (lat > 0.0)
        lat_raw = (uint32_t) (lat / LSB_CAT021_ITEM130_LAT + 0.5);

    SET_BITS(&(item->raw[0]), (lat_raw >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[1]), (lat_raw >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[2]), (lat_raw      ), MASK_08_BITS, 1);
}

void set_cat021_item130_LON(cat021_item130 * item, double lon)
{
    uint32_t lon_raw;

    // TODO: Check valus is within range

    // Change from degrees to raw value, rounding to nearest unit
    if (lon > 0.0)
        lon_raw = (uint32_t) (lon / LSB_CAT021_ITEM130_LAT + 0.5);

    SET_BITS(&(item->raw[3]), (lon_raw >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[4]), (lon_raw >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[5]), (lon_raw      ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item130(const cat021_item130 * item)
{
    printf("Category 021 / Item 130 - Position in WGS-84 Co-ordinates\n");
    printf("  LAT (degrees) = %f\n", get_cat021_item130_LAT(item));
    printf("  LON (degrees) = %f\n", get_cat021_item130_LON(item));
}
