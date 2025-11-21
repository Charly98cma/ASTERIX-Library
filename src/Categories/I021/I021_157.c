/**
 * @file I021_157.c
 * @brief Implementation of the Category 21 Item 157 functions
 */

#include <stdio.h>
#include <string.h>

#include "Common/constants.h"
#include "Aux_Funcs/aux_funcs.h"

#include "Categories/I021/I021_157.h"

/*******************************************************************************
 * Getters
 ******************************************************************************/

uint8_t get_I021_157_RE(const I021_157 * item)
{
    if (!item) return 0;
    return read_bits(item->raw, MASK_01_BITS, 7);
}

double get_I021_157_GVR(const I021_157 * item)
{
    if (!item) return 0.0F;
    return (read_twocomp_16bit(item->raw) & MASK_15_BITS) * I021_157_LSB_GVR;
}

/*******************************************************************************
 * Setters
 ******************************************************************************/

void set_I021_157_RE(I021_157 * item, uint8_t re)
{
    if (!item) return;
    write_bits(item->raw, MASK_01_BITS, 7, re);
}

void set_I021_157_GVR(I021_157 * item, double gvr_ftpmin)
{
    int16_t gvr_raw = 0;
    if (!item) return;
    if (gvr_ftpmin > 0)
        gvr_raw = (int16_t) ((gvr_ftpmin / I021_157_LSB_GVR) + 0.5);
    /* Write top 7 bits */
    write_bits(item->raw, MASK_07_BITS, 0, gvr_raw >> 8);
    /* Write remaining 8 bits */
    write_twocomp_8bit(&item->raw[1], gvr_raw);
}

/*******************************************************************************
 * Encoding and Decoding functions
 ******************************************************************************/

uint16_t encode_I021_157(void * item_in, unsigned char * msg_out, uint16_t out_index)
{
    I021_157 *item;
    if (!item_in || !msg_out) return out_index;
    item = (I021_157 *) item_in;
    memcpy(&msg_out[out_index], item->raw, 2);
    return out_index + 2;
}

uint16_t decode_I021_157(void * item_out, const unsigned char * msg_in, uint16_t in_index)
{
    I021_157 *item;
    if (!item_out || !msg_in) return in_index;
    item = (I021_157 *) item_out;
    memcpy(item->raw, &msg_in[in_index], 2);
    return in_index + 2;
}

/*******************************************************************************
 * Other Functions
 ******************************************************************************/

void print_I021_157(const I021_157 * item)
{
    printf("I021/157 - Geometric Vertical Rate\n");
    if (!item)
    {
        printf("I021/157 <null>\n");
        return;
    }
    printf("- RE = %d\n", get_I021_157_RE(item));
    printf("- GVR (feet/minute) = %f\n", get_I021_157_GVR(item));
}