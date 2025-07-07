/**
 * @file I021_010.c
 * @brief Implementation of the Category 21 Item 010 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_010.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_010_SAC(const I021_010 * item) {
    return get_SIC((SAC_SIC *) item);
}

uint8_t get_I021_010_SIC(const I021_010 * item) {
    return get_SIC((SAC_SIC *) item);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_010_SAC(I021_010 * item, const uint8_t sac_value) {
    set_SAC((SAC_SIC *) item, sac_value);
}

void set_I021_010_SIC(I021_010 * item, const uint8_t sic_value) {
    set_SIC((SAC_SIC *) item, sic_value);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_010(const I021_010 *item) {
    printf("Category 021 Item 010 - Data Source Identification\n");
    printf("  SAC: 0x%02X\n", get_I021_010_SAC(item));
    printf("  SIC: 0x%02X\n\n", get_I021_010_SIC(item));
}
