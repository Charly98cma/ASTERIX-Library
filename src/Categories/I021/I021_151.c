/**
 * @file I021_151.c
 * @brief Implementation of the Category 21 Item 151 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_151.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_151_RE(const I021_151 * item)
{
    if (!item) return 0;
    return read_bits(&item->raw[0], MASK_01_BITS, 7);
}

uint16_t get_I021_151_TAS(const I021_151 * item)
{
    if (!item) return 0;
    return read_unsigned_16bit(item->raw) & MASK_15_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_151_RE(I021_151 * item, uint8_t re)
{
    if (!item) return;
    write_bits(item->raw, MASK_01_BITS, 7, re);
}

void set_I021_151_TAS(I021_151 * item, uint16_t tas_kts)
{
    if (!item) return;
    /* Write top 7 bits */
    write_bits(item->raw, MASK_07_BITS, 0, tas_kts >> 8);
    /* Write remaining 8 bits */
    write_unsigned_8bit(&item->raw[1], tas_kts & MASK_08_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_151(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_151 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_151 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_151(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_151 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_151 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_151(const I021_151 * item)
{
    printf("I021/151 - True Air Speed\n");
    if (!item)
    {
        printf("I021/151 <null>\n");
        return;
    }
    printf("- RE = %d\n", get_I021_151_RE(item));
    printf("- TAS = %d\n", get_I021_151_TAS(item));
}