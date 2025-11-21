/**
 * @file I021_075.c
 * @brief Implementation of the Category 21 Item 075 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_075.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_075_TMRV(const I021_075 * item)
{
    if (!item) return 0.0F;
    return read_unsigned_24bit(item->raw) * I021_075_LSB_TMRV;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_075_TMRV(I021_075 * item, double tmrv_seconds)
{
    uint32_t tmrv_raw = 0;
    if (!item) return;
    /* Turn to raw format and round to nearest unit if bigger than 0 */
    if (tmrv_seconds > 0)
    tmrv_raw = (uint32_t) ((tmrv_seconds / I021_075_LSB_TMRV) + 0.5);
    write_unsigned_24bit(item->raw, tmrv_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_075(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_075 * item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_075 *)item_in;
    memcpy(&msg_out[out_index], item->raw, 3);
    return out_index + 3;
}

uint16_t decode_I021_075(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_075 * item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_075 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 3);
    return in_index + 3;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_075(const I021_075 * item)
{
    printf("I021/075 - Time of Message Reception for Velocity\n");
    if (!item)
    {
        printf("I021/075: <null>\n");
        return;
    }
    printf("- TMRV (seconds) = %f\n", get_I021_075_TMRV(item));
}