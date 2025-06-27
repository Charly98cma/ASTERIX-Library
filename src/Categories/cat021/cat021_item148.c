/**
 * @file cat021_item148.c
 * @brief Implementation of the Category 21 Item 148 functions
 */

#include "Categories/cat021/cat021_item148.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item148_MV(const cat021_item148 * item)
{
    return GET_BITS((item)->raw, 16, MASK_01_BITS);
}

uint8_t get_cat021_item148_AH(const cat021_item148 * item)
{
    return GET_BITS((item)->raw, 15, MASK_02_BITS);
}

uint8_t get_cat021_item148_AM(const cat021_item148 * item)
{
    return GET_BITS((item)->raw, 14, MASK_01_BITS);
}

int32_t get_cat021_item148_ALT(const cat021_item148 * item)
{
    return (int32_t) (GET_BITS((item)->raw, 1, MASK_13_BITS) * LSB_CAT021_ITEM148_ALT);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item148_MV(cat021_item148 * item, uint8_t sas)
{
    SET_BITS(&((item)->raw), sas, MASK_01_BITS, 16);
}

void set_cat021_item148_AH(cat021_item148 * item, uint8_t src)
{
    SET_BITS(&((item)->raw), src, MASK_01_BITS, 15);
}

void set_cat021_item148_AM(cat021_item148 * item, uint8_t src)
{
    SET_BITS(&((item)->raw), src, MASK_01_BITS, 14);
}

void set_cat021_item148_ALT(cat021_item148 * item, int32_t alt)
{
    int16_t alt_raw = 0;

    // TODO: Check value is within valid range
    if (alt > 0)
        alt_raw = (int16_t) ((alt / LSB_CAT021_ITEM148_ALT) + 0.5);

    SET_BITS(&((item)->raw), alt_raw, MASK_13_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item148(const cat021_item148 * item)
{
    printf("Category 021 / Item 148 - Final State Selected Altitude\n");
    printf("  MV = %d\n", get_cat021_item148_MV(item));
    printf("  AH = %d\n", get_cat021_item148_AH(item));
    printf("  AM = %d\n", get_cat021_item148_AM(item));
    printf("  ALT = %d\n", get_cat021_item148_ALT(item));
}
