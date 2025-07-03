/**
 * @file cat021_item008.c
 * @brief Implementation of the Category 21 Item 008 functions
 */

#include "Categories/cat021/cat021_item008.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item008_RA(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 8, MASK_01_BITS);
}

uint8_t get_cat021_item008_TC(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 6, MASK_02_BITS);
}

uint8_t get_cat021_item008_TS(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 5, MASK_01_BITS);
}

uint8_t get_cat021_item008_ARV(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 4, MASK_01_BITS);
}

uint8_t get_cat021_item008_CDTI(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 3, MASK_01_BITS);
}

uint8_t get_cat021_item008_NTCAS(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 2, MASK_01_BITS);
}

uint8_t get_cat021_item008_SA(const cat021_item008 * item)
{
    return GET_BITS((item)->raw, 1, MASK_01_BITS);;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item008_RA(cat021_item008 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 8);
}

void set_cat021_item008_TC(cat021_item008 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_02_BITS, 6);
}

void set_cat021_item008_TS(cat021_item008 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 5);
}

void set_cat021_item008_ARV(cat021_item008 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 4);
}

void set_cat021_item008_CDTI(cat021_item008 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 3);
}

void set_cat021_item008_NTCAS(cat021_item008 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 2);
}


void set_cat021_item008_SA(cat021_item008 * item, uint8_t value)
{
    // TODO: Check value is in valid range
    SET_BITS(&((item)->raw), value, MASK_01_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item008(const cat021_item008 *item)
{
    printf("Category 021 Item 008 - Aircraft Operational Status\n");
    printf("  RA: %d\n", get_cat021_item008_RA(item));
    printf("  TC: %d\n", get_cat021_item008_TC(item));
    printf("  TS: %d\n", get_cat021_item008_TS(item));
    printf("  ARV: %d\n", get_cat021_item008_ARV(item));
    printf("  CDTI: %d\n", get_cat021_item008_CDTI(item));
    printf("  NTCAS: %d\n", get_cat021_item008_NTCAS(item));
    printf("  SA: %d\n\n", get_cat021_item008_SA(item));
}
