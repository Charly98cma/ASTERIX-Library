/**
 * @file I034_120.c
 * @brief Implementation of I034/120 - 3D-Position of Data Source
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I034/I034_120.h"

/******************************************************************************
 * Getters
 ******************************************************************************/

int16_t get_I034_120_HEIGHT(const I034_120 *item)
{
    if (!item) return 0;
    return read_signmag_16bit(item->raw);
}

float get_I034_120_LATWGS84(const I034_120 *item)
{
    if (!item) return 0.0f;
    return read_twocomp_24bit(&item->raw[2]) *I034_120_LSB_LATWGS84;
}

float get_I034_120_LONWGS84(const I034_120 *item)
{
    if (!item) return 0.0f;
    return read_twocomp_24bit(&item->raw[5]) * I034_120_LSB_LONWGS84;
}

/******************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_120_HEIGHT(I034_120 *item, int16_t height)
{
    if (!item) return;
    write_signmag_24bit(item->raw, height);
}

void set_I034_120_LATWGS84(I034_120 *item, float lat_wgs84)
{
    uint32_t lat_raw = 0;
    if (!item) return;
    lat_raw = (lat_wgs84 / I034_120_LSB_LATWGS84 + 0.5f);
    write_twocomp_24bit(&item->raw[2], lat_raw);
}

void set_I034_120_LONWGS84(I034_120 *item, float lon_wgs84)
{
    uint32_t lon_raw = 0;
    if (!item) return;
    lon_raw = (lon_wgs84 / I034_120_LSB_LONWGS84 + 0.5f);
    write_twocomp_24bit(&item->raw[5], lon_raw);
}

/******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I034_120(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I034_120 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I034_120 *)item_in;
    memcpy(&msg_out[out_index], item->raw, 8);
    return out_index + 8;
}

uint16_t decode_I034_120(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I034_120 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I034_120 *)item_out;
    memcpy(item->raw, &msg_in[in_index], 8);
    return in_index + 8;
}

/******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I034_120(const I034_120 *item)
{
    printf("I034/120 - 3D-Position of Data Source\n");
    if (!item)
    {
        printf("I034/120: <null>\n");
        return;
    }
    printf("- HEIGHT WGS84 = %d\n", get_I034_120_HEIGHT(item));
    printf("- LATITUDE WGS84 = %f\n", get_I034_120_LATWGS84(item));
    printf("- LONGITUDE WGS84 = %f\n", get_I034_120_LONWGS84(item));
}
