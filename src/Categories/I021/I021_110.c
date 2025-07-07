/**
 * @file I021_110.c
 * @brief Implementation of the Category 21 Item 110 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_110.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

uint8_t get_I021_110_TIS(const I021_110 * item) {
    return GET_BITS(item->raw, 8, MASK_01_BITS);
}

uint8_t get_I021_110_TID(const I021_110 * item) {
    return GET_BITS(item->raw, 7, MASK_01_BITS);
}

uint8_t get_I021_110_FX(const I021_110 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}


/* ============================= FIRST EXTENSION ============================ */

uint8_t get_I021_110_EXT1_NAV(const I021_110_EXT1 * item) {
    return GET_BITS(item->raw, 8, MASK_01_BITS);
}

uint8_t get_I021_110_EXT1_NVB(const I021_110_EXT1 * item) {
    return GET_BITS(item->raw, 7, MASK_01_BITS);
}

uint8_t get_I021_110_EXT1_FX(const I021_110_EXT1 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}


/* ============================ SECOND EXTENSION ============================ */

#define TIP_BYTE(index, offset) (1 + ((index) * NUM_BYTES_I021_110_EXT2) + (offset))

uint8_t get_I021_110_EXT2_REP(const I021_110_EXT2 * item) {
    return GET_BITS(item->raw[0], 1, MASK_08_BITS);
}

uint8_t get_I021_110_EXT2_TCA(const I021_110_EXT2 * item, const uint8_t index) {
    return GET_BITS(item->raw[TIP_BYTE(index, 0)], 8, MASK_01_BITS);
}

uint8_t get_I021_110_EXT2_NC(const I021_110_EXT2 * item, const uint8_t index) {
    return GET_BITS(item->raw[TIP_BYTE(index, 0)], 7, MASK_01_BITS);
}

uint8_t get_I021_110_EXT2_TCP_NUM(const I021_110_EXT2 * item, const uint8_t index) {
    return GET_BITS(item->raw[TIP_BYTE(index, 0)], 1, MASK_06_BITS);
}

int32_t get_I021_110_EXT2_ALT(const I021_110_EXT2 * item, const uint8_t index) {
    int32_t alt_raw = 
        ((int32_t) (GET_BITS(item->raw[TIP_BYTE(index, 1)], 1, MASK_08_BITS) << 8) |
         (int32_t) (GET_BITS(item->raw[TIP_BYTE(index, 2)], 1, MASK_08_BITS)     ));
    return alt_raw * I021_110_LSB_ALT; 
}

double get_I021_110_EXT2_LAT(const I021_110_EXT2 * item, const uint8_t index) {
    uint32_t lat_raw = 
        ((uint32_t) (GET_BITS(item->raw[TIP_BYTE(index, 3)], 1, MASK_08_BITS) << 16) |
         (uint32_t) (GET_BITS(item->raw[TIP_BYTE(index, 4)], 1, MASK_08_BITS) <<  8) |
         (uint32_t) (GET_BITS(item->raw[TIP_BYTE(index, 5)], 1, MASK_08_BITS)      ));
    return lat_raw * I021_110_LSB_LAT;
}

double get_I021_110_EXT2_LON(const I021_110_EXT2 * item, const uint8_t index) {
    uint32_t lon_raw = 
        ((uint32_t) (GET_BITS(item->raw[TIP_BYTE(index, 6)], 1, MASK_08_BITS) << 16) |
         (uint32_t) (GET_BITS(item->raw[TIP_BYTE(index, 7)], 1, MASK_08_BITS) <<  8) |
         (uint32_t) (GET_BITS(item->raw[TIP_BYTE(index, 8)], 1, MASK_08_BITS)      ));
    return lon_raw * I021_110_LSB_LON;
}

uint8_t get_I021_110_EXT2_PT(const I021_110_EXT2 * item, const uint8_t index) {
    return GET_BITS(item->raw[TIP_BYTE(index, 9)], 5, MASK_04_BITS);
}

uint8_t get_I021_110_EXT2_TD(const I021_110_EXT2 * item, const uint8_t index) {
    return GET_BITS(item->raw[TIP_BYTE(index, 9)], 3, MASK_02_BITS);
}

uint8_t get_I021_110_EXT2_TRA(const I021_110_EXT2 * item, const uint8_t index) {
    return GET_BITS(item->raw[TIP_BYTE(index, 9)], 2, MASK_01_BITS);
}

