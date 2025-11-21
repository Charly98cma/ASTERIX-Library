/**
 * @file I021_161.c
 * @brief Implementation of the Category 21 Item 161 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_161.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint16_t get_I021_161_TRKNUM(const I021_161 * item)
{
    if (!item) return 0;
    return read_unsigned_16bit(item->raw) & MASK_12_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_161_TRKNUM(I021_161 * item, uint16_t track_number)
{
    if (!item) return;
    write_unsigned_16bit(item->raw, track_number & MASK_12_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_161(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_161 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_161 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_161(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_161 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_161 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_161(const I021_161 * item)
{
    printf("I021/161 - Track Number\n");
    if (!item)
    {
        printf("I021/161 <null>\n");
        return;
    }
    printf("- TRACK NUMBER = %d\n", get_I021_161_TRKNUM(item));
}