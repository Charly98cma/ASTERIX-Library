/**
 * @file I021_073.c
 * @brief Implementation of the Category 21 Item 073 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_073.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_073_TMRP(const I021_073 * item)
{
    if (!item) return 0;
    return read_unsigned_24bit(item->raw) * I021_073_LSB_TMRP;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_073_TMRP(I021_073 * item, double seconds)
{
    uint32_t tmrp_raw = 0;
    if (!item) return;
    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (seconds > 0)
        tmrp_raw = (uint32_t) ((seconds / I021_073_LSB_TMRP) + 0.5);
    write_unsigned_24bit(item->raw, tmrp_raw & MASK_24_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_073(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_073 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_073 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 3);
    return out_index + 3;
}

uint16_t decode_I021_073(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_073 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_073 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 3);
    return in_index + 3;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_073(const I021_073 * item)
{
    printf("I021/073 - Time of Message Reception for Position\n");
    if (!item)
    {
        printf("I021/073: <null>\n");
        return;
    }
    printf("- TMRP (seconds) = %f\n", get_I021_073_TMRP(item));
}