uint8_t get_I021_110_EXT2_TOA(const I021_110_EXT2 * item, const uint8_t index) {
    return GET_BITS(item->raw[TIP_BYTE(index, 9)], 1, MASK_01_BITS);
}

uint32_t get_I021_110_EXT2_TOV(const I021_110_EXT2 * item, const uint8_t index) {
    uint32_t tov_raw =
        ((uint32_t) (GET_BITS(item->raw[TIP_BYTE(index, 10)], 1, MASK_08_BITS) << 16) |
         (uint32_t) (GET_BITS(item->raw[TIP_BYTE(index, 11)], 1, MASK_08_BITS) <<  8) |
         (uint32_t) (GET_BITS(item->raw[TIP_BYTE(index, 12)], 1, MASK_08_BITS)      ));
    return tov_raw * I021_110_LSB_TOV;
}

double get_I021_110_EXT2_TTR(const I021_110_EXT2 * item, const uint8_t index) {
    uint16_t ttr_raw =
        ((uint16_t) (GET_BITS(item->raw[TIP_BYTE(index, 13)], 1, MASK_08_BITS) << 8) |
         (uint16_t) (GET_BITS(item->raw[TIP_BYTE(index, 14)], 1, MASK_08_BITS)     ));
    return ttr_raw * I021_110_LSB_TTR;
}


/*******************************************************************************
* Setters
******************************************************************************/

/* =============================== MAIN BYTE =============================== */

void set_I021_110_TIS(I021_110 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8);
}

void set_I021_110_TID(I021_110 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 7);
}

void set_I021_110_FX(I021_110 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}


/* ============================= FIRST EXTENSION ============================ */

void set_I021_110_EXT1_NAV(I021_110_EXT1 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 8);
}

void set_I021_110_EXT1_NVB(I021_110_EXT1 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 7);
}

void set_I021_110_EXT1_FX(I021_110_EXT1 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw), value, MASK_01_BITS, 1);
}


/* ============================ SECOND EXTENSION ============================ */

void set_I021_110_EXT2_REP(I021_110_EXT2 * item, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[0]), value, MASK_08_BITS, 1);
}

void set_I021_110_EXT2_TCA(I021_110_EXT2 * item, const uint8_t index, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[TIP_BYTE(index, 0)]), value, MASK_01_BITS, 8);
}

void set_I021_110_EXT2_NC(I021_110_EXT2 * item, const uint8_t index, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[TIP_BYTE(index, 0)]), value, MASK_01_BITS, 7);
}

void set_I021_110_EXT2_TCP_NUM(I021_110_EXT2 * item, const uint8_t index, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[TIP_BYTE(index, 0)]), value, MASK_01_BITS, 1);
}

void set_I021_110_EXT2_ALT(I021_110_EXT2 * item, const uint8_t index, double value) {
    uint16_t alt_raw;

    // TODO: Check value is in valid range

    alt_raw = value / I021_110_LSB_ALT;
    SET_BITS(&(item->raw[TIP_BYTE(index, 1)]), (alt_raw >> 8), MASK_08_BITS, 8);
    SET_BITS(&(item->raw[TIP_BYTE(index, 2)]), (alt_raw     ), MASK_08_BITS, 1);
}

void set_I021_110_EXT2_LAT(I021_110_EXT2 * item, const uint8_t index, uint32_t value) {
    uint16_t lat_raw;

    // TODO: Check value is in valid range

    lat_raw = value / I021_110_LSB_LAT;
    SET_BITS(&(item->raw[TIP_BYTE(index, 3)]), (lat_raw >> 16), MASK_08_BITS, 16);
    SET_BITS(&(item->raw[TIP_BYTE(index, 4)]), (lat_raw >>  8), MASK_08_BITS,  8);
    SET_BITS(&(item->raw[TIP_BYTE(index, 5)]), (lat_raw      ), MASK_08_BITS,  1);
}

void set_I021_110_EXT2_LON(I021_110_EXT2 * item, const uint8_t index, uint32_t value) {
    uint16_t lon_raw;

    // TODO: Check value is in valid range

    lon_raw = value / I021_110_LSB_LON;
    SET_BITS(&(item->raw[TIP_BYTE(index, 6)]), (lon_raw >> 16), MASK_08_BITS, 16);
    SET_BITS(&(item->raw[TIP_BYTE(index, 7)]), (lon_raw >>  8), MASK_08_BITS,  8);
    SET_BITS(&(item->raw[TIP_BYTE(index, 8)]), (lon_raw      ), MASK_08_BITS,  1);
}

