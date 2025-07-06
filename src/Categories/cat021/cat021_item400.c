/**
 * @file cat021_item400.c
 * @brief Implementation of the Category 21 Item 400 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/cat021/cat021_item400.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_cat021_item400_RID(const cat021_item400 * item)
{
    return GET_BITS(item->raw, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_cat021_item400_RID(cat021_item400 * item, const uint8_t rid)
{
    SET_BITS(&(item->raw), rid, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_cat021_item400(const cat021_item400 * item)
{
    printf("Category 021 Item 400 - Receiver ID\n");
    printf("  RID = %d\n", get_cat021_item400_RID(item));
}