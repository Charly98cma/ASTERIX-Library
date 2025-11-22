/**
 * @file I034_110.c
 * @brief Implementation of I034/110 - Message Type
 */

#include <stdio.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I034/I034_110.h"

/******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I034_110_TYP(const I034_110 *item)
{
    if (!item) return 0;
    return read_unsigned_8bit(&item->raw);
}

/******************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_110_TYP(I034_110 *item, uint8_t typ)
{
    if (!item) return;
    write_unsigned_8bit(&item->raw, typ);
}

/******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I034_110(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I034_110 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I034_110 *)item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I034_110(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I034_110 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I034_110 *)item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I034_110(const I034_110 *item)
{
    printf("I034/110 - Data Filter\n");
    if (!item)
    {
        printf("I034/110: <NULL POINTER>\n");
        return;
    }

    printf("- Data Filter Type (TYP): %u\n", get_I034_110_TYP(item));
}