void set_I021_110_EXT2_PT(I021_110_EXT2 * item, const uint8_t index, uint8_t value) {    
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[TIP_BYTE(index, 9)]), value, MASK_04_BITS, 5);
}

void set_I021_110_EXT2_TD(I021_110_EXT2 * item, const uint8_t index, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[TIP_BYTE(index, 9)]), value, MASK_02_BITS, 3);
}

void set_I021_110_EXT2_TRA(I021_110_EXT2 * item, const uint8_t index, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[TIP_BYTE(index, 9)]), value, MASK_01_BITS, 2);
}

void set_I021_110_EXT2_TOA(I021_110_EXT2 * item, const uint8_t index, uint8_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[TIP_BYTE(index, 9)]), value, MASK_01_BITS, 1);
}

void set_I021_110_EXT2_TOV(I021_110_EXT2 * item, const uint8_t index, uint32_t value) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->raw[TIP_BYTE(index, 10)]), (value >> 16), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[TIP_BYTE(index, 11)]), (value >>  8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[TIP_BYTE(index, 12)]), (value      ), MASK_08_BITS, 1);
}

void set_I021_110_EXT2_TTR(I021_110_EXT2 * item, const uint8_t index, double value) {
    uint16_t ttr_raw;

    // TODO: Check value is in valid range

    ttr_raw = value / I021_110_LSB_TTR;
    SET_BITS(&(item->raw[TIP_BYTE(index, 13)]), (ttr_raw >> 8), MASK_08_BITS, 1);
    SET_BITS(&(item->raw[TIP_BYTE(index, 14)]), (ttr_raw     ), MASK_08_BITS, 1);
}


/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_110(const I021_110 * item) {
    uint8_t i, rep = 0;

    printf("Category 021 Item 110 - Trajectory Intent\n");
    printf("  TIS = %d\n", get_I021_110_TIS(item));
    printf("  TID = %d\n", get_I021_110_TID(item));
    printf("  FX = %d\n", get_I021_110_FX(item));

    if (get_I021_110_TIS(item)) {
    
        printf("  EXT1_NAV = %d\n", get_I021_110_EXT1_NAV(&item->ext1));
        printf("  EXT1_NVB = %d\n", get_I021_110_EXT1_NVB(&item->ext1));
        printf("  EXT1_FX = %d\n", get_I021_110_EXT1_FX(&item->ext1));
    }

    if (get_I021_110_TID(item)) {
    
        rep = get_I021_110_EXT2_REP(&(item->ext2));
        printf("  REP = %d\n", rep);
        for (i = 0; i < rep; i++) {
            printf("  (TIP %d) ext2_TCA = %d\n", 
                i, get_I021_110_EXT2_TCA(&(item->ext2), i));
            printf("  (TIP %d) ext2_NC = %d\n", 
                i, get_I021_110_EXT2_NC(&(item->ext2), i));
            printf("  (TIP %d) ext2_TCP_NUM = %d\n", 
                i, get_I021_110_EXT2_TCP_NUM(&(item->ext2), i));
            printf("  (TIP %d) ext2_ALT = %d\n", 
                i, get_I021_110_EXT2_ALT(&(item->ext2), i));
            printf("  (TIP %d) ext2_LAT = %f\n", 
                i, get_I021_110_EXT2_LAT(&(item->ext2), i));
            printf("  (TIP %d) ext2_LON = %f\n", 
                i, get_I021_110_EXT2_LON(&(item->ext2), i));
            printf("  (TIP %d) ext2_TYPE = %d\n", 
                i, get_I021_110_EXT2_TYPE(&(item->ext2), i));
            printf("  (TIP %d) ext2_TD = %d\n", 
                i, get_I021_110_EXT2_TD(&(item->ext2), i));
            printf("  (TIP %d) ext2_TRA = %d\n", 
                i, get_I021_110_EXT2_TRA(&(item->ext2), i));
            printf("  (TIP %d) ext2_TOA = %d\n", 
                i, get_I021_110_EXT2_TOA(&(item->ext2), i));
            printf("  (TIP %d) ext2_TOV = %d\n", 
                i, get_I021_110_EXT2_TOV(&(item->ext2), i));
            printf("  (TIP %d) ext2_TTR = %f\n", 
                i, get_I021_110_EXT2_TTR(&(item->ext2), i));
        }
    }
}