/**
 * @file I021_250.c
 * @brief Implementation of the Category 21 Item 250 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_250.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

#define BDS_BYTE(index, offset) (1 + ((index) * I021_250_BDSREG_N_OCTETS) + (offset))

uint8_t get_I021_250_REP(const I021_250 * item) {
    return GET_BITS(item->raw[0], 1, MASK_08_BITS);
}

uint64_t get_I021_250_BDSDATA(const I021_250 * item, const uint8_t bds_index) {
    uint64_t bds_register = (
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 0)], 1, MASK_08_BITS)) << 48) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 1)], 1, MASK_08_BITS)) << 40) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 2)], 1, MASK_08_BITS)) << 32) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 3)], 1, MASK_08_BITS)) << 24) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 4)], 1, MASK_08_BITS)) << 16) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 5)], 1, MASK_08_BITS)) <<  8) |
        ((uint64_t)(GET_BITS(item->raw[BDS_BYTE(bds_index, 6)], 1, MASK_08_BITS))      )
    );
    return bds_register;
}

uint8_t get_I021_250_BDS1(const I021_250 * item, const uint8_t bds_index) {
    return GET_BITS((item->raw[BDS_BYTE(bds_index, 7)]), 5, MASK_04_BITS);
}

uint8_t get_I021_250_BDS2(const I021_250 * item, const uint8_t bds_index) {
    return GET_BITS((item->raw[BDS_BYTE(bds_index, 7)]), 1, MASK_04_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_250_REP(I021_250 * item, uint8_t rep) {
    SET_BITS(&(item->raw[0]), rep, MASK_08_BITS, 1);
}

void set_I021_250_BDSDATA(I021_250 * item, const uint8_t bds_index, const uint64_t bds_data) {
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 0)]), (bds_data >> 48), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 1)]), (bds_data >> 40), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 2)]), (bds_data >> 32), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 3)]), (bds_data >> 24), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 4)]), (bds_data >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 5)]), (bds_data >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 6)]), (bds_data      ), MASK_08_BITS, 1);
}

void set_I021_250_BDS1(I021_250 * item, const uint8_t bds_index, const uint8_t bds1) {
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 7)]), bds1, MASK_04_BITS, 5);
}

void set_I021_250_BDS2(I021_250 * item, const uint8_t bds_index, const uint8_t bds2) {
    SET_BITS(&(item->raw[BDS_BYTE(bds_index, 7)]), bds2, MASK_04_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_250(const I021_250 * item) {
    uint8_t i, rep = 0;
    uint64_t bds_reg = 0;

    rep = get_I021_250_REP(item);

    printf("Category 021 Item 250 - BDS Register Data\n");
    printf("  REP = %d\n", rep);

    for (i = 0; i < rep; i++) {
        bds_reg = get_I021_250_BDSDATA(item, i);
        printf(" BDS Reg. Data (%d) = 0x%03X%04X\n", i,
                                                    (uint32_t)(bds_reg >> 32),
                                                    (uint32_t)(bds_reg      ));
        printf(" BDS Reg. Addr. 1 (%d) = 0x%X\n", i, get_I021_250_BDS1(item, i));
        printf(" BDS Reg. Addr. 1 (%d) = 0x%X\n", i, get_I021_250_BDS2(item, i));
    }
}