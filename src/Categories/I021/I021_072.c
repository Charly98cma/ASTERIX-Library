/**
 * @file I021_072.c
 * @brief Implementation of the Category 21 Item 072 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_072.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_072_TAV(const I021_072 * item)
{
    if (!item) return 0;
    return read_unsigned_24bit(item->raw) * I021_072_LSB_TAV;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_072_TAV(I021_072 * item, double tav_seconds)
{
    uint32_t tav_raw = 0;
    if (!item) return;
    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (tav_seconds > 0)
        tav_raw = (uint32_t) ((tav_seconds / I021_072_LSB_TAV) + 0.5);
    write_unsigned_24bit(item->raw, tav_raw & MASK_24_BITS);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_072(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_072 * item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_072 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 3);
    return out_index + 3;
}

uint16_t decode_I021_072(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_072 * item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_072 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 3);
    return in_index + 3;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_072(const I021_072 * item)
{
    printf("I021/072 - Time of Applicability for Velocity\n");
    if (!item)
    {
        printf("I021/072: <null>\n");
        return;
    }
    printf("- TAV (seconds) = %f\n",get_I021_072_TAV(item));
}
