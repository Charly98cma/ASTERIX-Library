/**
 * @file I021_220.c
 * @brief Implementation of the Category 21 Item 220 functions
 */ 

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_220.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/ 

/* ============================== MAIN BYTE ============================== */

uint8_t get_I021_220_WS(const I021_220 * item) {
    return (item->raw >> 7) & MASK_01_BITS;
}

uint8_t get_I021_220_WD(const I021_220 * item) {
    return (item->raw >> 6) & MASK_01_BITS;
}

uint8_t get_I021_220_TEMP(const I021_220 * item) {
    return (item->raw >> 5) & MASK_01_BITS;
}

uint8_t get_I021_220_TRB(const I021_220 * item) {
    return (item->raw >> 4) & MASK_01_BITS;
}

uint8_t get_I021_220_FX(const I021_220 * item) {
    return item->raw & MASK_01_BITS;
}

/* ============================== SUBFIELD #1 ============================== */

uint16_t get_I021_220_EXT1_WS(const I021_220_EXT1 * item) {
    return (item->WS[0] << 8) | item->WS[1];
}

/* ============================== SUBFIELD #2 ============================== */

uint16_t get_I021_220_EXT2_WD(const I021_220_EXT2 * item) {
    return (item->WD[0] << 8) | item->WD[1];
}

/* ============================== SUBFIELD #3 ============================== */

double get_I021_220_EXT3_TEMP(const I021_220_EXT3 * item) {
    return ((item->TEMP[0] << 8) | item->TEMP[1]) * I021_220_EXT3_LSB_TEMP;
}

/* ============================== SUBFIELD #4 ============================== */

uint8_t get_I021_220_EXT4_TRB(const I021_220_EXT4 * item) {
    return item->TRB;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

/* ============================== MAIN BYTE ============================== */

void set_I021_220_WS(I021_220 * item, uint8_t ws) {
    item->raw |= (ws & MASK_01_BITS) << 7;
}

void set_I021_220_WD(I021_220 * item, uint8_t wd) {
    item->raw |= (wd & MASK_01_BITS) << 6;
}

void set_I021_220_TEMP(I021_220 * item, uint8_t temp) {
    item->raw |= (temp & MASK_01_BITS) << 5;
}

void set_I021_220_TRB(I021_220 * item, uint8_t trb) {
    item->raw |= (trb & MASK_01_BITS) << 4;
}

void set_I021_220_FX(I021_220 * item, uint8_t fx) {
    item->raw |= fx & MASK_01_BITS;
}

/* ============================== SUBFIELD #1 ============================== */

void set_I021_220_EXT1_WS(I021_220_EXT1 * item, uint16_t wind_spd) {
    /* TODO: Check value is in valid range */
    item->WS[0] = wind_spd >> 8;
    item->WS[1] = wind_spd;
}

/* ============================== SUBFIELD #2 ============================== */

void set_I021_220_EXT2_WD(I021_220_EXT2 * item, uint16_t wind_dir) {
    /* TODO: Check value is in valid range */
    item->WD[0] = wind_dir >> 8;
    item->WD[1] = wind_dir;
}

/* ============================== SUBFIELD #3 ============================== */

void set_I021_220_EXT3_TEMP(I021_220_EXT3 * item, double temp_celsius) {
    int16_t temp_raw = 0;

    /* TODO: Check value is in valid range */
    if (temp_celsius > 0)
        temp_raw = (int16_t) ((temp_celsius / I021_220_EXT3_LSB_TEMP) + 0.5);

    item->TEMP[0] = temp_raw >> 8;
    item->TEMP[1] = temp_raw;
}

/* ============================== SUBFIELD #4 ============================== */

void set_I021_220_EXT4_TRB(I021_220_EXT4 * item, uint8_t trb) {
    /* TODO: Check value is in valid range */
    item->TRB = trb;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_220(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_220 * item = (I021_220 *) item_in;
    msg_out[out_index++] = item->raw;
    if (get_I021_220_WS(item)) {
        msg_out[out_index++] = item->ext1.WS[0];
        msg_out[out_index++] = item->ext1.WS[1];
        if (get_I021_220_WD(item)) {
            msg_out[out_index++] = item->ext2.WD[0];
            msg_out[out_index++] = item->ext2.WD[1];
            if (get_I021_220_TEMP(item)) {
                msg_out[out_index++] = item->ext3.TEMP[0];
                msg_out[out_index++] = item->ext3.TEMP[1];
                if (get_I021_220_TRB(item)) {
                    msg_out[out_index++] = item->ext4.TRB;
                }
            }
        }
    }
    return out_index;
}

uint16_t decode_I021_220(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_220 * item = (I021_220 *) item_out;
    item->raw = msg_in[in_index++];
    if (get_I021_220_WS(item)) {
        item->ext1.WS[0] = msg_in[in_index++];
        item->ext1.WS[1] = msg_in[in_index++];
        if (get_I021_220_WD(item)) {
            item->ext2.WD[0] = msg_in[in_index++];
            item->ext2.WD[1] = msg_in[in_index++];
            if (get_I021_220_TEMP(item)) {
                item->ext3.TEMP[0] = msg_in[in_index++];
                item->ext3.TEMP[1] = msg_in[in_index++];
                if (get_I021_220_TRB(item)) {
                    item->ext4.TRB = msg_in[in_index++];
                }
            }
        }
    }
    return in_index;
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

    if (get_I021_220_WS(item))
        printf("  EXT1_WS = %d\n", get_I021_220_EXT1_WS(&(item->ext1)));
    if (get_I021_220_WD(item))
        printf("  EXT2_WD = %d\n", get_I021_220_EXT2_WD(&(item->ext2)));
    if (get_I021_220_TEMP(item))
        printf("  EXT3_TEMP = %f\n", get_I021_220_EXT3_TEMP(&(item->ext3)));
    if (get_I021_220_TRB(item))
        printf("  EXT4_TRB = %d\n", get_I021_220_EXT4_TRB(&(item->ext4)));
}

