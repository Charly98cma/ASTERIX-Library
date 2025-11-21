/**
 * @file I021_070.c
 * @brief Implementation of the Category 21 Item 070 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_070.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint16_t get_I021_070_code(const I021_070 * item)
{
    if (!item) return 0;
    return read_unsigned_16bit(item->raw) & MASK_12_BITS;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_070_code(I021_070 * item, uint16_t code)
{
    if (!item || (code > 07777)) return;
    write_unsigned_16bit(item->raw, code & MASK_12_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_070(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_070 * item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_070 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_070(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_070 * item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_070 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_070(const I021_070 * item)
{
    printf("I021/070 - Mode 3/A\n");
    if (!item)
    {
        printf("I021/070: <null>\n");
        return;
    }
    printf("- Code: %04o (raw: 0x%02X%02X)\n",
           get_I021_070_code(item) , item->raw[0], item->raw[1]);
}
