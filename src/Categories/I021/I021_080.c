/**
 * @file I021_080.c
 * @brief Implementation of the Category 21 Item 080 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_080.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_I021_080_TGTADDR(const I021_080 * item) {
    return (((uint32_t) item->raw[0] << 16) |
            ((uint32_t) item->raw[1] <<  8) |
            ((uint32_t) item->raw[2]      ));
}
/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_080_TGTADDR(I021_080 * item, const uint32_t addr) {
    SET_BITS(&(item->raw[0]), (addr >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[1]), (addr >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[2]), (addr      ), MASK_08_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_080(const I021_080 * item) {
    printf("Category 021 Item 080 - Target ICAO Address (24 bits)\n");
    printf("  ICAO Addr = 0x%03X\n", get_I021_080_TGTADDR(item));
}