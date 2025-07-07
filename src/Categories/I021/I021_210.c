/**
 * @file I021_210.c
 * @brief Implementation of the Category 21 Item 210 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_210.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_210_VNS(const I021_210 * item) {
    return GET_BITS(item->raw, 7, MASK_01_BITS);
}

uint8_t get_I021_210_VN(const I021_210 * item) {
    return GET_BITS(item->raw, 4, MASK_03_BITS);
}

uint8_t get_I021_210_LTT(const I021_210 * item) {
    return GET_BITS(item->raw, 1, MASK_03_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_210_VNS(I021_210 * item, const uint8_t vns) {
    SET_BITS(&(item->raw), vns, MASK_01_BITS, 7);
}

void set_I021_210_VN(I021_210 * item, const uint8_t vn) {
    SET_BITS(&(item->raw), vn, MASK_03_BITS, 4);
}

void set_I021_210_LTT(I021_210 * item, const uint8_t ltt) {
    SET_BITS(&(item->raw), ltt, MASK_03_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_210(const I021_210 * item) {
    printf("Category 021 Item 200 - MOPS Version\n");
    printf("  VNS = %d\n", get_I021_210_VNS(item));
    printf("  VN = %d\n", get_I021_210_VN(item));
    printf("  LTT = %d\n", get_I021_210_LTT(item));
}