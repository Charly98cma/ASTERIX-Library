/**
 * @file I021_145.c
 * @brief Implementation of the Category 21 Item 145 functions
 */

#include <stdio.h>
#include <string.h>

#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_145.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

int16_t get_I021_145_FL_feet(const I021_145 * item)
{
    if (!item) return 0;
    return read_twocomp_16bit(item->raw) * I021_145_LSB_FL;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_145_FL_feet(I021_145 * item, int16_t fl)
{
    int16_t fl_raw = 0;
    if (!item) return;
    if (fl > 0)
        fl_raw = (fl / I021_145_LSB_FL) + 0.5;
    write_twocomp_16bit(item->raw, fl_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_145(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_145 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_145 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_145(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_145 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_145 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_145(const I021_145 * item)
{
    printf("I021/145 - Flight Level\n");
    if (!item)
    {
        printf("I021/145 <null>\n");
        return;
    }
    printf("- FL = %d\n", get_I021_145_FL_feet(item));
}