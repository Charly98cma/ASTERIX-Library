/**
 * @file I021_152.c
 * @brief Implementation of the Category 21 Item 152 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_152.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_152_MH(const I021_152 * item)
{
    if (!item) return 0.0F;
    return read_unsigned_24bit(item->raw) * I021_152_LSB_MH;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_152_MH(I021_152 * item, double mh)
{
    uint16_t mh_raw = 0;
    if (!item) return;
    if (mh > 0)
        mh_raw = (uint16_t) ((mh / I021_152_LSB_MH) + 0.5);
    write_unsigned_16bit(item->raw, mh_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_152(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_152 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_152 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_152(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_152 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_152 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_152(const I021_152 * item)
{
    printf("I021/152 - Magnetic Heading\n");
    if (!item)
    {
        printf("I021/152 <null>\n");
        return;
    }
    printf("- MH (degrees) = %f\n", get_I021_152_MH(item));
}