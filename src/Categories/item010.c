/**
 * @file item010.c
 * @brief Implementation of the Item 010 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/item010.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_item010_SAC(const item010 * item)
{
    return GET_BITS(item->raw[0], 1, MASK_08_BITS);
}

uint8_t get_item010_SIC(const item010 * item)
{
    return GET_BITS(item->raw[1], 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_item010_SAC(item010 * item, uint8_t sac_value)
{
    SET_BITS(&(item->raw[0]), sac_value, MASK_08_BITS, 1);
}

void set_item010_SIC(item010 * item, uint8_t sic_value)
{
    SET_BITS(&(item->raw[1]), sic_value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/
