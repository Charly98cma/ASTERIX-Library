/**
 * @file I021_140.c
 * @brief Implementation of the Category 21 Item 140 functions
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_140.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_140_GH(const I021_140 * item)
{
    if (!item) return 0.0F;
    return read_twocomp_16bit(item->raw) * I021_140_LSB_GH;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_140_GH(I021_140 * item, double gh_ft)
{
    uint16_t gh_raw = 0;
    if (!item) return;
    if (gh_ft > 0)
        gh_raw = (uint16_t) ((gh_ft / I021_140_LSB_GH) + 0.5);
    write_twocomp_16bit(item->raw, gh_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_140(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_140 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_140 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_140(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_140 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_140 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_140(const I021_140 * item)
{
    printf("I021/140 - Geometric Height\n");
    if (!item)
    {
        printf("I021/140 <null>");
        return;
    }
    printf("- GH (feets) = %f\n", get_I021_140_GH(item));
}