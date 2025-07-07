/**
 * @file SAC_SIC.c
 * @brief Implementation of the Item 010 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/SAC_SIC.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_SAC(const SAC_SIC * item) {
    return GET_BITS(item->raw[0], 1, MASK_08_BITS);
}

uint8_t get_SIC(const SAC_SIC * item) {
    return GET_BITS(item->raw[1], 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_SAC(SAC_SIC * item, uint8_t sac_value) {
    SET_BITS(&(item->raw[0]), sac_value, MASK_08_BITS, 1);
}

void set_SIC(SAC_SIC * item, uint8_t sic_value) {
    SET_BITS(&(item->raw[1]), sic_value, MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/
