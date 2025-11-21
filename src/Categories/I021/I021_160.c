/**
 * @file I021_160.c
 * @brief Implementation of the Category 21 Item 160 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_160.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_160_RE(const I021_160 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

double get_I021_160_GRDSPD(const I021_160 * item)
{
    if (!item) return 0.0F;
    return (read_unsigned_16bit(&item->raw[0]) & MASK_15_BITS) * I021_160_LSB_GRDSPD;
}

double get_I021_160_TRKANG(const I021_160 * item)
{
    if (!item) return 0.0F;
    return read_unsigned_16bit(&item->raw[2]) * I021_160_LSB_TRKANG;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_160_RE(I021_160 * item, uint8_t re)
{
    if (!item) return;
    write_bits(item->raw, MASK_01_BITS, 7, re);
}

void set_I021_160_GRDSPD(I021_160 * item, double ground_speed_nmpmin)
{
    uint16_t gs_raw = 0;
    if (!item) return;
    if (ground_speed_nmpmin > 0)
        gs_raw = ((ground_speed_nmpmin / I021_160_LSB_GRDSPD) + 0.5);
    write_bits(item->raw, MASK_07_BITS, 0, gs_raw >> 8);
    write_unsigned_8bit(&item->raw[1], gs_raw & MASK_08_BITS);
}

void set_I021_160_TRKANG(I021_160 * item, double track_angle_deg)
{
    uint16_t ta_raw = 0;
    if (!item) return;
    if (track_angle_deg > 0)
        ta_raw = ((track_angle_deg / I021_160_LSB_TRKANG) + 0.5);
    write_unsigned_16bit(&item->raw[2], ta_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_160(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_160 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_160 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 4);
    return out_index + 4;
}

uint16_t decode_I021_160(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_160 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_160 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 4);
    return in_index + 4;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_160(const I021_160 * item)
{
    printf("I021/160 - Airborne Ground Vector\n");
    if (!item)
    {
        printf("I021/160 <null>\n");
        return;
    }
    printf("- RE = %d\n", get_I021_160_RE(item));
}