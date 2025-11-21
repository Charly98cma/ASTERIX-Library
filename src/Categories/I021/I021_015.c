/**
 * @file I021_015.c
 * @brief Implementation of the Category 21 Item 015 functions
 */

#include <stdio.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_015.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_015_SI(const I021_015 * item)
{
    if (!item) return 0;
    return read_unsigned_8bit(&item->raw);
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_015_SI(I021_015 * item, uint8_t si)
{
    if (!item) return;
    write_unsigned_8bit(&item->raw, si);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_015(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_015 * item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_015 *) item_in;
    msg_out[out_index++] = item->raw;
    return out_index;
}

uint16_t decode_I021_015(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_015 * item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_015 *) item_out;
    item->raw = msg_in[in_index++];
    return in_index;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_015(const I021_015 *item)
{
    printf("I021/015 - Service Identification\n");
    if (!item)
    {
        printf("I021/015: <null>\n");
        return;
    }
    printf("- SI: 0x%02X\n\n", get_I021_015_SI(item));
}
