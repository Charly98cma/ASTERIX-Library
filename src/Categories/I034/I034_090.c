/**
 * @file I034_090.c
 * @brief Implementation of I090/000 - System Configuration and Status
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I034/I034_090.h"

/*****************************************************************************
 * Getters
 ******************************************************************************/

float get_I034_090_RANGEERR(const I034_090 *item)
{
    if (!item) return 0.0f;
    return read_twocomp_8bit(item->raw) * I034_090_LSB_RANGEERR;
}

float get_I034_090_AZERR(const I034_090 *item)
{
    if (!item) return 0.0f;
    return read_twocomp_8bit(&item->raw[1]) * I034_090_LSB_AZERR;
}

/*****************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_090_RANGEERR(I034_090 *item, float range_error)
{
    int8_t raw_value;
    if (!item) return;
    raw_value = (int8_t)(range_error / I034_090_LSB_RANGEERR + 0.5f);
    write_twocomp_8bit(item->raw, raw_value);
}

void set_I034_090_AZERR(I034_090 *item, float az_error)
{
    int8_t raw_value;
    if (!item) return;
    raw_value = (int8_t)(az_error / I034_090_LSB_AZERR + 0.5f);
    write_twocomp_8bit(&item->raw[1], raw_value);
}

/*****************************************************************************
 * Encoding and Decoding
 ******************************************************************************/

uint16_t encode_I034_090(void *item_in, uint8_t *msg_out, uint16_t out_index)
{
    I034_090 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I034_090 *)item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I034_090(void *item_out, const uint8_t *msg_in, uint16_t in_index)
{
    I034_090 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I034_090 *)item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*****************************************************************************
 * Print
 ******************************************************************************/

void print_I034_090(const I034_090 *item)
{
    printf("I034/090 - Collimation Error:\n");
    if (!item)
    {
        printf("I034/090: <null>\n");
        return;
    }
    printf("- RANGE ERROR: %.3f NM\n", get_I034_090_RANGEERR(item));
    printf("- AZIMUTH ERROR: %.3f degrees\n", get_I034_090_AZERR(item));
}
