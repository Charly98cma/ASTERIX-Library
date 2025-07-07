/**
 * @file I021_260.c
 * @brief Implementation of the Category 21 Item 260 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_260.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_260_TYP(const I021_260 * item) {
    return GET_BITS(item->raw[0], 4, MASK_05_BITS);
}

uint8_t get_I021_260_STYP(const I021_260 * item) {
    return GET_BITS(item->raw[0], 1, MASK_03_BITS);
}

uint16_t get_I021_260_ARA(const I021_260 * item) {
    return ((GET_BITS(item->raw[1], 1, MASK_08_BITS) << 6) |
            (GET_BITS(item->raw[2], 3, MASK_06_BITS)     ));
}

uint8_t get_I021_260_RAC(const I021_260 * item) {
    return ((GET_BITS(item->raw[2], 1, MASK_02_BITS) << 2) |
            (GET_BITS(item->raw[3], 7, MASK_02_BITS)     ));
}

uint8_t get_I021_260_RAT(const I021_260 * item) {
    return GET_BITS(item->raw[3], 6, MASK_01_BITS);
}

uint8_t get_I021_260_MTE(const I021_260 * item) {
    return GET_BITS(item->raw[3], 5, MASK_01_BITS);
}

uint8_t get_I021_260_TTI(const I021_260 * item) {
    return GET_BITS(item->raw[3], 3, MASK_02_BITS);
}

uint32_t get_I021_260_TID(const I021_260 * item) {
    return ((GET_BITS(item->raw[3], 1, MASK_02_BITS) << 24) |
            (GET_BITS(item->raw[4], 1, MASK_08_BITS) << 16) |
            (GET_BITS(item->raw[5], 1, MASK_08_BITS) <<  8) |
            (GET_BITS(item->raw[6], 1, MASK_08_BITS)      ));
    
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_260_TYP(I021_260 * item, const uint8_t typ) {
    SET_BITS(&(item->raw[0]), typ, MASK_05_BITS, 4);
}

void set_I021_260_STYP(I021_260 * item, const uint8_t styp) {
    SET_BITS(&(item->raw[0]), styp, MASK_03_BITS, 1);
}

void set_I021_260_ARA(I021_260 * item, const uint16_t ara) {
    SET_BITS(&(item->raw[1]), (ara >> 6), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[2]), (ara     ), MASK_06_BITS, 3);
}

void set_I021_260_RAC(I021_260 * item, const uint8_t rac) {
    SET_BITS(&(item->raw[2]), (rac >> 2), MASK_02_BITS, 1);
    SET_BITS(&(item->raw[3]), (rac     ), MASK_02_BITS, 7);
}

void set_I021_260_RAT(I021_260 * item, const uint8_t rat) {
    SET_BITS(&(item->raw[3]), rat, MASK_01_BITS, 6);
}

void set_I021_260_MTE(I021_260 * item, const uint8_t mte) {
    SET_BITS(&(item->raw[3]), mte, MASK_01_BITS, 5);
}

void set_I021_260_TTI(I021_260 * item, const uint8_t tti) {
    SET_BITS(&(item->raw[3]), tti, MASK_02_BITS, 3);
}

void set_I021_260_TID(I021_260 * item, const uint32_t tid) {
    SET_BITS(&(item->raw[3]), (tid >> 24), MASK_02_BITS, 1);
    SET_BITS(&(item->raw[4]), (tid >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[5]), (tid >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[6]), (tid      ), MASK_08_BITS, 1);   
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_260(const I021_260 * item) {
    printf("Category 021 Item 260 - ACAS Resolution Advisory Report\n");
    printf("  TYP = %d\n", get_I021_260_TYP(item));
    printf("  STYP = %d\n", get_I021_260_STYP(item));
    printf("  ARA = %d\n", get_I021_260_ARA(item));
    printf("  RAC = %d\n", get_I021_260_RAC(item));
    printf("  RAT = %d\n", get_I021_260_RAT(item));
    printf("  MTE = %d\n", get_I021_260_MTE(item));
    printf("  TTI = %d\n", get_I021_260_TTI(item));
    printf("  TID = %d\n", get_I021_260_TID(item));
}
