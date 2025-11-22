/**
 * @file I034_030.c
 * @brief Implementation of I034/030 - Time of Day (TOD)
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I034/I034_030.h"

/******************************************************************************
 * Getters
 ******************************************************************************/

float get_I034_030_TOD(const I034_030 *item)
{
    uint32_t tod_raw;
    if (!item) return 0.0f;
    tod_raw = read_unsigned_24bit(item->raw);
    return tod_raw * I034_030_LSB_TOD;
}

/******************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_030_TOD(I034_030 *item, float tod_seconds)
{
    uint32_t tod_raw;
    if (!item) return;
    tod_raw = (uint32_t)(tod_seconds / I034_030_LSB_TOD + 0.5f);
    write_unsigned_24bit(item->raw, tod_raw);}

/******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I034_030(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I034_030 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I034_030 *)item_in;
    memcpy(&msg_out[out_index], item->raw, 3);
    return out_index + 3;
}

uint16_t decode_I034_030(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I034_030 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I034_030 *)item_out;
    memcpy(item->raw, &msg_in[in_index], 3);
    return in_index + 3;
}

/******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I034_030(const I034_030 *item)
{
    printf("I034/030 - Time of Day (TOD)\n");
    if (!item)
    {
        printf("I034/030: <null>\n");
        return;
    }
    printf("- TOD = %f seconds (raw=%02X%02X%02X) \n",
        get_I034_030_TOD(item),
        item->raw[0], item->raw[1], item->raw[2]);
}
