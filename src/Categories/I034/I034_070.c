/**
 * @file I034_070.c
 * @brief Implementation of I034/070 - System Configuration and Status
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"
#include "Common/constants.h"

#include "Categories/I034/I034_070.h"

/*****************************************************************************
 * Getters
 ******************************************************************************/

#define TIP_BYTE(index, offset) (1 + ((index) * I034_070_N_OCTETS) + (offset))

uint8_t get_I034_070_REP(const I034_070 *item)
{
    if (!item) return 0;
    return read_unsigned_8bit(item->raw);
}

uint8_t get_I034_070_TYP(const I034_070 *item, uint8_t counter_index)
{
    if (!item) return 0;
    return read_bits(&item->raw[TIP_BYTE(counter_index, 0)], MASK_05_BITS, 3);
}

uint16_t get_I034_070_COUNTER(const I034_070 *item, uint8_t counter_index)
{
    uint16_t counter_value;
    if (!item) return 0;
    counter_value  = (item->raw[TIP_BYTE(counter_index, 0)] & MASK_03_BITS) << 8;
    counter_value |= item->raw[TIP_BYTE(counter_index, 1)];
    return counter_value;
}

/*****************************************************************************
 * Setters
 ******************************************************************************/

void set_I034_070_REP(I034_070 *item, uint8_t rep)
{
    if (!item) return;
    write_unsigned_8bit(item->raw, rep);
}

void set_I034_070_TYP(I034_070 *item, uint8_t counter_index, uint8_t typ)
{
    uint8_t index;
    if (!item) return;
    index = TIP_BYTE(counter_index, 0);
    item->raw[index] &= ~((MASK_05_BITS) << 3);
    item->raw[index] |= (typ & MASK_05_BITS) << 3;
}

void set_I034_070_COUNTER(I034_070 *item, uint8_t counter_index, uint16_t counter_value)
{
    uint8_t index;
    if (!item) return;
    index = TIP_BYTE(counter_index, 0);
    item->raw[index] &= ~MASK_03_BITS;
    item->raw[index] |= (counter_value >> 8) & MASK_03_BITS;
    item->raw[index+1] = counter_value & MASK_08_BITS;
}

/*****************************************************************************
 * Encoding and Decoding
 ******************************************************************************/

uint16_t encode_I034_070(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    uint8_t i, rep;
    I034_070 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I034_070 *)item_in;
    rep = get_I034_070_REP(item);
    msg_out[out_index++] = item->raw[0];
    for (i = 0; i < rep; i++)
{
        memcpy(&msg_out[out_index], &item->raw[TIP_BYTE(i, 0)], I034_070_N_OCTETS);
        out_index += I034_070_N_OCTETS;
    }
    return out_index;
}

uint16_t decode_I034_070(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    uint8_t i, rep;
    I034_070 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I034_070 *)item_out;
    item->raw[0] = msg_in[in_index++];
    rep = get_I034_070_REP(item);
    for (i = 0; i < rep; i++)
{
        memcpy(&item->raw[TIP_BYTE(i, 0)], &msg_in[in_index], I034_070_N_OCTETS);
        in_index += I034_070_N_OCTETS;
    }
    return in_index;
}

/*****************************************************************************
 * Print
 ******************************************************************************/

void print_I034_070(const I034_070 *item)
{
    uint8_t i, rep;
    printf("I034/070 - Message Count Values\n");
    if (!item)
    {
        printf("I034/070: <null>\n");
        return;
    }

    rep = get_I034_070_REP(item);
    printf("- REP = %u\n", rep);
    for (i = 0; i < rep; i++)
{
        printf("-- COUNTER[%d] : TYP = %u | COUNTER = %u\n",
               i + 1,
               get_I034_070_TYP(item, i),
               get_I034_070_COUNTER(item, i));
    }
}