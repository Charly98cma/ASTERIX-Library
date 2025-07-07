/**
 * @file I021_271.c
 * @brief Implementation of the Category 21 Item 271 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_271.h"


/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_271_POA(const I021_271 * item) {
    return GET_BITS(item->raw, 6, MASK_01_BITS);
}

uint8_t get_I021_271_CDTIS(const I021_271 * item) {
    return GET_BITS(item->raw, 5, MASK_01_BITS);
}

uint8_t get_I021_271_B2(const I021_271 * item) {
    return GET_BITS(item->raw, 4, MASK_01_BITS);
}

uint8_t get_I021_271_RAS(const I021_271 * item) {
    return GET_BITS(item->raw, 3, MASK_01_BITS);
}

uint8_t get_I021_271_IDENT(const I021_271 * item) {
    return GET_BITS(item->raw, 2, MASK_01_BITS);
}

uint8_t get_I021_271_FX(const I021_271 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

uint8_t get_I021_271_EXT1_LW(const I021_271_EXT1 * item) {
    return GET_BITS(item->raw, 5, MASK_04_BITS);
}

uint8_t get_I021_271_EXT1_FX(const I021_271_EXT1 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_271_POA(I021_271 * item, const uint8_t poa) {
    SET_BITS(&(item->raw), poa, MASK_01_BITS, 6);
}

void set_I021_271_CDTIS(I021_271 * item, const uint8_t cdtis) {
    SET_BITS(&(item->raw), cdtis, MASK_01_BITS, 5);
}

void set_I021_271_B2(I021_271 * item, const uint8_t b2) {
    SET_BITS(&(item->raw), b2, MASK_01_BITS, 4);
}

void set_I021_271_RAS(I021_271 * item, const uint8_t ras) {
    SET_BITS(&(item->raw), ras, MASK_01_BITS, 3);
}

void set_I021_271_IDENT(I021_271 * item, const uint8_t ident) {
    SET_BITS(&(item->raw), ident, MASK_01_BITS, 2);
}

void set_I021_271_FX(I021_271 * item, const uint8_t fx) {
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

void set_I021_271_EXT1_LW(I021_271_EXT1 * item, const uint8_t lw) {
    SET_BITS(&(item->raw), lw, MASK_04_BITS, 5);
}

void set_I021_271_EXT1_FX(I021_271_EXT1 * item, const uint8_t fx) {
    SET_BITS(&(item->raw), fx, MASK_01_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_271(const I021_271 * item) {
    printf("Category 021 Item 271 - Surface Capabilities and Characteristics\n");
    printf("  POA = %d\n", get_I021_271_POA(item));
    printf("  CDTIS = %d\n", get_I021_271_CDTIS(item));
    printf("  B2 = %d\n", get_I021_271_B2(item));
    printf("  RAS = %d\n", get_I021_271_RAS(item));
    printf("  IDENT = %d\n", get_I021_271_IDENT(item));
    printf("  FX = %d\n", get_I021_271_FX(item));

    if (get_I021_271_FX(item)) {
        printf("  EXT1_LW = %d\n", get_I021_271_EXT1_LW(&(item->ext1)));
        printf("  EXT1_FX = %d\n", get_I021_271_EXT1_FX(&(item->ext1)));
    }
}