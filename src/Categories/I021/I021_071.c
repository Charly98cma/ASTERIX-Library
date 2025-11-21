/**
 * @file I021_071.c
 * @brief Implementation of the Category 21 Item 071 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_071.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_071_TAP(const I021_071 * item)
{
    if (!item) return 0;
    return read_unsigned_24bit(item->raw) * I021_071_LSB_TAP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_071_TAP(I021_071 * item, double tap_seconds)
{
    uint32_t tap_raw = 0;
    if (!item) return;
    if (tap_seconds > 0)
        tap_raw = (uint32_t) ((tap_seconds / I021_071_LSB_TAP) + 0.5);
    write_unsigned_24bit(item->raw, tap_raw & MASK_24_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_071(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_071 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_071 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 3);
    return out_index + 3;
}

uint16_t decode_I021_071(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_071 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_071 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 3);
    return in_index + 3;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_071(const I021_071 * item)
{
    printf("I021/071 - Time of Applicability for Position\n");
    if (!item)
    {
        printf("I021/071: <null>\n");
        return;
    }
    printf("- TAP (seconds) = %f\n", get_I021_071_TAP(item));
}
