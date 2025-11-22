/**
 * @file I034_041.c
 * @brief Implementation of I034/041 - Antenna Rotation Speed
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I034/I034_041.h"

/******************************************************************************
 * Getters
 ******************************************************************************/

float get_I034_041_ANTROTSPD(const I034_041 *item)
{
    if (!item) return 0.0f;
    return read_unsigned_16bit(item->raw) * I034_041_LSB_ANTROTSPD;
}

/******************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_041_ANTROTSPD(I034_041 *item, float antrotspd_seconds)
{
    uint16_t androtspd_raw;
    if (!item) return;
    androtspd_raw = (uint16_t)(antrotspd_seconds / I034_041_LSB_ANTROTSPD + 0.5f);
    write_unsigned_16bit(item->raw, androtspd_raw);
}

/******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I034_041(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I034_041 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I034_041 *)item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I034_041(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I034_041 *item = (I034_041 *)item_out;
    if (!item_out || !msg_in) return in_index;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I034_041(const I034_041 *item)
{
    printf("I034/041 - Antenna Rotation Speed\n");
    if (!item)
    {
        printf("I034/041: <null>\n");
        return;
    }
    printf("- ANTROTSPD = %f seconds (raw = %02X%02X)\n",
        get_I034_041_ANTROTSPD(item),
        item->raw[0], item->raw[1]);
}
