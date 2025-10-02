/**
 * @file I021_131.c
 * @brief Implementation of the Category 21 Item 131 functions
 */

#include <stdio.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_131.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_131_LAT(const I021_131 * item) {
    uint32_t lat_raw = ((item->raw[0] << 24) |
                        (item->raw[1] << 16) |
                        (item->raw[2] <<  8) |
                        (item->raw[3]      ));
    return lat_raw * I021_131_LSB_LAT;
}

double get_I021_131_LON(const I021_131 * item) {
    uint32_t lon_raw = ((item->raw[4] << 24) |
                        (item->raw[5] << 16) |
                        (item->raw[6] <<  8) |
                        (item->raw[7]      ));
    return lon_raw * I021_131_LSB_LON;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_131_LAT(I021_131 * item, double lat) {
    int32_t lat_raw = 0;

    /* TODO: Check valus is within range */
    /* if (!IN_RANGE(-90.0, lon, 90.0)) return; */

    /* Change from degrees to raw value, rounding to nearest unit */
    if (lat > 0.0)
        lat_raw = (int32_t) ((lat / I021_131_LSB_LAT) + 0.5);

    item->raw[0] = (lat_raw >> 24);
    item->raw[1] = (lat_raw >> 16);
    item->raw[2] = (lat_raw >>  8);
    item->raw[3] = lat_raw;
}

void set_I021_131_LON(I021_131 * item, double lon) {
    int32_t lon_raw = 0;

    /* TODO: Check valus is within range */
    /* if (!IN_RANGE(-180.0, lon, 180.0)) return; */

    /* Change from degrees to raw value, rounding to nearest unit */
    if (lon > 0.0)
        lon_raw = (int32_t) (lon / I021_131_LSB_LAT + 0.5);

    item->raw[4] = (lon_raw >> 24);
    item->raw[5] = (lon_raw >> 16);
    item->raw[6] = (lon_raw >>  8);
    item->raw[7] = lon_raw;
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_131(void * item_in, unsigned char * msg_out, uint16_t out_index) {
    I021_131 * item = (I021_131 *) item_in;
    /* LAT */
    msg_out[out_index++] = item->raw[0];
    msg_out[out_index++] = item->raw[1];
    msg_out[out_index++] = item->raw[2];
    msg_out[out_index++] = item->raw[3];
    /* LON */
    msg_out[out_index++] = item->raw[4];
    msg_out[out_index++] = item->raw[5];
    msg_out[out_index++] = item->raw[6];
    msg_out[out_index++] = item->raw[7];
    return out_index;
}

uint16_t decode_I021_131(void * item_out, const unsigned char * msg_in, uint16_t in_index) {
    I021_131 * item = (I021_131 *) item_out;
    /* LAT */
    item->raw[0] = msg_in[in_index++];
    item->raw[1] = msg_in[in_index++];
    item->raw[2] = msg_in[in_index++];
    item->raw[3] = msg_in[in_index++];
    /* LON */
    item->raw[4] = msg_in[in_index++];
    item->raw[5] = msg_in[in_index++];
    item->raw[6] = msg_in[in_index++];
    item->raw[7] = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_131(const I021_131 * item) {
    printf("Category 021 Item 131 - Position in WGS-84 Co-ordinates High-precision\n");
    printf("  LAT (degrees) = %f\n", get_I021_131_LAT(item));
    printf("  LON (degrees) = %f\n", get_I021_131_LON(item));
}
