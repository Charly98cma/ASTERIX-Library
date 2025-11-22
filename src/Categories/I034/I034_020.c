/**
 * @file I034_020.c
 * @brief Implementation of I034/020 - Sector Number
 */

#include <stdio.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I034/I034_020.h"

/******************************************************************************
 * Getters
 ******************************************************************************/

float get_I034_020_SECTORNUM(const I034_020 *item)
{
    if (!item) return 0.0f;
    return read_unsigned_8bit(&item->raw) * I034_020_LSB_SECTORNUM;
}

/******************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_020_SECTORNUM(I034_020 *item, float sector_az)
{
    uint8_t sector_raw = 0;
    if (!item) return;
    sector_raw = (uint8_t)(sector_az / I034_020_LSB_SECTORNUM + 0.5f);
    write_unsigned_8bit(&item->raw, sector_raw);
}

/******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I034_020(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I034_020 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I034_020 *)item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I034_020(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I034_020 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I034_020 *)item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I034_020(const I034_020 *item)
{
    printf("I034/020 - Sector Number\n");
    if (!item)
    {
        printf("I034/020: <null>\n");
        return;
    }
    printf("- SECTORNUM = %.4f deg (raw = 0x%02X)\n",
           get_I034_020_SECTORNUM(item), item->raw);
}
