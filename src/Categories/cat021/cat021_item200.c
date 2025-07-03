/**
 * @file cat021_item200.c
 * @brief Implementation of the Category 21 Item 200 functions
 */

#include <stdio.h>
#include "Categories/cat021/cat021_item200.h"
#include "Common/constants.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item200_ICF(const cat021_item200 * item)
{
    return GET_BITS((item)->raw, 8, MASK_01_BITS);
}

uint8_t get_cat021_item200_LNAV(const cat021_item200 * item)
{
    return GET_BITS((item)->raw, 7, MASK_01_BITS);
}

uint8_t get_cat021_item200_ME(const cat021_item200 * item)
{
    return GET_BITS((item)->raw, 6, MASK_01_BITS);
}

uint8_t get_cat021_item200_PS(const cat021_item200 * item)
{
    return GET_BITS((item)->raw, 3, MASK_03_BITS);
}

uint8_t get_cat021_item200_SS(const cat021_item200 * item)
{
    return GET_BITS((item)->raw, 1, MASK_02_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item200_ICF(cat021_item200 * item, uint8_t icf)
{
    // TODO: Check valus is within range
    SET_BITS(&((item)->raw), icf, MASK_01_BITS, 8);
}

void set_cat021_item200_LNAV(cat021_item200 * item, uint8_t lnav)
{
    // TODO: Check valus is within range
    SET_BITS(&((item)->raw), lnav, MASK_01_BITS, 7);
}

void set_cat021_item200_ME(cat021_item200 * item, uint8_t me)
{
    // TODO: Check valus is within range
    SET_BITS(&((item)->raw), me, MASK_01_BITS, 6);
}

void set_cat021_item200_PS(cat021_item200 * item, uint8_t ps)
{
    // TODO: Check valus is within range
    SET_BITS(&((item)->raw), ps, MASK_03_BITS, 3);
}

void set_cat021_item200_SS(cat021_item200 * item, uint8_t ss)
{
    // TODO: Check valus is within range
    SET_BITS(&((item)->raw), ss, MASK_02_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item200(const cat021_item200 * item)
{
    printf("Category 021 Item 200 - Target Status\n");
    printf("  ICF = %d\n", get_cat021_item200_ICF(item));    
    printf("  LNAV = %d\n", get_cat021_item200_LNAV(item));    
    printf("  ME = %d\n", get_cat021_item200_ME(item));    
    printf("  PS = %d\n", get_cat021_item200_PS(item));    
    printf("  SS = %d\n", get_cat021_item200_SS(item));
}
