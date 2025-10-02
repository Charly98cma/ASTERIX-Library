/**
 * @file I021_150.c
 * @brief Implementation of the Category 21 Item 150 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_150.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_150_IM(const I021_150 * item) {
    return (item->raw[0] >> 7) & MASK_01_BITS;
}

double get_I021_150_AIRSPD(const I021_150 * item) {
    double air_speed = 0;
    uint16_t air_speed_raw = ((item->raw[0] & MASK_07_BITS) << 8) | item->raw[1];

    if (get_I021_150_IM(item) == I021_150_IM_IAS)
        air_speed = air_speed_raw * I021_150_LSB_IAS;
    else
        air_speed = air_speed_raw * I021_150_LSB_MACH;

    return air_speed;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_150_IM(I021_150 * item, uint8_t im) {
    item->raw[0] |= (im & MASK_01_BITS) << 7;
}

void set_I021_150_AIRSPD(I021_150 * item, double airspd) {
    uint16_t airspd_raw = 0;

    if (get_I021_150_IM(item) == I021_150_IM_IAS)
        airspd_raw = airspd / I021_150_LSB_IAS;
    else
        airspd_raw = airspd / I021_150_LSB_MACH;

    item->raw[0] |= (airspd_raw >> 8) & MASK_07_BITS;
    item->raw[1] = airspd_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_150(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_150 * item = (I021_150 *) item_in;
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    return out_index;
}

uint16_t decode_I021_150(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_150 * item = (I021_150 *) item_out;
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_150(const I021_150 * item) {
    uint8_t im = get_I021_150_IM(item);

    printf("Category 021 Item 150 - Air Speed\n");
    printf("  IM = %d\n", im);
    if (im == I021_150_IM_IAS)
        printf("  IAS = %f\n", get_I021_150_AIRSPD(item));
    else
        printf("  MACH = %f\n", get_I021_150_AIRSPD(item));
}