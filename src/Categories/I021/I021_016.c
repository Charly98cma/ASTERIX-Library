/**
 * @file I021_016.c
 * @brief Implementation of the Category 21 Item 016 functions
 */

#include <stdio.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_016.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_016_RP(const I021_016 *item)
{
    if (!item) return 0.0;
    return read_unsigned_8bit(&item->raw) * I021_016_LSB_RP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_016_RP(I021_016 *item, double rp_seconds)
{
    uint8_t raw_value = 0;
    if (!item) return;
    /* Change from seconds to raw value, rounding to nearest unit */
    if (rp_seconds > 0)
        raw_value = (rp_seconds / I021_016_LSB_RP) + 0.5;
    write_unsigned_8bit(&item->raw, raw_value);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_016(void *item_in, unsigned char *msg_out, uint16_t out_index)
{
    I021_016 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_016 *)item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_016(void *item_out, const unsigned char *msg_in, uint16_t in_index)
{
    I021_016 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_016 *)item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_016(const I021_016 *item)
{
    printf("I021/016 - Service Management\n");
    if (!item)
    {
        printf("I021/016: <null>\n");
        return;
    }
    printf("- RP (seconds): %f\n\n", get_I021_016_RP(item));
}