/**
 * @file I021_080.c
 * @brief Implementation of the Category 21 Item 080 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_080.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint32_t get_I021_080_TGTADDR(const I021_080 * item)
{
    if (!item) return 0;
    return read_unsigned_24bit(item->raw);
}
/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_080_TGTADDR(I021_080 * item, uint32_t addr)
{
    if (!item) return;
    write_unsigned_24bit(item->raw, addr & MASK_24_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_080(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_080 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_080 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 3);
    return out_index + 3;
}

uint16_t decode_I021_080(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_080 * item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_080 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 3);
    return in_index + 3;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_080(const I021_080 * item)
{
    printf("I021/080 - Target ICAO Address (24 bits)\n");
    if (!item)
    {
        printf("I021/080: <null>\n");
        return;
    }
    printf("- ICAO Addr = 0x%04X\n", get_I021_080_TGTADDR(item));
}