/**
 * @file cat021_item271.c
 * @brief Implementation of the Category 21 Item 271 functions
 */

#include <stdio.h>
#include "Categories/cat021/cat021_item271.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item271_POA(const cat021_item271 * item)
{
    return GET_BITS(item->raw, 6, MASK_01_BITS);
}

uint8_t get_cat021_item271_CDTIS(const cat021_item271 * item)
{
    return GET_BITS(item->raw, 5, MASK_01_BITS);
}

uint8_t get_cat021_item271_B2(const cat021_item271 * item)
{
    return GET_BITS(item->raw, 4, MASK_01_BITS);
}

uint8_t get_cat021_item271_RAS(const cat021_item271 * item)
{
    return GET_BITS(item->raw, 3, MASK_01_BITS);
}

uint8_t get_cat021_item271_IDENT(const cat021_item271 * item)
{
    return GET_BITS(item->raw, 2, MASK_01_BITS);
}

uint8_t get_cat021_item271_FX(const cat021_item271 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

uint8_t get_cat021_item271_ext1_LW(const cat021_item271_ext1 * item)
{
    return GET_BITS(item->raw, 5, MASK_04_BITS);
}

uint8_t get_cat021_item271_ext1_FX(const cat021_item271_ext1 * item)
{
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item271_POA(cat021_item271 * item, uint8_t poa)
{
    SET_BITS(&(item->raw), poa, MASK_01_BITS, 6);
}

void set_cat021_item271_CDTIS(cat021_item271 * item, uint8_t cdtis)
{
    SET_BITS(&(item->raw), cdtis, MASK_01_BITS, 5);
}

void set_cat021_item271_B2(cat021_item271 * item, uint8_t b2)
{
    SET_BITS(&(item->raw), b2, MASK_01_BITS, 4);
}

void set_cat021_item271_RAS(cat021_item271 * item, uint8_t ras)
{
    SET_BITS(&(item->raw), ras, MASK_01_BITS, 3);
}

void set_cat021_item271_IDENT(cat021_item271 * item, uint8_t ident)
{
    SET_BITS(&(item->raw), ident, MASK_01_BITS, 2);
}

void set_cat021_item271_FX(cat021_item271 * item, uint8_t fx)
{
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

void set_cat021_item271_ext1_LW(cat021_item271_ext1 * item, uint8_t lw)
{
    SET_BITS(&(item->raw), lw, MASK_04_BITS, 5);
}

void set_cat021_item271_ext1_FX(cat021_item271_ext1 * item, uint8_t fx)
{
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item271(const cat021_item271 * item)
{
    printf("Category 021 Item 271 - Surface Capabilities and Characteristics\n");
    printf("  POA = %d\n", get_cat021_item271_POA(item));
    printf("  CDTIS = %d\n", get_cat021_item271_CDTIS(item));
    printf("  B2 = %d\n", get_cat021_item271_B2(item));
    printf("  RAS = %d\n", get_cat021_item271_RAS(item));
    printf("  IDENT = %d\n", get_cat021_item271_IDENT(item));
    printf("  FX = %d\n", get_cat021_item271_FX(item));

    if (get_cat021_item271_FX(item))
    {
        printf("  ext1_LW = %d\n", get_cat021_item271_ext1_LW(&(item->ext1)));
        printf("  ext1_FX = %d\n", get_cat021_item271_ext1_FX(&(item->ext1)));
    }
}