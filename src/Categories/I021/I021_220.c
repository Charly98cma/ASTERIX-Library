/**
 * @file I021_220.c
 * @brief Implementation of the Category 21 Item 220 functions
 */ 

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/bitwise_funcs.h"

#include "Categories/I021/I021_220.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/ 

/* ============================== MAIN BYTE ============================== */

uint8_t get_I021_220_WS(const I021_220 * item) {
    return GET_BITS(item->raw, 8, MASK_01_BITS);
}    

uint8_t get_I021_220_WD(const I021_220 * item) {
    return GET_BITS(item->raw, 7, MASK_01_BITS);
}    

uint8_t get_I021_220_TEMP(const I021_220 * item) {
    return GET_BITS(item->raw, 6, MASK_01_BITS);
}    

uint8_t get_I021_220_TRB(const I021_220 * item) {
    return GET_BITS(item->raw, 5, MASK_01_BITS);
}    

uint8_t get_I021_220_FX(const I021_220 * item) {
    return GET_BITS(item->raw, 1, MASK_01_BITS);
}    

/* ============================== SUBFIELD #1 ============================== */

uint16_t get_I021_220_EXT1_WINDSPD(const I021_220_EXT1 * item) {
    uint16_t windspd = (uint16_t) (
        (GET_BITS(item->WINDSPD[0], 1, MASK_08_BITS) << 8) |
        (GET_BITS(item->WINDSPD[1], 1, MASK_08_BITS)     )
    );

    return windspd;
}    

/* ============================== SUBFIELD #2 ============================== */

uint16_t get_I021_220_EXT2_WINDDIR(const I021_220_EXT2 * item) {
    uint16_t winddir = (uint16_t) (
        (GET_BITS(item->WINDDIR[0], 1, MASK_08_BITS) << 8) |
        (GET_BITS(item->WINDDIR[1], 1, MASK_08_BITS)     )
    );

    return winddir;
}    

/* ============================== SUBFIELD #3 ============================== */

double get_I021_220_EXT3_TEMP(const I021_220_EXT3 * item) {
    int16_t temp_raw = (int16_t) (
        (GET_BITS(item->TEMP[0], 1, MASK_08_BITS) << 8) |
        (GET_BITS(item->TEMP[1], 1, MASK_08_BITS)     )
    );
    return (double) (temp_raw * I021_220_EXT3_LSB_TEMP);
}

/* ============================== SUBFIELD #4 ============================== */

uint8_t get_I021_220_EXT4_TURB(const I021_220_EXT4 * item) {
    return GET_BITS(item->TURB, 1, MASK_08_BITS);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================== MAIN BYTE ============================== */

void set_I021_220_WS(I021_220 * item, const uint8_t ws) {
    SET_BITS(&(item->raw), ws, 8, MASK_01_BITS);
}

void set_I021_220_WD(I021_220 * item, const uint8_t wd) {
    SET_BITS(&(item->raw), wd, 7, MASK_01_BITS);
}

void set_I021_220_TEMP(I021_220 * item, const uint8_t temp) {
    SET_BITS(&(item->raw), temp, 6, MASK_01_BITS);
}

void set_I021_220_TRB(I021_220 * item, const uint8_t trb) {
    SET_BITS(&(item->raw), trb, 5, MASK_01_BITS);
}

void set_I021_220_FX(I021_220 * item, const uint8_t fx) {
    SET_BITS(&(item->raw), fx, 1, MASK_01_BITS);
}

/* ============================== SUBFIELD #1 ============================== */

void set_I021_220_EXT1_WINDSPD(I021_220_EXT1 * item, const uint16_t wind_spd) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->WINDSPD[0]), (wind_spd >> 8), MASK_08_BITS, 1);
    SET_BITS(&(item->WINDSPD[1]), (wind_spd     ), MASK_08_BITS, 1);
}

/* ============================== SUBFIELD #2 ============================== */

void set_I021_220_EXT2_WINDDIR(I021_220_EXT2 * item, const uint16_t wind_dir) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->WINDDIR[0]), (wind_dir >> 8), MASK_08_BITS, 1);
    SET_BITS(&(item->WINDDIR[1]), (wind_dir     ), MASK_08_BITS, 1);
}

/* ============================== SUBFIELD #3 ============================== */

void set_I021_220_EXT3_TEMP(I021_220_EXT3 * item, const double temp) {
    int16_t temp_raw = 0;

    // TODO: Check value is in valid range
    if (temp > 0)
        temp_raw = (int16_t) ((temp / I021_220_EXT3_LSB_TEMP) + 0.5);

    SET_BITS(&(item->TEMP[0]), (temp_raw >> 8), MASK_08_BITS, 1);
    SET_BITS(&(item->TEMP[1]), (temp_raw     ), MASK_08_BITS, 1);
}

/* ============================== SUBFIELD #4 ============================== */

void set_I021_220_EXT4_TURB(I021_220_EXT4 * item, const uint8_t turb) {
    // TODO: Check value is in valid range
    SET_BITS(&(item->TURB), turb, MASK_16_BITS, 1);
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_220(const I021_220 * item) {
    printf("Category 021 Item 220 - Met Information\n");

    printf("  WS = %d\n", get_I021_220_WS(item));
    printf("  WD = %d\n", get_I021_220_WD(item));
    printf("  TEMP = %d\n", get_I021_220_TEMP(item));
    printf("  TRB = %d\n", get_I021_220_TRB(item));
    printf("  FX = %d\n", get_I021_220_FX(item));

    if (get_I021_220_WS(item)) {
        printf("  EXT1_WS = %d\n", get_I021_220_EXT1_WINDSPD(&(item->ext1)));
    }

    if (get_I021_220_WD(item)) {
        printf("  EXT2_WD = %d\n", get_I021_220_EXT2_WINDDIR(&(item->ext2)));
    }

    if (get_I021_220_TEMP(item)) {
        printf("  EXT3_TEMP = %f\n", get_I021_220_EXT3_TEMP(&(item->ext3)));
    }

    if (get_I021_220_TRB(item)) {
        printf("  EXT4_TRB = %d\n", get_I021_220_EXT4_TURB(&(item->ext4)));
    }
}

