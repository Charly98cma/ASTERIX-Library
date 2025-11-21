/**
 * @file I021_130.c
 * @brief Implementation of the Category 21 Item 130 functions
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_130.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_130_LAT(const I021_130 * item)
{
    if (!item) return 0.0F;
    return read_twocomp_24bit(&item->raw[0]) * I021_130_LSB_LAT;
}

double get_I021_130_LON(const I021_130 * item)
{
    if (!item) return 0.0F;
    return read_twocomp_24bit(&item->raw[3]) * I021_130_LSB_LON;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_130_LAT(I021_130 * item, double lat)
{
    int32_t lat_raw = 0;
    if (!item) return;
    if (lat > 0.0)
        lat_raw = (int32_t) (lat / I021_130_LSB_LAT + 0.5);
    write_twocomp_24bit(&item->raw[0], lat_raw);
}

void set_I021_130_LON(I021_130 * item, double lon)
{
    int32_t lon_raw = 0;
    if (!item) return;
    if (lon > 0.0)
        lon_raw = (int32_t) (lon / I021_130_LSB_LAT + 0.5);
    write_twocomp_24bit(&item->raw[3], lon_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_130(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_130 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_130 *)item_in;
    memcpy(&msg_out[out_index], item->raw, 6);
    return out_index + 6;
}

uint16_t decode_I021_130(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_130 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_130 *)item_out;
    memcpy(item->raw, &msg_in[in_index], 6);
    return in_index + 6;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_130(const I021_130 * item)
{
    printf("I021/130 - Position in WGS-84 Co-ordinates\n");
    if (!item)
    {
        printf("I021/130: <null>\n");
        return;
    }
    printf("- LAT (degrees) = %f\n", get_I021_130_LAT(item));
    printf("- LON (degrees) = %f\n", get_I021_130_LON(item));
}
