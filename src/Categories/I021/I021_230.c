/**
 * @file I021_230.c
 * @brief Implementation of the Category 21 Item 230 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_230.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

double get_I021_230_RA(const I021_230 * item)
{
    if (!item) return 0.0F;
    return read_twocomp_16bit(item->raw) * I021_230_LSB_RA;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_230_RA(I021_230 * item, double ra_deg)
{
    int16_t ra_raw = 0;
    if (!item) return;
    if (ra_deg > 0)
        ra_raw = (int16_t) ((ra_deg / I021_230_LSB_RA) + 0.5);
    write_twocomp_16bit(item->raw, ra_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_230(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_230 *item;    
    if (!item_in || !msg_out) return out_index;
    item = (I021_230 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_230(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_230 *item;    
    if (!item_out || !msg_in) return in_index;
    item = (I021_230 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_230(const I021_230 * item)
{
    printf("I021/230 - Roll Angle\n");
    if (!item)
    {
        printf("I021/230 <null>\n");
        return;
    }
    printf("- ROLL ANGLE = %f\n", get_I021_230_RA(item));
}
