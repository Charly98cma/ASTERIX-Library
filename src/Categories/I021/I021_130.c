/**
 * @file I021_130.c
 * @brief Implementation of the Category 21 Item 130 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_130.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

/* TODO: DOING... */

double get_I021_130_LAT(const I021_130 * item) {
    int32_t lat_raw = ((item->raw[0] << 16) |
                       (item->raw[1] <<  8) |
                       (item->raw[2]      ));
    return lat_raw * I021_130_LSB_LAT;
}

double get_I021_130_LON(const I021_130 * item) {
    int32_t lon_raw = ((item->raw[3] << 16) |
                       (item->raw[4] <<  8) |
                       (item->raw[5]      ));
    return lon_raw * I021_130_LSB_LON;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_130_LAT(I021_130 * item, double lat) {
    int32_t lat_raw = 0;

    /* TODO: Check valus is within range */

    /* Change from degrees to raw value, rounding to nearest unit */
    if (lat > 0.0)
        lat_raw = (int32_t) (lat / I021_130_LSB_LAT + 0.5);

    item->raw[0] = (lat_raw >> 16);
    item->raw[1] = (lat_raw >>  8);
    item->raw[2] = lat_raw;
}

void set_I021_130_LON(I021_130 * item, double lon) {
    int32_t lon_raw = 0;

    /* TODO: Check valus is within range */

    /* Change from degrees to raw value, rounding to nearest unit */
    if (lon > 0.0)
        lon_raw = (int32_t) (lon / I021_130_LSB_LAT + 0.5);

    item->raw[3] = (lon_raw >> 16);
    item->raw[4] = (lon_raw >>  8);
    item->raw[5] = lon_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_130(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_130 * item = (I021_130 *) item_in;
    /* LAT */
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    /* LON */
    msg_out[out_index++] = item->raw[3];
    msg_out[out_index++] = item->raw[4];
    msg_out[out_index++] = item->raw[5];
    return out_index;
}

uint16_t decode_I021_130(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_130 * item = (I021_130 *) item_out;
    /* LAT */
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    /* LON */
    item->raw[3] = msg_in[in_index++];
    item->raw[4] = msg_in[in_index++];
    item->raw[5] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_130(const I021_130 * item) {
    printf("Category 021 Item 130 - Position in WGS-84 Co-ordinates\n");
    printf("  LAT (degrees) = %f\n", get_I021_130_LAT(item));
    printf("  LON (degrees) = %f\n", get_I021_130_LON(item));
}
