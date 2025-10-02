/**
 * @file I021_110.c
 * @brief Implementation of the Category 21 Item 110 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_110.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* =============================== MAIN BYTE =============================== */

uint8_t get_I021_110_TIS(const I021_110 * item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_110_TID(const I021_110 * item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_110_FX(const I021_110 * item) {
    return item->raw & MASK_01_BITS;
}


/* ============================= FIRST EXTENSION ============================ */

uint8_t get_I021_110_EXT1_NAV(const I021_110_EXT1 * item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_110_EXT1_NVB(const I021_110_EXT1 * item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_110_EXT1_FX(const I021_110_EXT1 * item) {
    return item->raw & MASK_01_BITS;
}


/* ============================ SECOND EXTENSION ============================ */

#define TIP_BYTE(index, offset) (1 + ((index) * NUM_BYTES_I021_110_EXT2) + (offset))

uint8_t get_I021_110_EXT2_REP(const I021_110_EXT2 * item) {
    return item->raw[0];
}

uint8_t get_I021_110_EXT2_TCA(const I021_110_EXT2 * item, uint8_t index) {
    return (item->raw[TIP_BYTE(index, 0)] >> 7) & MASK_01_BITS;
}

uint8_t get_I021_110_EXT2_NC(const I021_110_EXT2 * item, uint8_t index) {
    return (item->raw[TIP_BYTE(index, 0)] >> 6) & MASK_01_BITS;
}

uint8_t get_I021_110_EXT2_TCP_NUM(const I021_110_EXT2 * item, uint8_t index) {
    return item->raw[TIP_BYTE(index, 0)] & MASK_06_BITS;
}

int32_t get_I021_110_EXT2_ALT(const I021_110_EXT2 * item, uint8_t index) {
    int32_t alt_raw = (
        (item->raw[TIP_BYTE(index, 1)] << 8) |
        (item->raw[TIP_BYTE(index, 2)]     ));
    return alt_raw * I021_110_LSB_ALT; 
}

double get_I021_110_EXT2_LAT(const I021_110_EXT2 * item, uint8_t index) {
    int32_t lat_raw = (
        (item->raw[TIP_BYTE(index, 3)] << 16) |
        (item->raw[TIP_BYTE(index, 4)] <<  8) |
        (item->raw[TIP_BYTE(index, 5)]      ));
    return lat_raw * I021_110_LSB_LAT;
}

double get_I021_110_EXT2_LON(const I021_110_EXT2 * item, uint8_t index) {
    int32_t lon_raw = (
        (item->raw[TIP_BYTE(index, 6)] << 16) |
        (item->raw[TIP_BYTE(index, 7)] <<  8) |
        (item->raw[TIP_BYTE(index, 8)]      ));
    return lon_raw * I021_110_LSB_LON;
}

uint8_t get_I021_110_EXT2_TYPE(const I021_110_EXT2 * item, uint8_t index) {
    return (item->raw[TIP_BYTE(index, 9)] >> 4) & MASK_04_BITS;
}

uint8_t get_I021_110_EXT2_TD(const I021_110_EXT2 * item, uint8_t index) {
    return (item->raw[TIP_BYTE(index, 9)] >> 2) & MASK_02_BITS;
}

uint8_t get_I021_110_EXT2_TRA(const I021_110_EXT2 * item, uint8_t index) {
    return (item->raw[TIP_BYTE(index, 9)] >> 1) & MASK_01_BITS;
}

uint8_t get_I021_110_EXT2_TOA(const I021_110_EXT2 * item, uint8_t index) {
    return item->raw[TIP_BYTE(index, 9)] & MASK_01_BITS;
}

uint32_t get_I021_110_EXT2_TOV(const I021_110_EXT2 * item, uint8_t index) {
    uint32_t tov_raw = (
        (item->raw[TIP_BYTE(index, 10)] << 16) |
        (item->raw[TIP_BYTE(index, 11)] <<  8) |
        (item->raw[TIP_BYTE(index, 12)]      ));
    return tov_raw * I021_110_LSB_TOV;
}

double get_I021_110_EXT2_TTR(const I021_110_EXT2 * item, uint8_t index) {
    uint16_t ttr_raw = (
        (item->raw[TIP_BYTE(index, 13)] << 8) |
        (item->raw[TIP_BYTE(index, 14)]     ));
    return ttr_raw * I021_110_LSB_TTR;
}


/*******************************************************************************
* Setters
******************************************************************************/

/* =============================== MAIN BYTE =============================== */

void set_I021_110_TIS(I021_110 * item, uint8_t tis) {
    /* TODO: Check value is in valid range */
    item->raw |= (tis & MASK_01_BITS) << 7;
}

void set_I021_110_TID(I021_110 * item, uint8_t tid) {
    /* TODO: Check value is in valid range */
    item->raw |= (tid & MASK_01_BITS) << 6;
}

void set_I021_110_FX(I021_110 * item, uint8_t fx) {
    /* TODO: Check value is in valid range */
    item->raw |= fx & MASK_01_BITS;
}


/* ============================= FIRST EXTENSION ============================ */

void set_I021_110_EXT1_NAV(I021_110_EXT1 * item, uint8_t nav) {
    /* TODO: Check value is in valid range */
    item->raw |= (nav & MASK_01_BITS) << 7;
}

void set_I021_110_EXT1_NVB(I021_110_EXT1 * item, uint8_t nvb) {
    /* TODO: Check value is in valid range */
    item->raw |= (nvb & MASK_01_BITS) << 6;
}

void set_I021_110_EXT1_FX(I021_110_EXT1 * item, uint8_t fx) {
    /* TODO: Check value is in valid range */
    item->raw |= fx & MASK_01_BITS;
}


/* ============================ SECOND EXTENSION ============================ */

void set_I021_110_EXT2_REP(I021_110_EXT2 * item, uint8_t rep) {
    /* TODO: Check value is in valid range */
    item->raw[0] |= rep & MASK_08_BITS;
}

void set_I021_110_EXT2_TCA(I021_110_EXT2 * item, uint8_t index, uint8_t tca) {
    /* TODO: Check value is in valid range */
    item->raw[TIP_BYTE(index, 0)] |= (tca & MASK_01_BITS) << 7;
}

void set_I021_110_EXT2_NC(I021_110_EXT2 * item, uint8_t index, uint8_t nc) {
    /* TODO: Check value is in valid range */
    item->raw[TIP_BYTE(index, 0)] |= (nc & MASK_01_BITS) << 6;
}

void set_I021_110_EXT2_TCP_NUM(I021_110_EXT2 * item, uint8_t index, uint8_t num) {
    /* TODO: Check value is in valid range */
    item->raw[TIP_BYTE(index, 0)] |= num & MASK_06_BITS;
}

void set_I021_110_EXT2_ALT(I021_110_EXT2 * item, uint8_t index, double alt) {
    uint16_t alt_raw;

    /* TODO: Check value is in valid range */

    alt_raw = alt / I021_110_LSB_ALT;
    item->raw[TIP_BYTE(index, 1)] = alt_raw >> 8;
    item->raw[TIP_BYTE(index, 2)] =alt_raw;
}

void set_I021_110_EXT2_LAT(I021_110_EXT2 * item, uint8_t index, uint32_t lat) {
    int16_t lat_raw;

    /* TODO: Check value is in valid range */

    lat_raw = (lat / I021_110_LSB_LAT) + 0.5;
    item->raw[TIP_BYTE(index, 3)] = (lat_raw >> 16);
    item->raw[TIP_BYTE(index, 4)] = (lat_raw >>  8);
    item->raw[TIP_BYTE(index, 5)] =lat_raw;
}

void set_I021_110_EXT2_LON(I021_110_EXT2 * item, uint8_t index, uint32_t lon) {
    int16_t lon_raw;

    /* TODO: Check value is in valid range */

    lon_raw = lon / I021_110_LSB_LON;
    item->raw[TIP_BYTE(index, 6)] = (lon_raw >> 16);
    item->raw[TIP_BYTE(index, 7)] = (lon_raw >>  8);
    item->raw[TIP_BYTE(index, 8)] =lon_raw;
}

void set_I021_110_EXT2_PT(I021_110_EXT2 * item, uint8_t index, uint8_t pt) {    
    /* TODO: Check value is in valid range */
    item->raw[TIP_BYTE(index, 9)] |= (pt & MASK_04_BITS) << 4;
}

void set_I021_110_EXT2_TD(I021_110_EXT2 * item, uint8_t index, uint8_t td) {
    /* TODO: Check value is in valid range */
    item->raw[TIP_BYTE(index, 9)] |= (td & MASK_02_BITS) << 2;
}

void set_I021_110_EXT2_TRA(I021_110_EXT2 * item, uint8_t index, uint8_t tra) {
    /* TODO: Check value is in valid range */
    item->raw[TIP_BYTE(index, 9)] |= (tra & MASK_01_BITS) << 1;
}

void set_I021_110_EXT2_TOA(I021_110_EXT2 * item, uint8_t index, uint8_t toa) {
    /* TODO: Check value is in valid range */
    item->raw[TIP_BYTE(index, 9)] |= toa & MASK_01_BITS;
}

void set_I021_110_EXT2_TOV(I021_110_EXT2 * item, uint8_t index, uint32_t tov) {
    /* TODO: Check value is in valid range */
    item->raw[TIP_BYTE(index, 10)] = (tov >> 16);
    item->raw[TIP_BYTE(index, 11)] = (tov >>  8);
    item->raw[TIP_BYTE(index, 12)] =tov;
}

void set_I021_110_EXT2_TTR(I021_110_EXT2 * item, uint8_t index, double ttr) {
    uint16_t ttr_raw;

    /* TODO: Check value is in valid range */

    ttr_raw = ttr / I021_110_LSB_TTR;
    item->raw[TIP_BYTE(index, 13)] = ttr_raw >> 8;
    item->raw[TIP_BYTE(index, 14)] =ttr_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_110(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    uint16_t i, j, rep;
    I021_110 * item = (I021_110 *) item_in;
    
    msg_out[out_index++] = item->raw;
    if (get_I021_110_TIS(item))
        msg_out[out_index++] = item->ext1.raw;
    if (get_I021_110_TID(item)) {
        rep = item->ext2.REP;
        msg_out[out_index++] = rep;
        for (i = 0; i < rep; i++) {
            for (j = 0; j < NUM_BYTES_I021_110_EXT2; j++) {
                msg_out[out_index++] = item->ext2.raw[TIP_BYTE(i, j)];
            }
        }
    }

    return out_index;
}

uint16_t decode_I021_110(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    uint16_t i, j, rep;
    I021_110 * item = (I021_110 *) item_out;

    item->raw = msg_in[in_index++];
    if (get_I021_110_TIS(item))
        item->ext1.raw = msg_in[in_index++];
    if (get_I021_110_TID(item)) {
        rep = msg_in[in_index++];
        item->ext2.REP = rep;
        for (i = 0; i < rep; i++) {
            for (j = 0; j < NUM_BYTES_I021_110_EXT2; j++) {
                item->ext2.raw[TIP_BYTE(i, j)] = msg_in[in_index++];
            }
        }
    }

    return in_index;
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