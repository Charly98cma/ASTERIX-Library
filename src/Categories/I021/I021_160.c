/**
 * @file I021_160.c
 * @brief Implementation of the Category 21 Item 160 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_160.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_160_RE(const I021_160 * item) {
    return (item->raw[0] >> 7) & MASK_01_BITS;
}

double get_I021_160_GRDSPD(const I021_160 * item) {
    int16_t gs_raw = ((item->raw[0] & MASK_07_BITS) << 8) | item->raw[1];
    return gs_raw * I021_160_LSB_GRDSPD;
}

double get_I021_160_TRKANG(const I021_160 * item) {
    uint16_t ta_raw = ((item->raw[2]) << 8) | item->raw[3];
    return ta_raw * I021_160_LSB_TRKANG;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_160_RE(I021_160 * item, uint8_t re) {
    item->raw[0] |= (re >> 7) & MASK_01_BITS;
}

void set_I021_160_GRDSPD(I021_160 * item, double ground_speed_nmpmin) {
    uint16_t gs_raw = 0;

    /* TODO: Check ground_speed value in range */
    if (ground_speed_nmpmin > 0)
        gs_raw = ((ground_speed_nmpmin / I021_160_LSB_GRDSPD) + 0.5);

    item->raw[0] = gs_raw >> 8;
    item->raw[1] = gs_raw;
}

void set_I021_160_TRKANG(I021_160 * item, double track_angle_deg) {
    uint16_t ta_raw = 0;

    /* TODO: Check track_angle value in range */
    if (track_angle_deg > 0)
        ta_raw = ((track_angle_deg / I021_160_LSB_TRKANG) + 0.5);

    item->raw[2] = ta_raw >> 8;
    item->raw[3] = ta_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_160(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_160 * item = (I021_160 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    msg_out[out_index++] = item->raw[3];
    return out_index;
}

uint16_t decode_I021_160(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_160 * item = (I021_160 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    item->raw[3] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_160(const I021_160 * item) {
    printf("Category 021 Item 160 - Airborne Ground Vector\n");
    printf("  RE = %d\n", get_I021_160_RE(item));
}