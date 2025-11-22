/**
 * @file I034_000.c
 * @brief Implementation of I034/000 - Message Type
 */

#include <stdio.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I034/I034_000.h"

/******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I034_000_MSGTYPE(const I034_000 *item)
{
    if (!item) return 0;
    return read_unsigned_8bit(&item->raw);
}

/******************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_000_MSGTYPE(I034_000 *item, uint8_t msg_type)
{
    if (!item) return;
    write_unsigned_8bit(&item->raw, msg_type);
}

/******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I034_000(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I034_000 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I034_000 *)item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I034_000(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I034_000 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I034_000 *)item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I034_000(const I034_000 *item)
{
    printf("I034/000 - Message Type\n");
    if (!item)
    {
        printf("I034/000: <null>\n");
        return;
    }
    printf("- MSGTYPE = %u\n", get_I034_000_MSGTYPE(item));
}